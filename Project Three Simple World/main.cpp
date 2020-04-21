#include <fstream>
#include "simulation.h"
int main(int argc, char* argv[]) {
    world_t world;
    unsigned int i,j,k;
    for(i=0;i<MAXCREATURES;i++){
        world.creatures[i].species= nullptr;
    }
    for(j=0;j<MAXHEIGHT;j++){
        for(k=0;k<MAXWIDTH;k++){
            world.grid.squares[j][k]= nullptr;
        }
    }//Initialize world together with seting all pointers(world contains) as nullptr
    if (argc < 4) {
        cout << "Error: Missing arguments!" << endl;
        cout << "Usage: ./p3 <species-summary> <world-file> <rounds> [v|verbose]" << endl;
        return 0;
    } else {
        int round = atoi(argv[3]);
        string v;
        string species,world_file;
        species=argv[1];
        world_file=argv[2];
        if (round < 0) {
            cout << "Error: Number of simulation rounds is negative!" << endl;
            return 0;
        }
        initSpecies(world, species);
        initWorld(world, world_file);
        if (argc >= 5) {
            v = argv[4];
            if (v == "v" || v == "verbose") {
                simulation_verbose(world, round);
            } else {
                simulation_concise(world, round);
            }
        }
        if (argc == 4) {
            simulation_concise(world, round);
        }
        return 0;
    }
}