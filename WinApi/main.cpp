#include <Windows.h>
#include "resource.h"

CHAR sz_login_invitation[] = "Enter login";
CHAR sz_password_invitation[] = "Enter password";

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMgs, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) 
{
	//int Value_Message_Box = MessageBox(NULL, "HelloWINAPI", "INFO", MB_OKCANCEL | MB_ICONHAND);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(ID_CLOGIN), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg)
		{
		case WM_INITDIALOG: {
			HICON hicon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hicon);
			SendMessage(GetDlgItem(hwnd,IDC_LOGIN1), WM_SETTEXT, 0, (LPARAM)sz_login_invitation);
			SendMessage(GetDlgItem(hwnd,IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)sz_password_invitation);
		}
			break;
		case WM_COMMAND: {
			switch (LOWORD(wParam))
			{
			case IDC_LOGIN1: {
				switch (HIWORD(wParam))
				{
				case EN_SETFOCUS: {
					SendMessage(GetDlgItem(hwnd, IDC_LOGIN1),WM_SETTEXT, 0, (LPARAM)"");
				}
				break;
				default:
					break;
				}
			}
			break;
			case IDC_LOGIN2: {
				switch (HIWORD(wParam))
				{
				case EN_SETFOCUS: {
					SendMessage(GetDlgItem(hwnd, IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)"");
				} break;
				default:
					break;
				}
			}
			break;
			case IDC_COPYBUTTON: {
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE] = {}; 
				HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1); 
				SendMessage(hLogin, WM_GETTEXT,SIZE, (LPARAM)sz_buffer);
				HWND hPassword = GetDlgItem(hwnd, IDC_LOGIN2);
				SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			}
			break;
			case IDC_SET_TITLE_BUTTON: {
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE] = {};
				SendMessage(GetDlgItem(hwnd, IDC_LOGIN1), WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer); 
			}
			break;
			case IDOK:{
				MessageBox(NULL, "YOU PRESSED OK", "INFO", MB_OK | MB_ICONINFORMATION);
			}
				break;
			case IDCANCEL: {
				EndDialog(hwnd, 0);
			}
			default:
				break;
			}
			break;
		}
		case WM_CLOSE:
			EndDialog(hwnd, 0);
		}
		return FALSE;
}