#ifndef THIRDPARTYSTRATEGY_H
#define THIRDPARTYSTRATEGY_H

#include "deliverystrategy.h"

class ThirdPartyStrategy : public DeliveryStrategy
{
    public:
        double calculateCost(DeliveryDetails& details) const override
        {
            return 55.0;
        }
};

#endif // THIRDPARTYSTRATEGY_H