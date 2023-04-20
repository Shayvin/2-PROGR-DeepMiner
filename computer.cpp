#include "computer.h"

void Computer::printWorld(Computer &cpu, World &world) {
    int currentX = cpu.getX();
    int currentY = cpu.getY();
    int z = 0;
    vector<int> zValues;
    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }
    for (int y = 0; y < LENGTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == currentX && y == currentY) {
                cout << "C  ";
            } else {
                int value = 0;
                value = world.world[z][y][x];
                if(value == 0) {
                    cout << "0  ";
                } else {
                    cout << value << "  ";
                }
            }
        }
        std::cout << "\n";
    }
}

void Computer::moveComputer(Computer &cpu, World &world) {
    int _currentX = rand() % 5;
    int _currentY = rand() % 5;
    cpu.setX(_currentX);
    cpu.setY(_currentY);
}

void Computer1::sortZ(Computer1 &cpu, World &world) {
    int currentX = cpu.getX();
    int currentY = cpu.getY();
    vector<int> zValues;
    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }
    sort(zValues.begin(), zValues.end(), greater<int>());
    for (int z = 0; z < HEIGHT; z++) {
        world.world[z][currentY][currentX] = zValues[z];
        int value = world.world[z][currentY][currentX];
        cout << "Z=" << z << ": " << value << endl;
    }
    cout << endl;
}

void Computer1::digComputer1(Computer1 &cpu, World &world) {
    int currentX = cpu.getX();
    int currentY = cpu.getY();
    int currentCP = cpu.getCP();
    vector<int> zValues;

    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }
    cout << endl;

    int highestValue = zValues[0];
    int highestValueIndex = -1;

    for (int i = 0; i < HEIGHT; i++) {
        if (world.world[i][currentY][currentX] == highestValue) {
            highestValueIndex = i;
            break;
        }
    }

    if (highestValue > 0 && highestValueIndex != -1) {
        currentCP += highestValue;
        zValues.erase(zValues.begin());
        for (int z = 0; z < HEIGHT; z++) {
            if (z < zValues.size()) {
                world.world[z][currentY][currentX] = zValues[z];
            } else {
                world.world[z][currentY][currentX] = 0;
            }
        }
    }
    cpu.setCP(currentCP);
}

void Computer1::moveComputer1(Computer1 &cpu, World &world) {
    int _currentX = rand() % 5;
    int _currentY = rand() % 5;
    cpu.setX(_currentX);
    cpu.setY(_currentY);

    sortZ(cpu, world);
    digComputer1(cpu, world);
}

void Computer2::digComputer2(Computer2 &cpu, World &world) {
    int currentX = cpu.getX();
    int currentY = cpu.getY();
    int currentCP = cpu.getCP();
    vector<int> zValues;

    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }
    for (int z = 0; z < HEIGHT; z++) {
        world.world[z][currentY][currentX] = zValues[z];
        int value = world.world[z][currentY][currentX];
        cout << "Z=" << z << ": " << value << endl;
    }
    int lastNonZeroIndex = 0;
    while (lastNonZeroIndex <= 9 && zValues[lastNonZeroIndex] == 0) {
        lastNonZeroIndex++;
    }
    currentCP += zValues[lastNonZeroIndex] + zValues[lastNonZeroIndex + 1] + zValues[lastNonZeroIndex + 2];
    zValues.erase(zValues.begin(), zValues.begin() + 3);
    if(zValues[8] == 0 && zValues[9] != 0) {
        currentCP += zValues[9];
        zValues.erase(zValues.end());
    }
    for (int z = 0; z < HEIGHT; z++) {
        if (z < zValues.size()) {
            world.world[z][currentY][currentX] = zValues[z];
        } else {
            world.world[z][currentY][currentX] = 0;
        }
    }
    cpu.setCP(currentCP);
}

void Computer2::moveComputer2(Computer2 &cpu, World &world) {
    int _currentX = rand() % 5;
    int _currentY = rand() % 5;
    cpu.setX(_currentX);
    cpu.setY(_currentY);

    digComputer2(cpu, world);
}

void Computer3::digComputer3(Computer3 &cpu, World &world) {
    int currentX = cpu.getX();
    int currentY = cpu.getY();
    int currentCP = cpu.getCP();
    vector<int> zValues;

    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }
    for (int z = 0; z < HEIGHT; z++) {
        world.world[z][currentY][currentX] = zValues[z];
        int value = world.world[z][currentY][currentX];
        cout << "Z=" << z << ": " << value << endl;
    }
    cout << endl;
    int lastNonZeroIndex = 0;
    while (lastNonZeroIndex <= 9 && zValues[lastNonZeroIndex] == 0) {
        lastNonZeroIndex++;
    }
    currentCP += zValues[lastNonZeroIndex] * 3;
    zValues[lastNonZeroIndex] = 0;
    zValues.erase(zValues.begin());
    for (int z = 0; z < HEIGHT; z++) {
        if (z < zValues.size()) {
            world.world[z][currentY][currentX] = zValues[z];
        } else {
            world.world[z][currentY][currentX] = 0;
        }
    }
    cpu.setCP(currentCP);
}

void Computer3::moveComputer3(Computer3 &cpu, World &world) {
    int _currentX = rand() % 5;
    int _currentY = rand() % 5;
    cpu.setX(_currentX);
    cpu.setY(_currentY);

    digComputer3(cpu, world);
}