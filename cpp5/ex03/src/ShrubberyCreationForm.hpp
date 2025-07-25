#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

#include "AForm.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define SCF_SIGN 145
#define SCF_EXEC 137
///////////////////////////////////////////////////////////////////////////////]
class ShrubberyCreationForm : public AForm {

private:
	std::string _target;
	
	void 	doExecution() const;

protected:

public:

/////   CANONICAL
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

/////

};
typedef ShrubberyCreationForm SCF;

///////////////////////////////////////////////////////////////////////////////]
#define TREE GREEN "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⠀⠀⢀⢆⢇⢕⢠⢄⠀⢄⢄⢈⢎⠦⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡢⡂⡄⡐⡀⡌⢆⢊⠔⢔⢜⡔⡆⣆⢠⢨⢢⢣⢪⠸⢸⡘" C_231 "⡄⡮⡪⡮⢚⡘⡌⢇⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡐⠕⢎⢆⡕⢅⠇⡕⠔⠕⣅⠕⡍⡺⡐⢑⢆⡧⡹⣜" C_231 "⡎⣧⠳⡝⡎⣕⣇⣗⠥⡃⠗⡡⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⢄⠡⠓⢌⢆⢇⢕⢙⠮⣎⢗⡉⡪⢔⢥⠥⡪⡊" C_231 "⢀⢂⢥⢙⢘⣈⢡⢩⢘⣈⢪⠰⡑⢣⠰⡸⡰⢒⡢⡱⡑⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⢕⢍⢕⢕⢵⢕⠝⣜⢜⢔⢕⢒⢵⢸⡸⡕" C_231 "⣇⢫⢡⠩⡐⣜⢆⡇⡧⡣⡳⣵⢧⣳⣣⢍⣞⢎⡚⠌⢎⣎⡬⡍⡌⢠⢠⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⡢⡪⡐⢅⢪⠺⡪⣳⡱⡱⡢⢣⢥⠡⡡⢈⠘⢌⠜⢱⠠" C_231 "⡑⡪⡯⡾⣵⣳⢽⡽⣝⢷⣹⡪⡮⡫⣺⢫⡼⣕⡕⡄⡦⡢⡊⢊⠨⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⢠⠀⡄⠠⠰⡱⡪⢮⢇⢗⢭⠪⠳⡱⡃⡣⡓⣑⢅⣪⡢⣇" C_231 "⢖⣜⢼⣰⡢⣅⢝⣽⢵⢯⣯⣻⢾⢽⡺⡮⣺⣺⣓⡵⢽⣺⢮⣓⠽⡜⡕⡥⡫⠘⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢎⠮⡳⣕⢲⢀⠄⡈⣈⢢⡢⡭⡐⣬⣒⣎⣖⣖⡭⣞" C_231 "⠽⣺⡹⣮⢻⢮⣗⢗⡽⡮⡭⡜⡕⣯⢺⣪⡗⣿⢼⡫⢞⡼⡺⣺⣝⡽⣝⣞⢯⡺⣸⢔⡥⡀⡀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢌⢕⡯⣪⡳⢱⢵⢱⠰⣣⢳⣝⣝⡺⣚⣖⣗⡵⡫⡕⣯⢷" C_231 "⣻⣺⢽⡱⡵⡳⢭⢻⣜⢷⣑⡳⠵⢮⣿⡳⣵⢭⣵⣫⢝⣡⢑⠯⡮⡪⡣⡣⡱⡉⠍⢶⣪⢧⡢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠩⡊⡍⣓⢉⡅⡢⣕⢎⣞⢵⡱⣵⢽⢵⣣⢗" C_231 "⣽⣫⢯⢯⢯⣗⡷⣝⡷⡵⣳⢧⣫⢾⣝⡮⡶⣽⡲⠵⣽⡻⡽⣪⡺⣓⢯⢥⢝⣜⢇⣽⣹⢮⢮⢪⠰⢤⡱⡨⡬⣨⢱⡑⡕⣒⣔⠔⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣐⢴⣱⣹⣳⣳⡳⡕⣯⢞⣦⢧⡧⣿⣪⡯⣟⠮⣻⣳⢵" C_231 "⢯⣺⢵⢖⣹⡺⣝⢭⢮⣫⢯⣻⢼⣗⣿⣞⡾⣝⢥⡰⡴⢮⣞⣞⣟⣟⡿⣞⣷⣳⡽⣹⡱⢱⢘⣄⣆⢪⢈⡊⡓⡙⡊⢚⡎⣆⢂⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣅⣓⠫⡚⣞⢵⣕⡯⡵⡦⡯⣯⠣⡫⣎⠞" C_231 "⣜⢵⣳⢽⣝⢾⣝⡽⡮⡯⣯⠯⡯⣞⣽⣽⣳⣳⡳⣯⣻⣺⡵⣵⢟⣗⣟⣞⣗⣽⢻⢯⢗⣗⣯⡳⡼⣸⣞⢞⢜⣝⣪⣺⣜⡮⡮⡾⣝⡞⠐⠁⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡘⢊⢱⢝⡞⡵⣵⣟⢯⢟⠽⠺⣩⢮⡪⣮⢾⣯⢺⢁" C_231 "⠨⢂⠢⡋⠳⡍⣷⡪⠪⡞⠼⣺⢾⣺⣽⣞⡗⣟⡽⡯⡷⡹⣕⠷⡽⢾⢙⡳⡯⣶⡲⡇⡯⣂⣨⠱⣳⢪⢗⢟⣞⢝⢕⡯⢗⢝⠡⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⢕⡹⣝⢷⡻⣚⣳⢭⣂⢧⣺⢦⢍⢺⡺⣞⡧⣿⢼⡧" C_231 "⢍⠨⢨⢈⡳⠽⣵⣻⣞⣗⡯⡯⣳⢱⡙⡗⡝⡕⡟⡷⣻⡻⣵⣕⣵⣣⣎⡯⡪⡗⡽⡮⣗⢶⢏⡯⣾⢕⠧⡝⠜⠮⡣⢯⠊⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⣏⡮⣞⣞⠾⢾⢹⢾⢝⣯⡫⣮⢞⡮⢷⢽⡳⡯⣟⣽⣽⡢" C_231 "⣨⡰⡀⣌⢮⣱⢝⢮⢧⣫⢽⢽⡽⣼⣪⢻⠝⣵⢝⣆⡢⣳⠱⠓⡿⡮⣫⣫⢥⣳⡹⡮⡮⡇⣇⠳⠕⡤⣀⢠⢀⠀⠈⠈⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢐⠭⢏⢮⢯⣳⠹⣺⢺⢮⡿⡽⣝⣯⣟⡽⢾⣻⡯⡿⣞⣯⢾⢽⢽⣫⡿" C_231 "⣺⡽⣯⡟⣞⢿⣽⡟⣧⢯⡿⣳⣗⣟⣮⡳⣯⣯⡯⣯⢽⣫⡞⡕⡆⡏⡽⠫⢷⣗⣧⣫⣊⠣⡃⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢈⢌⣈⢤⢦⣶⣲⢾⡽⣯⢾⣻⣟⢞⣗⣟⡽⣺⢭⣻⣜⣞⢽⢝⡾⣜⡮⣷⣻" C_231 "⣗⡿⣯⣻⢷⣻⢽⣻⣽⣻⣺⢕⡷⣝⡾⣖⣯⣛⢭⢯⣮⣫⢯⣯⣪⢇⡝⠮⢷⢷⢬⡀⡠⡀⣀⢀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⡐⣹⢸⢮⢗⣷⣻⡽⡾⡽⡽⣽⢽⣻⣗⣯⢯⣗⡗⣟⡮⣗⢿⣪⣾⣹⢧⣟⢾⡺⣽⢾⣺⣽⣺" C_231 "⠏⠋⡚⣗⢗⢿⡺⡏⢊⠒⣿⣻⣞⣞⢯⣟⣷⡻⡯⣻⣺⡻⡾⣝⡷⡽⣶⣳⢝⡜⡜⠖⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⢈⡊⡤⣜⢮⣞⣮⣻⢽⡯⡿⣾⣑⢗⡙⡎⢻⡮⣿⣪⠭⠷⣝⣞⢯⣳⡔⡈⣵⡒⣯⣷⡿⣾⢮⣓⣉⢧" C_231 "⢷⣹⡺⡮⣇⢦⣿⢷⠾⡝⡳⣳⢮⣫⢯⡷⣫⡿⣮⢮⣻⢽⣝⡎⡳⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠡⡻⢞⡽⡯⣯⠞⣷⣻⣍⣯⢺⣺⢽⣽⢽⣻⠵⣻⢺⢽⣻⢪⣟⣮⢽⣺⣦⢷⢽⣻⣿⣻⡯⣶⣸⢳⡿⣵" C_231 "⡻⣎⢟⣧⣿⣿⠽⡲⣖⣞⡶⣟⢎⡯⣟⢵⡽⣻⣽⢯⣷⢽⡪⠋⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢢⡘⡮⡷⣿⠯⢏⢣⡫⢟⢺⢽⡪⣅⠥⠭⢒⣑⢄⢫⡻⠮⢿⣟⣯⣿⢽⣽⢾⡿⣾⢽⣗⣯⡷⣟⢗⡯⣯⢿⡾⡳⠝⣧⢂" C_231 "⢑⠳⢯⡯⣯⢟⣞⢵⣡⣄⣑⠫⠪⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡣⣕⡽⣟⣯⣟⢿⣽⡻⣝⣼⢜⣟⣝⣞⣗⡽⡄⣦⣱⣲⢼⣫⡻⢜⡺⠑⠻⢽⣻⣽⡯⡟⢱⢯⣗⣯⢷⡵⢫⡬⠏⣯⢻⡼⢯⢟⣯⢞⣣⡕⣓" C_231 "⠉⠻⢹⡻⣺⣳⢧⢳⢤⡰⣂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⢀⢬⣫⣺⠽⠯⠗⠉⢣⣽⣚⣾⢯⣧⢥⢔⣼⢮⣋⠶⣠⣱⣝⢏⡫⡻⡽⠖⠶⠲⠮⡯⣷⣻⣷⣟⣽⡾⣞⡟⠞⠋⠋⠛⠙⠓⠒⠙⠙⠚⣝⠑⢿⢽⡻⣴" C_231 "⡄⡉⠑⠈⠈⠫⠳⡝⠆⠣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠊⠀⠀⠀⣸⡺⡽⡷⡻⢻⣌⢖⢧⢣⡑⠏⠈⠚⢚⠜⠂⠈⠁⠁⠀⠀⠀⠀⠈⢷" C_210 "⣳⢷⣽⡚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" C_221 "⠀⠁⠃⠀⠀⠀⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_040 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢒⢜⠾⡏⠛⠁⠐⠏⠖⠙⠈⠚⠀⠀" C_320 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣝" C_210 "⣗⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_320 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⢮⢮" C_210 "⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_320 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⣏⣗" C_210 "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_320 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⣞⢮" C_210 "⢯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_320 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⣞⡾⣕" C_210 "⢟⡶⡤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" C_210 "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⢀⢀⠄⡠⠠⡠⠢⡒⠖⢝⠝⡪⡓⢏⠗⡏⢯⠫⢗⢏⠯⡫⡖⡲⡰⠤⠤⡄⡄⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" RESET "\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
#endif
