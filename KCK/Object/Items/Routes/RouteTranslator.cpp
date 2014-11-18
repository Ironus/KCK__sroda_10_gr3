#pragma once
#include "RouteDirection.cpp"

class RouteTranslator
{
    public:
		static std::string directionToString(RouteDirection direction)
		{
			std::string directionString;
			
			switch(direction)
			{
				case RouteDirection::North:
					directionString = "północnym";
				break;
				case RouteDirection::East:
					directionString = "wschodnim";
				break;
				case RouteDirection::South:
					directionString = "południowym";
				break;
				case RouteDirection::West:
					directionString = "zachodnim";
				break;
			}				
			
			return "w kierunku " + directionString;
		}
};
