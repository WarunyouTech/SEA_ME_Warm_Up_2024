# Code Summary and Explanation

## Overview

The provided C++ code demonstrates object-oriented programming concepts with a hierarchy of classes representing vehicles. It includes a `Vehicle` base class, a `Car` derived class, and a `UAM` (Urban Air Mobility) class extending `Car`. The code showcases inheritance, polymorphism, and the use of smart pointers.

## Class Definitions

### `Vehicle` Class

- **Purpose**: Base class for all vehicle types.
- **Members**:
  - **Protected**: `make`, `model`, `year` (attributes of the vehicle).
  - **Public**:
    - **Constructors**: Default, Parameterized, Copy Constructor.
    - **Destructor**: Virtual to ensure proper cleanup of derived classes.
    - **Assignment Operator**: Copies attributes from one `Vehicle` to another.
    - **Pure Virtual Function `drive()`**: Must be implemented by derived classes.
    - **Setters and Getters**: For `make`, `model`, and `year`.

### `Car` Class

- **Inherits**: Publicly from `Vehicle`.
- **Purpose**: Represents a car with additional attributes.
- **Members**:
  - **Protected**: `wheelCount` (number of wheels).
  - **Public**:
    - **Constructors**: Default, Parameterized, Copy Constructor.
    - **Assignment Operator**: Copies attributes from one `Car` to another.
    - **`drive()` Method**: Prints details about the car.

### `UAM` Class

- **Inherits**: Publicly from `Car`.
- **Purpose**: Represents an Urban Air Mobility vehicle, extending the `Car` class with additional features.
- **Members**:
  - **Protected**: `wingCount` (number of wings).
  - **Public**:
    - **Constructors**: Default, Parameterized, Copy Constructor.
    - **Assignment Operator**: Copies attributes from one `UAM` to another.
    - **`drive()` Method**: Prints details about the UAM.

## Main Function

1. **Object Creation**:
   - Creates instances of `Car` and `UAM` with specific attributes.

2. **Display Details**:
   - Calls the `drive()` method on `Car` and `UAM` objects to display their details.

3. **Polymorphism**:
   - Uses a `vector` of `unique_ptr<Vehicle>` to store and manage `Car` and `UAM` objects.
   - Demonstrates polymorphism by calling the `drive()` method on base class pointers, which invokes the overridden methods in derived classes.

## Input and Output

**Output**:
- Displays details of a `Car` and a `UAM` object.
- Iterates through a collection of `Vehicle` pointers and displays details for each vehicle.

*******************************************************
## Learn More: A Software Defined Car
### Relevant YouTube Tutorials:
1. [Object Oriented Programming (OOP) in C++ Course](https://www.youtube.com/watch?v=wN0x9eZLix4)
2. [Constructors And Destructors In C++](https://www.youtube.com/watch?v=oRBK0Mh_gG0)
3. [C++ Polymorphism Tutorial](https://www.youtube.com/watch?v=pcMSlWLKzOE)
4. [MART POINTERS in C++](https://www.youtube.com/watch?v=e2LMAgoqY_k)
5. [C++ OOP - What is inheritance in programming?](https://www.youtube.com/watch?v=-W-TYjL0aFE)
