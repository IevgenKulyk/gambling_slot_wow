#include "controller.h"

void controller::execute()
{
	game_data data = { 2000, 0, 0, 0, 0 };
	std::locale loc;	
	View.draw_intro();

	while (true)
	{
		std::string value;
		std::cin >> value;
		for (char& symbol : value)
			symbol = std::tolower(symbol, loc);

		if (value.length() > 0 && isdigit(value[0]))
		{
			char* endptr = nullptr;
			data.bet_per_line = strtoul(value.c_str(), &endptr, 10);
			uint32_t lines;
			std::cin >> lines;
			data.lines = static_cast<uint8_t> (lines);	
			if (data.lines > 9)
				throw std::logic_error("too many lines, only 9 max allowded");
		}
		else if (value != "start" && value.length() > 0)
			throw std::logic_error("bad control command");

		data = Model.process_game_data(data);
		View.update_data(data);
		View.draw_data();
	}
}