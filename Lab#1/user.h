#ifndef USER_H
#define USER_H

#include "storagemanager.h"
#include "storage.h"

class User
{
    private:
        std::string name;
        Storage* storage;

    public:
        User(const std::string& name, const std::string& storageType) : name(name)
        {
            storage = StorageManager::getInstance()->selectStorage(storageType);
        }

        void upload(const std::string& filename)
        {
            storage->uploadFile(filename);
        }

        void download(const std::string& filename)
        {
            storage->downloadFile(filename);
        }
};

#endif // USER_H