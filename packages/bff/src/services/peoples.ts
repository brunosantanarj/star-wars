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
  
    createResponse({
      results: resultsWithImags,
      next: extractPaginagion(next),
      previous: extractPaginagion(previous)
    });
  } catch {
    createResponse({ error: true });
  }
}
