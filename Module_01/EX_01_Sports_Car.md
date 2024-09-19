# Code Explanation

## Summary

The provided C++ code demonstrates the use of inheritance and polymorphism through a `Car` base class and a `SportsCar` derived class. The `Car` class encapsulates basic car details, while the `SportsCar` class extends `Car` by adding additional functionality specific to sports cars. The code includes various constructors, accessors, mutators, and a display function to showcase object-oriented programming principles.

## Input and Output

### Input

- **User Input**: 
  - For `Car`: Prompts the user to enter the car's make, name, and year of manufacture.
  - For `SportsCar`: Prompts the user to enter the car's make, name, year of manufacture, and top speed.

### Output

- **Car Details**: Prints the make, name, and year of the car.
- **SportsCar Details**: Prints the make, name, year, and top speed of the sports car.

## How the Code Works

1. **Class Definitions**:
   - **Base Class (`Car`)**:
     - **Attributes**: `make`, `name`, `year`.
     - **Constructors**:
       - **Default Constructor**: Initializes `make` to "HYUNDAI", `name` to "AVANTE", and `year` to 2014.
       - **Parameterized Constructor**: Initializes `make`, `name`, and `year` with provided values.
       - **Copy Constructor**: Initializes a new `Car` object by copying from another `Car` object.
       - **Copy Assignment Operator**: Assigns values from one `Car` object to another, with a self-assignment check.
     - **Destructor**: No special functionality but provides a message when a `Car` object is destroyed.
     - **Accessors and Mutators**: Get and set methods for `make`, `name`, and `year`.
     - **Display Function**: Prints the car's make, name, and year.
   
   - **Derived Class (`SportsCar`)**:
     - **Additional Attribute**: `top_speed`.
     - **Parameterized Constructor**: Initializes the base class attributes and `top_speed`.
     - **Override Display Function**: Calls the base class `display` method and adds the top speed to the output.
     - **Accessor and Mutator for `top_speed`**: Get and set methods for the top speed.

2. **Functions to Create Objects**:
   - **`createCar()`**: Prompts the user for car details and returns a `Car` object.
   - **`createSportsCar()`**: Prompts the user for sports car details and returns a `SportsCar` object.

3. **`main` Function**:
   - **Creates a `Car` Object**: Uses `createCar()` to get user input and displays car details.
   - **Creates a `SportsCar` Object**: Uses `createSportsCar()` to get user input and displays sports car details.

6. **Menu Options**: Displays the menu for navigating the phonebook operations.

*******************************************************
## Learn More
### Relevant YouTube Tutorials:
1. **[C++ Classes and Inheritance](https://www.youtube.com/watch?v=0ifML4n2ZbU)**
2. **[Understanding C++ Constructors and Destructors](https://www.youtube.com/watch?v=MjDNmTeB1hM)**
3. **[C++ Polymorphism and Virtual Functions](https://www.youtube.com/watch?v=xfZ_AY1lEOM)**
4. **[C++ Inheritance and Access Specifiers](https://www.youtube.com/watch?v=4aLT3ggfi0s)**
