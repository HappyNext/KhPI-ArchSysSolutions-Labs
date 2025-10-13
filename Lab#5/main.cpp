#include <iostream>
#include "windows.h"
#include "product.h"
#include "htmlrenderer.h"
#include "jsonrenderer.h"
#include "simplepage.h"
#include "productpage.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Product laptop("HP", "Потужний ноутбук", "lp-4884", "/images/laptop.img");

    HTMLRenderer htmlrenderer;
    JSONRenderer jsonrenderer;

    SimplePage simple_page_html("Головна", "Ласкаво просимо!", htmlrenderer);
    ProductPage product_page_html(laptop, htmlrenderer);

    std::cout << "\nПроста сторінка в HTML:\n";
    simple_page_html.render();
    std::cout << std::endl;

    std::cout << "\nСторінка продукту в HTML:\n";
    product_page_html.render();
    std::cout << std::endl;

    SimplePage simple_json_page("Головна", "Ласкаво просимо!", jsonrenderer);
    ProductPage product_json_page(laptop, jsonrenderer);

    std::cout << "\nПроста сторінка в JSON:\n";
    simple_json_page.render();
    std::cout << std::endl;

    std::cout << "\nСторінка продукту в JSON:\n";
    product_json_page.render();
    std::cout << std::endl;

    return 0;
}