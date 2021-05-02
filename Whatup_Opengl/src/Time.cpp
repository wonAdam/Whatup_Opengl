#include "Time.h"

void Time::Update(float time)
{
	deltaTime = time - _lastFrame;
	_lastFrame = time;
}

Time::Time()
{
}

Time::~Time()
{
}
