#ifndef SMSNOTIFICATIONADAPTER_H
#define SMSNOTIFICATIONADAPTER_H

#include "notification.h"
#include "smsclient.h"

class SMSNotificationAdapter : public Notification
{
    SMSClient* sms;
    std::string phone;
    public:
        SMSNotificationAdapter(const std::string& sender, const std::string& phone)
        {
            sms = new SMSClient(sender);
            this->phone = phone;
        };
        ~SMSNotificationAdapter()
        {
            delete sms;
        };
        void send(const std::string& title, const std::string& message) override
        {
            std::string text = title + ": " + message;
            sms->sendSMS(phone, text);
        };
};

#endif // SMSNOTIFICATIONADAPTER_H