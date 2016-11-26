#include "joker.h"

char joker::increment_symbol_for_joker_bruteforce(char current_symbol)
{
	switch (current_symbol)
	{
	case '1':
		return '2';
	case '2':
		return '3';
	case '3':
		return 'A';
	case 'A':
		return 'B';
	case 'B':
		return 'C';
	default:
		return '1';
	}
}

uint32_t joker::parse_line_for_joker(std::string& line)
{
	uint32_t joker_ratio = 1;

	std::vector<uint32_t> positions;
	for (uint32_t i = 0; i < line.length(); i++)
	{
		if (line[i] == 'Z')
		{
			line[i] = increment_symbol_for_joker_bruteforce(line[i]);
			positions.push_back(i);
		}
	}

	uint32_t variants = static_cast<uint32_t> (pow(6, positions.size()));
	std::string best_variant = line;
	uint32_t best_summ = state_machine.calc_ratio_from_line(line);

	for (uint32_t i = 1; i < variants; i++)
	{
		uint32_t current = i;
		uint32_t pos = 0;
		while (current >= 6)
		{
			if (current % 6 == 0)
			{
				pos++;
				current /= 6;
				line[positions[pos]] = increment_symbol_for_joker_bruteforce(line[positions[pos]]);
			}
			else
				break;
		}

		uint32_t current_summ = state_machine.calc_ratio_from_line(line);
		if (best_summ < current_summ)
		{
			best_summ = current_summ;
			best_variant = line;
		}

		line[positions[0]] = increment_symbol_for_joker_bruteforce(line[positions[0]]);
	}

	uint32_t current_summ = state_machine.calc_ratio_from_line(line);
	if (best_summ < current_summ)
	{
		best_summ = current_summ;
		best_variant = line;
	}

	line = best_variant;

	if (positions.size() > 0)
		joker_ratio = positions.size() * 2;

	return joker_ratio;
}

joker::joker(finite_automata& sm) :state_machine(sm){ }