#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "socialnetwork.h"
#include <iostream>

class Facebook : public SocialNetwork
{
    private:
        std::string login;
        std::string password;
    public:
        Facebook(const std::string& l, const std::string& p) : login(l), password(p) {}
        void connect() override { std::cout << "Connected to Facebook as " << login << std::endl; };
        void publish(const std::string& message = 0) override { std::cout << "[Facebook] " << message << std::endl;};
};

#endif // FACEBOOK_H