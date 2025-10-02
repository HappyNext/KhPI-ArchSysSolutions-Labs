#ifndef SLACKCLIENT_H
#define SLACKCLIENT_H

#include <iostream>
#include <string>

class SlackClient
{
    std::string login;
    std::string apiKey;
    public:
        SlackClient(const std::string& l, const std::string& apiKey) : login(l), apiKey(apiKey) {}
        void logIn()
        {
            std::cout << "Logged in to Slack with login '" << login << "' and apiKey '" << apiKey << "'." << std::endl;
        };
        void postMessage(const int chatId, const std::string& text)
        {
            std::cout << "Posted to Slack chat '" << chatId << "': " << text << std::endl;
        };
};

#endif // SLACKCLIENT_H