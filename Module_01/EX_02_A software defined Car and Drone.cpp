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

    // Virtual Drive Function
    virtual void drive() const = 0;

    // Setters and Getters
    void setMake(int m) { make = m; }
    void setModel(int m) { model = m; }
    void setYear(int y) { year = y; }

    int getMake() const { return make; }
    int getModel() const { return model; }
    int getYear() const { return year; }
};

class Car : public virtual Vehicle {
protected:
    int wheelCount;

public:
    Car() : Vehicle(), wheelCount(4) {}

    Car(int make, int model, int year, int wheels) 
        : Vehicle(make, model, year), wheelCount(wheels) {}

    Car(const Car& other) : Vehicle(other), wheelCount(other.wheelCount) {}

    ~Car() override {}

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

class Drone : public virtual Vehicle {
protected:
    int wingCount;

public:
    Drone() : Vehicle(), wingCount(4) {}

    Drone(int make, int model, int year, int wings) 
        : Vehicle(make, model, year), wingCount(wings) {}

    Drone(const Drone& other) : Vehicle(other), wingCount(other.wingCount) {}

    ~Drone() override {}

    Drone& operator=(const Drone& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            wingCount = other.wingCount;
        }
        return *this;
    }

    void drive() const override {
        cout << "Flying Drone - Make: " << make << ", Model: " << model 
             << ", Year: " << year << ", Wings: " << wingCount << endl;
    }
};

class UAM : public Car, public Drone {
public:
    UAM() : Vehicle(), Car(), Drone() {}

    UAM(int make, int model, int year, int wings, int wheels) 
        : Vehicle(make, model, year), Car(make, model, year, wheels), Drone(make, model, year, wings) {}

    UAM(const UAM& other) : Vehicle(other), Car(other), Drone(other) {}

    ~UAM() override {}

    UAM& operator=(const UAM& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            Car::operator=(other);
            Drone::operator=(other);
        }
        return *this;
    }

    void drive() const override {
        cout << "Operating UAM - Make: " << make << ", Model: " << model 
             << ", Year: " << year << ", Wings: " << wingCount 
             << ", Wheels: " << wheelCount << endl;
    }
};

int main() {
    // Creating Car and Drone objects
    Car myCar(1, 2023, 2023, 4);
    Drone myDrone(2, 2025, 2025, 6);

    cout << "Car Details: ";
    myCar.drive();

    cout << "Drone Details: ";
    myDrone.drive();

    // Polymorphism
    vector<unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(make_unique<Car>(3, 2026, 2026, 4));
    vehicles.push_back(make_unique<Drone>(4, 2027, 2027, 8));
    vehicles.push_back(make_unique<UAM>(5, 2028, 2028, 4, 6));

    for (const auto& vehicle : vehicles) {
        cout << "Vehicle Details: ";
        vehicle->drive();
    }

    return 0;
}
