#ifndef PRODUCTUPDATER_H
#define PRODUCTUPDATER_H

#include "baseentityupdater.h"

class ProductUpdater : public BaseEntityUpdater 
{
protected:
    bool validate(const std::string& entity, const RequestData& data) const override 
    {
        return data.body.find("spam") == std::string::npos;
    }

    void handleValidationError(const std::string& entity, const RequestData& data) const override 
    {
        std::cout << "HOOK: !!! Sending notification to admin: Product validation failed for ID "
                  << data.id << " !!!" << std::endl;
    }
};

#endif //PRODUCTUPDATER_H