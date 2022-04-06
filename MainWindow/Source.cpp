#include <Windows.h>
CONST CHAR g_szclassName[] = "My Window Class";
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wparam,LPARAM lparam);
INT WINAPI WINMAIN(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR lpCmdline,INT cCmdShow) 
{
	WNDCLASSEX wc; //windows class
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0; 
	wc.cbWndExtra = 0; 
	wc.lpfnWndProc = WndProc;
	wc.style = 0; 
	wc.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wc.hIconSm = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wc.hCursor = LoadCursor(hinstance, MAKEINTRESOURCE(IDC_ARROW)); 
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; 
	wc.hInstance = hinstance; 
	wc.lpszMenuName = NULL; 
	wc.lpszClassName = g_szclassName; 

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL,"Class registriation failed","Error",MB_OK | MB_ICONERROR);
		return 0;
	}
	
	//Creating window

	HWND hwnd = CreateWindowEx(
		NULL,
		g_szclassName,
		g_szclassName,
		WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hinstance,
		NULL
	);

	if (hwnd == NULL) {
		MessageBox(NULL, "WINDOW CREATION FAILED", "FAIL", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, cCmdShow);
	UpdateWindow(hwnd);

	MSG msg; 

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
	switch (uMsg)
	{
	case WM_CREATE: break; 
	case WM_COMMAND: break; 
	case WM_CLOSE: 
		if (MessageBox(hwnd, "Are you sure close", "close", MB_YESNO | MB_ICONINFORMATION) == IDYES) {
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY : 
		PostQuitMessage(0);
	default: {
		return DefWindowProc(hwnd, uMsg, wparam, lparam);
	}
	}
}
