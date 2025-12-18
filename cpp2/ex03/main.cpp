#include <iostream>

#include <SFML/Graphics.hpp>

#include <sstream>
#include <iomanip>
#include <math.h>

#define SZ_PX_X 1200
#define SZ_PX_Y 900
#define FOV 100.0f
#define PX (FOV / SZ_PX_X)

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
struct BetterPoint {
	float _x, _y;

	BetterPoint() {}
	BetterPoint(float x, float y) : _x(x), _y(y) {}
};

///////////////////////////////////////////////////////////////////////////////]
void draw_line(sf::RenderWindow& window, const BetterPoint& a, const BetterPoint& b, const sf::Color& color) {
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(SZ_PX_X / 2.0f + a._x / PX, SZ_PX_Y / 2.0f - a._y / PX), color),
		sf::Vertex(sf::Vector2f(SZ_PX_X / 2.0f + b._x / PX, SZ_PX_Y / 2.0f - b._y / PX), color)
	};
	window.draw(line, 2, sf::Lines);
}

void draw_thick_line(sf::RenderWindow& window, const BetterPoint& a, const BetterPoint& b, float thickness, const sf::Color& color)
{
    sf::Vector2f p1(
        SZ_PX_X / 2.0f + a._x / PX,
        SZ_PX_Y / 2.0f - a._y / PX
    );

    sf::Vector2f p2(
        SZ_PX_X / 2.0f + b._x / PX,
        SZ_PX_Y / 2.0f - b._y / PX
    );

    sf::Vector2f diff = p2 - p1;
    float length = std::sqrt(diff.x * diff.x + diff.y * diff.y);

    sf::RectangleShape line(sf::Vector2f(length, thickness));
    line.setFillColor(color);
    line.setPosition(p1);
    line.setRotation(std::atan2(diff.y, diff.x) * 180.f / M_PI);

    window.draw(line);
}

///////////////////////////////////////////////////////////////////////////////]
void	handle_event(sf::RenderWindow& win) {

	sf::Event event;

	while (win.pollEvent(event)) {
		if (event.type == sf::Event::Closed)  // Exit on cross
			win.close();
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape)  // Exit on Esc
				win.close();
		}
	}
}

#define THICKNESS 10.0
///////////////////////////////////////////////////////////////////////////////]
void	draw_screen(sf::RenderWindow& win, BetterPoint* points, BetterPoint* points_bellow) {

	for (int i = 0; i < 12; i++) {
	
		// draw_line(win, points[i], points[(i+4)%12], sf::Color::Black);
		// draw_line(win, points_bellow[i], points_bellow[(i+4)%12], sf::Color::Black);
		draw_thick_line(win, points[i], points[(i+4)%12], THICKNESS, sf::Color::Black);
		draw_thick_line(win, points_bellow[i], points_bellow[(i+4)%12], THICKNESS, sf::Color::Black);
	}
}

#define RAD1 30.0
#define RAD2 15.0
///////////////////////////////////////////////////////////////////////////////]
int main() {

	BetterPoint	notes[12];
	BetterPoint	notes_bellow[12];

	for (int i = 0; i < 12; ++i) {
		float angle = i * M_PI / 6.0f; // i * (π/6)

		notes[i]._x = RAD1 * std::cos(angle);
		notes[i]._y = RAD1 * std::sin(angle);

		notes_bellow[i]._x = RAD2 * std::cos(angle);
		notes_bellow[i]._y = RAD2 * std::sin(angle);
	}
	
	sf::RenderWindow window(sf::VideoMode(SZ_PX_X, SZ_PX_Y), "SFML Window");

	while (window.isOpen()) {

		handle_event(window);
		window.clear(sf::Color::White);
		draw_screen(window, notes, notes_bellow);
		window.display();
	}

	return 0;
}