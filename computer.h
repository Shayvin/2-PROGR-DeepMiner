#ifndef INC_2_PROGR_DEEPMINER_COMPUTER_H
#define INC_2_PROGR_DEEPMINER_COMPUTER_H

#include "init.h"
#include "miner.h"
#include "globals.h"
#include "manager.h"

class Computer {
public:
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getZ() {
        return z;
    }
    int getCP() {
        return cp;
    }
    void setX(int _x) {
        x = _x;
    }
    void setY(int _y) {
        y = _y;
    }
    void setZ(int _z) {
        z = _z;
    }
    void setCP(int _cp) {
        cp = _cp;
    }
    /* void setType1(int _cpuType) {
        cpuType1 = _cpuType;
    }
    int getType1() {
        return cpuType1;
    }
    void setType2(int _cpuType) {
        cpuType2 = _cpuType;
    }
    int getType2() {
        return cpuType2;
    } */
    void printWorld(Computer &player, World &world);
    void moveComputer(Computer &cpu, World &world);
protected:
    int x = 0;
    int y = 4;
    int z = 9;
    int cp = 0; // Collected Points
    // int cpuType1 = 0;
    // int cpuType2 = 0;
};

class Computer1 : public Computer {
public:
    void sortZ(Computer1 &cpu, World &world);
    void digComputer1(Computer1 &player, World &world);
    void moveComputer1(Computer1 &player, World &world);
};

class Computer2 : public Computer {
public:
    void digComputer2(Computer2 &player, World &world);
    void moveComputer2(Computer2 &player, World &world);
};

class Computer3 : public Computer {
public:
    void digComputer3(Computer3 &cpu, World &world);
    void moveComputer3(Computer3 &cpu, World &world);
};
#endif //INC_2_PROGR_DEEPMINER_COMPUTER_H
