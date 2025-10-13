#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>

class Renderer
{
    public:
        virtual void renderTitle(const std::string& title) const = 0;
        virtual void renderImage(const std::string& url) const = 0;
        virtual void renderText(const std::string& text) const = 0;
        virtual void renderID(const std::string& ID) const = 0;
        virtual ~Renderer() = default;
};

#endif //RENDERER_H