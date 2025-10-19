#include <iostream>
#include <memory>
#include "windows.h"
#include "order.h"
#include "pickupstrategy.h"
#include "internalstrategy.h"
#include "thirdpartystrategy.h"

void printOrderCost(const Order& order, const std::string& strategyName)
{
    std::cout << "Загальна вартість замовлення зі стратегією '" << strategyName << "': "
              << order.getTotalCost() << std::endl;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    

    Order myOrder(500.0); 
    myOrder.setOrderWeight(10.5);   
    myOrder.setDeliveryDistance(15.0); 
    
    std::cout << "Створено замовлення вартістю " << 500.0
              << ", вагою " << 10.5 << " кг"
              << ", на відстань " << 15.0 << " км." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    PickUpStrategy pickup;
    InternalStrategy internalDelivery;
    ThirdPartyStrategy thirdPartyDelivery;

    myOrder.setDeliveryStrategy(&pickup);
    printOrderCost(myOrder, "Самовивіз");

    std::cout << "\nКлієнт змінив спосіб доставки..." << std::endl;
    myOrder.setDeliveryStrategy(&internalDelivery);
    printOrderCost(myOrder, "Внутрішня доставка");

    std::cout << "\nУмови знову змінилися..." << std::endl;
    myOrder.setDeliveryStrategy(&thirdPartyDelivery);
    printOrderCost(myOrder, "Доставка сторонньою службою");

    return 0;
}