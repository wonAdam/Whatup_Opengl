#pragma once

#include "Game.h"

class Time
{
public:
	static float deltaTime;

private:
	static float _lastFrame;
	static void Update(float time);



	friend void Game::Update(float time);
};

