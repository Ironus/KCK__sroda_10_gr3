#include "map_objects.h"

map_objects::map_objects(short _x, short _y, short agent_nbr) {
   // przypisanie x,y w konstruktorze
   x = _x;
   y = _y;
   // sprawdzenie dla ktorego agenta jest tworzony obiekt i dodanie wartoúci
   agent_nbr == 1 ? add_pixels = 0 : add_pixels = 310;
   // przypisanie wskaünika do bitmapy
   bitmap = al_load_bitmap("images/grass.png");
}

map_objects::~map_objects() {
   // zniszczenie bitmapy i wyzerowanie wskaünika
   al_destroy_bitmap(bitmap);
   bitmap = NULL;
}

void map_objects::draw() {
   al_draw_bitmap(bitmap, x * 30 + add_pixels, y * 30, NULL);
}
