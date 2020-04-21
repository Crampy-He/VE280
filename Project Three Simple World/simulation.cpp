//
// Created by crampy on 2019/7/1.
//
#include "simulation.h"
void printGrid(const world_t pre_world){
    int i,j,grid_height,grid_width;
    grid_height=(int)pre_world.grid.height;
    grid_width=(int)pre_world.grid.width;
    for(i=0;i<grid_height;i++){
        for(j=0;j<5*grid_width;j++){
            if(j%5==4){
                cout<<" ";
            }else if(pre_world.grid.squares[i][j/5]!= nullptr){
                if(j%5==0){
                    cout<<pre_world.grid.squares[i][j/5]->species->name.substr(0,1);
                }else if(j%5==1){
                    cout<<pre_world.grid.squares[i][j/5]->species->name.substr(1,1);
                }else if(j%5==2){
                    cout<<"_";
                }
                else if(j%5==3){
                    switch (pre_world.grid.squares[i][j/5]->direction){
                        case EAST:
                            cout<<directShortName[0];
                            break;
                        case SOUTH:
                            cout<<directShortName[1];
                            break;
                        case  WEST:
                            cout<<directShortName[2];
                            break;
                        case  NORTH:
                            cout<<directShortName[3];
                            break;
                    }
                }
            }else {
                cout<<"_";
            }
        }
        cout<<endl;
    }
}

