# cmake_minimum_required(VERSION 3.5)

# project(RacingGame)

# set(CMAKE_CXX_STANDARD 14)

## Find required Qt5 modules
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

## Add source files
set(SOURCES
    main.cpp
    Car.cpp
    RaceTrack.cpp
    CarThread.cpp
    RacingGame.cpp)

## Add header files
set(HEADERS
    Car.h
    RaceTrack.h
    CarThread.h
    RacingGame.h)

### If you have a .ui file from Qt Designer, include this:
qt5_wrap_ui(UIS_HEADERS RacingGame.ui)

### Add the executable
add_executable(RacingGame ${SOURCES} ${HEADERS} ${UIS_HEADERS})

### Link necessary Qt5 libraries
target_link_libraries(RacingGame Qt5::Widgets Qt5::Core Qt5::Gui)
