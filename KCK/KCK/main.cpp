#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>

/* deklaracja sta�ych zawieraj�cych szeroko�� i wysoko�� okna
*  width = 2 * 300px - po 300px na agenta + 10 na przerwe mi�dzy ich mapami
*  height = 500px - 300 na wysoko�� mapki + 200 na log tekstowy z tras�
*  z przyzwyczajenia nazwy sta�ych pisz� wielkimi literami
*  a wielocz�onowe nazwy zmiennych oddzielam '_'
*  by Ironus
*/
const short SCREEN_W = 610, SCREEN_H = 500, MAP_SIDE = 300;

/* deklaracja zmiennej przetrzymuj�cej kod b��du
*  <>0 - b��d
*  ==0 - brak b��du
*/
int error_code = 0;

// deklaracje zmiennych/wska�nik�w allegro
ALLEGRO_DISPLAY *display = NULL;          // wska�nik g��wnego okna
ALLEGRO_FONT *font = NULL;                // wska�nik na czcionk�

int graphic_initialize() {
   /* zainicjowanie biblioteki allegro poprzez sprawdzenie zwr�conej warto�ci z al_init()
   *  je�li if zwr�ci 1 - b��d inicjalizacji, przerwanie dzia�ania programu
   *  je�li zwr�ci 0 - zainicjowano allegro, program wykona si� dalej
   */
   if (!al_init()) {
      // wy�wietlenie okna dialogowego z komunikatem b��du
      al_show_native_message_box(NULL, NULL, "ERROR al_init()", "B��d inicjalizacji allegro.", NULL, NULL);
      return -1;
   }
   // nadanie wymiar�w g�ownemu okienku
   display = al_create_display(SCREEN_W, SCREEN_H);
   // sprawdzenie utworzenia okienka
   if (!display) {
      al_show_native_message_box(NULL, NULL, "ERROR display", "B��d tworzenia okna display.", NULL, NULL);
      return -2;
   }
   // inicjalizacja wtyczek
   al_init_image_addon();        // obrazy
   al_init_font_addon();         // czcionka
   al_init_ttf_addon();          // czcionka truetype
   al_init_primitives_addon();   // kszta�ty predefiniowane
   // za�adowanie czcionki
   font = al_load_font("fonts/arial.ttf", 16, 0);
   // sprawdzenie czy za�adowana poprawnie
   if (!font) {
      al_show_native_message_box(NULL, NULL, "Font error", "b��d czcionki", NULL, NULL);
      return 1;
   }
   // zwr�cenie braku b��du
   return 0;
}
/* funkcje *_destroy i draw w allegro nie zwracaj� warto�ci 
*  wi�c funkcje tworz� jako boole zwracaj�ce 0 po wykonaniu
*/
bool graphic_destroy() {
   // zniszczenie g��wnego okna
   al_destroy_display(display);
   // zniszczenie czcionki
   al_destroy_font(font);
   // zwolnienie wska�nik�w
   display = NULL;
   font = NULL;
   return 0;
}
//funkcja rysuj�ca menu
bool draw_menu() {
   // czyszczenie t�a do koloru magenty(255,0,255) :3
   al_clear_to_color(al_map_rgb(255, 0, 255));
   // rysowanie linii oddzielaj�cej mapki od siebie
   al_draw_line(MAP_SIDE, 0, MAP_SIDE, MAP_SIDE, al_map_rgb(128, 128, 128), 10);
   // rysowanie linii oddzielaj�cej mapki od log�w
   al_draw_line(0, MAP_SIDE + 2, SCREEN_W, MAP_SIDE + 2, al_map_rgb(128, 128, 128), 4);
   // rysowanie bia�ego t�a pod loga
   al_draw_filled_rectangle(0, MAP_SIDE + 4, SCREEN_W, SCREEN_H, al_map_rgb(255, 255, 255));
   // rysowanie tekstu
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 10, 0, "1. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 25, 0, "2. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 40, 0, "3. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 55, 0, "4. Log agenta");
   // zmiana buffera (wy�wietlanego ekranu)
   al_flip_display();
   //zwr�cenie braku b��du
   return 0;
}

int main() {
   //wywo�anie inicjalizacji silnika graficznego
   error_code = graphic_initialize();
   if (error_code != 0) {
      // wy�wietlenie okna dialogowego z komunikatem b��du
      al_show_native_message_box(NULL, NULL, "Graphic error", "Kod b��du: " + error_code, NULL, NULL);
      return error_code;
   }
   // wywo�anie funkcji rysuj�cej menu
   error_code = draw_menu();
   if (error_code != 0) {
      // wy�wietlenie okna dialogowego z komunikatem b��du
      al_show_native_message_box(NULL, NULL, "Graphic error", "Kod b��du: " + error_code, NULL, NULL);
      return error_code;
   }
   al_rest(5.0);
   graphic_destroy();
   return 0;
}