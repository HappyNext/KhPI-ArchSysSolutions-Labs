#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
    public:
        virtual void connect () = 0;
        virtual void uploadFile(const std::string& filename = 0);
        virtual void downloadFile(const std::string& filename = 0);
        virtual ~Storage() = default;
};

#endif // STORAGE_H