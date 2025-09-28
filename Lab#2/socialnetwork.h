#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include <string>

class SocialNetwork
{
    public:
        virtual void connect() = 0;
        virtual void publish(const std::string& message = 0) = 0;
        virtual ~SocialNetwork() = default;
};

#endif // SOCIALNETWORK_H