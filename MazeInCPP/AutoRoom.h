#pragma once
#include "NormalRoom.h"
#include "Includes.h"
class AutoRoom : public NormalRoom
{
private:
	bool visited = false;

public:
	bool Visited() { return visited; };
	bool visit();
	AutoRoom(std::string n);
	AutoRoom();
	std::string get_directions();

};