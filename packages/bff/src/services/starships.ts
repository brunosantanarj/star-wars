import { Context } from 'koa';
import * as R from 'ramda';
import fetch from '../utils/fetch';
import withImages from '../utils/withImages';

const VALUES_TO_FRONT = [
  'name', 'model', 'manufacturer', 'max_atmosphering_speed', 'passengers', 'cargo_capacity', 'image'
];

export default async (ctx: Context): Promise<void> => {
  const createResponse = (response: any): void => {
    ctx.body = { data: { ...response } }
  };

  try {
    const { starships } = ctx.request.body;
    if (Array.isArray(starships) && starships.length) {
      const results = await Promise
        .all(starships.map(async (starship) => await(await fetch(starship)).json()));
      const resultsWithImags = (await withImages(results)).map(item => R.pick(VALUES_TO_FRONT, item));
      
      createResponse({ results: resultsWithImags });
      return;
    }
  
    createResponse({ error: true });
  } catch {
    createResponse({ error: true });
  }
}
