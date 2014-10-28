#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
/*
*  klasa skupiaj¹ca elementy mapy
*/
class map_objects {
protected:
   /* parametry (x,y) - przypisywane przez konstruktor
   *  równe wspó³rzêdnym w tabeli, w której znajduje siê obiekt
   *  przemno¿one przez 30 (rozmiar jednego klocka) dadz¹ wspó³rzêdne rysowania
   */
   short x;    //x w prawo
   short y;    //y w dó³
   /*
   *  zmienna odpowiedzialna za przesuniêcie x o 310px w prawo
   *  wykorzystywana przy odwzorowywaniu mapy przez agenta 2
   *  jeœli mapa jest rysowana dla agenta 1 - zmienna ma wartoœæ 0
   *  jeœli dla agenta 2 - wartoœæ 310
   *  jest dodawana w funkcji rysowania
   */
   short add_pixels;
   // zmienna przechowuj¹ca œcie¿kê do pliku z bitmap¹
   ALLEGRO_BITMAP *bitmap = NULL;
public:
   // konstruktor i dekonstruktor
   map_objects(short x, short y, short agent_nbr);
   ~map_objects();
   // funkcja rysuj¹ca bitmape
   void draw();
};

