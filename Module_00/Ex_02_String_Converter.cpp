#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Utility class to convert strings to upper or lower case
class CaseConverter {
public:
    // Convert a string to uppercase
    static string toUpperCase(const string &input) {
        string result = input;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    // Convert a string to lowercase
    static string toLowerCase(const string &input) {
        string result = input;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

// Function to join command-line arguments into a single string
string joinArguments(int argc, char *argv[], int startIndex) {
    string combinedInput;
    for (int i = startIndex; i < argc; ++i) {
        if (i > startIndex) combinedInput += " ";
        combinedInput += argv[i];
    }
    return combinedInput;
}

// Function to display usage information to the user
void displayUsage(const char *programName) {
    cerr << "Usage: " << programName << " <up|down> <string to convert>" << endl;
    cerr << "Example: " << programName << " up \"Hello World\"" << endl;
}

// Function to display help information when requested
void displayHelp() {
    cout << "This program converts a given string to either UPPERCASE or lowercase." << endl;
    cout << "Commands:" << endl;
    cout << "  up    - Convert the string to UPPERCASE." << endl;
    cout << "  down  - Convert the string to lowercase." << endl;
    cout << "Example Usage:" << endl;
    cout << "  ./program up \"Hello World\"" << endl;
    cout << "  ./program down \"HELLO WORLD\"" << endl;
}

int main(int argc, char *argv[]) {
    // If the user requests help
    if (argc == 2 && string(argv[1]) == "--help") {
        displayHelp();
        return 0;
    }

    // Validate that the required arguments are provided
    if (argc < 3) {
        cerr << "Error: Missing arguments." << endl;
        displayUsage(argv[0]);
        return 1;
    }

    // Extract the action (up or down) from the first argument
    string action = argv[1];
    
    // Join the remaining arguments into a single string to be converted
    string inputString = joinArguments(argc, argv, 2);

    // Perform the conversion based on the action
    if (action == "up") {
        cout << "Original String: " << inputString << endl;
        cout << "Converted to UPPERCASE: " << CaseConverter::toUpperCase(inputString) << endl;
    } else if (action == "down") {
        cout << "Original String: " << inputString << endl;
        cout << "Converted to lowercase: " << CaseConverter::toLowerCase(inputString) << endl;
    } else {
        // Handle unknown actions
        cerr << "Error: Unknown action '" << action << "'." << endl;
        displayUsage(argv[0]);
        return 1;
    }

    return 0;
}
