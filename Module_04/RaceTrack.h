#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
public:
    RaceTrack(int size, int finishLine);

    int getFinishLine() const;
    int getSize() const;

private:
    int size;
    int finishLine;
};

#endif // RACETRACK_H
