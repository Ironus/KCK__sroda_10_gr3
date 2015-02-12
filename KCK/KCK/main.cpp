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
   string nazwa;
   string ToString;
   string dest;
   bool seen;
   ALLEGRO_BITMAP *bitmap;
   item() {
      ToString = "1";
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

   string getdest(){
      return dest;
   }

   ALLEGRO_BITMAP* getBitmap() {
      return bitmap;
   }
};

//////////////////////////////////////////////////////////////////   Funkcje

bool prawo(int _x, int _y, item *tab[15][15]){
   if (tab[_y][_x + 1] == NULL)
      return true;
   else
      return false;

}

bool lewo(int _x, int _y, item *tab[15][15]){
   if (tab[_y][_x - 1] == NULL)
      return true;
   else
      return false;

}

bool gora(int _x, int _y, item *tab[15][15]){
   if (tab[_y - 1][_x] == NULL)
      return true;
   else
      return false;

}

bool dol(int _x, int _y, item *tab[15][15]){
   if (tab[_y + 1][_x] == NULL)
      return true;
   else
      return false;

}

string makeLine(string tekst, int poczX, int poczY, int konX, int konY){
   string line;
   stringstream ss;
   ss << poczX;
   string str = ss.str();
   line = tekst + "(" + str + ",";
   ss.str(std::string());
   ss << poczY;
   str = ss.str();
   line += str + ")";
   ss.str(std::string());
   ss << konX;
   str = ss.str();
   line += "(" + str + ",";
   ss.str(std::string());
   ss << konY;
   str = ss.str();
   line += str + ")";
   return line;
}

string makeLineLUK(string tekst, int poczX, int poczY, int konX, int konY, float srX, float srY){
   string line;
   stringstream ss;
   ss << poczX;
   string str = ss.str();
   line = tekst + "(" + str + ",";
   ss.str(std::string());
   ss << poczY;
   str = ss.str();
   line += str + ")";
   ss.str(std::string());
   ss << konX;
   str = ss.str();
   line += "(" + str + ",";
   ss.str(std::string());
   ss << konY;
   str = ss.str();
   line += str + ")";
   ss.str(std::string());
   ss << srX;
   str = ss.str();
   line += "(" + str + ",";
   ss.str(std::string());
   ss << srY;
   str = ss.str();
   line += str + ")";
   return line;
}




/////////////////////////////////////////////////////////////////   Podklasy

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
   //  void getvalue(){}
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
   dDrzewo(string __tostr = "L1", string __toatr = "Duże") : Landmark(__tostr, __toatr){
      ToString = "L1";
      nazwa = "duze drzewo";
      bitmap = al_load_bitmap("images/tree2.png");
   };
};

class mDrzewo : public Landmark {
public:
   mDrzewo(string __tostr = "L2", string __toatr = "Małe") : Landmark(__tostr, __toatr){
      ToString = "L2";
      nazwa = "male drzewo";
      bitmap = al_load_bitmap("images/tree.png");
   };
};

class Kamien : public Landmark {
public:
   Kamien(string __tostr = "L3", string __toatr = "Twardy") : Landmark(__tostr, __toatr){
      ToString = "L3";
      nazwa = "twardy kamien";
      bitmap = al_load_bitmap("images/stone.png");
   };
};

class Krzak : public Landmark {
public:
   Krzak(string __tostr = "L5", string __toatr = "Zielony") : Landmark(__tostr, __toatr){
      ToString = "L5";
      nazwa = "zielony krzak";
      bitmap = al_load_bitmap("images/bush.png");
   };
};

