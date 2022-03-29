#include <Windows.h>
#include "resource.h"
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMgs, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) 
{
	//int Value_Message_Box = MessageBox(NULL, "HelloWINAPI", "INFO", MB_OKCANCEL | MB_ICONHAND);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(id_1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:break;
	case WM_COMMAND:break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}