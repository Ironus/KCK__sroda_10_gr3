#pragma once

class Item
{
	public:
		// get image path relatively to main.cpp file
		virtual std::string getImage() = 0;
};