class Dom : public Landmark {
public:
   Dom(string __tostr = "L4", string __toatr = "Rodzinny") : Landmark(__tostr, __toatr){
      ToString = "L4";
      nazwa = "dom rodzinny";
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
   };
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

/////// LOSOWANIE LANDMARKÓW

item* getRandomLand(){
   int landki;
   //srand(time(NULL));
   landki = rand() % 5;
   switch (landki) {
   case 0: {
      dDrzewo *d = new dDrzewo();
      return d;
   }
   case 1: {
      Kamien *k = new Kamien();
      return k;
   }
   case 2: {
      Dom *dm = new Dom();
      return dm;
   }
   case 3: {
      mDrzewo *mD = new mDrzewo();
      return mD;
   }
   case 4: {
      Krzak *krz = new Krzak();
      return krz;
   }
   }
}

////sprawdzanie elementów obok drogi 

vector<string>trasa;
item* siatka[15][15];

string coToZaElement(string kierunek, int _y, int _x){
   string name = siatka[_y][_x]->ToString;

   //proste
   if (name == "D1" && kierunek == "2"){
      return "Ide na polnoc";
   }
   else if (name == "D1" && kierunek == "4"){
      return "Ide na poludnie";
   }
   else if (name == "D2" && kierunek == "1"){
      return "Ide na wschod";
   }
   else if (name == "D2" && kierunek == "3"){
      return "Ide na zachod";
   }
   //skrzyzowanie
   else if (name == "cr"){
      kierunek = siatka[_y][_x]->getdest();
      if (kierunek == "1")
         return "Na skrzyzowaniu ide na wschod";
      else if (kierunek == "2")
         return "Na skrzyzowaniu ide na polnoc";
      else if (kierunek == "3")
         return "Na skrzyzowaniu ide na zachod";
      else if (kierunek == "4")
         return "Na skrzyzowaniu ide na poludnie";
   }
   //luk lagodny
   else if (name == "z1" && kierunek == "4"){
      return "Skrecam lagodnie z polnocy na zachod";
   }
   else if (name == "z1" && kierunek == "1"){
      return "Skrecam lagodnie z zachodu na polnoc";
   }
   else if (name == "z2" && kierunek == "4"){
      return "Skrecam lagodnie z polnocy na wschod";
   }
   else if (name == "z2" && kierunek == "3"){
      return "Skrecam lagodnie z wschodu na polnoc";
   }
   else if (name == "z3" && kierunek == "2"){
      return "Skrecam lagodnie z poludnia na zachod";
   }
   else if (name == "z3" && kierunek == "1"){
      return "Skrecam lagodnie z zachodu na poludnie";
   }
   else if (name == "z4" && kierunek == "2"){
      return "Skrecam lagodnie z poludnia na wschod";
   }
   else if (name == "z4" && kierunek == "3"){
      return "Skrecam lagodnie z wschodu na poludnie";
   }
   //luk ostry
   else if (name == "z11" && kierunek == "4"){
      return "Skrecam ostro z polnocy na zachod";
   }
   else if (name == "z11" && kierunek == "1"){
      return "Skrecam ostro z zachodu na polnoc";
   }
   else if (name == "z21" && kierunek == "4"){
      return "Skrecam ostro z polnocy na wschod";
   }
   else if (name == "z21" && kierunek == "3"){
      return "Skrecam ostro z wschodu na polnoc";
   }
   else if (name == "z31" && kierunek == "2"){
      return "Skrecam ostro z poludnia na zachod";
   }
   else if (name == "z31" && kierunek == "1"){
      return "Skrecam ostro z zachodu na poludnie";
   }
   else if (name == "z41" && kierunek == "2"){
      return "Skrecam ostro z poludnia na wschod";
   }
   else if (name == "z41" && kierunek == "3"){
      return "Skrecam ostro z wschodu na poludnie";
   }
   else
      return " ";
}

void sprawdz(string kier, int _x, int _y) {
   trasa.clear();
   trasa.resize(0);
   srand(time(NULL));
   for (int i = 0; i < 15; i++){
      if (kier == "1") { //kier w prawo

         if (siatka[_y - 1][_x] == NULL) {

            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y - 1][_x] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y - 1][_x]->nazwa + " na polnocy");
            }
         }
         if (siatka[_y + 1][_x] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y + 1][_x] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y + 1][_x]->nazwa + " na poludniu");
            }
         }
         if (siatka[_y - 2][_x] == NULL) {

            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y - 2][_x] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y - 2][_x]->nazwa + " na polnocy");
            }
         }
         if (siatka[_y + 2][_x] == NULL) {

            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y + 2][_x] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y + 2][_x]->nazwa + " na poludniu");
            }
         }
         trasa.push_back(coToZaElement(kier, _y, _x + 1));
         _x++;
      }
      else if (kier == "2") { //kier w gore

         if (siatka[_y][_x - 1] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x - 1] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y][_x - 1]->nazwa + " na zachodzie");
            }
         }
         if (siatka[_y][_x + 1] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x + 1] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y][_x + 1]->nazwa + " na wschodzie");
            }
         }
         if (siatka[_y][_x + 2] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x + 2] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y][_x + 2]->nazwa + " na wschodzie");
            }
         }
         if (siatka[_y][_x - 2] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x - 2] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y][_x - 2]->nazwa + " na zachodzie");
            }
         }
         trasa.push_back(coToZaElement(kier, _y - 1, _x));
         _y--;
      }
      else if (kier == "3") { //kier w lewo

         if (siatka[_y - 1][_x] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y - 1][_x] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y - 1][_x]->nazwa + " na polnocy");
            }
         }
         if (siatka[_y + 1][_x] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y + 1][_x] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y + 1][_x]->nazwa + " na poludniu");
            }
         }
         if (siatka[_y + 2][_x] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y + 2][_x] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y + 2][_x]->nazwa + " na poludniu");
            }
         }
         if (siatka[_y - 2][_x] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y - 2][_x] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y - 2][_x]->nazwa + " na polnocy");
            }
         }
         trasa.push_back(coToZaElement(kier, _y, _x - 1));
         _x--;
      }
      else if (kier == "4") { //kier w dol

         if (siatka[_y][_x - 1] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x - 1] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y][_x - 1]->nazwa + " na zachodzie");
            }
         }
         if (siatka[_y][_x + 1] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x + 1] = getRandomLand();
               trasa.push_back("Widze blisko " + siatka[_y][_x + 1]->nazwa + " na wschodzie");
            }
         }
         if (siatka[_y][_x + 2] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x + 2] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y][_x + 2]->nazwa + " na wschodzie");
            }
         }
         if (siatka[_y][_x - 2] == NULL) {
            //srand(time(NULL));
            int los = rand() % 4;
            if (los >= 1){ // wstawia element
               siatka[_y][_x - 2] = getRandomLand();
               trasa.push_back("Widze daleko " + siatka[_y][_x - 2]->nazwa + " na zachodzie");
            }
         }
         trasa.push_back(coToZaElement(kier, _y + 1, _x));
         _y++;
      }
      kier = siatka[_y][_x]->getdest();
   }


}
/* deklaracja stałych zawierających szerokość i wysokość okna
*  width = 2 * 300px - po 300px na agenta + 10 na przerwe między ich mapami
*  height = 500px - 300 na wysokość mapki + 200 na log tekstowy z trasą
*  z przyzwyczajenia nazwy stałych piszę wielkimi literami
*  a wieloczłonowe nazwy zmiennych oddzielam '_'
*  by Ironus
*/
const short SCREEN_W = 800, SCREEN_H = 550, MAP_SIDE = 450;

