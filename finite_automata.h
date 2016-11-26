#pragma once

#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stdint.h>

enum State{
	S,
	S1,
	S11,
	S111,
	S1111,
	S11111,
	S2,
	S22,
	S222,
	S2222,
	S22222,
	S3,
	S33,
	S333,
	S3333,
	S33333,
	SA,
	SAA,
	SAAA,
	SAAAA,
	SAAAAA,
	SB,
	SBB,
	SBBB,
	SBBBB,
	SBBBBB,
	SC,
	SCC,
	SCCC,
	SCCCC,
	SCCCCC,
	E
};

class finite_automata
{
private:
	std::map<std::pair<char, State>, State> state_machine;

	uint32_t states_to_points(State state);
	State get_default_state(char symbol);
public:
	uint32_t calc_ratio_from_line(const std::string& line);
	finite_automata();
};

