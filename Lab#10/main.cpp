#include <iostream>
#include "Windows.h"
#include "orderformmediator.h"

void displayFormStatus(const std::vector<Component*>& components) 
{
    std::cout << "\n--- ПОТОЧНИЙ СТАН ФОРМИ ---" << std::endl;
    for (const auto& component : components) {
        component->displayStatus();
    }
    std::cout << "---------------------------------" << std::endl;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    OrderFormMediator mediator;
    DatePicker datePicker;
    TimePicker timePicker;
    AnotherRecipientCheckBox anotherRecipientCheckbox;
    RecipientNameInput recipientNameInput;
    RecipientPhoneInput recipientPhoneInput;
    PickUpCheckBox pickupCheckbox;
    AddressInput addressInput;
    
    std::vector<Component*> components = {
        &datePicker, &timePicker, &anotherRecipientCheckbox, &recipientNameInput, 
        &recipientPhoneInput, &pickupCheckbox, &addressInput
    };
    
    for (auto& component : components) component->setMediator(&mediator);
    
    mediator.setComponents(&datePicker, &timePicker, &anotherRecipientCheckbox,
                          &recipientNameInput, &recipientPhoneInput,
                          &pickupCheckbox, &addressInput);
    
    std::cout << "Початковий стан форми: " << std::endl;
    displayFormStatus(components);

    std::cout << "\n>>> Сценарій 1: Користувач обирає дату" << std::endl;
    datePicker.selectDate("2025-12-25");
    displayFormStatus(components);
    
    std::cout << "\n>>> Сценарій 2: Користувач вказує, що отримувач - інша особа" << std::endl;
    anotherRecipientCheckbox.check(true);
    displayFormStatus(components);
    
    std::cout << "\n>>> Сценарій 3: Користувач вирішує забрати замовлення самостійно" << std::endl;
    pickupCheckbox.check(true);
    displayFormStatus(components);

    std::cout << "\n>>> Сценарій 4: Користувач передумав і хоче доставку" << std::endl;
    pickupCheckbox.check(false);
    displayFormStatus(components);

    return 0;
}