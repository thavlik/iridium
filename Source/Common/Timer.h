#pragma once

#include <windows.h>

class Timer
{
public:
	Timer()
	{
		QueryPerformanceFrequency(&_freq);
	}
	~Timer()
	{
	}

	double Stop()
	{
		QueryPerformanceCounter(&_stop);
		return (double)(_stop.QuadPart)/(double)_freq.QuadPart;
	}

private:
	LARGE_INTEGER	_freq,
					_stop;
};