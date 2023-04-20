#include "miner.h"
#include "globals.h"
#include "init.h"

void Dave::sortZ(Dave& player, World& world) {
    int currentX = player.getX();
    int currentY = player.getY();
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

void Dave::digDave(Dave &player, World &world) {
    int currentX = player.getX();
    int currentY = player.getY();
    int currentCP = player.getCP();
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
    player.setCP(currentCP);
}

char Dave::moveDave(Dave &player, World &world, char input) {
    int x = player.getX();
    int y = player.getY();

    switch(input) {
        case 's': {
            if(y + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y + 1);
                sortZ(player, world);
                digDave(player, world);
            }
            break;
        }
        case 'w': {
            if(y - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y - 1);
                sortZ(player, world);
                digDave(player, world);
            }
            break;
        }
        case 'a': {
            if(x - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x - 1);
                sortZ(player, world);
                digDave(player, world);
            }
            break;
        }
        case 'd': {
            if(x + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x + 1);
                sortZ(player, world);
                digDave(player, world);
            }
            break;
        }
        case 'x': {
                sortZ(player, world);
                digDave(player, world);
            }
            break;
        default:
            cout << "Falsch Eingabe!" << endl;
    }
}

void Jordan::digJordan(Jordan &player, World &world) {
    int currentX = player.getX();
    int currentY = player.getY();
    int currentCP = player.getCP();
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
    player.setCP(currentCP);
}

char Jordan::moveJordan(Jordan &player, World &world, char input) {
    int x = player.getX();
    int y = player.getY();

    switch(input) {
        case 's': {
            if(y + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y + 1);
                digJordan(player, world);
            }
            break;
        }
        case 'w': {
            if(y - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y - 1);
                digJordan(player, world);
            }
            break;
        }
        case 'a': {
            if(x - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x - 1);
                digJordan(player, world);
            }
            break;
        }
        case 'd': {
            if(x + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x + 1);
                digJordan(player, world);
            }
            break;
        }
        case 'x': {
            digJordan(player, world);
            break;
        }
        default:
            cout << "Falsch Eingabe!" << endl;
    }
}

void Malcom::digMalcom(Malcom &player, World &world) {
    int currentX = player.getX();
    int currentY = player.getY();
    int currentCP = player.getCP();
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
    player.setCP(currentCP);
}

char Malcom::moveMalcom(Malcom &player, World &world, char input) {
    int x = player.getX();
    int y = player.getY();

    switch(input) {
        case 's': {
            if(y + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y + 1);
                digMalcom(player, world);
            }
            break;
        }
        case 'w': {
            if(y - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setY(y - 1);
                digMalcom(player, world);
            }
            break;
        }
        case 'a': {
            if(x - 1 < 0) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x - 1);
                digMalcom(player, world);
            }
            break;
        }
        case 'd': {
            if(x + 1 > 4) {
                cout << "Du bewegst dich ausserhalb des Spielfeldes!" << endl;
                return 0;
            } else {
                player.setX(x + 1);
                digMalcom(player, world);
            }
            break;
        }
        case 'x': {
            digMalcom(player, world);
            break;
        }
        default:
            cout << "Falsch Eingabe!" << endl;
    }
}