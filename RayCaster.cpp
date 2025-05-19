#include "RayCaster.h"
RayCaster::RayCaster(const LightSource& light, const Occluder& occ, int samples) : m_light(light) , m_occluder(occ)
{
	m_samples = samples;
	rays.setPrimitiveType(Lines);
	rays.resize(samples * 2);
}

const VertexArray& RayCaster::buildFan()
{
	Vector2f origin = m_light.getPosition();
	for (int i = 0; i < m_samples; i++)
	{
		rays[i * 2].position = origin;
		float t;
		float ang = ((2.f * PI) * i) / m_samples;
		Vector2f direction(cos(ang), -sin(ang));
		if (!(m_occluder.intersectRay(origin, direction, t)))
		{
			t = 5000.f;
		}
		rays[(i * 2) + 1].position = origin + (direction * t);
		rays[i * 2].color = Color::Yellow;
		rays[i * 2 + 1].color = Color::Yellow;
	}
	return rays;
}