#ifndef BASEENTITYUPDATER_H
#define BASEENTITYUPDATER_H

#include <string>
#include <iostream>

struct RequestData {
    int id;
    std::string body;
};

struct Response {
    int statusCode;
    std::string statusMessage;
    std::string body;
};

void printResponse(const Response& res) {
    std::cout << "--> Response <--\n"
              << "Status Code: " << res.statusCode << "\n"
              << "Message: " << res.statusMessage << "\n"
              << "Body: " << res.body << "\n"
              << "----------------\n";
}

class BaseEntityUpdater
{
    public:
        Response update(const RequestData& data) const
        {
            std::cout << "\n--- Starting update process for ID: " << data.id << " ---" << std::endl;

            std::string entity = getEntity(data.id);
            bool isValid = validate(entity, data);
            if (!isValid)
            {
                handleValidationError(entity,data);
                return createErrorResponse("Validation Error!");
            }
            std::string saveRequest = buildSaveRequest(entity, data);
            std::cout << "Step 3: Built save request: \"" << saveRequest << "\"" << std::endl;
            std::string updatedEntity = save(saveRequest);
            return formatSuccessResponse(updatedEntity);
        }
        virtual ~BaseEntityUpdater() = default;
    protected:

        virtual bool validate(const std::string& entity, const RequestData& data) const {};

        virtual Response formatSuccessResponse(const std::string& updatedEntity) const 
        {
            return {200, "OK", ""};
        }
        virtual void handleValidationError(const std::string& entity, const RequestData& data) const {};

    private:

        std::string getEntity(int id) const {
            // Імітація завантаження даних з бази
            return "Existing data for ID: " + std::to_string(id);
        }

        std::string buildSaveRequest(const std::string& entity, const RequestData& data) const {
            return "Save request with data: " + data.body;
        }

        std::string save(const std::string& saveRequest) const {
            // Імітація збереження
            return "Successfully saved entity from request: \"" + saveRequest + "\"";
        }

        Response createErrorResponse(const std::string& message) const {
            return {400, "Bad Request", message};
        }
        
};

#endif // BASEENTITYUPDATER_H