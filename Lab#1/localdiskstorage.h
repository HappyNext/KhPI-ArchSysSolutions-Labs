#ifndef LOCALDISKSTORAGE_H
#define LOCALDISKSTORAGE_H

#include "storage.h"

class LocalDiskStorage : public Storage 
{
    void connect() override;
    void uploadFile(const std::string& filename = 0) override;
    void downloadFile(const std::string& filename = 0) override;
};

#endif // LOCALDISKSTORAGE_H