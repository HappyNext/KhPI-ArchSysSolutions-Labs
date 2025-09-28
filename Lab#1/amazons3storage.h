#ifndef AMAZONS3STORAGE_H
#define AMAZONS3STORAGE_H

#include "storage.h"

class AmazonS3Storage : public Storage
{
    void connect() override;
    void uploadFile(const std::string& filename = 0) override;
    void downloadFile(const std::string& filename = 0) override;
};

#endif // AMAZONS3STORAGE_H