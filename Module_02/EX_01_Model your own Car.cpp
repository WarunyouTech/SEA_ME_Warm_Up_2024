#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Abstract Part class
class Part {
public:
    virtual void display() const = 0; // Pure virtual function for displaying part details
    virtual ~Part() = default; // Virtual destructor for safe polymorphic destruction
};

// Engine class
class Engine : public Part {
public:
    Engine(const std::string& model) : model(model) {}
    
    void display() const override {
        std::cout << "Engine Model: " << model << "\n";
    }

private:
    std::string model;
};

// Wheel class
class Wheel : public Part {
public:
    Wheel(const std::string& size) : size(size) {}
    
    void display() const override {
        std::cout << "Wheel Size: " << size << "\n";
    }

private:
    std::string size;
};

// Brake class
class Brake : public Part {
public:
    Brake(const std::string& type) : type(type) {}
    
    void display() const override {
        std::cout << "Brake Type: " << type << "\n";
    }

private:
    std::string type;
};

// Transmission class
class Transmission : public Part {
public:
    Transmission(const std::string& type) : type(type) {}
    
    void display() const override {
        std::cout << "Transmission Type: " << type << "\n";
    }

private:
    std::string type;
};

// Light class
class Light : public Part {
public:
    Light(const std::string& type) : type(type) {}
    
    void display() const override {
        std::cout << "Light Type: " << type << "\n";
    }

private:
    std::string type;
};

// Battery class
class Battery : public Part {
public:
    Battery(const std::string& capacity) : capacity(capacity) {}
    
    void display() const override {
        std::cout << "Battery Capacity: " << capacity << "\n";
    }

private:
    std::string capacity;
};

// The Car class
class Car {
public:
    Car(const std::string& model)
    : model(model) {
        engine = std::make_unique<Engine>("Porsche 911 Turbo Engine");
        wheels.emplace_back(std::make_unique<Wheel>("20 inches"));
        wheels.emplace_back(std::make_unique<Wheel>("20 inches"));
        wheels.emplace_back(std::make_unique<Wheel>("20 inches"));
        wheels.emplace_back(std::make_unique<Wheel>("20 inches"));
        brakes.emplace_back(std::make_unique<Brake>("Carbon-Ceramic"));
        brakes.emplace_back(std::make_unique<Brake>("Carbon-Ceramic"));
        brakes.emplace_back(std::make_unique<Brake>("Carbon-Ceramic"));
        brakes.emplace_back(std::make_unique<Brake>("Carbon-Ceramic"));
        transmission = std::make_unique<Transmission>("7-Speed Dual-Clutch");
        lights.emplace_back(std::make_unique<Light>("LED Headlights"));
        lights.emplace_back(std::make_unique<Light>("LED Taillights"));
        lights.emplace_back(std::make_unique<Light>("LED Fog Lights"));
        battery = std::make_unique<Battery>("70 Ah");
    }

    void displayParts() const {
        std::cout << "Porsche " << model << " Components:\n";
        engine->display();
        for (const auto& wheel : wheels) {
            wheel->display();
        }
        for (const auto& brake : brakes) {
            brake->display();
        }
        transmission->display();
        for (const auto& light : lights) {
            light->display();
        }
        battery->display();
    }

    void testDrive() const {
        std::cout << "\nStarting test drive...\n";
        std::cout << "The Porsche " << model << " roars to life with its powerful engine.\n";
        std::cout << "The handling is precise with the carbon-ceramic brakes and 20-inch wheels.\n";
        std::cout << "The dual-clutch transmission shifts smoothly, and the LED lights provide excellent visibility.\n";
        std::cout << "The battery ensures reliable power supply throughout the drive.\n";
        std::cout << "You accelerate swiftly and experience the thrill of driving a Porsche.\n";
    }

private:
    std::string model;
    std::unique_ptr<Engine> engine;
    std::vector<std::unique_ptr<Wheel>> wheels;
    std::vector<std::unique_ptr<Brake>> brakes;
    std::unique_ptr<Transmission> transmission;
    std::vector<std::unique_ptr<Light>> lights;
    std::unique_ptr<Battery> battery;
};

int main() {
    Car porsche_911_Turbo("911 Turbo");
    porsche_911_Turbo.displayParts();
    porsche_911_Turbo.testDrive();

    return 0;
}
