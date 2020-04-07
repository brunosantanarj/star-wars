import * as Koa from 'koa';

const app = (new Koa);

app.use(async ctx => {
  ctx.body = 'Koa start'
});

app.listen(3000);
