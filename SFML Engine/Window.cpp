#include "Window.h"

Window::Window(std::string name) : sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), name), dt{0}, event{}
{
	// The stack
	states.push(new GameState{});
	setFramerateLimit(60);
}

Window::~Window()
{
	while (!states.empty())
	{
		delete states.top(); // <--- Polymorphism!!!
		states.pop();
	}
}

void Window::run()
{
	while (isOpen())
	{
		dt = clock.restart().asSeconds(); // Delta time
		update();
		render();
	}
}

void Window::update()
{
	while (pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
			close();
		states.top()->handleEvents(event);
	}
	// Call update() from state classes
	if (!states.empty())
		states.top()->update(dt); // <--- Polymorphism!!!
}

void Window::render()
{
	clear();

	// Call render() from state classes
	if (!states.empty())
		states.top()->render(this); // <--- Polymorphism!!!

	display();
}