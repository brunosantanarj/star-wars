import searchImage from '../services/searchImages';

type withImagesReturn = Promise<[] | Record<string, any>>;

export default async (results: Record<string, any>[], termProperty = 'name'): withImagesReturn => {
  const withImages = results.map(async resultItem => ({
    ...resultItem,
    image: await searchImage(resultItem[termProperty])
  }));

  const completed = await Promise.all(withImages);

  return completed;
}
