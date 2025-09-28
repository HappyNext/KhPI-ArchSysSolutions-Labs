#ifndef FACEBOOKCREATOR_H
#define FACEBOOKCREATOR_H

#include "socialnetworkcreator.h"
#include "facebook.h"

class FacebookCreator : public SocialNetworkCreator
{
    std::string login;
    std::string password;

    public:
        FacebookCreator(const std::string& login, const std::string& password) : login(login), password(password) {};
        SocialNetwork* createNetwork() override { return new Facebook(login, password); };
};

#endif // FACEBOOKNETWORK_H