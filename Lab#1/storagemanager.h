#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "storage.h"
#include "localdiskstorage.h"
#include "amazons3storage.h"

class StorageManager
{
    private:
        static StorageManager* instance;
        StorageManager() {};

    public:
        static StorageManager* getInstance()
        {
            if (!instance)
            {
                instance = new StorageManager();
            }
            return instance;
        }

        Storage* selectStorage(const std::string& type)
        {
            if (type == "local")
            {
                return new LocalDiskStorage();
            }
            else if (type == "s3")
            {
                return new AmazonS3Storage();
            }
            return nullptr;
        }
};

#endif //STORAGEMANAGER_H