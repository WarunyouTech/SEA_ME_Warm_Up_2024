#include "RacingGame.h"
#include "ui_RacingGame.h"
#include <QDebug>

RacingGame::RacingGame(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::RacingGame) {
    ui->setupUi(this);

    raceTrack = new RaceTrack(1000, 1000);  // Track length 1000, finish line at 1000

    // Connect the buttons to their respective slots
    connect(ui->startButton, &QPushButton::clicked, this, &RacingGame::startRace);
    connect(ui->pauseButton, &QPushButton::clicked, this, &RacingGame::pauseRace);
    connect(ui->exitButton, &QPushButton::clicked, this, &RacingGame::exitGame);

    // Add cars to the race (with random speeds)
    carList.append(new Car(1, 10, 1, this));
    carList.append(new Car(2, 12, 1, this));
    carList.append(new Car(3, 8, 1, this));
}

RacingGame::~RacingGame() {
    delete ui;
}

void RacingGame::startRace() {
    // Start a thread for each car
    for (Car *car : carList) {
        CarThread *carThread = new CarThread(car, raceTrack, this);

        // Connect car's positionChanged signal to updateCarPosition slot
        connect(car, &Car::positionChanged, this, &RacingGame::updateCarPosition);

        // Start the thread
        threadList.append(carThread);
        carThread->start();
    }
}

void RacingGame::pauseRace() {
    // Implement pause logic (optional for this demo)
    qDebug() << "Race paused!";
}

void RacingGame::exitGame() {
    // Close the application
    qApp->exit();
}

void RacingGame::updateCarPosition(int carId, int newPosition) {
    // Update the GUI or print the new car position
    qDebug() << "Car " << carId << " is at position " << newPosition;
}
