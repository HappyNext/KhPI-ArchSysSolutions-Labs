#ifndef USERUPDATER_H
#define USERUPDATER_H

#include "baseentityupdater.h"

class UserUpdater : public BaseEntityUpdater
{
    protected:
        bool validate(const std::string& entity, const RequestData& data) const override {
        std::cout << "Step 2: Running USER validation." << std::endl;
        // Умова: заборонено змінювати email
        if (data.body.find("email") != std::string::npos) {
            std::cout << "Validation failed: Attempt to change email." << std::endl;
            return false;
        }
        return true;
    }
};

#endif // USERUPDATER_H