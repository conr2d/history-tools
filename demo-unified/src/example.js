const { createClientWasm, transact } = require('./lib/eosio-client');
const fs = require('fs');
const { TextDecoder, TextEncoder } = require('util');
const fetch = require('node-fetch');
const encoder = new TextEncoder('utf8');
const decoder = new TextDecoder('utf8');
const { Api, JsonRpc, RpcError, Serialize } = require('eosjs');
const { JsSignatureProvider } = require('eosjs/dist/eosjs-jssig');
const commander = require('commander');

const signatureProvider = new JsSignatureProvider(['5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3']);
const rpc = new JsonRpc('http://127.0.0.1:8888', { fetch });
const queryUrl = 'http://localhost:8880';
const api = new Api({ rpc, signatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() });

async function test_transact(token) {
    const result = await transact(api, {
        actions: [
            token.actions.create([{ actor: 'eosio.token', permission: 'active' }], 'eosio', '1000000.0000 TIC'),
            token.actions.create([{ actor: 'eosio.token', permission: 'active' }], 'eosio', '2000000.0000 TOC'),
            token.actions.create([{ actor: 'eosio.token', permission: 'active' }], 'eosio', '3000000.0000 TOK'),
            token.actions.issue([{ actor: 'eosio', permission: 'active' }], 'eosio', '100000.0000 TIC', 'issuing'),
            token.actions.issue([{ actor: 'eosio', permission: 'active' }], 'eosio', '200000.0000 TOC', 'issuing'),
            token.actions.issue([{ actor: 'eosio', permission: 'active' }], 'eosio', '300000.0000 TOK', 'issuing'),
            token.actions.open([{ actor: 'a', permission: 'active' }], 'a', '4,TIC', 'a'),
            token.actions.open([{ actor: 'a', permission: 'active' }], 'a', '4,TOC', 'a'),
            token.actions.open([{ actor: 'a', permission: 'active' }], 'a', '4,TOK', 'a'),
            token.actions.open([{ actor: 'b', permission: 'active' }], 'b', '4,TIC', 'b'),
            token.actions.open([{ actor: 'b', permission: 'active' }], 'b', '4,TOC', 'b'),
            token.actions.open([{ actor: 'b', permission: 'active' }], 'b', '4,TOK', 'b'),
            token.actions.transfer([{ actor: 'eosio', permission: 'active' }], 'eosio', 'a', '1000.0000 TIC', 'transferring'),
            token.actions.transfer([{ actor: 'eosio', permission: 'active' }], 'eosio', 'a', '2000.0000 TOC', 'transferring'),
            token.actions.transfer([{ actor: 'eosio', permission: 'active' }], 'eosio', 'a', '3000.0000 TOK', 'transferring'),
            token.actions.transfer([{ actor: 'a', permission: 'active' }], 'a', 'b', '100.0000 TIC', 'transferring'),
            token.actions.transfer([{ actor: 'a', permission: 'active' }], 'a', 'b', '200.0000 TOC', 'transferring'),
            token.actions.transfer([{ actor: 'a', permission: 'active' }], 'a', 'b', '300.0000 TOK', 'transferring'),
        ]
    }, {
        blocksBehind: 3,
        expireSeconds: 30,
    });
    console.log(result.processed.receipt.status);
}

async function test_query(token) {
    console.log('eosio:', await token.queries.gettoks('eosio'));
    console.log('a:', await token.queries.gettoks('a'));
    console.log('b:', await token.queries.gettoks('b'));
}

commander
    .option('-t, --transact', 'Transact')
    .option('-q, --query', 'Query')
    .parse(process.argv);

(async () => {
    try {
        const token = await createClientWasm({
            account: 'eosio.token',
            mod: new WebAssembly.Module(fs.readFileSync('../build/eosio.token.client.wasm')),
            encoder, decoder, fetch, queryUrl,
        });
        if (commander.transact) test_transact(token);
        if (commander.query) test_query(token);
    } catch (e) {
        if (e instanceof RpcError && e.json && e.json.error && e.json.error.details)
            console.log(e.json.error.details);
        else
            console.log(e);
    }
})();
