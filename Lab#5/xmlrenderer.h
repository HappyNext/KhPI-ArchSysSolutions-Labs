#ifndef XMLRENDERER_H
#define XMLRENDERER_H

#include "renderer.h"

class XMLRenderer : public Renderer
{
    public:
        void renderText(const std::string& text) const override
        {
            std::cout << "<content>" << text << "</content>" << std::endl;
        }
        
        void renderTitle(const std::string& title) const override
        {
            std::cout << "<title>" << title << "</title>" << std::endl;
        }

        void renderImage(const std::string& url) const override
        {
            std::cout << "<image src=\"" << url << "\"" << std::endl;
        }

        void renderID(const std::string& ID) const override
        {
            std::cout << "<id>" << ID << "</id>" << std::endl;
        }
};

#endif //XMLRENDERER_H