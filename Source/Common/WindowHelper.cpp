#include "WindowHelper.h"

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}	
}

WindowHelper::WindowHelper(const char* title, int w, int h, int x, int y) :
	_escape(false),
	_hwnd(0)
{
	_width = w;
	_height = h;

	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass1";
	RegisterClassEx(&wc);
	_hwnd = CreateWindowEx(NULL,
		"WindowClass1",
		title,
		WS_OVERLAPPEDWINDOW,
		x,
		y,
		w,
		h,
		NULL,
		NULL,
		hInstance,
		NULL);

	// Now actually set the width and height
	RECT winRC, clientRC;
	GetWindowRect(_hwnd,&winRC);
	GetClientRect(_hwnd,&clientRC);
	int dx = (clientRC.right-clientRC.left)-w;
	int dy = (clientRC.bottom-clientRC.top)-h;
	SetWindowPos(_hwnd, 0, x, y, winRC. right-winRC.left-dx, winRC.bottom-winRC.top-dy, 0);

	ShowWindow(_hwnd, SW_SHOWNORMAL);
}

WindowHelper::~WindowHelper()
{
	DestroyWindow(_hwnd);
}

void WindowHelper::ProcessMessages()
{
	MSG msg;
	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if(msg.message == WM_QUIT)
		{
			_escape = true;
		}
	}
}