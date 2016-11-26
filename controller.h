#pragma once

#include <locale>
#include "model.h"
#include "view.h"

class controller
{
private:
	model Model;
	view View;

public:
	void execute();
};

