#pragma once
#include "stdafx.h"
#include "AbstractRoom.h"
namespace MazeInCPP {
	class NormalRoom : public AbstractRoom
	{
	protected:
		AbstractRoom * trap;
	public:
		NormalRoom(std::string n);
		NormalRoom();
		void set_link(char dir, AbstractRoom* room);
		AbstractRoom * get_link(char dir);
		std::string get_directions();
	};
}
