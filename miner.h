#ifndef INC_2_PROGR_DEEPMINER_MINER_H
#define INC_2_PROGR_DEEPMINER_MINER_H
#include "init.h"
class Miner {
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
protected:
    int x = 0;
    int y = 4;
    int z = 9;
    int cp = 0; // Collected Points
};

class Dave : public Miner {
public:
    char moveDave(Dave &player, World &world, char input);
    void digDave(Dave &player, World &world);
    void sortZ(Dave &player, World &world);
};

class Jordan : public Miner {
public:
    char moveJordan(Jordan &player, World &world, char input);
    void digJordan(Jordan &player, World &world);
};

class Malcom : public Miner {
public:
    char moveMalcom(Malcom &player, World &world, char input);
    void digMalcom(Malcom &player, World &world);
};

#endif //INC_2_PROGR_DEEPMINER_MINER_H
