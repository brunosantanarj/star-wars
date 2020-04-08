import { Context } from 'koa';
import * as R from 'ramda';
import fetch from '../utils/fetch';
import extractPaginagion from '../utils/extractPagination';
import withImages from '../utils/withImages';

import env from '../env';

const VALUES_TO_FRONT = ['name', 'starships', 'height', 'gender', 'image', 'birth_year'];

export default async (ctx: Context): Promise<void> => {
  const createResponse = (response: any): void => {
    ctx.body = { data: { ...response } }
  };

  try {
    const { search } = ctx;
    const url = search ? `people/${search}` : 'people';

    const { results, next, previous } = await (await fetch(`${env.baseURL}/${url}`)).json();
    const resultsWithImags = (await withImages(results)).map(item => R.pick(VALUES_TO_FRONT, item));

    // const results = [
    //   {
    //     name: 'luke skywalker',
    //     height: '110',
    //     gender: 'male',
    //     image: 'https://s2.glbimg.com/LttsvVoQZGHoIJsmdlXMULY336A=/e.glbimg.com/og/ed/f/original/2019/09/23/ea1e16061bdf92edb111d8808c6741a6.jpg',
    //     birty_year: '199x',
    //     starships: [12, 22],
    //   }
    // ]
  
    createResponse({
      results: resultsWithImags,
      // results,
      next: extractPaginagion(next),
      previous: extractPaginagion(previous)
    });
  } catch {
    ctx.throw(500,'Error Message');
    // createResponse({ error: true });
  }
}