direction_t rightFrom(direction_t dir){
    if(dir==EAST){
        return SOUTH;
    }
    else if(dir==SOUTH){
        return WEST;
    }
    else if(dir==WEST){
        return NORTH;
    }else {
        return EAST;
    }
};
direction_t leftFrom(direction_t dir){
    if(dir==EAST){
        return NORTH;
    }
    else if(dir==WEST){
        return SOUTH;
    }
    else if(dir==NORTH){
        return WEST;
    }
    else {
        return EAST;
    }
};
world_t hop_function(world_t & pre_world, int creature_number) {
    if (pre_world.creatures[creature_number].direction == EAST) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r][
                    pre_world.creatures[creature_number].location.c + 1] == nullptr &&
            pre_world.creatures[creature_number].location.c < (int) pre_world.grid.width - 1) {
            pre_world.creatures[creature_number].location.c++;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c] = &pre_world.creatures[creature_number];
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][
                    pre_world.creatures[creature_number].location.c - 1] = nullptr;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == WEST) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r][
                    pre_world.creatures[creature_number].location.c - 1] == nullptr &&
            pre_world.creatures[creature_number].location.c > 0) {
            pre_world.creatures[creature_number].location.c--;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c] = &pre_world.creatures[creature_number];
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][
                    pre_world.creatures[creature_number].location.c + 1] = nullptr;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
     else if (pre_world.creatures[creature_number].direction == NORTH) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r -
                                   1][pre_world.creatures[creature_number].location.c] == nullptr &&
            pre_world.creatures[creature_number].location.r > 0) {
            pre_world.creatures[creature_number].location.r--;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c] = &pre_world.creatures[creature_number];
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r +
                                   1][pre_world.creatures[creature_number].location.c] = nullptr;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
     else if (pre_world.creatures[creature_number].direction == SOUTH) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r +
                                   1][pre_world.creatures[creature_number].location.c] == nullptr &&
            pre_world.creatures[creature_number].location.r < (int) pre_world.grid.height - 1) {
            pre_world.creatures[creature_number].location.r++;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c] = &pre_world.creatures[creature_number];
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r -
                                   1][pre_world.creatures[creature_number].location.c] = nullptr;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    return  pre_world;
}
world_t left_function(world_t & pre_world, int creature_number){
    pre_world.creatures[creature_number].direction=leftFrom(pre_world.creatures[creature_number].direction);
    pre_world.creatures[creature_number].programID++;
    return pre_world;
}
world_t right_function(world_t & pre_world, int creature_number){
    pre_world.creatures[creature_number].direction=rightFrom(pre_world.creatures[creature_number].direction);
    pre_world.creatures[creature_number].programID++;
    return pre_world;
}
world_t infect_function(world_t & pre_world, int creature_number){
    if(pre_world.creatures[creature_number].direction==SOUTH&&pre_world.creatures[creature_number].location.r<(int)pre_world.grid.height-1){
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r+1][pre_world.creatures[creature_number].location.c]!=nullptr&&
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r+1][pre_world.creatures[creature_number].location.c]->species->name!=pre_world.creatures[creature_number].species->name){
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r+1][pre_world.creatures[creature_number].location.c]->species=pre_world.creatures[creature_number].species;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r+1][pre_world.creatures[creature_number].location.c]->programID=1;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==NORTH&&pre_world.creatures[creature_number].location.r>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]->species->name!=
           pre_world.creatures[creature_number].species->name){
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]->species=pre_world.creatures[creature_number].species;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]->programID=1;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==WEST&&pre_world.creatures[creature_number].location.c>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]->species->name!=
           pre_world.creatures[creature_number].species->name){
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]->species=pre_world.creatures[creature_number].species;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]->programID=1;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==EAST&&pre_world.creatures[creature_number].location.c<(int)pre_world.grid.width-1){
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]!=nullptr&&
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]->species->name!=
            pre_world.creatures[creature_number].species->name){
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]->species=pre_world.creatures[creature_number].species;
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]->programID=1;
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else {
        return pre_world;
    }
}
world_t ifempty_function(world_t & pre_world, int creature_number, int program_number) {
    if (pre_world.creatures[creature_number].direction == SOUTH&& pre_world.creatures[creature_number].location.r < (int)pre_world.grid.height-1) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r + 1][pre_world.creatures[creature_number].location.c] == nullptr) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == NORTH && pre_world.creatures[creature_number].location.r > 0) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r - 1][pre_world.creatures[creature_number].location.c] == nullptr) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == WEST && pre_world.creatures[creature_number].location.c > 0) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c - 1] == nullptr) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }

    }
    else if (pre_world.creatures[creature_number].direction == EAST&& pre_world.creatures[creature_number].location.c < (int)pre_world.grid.width-1) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c + 1] == nullptr) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else {
        pre_world.creatures[creature_number].programID++;
        return pre_world;
    }
}
world_t ifwall_function(world_t & pre_world, int creature_number,int program_number) {
    if (pre_world.creatures[creature_number].direction == EAST) {
        if (pre_world.creatures[creature_number].location.c == (int)pre_world.grid.width-1) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == WEST) {
        if (pre_world.creatures[creature_number].location.c == 0) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == NORTH) {
        if (pre_world.creatures[creature_number].location.r == 0) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if (pre_world.creatures[creature_number].direction == SOUTH) {
        if (pre_world.creatures[creature_number].location.r == (int)pre_world.grid.height-1) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else{
        return pre_world;
    }
}
world_t ifsame_function(world_t & pre_world, int creature_number,int program_number){
    if(pre_world.creatures[creature_number].direction==SOUTH&&pre_world.creatures[creature_number].location.r<(int)pre_world.grid.height-1) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r +
                                   1][pre_world.creatures[creature_number].location.c] != nullptr &&
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r +
                                   1][pre_world.creatures[creature_number].location.c]->species->name ==
            pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==NORTH&&pre_world.creatures[creature_number].location.r>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]->species->name==pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==WEST&&pre_world.creatures[creature_number].location.c>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]->species->name==pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==EAST&&pre_world.creatures[creature_number].location.c<(int)pre_world.grid.height-1){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]->species->name==pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else {
        return  pre_world;
    }
}
world_t ifenemy_function(world_t & pre_world, int creature_number,int program_number){
    if(pre_world.creatures[creature_number].direction==SOUTH&&pre_world.creatures[creature_number].location.r<(int)pre_world.grid.height-1) {
        if (pre_world.grid.squares[pre_world.creatures[creature_number].location.r + 1][pre_world.creatures[creature_number].location.c] != nullptr &&
            pre_world.grid.squares[pre_world.creatures[creature_number].location.r + 1][pre_world.creatures[creature_number].location.c]->species->name !=
            pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==NORTH&&pre_world.creatures[creature_number].location.r>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r-1][pre_world.creatures[creature_number].location.c]->species->name!=pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==WEST&&pre_world.creatures[creature_number].location.c>0){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c-1]->species->name!=pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else if(pre_world.creatures[creature_number].direction==EAST&&pre_world.creatures[creature_number].location.c<(int)pre_world.grid.width-1){
        if(pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]!=nullptr&&
           pre_world.grid.squares[pre_world.creatures[creature_number].location.r][pre_world.creatures[creature_number].location.c+1]->species->name!=pre_world.creatures[creature_number].species->name) {
            pre_world.creatures[creature_number].programID = (unsigned) program_number;
            return pre_world;
        } else {
            pre_world.creatures[creature_number].programID++;
            return pre_world;
        }
    }
    else{
        pre_world.creatures[creature_number].programID++;
        return pre_world;
    }
}


