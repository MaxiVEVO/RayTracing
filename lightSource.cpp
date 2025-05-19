#include "lightSource.h"
LightSource::LightSource(Vector2f pos, float visRad, Color c)
{
	m_pos = pos;
	m_VisRad = visRad;
	m_color = c;
	circle.setRadius(m_VisRad);
	circle.setOrigin(m_VisRad, m_VisRad);
	circle.setPosition(m_pos);
	circle.setFillColor(c);
	circle.setOutlineColor(Color::White);
}
void LightSource::setPosition(Vector2f pos)
{
	m_pos = pos;
	circle.setPosition(m_pos);
}
Vector2f LightSource::getPosition() const
{
	return m_pos;
}
Color LightSource::getColor() const
{
	return m_color;
}
float LightSource::getVisRad() const
{
	return m_VisRad;
}