/* deklaracja zmiennej przetrzymującej kod błędu
*  <>0 - błąd
*  ==0 - brak błędu
*/
int error_code = 0;

// deklaracje zmiennych/wskaźników allegro
ALLEGRO_DISPLAY *display = NULL;          // wskaźnik głównego okna
ALLEGRO_FONT *font = NULL;                // wskaźnik na czcionkę
ALLEGRO_EVENT_QUEUE *event_queue = NULL;  // wskaźnik na kolejkę zdarzeń

int graphic_initialize() {
   /* zainicjowanie biblioteki allegro poprzez sprawdzenie zwróconej wartości z al_init()
   *  jeśli if zwróci 1 - błąd inicjalizacji, przerwanie działania programu
   *  jeśli zwróci 0 - zainicjowano allegro, program wykona się dalej
   */
   if (!al_init()) {
      // wyświetlenie okna dialogowego z komunikatem błędu
      al_show_native_message_box(NULL, NULL, "ERROR al_init()", "Błąd inicjalizacji allegro.", NULL, NULL);
      return -1;
   }
   // nadanie wymiarów głownemu okienku
   display = al_create_display(SCREEN_W, SCREEN_H);
   // sprawdzenie utworzenia okienka
   if (!display) {
      al_show_native_message_box(NULL, NULL, "ERROR display", "Błąd tworzenia okna display.", NULL, NULL);
      return -2;
   }
   // inicjalizacja wtyczek
   al_init_image_addon();        // obrazy
   al_init_font_addon();         // czcionka
   al_init_ttf_addon();          // czcionka truetype
   al_init_primitives_addon();   // kształty predefiniowane
   al_install_keyboard();

   //inicjalizacja kolejki
   event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   // załadowanie czcionki
   font = al_load_font("fonts/arial.ttf", 13, 0);
   // sprawdzenie czy załadowana poprawnie
   if (!font) {
      al_show_native_message_box(NULL, NULL, "Font error", "błąd czcionki", NULL, NULL);
      return 1;
   }
   // zwrócenie braku błędu
   return 0;
}
/* funkcje *_destroy i draw w allegro nie zwracają wartości
*  więc funkcje tworzę jako boole zwracające 0 po wykonaniu
*/
bool graphic_destroy() {
   // zniszczenie głównego okna
   al_destroy_display(display);
   // zniszczenie czcionki
   al_destroy_font(font);
   // zniszczenie kolejki
   al_destroy_event_queue(event_queue);
   // zwolnienie wskaźników
   display = NULL;
   font = NULL;
   event_queue = NULL;
   return 0;
}

