#pragma once
#include "lightSource.h"
#include "Occluder.h"

class RayCaster
{
public:
    RayCaster(const LightSource& light ,const Occluder& occ, int samples = 360);

    const VertexArray& buildFan();

private:
    const LightSource& m_light;
    const Occluder& m_occluder;
    int m_samples;
    VertexArray rays;
};

 