world_t go_function(world_t & pre_world, int creature_number,int program_number){
    pre_world.creatures[creature_number].programID=(unsigned)program_number;
    return pre_world;
}
bool initSpecies(world_t &world, const string &speciesFile) {
    unsigned int i = 0;
    ifstream iFile_species;
    iFile_species.open(speciesFile);
    if (!(iFile_species)) {
        cout << "Error: Cannot open file " << speciesFile << "!" << endl;
        exit(0);
    } else {
        string directory,line_test;
        getline(iFile_species, directory);
        world.numSpecies = 0;
        while (iFile_species) {
            if (iFile_species) {
                if (world.numSpecies<=9) {
                    getline(iFile_species, world.species[world.numSpecies].name);
                    if(!(world.species[world.numSpecies].name == "")){
                    world.numSpecies++;
                }
                } else {
                    getline(iFile_species,line_test);
                    if(!(line_test=="")){
                        cout << "Error: Too many species!" << endl;
                        cout << "Maximal number of species is " << MAXSPECIES << "." << endl;
                        exit(0);
                    }
                }
            }
        }
            iFile_species.close();
            for (i = 0; i < world.numSpecies; i++) {
                string path_name, line, instruction[MAXPROGRAM*2];
                unsigned int prog_num = 0;
                path_name = directory + "/" + world.species[i].name;
                ifstream iFile_single_speice;
                istringstream iString;
                iFile_single_speice.open(path_name);
                if (!(iFile_single_speice)) {
                    cout << "Error: Cannot open file " << path_name << "!" << endl;
                    exit(0);
                } else {
                    while (iFile_single_speice) {
                            getline(iFile_single_speice, line);
                            iString.clear();
                            iString.str(line);
                            iString >> instruction[prog_num];
                            if (instruction[prog_num].empty()) {
                                break;
                            } else {
                                if (instruction[prog_num] == opName[0]) {
                                    world.species[i].program[prog_num].op = HOP;
                                    world.species[i].program[prog_num].address = 0;
                                } else if (instruction[prog_num] == opName[1]) {
                                    world.species[i].program[prog_num].op = LEFT;
                                    world.species[i].program[prog_num].address = 0;
                                } else if (instruction[prog_num] == opName[2]) {
                                    world.species[i].program[prog_num].op = RIGHT;
                                    world.species[i].program[prog_num].address = 0;
                                } else if (instruction[prog_num] == opName[3]) {
                                    world.species[i].program[prog_num].op = INFECT;
                                    world.species[i].program[prog_num].address = 0;
                                } else if (instruction[prog_num] == opName[4]) {
                                    world.species[i].program[prog_num].op = IFEMPTY;
                                    iString >> world.species[i].program[prog_num].address;
                                } else if (instruction[prog_num] == opName[5]) {
                                    world.species[i].program[prog_num].op = IFENEMY;
                                    iString >> world.species[i].program[prog_num].address;
                                } else if (instruction[prog_num] == opName[6]) {
                                    world.species[i].program[prog_num].op = IFSAME;
                                    iString >> world.species[i].program[prog_num].address;
                                } else if (instruction[prog_num] == opName[7]) {
                                    world.species[i].program[prog_num].op = IFWALL;
                                    iString >> world.species[i].program[prog_num].address;
                                } else if (instruction[prog_num] == opName[8]) {
                                    world.species[i].program[prog_num].op = GO;
                                    iString >> world.species[i].program[prog_num].address;
                                } else {
                                    cout << "Error: Instruction " << instruction[prog_num] << " is not recognized!"
                                         << endl;
                                    exit(0);
                                }
                            }
                           prog_num++;
                        }
                        if (prog_num > MAXPROGRAM) {
                            cout << "Error: Too many instructions for species " << world.species[i].name <<"!"<< endl;
                            cout << "Maximal number of instructions is " << MAXPROGRAM << "." << endl;
                            exit(0);
                        }
                    }
                world.species[i].programSize =  prog_num;
                iFile_single_speice.close();
                }
            }
            return true;
        }

