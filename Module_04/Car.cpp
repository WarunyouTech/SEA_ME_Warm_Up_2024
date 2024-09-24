#include "Car.h"

Car::Car(int id, int speed, int direction, QObject *parent)
    : QObject(parent), carId(id), position(0), speed(speed), direction(direction) {}

int Car::getPosition() const {
    return position;
}

int Car::getSpeed() const {
    return speed;
}

int Car::getCarId() const {
    return carId;
}

void Car::move() {
    position += speed * direction;
    emit positionChanged(carId, position);  // Emit signal when car moves
}
