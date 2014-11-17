#include <iostream>
using namespace std;


class item{};

class Trasa: public item{
    public:
    string image;
    bool Lewo, Prawo, Gora, Dol;
    Trasa(bool l, bool p, bool g, bool d){
        Lewo = l;
        Prawo = p;
        Gora = g;
        Dol = d;
        }
};

class Landmark: public item{
    public:
    string image, Nazwa, Atrybut;
    Landmark(string I, string N, string A){
        image = I;
        Nazwa = N;
        Atrybut = A;
        }
};
/*
                                            1   / \    2            Rodzaje zakrêtów
                                               /   \


                                               \   /
                                            3   \ /    4

*/
class z1: public Trasa
{
    string image;
    string ToString; // Opis dla agenta 2

    z1(){
    Trasa(true,false,true,false);
    }

};

class z2: public Trasa
{
    string image;
    string ToString;
    z2(){
    Trasa(false,true,true,false);
    }

};

class z3: public Trasa
{
    string image;
    string ToString;
    z3(){
    Trasa(true,false,false,true);
    }
};

class z4: public Trasa
{
    string image;
    string ToString;

    z4(){
    Trasa(false,true,false,true);
    }
};



class cross: public Trasa
{
    string image;
    string ToString;

    Trasa(true,true,true,true);
};
/*
class lukL : public Trasa
{
	string image;
    string ToString;



};

class lukP : public Trasa
{
	string image;
    string ToString;



};
class lukG : public Trasa
{
	string image;
    string ToString;



};
class lukD : public Trasa
{
	string image;
    string ToString;



};

*/



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
