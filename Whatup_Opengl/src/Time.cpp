#include "Time.h"

float Time::_lastFrame = 0.0f;
float Time::deltaTime = 0.0f;

void Time::Update(float time)
{
	deltaTime = time - _lastFrame;
	_lastFrame = time;
}
