#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>

/* deklaracja sta³ych zawieraj¹cych szerokoœæ i wysokoœæ okna
*  width = 2 * 300px - po 300px na agenta + 10 na przerwe miêdzy ich mapami
*  height = 500px - 300 na wysokoœæ mapki + 200 na log tekstowy z tras¹
*  z przyzwyczajenia nazwy sta³ych piszê wielkimi literami
*  a wielocz³onowe nazwy zmiennych oddzielam '_'
*  by Ironus
*/
const short SCREEN_W = 610, SCREEN_H = 500, MAP_SIDE = 300;

/* deklaracja zmiennej przetrzymuj¹cej kod b³êdu
*  <>0 - b³¹d
*  ==0 - brak b³êdu
*/
int error_code = 0;

// deklaracje zmiennych/wskaŸników allegro
ALLEGRO_DISPLAY *display = NULL;          // wskaŸnik g³ównego okna
ALLEGRO_FONT *font = NULL;                // wskaŸnik na czcionkê

int graphic_initialize() {
   /* zainicjowanie biblioteki allegro poprzez sprawdzenie zwróconej wartoœci z al_init()
   *  jeœli if zwróci 1 - b³¹d inicjalizacji, przerwanie dzia³ania programu
   *  jeœli zwróci 0 - zainicjowano allegro, program wykona siê dalej
   */
   if (!al_init()) {
      // wyœwietlenie okna dialogowego z komunikatem b³êdu
      al_show_native_message_box(NULL, NULL, "ERROR al_init()", "B³¹d inicjalizacji allegro.", NULL, NULL);
      return -1;
   }
   // nadanie wymiarów g³ownemu okienku
   display = al_create_display(SCREEN_W, SCREEN_H);
   // sprawdzenie utworzenia okienka
   if (!display) {
      al_show_native_message_box(NULL, NULL, "ERROR display", "B³¹d tworzenia okna display.", NULL, NULL);
      return -2;
   }
   // inicjalizacja wtyczek
   al_init_image_addon();        // obrazy
   al_init_font_addon();         // czcionka
   al_init_ttf_addon();          // czcionka truetype
   al_init_primitives_addon();   // kszta³ty predefiniowane
   // za³adowanie czcionki
   font = al_load_font("fonts/arial.ttf", 16, 0);
   // sprawdzenie czy za³adowana poprawnie
   if (!font) {
      al_show_native_message_box(NULL, NULL, "Font error", "b³¹d czcionki", NULL, NULL);
      return 1;
   }
   // zwrócenie braku b³êdu
   return 0;
}
/* funkcje *_destroy i draw w allegro nie zwracaj¹ wartoœci 
*  wiêc funkcje tworzê jako boole zwracaj¹ce 0 po wykonaniu
*/
bool graphic_destroy() {
   // zniszczenie g³ównego okna
   al_destroy_display(display);
   // zniszczenie czcionki
   al_destroy_font(font);
   // zwolnienie wskaŸników
   display = NULL;
   font = NULL;
   return 0;
}
//funkcja rysuj¹ca menu
bool draw_menu() {
   // czyszczenie t³a do koloru magenty(255,0,255) :3
   al_clear_to_color(al_map_rgb(255, 0, 255));
   // rysowanie linii oddzielaj¹cej mapki od siebie
   al_draw_line(MAP_SIDE, 0, MAP_SIDE, MAP_SIDE, al_map_rgb(128, 128, 128), 10);
   // rysowanie linii oddzielaj¹cej mapki od logów
   al_draw_line(0, MAP_SIDE + 2, SCREEN_W, MAP_SIDE + 2, al_map_rgb(128, 128, 128), 4);
   // rysowanie bia³ego t³a pod loga
   al_draw_filled_rectangle(0, MAP_SIDE + 4, SCREEN_W, SCREEN_H, al_map_rgb(255, 255, 255));
   // rysowanie tekstu
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 10, 0, "1. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 25, 0, "2. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 40, 0, "3. Log agenta");
   al_draw_text(font, al_map_rgb(0, 0, 0), 10, MAP_SIDE + 55, 0, "4. Log agenta");
   // zmiana buffera (wyœwietlanego ekranu)
   al_flip_display();
   //zwrócenie braku b³êdu
   return 0;
}

int main() {
   //wywo³anie inicjalizacji silnika graficznego
   error_code = graphic_initialize();
   if (error_code != 0) {
      // wyœwietlenie okna dialogowego z komunikatem b³êdu
      al_show_native_message_box(NULL, NULL, "Graphic error", "Kod b³êdu: " + error_code, NULL, NULL);
      return error_code;
   }
   // wywo³anie funkcji rysuj¹cej menu
   error_code = draw_menu();
   if (error_code != 0) {
      // wyœwietlenie okna dialogowego z komunikatem b³êdu
      al_show_native_message_box(NULL, NULL, "Graphic error", "Kod b³êdu: " + error_code, NULL, NULL);
      return error_code;
   }
   al_rest(5.0);
   graphic_destroy();
   return 0;
}