int main() {
   //wywołanie inicjalizacji silnika graficznego
   graphic_initialize();
   // czyszczenie tła do koloru magenty(255,0,255) :3
   al_clear_to_color(al_map_rgb(255, 255, 255));
   // rysowanie linii oddzielającej mapke od logow
   al_draw_line(MAP_SIDE, 0, MAP_SIDE, SCREEN_H, al_map_rgb(128, 128, 128), 10);
   al_draw_filled_rectangle(0, 0, MAP_SIDE, SCREEN_H, al_map_rgb(255, 255, 255));
   // rysowanie białego tła pod loga
   al_draw_filled_rectangle(MAP_SIDE + 4, 0, SCREEN_W, SCREEN_H, al_map_rgb(255, 255, 255));

   z1 a;
   z2 b;
   z3 c;
   z4 d;
   cross e;
   d1 f;
   d2 g;
   start startl;
   stop stop1;


   int y = 8, x = 8, i = 0;          // zmienne przechowujace miejsce poprzedniego elementu     default srodek
   //item* siatka[15][15];

   std::string opisTrasy = "";

   for (int l = 0; l < 15; l++){
      for (int m = 0; m < 15; m++) {
         siatka[l][m] = NULL;
      }
   }

   srand(time(NULL));

   siatka[y][x] = new start();
   siatka[y][x]->nadajDest("2");


   int zmiennalosowania = 0;


   //int element = rand() % 5 + 1;      //losowanie elementu
   int kierunek = rand() % 4 + 1;      //losowanie kierunku

   if (kierunek == 1 && prawo(x, y, siatka) == true){
      siatka[y][x]->nadajDest("1");
   kier1:
      if (i >= 16) goto live;
      else{
         x++;
         int tempsum = 0;
         if (prawo(x, y, siatka) == true && x + 1<15) tempsum = tempsum + 1;
         if (gora(x, y, siatka) == true && y - 1 >= 0) tempsum = tempsum + 2;
         if (dol(x, y, siatka) == true && y + 1<15) tempsum = tempsum + 4;


         if (tempsum == 1) {
            siatka[y][x] = new d2();
            siatka[y][x]->nadajDest("1");
            opisTrasy += "Ide na wschod";
            trasa.push_back("Ide na wschod");
            i++;
            goto kier1;
         }
         if (tempsum == 2) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z zachodu na polnoc";
               trasa.push_back("Skrecam z zachodu na polnoc");

            }
            if (templuk == 2){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z zachodu na polnoc";
               trasa.push_back("Skrecam ostro z zachodu na polnoc");
            }
            goto kier2;
         }
         if (tempsum == 3) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Ide na wschod";
               trasa.push_back("Ide na wschod");
               goto kier1;
            }
            if (temprand == 2) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z zachodu na polnoc";
               trasa.push_back("Skrecam z zachodu na polnoc");
            }
            if (temprand == 3){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z zachodu na polnoc";
               trasa.push_back("Skrecam ostro z zachodu na polnoc");
            }
            goto kier2;
         }

         if (tempsum == 4) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z zachodu na poludnie";
               trasa.push_back("Skrecam z zachodu na poludnie");

            }
            if (templuk == 2){
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z zachodu na poludnie";
               trasa.push_back("Skrecam ostro z zachodu na poludnie");
            }
            goto kier4;
         }
         if (tempsum == 5) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Ide na wschod";
               trasa.push_back("Ide na wschod");
               goto kier1;
            }
            if (temprand == 2) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z zachodu na poludnie";
               trasa.push_back("Skrecam z zachodu na poludnie");
               goto kier4;
            }
            if (temprand == 3){
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z zachodu na poludnie";
               trasa.push_back("Skrecam ostro z zachodu na poludnie");
               goto kier4;
            }
         }
         if (tempsum == 6) {
            int temprand = rand() % 4 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z zachodu na polnoc";
               trasa.push_back("Skrecam z zachodu na polnoc");
               goto kier2;
            }
            if (temprand == 2){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z zachodu na polnoc";
               trasa.push_back("Skrecam ostro z zachodu na polnoc");
               goto kier2;
            }
            if (temprand == 3) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z zachodu na poludnie";
               trasa.push_back("Skrecam z zachodu na poludnie");
               goto kier4;
            }
            if (temprand == 4) {
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z zachodu na poludnie";
               trasa.push_back("Skrecam ostro z zachodu na poludnie");
               goto kier4;
            }
         }
         if (tempsum == 7) {
            int temprand = rand() % 6 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z zachodu na polnoc";
               trasa.push_back("Skrecam z zachodu na polnoc");
               goto kier2;
            }
            if (temprand == 2){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z zachodu na polnoc";
               trasa.push_back("Skrecam ostro z zachodu na polnoc");
               goto kier2;
            }
            if (temprand == 3) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z zachodu na poludnie";
               trasa.push_back("Skrecam z zachodu na poludnie");
               goto kier4;
            }
            if (temprand == 4) {
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z zachodu na poludnie";
               trasa.push_back("Skrecam ostro z zachodu na poludnie");
               goto kier4;

            }
            if (temprand == 5) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Ide na wschod";
               trasa.push_back("Ide na wschod");
               goto kier1;
            }
            if (temprand == 6){
               siatka[y][x] = new cross(); i++;
               int temprandcross = rand() % 3 + 1;
               if (temprandcross == 1){
                  siatka[y][x]->nadajDest("2");
                  opisTrasy += "Na skrzyzowaniu ide na polnoc";
                  trasa.push_back("Na skrzyzowaniu ide na polnoc");
                  goto kier2;

               }
               if (temprandcross == 2){
                  siatka[y][x]->nadajDest("1");
                  opisTrasy += "Na skrzyzowaniu ide na wschod";
                  trasa.push_back("Na skrzyzowaniu ide na wschod");
                  goto kier1;

               }
               if (temprandcross == 3){
                  siatka[y][x]->nadajDest("4");
                  opisTrasy += "Na skrzyzowaniu ide na poludnie";
                  trasa.push_back("Na skrzyzowaniu ide na poludnie");
                  goto kier4;

               }

            }

         }

      }

   }


   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   2

   if (kierunek == 2 && gora(x, y, siatka) == true){
      siatka[y][x]->nadajDest("2");
   kier2:
      if (i >= 16) goto live;
      else{
         y--;
         int tempsum = 0;
         if (prawo(x, y, siatka) == true) tempsum = tempsum + 1;
         if (gora(x, y, siatka) == true) tempsum = tempsum + 2;
         if (lewo(x, y, siatka) == true) tempsum = tempsum + 4;


         if (tempsum == 1) {



            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z poludnia na wschod";
               trasa.push_back("Skrecam z poludnia na wschod");
            }
            if (templuk == 2){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z poludnia na wschod";
               trasa.push_back("Skrecam ostro z poludnia na wschod");
            }

            goto kier1;
         }
         if (tempsum == 2) {
            siatka[y][x] = new d1();
            siatka[y][x]->nadajDest("2"); i++;
            opisTrasy += "Ide na polnoc";
            trasa.push_back("Ide na polnoc");
            goto kier2;
         }
         if (tempsum == 3) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Ide na polnoc";
               trasa.push_back("Ide na polnoc");
               goto kier2;
            }
            if (temprand == 2) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z poludnia na wschod";
               trasa.push_back("Skrecam z poludnia na wschod");
               goto kier1;
            }
            if (temprand == 3){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z poludnia na wschod";
               trasa.push_back("Skrecam ostro z poludnia na wschod");
               goto kier1;
            }
         }
         if (tempsum == 4) {




            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z poludnia na zachod";
               trasa.push_back("Skrecam z poludnia na zachod");
            }
            if (templuk == 2){
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z poludnia na zachod";
               trasa.push_back("Skrecam ostro z poludnia na zachod");
            }



            goto kier3;
         }
         if (tempsum == 5) {
            int temprand = rand() % 4 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z poludnia na wschod";
               trasa.push_back("Skrecam z poludnia na wschod");
               goto kier1;
            }
            if (temprand == 2) {
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z poludnia na wschod";
               trasa.push_back("Skrecam ostro z poludnia na wschod");
               goto kier1;
            }
            if (temprand == 3) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z poludnia na zachod";
               trasa.push_back("Skrecam z poludnia na zachod");
               goto kier3;
            }
            if (temprand == 4){
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z poludnia na zachod";
               trasa.push_back("Skrecam ostro z poludnia na zachod");
               goto kier3;


            }
         }
         if (tempsum == 6) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Ide na polnoc";
               trasa.push_back("Ide na polnoc");
               goto kier2;
            }
            if (temprand == 2) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z poludnia na zachod";
               trasa.push_back("Skrecam z poludnia na zachod");
               goto kier3;
            }
            if (temprand == 3){
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z poludnia na zachod";
               trasa.push_back("Skrecam ostro z poludnia na zachod");
               goto kier3;
            }
         }
         if (tempsum == 7) {
            int temprand = rand() % 6 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z poludnia na wschod";
               trasa.push_back("Skrecam z poludnia na wschod");
               goto kier1;
            }
            if (temprand == 2) {
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z poludnia na wschod";
               trasa.push_back("Skrecam ostro z poludnia na wschod");
               goto kier1;
            }
            if (temprand == 3) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Ide na polnoc";
               trasa.push_back("Ide na polnoc");
               goto kier2;
            }
            if (temprand == 4) {
               siatka[y][x] = new z3();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z poludnia na zachod";
               trasa.push_back("Skrecam z poludnia na zachod");
               goto kier3;
            }
            if (temprand == 5) {
               siatka[y][x] = new z31();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z poludnia na zachod";
               trasa.push_back("Skrecam ostro z poludnia na zachod");
               goto kier3;
            }
            if (temprand == 6){
               siatka[y][x] = new cross(); i++;
               int temprandcross = rand() % 3 + 1;
               if (temprandcross == 1){
                  siatka[y][x]->nadajDest("1");
                  opisTrasy += "Na skrzyzowaniu ide na wschod";
                  trasa.push_back("Na skrzyzowaniu ide na wschod");
                  goto kier1;

               }
               if (temprandcross == 2){
                  siatka[y][x]->nadajDest("3");
                  opisTrasy += "Na skrzyzowaniu ide na zachod";
                  trasa.push_back("Na skrzyzowaniu ide na zachod");
                  goto kier3;

               }
               if (temprandcross == 3){
                  siatka[y][x]->nadajDest("2");
                  opisTrasy += "Na skrzyzowaniu ide na polnoc";
                  trasa.push_back("Na skrzyzowaniu ide na polnoc");
                  goto kier2;

               }

            }
         }
      }
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////   3
   if (kierunek == 3 && lewo(x, y, siatka) == true){
      siatka[y][x]->nadajDest("3");
   kier3:
      if (i >= 16) goto live;
      else{
         x--;
         int tempsum = 0;
         if (dol(x, y, siatka) == true) tempsum = tempsum + 1;
         if (gora(x, y, siatka) == true) tempsum = tempsum + 2;
         if (lewo(x, y, siatka) == true) tempsum = tempsum + 4;


         if (tempsum == 1) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z wschodu na poludnie";
               trasa.push_back("Skrecam z wschodu na poludnie");
            }
            if (templuk == 2){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z wschodu na poludnie";
               trasa.push_back("Skrecam ostro z wschodu na poludnie");
            }
            goto kier4;
         }
         if (tempsum == 2) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z wschodu na polnoc";
               trasa.push_back("Skrecam z wschodu na polnoc");

            }
            if (templuk == 2){
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z wschodu na polnoc";
               trasa.push_back("Skrecam ostro z wschodu na polnoc");
            }
            goto kier2;
         }
         if (tempsum == 3) {
            int temprand = rand() % 4 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z wschodu na poludnie";
               trasa.push_back("Skrecam z wschodu na poludnie");
               goto kier4;
            }
            if (temprand == 2){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z wschodu na poludnie";
               trasa.push_back("Skrecam ostro z wschodu na poludnie");
            }
            if (temprand == 3) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z wschodu na polnoc";
               trasa.push_back("Skrecam z wschodu na polnoc");
               goto kier2;
            }
            if (temprand == 4){
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z wschodu na polnoc";
               trasa.push_back("Skrecam ostro z wschodu na polnoc");
               goto kier2;
            }
         }
         if (tempsum == 4) {
            siatka[y][x] = new d2();
            siatka[y][x]->nadajDest("3"); i++;
            opisTrasy += "Ide na zachod";
            trasa.push_back("Ide na zachod");
            goto kier3;
         }
         if (tempsum == 5) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam z wschodu na poludnie";
               trasa.push_back("Skrecam z wschodu na poludnie");
               goto kier4;
            }
            if (temprand == 2){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Skrecam ostro z wschodu na poludnie";
               trasa.push_back("Skrecam ostro z wschodu na poludnie");
               goto kier4;
            }
            if (temprand == 3) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Ide na zachod";
               trasa.push_back("Ide na zachod");
               goto kier3;
            }
         }
         if (tempsum == 6) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Ide na zachod";
               trasa.push_back("Ide na zachod");
               goto kier3;
            }
            if (temprand == 2) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z wschodu na polnoc";
               trasa.push_back("Skrecam z wschodu na polnoc");
               goto kier2;
            }
            if (temprand == 3){
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z wschodu na polnoc";
               trasa.push_back("Skrecam ostro z wschodu na polnoc");
               goto kier2;

            }
         }
         if (tempsum == 7) {
            int temprand = rand() % 6 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z4();
               siatka[y][x]->nadajDest("4"); i++; //Dominik - bylo nadajdest("1"), jak tak mialo byc to poprawcie z powrotem
               opisTrasy += "Skrecam z wschodu na poludnie";
               trasa.push_back("Skrecam z wschodu na poludnie");
               goto kier4;
            }
            if (temprand == 2){
               siatka[y][x] = new z41();
               siatka[y][x]->nadajDest("4"); i++; // tutaj tez
               opisTrasy += "Skrecam ostro z wschodu na poludnie";
               trasa.push_back("Skrecam ostro z wschodu na poludnie");
               goto kier4;

            }
            if (temprand == 3) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam z wschodu na polnoc";
               trasa.push_back("Skrecam z wschodu na polnoc");
               goto kier2;
            }
            if (temprand == 4) {
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("2"); i++;
               opisTrasy += "Skrecam ostro z wschodu na polnoc";
               trasa.push_back("Skrecam ostro z wschodu na polnoc");
               goto kier2;

            }
            if (temprand == 5) {
               siatka[y][x] = new d2();
               siatka[y][x]->nadajDest("3"); i++; //Dominik - dodalem bo chyba brakowalo, jak sie myle to wywalcie
               opisTrasy += "Ide na zachod";
               trasa.push_back("Ide na zachod");
               goto kier3;
            }
            if (temprand == 6){
               siatka[y][x] = new cross(); i++;
               int temprandcross = rand() % 3 + 1;
               if (temprandcross == 1){
                  siatka[y][x]->nadajDest("2");
                  opisTrasy += "Na skrzyzowaniu ide na polnoc";
                  trasa.push_back("Na skrzyzowaniu ide na polnoc");
                  goto kier2;

               }
               if (temprandcross == 2){
                  siatka[y][x]->nadajDest("3");
                  opisTrasy += "Na skrzyzowaniu ide na zachod";
                  trasa.push_back("Na skrzyzowaniu ide na zachod");
                  goto kier3;

               }
               if (temprandcross == 3){
                  siatka[y][x]->nadajDest("4");
                  opisTrasy += "Na skrzyzowaniu ide na poludnie";
                  trasa.push_back("Na skrzyzowaniu ide na poludnie");
                  goto kier4;

               }

            }
         }
      }
   }


   if (kierunek == 4 && dol(x, y, siatka) == true){
      siatka[y][x]->nadajDest("4");
   kier4:
      if (i >= 16) goto live;
      else{
         y++;
         int tempsum = 0;
         if (dol(x, y, siatka) == true) tempsum = tempsum + 1;
         if (prawo(x, y, siatka) == true) tempsum = tempsum + 2;
         if (lewo(x, y, siatka) == true) tempsum = tempsum + 4;


         if (tempsum == 1) {
            siatka[y][x] = new d1();
            siatka[y][x]->nadajDest("4"); i++;
            opisTrasy += "Ide na poludnie";
            trasa.push_back("Ide na poludnie");
            goto kier4;
         }
         if (tempsum == 2) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z polnocy na wschod";
               trasa.push_back("Skrecam z polnocy na wschod");
            }
            if (templuk == 2){
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z polnocy na wschod";
               trasa.push_back("Skrecam ostro z polnocy na wschod");
            }
            goto kier1;
         }
         if (tempsum == 3) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Ide na poludnie";
               trasa.push_back("Ide na poludnie");
               goto kier4;
            }
            if (temprand == 2) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z polnocy na wschod";
               trasa.push_back("Skrecam z polnocy na wschod");
               goto kier1;
            }
            if (tempsum == 3) {
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z polnocy na wschod";
               trasa.push_back("Skrecam ostro z polnocy na wschod");
               goto kier1;

            }
         }
         if (tempsum == 4) {
            int templuk = rand() % 2 + 1;
            if (templuk == 1){
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z polnocy na zachod";
               trasa.push_back("Skrecam z polnocy na zachod");
            }
            if (templuk == 2){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z polnocy na zachod";
               trasa.push_back("Skrecam ostro z polnocy na zachod");
            }
            goto kier3;
         }
         if (tempsum == 5) {
            int temprand = rand() % 3 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Ide na poludnie";
               trasa.push_back("Ide na poludnie");
               goto kier4;
            }
            if (temprand == 2) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z polnocy na zachod";
               trasa.push_back("Skrecam z polnocy na zachod");
               goto kier3;
            }
            if (temprand == 3){
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z polnocy na zachod";
               trasa.push_back("Skrecam ostro z polnocy na zachod");
               goto kier3;
            }
         }
         if (tempsum == 6) {
            int temprand = rand() % 4 + 1;
            if (temprand == 1) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z polnocy na zachod";
               trasa.push_back("Skrecam z polnocy na zachod");
               goto kier3;
            }
            if (temprand == 2) {
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z polnocy na zachod";
               trasa.push_back("Skrecam ostro z polnocy na zachod");
               goto kier3;
            }
            if (temprand == 3) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z polnocy na wschod";
               trasa.push_back("Skrecam z polnocy na wschod");
               goto kier1;
            }
            if (temprand == 4) {
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z polnocy na wschod";
               trasa.push_back("Skrecam ostro z polnocy na wschod");
               goto kier1;
            }
         }
         if (tempsum == 7) {
            int temprand = rand() % 4 + 1;
            if (temprand == 1) {
               siatka[y][x] = new d1();
               siatka[y][x]->nadajDest("4"); i++;
               opisTrasy += "Ide na poludnie";
               trasa.push_back("Ide na poludnie");
               goto kier4;
            }
            if (temprand == 2) {
               siatka[y][x] = new z2();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam z polnocy na wschod";
               trasa.push_back("Skrecam z polnocy na wschod");
               goto kier1;
            }
            if (temprand == 3) {
               siatka[y][x] = new z21();
               siatka[y][x]->nadajDest("1"); i++;
               opisTrasy += "Skrecam ostro z polnocy na wschod";
               trasa.push_back("Skrecam ostro z polnocy na wschod");
               goto kier1;
            }
            if (temprand == 4) {
               siatka[y][x] = new z1();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam z polnocy na zachod";
               trasa.push_back("Skrecam z polnocy na zachod");
               goto kier3;
            }
            if (temprand == 5) {
               siatka[y][x] = new z11();
               siatka[y][x]->nadajDest("3"); i++;
               opisTrasy += "Skrecam ostro z polnocy na zachod";
               trasa.push_back("Skrecam ostro z polnocy na zachod");
               goto kier3;
            }
            if (temprand == 6){
               siatka[y][x] = new cross(); i++;
               int temprandcross = rand() % 3 + 1;
               if (temprandcross == 1){
                  siatka[y][x]->nadajDest("3");
                  opisTrasy += "Na skrzyzowaniu ide na zachod";
                  trasa.push_back("Na skrzyzowaniu ide na zachod");
                  goto kier3;

               }
               if (temprandcross == 2){
                  siatka[y][x]->nadajDest("1");
                  opisTrasy += "Na skrzyzowaniu ide na wschod";
                  trasa.push_back("Na skrzyzowaniu ide na wschod");
                  goto kier1;

               }
               if (temprandcross == 3){
                  siatka[y][x]->nadajDest("4");
                  opisTrasy += "Na skrzyzowaniu ide na poludnie";
                  trasa.push_back("Na skrzyzowaniu ide na poludnie");
                  goto kier4;

               }

            }
         }
      }
   }

   if (prawo(x, y, siatka) == false && lewo(x, y, siatka) == false && gora(x, y, siatka) == false && dol(x, y, siatka) == false){
      siatka[y][x] = new stop();
      opisTrasy += "Koniec trasy";
      trasa.push_back("Koniec Trasy");
      i = 10;
   }





