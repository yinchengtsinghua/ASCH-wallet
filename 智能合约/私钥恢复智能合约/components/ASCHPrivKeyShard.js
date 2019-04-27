var http = require('http');
var secrets = require('../secrets.js');


http.createServer(function (req, res) {

    var key, comb, shares, newShare;
    key = 'fe1dfcaf50206561e507e9d659bdc8017907d4529f051152978d8df5b7d93328';
    shares = secrets.share(key, 3, 2);
    comb = secrets.combine( shares );
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('You should see two identical keys below, before and after share and combine.\n\n' + "Private key to be sharded: " + key + '\n' + "Private key shard array: " + shares + '\n' + "Recovered Private Key: " + comb);

}).listen(1337, '127.0.0.1');
console.log('Server running at http://127.0.0.1:1337/');
