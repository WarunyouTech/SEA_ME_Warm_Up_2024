#include "Contactlist.h"

// Add contact to the list
void ContactList::addContact(const Contact &contact) {
    contacts.append(contact);
}

// Remove contact from the list
void ContactList::removeContact(int index) {
    if (index >= 0 && index < contacts.size()) {
        contacts.removeAt(index);
    }
}

// Search for a contact by name
Contact ContactList::searchContact(const QString &name) const {
    for (const Contact &contact : contacts) {
        if (contact.getName() == name) {
            return contact;
        }
    }
    return Contact();  // Return empty Contact if not found
}

// Get all contacts
QList<Contact> ContactList::getContacts() const {
    return contacts;
}
