#ifndef LINKEDIN_H
#define LINKEDIN_H

#include "socialnetwork.h"
#include <iostream>

class LinkedIn : public SocialNetwork
{
    std::string email;
    std::string password;

    public:
        LinkedIn(const std::string& e, const std::string& p) : email(e), password(p) {};
        void connect() override { std::cout << "Connect to LinkedIn as " << email << std::endl; };
        void publish(const std::string& message = 0) override { std::cout << "[LinkedIn] " << message << std::endl; };
};

#endif // LINKEDIN_H