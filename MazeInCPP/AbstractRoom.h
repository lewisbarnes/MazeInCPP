#pragma once
#include "Includes.h"

class AbstractRoom
{
protected:
	std::string name;
	AbstractRoom * north;
	AbstractRoom * east;
	AbstractRoom * south;
	AbstractRoom * west;

public:
	AbstractRoom();
	AbstractRoom(std::string n);
	virtual void set_link(char dir, AbstractRoom* room);
	virtual AbstractRoom* get_link(char dir);
	virtual std::string get_directions();
	std::string get_name();
};