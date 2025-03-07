import express from 'express'
import { createHandler } from 'graphql-http/lib/use/express';
import { resolvers, schema } from './schema.mjs';
import { ruruHTML } from "ruru/server";
import cors from 'cors'

const app = express();

app.use(cors());

app.get('/', (req, res) => {
  res.writeHead(200, { "Content-Type": "text/html" });
  return res.end(
    ruruHTML({
      endpoint: "/graphql",
    }),
  );
})

app.use('/graphql', createHandler({
    schema: schema,
    rootValue: resolvers
}))

app.listen(3000);