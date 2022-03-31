#include <Windows.h>
#include <cstring>
#include "resource.h"
using namespace std;
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
				//get text from input to check
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE] = {};
				HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1);
				SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				switch (HIWORD(wParam))
				{
					case EN_SETFOCUS: {
						//if input is null then clear it else nothing it stay same
						if (std::strcmp(sz_buffer, sz_login_invitation) == 0) {
							SendMessage(GetDlgItem(hwnd, IDC_LOGIN1),WM_SETTEXT, 0, (LPARAM)"");
						}
					}
					break;
					case EN_KILLFOCUS: {
						if (sz_buffer[0] == '\0') {
							SendMessage(GetDlgItem(hwnd, IDC_LOGIN1), WM_SETTEXT, 0, (LPARAM)sz_login_invitation);
						}
					}
					break;
				default:
					break;
				}
			}
			break;
			case IDC_LOGIN2: {
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE] = {};
				HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN2);
				SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				switch (HIWORD(wParam))
				{
				case EN_SETFOCUS: {
					if (std::strcmp(sz_buffer, sz_password_invitation) == 0) {
						SendMessage(GetDlgItem(hwnd, IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)"");
					}
				}
				break;
				case EN_KILLFOCUS: {
					if (sz_buffer[0] == '\0') {
						SendMessage(GetDlgItem(hwnd, IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)sz_password_invitation);
					}
				}
				break;
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