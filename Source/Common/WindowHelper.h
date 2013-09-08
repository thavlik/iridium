#pragma once
#include <windows.h>

class WindowHelper
{
public:
	WindowHelper(const char* title, int w, int h, int x, int y);
	~WindowHelper();

	void		ProcessMessages();
	bool		Escape()	const	{ return _escape; }
	HWND		Handle()	const	{ return _hwnd; }
	unsigned	Width()		const	{ return _width; }
	unsigned	Height()	const	{ return _height; }

private:
	bool		_escape;
	HWND		_hwnd;
	unsigned	_width;
	unsigned	_height;
};