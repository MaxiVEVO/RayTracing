#include "Engine.h"
Engine::Engine() : light(Vector2f(480, 540), 5, Color::Yellow), occ(Vector2f(1440, 540), 100, Color::Blue), rays(light, occ,1)
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);
	m_Window.create(vm, "RayTracing", Style::Default);
}
void Engine::run()
{
	while (m_Window.isOpen())
	{
		input();
		draw();
	}
}
void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape)) m_Window.close();
		if (event.type == sf::Event::Closed) m_Window.close();\
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f clickPos(event.mouseButton.x, event.mouseButton.y);
				light.setPosition(clickPos);
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				Vector2f clickPos(event.mouseButton.x, event.mouseButton.y);
				occ.setPosition(clickPos);
			}
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	m_Window.draw(rays.buildFan());
	m_Window.draw(occ);         
	m_Window.draw(light);        
	m_Window.display();
}
