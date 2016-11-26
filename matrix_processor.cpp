#include "matrix_processor.h"


matrix_processor::matrix_processor(Matrix m) :matrix(m)
{
	joker_worker = std::unique_ptr<joker>(new joker(state_machine));
}

std::string matrix_processor::extract_line_by_number(const uint32_t number)
{
	std::string result = "";

	auto line = default_line_map[number];
	for (auto element : line)
	{
		result += matrix[element.first][element.second];
	}

	return result;
}

uint32_t matrix_processor::parse_line_for_joker(std::string& line)
{
	return joker_worker.get()->parse_line_for_joker(line);
}

uint32_t matrix_processor::get_bonus_number()
{
	uint32_t bonuses = 0;

	for (auto line : matrix)
	{
		for (auto element : line)
		{
			if (element == 'Y')
				bonuses++;
		}
	}

	return bonuses;
}

uint32_t matrix_processor::calculate_ratio_from_line(const std::string& line)
{
	return state_machine.calc_ratio_from_line(line);
}

uint32_t matrix_processor::find_win_points(const uint32_t bet, const uint8_t number_of_lines)
{
	uint32_t result = 0;

	uint32_t whole_ratio = 1;
	for (uint8_t i = 0; i < number_of_lines; i++)
	{
		std::string line = extract_line_by_number(i);
		uint32_t local_ratio = parse_line_for_joker(line);
		uint32_t line_ratio = calculate_ratio_from_line(line);
		local_ratio *= line_ratio;
		result += local_ratio * bet;
	}

	uint32_t bonuses = get_bonus_number();
	if (bonuses > 1)
		whole_ratio = bonuses;

	result += whole_ratio * bet * number_of_lines;

	return result;
}
