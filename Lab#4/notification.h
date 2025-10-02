#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>

class Notification
{
    public:
        virtual void send(const std::string& title, const std::string& message) = 0;
        virtual ~Notification() = default;
};

#endif // NOTIFICATION_H