#pragma once

#include <stdint.h>
#include <iostream>
#include <math.h>

typedef struct _game_data
{
	int32_t credits;
	uint32_t bet_per_line;
	uint8_t lines;
	uint32_t total_win;
	uint32_t total_bet;
	uint32_t games;
}game_data,*pgame_data;

class view
{
private:
	game_data data;
	float round(float value);
	float make_win_bet();
public:
	void draw_intro();
	void draw_data();
	void update_data(const game_data& new_data);
};

