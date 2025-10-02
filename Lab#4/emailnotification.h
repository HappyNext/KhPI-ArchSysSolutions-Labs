#ifndef EMAILNOTIFICATION_H
#define EMAILNOTIFICATION_H

#include "notification.h"

class EmailNotification : public Notification
{
    std::string adminEmail;
    public:
        EmailNotification(std::string adminEmail) : adminEmail(adminEmail) {}
        void send(const std::string& title, const std::string& message) override
        {
            std::cout << "Sent email with title " << title << " to " 
            << adminEmail << " that says " << message << std::endl;
        }
};

#endif // NOTIFICATION_H