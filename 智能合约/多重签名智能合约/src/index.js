
const baseConf = {}

function prepare (module) {
  const layer = {}
  for (let name in module) {
    if (typeof module[name] !== "function") continue
    layer[name] = passConfig(module[name])
  }

  return Object.assign({}, module, layer)
}

function passConfig (func) {
  return function (...params) {
    // Make a one-time configuration object and pass it to the underlying
    // function along with user parameters.
    const conf = Object.create(baseConf)
    return func(conf, ...params)
  }
}

module.exports = prepare(require("./multisig"))
