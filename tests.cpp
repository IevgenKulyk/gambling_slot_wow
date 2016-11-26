#include "view.h"
#include "model.h"
#include "controller.h"

int main(int argc, char* argv[])
{
	//tests implementations
	Matrix test1 = {
		"1AY3C",
		"A122Y",
		"CZ11B"
	};
	matrix_processor processor(test1);
	//_ASSERT(processor.extract_line_by_number(3) == "1112C");
	std::cout << processor.extract_line_by_number(3) << std::endl;
	std::cout << processor.extract_line_by_number(5) << std::endl;
	std::cout << processor.extract_line_by_number(6) << std::endl;

	std::string test3 = "1112C";
	finite_automata state_machine;
	std::cout << state_machine.calc_ratio_from_line(test3) << std::endl;
	std::cout << state_machine.calc_ratio_from_line(std::string("123AB")) << std::endl;

	std::string a = "ZZZZZ";
	std::cout << processor.parse_line_for_joker(a) << std::endl;
	std::cout << a << std::endl;

	std::cout << processor.calculate_ratio_from_line(std::string("C12AA")) << std::endl;
	std::cout << processor.calculate_ratio_from_line(std::string("112AA")) << std::endl;
	std::cout << processor.calculate_ratio_from_line(std::string("111AA")) << std::endl;
	std::cout << processor.calculate_ratio_from_line(std::string("CCCAA")) << std::endl;

	std::cout << processor.find_win_points(10, 7) << std::endl;

	std::string aa = "C111B";
	std::string bb = "CC11B";
	std::cout << processor.calculate_ratio_from_line(aa) << std::endl;
	std::cout << processor.calculate_ratio_from_line(bb) << std::endl;

	view v;
	game_data d;
	d.credits = 2000;
	d.bet_per_line = 10;
	d.games = 0;
	d.lines = 6;
	d.total_bet = 0;
	d.total_win = 0;
	v.draw_intro();
	v.update_data(d);
	v.draw_data();

	matrix_generator gen;
	Matrix mm = gen.generate_game_matrix();
	matrix_processor proc_handler(mm);
	std::cout << proc_handler.find_win_points(30, 9) << std::endl;

	return 0;
}
