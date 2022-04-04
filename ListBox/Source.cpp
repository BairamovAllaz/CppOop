#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include "resource.h"
using namespace std; 

CONST CHAR* string[] = {
	"This","Is","My","First","List","Box"
}; 


BOOL CALLBACK DlgProc(HWND hwnd,UINT uMsg,WPARAM wparam,LPARAM lparam);
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) {

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)DlgProc, 0);
	return 0;
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hListBox = GetDlgItem(hwnd, IDC_LIST1); 
		for (int i = 0; i < sizeof(string) / sizeof(string[0]);++i)
		{
			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)string[i]); 
		}
	}
	break;

	case WM_COMMAND: { //Windows message command
		switch (LOWORD(wparam))
		{
			case IDOK: {
				CONST INT SIZE = 256; 
				CHAR sz_buffer[SIZE] = {};
				CHAR sz_message[SIZE] = {};
				HWND hListBox = GetDlgItem(hwnd, IDC_LIST1); 
				int index = SendMessage(hListBox,LB_GETCURSEL,0,0);
				SendMessage(hListBox, LB_GETTEXT, 0, (LPARAM)sz_buffer);
				sprintf(sz_message,"You picked element NO %d which is value %s",index,sz_buffer);
				MessageBox(hwnd,sz_message,"Info",MB_OK | MB_ICONINFORMATION);
;			}
			break;
			case IDCANCEL: {
				EndDialog(hwnd, 0); 
			}
			break;
		default:
			break;
		}


	}
	break;
	case WM_CLOSE: {
		EndDialog(hwnd, 0);
	}
	default:
		break;
	}


	return FALSE;
}