#ifndef CACHINGDOWNLOADER_H
#define CACHINGDOWNLOADER_H

#include <map>
#include "downloader.h"
#include "simpledownloader.h"

class CachingDownloader : public Downloader
{
    SimpleDownloader& realDownloader;
    std::map<std::string, std::string> cache;
    bool isInCache(const std::string& url)
    {
        return cache.find(url) != cache.end();
    }
    public:
        CachingDownloader(SimpleDownloader& s): realDownloader(s) {}
        std::string download(const std::string& file_url) override
        {
            if(isInCache(file_url))
            {
                std::cout << "==> [Proxy] Повернення даних з кешу для: " << file_url << "\n";
                return cache[file_url];
            }
            else
            {
                std::cout << "==> [Proxy] В кеші нічого немає. Звертаюсь до реального завантажувача.\n";
                std::string fileContent = realDownloader.download(file_url);
                cache[file_url] = fileContent;
                std::cout << "==> [Proxy] Збережено в кеш дані для: " << file_url << "\n";
                return fileContent;
            }
        }
};

#endif // CACHINGDOWNLOADER_H