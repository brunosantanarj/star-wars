import { ImageSearchClient, ImageSearchModels } from "@azure/cognitiveservices-imagesearch";
import { CognitiveServicesCredentials } from "@azure/ms-rest-azure-js";

const credentials = new CognitiveServicesCredentials('2b32f46321d1446ea9a027d56ce80085');
const client = new ImageSearchClient(credentials);

const options: ImageSearchModels.ImagesSearchOptionalParams = {
  count: 1,
};

const NOT_FOUND_IMAGE = 'https://sm.ign.com/ign_br/news/s/star-wars-/star-wars-the-rise-of-skywalker-score-will-include-every-the_vwjn.jpg';

const searchImage = async (term: string): Promise<null | string> => {
  const response = await client.images.search(term, options);
  if (!response) {
    return NOT_FOUND_IMAGE;
  }

  return response.value[0].contentUrl || NOT_FOUND_IMAGE;
}

export default searchImage;
