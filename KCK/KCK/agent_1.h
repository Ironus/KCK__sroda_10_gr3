#pragma once
#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include <vector>
#include <conio.h>
#include "map_objects.h"
#include "straight.h"

using namespace std;

class agent_1 {
private:
   short x;
   short y;
   //enum DROGA { START, STRAIGHT, ARC, CROSS, FINISH, EMPTY };
   //enum KIERUNEK { N, NE, E, SE, S, SW, W, NW, EMPTY };
   //vector<vector<map_objects *> > siatka;
public:
   agent_1();
   ~agent_1();
};

