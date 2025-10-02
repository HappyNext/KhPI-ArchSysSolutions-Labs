#ifndef SLACKNOTIFICATIONADAPTER_H
#define SLACKNOTIFICATIONADAPTER_H

#include <string>
#include "notification.h"
#include "slackclient.h"

class SlackNotificationAdapter : public Notification
{
    SlackClient* slack;
    int chatID;
    public:
        SlackNotificationAdapter(const std::string& login, const std::string& apiKey, const int chatId)
        {
            slack = new SlackClient(login, apiKey);
            slack->logIn();
            this->chatID = chatId;
        };
        ~SlackNotificationAdapter()
        {
            delete slack;
        };
        void send(const std::string& title, const std::string& message) override
        {
            std::string text = title + "\n" + message;
            slack->postMessage(chatID, text);
        };
};

#endif // SLACKNOTIFICATIONADAPTER_H