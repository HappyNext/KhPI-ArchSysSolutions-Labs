#include <iostream>
#include "storage.h"
#include "storagemanager.h"
#include "user.h"

int main()
{
    StorageManager* manager1 = StorageManager::getInstance();
    StorageManager* manager2 = StorageManager::getInstance();

    if (manager1 == manager2)
    {
        std::cout << "Let's get it started!" << std::endl;
    }

    User user1("Oleh", "local");
    User user2("Natalia", "s3");

    user1.upload("report.txt");
    user2.upload("photo.png");

    user1.download("data.txt");
    user2.download("zip.zip");
    return 0;
}