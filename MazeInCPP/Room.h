#pragma once
#include "AbstractRoom.h"
#include "Includes.h"
class NormalRoom : public AbstractRoom
{
private:
	AbstractRoom * trap;
public: 
	NormalRoom(std::string n);
	void set_link(char dir, AbstractRoom* room);
	AbstractRoom * get_link(char dir);
	std::string get_directions();
};