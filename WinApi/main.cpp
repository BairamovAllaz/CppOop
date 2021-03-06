#include <Windows.h>
#include <cstring>
#include <string>
#include <fstream>
#include "resource.h"
using namespace std;
CHAR sz_login_invitation[] = "Enter login";
CHAR sz_password_invitation[] = "Enter password";
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMgs, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) 
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(ID_CLOGIN), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg)
		{
		case WM_CTLCOLORSTATIC: { //change color of static text
			if ((HWND)lParam == GetDlgItem(hwnd, IDC_STATICTEXTALERT)) {
				SetBkMode((HDC)wParam, TRANSPARENT);
				SetTextColor((HDC)wParam, RGB(255, 0, 0)); 
				return (BOOL)GetSysColorBrush(COLOR_MENU); 
			}
		}
		break;
		case WM_INITDIALOG: {
			HICON hicon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hicon);
			SendMessage(GetDlgItem(hwnd,IDC_LOGIN1), WM_SETTEXT, 0, (LPARAM)sz_login_invitation);
			SendMessage(GetDlgItem(hwnd,IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)sz_password_invitation);
		}
		break;
		case WM_COMMAND: {
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1);
			HWND hPassword = GetDlgItem(hwnd, IDC_LOGIN2);
			switch (LOWORD(wParam))
			{
			case IDC_LOGIN1: {
				//get text from input to check

				//HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1);
				SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				//HWND hEditLogin = GetDlgItem(hwnd, IDC_LOGIN1);
				switch (HIWORD(wParam))
				{
					case EN_SETFOCUS: {
						//if input is null then clear it els enothing it stay same
						if (std::strcmp(sz_buffer, sz_login_invitation) == 0) {
							SendMessage(hLogin,WM_SETTEXT, 0, (LPARAM)"");
						}
					}
					break;
					case EN_KILLFOCUS: {
						if (sz_buffer[0] == '\0') {
							SendMessage(hLogin, WM_SETTEXT, 0, (LPARAM)sz_login_invitation);
						}
					}
					break;
				default:
					break;
				}
			}
			break;
			case IDC_LOGIN2: {
				SendMessage(hPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				switch (HIWORD(wParam))
				{
				case EN_SETFOCUS: {
					if (std::strcmp(sz_buffer, sz_password_invitation) == 0) {
						SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)"");
					}
				}
				break;
				case EN_KILLFOCUS: {
					if (sz_buffer[0] == '\0') {
						SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_password_invitation);
					}
				}
				break;
				default:
					break;
				}
			}
			break;
			/*case IDC_BUTTONSIGNIN: {
				CONST INT SIZE = 256;
				CHAR sz_buffer_login[SIZE] = {};
				CHAR sz_buffer_password[SIZE] = {};
				HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1);
				SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer_login);
				HWND hPassword = GetDlgItem(hwnd, IDC_LOGIN2);
				SendMessage(hPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer_password);
				
				std::ofstream database("database.txt");
				if (database.is_open()) {
					if (
						std::strcmp(sz_buffer_login, sz_login_invitation) == 0
						|| std::strcmp(sz_buffer_password, sz_password_invitation) == 0
						|| sz_buffer_login[0] == '\0'
						|| sz_buffer_password[0] == '\0'
					) {
						SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"INPUTS CANT BE EMPTY");
						MessageBox(NULL, "INPUTS CANT BE EMPTY", "ERROR", MB_ICONERROR);
					}
					else {
						database << sz_buffer_login << endl;
						database << sz_buffer_password << endl;
						SendMessage(GetDlgItem(hwnd, IDC_LOGIN1), WM_SETTEXT, 0, (LPARAM)sz_login_invitation);
						SendMessage(GetDlgItem(hwnd, IDC_LOGIN2), WM_SETTEXT, 0, (LPARAM)sz_password_invitation);
						SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"LETS LOGIN NOW!!");
					}
					database.close();
				}
				else {
					SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"DATABASE NOT FOUNDED");
					MessageBox(NULL, "FILE NOT FOUNDED", "ERROR", MB_ICONERROR);
				}			
			}
			break;*/
			//case IDC_BUTTONLOGIN: {
			//	CONST INT SIZE = 256;
			//	CHAR sz_buffer_login[SIZE] = {};
			//	CHAR sz_buffer_password[SIZE] = {};
			//	HWND hLogin = GetDlgItem(hwnd, IDC_LOGIN1);
			//	SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer_login);
			//	HWND hPassword = GetDlgItem(hwnd, IDC_LOGIN2);
			//	SendMessage(hPassword, WM_GETTEXT, SIZE, (LPARAM)sz_buffer_password);
			//	std::ifstream database("database.txt");
			//		SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)login.c_str());
			//		std::string stsz_buffer_login(sz_buffer_login);
			//		std::string stsz_buffer_password(sz_buffer_password);
			//		if (login == stsz_buffer_login && password == stsz_buffer_password) {
			//			SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"WELCOME TO YOUR ACCOUNT");
			//		}
			//		else {
			//			SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"WRONG LOGIN OR PASSWORD");
			//			MessageBox(NULL, "WRONG LOGIN OR PASSWORD", "WRONG", MB_ICONERROR);
			//		}
			//		database.close();
			//	}
			//	else {
			//		SendMessage(GetDlgItem(hwnd, IDC_STATICTEXTALERT), WM_SETTEXT, 0, (LPARAM)"DATABASE NOT FOUNDED");
			//		MessageBox(NULL, "FILE NOT FOUNDED", "ERROR", MB_ICONERROR);
			//	}
			//}
			//break;
			case IDC_COPYBUTTON: {
				SendMessage(hLogin, WM_GETTEXT,SIZE, (LPARAM)sz_buffer);
				SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			}
			break;
			case IDC_SET_TITLE_BUTTON: {
				SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
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