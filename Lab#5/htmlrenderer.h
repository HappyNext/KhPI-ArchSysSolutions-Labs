#ifndef HTMLRENDERER_H
#define HTMLRENDERER_H

#include "renderer.h"

class HTMLRenderer : public Renderer
{
    public:
        void renderText(const std::string& text) const override
        {
            std::cout << "<p>" << text << "</p>" << std::endl;
        } 

        void renderImage(const std::string& url) const override
        {
            std::cout << "<img src = \"" << url << "\">" << std::endl;
        }

        void renderTitle(const std::string& title) const override
        {
            std::cout << "<h1>" << title << "</h1>" << std::endl;
        }

        void renderID(const std::string& ID) const override
        {
            std::cout << "<p>ID: " << ID << "</p>" << std::endl;
        }
};

#endif // HTMLRENDERER_H