#include <iostream>
#include <vector>
#include <map>

// Contact structure
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool isBookmarked = false;
};

// Phonebook and map for quick access
std::vector<Contact> phonebook;
std::map<std::string, int> phoneMap;

// Helper function to get user input
std::string getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin.ignore();
    getline(std::cin, input);
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
        std::cout << "Error: This phone number already exists. Try a different number.\n";
        return;
    }

    newContact.nickname = getInput("Enter Nickname: ");
    std::cout << "Bookmark this contact? (y/n): ";
    std::cin >> bookmarkStatus;

    newContact.isBookmarked = (bookmarkStatus == "y");

    phonebook.push_back(newContact);
    phoneMap[newContact.phoneNumber] = phonebook.size() - 1;

    std::cout << "Contact added successfully.\n";
}

// Function to search contacts
void searchContact() {
    std::string searchQuery = getInput("Enter Name or Phone Number: ");

    std::vector<int> matchingContacts;
    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].name == searchQuery || phonebook[i].phoneNumber == searchQuery) {
            matchingContacts.push_back(i);
            std::cout << "Index: " << i << " | Name: " << phonebook[i].name << " | Phone: " << phonebook[i].phoneNumber << std::endl;
        }
    }

    if (matchingContacts.empty()) {
        std::cout << "No matching contacts found.\n";
        return;
    }

    int index;
    std::cout << "Enter index to view details or -1 to cancel: ";
    std::cin >> index;

    if (index >= 0 && index < phonebook.size()) {
        std::cout << "\n--- Contact Details ---\n";
        std::cout << "Name: " << phonebook[index].name << std::endl;
        std::cout << "Phone Number: " << phonebook[index].phoneNumber << std::endl;
        std::cout << "Nickname: " << phonebook[index].nickname << std::endl;
        std::cout << "Bookmarked: " << (phonebook[index].isBookmarked ? "Yes" : "No") << std::endl;

        std::string bookmark;
        std::cout << "Would you like to bookmark this contact? (y/n): ";
        std::cin >> bookmark;
        phonebook[index].isBookmarked = (bookmark == "y");
    }
    else if (index != -1) {
        std::cout << "Invalid index.\n";
    }
}

// Function to remove a contact
void removeContact() {
    std::string removalQuery = getInput("Enter Phone Number to Remove: ");

    auto it = phoneMap.find(removalQuery);
    if (it != phoneMap.end()) {
        int index = it->second;
        phoneMap.erase(removalQuery);
        phonebook.erase(phonebook.begin() + index);

        // Update phoneMap for remaining contacts
        for (int i = index; i < phonebook.size(); ++i) {
            phoneMap[phonebook[i].phoneNumber] = i;
        }

        std::cout << "Contact removed successfully.\n";
    } else {
        std::cout << "No contact found with that phone number.\n";
    }
}

// Function to display bookmarked contacts
void showBookmarks() {
    std::cout << "--- Bookmarked Contacts ---\n";
    bool hasBookmarks = false;
    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].isBookmarked) {
            hasBookmarks = true;
            std::cout << i << ". " << phonebook[i].name << " | " << phonebook[i].phoneNumber << std::endl;
        }
    }
    if (!hasBookmarks) {
        std::cout << "No contacts are bookmarked.\n";
    }
}

int main() {
    std::string command;
    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            addContact();
        } else if (command == "SEARCH") {
            searchContact();
        } else if (command == "REMOVE") {
            removeContact();
        } else if (command == "BOOKMARK") {
            showBookmarks();
        } else if (command == "EXIT") {
            std::cout << "Exiting the phonebook. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
