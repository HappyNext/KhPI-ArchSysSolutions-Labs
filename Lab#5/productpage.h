#ifndef PRODUCTPAGE_H
#define PRODUCTPAGE_H

#include "page.h"
#include "product.h"

class ProductPage : public Page
{
    Product product;
    public:
        ProductPage(const Product& prod, const Renderer& rend) : product(prod), Page(rend) {}
        void render()
        {
            renderer.renderTitle(product.getName());
            renderer.renderText(product.getDescription());
            renderer.renderImage(product.getImageURL());
            renderer.renderID(product.getID());
        }
};

#endif // PRODUCTPAGE_H