#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

// Contact structure
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool isBookmarked = false;
};

// Phonebook data
std::vector<Contact> phonebook;
std::map<std::string, int> phoneMap;  // Map to store phone number to index

// Function to get input from the user
std::string getInput(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::cin.ignore();
    std::getline(std::cin, input);
    return input;
}

// Function to add a contact
void addContact() {
    Contact newContact;
    std::string bookmarkStatus;

    newContact.name = getInput("Enter Name: ");
    newContact.phoneNumber = getInput("Enter Phone number: ");

    // Validate that the phone number doesn't already exist
    if (phoneMap.find(newContact.phoneNumber) != phoneMap.end()) {
        std::cout << "Error: This phone number already exists.\n";
        return;
    }

    newContact.nickname = getInput("Enter Nickname: ");
    std::cout << "Bookmark this contact? (y/n): ";
    std::cin >> bookmarkStatus;

    newContact.isBookmarked = (bookmarkStatus == "y");

    // Add contact to phonebook and map
    phonebook.push_back(newContact);
    phoneMap[newContact.phoneNumber] = phonebook.size() - 1;

    std::cout << "Contact added successfully.\n";
}

// Function to search contacts
void searchContact() {
    std::string query = getInput("Enter Name or Phone Number to Search: ");
    std::vector<int> foundIndices;

    // Search by name or phone number
    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].name.find(query) != std::string::npos || phonebook[i].phoneNumber == query) {
            foundIndices.push_back(i);
            std::cout << i << ". " << phonebook[i].name << " | " << phonebook[i].phoneNumber << std::endl;
        }
    }

    if (foundIndices.empty()) {
        std::cout << "No matching contacts found.\n";
        return;
    }

    int index;
    std::cout << "Enter index to view details (-1 to cancel): ";
    std::cin >> index;

    if (index >= 0 && index < phonebook.size()) {
        Contact &contact = phonebook[index];
        std::cout << "\n--- Contact Details ---\n";
        std::cout << "Name: " << contact.name << "\n";
        std::cout << "Phone Number: " << contact.phoneNumber << "\n";
        std::cout << "Nickname: " << contact.nickname << "\n";
        std::cout << "Bookmarked: " << (contact.isBookmarked ? "Yes" : "No") << "\n";

        std::string bookmarkChoice;
        std::cout << "Bookmark this contact? (y/n): ";
        std::cin >> bookmarkChoice;
        contact.isBookmarked = (bookmarkChoice == "y");
    } else if (index != -1) {
        std::cout << "Invalid index.\n";
    }
}

// Function to remove a contact
void removeContact() {
    std::string query = getInput("Enter Phone Number or Name to Remove: ");

    // Try to find the contact by phone number
    auto it = phoneMap.find(query);
    if (it != phoneMap.end()) {
        int index = it->second;
        phonebook.erase(phonebook.begin() + index);
        phoneMap.erase(query);
        std::cout << "Contact removed successfully.\n";
    } else {
        std::cout << "No contact found with that phone number.\n";
    }
}

// Function to list bookmarked contacts
void listBookmarks() {
    std::cout << "--- Bookmarked Contacts ---\n";
    bool found = false;
    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].isBookmarked) {
            found = true;
            std::cout << i << ". " << phonebook[i].name << " | " << phonebook[i].phoneNumber << std::endl;
        }
    }
    if (!found) {
        std::cout << "No contacts are bookmarked.\n";
    }
}

// Function to edit an existing contact
void editContact() {
    std::string query = getInput("Enter Phone Number of Contact to Edit: ");
    
    auto it = phoneMap.find(query);
    if (it == phoneMap.end()) {
        std::cout << "No contact found with that phone number.\n";
        return;
    }

    int index = it->second;
    Contact &contact = phonebook[index];

    std::cout << "Editing Contact: " << contact.name << " | " << contact.phoneNumber << std::endl;
    contact.name = getInput("Enter new Name (or press Enter to keep unchanged): ");
    contact.nickname = getInput("Enter new Nickname (or press Enter to keep unchanged): ");
    std::string bookmarkStatus;
    std::cout << "Bookmark this contact? (y/n): ";
    std::cin >> bookmarkStatus;
    contact.isBookmarked = (bookmarkStatus == "y");

    std::cout << "Contact updated successfully.\n";
}

// Function to display the menu
void displayMenu() {
    std::cout << "\n--- PHONEBOOK MENU ---\n";
    std::cout << "1. ADD Contact\n";
    std::cout << "2. SEARCH Contact\n";
    std::cout << "3. REMOVE Contact\n";
    std::cout << "4. VIEW Bookmarked Contacts\n";
    std::cout << "5. EDIT Contact\n";
    std::cout << "6. EXIT\n";
    std::cout << "Enter your choice: ";
}

// Main function
int main() {
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                removeContact();
                break;
            case 4:
                listBookmarks();
                break;
            case 5:
                editContact();
                break;
            case 6:
                std::cout << "Exiting the phonebook. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
