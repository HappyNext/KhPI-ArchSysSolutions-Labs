#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <iostream>
#include <string>
#include <vector>

class Downloader 
{
    public:
        virtual std::string download(const std::string& file_url) = 0;
        virtual ~Downloader() = default;
};

#endif // DOWNLOADER_H