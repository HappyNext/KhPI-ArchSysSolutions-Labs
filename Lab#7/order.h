#ifndef ORDER_H
#define ORDER_H

#include "deliverystrategy.h"
#include "deliverydetails.h"
#include <memory>

class Order
{
    DeliveryStrategy* deliveryStrategy;
    double orderCost;
    double orderWeight;
    double deliveryDistance;
    public:
        Order(double cost): orderCost(cost) {}
        void setOrderCost(double cost)
        {
            orderCost = cost;
        }
        void setDeliveryStrategy(DeliveryStrategy* strategy)
        {
            deliveryStrategy = strategy;
        }
        void setDeliveryDistance(double distance)
        {
            deliveryDistance = distance;
        }
        void setOrderWeight(double weight)
        {
            orderWeight = weight;
        }
        double getTotalCost() const 
        {
            DeliveryDetails details;
            details.weight = this->deliveryDistance;
            details.distance = this->orderWeight;
            
            return orderCost + deliveryStrategy->calculateCost(details);
        }
};

#endif // ORDER_H