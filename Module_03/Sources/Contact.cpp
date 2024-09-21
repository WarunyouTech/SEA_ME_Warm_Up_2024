#include "Contact.h"

// Constructor definition
Contact::Contact(const QString &name, const QString &phone, const QString &email)
    : name(name), phone(phone), email(email) {}

// Getter definitions
QString Contact::getName() const {
    return name;
}

QString Contact::getPhone() const {
    return phone;
}

QString Contact::getEmail() const {
    return email;
}
