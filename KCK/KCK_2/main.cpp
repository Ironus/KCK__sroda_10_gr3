#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class item {
public:
   string ToString;
   string dest;
   bool seen;
   ALLEGRO_BITMAP *bitmap;
   item() {
      ToString = "1";
      bitmap = NULL;
   }

   void setSeen(){
      seen = true;
   }

   string getvalue() {
      return ToString;
   }

   void nadajString(string _toString) {
      ToString = _toString;
   }

   void nadajDest(string _toString) {
      dest = _toString;
   }

   ALLEGRO_BITMAP* getBitmap() {
      return bitmap;
   }
};

class Trasa : public item {
public:
   string image;
   bool Lewo, Prawo, Gora, Dol;
   Trasa(bool l, bool p, bool g, bool d) {
      Lewo = l;
      Prawo = p;
      Gora = g;
      Dol = d;
   }
   void getvalue(){}
};

class Landmark : public item {
public:
   string image, Nazwa, Atrybut;
   Landmark(string N, string A) {
      Nazwa = N;
      Atrybut = A;
   }
};

class d1 : public Trasa {
public:
   d1(bool _lewo = false, bool _prawo = false, bool _gora = true, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "D1";
      bitmap = al_load_bitmap("images/road.png");
   }
};

class d2 : public Trasa {
public:
   d2(bool _lewo = false, bool _prawo = false, bool _gora = true, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "D2";
      bitmap = al_load_bitmap("images/road2.png");
   }
};
class z1 : public Trasa {
public:
   z1(bool _lewo = true, bool _prawo = false, bool _gora = true, bool _dol = false) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z1";
      bitmap = al_load_bitmap("images/left_to_up_turn.png");
   }
};

class z2 : public Trasa {
public:
   z2(bool _lewo = false, bool _prawo = true, bool _gora = true, bool _dol = false) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z2";
      bitmap = al_load_bitmap("images/right_to_up_turn.png");
   }
};

class z3 : public Trasa {
public:
   z3(bool _lewo = true, bool _prawo = false, bool _gora = false, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z3";
      bitmap = al_load_bitmap("images/left_turn.png");
   }
};

class z4 : public Trasa {
public:
   z4(bool _lewo = false, bool _prawo = true, bool _gora = false, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z4";
      bitmap = al_load_bitmap("images/right_turn.png");
   }
};

class z11 : public Trasa {
public:
   z11(bool _lewo = true, bool _prawo = false, bool _gora = true, bool _dol = false) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z11";
      bitmap = al_load_bitmap("images/left_to_up_turn_sharp.png");
   }
};

class z21 : public Trasa {
public:
   z21(bool _lewo = false, bool _prawo = true, bool _gora = true, bool _dol = false) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z21";
      bitmap = al_load_bitmap("images/right_to_up_turn_sharp.png");
   }
};

class z31 : public Trasa {
public:
   z31(bool _lewo = true, bool _prawo = false, bool _gora = false, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z31";
      bitmap = al_load_bitmap("images/left_turn_sharp.png");
   }
};

class z41 : public Trasa {
public:
   z41(bool _lewo = false, bool _prawo = true, bool _gora = false, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "z41";
      bitmap = al_load_bitmap("images/right_turn_sharp.png");
   }
};

class cross : public Trasa {
public:
   cross(bool _lewo = true, bool _prawo = true, bool _gora = true, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "cr";
      bitmap = al_load_bitmap("images/junction.png");
   }
};

class start : public Trasa {
public:
   start(bool _lewo = true, bool _prawo = true, bool _gora = true, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "St";
      bitmap = al_load_bitmap("images/start.png");
   }
};

class stop : public Trasa {
public:
   stop(bool _lewo = true, bool _prawo = true, bool _gora = true, bool _dol = true) : Trasa(_lewo, _prawo, _gora, _dol){
      ToString = "Sp";
      bitmap = al_load_bitmap("images/stop.png");
   }
};

