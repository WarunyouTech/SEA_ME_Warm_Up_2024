#include "CarThread.h"
#include <QMutex>
#include <QMutexLocker>

QMutex mutex;  // Global mutex for synchronizing car movements

CarThread::CarThread(Car *car, RaceTrack *track, QObject *parent)
    : QThread(parent), car(car), raceTrack(track) {}

void CarThread::run() {
    while (car->getPosition() < raceTrack->getFinishLine()) {
        {
            QMutexLocker locker(&mutex);  // Lock mutex for synchronization
            car->move();  // Move the car
        }
        msleep(100);  // Simulate delay between movements
    }
}
