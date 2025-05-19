#include "Occluder.h"
Occluder::Occluder(Vector2f pos, float r, Color c )
{
	m_pos = pos;
	m_radius = r;
	m_color = c;
	m_occluder.setRadius(r);
	m_occluder.setPosition(m_pos);
	m_occluder.setFillColor(c);
	m_occluder.setOrigin(r, r);
}
void Occluder::setPosition(Vector2f p)
{
	m_pos = p;
	m_occluder.setPosition(m_pos);
}
float Occluder::getRadius() const
{
	return m_radius;
}
Vector2f Occluder::getPosition() const
{
	return m_pos;
}
bool Occluder::intersectRay(const Vector2f& origin, const Vector2f& dir, float& hitT) const
{
	float a, b, c, disc;
	a = pow(dir.x, 2) + pow(dir.y, 2);
	b = 2 * (((origin.x - m_pos.x) * dir.x) + ((origin.y - m_pos.y) * dir.y));
	c = pow((origin.x - m_pos.x), 2) + pow((origin.y - m_pos.y), 2) - pow(m_radius, 2);
	disc = ((b * b) - (4 * a * c));
	if (disc > 0)
	{
		float tempT1, tempT2;

		tempT1 = ((-b + sqrt(disc)) / (2 * a));
		tempT2 = ((-b - sqrt(disc)) / (2 * a));
		if (tempT1 > 0 && tempT2 > 0)
		{
			if (tempT1 > tempT2)
			{
				hitT = tempT2;
			}
			else
			{
				hitT = tempT1;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (disc == 0)
	{
		hitT = (-b / (2 * a));
		return true;
	}
	else
	{
		return false;
	}

}
