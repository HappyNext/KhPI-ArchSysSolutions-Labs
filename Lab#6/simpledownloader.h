#ifndef SIMPLEDOWNLOADER_H
#define SIMPLEDOWNLOADER_H

#include "downloader.h"

class SimpleDownloader : public Downloader
{
    public:
       std::string download(const std::string& file_url) override
        {
            std::cout << "[SimpleDownloader] Завантаження з файлу: " << file_url << std::endl;
            std::string fileContent = "Це вміст файлу з " + file_url;
            std::cout << "<-- [SimpleDownloader] Файл завантажено.\n";
            return fileContent;
        }
};

#endif // SIMPLEDOWNLOADER