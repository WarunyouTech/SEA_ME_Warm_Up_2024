# Exercise 00 : Graphical Phonebook

This exercise involves designing a phonebook application using the Qt framework. Below is a step-by-step guide on how to approach it creatively.

## 1. Create a Qt Project

- **Goal**: Start by creating a new Qt project using the Qt Creator.
- **Tip**: Choose a "GUI application" to benefit from the visual interface.
- **Tools**: Go to `File > New Project > Qt Widgets Application`.
- **Creative Idea**: Customize the app name to something fun, like “SmartContacts” or “QuickCall”.

## 2. Create a Contact Class

- **Goal**: Design a `Contact` class in C++ that holds the contact’s details (name, phone number, email, etc.).
- **Tip**: Focus on encapsulation. Use `getters` and `setters` to manage contact details.
- **Creative Idea**: Add a contact photo, birthday, or notes field to make it more personalized.

**Example:**

```cpp
class Contact {
private:
    QString name;
    QString phoneNumber;
    QString email;
    // Add extra fields like birthday, notes
public:
    Contact(QString n, QString p, QString e) : name(n), phoneNumber(p), email(e) {}
    QString getName() const { return name; }
    QString getPhoneNumber() const { return phoneNumber; }
    QString getEmail() const { return email; }
    void setName(QString n) { name = n; }
    void setPhoneNumber(QString p) { phoneNumber = p; }
    void setEmail(QString e) { email = e; }
};
```

## 3. Create a Contact List Class

- **Goal**: Create a `ContactList` class to manage multiple contacts.
- **Tip**: Use `QVector` or `QList` to store multiple `Contact` objects.
- **Creative Idea**: Enable groupings, such as “Family”, “Friends”, or “Work”.
  
**Example:**

```cpp
class ContactList {
private:
    QVector<Contact> contacts;
public:
    void addContact(Contact c) { contacts.append(c); }
    void removeContact(QString name);
    QVector<Contact> searchContacts(QString query);
};
```

## 4. Create the User Interface (UI)

- **Goal**: Use Qt Designer to create an intuitive UI for adding, viewing, and searching contacts.
- **Tip**: Use a combination of `QPushButton`, `QLineEdit`, `QListView`, and `QLabel` widgets.
- **Creative Idea**: Use icons for buttons, and employ color themes (dark mode, light mode). You can also add a fun splash screen or animations when launching the app!

**Example UI Elements:**
- `Add Contact` button
- `Search Bar` text field
- `Contact List` view

## 5. Connect the Interface to the Contact List

- **Goal**: Use Qt's signals and slots to handle button clicks and other events.
- **Tip**: Connect the "Add Contact" button to a slot that calls `addContact()`.
- **Creative Idea**: When a contact is added, display a popup or animation confirming the addition.

**Example:**

```cpp
connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
```

## 6. Save and Load Contacts

- **Goal**: Implement functionality to save the contact list to a file (e.g., `.txt` or `.json`) and load it.
- **Tip**: Use Qt's file-handling classes like `QFile`, `QTextStream`, and `QJsonDocument`.
- **Creative Idea**: Enable export options such as saving to `.csv` for easy backup or sharing.

**Example:**

```cpp
void saveContactsToFile(QString fileName);
void loadContactsFromFile(QString fileName);
```

## 7. Implement Search Functionality

- **Goal**: Add a search bar to filter contacts by name, phone number, or other fields.
- **Tip**: Use basic string matching or regular expressions to refine search results.
- **Creative Idea**: Introduce fuzzy search or live search results (updating as the user types).

**Example:**

```cpp
QVector<Contact> searchContacts(QString query) {
    // Search logic
}
```

## 8. Add Extra Features

- **Goal**: Improve the phonebook by adding advanced features.
- **Ideas**: 
    - Edit existing contacts with a simple double-click on a contact.
    - Group contacts in categories (e.g., Family, Friends, Work).
    - Add functionality to import contacts from other sources (like Google Contacts).
    - Display contact details in card format or list format.
    - Dark mode/light mode switch.

## Final Thoughts

With these steps, you will create a functional and creative phonebook application using the Qt framework. The project can be extended with various exciting features to make it more useful and fun to interact with.
