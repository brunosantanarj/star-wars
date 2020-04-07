import * as Router from 'koa-router';
import { starships, peoples } from './services';

const router = new Router({
  prefix: '/public'
});

router.post('/starships', starships);

router.get('/peoples', peoples);

export { router };
