#ifndef SMSCLIENT_H
#define SMSCLIENT_H

#include <iostream>
#include <string>

class SMSClient
{
    std::string sender_name;
    public:
        SMSClient(const std::string& sender) : sender_name(sender) {};
        void sendSMS(std::string& phone, std::string& text)
        {
            std::cout << "SMS from '" << sender_name << "' to '" << phone << "': " << text << std::endl;
        };
};

#endif // SMSCLIENT_H