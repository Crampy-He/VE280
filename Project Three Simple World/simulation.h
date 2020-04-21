//
// Created by crampy on 2019/7/1.
//

#ifndef P3_SIMULATION_H
#define P3_SIMULATION_H

#include "world_type.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
bool initWorld(world_t &world, const string &creaturesFile);
bool initSpecies(world_t &world, const string &speciesFile);
void simulation_concise(world_t &world, int round);
void simulation_verbose(world_t &world, int round);


void printGrid(const world_t pre_world);
// MODIFIES: cout.
//
// EFFECTS: print a grid representation of the creature world.

direction_t leftFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning
// left from the given direction "dir".
direction_t rightFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning
// right from the given direction "dir".

//
// EFFECTS: Returns a pointer to the creature at "location" in "grid".

world_t hop_function(world_t & pre_world, int creature_number);
world_t left_function(world_t & pre_world, int creature_number);
world_t right_function(world_t & pre_world, int creature_number);
world_t infect_function(world_t & pre_world, int creature_number);
world_t ifempty_function(world_t & pre_world, int creature_number, int program_number);
world_t ifwall_function(world_t & pre_world, int creature_number,int program_number);
world_t ifsame_function(world_t & pre_world, int creature_number,int program_number);
world_t ifenemy_function(world_t & pre_world, int creature_number,int program_number);
world_t go_function(world_t & pre_world, int creature_number,int program_number);





#endif //P3_SIMULATION_H
