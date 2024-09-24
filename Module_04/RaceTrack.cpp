#include "RaceTrack.h"

RaceTrack::RaceTrack(int size, int finishLine)
    : size(size), finishLine(finishLine) {}

int RaceTrack::getFinishLine() const {
    return finishLine;
}

int RaceTrack::getSize() const {
    return size;
}
