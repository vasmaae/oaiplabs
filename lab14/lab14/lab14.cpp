// lab14.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab14.h"
#include "images.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int image1_x = 0, image1_y = 0, type = 0, image1_n = 1, image1_m = 1, r = 0, g = 0, b = 0;

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

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB14));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB14);
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
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            image1_x -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_RIGHT:
            image1_x += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_DOWN:
            image1_y += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_UP:
            image1_y -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_SPACE:
            type++;
            if (type > 6) type = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        
        case 0x49:
            image1_n++;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x4f:
            image1_n--;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x55:
            image1_m++;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x4e:
            image1_m--;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x41:
            r += 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x5a:
            r -= 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x53:
            g += 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x58:
            g -= 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x44:
            b += 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 0x43:
            b -= 50;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_LBUTTONDOWN:
        {
            WORD xpos, ypos;
            xpos = LOWORD(lParam);
            ypos = HIWORD(lParam);
            image1_x = xpos;
            image1_y = ypos;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            int i, j = image1_y, n = 1, m;

            while (n <= image1_n) {
                i = image1_x;
                m = 1;
                while (m <= image1_m) {
                    if (type == 0) image0(hdc, i, j, RGB(r, g, b));
                    if (type == 1) image1(hdc, i, j, RGB(r, g, b));
                    if (type == 2) image2(hdc, i, j, RGB(r, g, b));
                    if (type == 3) image3(hdc, i, j, RGB(r, g, b));
                    if (type == 4) image4(hdc, i, j, RGB(r, g, b));
                    if (type == 5) image5(hdc, i, j, RGB(r, g, b));
                    if (type == 6) image6(hdc, i, j, RGB(r, g, b));
                    i += 70;
                    m++;
                }
                j += 70;
                n++;
            }

            /*if (type == 0) image0(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 1) image1(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 2) image2(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 3) image3(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 4) image4(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 5) image5(hdc, image1_x, image1_y, RGB(r, g, b));
            if (type == 6) image6(hdc, image1_x, image1_y, RGB(r, g, b));*/

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
