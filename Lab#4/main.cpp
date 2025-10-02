#include <iostream>

#include "emailnotification.h"
#include "slacknotificationadapter.h"
#include "smsnotificationadapter.h"

int main()
{
    // Відправка email
    Notification* emailNotifier = new EmailNotification("admin@example.com");
    emailNotifier->send("Important notice", "Details here.");
    delete emailNotifier;

    // Відправка в Slack
    Notification* slackNotifier = new SlackNotificationAdapter("user_login", "api_key_123", 151414);
    slackNotifier->send("Important notice", "Details here.");
    delete slackNotifier;

    // Відправка SMS
    Notification* smsNotifier = new SMSNotificationAdapter("System","+380987229388");
    smsNotifier->send("Important notice", "Details here.");
    delete smsNotifier;

    return 0;
}