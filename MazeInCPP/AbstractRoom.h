#pragma once
#include "stdafx.h"
namespace MazeInCPP
{
	class BaseRoom
	{
	protected:
		std::string name;
		BaseRoom * north;
		BaseRoom * east;
		BaseRoom * south;
		BaseRoom * west;
	public:
		BaseRoom(std::string n);
		virtual void set_link(char dir, BaseRoom* room);
		virtual BaseRoom* get_link(char dir);
		virtual std::string get_directions();
		std::string get_name();
	};
}
