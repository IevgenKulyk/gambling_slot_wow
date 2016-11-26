#include "controller.h"

int main(int argc,char** argv)
{
	try
	{
		controller engine;
		engine.execute();
	}
	catch (std::logic_error error)
	{
		std::cout << error.what() << std::endl;
	}

	return 0;
}

