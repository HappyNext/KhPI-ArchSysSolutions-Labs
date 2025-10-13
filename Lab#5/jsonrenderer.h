#ifndef JSONRENDERER_H
#define JSONRENDERER_H

#include "renderer.h"

class JSONRenderer : public Renderer
{
    public:
        void renderTitle(const std::string& title) const override
        {
            std::cout << "{\"title\": \"" << title << "\"}" << std::endl;
        }

        void renderText(const std::string& text) const override
        {
            std::cout << "{\"text\": \"" << text << "\"}" << std::endl;
        }

        void renderImage(const std::string& url) const override
        {
            std::cout << "{\"image_url\": \"" << url << "\"}" << std::endl;
        }

        void renderID(const std::string& ID) const override
        {
            std::cout << "{\"id\": \"" << ID << "\"}" << std::endl;
        }
};

#endif // JSONRENDERER_H