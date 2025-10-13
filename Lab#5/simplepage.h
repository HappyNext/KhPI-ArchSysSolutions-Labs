#ifndef SIMPLEPAGE_H
#define SIMPLEPAGE_H

#include "page.h"

class SimplePage : public Page
{
    std::string title;
    std::string content;
    public:
        SimplePage(const std::string& t, const std::string& c, const Renderer& rend) : title(t), content(c), Page(rend) {}
        void render()
        {
            renderer.renderTitle(title);
            renderer.renderText(content);
        }

};
#endif // SIMPLEPAGE_H