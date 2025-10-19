#ifndef INTERNALSTRATEGY_H
#define INTERNALSTRATEGY_H

#include "deliverystrategy.h"

class InternalStrategy : public DeliveryStrategy
{
    public:
        double calculateCost(DeliveryDetails& details) const override
        {
            return 40.0;
        }
};

#endif // INTERNALSTRATEGY_H