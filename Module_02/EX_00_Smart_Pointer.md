# Code Explanation

## Summary

The provided C++ code demonstrates the use of smart pointers: `unique_ptr`, `shared_ptr`, and `weak_ptr`. The `Car` class represents a car with a model name, and the code showcases how to manage object lifetimes and ownership with these smart pointers.

## Code Breakdown

### `Car` Class

- **Attributes**: 
  - `model`: A `string` representing the car model.
  
- **Constructors and Destructor**:
  - **Constructor**: Initializes the `model` and prints a message indicating that a car has been created.
  - **Destructor**: Prints a message indicating that a car has been destroyed.

- **Methods**:
  - `drive()`: Prints a message indicating that the car is being driven.

### `main` Function

1. **Unique Pointer Demonstration**:
   - **Creation**:
     ```cpp
     unique_ptr<Car> car1 = make_unique<Car>("Volkswagen");
     ```
     A `unique_ptr` named `car1` is created, managing a `Car` object with the model "Volkswagen". The `Car` object is created, and the message "Car Volkswagen created." is printed.
   
   - **Driving the Car**:
     ```cpp
     car1->drive();
     ```
     The `drive()` method is called on `car1`, printing "Driving Volkswagen.".
   
   - **Transfer Ownership**:
     ```cpp
     unique_ptr<Car> car2 = move(car1);
     ```
     Ownership of the `Car` object is transferred from `car1` to `car2`. After this, `car1` no longer owns the car. A message is printed to indicate that `car1` no longer owns the Volkswagen. The `drive()` method is then called on `car2`, printing "Driving Volkswagen.".

2. **Shared Pointer Demonstration**:
   - **Creation**:
     ```cpp
     shared_ptr<Car> car3 = make_shared<Car>("Porsche 911");
     ```
     A `shared_ptr` named `car3` is created, managing a `Car` object with the model "Porsche 911". The `Car` object is created, and the message "Car Porsche 911 created." is printed.

   - **Shared Ownership**:
     ```cpp
     shared_ptr<Car> car4 = car3;
     ```
     `car4` shares ownership of the `Car` object with `car3`. The `drive()` method is called on `car4`, and the shared ownership count is printed.
   
   - **Ownership Count**:
     ```cpp
     cout << "Shared ownership count: " << car3.use_count() << endl;
     ```
     The ownership count is printed, showing how many `shared_ptr` instances own the `Car` object.

   - **Out of Scope**:
     ```cpp
     // car4 goes out of scope here
     ```
     When `car4` goes out of scope, it no longer owns the `Car` object, but `car3` still does. The ownership count is printed again to reflect the change.

3. **Weak Pointer Demonstration**:
   - **Creation**:
     ```cpp
     weak_ptr<Car> weakCar = car3;
     ```
     A `weak_ptr` named `weakCar` is created. It observes the `Car` object managed by `car3` but does not affect the reference count.

   - **Accessing the Car**:
     ```cpp
     if (auto sharedCar = weakCar.lock()) {
         sharedCar->drive();
     } else {
         cout << "Car no longer exists.\n";
     }
     ```
     The `lock()` method is used to attempt to create a `shared_ptr` from `weakCar`. If the `Car` object still exists, it prints "Weak pointer can access the car:" followed by "Driving Porsche 911." If not, it prints "Car no longer exists."

*******************************************************
## Learn More: Smart Pointers in C++
### Relevant YouTube Tutorials:
1. [++ POINTERS FULL COURSE Beginner to Advanced](https://www.youtube.com/watch?v=kiUGf_Z08RQ)
2. [Understanding Unique, Shared, and Weak Pointers](https://www.youtube.com/watch?v=UOB7-B2MfwA)
3. [Object Oriented Programming in C++ | C++ OOPs Concepts | Learn Object Oriented C++](https://www.youtube.com/watch?v=_SH1T3y_D7o)
