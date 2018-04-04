#pragma once
#include "stdafx.h"
class Global {
public:
	static std::string get_cwd() {
		char buff[FILENAME_MAX];
		_getcwd(buff, FILENAME_MAX);
		std::string current_working_dir(buff);
		return current_working_dir;
	}
};