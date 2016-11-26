#pragma once

#include "matrix_processor.h"
#include <stdlib.h>
#include <time.h>

class matrix_generator
{
private:
	std::string generate_game_line();
public:
	Matrix generate_game_matrix();
};

