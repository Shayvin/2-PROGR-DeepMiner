#ifndef INC_2_PROGR_DEEPMINER_MANAGER_H
#define INC_2_PROGR_DEEPMINER_MANAGER_H
#include "miner.h"
#include "init.h"
#include "computer.h"

class Manager {
public:
    void printWorld(Miner &player, World &world);
    void Intro();
    int chooseRobot();
    void gameStart(Manager &manager, World &world, Dave &d, Jordan &j, Malcom &m);
};

#endif //INC_2_PROGR_DEEPMINER_MANAGER_H
