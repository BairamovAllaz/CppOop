#define _CRT_SECURE_NO_WARNINGS
#include <winapifamily.h>
#include<Windows.h>
#include<cstring>
#include<string>
#include <stdio.h>
#include "resource.h"
using namespace std;

#define IDC_MY_STATIC 104


CONST CHAR g_szClassName[] = "My Window Class";
//g  - global
//sz - string zero

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	
	WNDCLASSEX wc;	//wc - Window Class
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WndProc;	
	wc.style = 0;	
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	//wc.hIcon = (HICON)LoadImage(hInstance,"new.ico",IMAGE_ICON,LR_DEFAULTSIZE,LR_DEFAULTSIZE,LR_LOADFROMFILE);
	//wc.hIconSm = (HICON)LoadImage(hInstance, "new.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}


	int height_screen = GetSystemMetrics(SM_CYSCREEN); 
	int width_screen = GetSystemMetrics(SM_CXSCREEN);
	int window_width = width_screen - (width_screen / 4);  
	int window_height = height_screen - (height_screen / 4);
	int window_start_x = width_screen / 8;
	int window_start_y = height_screen / 8;
	//2) Сохздание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL,	//Ex-style
		g_szClassName,	
		"Main Window",	
		WS_OVERLAPPEDWINDOW,
		//(width_screen / 2)  - (window_width / 2),(height_screen / 2) - (window_height/ 2),
		window_start_x,window_start_y,
		window_width, window_height,
		NULL,	
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Info", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);	
	UpdateWindow(hwnd);	

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);	
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: {
		CreateWindowEx(
			NULL, 
			"Static",
			"this is my static text",
			WS_CHILDWINDOW | WS_VISIBLE, 
			10,10,
			1000,50,
			hwnd,
			(HMENU)IDC_MY_STATIC,
			GetModuleHandle(NULL), 
			NULL
		);
	}
	break;
	case WM_COMMAND:break;
	case WM_MOVE:
	case WM_SIZE: {
		CONST INT SIZE = 256; 
		CHAR buffer[SIZE] = {}; 
		RECT rect;
		GetWindowRect(hwnd, &rect);
		int window_width = rect.right - rect.left;
		int window_height = rect.bottom - rect.top;
		sprintf(buffer,"Size: %dx%d , Position: %dx%d",window_width,window_height, rect.left,rect.top);
		SendMessage(hwnd,WM_SETTEXT,0,(LPARAM)buffer);
		HWND hStatic = GetDlgItem(hwnd, IDC_MY_STATIC);
		SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)buffer);

	}
	break;
	case WM_CLOSE: {
		/*int width, height;
		RECT rect;
		if (GetWindowRect(hwnd, &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		}
		std::string tmp = std::to_string(width);
		char const* num_char = tmp.c_str();
		*/
		if (MessageBox(hwnd,"Are you sure to close?", "Are You?", MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			DestroyWindow(hwnd);
		}
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}