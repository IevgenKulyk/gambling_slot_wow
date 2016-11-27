#include "view.h"
#include "model.h"
#include "controller.h"

int main(int argc, char* argv[])
{
	//Tests for matrix_process
	//************************
	std::cout << "matrix_process tests block started execution" << std::endl;
	//Test 1
	std::cout << "Test 1 started..." << std::endl;
	Matrix test1 = {
		"1AY3C",
		"A122Y",
		"CZ11B"
	};
	matrix_processor processor(test1);
	if (processor.extract_line_by_number(3) != "1112C")
	{
		std::cout << "Test 1 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 1 passed" << std::endl;
	//************************
	//Test 2 
	std::cout << "Test 2 started..." << std::endl;
	std::string test2 = "1112C";
	if (processor.calculate_ratio_from_line(test2) != 2)
	{
		std::cout << "Test 2 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 2 passed" << std::endl;
	//************************
	//Test 3
	std::cout << "Test 3 started..." << std::endl;
	std::string a = "ZZZZZ";
	processor.parse_line_for_joker(a);
	if (a != "CCCCC")
	{
		std::cout << "Test 3 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 3 passed" << std::endl;
	//************************
	//Test 4
	std::cout << "Test 4 started..." << std::endl;
	auto bonus4 = processor.get_bonus_number();
	if (bonus4 != 2)
	{
		std::cout << "Test 4 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 4 passed" << std::endl;
	//************************
	//Test 5
	std::cout << "Test 5 started..." << std::endl;
	auto win5 = processor.find_win_points(10, 7);
	if (win5 != 400)
	{
		std::cout << "Test 5 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 5 passed" << std::endl;
	//************************
	std::cout << "matrix_process tests block finished execution" << std::endl;
	//************************
	//************************
	std::cout << "joker tests block started execution" << std::endl;
	//Test 1
	std::cout << "Test 1 started..." << std::endl;
	finite_automata automata;
	joker j(automata);
	auto test1joker = j.parse_line_for_joker(std::string("1Z111"));
	if (test1joker != 2)
	{
		std::cout << "Test 1 failed" << std::endl;
		return 1;
	}
	std::cout << "Test 1 passed" << std::endl;
	//************************
	std::cout << "joker tests block ended execution" << std::endl;
	//************************
	//************************

	//test Travis CI build
	//
	return 0;
}
