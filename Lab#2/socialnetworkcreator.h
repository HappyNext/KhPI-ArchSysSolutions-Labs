#ifndef SOCIALNETWORKCREATOR_H
#define SOCIALNETWORKCREATOR_H

#include "socialnetwork.h"

class SocialNetworkCreator
{
    public:
        virtual SocialNetwork* createNetwork() = 0;
        virtual ~SocialNetworkCreator() = default;
};

#endif // SOCIALNETWORKCREATOR_H