#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
    // Constructor
    Contact(const QString &name = "", const QString &phone = "", const QString &email = "");

    // Getter functions
    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;

private:
    QString name;
    QString phone;
    QString email;
};

#endif // CONTACT_H
