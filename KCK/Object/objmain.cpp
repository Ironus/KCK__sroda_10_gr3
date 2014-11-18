#include <iostream>
#include "Items/Routes/Route.cpp"
#include "Items/Routes/RouteDirection.cpp"
//#include <string>

int main(int argc, char** argv)
{
	Route r = new Route(RouteDirection::North, RouteDirection::South);
	
	return 0;
}
