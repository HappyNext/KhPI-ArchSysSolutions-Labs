#include <iostream>
#include "socialnetwork.h"
#include "facebookcreator.h"
#include "socialnetworkcreator.h"
#include "linkedincreator.h"

int main() {
    // Facebook
    SocialNetworkCreator* fbCreator = new FacebookCreator("user123", "qwerty123");
    SocialNetwork* fb = fbCreator->createNetwork();
    fb->connect();
    fb->publish("Hello, Facebook!");
    delete fb;
    delete fbCreator;

    // LinkedIn
    SocialNetworkCreator* liCreator = new LinkedInCreator("user@mail.com", "123456");
    SocialNetwork* li = liCreator->createNetwork();
    li->connect();
    li->publish("Hello, LinkedIn!");
    delete li;
    delete liCreator;

    return 0;
}
