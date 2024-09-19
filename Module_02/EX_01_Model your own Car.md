# Code Explanation

## Summary

The provided C++ code demonstrates the use of object-oriented programming principles to model a `Car` with various components. Each component is represented by a class that inherits from an abstract base class `Part`. The `Car` class aggregates these components and provides methods to display their details and simulate a test drive.

## Code Breakdown

### Abstract `Part` Class

- **Purpose**: Acts as a base class for all car components.
- **Methods**:
  - `virtual void display() const = 0;`: Pure virtual function for displaying part details. This makes `Part` an abstract class.
  - `virtual ~Part() = default;`: Virtual destructor to ensure derived class destructors are called correctly during deletion.

### Derived Classes

Each derived class represents a specific car component and inherits from `Part`. They implement the `display()` method to show details specific to that component.

1. **Engine Class**:
   - **Attributes**: `model` (the engine model).
   - **Methods**:
     - `void display() const override`: Prints the engine model.

2. **Wheel Class**:
   - **Attributes**: `size` (the wheel size).
   - **Methods**:
     - `void display() const override`: Prints the wheel size.

3. **Brake Class**:
   - **Attributes**: `type` (the brake type).
   - **Methods**:
     - `void display() const override`: Prints the brake type.

4. **Transmission Class**:
   - **Attributes**: `type` (the transmission type).
   - **Methods**:
     - `void display() const override`: Prints the transmission type.

5. **Light Class**:
   - **Attributes**: `type` (the light type).
   - **Methods**:
     - `void display() const override`: Prints the light type.

6. **Battery Class**:
   - **Attributes**: `capacity` (the battery capacity).
   - **Methods**:
     - `void display() const override`: Prints the battery capacity.

### `Car` Class

- **Purpose**: Represents a car composed of various components.
- **Attributes**:
  - `model`: The car model.
  - `engine`: A `unique_ptr` to an `Engine` object.
  - `wheels`: A vector of `unique_ptr`s to `Wheel` objects.
  - `brakes`: A vector of `unique_ptr`s to `Brake` objects.
  - `transmission`: A `unique_ptr` to a `Transmission` object.
  - `lights`: A vector of `unique_ptr`s to `Light` objects.
  - `battery`: A `unique_ptr` to a `Battery` object.

- **Methods**:
  - `Car(const std::string& model)`: Constructor that initializes all components with specific values.
  - `void displayParts() const`: Displays details of all components.
  - `void testDrive() const`: Simulates a test drive, printing a narrative of the driving experience.

### `main` Function

- **Purpose**: Demonstrates the usage of the `Car` class.
- **Steps**:
  - Creates a `Car` object (`porsche_911_Turbo`) with the model "911 Turbo".
  - Calls `displayParts()` to print the details of all car components.
  - Calls `testDrive()` to simulate and print the driving experience.
