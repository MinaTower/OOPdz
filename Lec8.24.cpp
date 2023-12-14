// Lec8.24.cpp : Определяет точку входа для приложения.
//
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "framework.h"
#include "Lec8.24.h"
#include"Shape.h"
#include"Line.h"
#include"PolyLine.h"
#include"DB.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

int str_to_int(string&& obj, int ans = 0) {
    for (int i = 0; i < obj.size(); i++) {
        ans = ans * 10 + (obj[i] - 48);
    };
    return ans;
};

POINT get_POINT(POINT* ans, const string& inf, size_t s_elem, size_t e_elem) {
    string x_s, y_s;
    bool part_flag = false;
    int j;
    for (j = s_elem; j < e_elem; j++) {
        if (inf[j] == ',') { part_flag = true; continue; }
        else if (inf[j] == ';') { break; };
        if (part_flag == false) { x_s += inf[j]; }
        else { y_s += inf[j]; };
    };
    ans->x = str_to_int(move(x_s));
    ans->y = str_to_int(move(y_s));
    return *ans;
};

DB storage;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    string shape_part;
    string f_information;
    ifstream ifile;
    ifile.open("pixels-addition.hpgl");
    ifile >> f_information;
    shape_part = f_information.substr(f_information.find("SP1;") + 4);
    ifile.close();

    for (int i = 1 + shape_part.find("PU"); i < shape_part.rfind("SP"); i += 0) {
        shape_part[i - 1] = '-';
        shape_part[i] = '-';
        bool pu_flag = true;
        vector<POINT> pu;
        for (i = shape_part.find("PA"); i < min(shape_part.find("PU;"), shape_part.rfind(";SP")); i += 0) {
            shape_part[i] = '-';
            shape_part[i + 1] = '-';
            i += 2;
            int i_end = min(min(shape_part.rfind(";SP"), shape_part.find(";PU")), min(shape_part.find(";PA"), shape_part.find(";PD")));
            POINT c = get_POINT(&c, shape_part, i, i_end);
            if (pu_flag == true) {
                pu.clear();
            };
            pu.push_back(move(c));
            i = i_end + 1;
            if (i == shape_part.find("PD")) {//
                pu_flag = false;
                shape_part[i] = '-';
                shape_part[i + 1] = '-';
                i += 3;
                continue;
            };
        };
        if ((pu_flag == false) && (i == shape_part.find("PU"))) {
            if (pu.size() <= 2) {
                storage.adding(new Line(move(pu))); pu.clear();
            }
            else {
                storage.adding(new PolyLine(move(pu))); pu.clear();
            };
        };
    };

    nCmdShow = SW_SHOWMAXIMIZED;//

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LEC824, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LEC824));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LEC824));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LEC824);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   //SetWindowPos(hWnd, HWND_TOP, 0, 0, 9000, 9000, SWP_NOMOVE);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            storage.paint(hdc);//

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
