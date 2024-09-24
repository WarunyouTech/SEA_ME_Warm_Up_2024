#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject {
    Q_OBJECT

public:
    Car(int id, int speed, int direction, QObject *parent = nullptr);

    int getPosition() const;
    int getSpeed() const;
    int getCarId() const;

public slots:
    void move();  // Simulate car movement

signals:
    void positionChanged(int carId, int newPosition);  // Signal emitted when car moves

private:
    int carId;
    int position;
    int speed;
    int direction;
};

#endif // CAR_H
