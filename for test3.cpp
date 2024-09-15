// speed typping test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include "SoftwareDefinitions.h"
//#include "Header.h"
#include <string>
#include <cmath>
//#include <GLFW/glfw3.h>
#pragma warning(disable: 28252)
#include <Windows.h>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//using namespace std;

#define OnMenuClicked1 1
#define OnMenuClicked2 2
#define OnMenuClicked3 3
#define OnMenuClicked4 4
#define OnExitSoftware 5
#define OnButtonClicked 6
#define OnButtonClicked2 12
#define OnButtonClicked3 13
#define OnSaveFile 7
#define OnTipp 14
#define fsdw 8

int a = 0;
#define PlusPoint a
#define leim i

HWND hEditControl;
char filename[260];
#define fioli 11

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void prints(HWND hWnd);
void MainWndAddMenus(HWND hWnd);
void MainWndAddWidgets(HWND hWnd);

extern "C" int APIENTRY WinMain(_In_ HINSTANCE hInst, HINSTANCE hPrevInst, _In_ LPSTR args, _In_ int ncmdshow) {


    WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"MAinWndClass", SoftwareMainProcedure);

    if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
    MSG SoftwareMainMessage = { 0 };

    CreateWindow(L"MainWndClass", L"Click Click", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);

    while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
        TranslateMessage(&SoftwareMainMessage);
        DispatchMessage(&SoftwareMainMessage);
    }
    return (int)SoftwareMainMessage.wParam;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
    WNDCLASS NWC = { 0 };

    NWC.hCursor = Cursor;
    NWC.hIcon = Icon;
    NWC.hInstance = hInst;
    NWC.lpszClassName = Name;
    NWC.hbrBackground = BGColor;
    NWC.lpfnWndProc = Procedure;

    return NWC;
}

HWND windows;


LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wParam, /*WPARAM wp,*/ LPARAM lp) {
    HDC hdc = GetDC(hWnd);
    switch (msg) {
    case WM_COMMAND:
        switch (wParam) {
        case OnMenuClicked1:
            MessageBoxA(hWnd, "Cat Menu was clicked", "Menu worked", MB_OK);
            break;
        case OnMenuClicked2:
            MessageBoxA(hWnd, "Gun Menu was clicked", "Menu worked", MB_OK);
            break;
        case OnMenuClicked3:
            MessageBoxA(hWnd, "Bonus Menu was clicked", "Menu worked", MB_OK);
            break;
        case OnButtonClicked:
            break;
            /*case OnSaveFile:

                if (GetSaveFileNameA(&ofn)) { SaveData(filename); }
                break;*/
        case OnExitSoftware:
            PostQuitMessage(0);
            break;
        default: break;
        }
        break;
    case WM_CREATE:
        MainWndAddMenus(hWnd);
        MainWndAddWidgets(hWnd);
        //SetOpenFileParams(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lp);
    }
    return 0;
}

void MainWndAddMenus(HWND hWnd) {
    HMENU RootMenu = CreateMenu(); //обычное меню
    HMENU SubMenu = CreateMenu(); //меню с подпунктами
    HMENU SubBonusMenu = CreateMenu();//меню в меню с подпунктами

    AppendMenu(SubMenu, MF_STRING, OnMenuClicked1, L"Cat Menu"); //создание меню
    AppendMenu(SubMenu, MF_STRING, OnMenuClicked2, L"Gun Menu"); //создание меню

    AppendMenu(SubBonusMenu, MF_STRING, OnMenuClicked3, L"speed");//создание меню
    AppendMenu(SubMenu, MF_SEPARATOR, NULL, NULL);
    AppendMenu(SubMenu, MF_POPUP, (UINT_PTR)SubBonusMenu, L"Bonus Menu");

    AppendMenu(RootMenu, MF_STRING, OnExitSoftware, L"Exit");
    //AppendMenu(SubMenu, MF_STRING, OnExitSoftware, L"Exit");

    AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"Kauft_Menu");

    SetMenu(hWnd, RootMenu);
}

void MainWndAddWidgets(HWND hWnd) {
    //CreateWindowA("edit", "0asd", WS_VISIBLE | WS_CHILD | ES_MULTILINE /*разрешает использовать другие строки*/ |s WS_VSCROLL /*для того что бы писать больше строк чем позволяет поле*/, 5, 5, 490, 20, hWnd, NULL, NULL, NULL);
    HDC hdc = GetDC(hWnd);

    //CreateWindowA("button", "Point +1", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 30, hWnd, (HMENU)OnButtonClicked/*(HMENU)PlusCatPoint*/, NULL, NULL);
    CreateWindowA("static", "Speed Typping Test", WS_VISIBLE | WS_CHILD /* | ES_CENTER выводит надпись по центру*/, 5, 5, 490, 20, hWnd, (HMENU)OnButtonClicked , NULL, NULL);
}


int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

