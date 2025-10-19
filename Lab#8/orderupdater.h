#ifndef ORDERUPDATER_H
#define ORDERUPDATER_H

#include "baseentityupdater.h"

class OrderUpdater : public BaseEntityUpdater
{
    protected:
        bool validate(const std::string& entity, const RequestData& data) const override 
        {
            std::cout << "Step 2: Running ORDER validation." << std::endl;
            if (data.body.empty()) {
                return false;
            }
            return true;
        }

        Response formatSuccessResponse(const std::string& updatedEntity) const override 
        {
            std::cout << "Step 4: Formatting custom success response for Order." << std::endl;
            std::string jsonBody = "{ \"status\": \"success\", \"entity\": \"" + updatedEntity + "\" }";
            return {200, "OK", jsonBody};
        }
};

#endif // ORDERUPDATER_H