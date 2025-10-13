#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
    std::string name;
    std::string des;
    std::string id;
    std::string img_url;
public:
    Product(const std::string& name, const std::string& des, const std::string& id, const std::string& img_url)
        : name(name), des(des), id(id), img_url(img_url) {}
    
    std::string getName() const { return name; }
    std::string getDescription() const { return des; }
    std::string getID() const { return id; }
    std::string getImageURL() const { return img_url; }
};

#endif // PRODUCT_H