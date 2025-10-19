#ifndef PICKUPSTRATEGY_H
#define PICKUPSTRATEGY_H

#include "deliverystrategy.h"

class PickUpStrategy : public DeliveryStrategy
{
    public:
        double calculateCost(DeliveryDetails& details) const override
        {
            return 0.0;
        }
};

#endif // PICKUPSTRATEGY_H