bool initWorld(world_t &world, const string &creaturesFile) {
    ifstream iFile_world;
    iFile_world.open(creaturesFile);
    world.numCreatures = 0;
    int i, specie_decide;
    string dirction_decide[MAXCREATURES],specie_name[MAXCREATURES*2];
    if (!(iFile_world)) {
        cout << "Error: Cannot open file " << creaturesFile << "!" << endl;
        exit(0);
    } else {
        iFile_world >> world.grid.height;
        if (world.grid.height > MAXHEIGHT||world.grid.height<1) {
            cout << "Error: The grid height is illegal!" << endl;
            exit(0);
        } else {
            iFile_world >> world.grid.width;
            if (world.grid.width > MAXWIDTH||world.grid.width<1) {
                cout << "Error: The grid width is illegal!" << endl;
                exit(0);
            } else {
                while (iFile_world) {
                    if (iFile_world) {
                        if (world.numCreatures < MAXCREATURES) {
                            iFile_world >> specie_name[world.numCreatures];
                            if (!(specie_name[world.numCreatures] == "")) {
                                specie_decide = 0;
                                for (i = 0; i < (int) world.numSpecies; i++) {
                                    if (specie_name[world.numCreatures] == world.species[i].name) {
                                        specie_decide = 1;
                                        world.creatures[world.numCreatures].species = &world.species[i];
                                    }
                                    if ((unsigned) i == world.numSpecies - 1 && specie_decide == 0) {
                                        cout << "Error: Species " << specie_name[world.numCreatures]
                                             << " not found!" << endl;
                                        exit(0);
                                    }
                                }
                                iFile_world >> dirction_decide[world.numCreatures];
                                if (dirction_decide[world.numCreatures] == directName[0]) {
                                    world.creatures[world.numCreatures].direction = EAST;
                                } else if (dirction_decide[world.numCreatures] == directName[1]) {
                                    world.creatures[world.numCreatures].direction = SOUTH;
                                } else if (dirction_decide[world.numCreatures] == directName[2]) {
                                    world.creatures[world.numCreatures].direction = WEST;
                                } else if (dirction_decide[world.numCreatures] == directName[3]) {
                                    world.creatures[world.numCreatures].direction = NORTH;
                                } else {
                                    cout << "Error: Direction " << dirction_decide[world.numCreatures]
                                         << " is not recognized!" << endl;
                                    exit(0);
                                }
                                iFile_world >> world.creatures[world.numCreatures].location.r;
                                iFile_world >> world.creatures[world.numCreatures].location.c;
                                if (world.creatures[world.numCreatures].location.r + 1 > (int) world.grid.height ||
                                    world.creatures[world.numCreatures].location.r < 0 ||
                                    (unsigned) world.creatures[world.numCreatures].location.c + 1 > world.grid.width ||
                                    world.creatures[world.numCreatures].location.c < 0) {
                                    cout << "Error: Creature (" << world.creatures[world.numCreatures].species->name
                                         << " " << dirction_decide[world.numCreatures]
                                         << " " << world.creatures[world.numCreatures].location.r << " "
                                         << world.creatures[world.numCreatures].location.c << ") is out of bound!"
                                         << endl;
                                    cout << "The grid size is " << world.grid.height << "-by-" << world.grid.width
                                         << "." << endl;
                                    exit(0);
                                }
                                if (world.grid.squares[world.creatures[world.numCreatures].location.r][world.creatures[world.numCreatures].location.c] !=
                                    nullptr) {
                                    cout << "Error: Creature (" << world.creatures[world.numCreatures].species->name
                                         << " "
                                         << dirction_decide[world.numCreatures]
                                         << " " << world.creatures[world.numCreatures].location.r << " "
                                         << world.creatures[world.numCreatures].location.c <<
                                         ") overlaps with creature ("
                                         << world.grid.squares[world.creatures[world.numCreatures].location.r][world.creatures[world.numCreatures].location.c]->species->name
                                         << " "
                                         << directName[world.grid.squares[world.creatures[world.numCreatures].location.r][world.creatures[world.numCreatures].location.c]->direction]
                                         << " " << world.creatures[world.numCreatures].location.r << " "
                                         << world.creatures[world.numCreatures].location.c << ")!" << endl;
                                    exit(0);
                                } else {
                                    world.grid.squares[world.creatures[world.numCreatures].location.r][world.creatures[world.numCreatures].location.c] = &world.creatures[world.numCreatures];
                                    world.creatures[world.numCreatures].programID = 1;
                                    world.numCreatures++;
                                }
                            }
                                }else {
                            iFile_world >> specie_name[world.numCreatures];
                            if (!(specie_name[world.numCreatures] == "")){
                                cout << "Error: Too many creatures!" << endl;
                                cout << "Maximal number of creatures is " << MAXCREATURES << "." << endl;
                                exit(0);
                            }
                        }
                    }
                    }
                }
            }
        }
        iFile_world.close();
    return true;
    }


