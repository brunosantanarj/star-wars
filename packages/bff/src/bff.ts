import * as Koa from 'koa';
import * as bodyParser from 'koa-bodyparser';
import * as cors from '@koa/cors'
import { router } from './routes';

const app = (new Koa);

app
  .use(bodyParser())
  .use(cors())
  .use(router.routes())
  .use(router.allowedMethods());

app.listen(3000);
