#pragma once
#include "../Item.cpp"
#include "RouteDirection.cpp"
#include "RouteTranslator.cpp"

class Route: public Item
{
    public:
		RouteDirection start;
		RouteDirection end;
		std::string image;
		
		Route(RouteDirection start, RouteDirection end)
		{
			if (start == end) throw -1;
			
			this->start = start;
			this->end = end;
		}
		
		std::string getImage()
		{
			return "/Routes/images/" + this->start + this->end + "Route.png";
		}
		
		std::string toString()
		{
			return RouteTranslator::directionToString(this->end);
		}
};
