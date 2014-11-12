#include "agent_1.h"


agent_1::agent_1() {
   siatka.resize(10);
   for (int i = 0; i < 10; i++) {
      siatka[i].resize(10);
   }
   srand(time(NULL));

   x = rand() % 10;
   y = rand() % 10;

   int map_x = x;
   int map_y = y;

   siatka[map_x][map_y] = new straight(x, y, 1);
   
   DROGA element = DROGA(EMPTY);
   KIERUNEK kier = KIERUNEK(EMPTY);
   for (int i = 0; i < 20; i++) {
      element = DROGA(rand() % 4 + 1);
      if (element = STRAIGHT) {

      }
   }
}


agent_1::~agent_1(){
}