void simulation_verbose(world_t &world, int round) {
    int i, j = 0;
    cout << "Initial state" << endl;
    printGrid(world);
    for (i = 1; i <= round; i++) {
        cout << "Round " << i << endl;
        for (j = 0; j < (int) world.numCreatures; j++) {
            cout << "Creature (" << world.creatures[j].species->name << " " << directName[world.creatures[j].direction]
                 << " "
                 << world.creatures[j].location.r << " " << world.creatures[j].location.c << ") takes action:" << endl;
            while (world.creatures[j].species->program[world.creatures[j].programID - 1].op != 0 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 1 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 2 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 3) {
                if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 4) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << " "
                         << world.creatures[j].species->program[world.creatures[j].programID - 1].address << endl;
                    ifempty_function(world, j,
                                     world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 5) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << " "
                         << world.creatures[j].species->program[world.creatures[j].programID - 1].address << endl;
                    ifenemy_function(world, j,
                                     world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 6) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << " "
                         << world.creatures[j].species->program[world.creatures[j].programID - 1].address << endl;
                    ifsame_function(world, j,
                                    world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 7) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << " "
                         << world.creatures[j].species->program[world.creatures[j].programID - 1].address << endl;
                    ifwall_function(world, j,
                                    world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 8) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << " "
                         << world.creatures[j].species->program[world.creatures[j].programID - 1].address << endl;
                    go_function(world, j,
                                world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                }
            }
            if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 0) {
                cout << "Instruction " << world.creatures[j].programID << ": "
                     << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << endl;
                hop_function(world, j);
            } else {
                if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 1) {
                    cout << "Instruction " << world.creatures[j].programID << ": "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << endl;
                    left_function(world, j);
                } else {
                    if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 2) {
                        cout << "Instruction " << world.creatures[j].programID << ": "
                             << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op]
                             << endl;
                        right_function(world, j);
                    } else {
                        if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 3) {
                            cout << "Instruction " << world.creatures[j].programID << ": "
                                 << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op]
                                 << endl;
                            infect_function(world, j);
                        }
                    }
                }
            }
            printGrid(world);
        }
    }
}
void simulation_concise(world_t &world, int round){
    int i,j=0;
    cout<<"Initial state"<<endl;
    printGrid(world);
    for(i=1;i<=round;i++){
        cout<<"Round "<<i<<endl;
        for(j=0;j<(int)world.numCreatures;j++) {
            while (world.creatures[j].species->program[world.creatures[j].programID - 1].op != 0 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 1 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 2 &&
                   world.creatures[j].species->program[world.creatures[j].programID - 1].op != 3) {
                if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 4) {
                    ifempty_function(world, j,
                                     world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 5) {
                    ifenemy_function(world, j,
                                     world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 6) {
                    ifsame_function(world, j,
                                    world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 7) {
                    ifwall_function(world, j,
                                    world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                } else if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 8) {
                    go_function(world, j,
                                world.creatures[j].species->program[world.creatures[j].programID - 1].address);
                }
            }
            if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 0) {
                cout << "Creature (" << world.creatures[j].species->name << " "
                     << directName[world.creatures[j].direction] << " "
                     << world.creatures[j].location.r << " " << world.creatures[j].location.c << ") takes action: "
                     << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << endl;
                hop_function(world, j);
            } else {
                if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 1) {
                    cout << "Creature (" << world.creatures[j].species->name << " "
                         << directName[world.creatures[j].direction] << " "
                         << world.creatures[j].location.r << " " << world.creatures[j].location.c << ") takes action: "
                         << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op] << endl;
                    left_function(world, j);
                } else {
                    if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 2) {
                        cout << "Creature (" << world.creatures[j].species->name << " "
                             << directName[world.creatures[j].direction] << " "
                             << world.creatures[j].location.r << " " << world.creatures[j].location.c
                             << ") takes action: "
                             << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op]
                             << endl;
                        right_function(world, j);
                    }else {
                        if (world.creatures[j].species->program[world.creatures[j].programID - 1].op == 3) {
                            cout << "Creature (" << world.creatures[j].species->name << " "
                                 << directName[world.creatures[j].direction] << " "
                                 << world.creatures[j].location.r << " " << world.creatures[j].location.c
                                 << ") takes action: "
                                 << opName[world.creatures[j].species->program[world.creatures[j].programID - 1].op]
                                 << endl;
                            infect_function(world, j);
                        }
                    }
                }
            }
        }
        printGrid(world);
    }
}




