#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

#include "order.h"
#include "deliverydetails.h"

class DeliveryStrategy
{
    public:
        virtual ~DeliveryStrategy() = default;
        virtual double calculateCost(DeliveryDetails& details) const = 0;
};

#endif // DELIVERYSTRATEGY_H