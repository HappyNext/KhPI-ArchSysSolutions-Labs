#ifndef PAGE_H
#define PAGE_H

#include "renderer.h"

class Page
{
    protected:
        const Renderer& renderer;
    public:
        Page(const Renderer& rend): renderer(rend) {}
        virtual ~Page() = default;
        virtual void render() = 0;
};

#endif // PAGE_H