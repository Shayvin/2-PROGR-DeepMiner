#include "init.h"
#include "globals.h"

World::World() {
    srand(time(0));
    for (int z = 0; z < HEIGHT; z++) {
        vector<vector<int>> layer;
        for (int y = 0; y < LENGTH; y++) {
            vector<int> row;
            for (int x = 0; x < WIDTH; x++) {
                int value = rand() % 9 + 1;
                row.push_back(value);
            }
            layer.push_back(row);
        }
        world.push_back(layer);
    }
}



