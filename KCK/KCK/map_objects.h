#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
/*
*  klasa skupiaj�ca elementy mapy
*/
class map_objects {
protected:
   /* parametry (x,y) - przypisywane przez konstruktor
   *  r�wne wsp�rz�dnym w tabeli, w kt�rej znajduje si� obiekt
   *  przemno�one przez 30 (rozmiar jednego klocka) dadz� wsp�rz�dne rysowania
   */
   short x;    //x w prawo
   short y;    //y w d�
   /*
   *  zmienna odpowiedzialna za przesuni�cie x o 310px w prawo
   *  wykorzystywana przy odwzorowywaniu mapy przez agenta 2
   *  je�li mapa jest rysowana dla agenta 1 - zmienna ma warto�� 0
   *  je�li dla agenta 2 - warto�� 310
   *  jest dodawana w funkcji rysowania
   */
   short add_pixels;
   // zmienna przechowuj�ca �cie�k� do pliku z bitmap�
   ALLEGRO_BITMAP *bitmap = NULL;
public:
   // konstruktor i dekonstruktor
   map_objects(short x, short y, short agent_nbr);
   ~map_objects();
   // funkcja rysuj�ca bitmape
   void draw();
};

