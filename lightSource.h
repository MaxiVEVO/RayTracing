#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class LightSource : public Drawable
{
public:
	LightSource(Vector2f pos, float visRad, Color c = Color::Yellow);
	void setPosition(Vector2f pos);
	Vector2f getPosition() const;
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override {rt.draw(circle, states);}
	Color getColor() const;
	float getVisRad() const;
private:
	Vector2f m_pos;
	float m_VisRad;
	Color m_color;
	CircleShape circle;
};

