import { ImageSearchClient, ImageSearchModels } from "@azure/cognitiveservices-imagesearch";
import { CognitiveServicesCredentials } from "@azure/ms-rest-azure-js";

const credentials = new CognitiveServicesCredentials('my-fake-key');
const client = new ImageSearchClient(credentials);

const options: ImageSearchModels.ImagesSearchOptionalParams = {
  count: 1,
};

const searchImage = async (term: string): Promise<null | string> => {
  const response = await client.images.search(term, options);
  if (!response) {
    return null
  }

  return response.value[0].contentUrl;
}

export default searchImage;
