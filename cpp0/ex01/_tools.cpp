#include "_tools.hpp"

/*******************************************************************************
 * 		PRINT CAT RANDOM COLOR
 * bit[., ., 1] = stops
 * bit[., 1, .] = cls
 * bit[1, ., .] = return the input user
 * bit[1, ., ., .] = reset
******************************************************************************/
std::string	ft_print_ccat(std::string color1, std::string color2, std::string color3, int num, std::string string, int bit)
{
	if (bit & 0b10)
		std::cout << CLEAR;

	std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << "" << "~ " << num << " ~" + color1 + "\n\
	\t\t⠀|、˜\\\t\t\t" + color2 + "~" + string + "~" + color1 + "\n\
	\t\t⠀じしˍ)ノ\n" << std::endl;

	if (bit & 0b1)
	{
		std::cout << BLINK + color3 + "\n\t\t>>>  PRISS ENTER TO CONTINUE  <<<\n" + R_BLINK << std::endl;
		std::getline(std::cin, color1);
	}

	if (bit & 0b100)
	{
		// std::cout << BLINK + color3 + "\nGIV INPUT: " + R_BLINK;
		std::cout << color3 + ":" + RESET;
		std::cout.flush();
		std::getline(std::cin, color1);
		return (bit & 0b1000) ? color1 + RESET : color1;
	}
	return (bit & 0b1000) ? color3 + RESET : color3;
}

/*******************************************************************************
 * 		PRINT CAT RANDOM COLOR
 * bit[1, .] = cls
 * bit[., 1] = stops
******************************************************************************/
void	ft_print_cat(int num, std::string string2, int bit)
{
	srand(time(NULL));

	std::stringstream ss;
	ss << (rand() % 255 + 1);
	std::string color1 = "\e[38;5;" + ss.str() + "m";
	ss.str("");
	ss << (rand() % 255 + 1);
	std::string color2 = "\e[38;5;" + ss.str() + "m";
	ss.str("");
	ss << (rand() % 255 + 1);
	std::string color3 = "\e[38;5;" + ss.str() + "m";
	
	if ((bit >> 1) & 1)
		std::cout << CLEAR;

	std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << num << " ~" + color1 + "\n\
	\t\t⠀|、˜\\\t\t\t" + color2 + "~" + string2 + "~" + color1 + "\n\
	\t\t⠀じしˍ)ノ\n" << std::endl;

	if ((bit >> 0) & 1)
	{
		std::cout << BLINK + color3 + "\n\t\t>>>  PRISS ENTER TO CONTINUE  <<<\n" + R_BLINK;
		std::getline(std::cin, color1);
	}
}
