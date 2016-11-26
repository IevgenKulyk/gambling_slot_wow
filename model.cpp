#include "model.h"

game_data model::process_game_data(const game_data& data)
{
	if (static_cast<int32_t> (data.bet_per_line * data.lines) > data.credits)
		return data;

	game_data result;
	matrix_generator generator;
	auto matrix = generator.generate_game_matrix();
	matrix_processor processor(matrix);
	auto game_points = processor.find_win_points(data.bet_per_line, data.lines);

	result.bet_per_line = data.bet_per_line;
	result.credits = data.credits - (data.bet_per_line * data.lines) + game_points;
	result.games = data.games + 1;
	result.lines = data.lines;
	result.total_bet = data.total_bet + data.bet_per_line * data.lines;
	result.total_win = data.total_win + game_points;

	return result;
}
