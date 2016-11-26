#pragma once

#include "view.h"
#include "matrix_generator.h"
#include "matrix_processor.h"

class model
{
public:
	game_data process_game_data(const game_data& data);
};

