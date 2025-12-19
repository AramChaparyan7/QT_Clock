# Analog Clock Application

A Qt C++ application that displays a functional analog clock with hour, minute, and second hands.

## Features

- Real-time analog clock display
- Smooth second hand movement
- Hour, minute, and second hands with distinct styling
- Clock face with hour markers
- Automatic updates every second

## Requirements

- Qt 5.x or Qt 6.x
- C++ compiler with C++11 support or later
- CMake 3.x or qmake (depending on your build system)

## Building the Application

### Using qmake

qmake
make


## Running the Application

After building, run the executable:

./analogclock

## Implementation Details

The application uses:
- QWidget for the main window
- QPainter for drawing the clock face and hands
- QTimer for updating the display every second
- QTime for getting the current system time
- Transformations (rotate(), translate()) for positioning clock hands

### Clock Components

- Hour Hand: Shortest hand, rotates 360° every 12 hours
- Minute Hand: Medium length, rotates 360° every 60 minutes
- Second Hand: Longest and thinnest, rotates 360° every 60 seconds
- Clock Face: Circular background with 12 hour markers

