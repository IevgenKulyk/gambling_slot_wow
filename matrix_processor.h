#pragma once

#include <vector>
#include <string>
#include <stdint.h>
#include <memory>

#include "finite_automata.h"
#include "joker.h"

typedef std::vector<std::string> Matrix;
typedef std::vector<std::vector<std::pair<uint8_t, uint8_t>>> LineMap;

const LineMap default_line_map = {
	{ { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 } },
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } },
	{ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 } },
	{ { 0, 0 }, { 1, 1 }, { 2, 2 }, { 1, 3 }, { 0, 4 } },
	{ { 2, 0 }, { 1, 1 }, { 0, 2 }, { 1, 3 }, { 2, 4 } },
	{ { 1, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 1, 4 } },
	{ { 1, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 2 }, { 2, 3 }, { 2, 4 } },
	{ { 2, 0 }, { 2, 1 }, { 1, 2 }, { 0, 3 }, { 0, 4 } }
};

class matrix_processor
{
private:
	Matrix matrix;
	finite_automata state_machine;
	std::unique_ptr<joker> joker_worker;

public:
	matrix_processor(Matrix m);
	std::string extract_line_by_number(const uint32_t number);
	uint32_t parse_line_for_joker(std::string& line);
	uint32_t get_bonus_number();
	uint32_t calculate_ratio_from_line(const std::string& line);
	uint32_t find_win_points(const uint32_t bet, const uint8_t number_of_lines);
};

