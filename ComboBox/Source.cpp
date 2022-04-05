#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include "resource.h"


CONST CHAR title[] = "Select an item";

CONST CHAR* combostring[] = {
	title,
	"this",
	"is",
	"a",
	"example",
	"combo",
	"box",
	"winapi",
};

BOOL CALLBACK DlgProg(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);

INT WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hPrevinstance,LPSTR lpCmdLine,INT nCmdShow) {
	DialogBoxParam(hinstance,MAKEINTRESOURCE(IDD_DIALOG1),0,DlgProg,0);
	return 0;
}



BOOL CALLBACK DlgProg(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {

	switch (uMsg)
	{
	case WM_INITDIALOG: {
		HWND hComboBox = GetDlgItem(hwnd, IDC_COMBO1);
		for (int  i = 0; i < sizeof(combostring) / sizeof(combostring[0]); i++)
		{
			SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)combostring[i]);
		}
		SendMessage(hComboBox,CB_SETCURSEL, 0, 0);

		HICON hicon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hicon);

	}
	break;
	case WM_COMMAND: {
		switch (LOWORD(wparam))
		{
		case IDOK: {
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			CHAR sz_message[SIZE] = {};
			HWND combobox = GetDlgItem(hwnd, IDC_COMBO1);
			int index = SendMessage(combobox, CB_GETCURSEL, 0, 0);
			if (index == 0) {
				MessageBox(hwnd,"SELECT ONE ITEM!", "Info", MB_OK | MB_ICONWARNING);
			}
			else {
				SendMessage(combobox, CB_GETLBTEXT, 0, (LPARAM)sz_buffer);	
				sprintf(sz_message, "You picked element NO %d which is value %s", index, sz_buffer);
				MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
			}
		}
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
	break;
	default:
		break;
	}
	return FALSE;
}