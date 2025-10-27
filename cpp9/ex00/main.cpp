
#include "_colors.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

typedef std::map<std::string, float> t_db;
///////////////////////////////////////////////////////////////////////////////]
void	p(int a) { std::cout << C_511 "pb at sector: " RESET << a << std::endl; }
bool	isDataBaseValid( t_db& database );
bool	isDBlineValid(std::string& line, std::map<std::string, float>& database);
bool	isDateValid(std::string& date);
///////////////////////////////////////////////////////////////////////////////]
// open DB
bool	isDataBaseValid( t_db& database ) {

	std::ifstream db("data.csv");
	if (!db) {
		std::cout << ERR2 "can't locate database" RESET << std::endl;
		return p(0), false;
	}

	std::string line;
	getline(db, line);
	while (getline(db, line)) {
		if (!isDBlineValid(line, database))
			return p(1), false;
	}
	return true;
}

// 2009-01-02,0
bool	isDBlineValid(std::string& line, std::map<std::string, float>& database) {

	if (line.length() < 12 || line[10] != ',')
		return p(2), false;
	
	std::string	date = line.substr(0, 10);
	std::string bitcoin = line.substr(11);

	char *end = NULL;
	float bit_value = std::strtod(bitcoin.c_str(), &end);
	if (*end)
		return p(3), false;

	database[date] = bit_value;
	return isDateValid(date);
}

// "2009-01-02"
bool	isDateValid(std::string& date) {

	if (date.size() != 10)
		return p(4), false;// too small to be valid
	if (date[4] != '-' || date[7] != '-')
		return p(5), false; // incorrect sep
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return p(6), false; // something not number
	}

	std::stringstream d(date);
	int year, month, day;

	d >> year;
	d.ignore(1, '-');
	d >> month;
	d.ignore(1, '-');
	d >> day;

	if (!month || month > 12 || !day || day > 31)
		return p(7), false; //day month integrity

	int	t[] = {2,4,6,9,11}; // months with less 31 days
	// std::vector<int> trentaUno(t, t + sizeof(t)/sizeof(int));

	// if (day > 30 && std::find(trentaUno.begin(), trentaUno.end(), month) != trentaUno.end())
	// 	return p(8), false;
	if (day > 30 && std::find(t, t + sizeof(t) / sizeof(int), month) != t + sizeof(t) / sizeof(int))
		return p(8), false;
	
	if (month == 2) { // feburary
		if (day > 29)
			return p(9), false;
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day == 29 && !isLeap)
			return p(10), false;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////]

///////////////////////////////////////////////////////////////////////////////]
// "date | value"
bool	printOutput(t_db db, std::string& line) {

	if (line == "date | value")
		return true;
	if (line.length() < 14 || line.substr(10, 3) != " | ")
		return false;

	std::string date = line.substr(0, 10);
	std::string bitvalue = line.substr(13);

	char*	end = NULL;
	double	value = std::strtod(bitvalue.c_str(), &end);
	if (*end)
		return false;
	if (!isDateValid(date)) {
		std::cout << ERR4 "Input date not in format: " 
		C_411 "YYYY" RESET "/" C_411 "MM" RESET "/" C_411 "DD " RESET 
		<< date << std::endl;
		return true;
	}
	if (value < 0) {
		std::cout << ERR3 "Input value negative: " C_411 << value << RESET << std::endl;
		return true;
	}
	if (value > 1000) {
		std::cout << ERR3 "Input value too large: " C_411 << value << RESET << std::endl;
		return true;
	}

	t_db::iterator it = db.lower_bound(date);
	if (it == db.begin()) {
		std::cout << C_415 << date << RESET << ": " RED "BEFORE DATABASE RECORDS" RESET << std::endl;
		return true;
	}
	else if (it == db.end() || it->first != date)
		--it;

	if (it->first != date)
		std::cout << C_411 << date << " (" RESET << it->first << C_411 ")" RESET;
	else	
		std::cout << C_141 << date;
	
	std::cout << RESET " => " C_145 << value << RESET " * " C_041 
		<< it->second << RESET " = " C_530 << it->second * value << RESET << std::endl;
	return true;
}


///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av)
{
	if (ac != 2) {
		std::cout << ERR0 "need one file as input" RESET << std::endl;
		return 0;
	}

	t_db database;
	if (!isDataBaseValid(database)) {
		std::cout << ERR1 "Corrupted DataBase" RESET << std::endl;
		return 0;
	}

// input.txt file
	std::ifstream file(av[1]);
	if (!file) {
		std::cout << ERR1 "bad infile: " RESET << av[1] << std::endl;
		return 1;
	}

	std::string newline;
	while (std::getline(file, newline)) {
		if (!printOutput(database, newline))
			std::cout << ERR8 "Bad Input => '" << newline << "'" << std::endl;
	}

	return 0;
}