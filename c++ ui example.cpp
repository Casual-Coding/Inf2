#include <windows.h>

HWND button, textLabel;

typedef struct tagLOGFONTW {
  LONG      lfHeight;
  LONG      lfWidth;
  LONG      lfEscapement;
  LONG      lfOrientation;
  LONG      lfWeight;
  BYTE      lfItalic;
  BYTE      lfUnderline;
  BYTE      lfStrikeOut;
  BYTE      lfCharSet;
  BYTE      lfOutPrecision;
  BYTE      lfClipPrecision;
  BYTE      lfQuality;
  BYTE      lfPitchAndFamily;
  WCHAR     lfFaceName[LF_FACESIZE];
} LOGFONTW;

typedef struct tagTEXTMETRICW {
  LONG tmHeight;
  LONG tmAscent;
  LONG tmDescent;
  LONG tmInternalLeading;
  LONG tmExternalLeading;
  LONG tmAveCharWidth;
  LONG tmMaxCharWidth;
  LONG tmWeight;
  LONG tmOverhang;
  LONG tmDigitizedAspectX;
  LONG tmDigitizedAspectY;
  WCHAR tmFirstChar;
  WCHAR tmLastChar;
  WCHAR tmDefaultChar;
  WCHAR tmBreakChar;
  BYTE tmItalic;
  BYTE tmUnderlined;
  BYTE tmStruckOut;
  BYTE tmPitchAndFamily;
  BYTE tmCharSet;
} TEXTMETRICW;

int pointY = 50; // Ausgangsposition des Punktes

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            CreateWindowW(L"BUTTON", L"Click me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                          10, 10, 100, 30, hwnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == 1) {
                // Lade dynamisch die GDI-Funktionen
                HMODULE hGDI = LoadLibraryW(L"gdi32.dll");
                if (hGDI != NULL) {
                    typedef HBRUSH(WINAPI *CREATEBRUSHFUNC)(COLORREF);
                    CREATEBRUSHFUNC CreateSolidBrushFunc = (CREATEBRUSHFUNC)GetProcAddress(hGDI, "CreateSolidBrush");
                    if (CreateSolidBrushFunc != NULL) {
                        HBRUSH redBrush = CreateSolidBrushFunc(RGB(255, 0, 0));

                        // Zeichne den Punkt im Fenster
                        HDC hdc = GetDC(hwnd);
                        SelectObject(hdc, redBrush);
                        Ellipse(hdc, 400 - 2, pointY - 2, 400 + 2, pointY + 2); // Mittelpunkt (400, pointY)
                        ReleaseDC(hwnd, hdc);

                        // Bewege den Punkt nach unten für die nächste Position
                        pointY += 5;

                        // Freigebe der Ressourcen
                        DeleteObject(redBrush);
                    }

                    // Freigabe der Bibliothek
                    FreeLibrary(hGDI);
                }
            }
            break;
        }
        case WM_PAINT: {
            // Diese Zeichenprozedur wird aufgerufen, wenn das Fenster neu gezeichnet werden muss
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Hier könntest du weitere Zeichenoperationen durchführen, wenn nötig

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int main() {
    // Register the window class
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = L"MyWindowClass";
    RegisterClassW(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,
        L"MyWindowClass",
        L"My Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        0, 0, GetModuleHandle(0), 0);

    // Show the window
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    // Enter the message loop
    MSG msg = {0};
    while (GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
