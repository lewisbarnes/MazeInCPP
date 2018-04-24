#pragma once
#include "stdafx.h"
#include "AbstractRoom.h"
namespace MazeInCPP {
	class NormalRoom : public BaseRoom
	{
	protected:
		BaseRoom * trap;
	public:
		NormalRoom(std::string n);
		void set_link(char dir, BaseRoom* room);
		BaseRoom * get_link(char dir);
		std::string get_directions();
	};
}
