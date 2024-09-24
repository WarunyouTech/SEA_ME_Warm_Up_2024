#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>
#include <QList>
#include "Car.h"
#include "RaceTrack.h"
#include "CarThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RacingGame; }
QT_END_NAMESPACE

class RacingGame : public QMainWindow {
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();

private slots:
    void startRace();
    void pauseRace();
    void exitGame();
    void updateCarPosition(int carId, int newPosition);  // Update car position in the GUI

private:
    Ui::RacingGame *ui;

    RaceTrack *raceTrack;  // The race track object
    QList<Car*> carList;  // List of car objects
    QList<CarThread*> threadList;  // List of threads for cars
};

#endif // RACINGGAME_H

