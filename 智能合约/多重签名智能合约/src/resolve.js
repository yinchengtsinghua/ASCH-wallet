
const resolve = exports

const helpers = require("@cosmic-plus/jsutils/es5/misc")
const StellarSdk = require("@cosmic-plus/base/es5/stellar-sdk")


resolve.server = function (conf, network = conf.network, server = conf.server) {
  const passphrase = networkPassphrase(network)
  if (!passphrase) throw new Error("No network selected.")
  return getServer(passphrase, server)
}

resolve.network = function (conf, network = conf.network, server = conf.server) {
  let passphrase = networkPassphrase()
  const newPassphrase = networkPassphrase(network)

  if (passphrase !== newPassphrase) {
    console.log("Switch to network: " + network)
    StellarSdk.Network.use(new StellarSdk.Network(newPassphrase))
    passphrase = newPassphrase
  } else if (!passphrase) {
    throw new Error("No network selected.")
  }

  return getServer(passphrase, server)
}


function networkPassphrase (network) {
  if (network) {
    if (network === "public") return StellarSdk.Networks.PUBLIC
    else if (network === "test") return StellarSdk.Networks.TESTNET
    else return network
  } else {
    const currentNetwork = StellarSdk.Network.current()
    if (currentNetwork) return currentNetwork.networkPassphrase()
  }
}


const serverSaves = {}
const networkDefaultServer = {}
function getServer (passphrase, url) {
  if (url) networkDefaultServer[passphrase] = url
  else url = networkDefaultServer[passphrase]
  if (!url) throw new Error("No default server for requested network.")

  if (!serverSaves[url]) serverSaves[url] = new StellarSdk.Server(url)
  return serverSaves[url]
}


getServer(StellarSdk.Networks.PUBLIC, "https://horizon.stellar.org")
getServer(StellarSdk.Networks.TESTNET, "https://horizon-testnet.stellar.org")


resolve.accountCacheExpiration = 5 * 60


const accountCache = {}


async function cacheAccount (address, promise) {
  accountCache[address] = promise
  await helpers.timeout(resolve.accountCacheExpiration * 1000)
  delete accountCache[address]
}


resolve.address = function (c, address) {
  if (accountCache[address]) return accountCache[address]
  const promise = addressResolver(c, address)
  cacheAccount(address, promise)
  return promise
}


async function addressResolver (c, address) {


  const account = await StellarSdk.FederationServer.resolve(address)
  const publicKey = account.account_id
  if (!publicKey) throw new Error("Invalid response from federation server.")
  if (!account.memo_type && account.memo !== undefined) delete account.memo
  if (address !== publicKey) account.address = address
  const alias = c.aliases && c.aliases[publicKey]
  if (alias) account.alias = alias
  return account
}


resolve.account = async function (c, address, network = c.network) {
  const server = resolve.server(c, network)
  const account = await resolve.address(c, address)
  const publicKey = account.account_id
  const accountResponse = await server.loadAccount(publicKey)
  return accountResponse

}

resolve.accountIsEmpty = async function (conf, id) {
  return resolve
    .account(conf, id)
    .then(() => false)
    .catch(() => true)
}

resolve.transaction = async function (conf, txHash) {
  const caller = conf.server.transactions()
  return caller.transaction(txHash).call()
}


resolve.accountSigners = async function (c, address) {
  const account = await resolve.account(c, address)
  return account.signers
}

resolve.signersTable = async function (conf, ...addresses) {
  const obj = {}

  for (let index in addresses) {
    const account = await resolve.account(conf, addresses[index])
    if (!obj[account.id]) obj[account.id] = account.signers
  }

  return obj
}

resolve.signersList = async function (conf, ...addresses) {
  const array = []

  for (let index in addresses) {
    const account = await resolve.account(conf, addresses[index])
    account.signers.forEach(entry => {
      if (!array.find(a => a.key === entry.key)) array.push(entry.key)
    })
  }

  return array
}

resolve.txSources = function (conf, transaction) {
  const extra = useExtra(transaction)
  if (extra.sources) return extra.sources

  const array = [transaction.source]

  for (let index in transaction.operations) {
    const source = transaction.operations[index].source
    if (source && !array.find(a => a === source)) array.push(source)
  }

  extra.sources = array
  return array
}

resolve.txSignersList = async function (conf, transaction) {
  const extra = useExtra(transaction)
  if (!extra.signers) extra.signers = getTxSignersList(conf, transaction)
  return extra.signers
}

async function getTxSignersList (conf, transaction) {
  const sources = resolve.txSources(conf, transaction)
  return resolve.signersList(conf, ...sources)
}

const extraField = "extra_ocmultisig"
function useExtra (obj) {
  if (!obj[extraField]) obj[extraField] = {}
  return obj[extraField]
}
