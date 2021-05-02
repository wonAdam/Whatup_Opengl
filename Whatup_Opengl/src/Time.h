#pragma once

#include "Game.h"

class Time
{
public:
	float deltaTime = 0.0f;

private:
	float _lastFrame = 0.0f;
	void Update(float time);

private:
	Time();
	Time(const Time& rhs) = delete;
	virtual ~Time();

	friend void Game::Initialize();
	friend void Game::Update(float time);
};

