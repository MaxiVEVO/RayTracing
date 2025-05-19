#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Occluder.h"
#include "lightSource.h"
#include "RayCaster.h"
using namespace sf;
using namespace std;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;
	LightSource light;
	Occluder occ;
	RayCaster rays;
	//vector for Particles

	// Private functions for internal use only
	void input();
	void draw();

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};