class dDrzewo : public Landmark {
public:
   dDrzewo(string __tostr = "L1", string __toatr = "Du¿e") : Landmark(__tostr, __toatr){
      ToString = "L1";
      bitmap = al_load_bitmap("images/tree2.png");
   };
};

class mDrzewo : public Landmark {
public:
   mDrzewo(string __tostr = "L2", string __toatr = "Ma³e") : Landmark(__tostr, __toatr){
      ToString = "L2";
      bitmap = al_load_bitmap("images/tree.png");
   };
};

class Kamien : public Landmark {
public:
   Kamien(string __tostr = "L3", string __toatr = "Twardy") : Landmark(__tostr, __toatr){
      ToString = "L3";
      bitmap = al_load_bitmap("images/stone.png");
   };
};

class Krzak : public Landmark {
public:
   Krzak(string __tostr = "L5", string __toatr = "Zielony") : Landmark(__tostr, __toatr){
      ToString = "L5";
      bitmap = al_load_bitmap("images/bush.png");
   };
};

class Dom : public Landmark {
public:
   Dom(string __tostr = "L4", string __toatr = "Rodzinny") : Landmark(__tostr, __toatr){
      ToString = "L4";
      bitmap = al_load_bitmap("images/house.png");
   };
};

class FileHandler {
public:
   void static write(string contents, string filename) {
      ofstream file;

      file.open(filename);
      file << contents;
      file.close();
   }
   string static read(string filename) {
      ifstream file;
      string line;
      string contents;

      file.open(filename);
      while (getline(file, line))
      {
         contents += line + "\n";
      }
      file.close();

      return contents;
   }
};

const short SCREEN_W = 450, SCREEN_H = 450, MAP_SIDE = 450;
int error_code = 0;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

int graphic_initialize() {
   if (!al_init()) {
      al_show_native_message_box(NULL, NULL, "ERROR al_init()", "B³¹d inicjalizacji allegro.", NULL, NULL);
      return -1;
   }

   display = al_create_display(SCREEN_W, SCREEN_H);
   if (!display) {
      al_show_native_message_box(NULL, NULL, "ERROR display", "B³¹d tworzenia okna display.", NULL, NULL);
      return -2;
   }

   al_init_image_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   al_init_primitives_addon();
   al_install_keyboard();

   event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   return 0;
}

bool graphic_destroy() {
   al_destroy_display(display);
   al_destroy_font(font);
   al_destroy_event_queue(event_queue);
   display = NULL;
   font = NULL;
   event_queue = NULL;
   return 0;
}

