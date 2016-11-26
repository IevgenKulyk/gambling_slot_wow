#include "finite_automata.h"

finite_automata::finite_automata()
{
	std::map<std::pair<char, State>, State> sm = {
		{ { '1', S }, S1 },
		{ { '1', S1 }, S11 },
		{ { '1', S11 }, S111 },
		{ { '1', S111 }, S1111 },
		{ { '1', S1111 }, S11111 },
		{ { '2', S }, S2 },
		{ { '2', S2 }, S22 },
		{ { '2', S22 }, S222 },
		{ { '2', S222 }, S2222 },
		{ { '2', S2222 }, S22222 },
		{ { '3', S }, S3 },
		{ { '3', S3 }, S33 },
		{ { '3', S33 }, S333 },
		{ { '3', S333 }, S3333 },
		{ { '3', S3333 }, S33333 },
		{ { 'A', S }, SA },
		{ { 'A', SA }, SAA },
		{ { 'A', SAA }, SAAA },
		{ { 'A', SAAA }, SAAAA },
		{ { 'A', SAAAA }, SAAAAA },
		{ { 'B', S }, SB },
		{ { 'B', SB }, SBB },
		{ { 'B', SBB }, SBBB },
		{ { 'B', SBBB }, SBBBB },
		{ { 'B', SBBBB }, SBBBBB },
		{ { 'C', S }, SC },
		{ { 'C', SC }, SCC },
		{ { 'C', SCC }, SCCC },
		{ { 'C', SCCC }, SCCCC },
		{ { 'C', SCCCC }, SCCCCC }
	};

	state_machine = sm;
}

uint32_t finite_automata::states_to_points(State state) 
{
	switch (state)
	{
	case S:
		return 0;
	case S1:
		return 0;
	case S11:
		return 0;
	case S111:
		return 2;
	case S1111:
		return 4;
	case S11111:
		return 10;
	case S2:
		return 0;
	case S22:
		return 0;
	case S222:
		return 3;
	case S2222:
		return 5;
	case S22222:
		return 15;
	case S3:
		return 0;
	case S33:
		return 0;
	case S333:
		return 4;
	case S3333:
		return 6;
	case S33333:
		return 20;
	case SA:
		return 0;
	case SAA:
		return 4;
	case SAAA:
		return 8;
	case SAAAA:
		return 15;
	case SAAAAA:
		return 25;
	case SB:
		return 0;
	case SBB:
		return 5;
	case SBBB:
		return 9;
	case SBBBB:
		return 20;
	case SBBBBB:
		return 30;
	case SC:
		return 0;
	case SCC:
		return 6;
	case SCCC:
		return 10;
	case SCCCC:
		return 25;
	case SCCCCC:
		return 50;
	case E:
		return 0;
	default:
		return 0;
		break;
	}
}

State finite_automata::get_default_state(char symbol)
{
	State default_state = S;

	switch (symbol)
	{
	case '1':
		default_state = E;
		break;
	case '2':
		default_state = E;
		break;
	case '3':
		default_state = E;
		break;
	case 'A':
		default_state = E;
		break;
	case 'B':
		default_state = E;
		break;
	case 'C':
		default_state = E;
		break;
	}

	return default_state;
}

uint32_t finite_automata::calc_ratio_from_line(const std::string& line)
{
	std::vector<uint32_t> states;
	State current_state = S;

	for (char symbol : line)
	{
		try
		{
			current_state = state_machine.at(std::make_pair(symbol, current_state));
		}
		catch (std::out_of_range)
		{
			current_state = get_default_state(symbol);
		}
		states.push_back(current_state);
	}

	for (uint32_t& state : states)
	{
		state = states_to_points(static_cast<State> (state));
	}

	return *std::max_element(states.begin(), states.end());
}