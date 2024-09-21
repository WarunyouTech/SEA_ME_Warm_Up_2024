#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QList>

class ContactList {
public:
    void addContact(const Contact &contact);
    void removeContact(int index);
    Contact searchContact(const QString &name) const;
    QList<Contact> getContacts() const;

private:
    QList<Contact> contacts;  // List of Contact objects
};

#endif // CONTACTLIST_H
