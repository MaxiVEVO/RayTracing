#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;
const float PI = 3.14159265358979323846;
class Occluder : public Drawable
{
public:
	Occluder(Vector2f pos, float r, Color c = Color::Blue);
	void setPosition(Vector2f p);
	float getRadius() const;
	Vector2f getPosition() const;
	bool intersectRay(const Vector2f& origin,const Vector2f& dir, float& hitT) const;
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override {rt.draw(m_occluder, states);}
private:
	Vector2f m_pos;
	float m_radius;
	Color m_color;
	CircleShape m_occluder;
};

