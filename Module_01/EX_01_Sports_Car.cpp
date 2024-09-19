#include <iostream>
#include <string>

// Base class
class Car {
private:
    std::string make;
    std::string name;
    int year;

public:
    // Default Constructor
    Car() : make("HYUNDAI"), name("AVANTE"), year(2014) {}

    // Parameterized Constructor
    Car(const std::string& make, const std::string& name, int year)
        : make(make), name(name), year(year) {}

    // Copy Constructor
    Car(const Car& other) : make(other.make), name(other.name), year(other.year) {}

    // Copy Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            make = other.make;
            name = other.name;
            year = other.year;
        }
        return *this;
    }

    // Destructor
    ~Car() {}

    // Accessors (Getters)
    std::string getMake() const { return make; }
    std::string getName() const { return name; }
    int getYear() const { return year; }

    // Mutators (Setters)
    void setMake(const std::string& make) { this->make = make; }
    void setName(const std::string& name) { this->name = name; }
    void setYear(int year) { this->year = year; }

    // Display function
    virtual void display() const {
        std::cout << "Make: " << make << "\tName: " << name << "\tYear: " << year;
    }
};

// Derived class
class SportsCar : public Car {
private:
    int top_speed;

public:
    // Parameterized Constructor
    SportsCar(const std::string& make, const std::string& name, int year, int top_speed)
        : Car(make, name, year), top_speed(top_speed) {}

    // Override Display function
    void display() const override {
        Car::display(); // Call base class display
        std::cout << "\tTop Speed: " << top_speed << " km/h" << std::endl;
    }

    // Accessor for top_speed
    int getTopSpeed() const { return top_speed; }

    // Mutator for top_speed
    void setTopSpeed(int speed) { top_speed = speed; }
};

// Function to create a Car object from user input
Car createCar() {
    std::string make, name;
    int year;

    std::cout << "Enter car make: ";
    std::getline(std::cin, make);
    std::cout << "Enter car name: ";
    std::getline(std::cin, name);
    std::cout << "Enter year of manufacture: ";
    std::cin >> year;
    std::cin.ignore(); // To ignore leftover newline character

    return Car(make, name, year);
}

// Function to create a SportsCar object from user input
SportsCar createSportsCar() {
    std::string make, name;
    int year, top_speed;

    std::cout << "Enter sports car make: ";
    std::getline(std::cin, make);
    std::cout << "Enter sports car name: ";
    std::getline(std::cin, name);
    std::cout << "Enter year of manufacture: ";
    std::cin >> year;
    std::cout << "Enter top speed: ";
    std::cin >> top_speed;
    std::cin.ignore(); // To ignore leftover newline character

    return SportsCar(make, name, year, top_speed);
}

int main() {
    std::cout << "Create a Car:\n";
    Car car = createCar();
    car.display();

    std::cout << "\n\nCreate a Sports Car:\n";
    SportsCar sportsCar = createSportsCar();
    sportsCar.display();

    return 0;
}
