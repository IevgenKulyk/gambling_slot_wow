#include "view.h"

void view::draw_intro()
{
	std::cout << "Wellcome to the best casino ever!" << std::endl;
	std::cout << "To start the game input \"start\" or empty string and press enter. Example: start" << std::endl;
	std::cout << "To change \"Bet per line\" and \"Lines\" input two numbers respectively and press enter. Example: 1 7" << std::endl;
}

float view::round(float value)
{
	float tmp = value * 100;
	return ::round(tmp) / 100;
}

float view::make_win_bet()
{
	if (data.total_bet)
		return this->round(data.total_win / static_cast<float> (data.total_bet));
	return 0;
}

void view::draw_data()
{
	std::cout << "Credits: " << data.credits;
	std::cout << " Bet per line: " << data.bet_per_line;
	std::cout << " Lines: " << static_cast<uint32_t> (data.lines);
	std::cout << " Bet: " << data.lines * data.bet_per_line << std::endl;
	std::cout << "Total win: " << data.total_win;
	std::cout << " Total bet: " << data.total_bet;
	std::cout << " Games: " << data.games;
	std::cout << " win/bet: " << make_win_bet() << " %" << std::endl;
}

void view::update_data(const game_data& new_data)
{
	data = new_data;
}