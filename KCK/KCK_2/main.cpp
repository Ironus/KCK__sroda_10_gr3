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

class BobBudowniczy {
public:
	item* siatka;
	int x, y;
	
	BobBudowniczy(item* siatka)
	{
		this->siatka = siatka;
		this->zmienPozycje(8, 8);
	}
	
	// Zwraca mape po zbudowaniu jej
	item* oddajMape()
	{
		return this->siatka;
	}
	
	// Ogarnia znaczenie komendy i wczytuje do mapy odpowiedni obiekt
	void ogarnij(string komenda)
	{
		// Rozpoznanie landmarku
		if (this->zawiera('Widze', komenda))
		{
			// Trzeba wiedziec gdzie wrocic...
			int x, y;
			x = this->x;
			y = this->y;
			
			// Ruszamy sie w kierunku landmarku
			if (this->zawiera('poludniu', komenda))
			{
				this->naPoludnie();
				
				if (this->zawiera('daleko', komenda))
				{
					this->naPoludnie();
				}
			}
			else if (this->zawiera('polnocy', komenda))
			{
				this->naPolnoc();
				
				if (this->zawiera('daleko', komenda))
				{
					this->naPolnoc();
				}
			}
			else if (this->zawiera('wschodzie', komenda))
			{
				this->naWschod();
				
				if (this->zawiera('daleko', komenda))
				{
					this->naWschod();
				}
			}
			else if (this->zawiera('zachodzie', komenda))
			{
				this->naZachod();
				
				if (this->zawiera('daleko', komenda))
				{
					this->naZachod();
				}
			}
			
			// Dobór landmarku
			if (this->zawiera('male drzewo', komenda))
			{
				this->postawTutaj(new mDrzewo());
			} 
			else if (this->zawiera('duze drzewo', komenda))
			{
				this->postawTutaj(new dDrzewo());
			}
			else if (this->zawiera('twardy kamien', komenda))
			{
				this->postawTutaj(new Kamien());
			}
			else if (this->zawiera('zielony krzak', komenda))
			{
				this->postawTutaj(new Krzak());
			}
			else if (this->zawiera('rodzinny dom', komenda))
			{
				this->postawTutaj(new Dom());
			}
			
			// Powrot gdzie bylismy, landmark nie wymaga podrozy
			this->zmienPozycje(x, y);
		}
		// Rozpoznanie drogi prostej
		if (this->zawiera('Ide', komenda))
		{
			// Dobor kierunku
			if (this->zawiera('polnoc', komenda))
			{
				this->postawTutaj(new d1());
				this->naPolnoc();
			}
			else if (this->zawiera('poludnie', komenda))
			{
				this->postawTutaj(new d1());
				this->naPoludnie();
			}
			else if (this->zawiera('wschod', komenda))
			{
				this->postawTutaj(new d2());
				this->naWschod();
			}
			else if (this->zawiera('zachod', komenda))
			{
				this->postawTutaj(new d2());
				this->naZachod();
			}
		}
		// Rozpoznanie zakretu
		if (this->zawiera('Skrecam', komenda))
		{
			// Postaw odpowiedni zakret
			if (this->zawiera('polnocy', komenda) && this->zawiera('wschodu', komenda))
			{
				if (this->zawiera('lagodnie', komenda))
				{
					this->postawTutaj(new z1());
				}
				else if (this->zawiera('ostro', komenda))
				{
					this->postawTutaj(new z11());
				}

			}
			else if (this->zawiera('polnocy', komenda) && this->zawiera('zachodu', komenda))
			{
				if (this->zawiera('lagodnie', komenda))
				{
					this->postawTutaj(new z2());
				}
				else if (this->zawiera('ostro', komenda))
				{
					this->postawTutaj(new z21());
				}
			}
			else if (this->zawiera('poludnia', komenda) && this->zawiera('wschodu', komenda))
			{
				if (this->zawiera('lagodnie', komenda))
				{
					this->postawTutaj(new z3());
				}
				else if (this->zawiera('ostro', komenda))
				{
					this->postawTutaj(new z31());
				}
			}
			else if (this->zawiera('poludnia', komenda) && this->zawiera('zachodu', komenda))
			{
				if (this->zawiera('lagodnie', komenda))
				{
					this->postawTutaj(new z4());
				}
				else if (this->zawiera('ostro', komenda))
				{
					this->postawTutaj(new z41());
				}
			}
			
			// Rusz sie
			if (this->zawiera('polnoc', komenda))
			{
				this->naPolnoc();
			}
			else if (this->zawiera('poludnie', komenda))
			{
				this->naPoludnie();
			}
			else if (this->zawiera('wschod', komenda))
			{
				this->naWschod();
			}
			else if (this->zawiera('zachod', komenda))
			{
				this->naZachod();
			}
		}
		// Rozpoznanie skrzyzowania
		if (this->zawiera('Na skrzyzowaniu', komenda))
		{
			// Postaw skrzyzowanie
			this->postawTutaj(new cross());
			
			// Rusz sie
			if (this->zawiera('polnoc', komenda))
			{
				this->naPolnoc();
			}
			else if (this->zawiera('poludnie', komenda))
			{
				this->naPoludnie();
			}
			else if (this->zawiera('wschod', komenda))
			{
				this->naWschod();
			}
			else if (this->zawiera('zachod', komenda))
			{
				this->naZachod();
			}
		}
	}
	
protected:
	bool zawiera(string fraza, string komenda)
	{
		// moze nie byc dobrze, nie umim
		return komenda.find(fraza) != string::npos;
	}
	void postawTutaj(item elementTrasy)
	{
		this->siatka[this->x][this->y] = elementTrasy;
	}
	void zmienPozycje(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void naPolnoc()
	{
		this->y = this->y + 1;
	}
	void naPoludnie()
	{
		this->y = this->y - 1;
	}
	void naWschod()
	{
		this->x = this->y + 1;
	}
	void naZachod()
	{
		this->y = this->y - 1;
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
   item* siatka[15][15];

   for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 15; j++) {
         siatka[i][j] = NULL;
      }
   }
	
	string opisTrasy = FileHandler::read("../KCK/opisTrasy.txt");
	BobBudowniczy budowniczy = new BobBudowniczy(siatka);

	string komenda; // policji hehe
    stringstream stream(opisTrasy);
    
    // Dla kazdej komendy
    while(getline(stream, komenda, "\n"))
    {
        budowniczy->ogarnij(komenda);
	}
	
	siatka = budowniczy->oddajMape();

   // WEZ KTOS SIATKE ZRENDERUJ BO nie umim






   bool done = false;
   ALLEGRO_BITMAP * grassBitmap = NULL;
   grassBitmap = al_load_bitmap("images/grass.png");
   while (!done) {
      ALLEGRO_EVENT ev;
      for (int l = 0; l < 15; l++) {
         for (int m = 0; m < 15; m++) {
            if (siatka[m][l] != NULL)
               al_draw_bitmap(siatka[m][l]->getBitmap(), l * 30, m * 30, NULL);
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
