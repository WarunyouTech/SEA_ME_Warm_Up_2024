#include <iostream>
#include <memory>
using namespace std;

class Car {
public:
    string model;
    Car(const string& model) : model(model) {
        cout << "Car " << model << " created.\n";
    }
    ~Car() {
        cout << "Car " << model << " destroyed.\n";
    }
    void drive() const {
        cout << "Driving " << model << ".\n";
    }
};

int main() {
    cout << "Unique Pointer Demonstration:\n";
    
    // unique_ptr example
    unique_ptr<Car> car1 = make_unique<Car>("Volkswagen");
    car1->drive();
    
    // Transfer ownership
    unique_ptr<Car> car2 = move(car1);
    if (!car1) {
        cout << "car1 no longer owns the Volkswagen.\n";
    }
    car2->drive();

    cout << "\nShared Pointer Demonstration:\n";
    
    // shared_ptr example
    shared_ptr<Car> car3 = make_shared<Car>("Porsche 911");
    {
        shared_ptr<Car> car4 = car3; // car3 and car4 share ownership
        car4->drive();
        cout << "Shared ownership count: " << car3.use_count() << endl;
    } // car4 goes out of scope, car3 still owns the Porsche 911
    cout << "Shared ownership count after car4 is out of scope: " << car3.use_count() << endl;
    car3->drive();

    cout << "\nWeak Pointer Demonstration:\n";
    
    // weak_ptr example
    weak_ptr<Car> weakCar = car3; // weakCar does not affect the reference count
    if (auto sharedCar = weakCar.lock()) { // lock() returns a shared_ptr
        cout << "Weak pointer can access the car: ";
        sharedCar->drive();
    } else {
        cout << "Car no longer exists.\n";
    }

    return 0;
}
