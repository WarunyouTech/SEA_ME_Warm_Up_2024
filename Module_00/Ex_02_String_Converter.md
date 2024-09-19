# C++ Program: String Case Converter

## Summary of the Program

This C++ program converts a given string to either **uppercase** or **lowercase** based on the command-line arguments provided by the user. The user specifies an action (`up` or `down`) and provides a string. The program then either converts the string to **UPPERCASE** (if `up` is specified) or to **lowercase** (if `down` is specified). The program also offers a help option (`--help`) to explain its usage.

## Input and Output

### Input:
- **Command-line arguments**:
  - The first argument specifies the action (`up` for converting to uppercase, `down` for converting to lowercase).
  - The remaining arguments are combined to form the string that will be converted.

**Example inputs**:
- `./program up "Hello World"` (to convert "Hello World" to UPPERCASE).
- `./program down "HELLO WORLD"` (to convert "HELLO WORLD" to lowercase).
- `./program --help` (to display help instructions).

### Output:
- The program outputs the original string and the converted string based on the action.

**Example outputs**:
- For `./program up "Hello World"`:
  ```bash
  Original String: Hello World
  Converted to UPPERCASE: HELLO WORLD
  
*******************************************************
## Learn More: String Case Conversion with Command-Line Arguments

This C++ program converts a given string to either uppercase or lowercase based on the command-line arguments provided by the user. The user specifies an action (`up` for uppercase, `down` for lowercase) and the program performs the conversion. The program also offers a help option (`--help`) to explain its usage.

### Relevant YouTube Tutorials
1. [Convert String to Lowercase or Uppercase Using Command Line Arguments in C](https://www.youtube.com/watch?v=bDJ6JcCAITg)
2. [C++ Command Line Arguments String Case Conversion](https://www.youtube.com/watch?v=LV0ZsyOChGs)
