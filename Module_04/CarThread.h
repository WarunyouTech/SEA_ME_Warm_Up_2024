#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include "Car.h"
#include "RaceTrack.h"

class CarThread : public QThread {
    Q_OBJECT

public:
    CarThread(Car *car, RaceTrack *track, QObject *parent = nullptr);

protected:
    void run() override;

private:
    Car *car;
    RaceTrack *raceTrack;
};

#endif // CARTHREAD_H
