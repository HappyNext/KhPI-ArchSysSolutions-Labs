#ifndef LINKEDINCREATOR_H
#define LINKEDINCREATOR_H

#include "socialnetworkcreator.h"
#include "linkedin.h"

class LinkedInCreator : public SocialNetworkCreator
{
    std::string email;
    std::string password;
    public: 
        LinkedInCreator(const std::string& e, const std::string& p) : email(e), password(p) {};
        SocialNetwork* createNetwork() override { return new LinkedIn(email,password); };
};

#endif // LINKEDINCREATOR_H