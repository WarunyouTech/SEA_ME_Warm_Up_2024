#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Vehicle {
protected:
    int make;
    int model;
    int year;

public:
    // Default Constructor
    Vehicle() : make(0), model(0), year(0) {}

    // Parameterized Constructor
    Vehicle(int make, int model, int year) : make(make), model(model), year(year) {}

    // Copy Constructor
    Vehicle(const Vehicle& other) : make(other.make), model(other.model), year(other.year) {}

    // Virtual Destructor
    virtual ~Vehicle() {}

    // Assignment Operator
    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            make = other.make;
            model = other.model;
            year = other.year;
        }
        return *this;
    }

    // Pure Virtual Function
    virtual void drive() const = 0;

    // Setters and Getters
    void setMake(int m) { make = m; }
    void setModel(int m) { model = m; }
    void setYear(int y) { year = y; }

    int getMake() const { return make; }
    int getModel() const { return model; }
    int getYear() const { return year; }
};

class Car : public Vehicle {
protected:
    int wheelCount;

public:
    Car() : Vehicle(), wheelCount(4) {}

    Car(int make, int model, int year, int wheels) 
        : Vehicle(make, model, year), wheelCount(wheels) {}

    Car(const Car& other) : Vehicle(other), wheelCount(other.wheelCount) {}

    Car& operator=(const Car& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            wheelCount = other.wheelCount;
        }
        return *this;
    }

    void drive() const override {
        cout << "Driving Car - Make: " << make << ", Model: " << model 
             << ", Year: " << year << ", Wheels: " << wheelCount << endl;
    }
};

class UAM : public Car {
protected:
    int wingCount;

public:
    UAM() : Car(), wingCount(4) {}

    UAM(int make, int model, int year, int wheels, int wings) 
        : Car(make, model, year, wheels), wingCount(wings) {}

    UAM(const UAM& other) : Car(other), wingCount(other.wingCount) {}

    UAM& operator=(const UAM& other) {
        if (this != &other) {
            Car::operator=(other);
            wingCount = other.wingCount;
        }
        return *this;
    }

    void drive() const override {
        cout << "Operating UAM - Make: " << make << ", Model: " << model 
             << ", Year: " << year << ", Wheels: " << wheelCount 
             << ", Wings: " << wingCount << endl;
    }
};

int main() {
    // Creating Car and UAM objects
    Car myCar(1, 2023, 2023, 4);
    UAM myUAM(2, 2025, 2025, 4, 6);

    cout << "Car Details: ";
    myCar.drive();

    cout << "UAM Details: ";
    myUAM.drive();

    // Polymorphism
    vector<unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(make_unique<Car>(3, 2026, 2026, 4));
    vehicles.push_back(make_unique<UAM>(4, 2027, 2027, 6, 4));

    for (const auto& vehicle : vehicles) {
        cout << "Vehicle Details: ";
        vehicle->drive();
    }

    return 0;
}
