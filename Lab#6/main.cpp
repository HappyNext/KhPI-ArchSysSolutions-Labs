#include <iostream>
#include "windows.h"
#include "downloader.h"
#include "simpledownloader.h"
#include "cachingdownloader.h"

void DownloadLecture(Downloader& downloader)
{
    std::cout << "\n--- Запит про завантаження першої лекції з предмету Ефективність та якість архітектурних рішень інформаційних систем(лаб) ---\n";
    std::cout << "Отримано: " << downloader.download("https://khpi.edu.ua/ArchSysSolutions/lectures/lecture1.pdf") << std::endl;

    std::cout << "\n--- Повторний запит про завантаження першої лекції з предмету Ефективність та якість архітектурних рішень інформаційних систем(лаб) ---\n";
    std::cout << "Отримано: " << downloader.download("https://khpi.edu.ua/ArchSysSolutions/lectures/lecture1.pdf") << std::endl;

    std::cout << "\n--- Новий запит про завантаження другої лекції з предмету Ефективність та якість архітектурних рішень інформаційних систем(лаб) ---\n";
    std::cout << "Отримано: " << downloader.download("https://khpi.edu.ua/ArchSysSolutions/lectures/lecture2.pdf") << std::endl;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    SimpleDownloader simpleDownloader;
    CachingDownloader proxyDownloader(simpleDownloader);

    DownloadLecture(proxyDownloader);

    return 0;
}