#include "tmdbapicaller.h"

backend::TMDBApiCaller::TMDBApiCaller() {}

std::string backend::TMDBApiCaller::searchMovie(std::string s) {
  std::string webpage = "https://api.themoviedb.org/3/search/";
  std::string api_key = "361c7eb5c8aa08e79186317b4e404cb9";
  std::string api_call = webpage + "movie?api_key=" + api_key + "&query=" + s;

  // retrieve data from TMDB API
  std::string res = getUrl(api_call);
  return res;
}

std::string backend::TMDBApiCaller::searchTVShow(std::string s) {
  std::string webpage = "https://api.themoviedb.org/3/search/";
  std::string api_key = "361c7eb5c8aa08e79186317b4e404cb9";
  std::string api_call = webpage + "tv?api_key=" + api_key + "&query=" + s;

  // retrieve data from TMDB API
  std::string res = getUrl(api_call);
  return res;
}

std::string backend::TMDBApiCaller::getEpisodesList(std::string id,
                                                    std::string season) {
  std::string webpage = "https://api.themoviedb.org/3/tv/";
  std::string api_key = "361c7eb5c8aa08e79186317b4e404cb9";
  std::string api_call =
      webpage + id + "/season/" + season + "?api_key=" + api_key;

  // retrieve data from TMDB API
  std::string res = getUrl(api_call);
  return res;
}

std::string backend::TMDBApiCaller::getTVShowSeasons(std::string id) {
  std::string webpage = "https://api.themoviedb.org/3/tv/";
  std::string api_key = "361c7eb5c8aa08e79186317b4e404cb9";
  std::string api_call = webpage + id + "?api_key=" + api_key;

  // retrieve data from TMDB API
  std::string res = getUrl(api_call);
  return res;
}

std::size_t callback(const char* in, std::size_t size, std::size_t num,
                     std::string* out) {
  const std::size_t totalBytes(size * num);
  out->append(in, totalBytes);
  return totalBytes;
}

std::string backend::TMDBApiCaller::getUrl(std::string url) {
  long return_code(0);
  std::unique_ptr<std::string> data = std::make_unique<std::string>();
  CURL* curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, data.get());

    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &return_code);
    curl_easy_cleanup(curl);
  }

  if (return_code == 200) {
    return *data;
  } else {
    return "";
  }
}