live:
   siatka[y][x] = new stop;
   int j = 0;

   sprawdz(siatka[8][8]->getdest(), 8, 8);
   ///////////////////////////////////////////////////////////////////////////////////////////////
   //                                  ZEROWANIE   X I Y   Z TRASY                              //
   ///////////////////////////////////////////////////////////////////////////////////////////////


   while (siatka[y][x]->ToString != "Sp"){
      if (prawo(x, y, siatka) == true) {}
      if (lewo(x, y, siatka) == true) {}
      if (gora(x, y, siatka) == true) {}
      if (dol(x, y, siatka) == true) {}
   }

   cout << opisTrasy;
   trasa[trasa.size() - 1] = "STOP";
   FileHandler::write(opisTrasy, "opisTrasy.txt");

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

      for (int l = 0; l < 15; l++){
         for (int m = 0; m < 15; m++) {
            if (siatka[l][m] != NULL)
            {
               cout << " ";
               cout << siatka[l][m]->getvalue();
               cout << " ";
            }

            else cout << "    ";
         }
         cout << endl;
      }



      int round = 0;
      int jump = 12;
      for (int k = 0; k < trasa.size(); k++) {
         if (trasa[k] != " ") {
            al_draw_textf(font, al_map_rgb(0, 0, 0), MAP_SIDE + 10, 10 + round * jump, 0, "%s", trasa[k].c_str());
            round++;
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