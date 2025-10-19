#include <iostream>
#include <memory>
#include "productupdater.h"
#include "userupdater.h"
#include "orderupdater.h"

int main() 
{
    auto productUpdater = std::make_unique<ProductUpdater>();
    auto userUpdater = std::make_unique<UserUpdater>();
    auto orderUpdater = std::make_unique<OrderUpdater>();

    RequestData invalidProductData = {101, "invalid product data"};
    Response res1 = productUpdater->update(invalidProductData);
    printResponse(res1);

    RequestData changeEmailData = {202, "body with email change"};
    Response res2 = userUpdater->update(changeEmailData);
    printResponse(res2);
    
    RequestData validOrderData = {303, "Set status to 'shipped'"};
    Response res3 = orderUpdater->update(validOrderData);
    printResponse(res3);

    return 0;
}