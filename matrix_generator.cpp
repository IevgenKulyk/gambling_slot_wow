#include "matrix_generator.h"

std::string matrix_generator::generate_game_line()
{
	const std::string alphabet = "123ABCYZ";
	std::string result = "";	

	for (int i = 0; i < 5; i++)
	{
		result += alphabet[rand() % alphabet.length()];
	}

	return result;
}

Matrix matrix_generator::generate_game_matrix()
{
	Matrix result;
	srand(static_cast<unsigned int> (time(NULL)));

	for (int i = 0; i < 3; i++)
		result.push_back(generate_game_line());

	return result;
}