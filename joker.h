#pragma once

#include <string>
#include <vector>
#include <stdint.h>

#include "finite_automata.h"

class joker
{
private:
	finite_automata& state_machine;
	char increment_symbol_for_joker_bruteforce(char current_symbol);	
public:
	uint32_t parse_line_for_joker(std::string& line);
	joker(finite_automata& sm);
};

