#include <iostream>

#include "Point.hpp"
#include "Fixed.hpp"

#include <SFML/Graphics.hpp>

#include <sstream>
#include <iomanip>
#include <math.h>

#define SZ_PX_X 1200
#define SZ_PX_Y 900
#define FOV 100.0f
#define PX (FOV / SZ_PX_X)

typedef struct s_data {

	Point	*A, *B, *C, *P;

	int how_many_points;

	s_data() : A(NULL), B(NULL), C(NULL), P(NULL), how_many_points(0) {}
	~s_data() {
		delete A; 
		delete B; 
		delete C; 
		delete P;
	}

}	t_data;

///////////////////////////////////////////////////////////////////////////////]
bool bsp( Point const a, Point const b, Point const c, Point const point);
///////////////////////////////////////////////////////////////////////////////]
void draw_point(sf::RenderWindow& window, Point& p, const sf::Color& color) {
	sf::CircleShape point(3);
	int x = static_cast<int>(roundf(SZ_PX_X / 2.0f + p.getX() / PX));
	int y = static_cast<int>(roundf(SZ_PX_Y / 2.0f - p.getY() / PX));
	point.setFillColor(color);
	point.setPosition(x - 3, y - 3);
	window.draw(point);
}

void draw_line(sf::RenderWindow& window, const Point& a, const Point& b, const sf::Color& color) {
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(SZ_PX_X / 2.0f + a.getX() / PX, SZ_PX_Y / 2.0f - a.getY() / PX), color),
		sf::Vertex(sf::Vector2f(SZ_PX_X / 2.0f + b.getX() / PX, SZ_PX_Y / 2.0f - b.getY() / PX), color)
	};
	window.draw(line, 2, sf::Lines);
}

void	draw_background(sf::RenderWindow& win) {

	// Horizontal axis (x-axis)
	draw_line(win, Point(-FOV, 0.0f), Point(FOV, 0.0f), sf::Color(100, 100, 100));
	// Vertical axis (y-axis)
	draw_line(win, Point(0.0f, -SZ_PX_Y * PX), Point(0.0f, SZ_PX_Y * PX), sf::Color(100, 100, 100));

	// Origin & maxs circles
	sf::CircleShape origin(4);
	origin.setFillColor(sf::Color::White);
	origin.setPosition(win.getSize().x / 2 - 4, win.getSize().y / 2 - 4);
	win.draw(origin);
	sf::CircleShape maxx(4);
	maxx.setFillColor(sf::Color(250, 250, 250));
	maxx.setPosition(win.getSize().x - 4, win.getSize().y / 2 - 4);
	win.draw(maxx);
	sf::CircleShape maxy(4);
	maxy.setFillColor(sf::Color(250, 250, 250));
	maxy.setPosition(win.getSize().x / 2 - 4, -4);
	win.draw(maxy);

	// Fonts
	sf::Font font;
	if (font.loadFromFile("ARIAL.TTF")) {
		sf::Text txt_o("0", font, 14);
		txt_o.setFillColor(sf::Color::White);
		txt_o.setPosition(win.getSize().x / 2 + 5, win.getSize().y / 2 + 5);
		win.draw(txt_o);

		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2) << FOV;
		sf::Text txt_maxx(oss.str(), font, 14);
		txt_maxx.setFillColor(sf::Color::White);
		txt_maxx.setPosition(win.getSize().x - 40, win.getSize().y / 2 + 5);
		win.draw(txt_maxx);

		oss.str("");
		oss << std::fixed << std::setprecision(2) <<  SZ_PX_Y * PX;
		sf::Text txt_maxy(oss.str(), font, 14);
		txt_maxy.setFillColor(sf::Color::White);
		txt_maxy.setPosition(win.getSize().x / 2 - 30, 5);
		win.draw(txt_maxy);
	}
}

void	draw_screen(sf::RenderWindow& win, t_data& data) {

	draw_background(win);

	switch(data.how_many_points) {
		case 3:
			draw_point(win, *data.C, sf::Color::Blue);
			draw_line(win, *data.A, *data.C, sf::Color::Blue);
			draw_line(win, *data.B, *data.C, sf::Color::Blue);
		// fall through
		case 2:
			draw_point(win, *data.B, sf::Color::Blue);
			draw_line(win, *data.A, *data.B, sf::Color::Blue);
		// fall through
		case 1:
			draw_point(win, *data.A, sf::Color::Blue);
			break;
		default:
			;
	}
	if (data.P) {
		sf::Color rgb = sf::Color::White;
		if (data.how_many_points == 3)
			rgb = bsp(*data.A, *data.B, *data.C, *data.P) ? sf::Color::Green : sf::Color::Red;
		draw_point(win, *data.P, rgb);
	}
}

///////////////////////////////////////////////////////////////////////////////]
Point*	rtrn_point(sf::Event& event) {

	float x = (event.mouseButton.x - SZ_PX_X / 2.0f) * PX;
	float y = (SZ_PX_Y / 2.0f - event.mouseButton.y) * PX;

	std::cout << C_411 << "new point [" << event.mouseButton.x << "px, " << event.mouseButton.y 
	<< "px]:"  << RESET << " (" << x << ", " << y << ")" << std::endl;
	Point* P = new Point(x, y);
	return P;
}

void	assign_new_point(t_data& data, Point* p) {

	switch(data.how_many_points) {
		case 1:
			data.B = p;
			break;
		case 2:
			data.C = p;
			break;
		case 3:
			delete data.A;
			data.A = p;
			delete data.B;
			data.B = NULL;
			delete data.C;
			data.C = NULL;
			data.how_many_points = 0;
			break;
		default:
			data.A = p;
	}
	data.how_many_points++;
}

void	handle_event(sf::RenderWindow& win, t_data& data) {

	sf::Event event;

	while (win.pollEvent(event)) {
		if (event.type == sf::Event::Closed)  // Exit on cross
			win.close();
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape)  // Exit on Esc
				win.close();
			if (event.key.code == sf::Keyboard::BackSpace) { // Clear all points
				delete data.A;
				delete data.B;
				delete data.C;
				delete data.P;
				data.A = data.B = data.C = data.P = NULL;
				data.how_many_points = 0;
			}
		}
		else if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {  // Add new triangle point
				assign_new_point(data, rtrn_point(event));
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {  // Add new check point
				delete data.P;
				data.P = rtrn_point(event);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
class BetterPoint {
	float x, y;
};

///////////////////////////////////////////////////////////////////////////////]
int main() {

	t_data data;
	
	sf::RenderWindow window(sf::VideoMode(SZ_PX_X, SZ_PX_Y), "SFML Window");

	while (window.isOpen()) {

		handle_event(window, data);
		window.clear(sf::Color::Black);
		draw_screen(window, data);
		window.display();
	}

	return 0;
}