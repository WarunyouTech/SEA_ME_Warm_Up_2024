#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

// Utility class for case conversion
class CaseConverter {
public:
    // Convert string to uppercase
    static string toUpperCase(const string &str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    // Convert string to lowercase
    static string toLowerCase(const string &str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

// Function to display usage instructions
void printUsage(const char *programName) {
    cout << "Usage: " << programName << " <up|down> <string to convert>" << endl;
    cout << "Example: " << programName << " up \"Hello World\"" << endl;
}

// Function to validate the number of arguments
bool validateArguments(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Error: Insufficient arguments provided." << endl;
        printUsage(argv[0]);
        return false;
    }
    return true;
}

// Function to combine all arguments into a single string
string combineArguments(int argc, char *argv[]) {
    string combinedString;
    for (int i = 2; i < argc; ++i) {
        if (i > 2) combinedString += " ";  // Add space between words
        combinedString += argv[i];
    }
    return combinedString;
}

// Function to process the user's action: uppercase or lowercase
void processConversion(const string &action, const string &input) {
    if (action == "up") {
        cout << "Converting to UPPERCASE..." << endl;
        cout << "Result: " << CaseConverter::toUpperCase(input) << endl;
    } else if (action == "down") {
        cout << "Converting to lowercase..." << endl;
        cout << "Result: " << CaseConverter::toLowerCase(input) << endl;
    } else {
        cerr << "Error: Invalid action '" << action << "' provided." << endl;
        cerr << "Please choose 'up' for uppercase or 'down' for lowercase." << endl;
    }
}

int main(int argc, char *argv[]) {
    cout << "argc: " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }

    // Validate the number of arguments
    if (!validateArguments(argc, argv)) {
        return 1;
    }

    // Store the action ('up' or 'down') and combine the input string
    string action(argv[1]);
    string input = combineArguments(argc, argv);

    // Process the conversion based on the action
    processConversion(action, input);

    return 0;
}