int main() {
   graphic_initialize();
   al_clear_to_color(al_map_rgb(255, 0, 255));

   int y = 8, x = 8, i = 0;
   vector<vector<item*> > siatka;
   siatka.resize(15);
   for (int i = 0; i < 15; i++) {
      siatka[i].resize(15);
   }

   for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 15; j++) {
         siatka[i][j] = NULL;
      }
   }

   //string opisTrasy = FileHandler::read("../KCK/opisTrasy.txt");

   string komenda;
   ifstream input("../KCK/opisTrasy.txt");

   x = 8;
   y = 8;
   // Dla kazdej komendy
   getline(input, komenda);
   do {
      cout << komenda << endl;
      if (komenda.find("Na skrzyzowaniu") != std::string::npos) {
         siatka[x][y] = new cross();
         if (komenda.find("na wschod") != std::string::npos) {
            if (x + 1 < 15)
               x++;
         }
         else if (komenda.find("na zachod") != std::string::npos) {
            if (x - 1 >= 0)
               x--;
         }
         else if (komenda.find("na polnoc") != std::string::npos) {
            if (y - 1 >= 0)
               y--;
         }
         else {
            if (x + 1 >= 0)
               y++;
         }
      }
      else if (komenda.find("Ide na") != std::string::npos) {
         if (komenda.find("wschod") != std::string::npos) {
            siatka[x][y] = new d2();
            if (x + 1 < 15)
               x++;
         }
         else if (komenda.find("zachod") != std::string::npos) {
            siatka[x][y] = new d2();
            if (x - 1 >= 0)
               x--;
         }
         else if (komenda.find("polnoc") != std::string::npos) {
            siatka[x][y] = new d1();
            if (y - 1 >= 0)
               y--;
         }
         else {
            siatka[x][y] = new d1();
            if (y + 1 < 15)
               y++;
         }
      }
      else if (komenda.find("Skrecam") != std::string::npos) {
         if (komenda.find("lagodnie") != std::string::npos) {
            if (komenda.find("z polnocy na zachod") != std::string::npos) {
               siatka[x][y] = new z1();
               if (x - 1 >= 0)
                  x--;
            }
            else if (komenda.find("z zachodu na polnoc") != std::string::npos) {
               siatka[x][y] = new z1();
               if (y - 1 >= 0)
                  y--;
            }
            else if (komenda.find("z polnocy na wschod") != std::string::npos) {
               siatka[x][y] = new z2();
               if (x + 1 < 15)
                  x++;
            }
            else if (komenda.find("z wschodu na polnoc") != std::string::npos) {
               siatka[x][y] = new z2();
               if (y - 1 >= 0)
                  y--;
            }
            else if (komenda.find("z poludnia na zachod") != std::string::npos) {
               siatka[x][y] = new z3();
               if (x - 1 >= 0)
                  x--;
            }
            else if (komenda.find("z zachodu na poludnie") != std::string::npos) {
               siatka[x][y] = new z3();
               if (y + 1 < 15)
                  y++;
            }
            else if (komenda.find("z poludnia na wschod") != std::string::npos) {
               siatka[x][y] = new z4();
               if (x + 1 < 15)
                  x++;
            }
            else {
               siatka[x][y] = new z4();
               if (y + 1 < 15)
                  y++;
            }
         }
         else {
            if (komenda.find("z polnocy na zachod") != std::string::npos) {
               siatka[x][y] = new z11();
               if (x - 1 >= 0)
                  x--;
            }
            else if (komenda.find("z zachodu na polnoc") != std::string::npos) {
               siatka[x][y] = new z11();
               if (y - 1 >= 0)
                  y--;
            }
            else if (komenda.find("z polnocy na wschod") != std::string::npos) {
               siatka[x][y] = new z21();
               if (x + 1 < 15)
                  x++;
            }
            else if (komenda.find("z wschodu na polnoc") != std::string::npos) {
               siatka[x][y] = new z21();
               if (y - 1 >= 0)
                  y--;
            }
            else if (komenda.find("z poludnia na zachod") != std::string::npos) {
               siatka[x][y] = new z31();
               if (x - 1 >= 0)
                  x--;
            }
            else if (komenda.find("z zachodu na poludnie") != std::string::npos) {
               siatka[x][y] = new z31();
               if (y + 1 < 15)
                  y++;
            }
            else if (komenda.find("z poludnia na wschod") != std::string::npos) {
               siatka[x][y] = new z41();
               if (x + 1 < 15)
                  x++;
            }
            else {
               siatka[x][y] = new z41();
               if (y + 1 < 15)
                  y++;
            }
         }
      }
      else if (komenda.find("Widze") != std::string::npos) {
         if (komenda.find("blisko") != std::string::npos) {
            if (komenda.find("drzewo") != std::string::npos) {
               if (komenda.find("male") != std::string::npos) {
                  if (komenda.find("polnocy") != std::string::npos)
                     siatka[x][y - 1] = new mDrzewo();
                  else if (komenda.find("poludniu") != std::string::npos)
                     siatka[x][y + 1] = new mDrzewo();
                  else if (komenda.find("wschodzie") != std::string::npos)
                     siatka[x + 1][y] = new mDrzewo();
                  else
                     siatka[x - 1][y] = new mDrzewo();
               }
               else {
                  if (komenda.find("polnocy") != std::string::npos)
                     siatka[x][y - 1] = new dDrzewo();
                  else if (komenda.find("poludniu") != std::string::npos)
                     siatka[x][y + 1] = new dDrzewo();
                  else if (komenda.find("wschodzie") != std::string::npos)
                     siatka[x + 1][y] = new dDrzewo();
                  else
                     siatka[x - 1][y] = new dDrzewo();
               }
            }
            else if (komenda.find("kamien") != std::string::npos) {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 1] = new Kamien();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 1] = new Kamien();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 1][y] = new Kamien();
               else
                  siatka[x - 1][y] = new Kamien();
            }
            else if (komenda.find("krzak") != std::string::npos) {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 1] = new Krzak();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 1] = new Krzak();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 1][y] = new Krzak();
               else
                  siatka[x - 1][y] = new Krzak();
            }
            else {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 1] = new Dom();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 1] = new Dom();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 1][y] = new Dom();
               else
                  siatka[x - 1][y] = new Dom();
            }
         }
         else {
            if (komenda.find("drzewo") != std::string::npos) {
               if (komenda.find("male") != std::string::npos) {
                  if (komenda.find("polnocy") != std::string::npos)
                     siatka[x][y - 2] = new mDrzewo();
                  else if (komenda.find("poludniu") != std::string::npos)
                     siatka[x][y + 2] = new mDrzewo();
                  else if (komenda.find("wschodzie") != std::string::npos)
                     siatka[x + 2][y] = new mDrzewo();
                  else
                     siatka[x - 2][y] = new mDrzewo();
               }
               else {
                  if (komenda.find("polnocy") != std::string::npos)
                     siatka[x][y - 2] = new dDrzewo();
                  else if (komenda.find("poludniu") != std::string::npos)
                     siatka[x][y + 2] = new dDrzewo();
                  else if (komenda.find("wschodzie") != std::string::npos)
                     siatka[x + 2][y] = new dDrzewo();
                  else
                     siatka[x - 2][y] = new dDrzewo();
               }
            }
            else if (komenda.find("kamien") != std::string::npos) {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 2] = new Kamien();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 2] = new Kamien();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 2][y] = new Kamien();
               else
                  siatka[x - 2][y] = new Kamien();
            }
            else if (komenda.find("krzak") != std::string::npos) {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 2] = new Krzak();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 2] = new Krzak();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 2][y] = new Krzak();
               else
                  siatka[x - 2][y] = new Krzak();
            }
            else {
               if (komenda.find("polnocy") != std::string::npos)
                  siatka[x][y - 2] = new Dom();
               else if (komenda.find("poludniu") != std::string::npos)
                  siatka[x][y + 2] = new Dom();
               else if (komenda.find("wschodzie") != std::string::npos)
                  siatka[x + 2][y] = new Dom();
               else
                  siatka[x - 2][y] = new Dom();
            }
         }
      }
      getline(input, komenda);
   } while (komenda != "STOP");

   bool done = false;
   ALLEGRO_BITMAP * grassBitmap = NULL;
   grassBitmap = al_load_bitmap("images/grass.png");
   while (!done) {
      ALLEGRO_EVENT ev;
      for (int l = 0; l < 15; l++) {
         for (int m = 0; m < 15; m++) {
            if (siatka[l][m] != NULL)
               al_draw_bitmap(siatka[l][m]->getBitmap(), l * 30, m * 30, NULL);
            else
               al_draw_bitmap(grassBitmap, l * 30, m * 30, NULL);
         }
      }
      al_flip_display();
      al_wait_for_event(event_queue, &ev);
      if (ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch (ev.keyboard.keycode) {
         case ALLEGRO_KEY_ESCAPE:
            done = true;
         }
      }
   }
   graphic_destroy();
   return 0;
}