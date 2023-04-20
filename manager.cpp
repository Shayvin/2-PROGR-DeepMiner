#include "manager.h"

void Manager::printWorld(Miner &player, World &world) {
    int currentX = player.getX();
    int currentY = player.getY();
    int z = 0;
    vector<int> zValues;
    for (int z = 0; z < HEIGHT; z++) {
        zValues.push_back(world.world[z][currentY][currentX]);
    }

    for (int y = 0; y < LENGTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == currentX && y == currentY) {
                cout << "P  ";
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

void Manager::Intro() {
    string input;
    cout << "Willkommen zum Deep Miner!" << endl;
    cout << "Das Feld ist 5x5 groß und hat eine Tiefe von 10 Feldern" << endl;
    cout << "Am Anfang wählt man zwischen 3 Minenrobotern aus die alle verschiedene Eigenschaften haben" << endl;
    cout << "Ziel des Spiels ist es, mehr Punkte zu sammeln als der Gegner." << endl << endl;
    cout << "Regeln verstanden? (Enter)";
    getline(cin, input);
    if (input.empty()) {
        return;
    }
}

int Manager::chooseRobot() {
    Computer cpu;
    int input = 0;
    cout << "Wähle einen Roboter: " << endl;
    cout << "1) Dave - Sortiert die Werte unter ihm und baut den höchsten Wert ab." << endl;
    cout << "2) Jordan - Baut die 3 Blöcke unter sich ab." << endl;
    cout << "3) Malcom - Baut den obersten Block * 3 ab." << endl;
    cout << "4) Computer vs. Computer." << endl;

    while(true) {
        cin >> input;
        if(input == 1 || input == 2 || input == 3 || input == 4) {
            return input;
        }
        else {
            cout << "Falsch Eingabe!" << endl;
        }
    }
}

void Manager::gameStart(Manager &manager, World &world, Dave &d, Jordan &j, Malcom &m) {
    Computer cpu;
    Computer1 cpu1;
    Computer2 cpu2;
    Computer3 cpu3;
    manager.Intro();
    char input;
    switch (manager.chooseRobot()) {
        case 1:
            while(cpu2.getCP() < 100 || m.getCP() < 100) {
                cout << "Player (P): " << endl;
                manager.printWorld(d, world);
                cout << "---------------------------------------------" << endl;
                cout << "Computer (C): " << endl;
                cpu.printWorld(cpu2, world);
                cout << "---------------------------------------------" << endl;
                cout << "Welche Richtung willst du gehen (w, a, s, d, x)?" << endl;
                cin >> input;
                d.moveDave(d, world, input);
                cout << "Total Points Player: " << d.getCP() << endl;
                cpu2.moveComputer2(cpu2, world);
                cout << "Total Points Computer: " << cpu2.getCP() << endl;
                if(cpu2.getCP() > d.getCP()) {
                    if(cpu2.getCP() >= 100) {
                        cout << "Computer gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
                if(cpu2.getCP() < d.getCP()) {
                    if (d.getCP() >= 100) {
                        cout << "Player gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
            }
            break;

        case 2:
            while(cpu3.getCP() < 100 || j.getCP() < 100) {
                cout << "Player (P): " << endl;
                manager.printWorld(j, world);
                cout << "---------------------------------------------" << endl;
                cout << "Computer (C): " << endl;
                cpu.printWorld(cpu3, world);
                cout << "---------------------------------------------" << endl;
                cout << "Welche Richtung willst du gehen (w, a, s, d, x)?" << endl;
                cin >> input;
                j.moveJordan(j, world, input);
                cout << "Total Points Player: " << j.getCP() << endl;
                cpu3.moveComputer3(cpu3, world);
                cout << "Total Points Computer: " << cpu3.getCP() << endl;
                if(cpu3.getCP() > j.getCP()) {
                    if(cpu3.getCP() >= 100) {
                        cout << "Computer gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
                if(cpu3.getCP() < j.getCP()) {
                    if (j.getCP() >= 100) {
                        cout << "Player gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
            }
            break;

        case 3:
            while(cpu1.getCP() < 100 || m.getCP() < 100) {
                cout << "Player (P): " << endl;
                manager.printWorld(m, world);
                cout << "---------------------------------------------" << endl;
                cout << "Computer (C): " << endl;
                cpu.printWorld(cpu1, world);
                cout << "---------------------------------------------" << endl;
                cout << "Welche Richtung willst du gehen (w, a, s, d, x)?" << endl;
                cin >> input;
                m.moveMalcom(m, world, input);
                cout << "Total Points Player: " << m.getCP() << endl;
                cpu1.moveComputer1(cpu1, world);
                cout << "Total Points Computer: " << cpu1.getCP() << endl;
                if(cpu1.getCP() > m.getCP()) {
                    if(cpu1.getCP() >= 100) {
                        cout << "Computer gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
                if(cpu1.getCP() < m.getCP()) {
                    if (m.getCP() >= 100) {
                        cout << "Player gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
            }
            break;

        case 4:
            while(cpu2.getCP() < 100 || cpu3.getCP() < 100) {
                cout << "Computer1 (C): " << endl;
                cpu.printWorld(cpu2, world);
                cout << "---------------------------------------------" << endl;
                cout << "Computer2 (C): " << endl;
                cpu.printWorld(cpu3, world);
                cout << "---------------------------------------------" << endl;
                cpu2.moveComputer2(cpu2, world);
                cout << "Total Points Computer1: " << cpu2.getCP() << endl;
                cpu3.moveComputer3(cpu3, world);
                cout << "Total Points Computer2: " << cpu3.getCP() << endl;
                if(cpu2.getCP() > cpu3.getCP()) {
                    if(cpu2.getCP() >= 100) {
                        cout << "Computer1 gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
                if(cpu2.getCP() < cpu3.getCP()) {
                    if (cpu3.getCP() >= 100) {
                        cout << "Computer2 gewinnt!" << endl;
                        cout << "---------------------------------------------" << endl;
                        break;
                    }
                }
            }
            break;
        default:
            break;
    }
}
