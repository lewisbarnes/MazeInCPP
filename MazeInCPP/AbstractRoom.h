#pragma once
#include "Includes.h"

class AbstractRoom
{
protected:
	std::string name;
	AbstractRoom * north = nullptr;
	AbstractRoom * east = nullptr;
	AbstractRoom * south = nullptr;
	AbstractRoom * west = nullptr;
public:
	AbstractRoom();
	AbstractRoom(std::string n);
	virtual void set_link(char dir, AbstractRoom* room);
	virtual AbstractRoom* get_link(char dir);
	virtual std::string get_directions();
	std::string get_name();
};