#include <windows.h>

HWND button, textLabel;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            button = CreateWindowW(L"BUTTON", L"Click me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                   10, 10, 100, 30, hwnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

            textLabel = CreateWindowW(L"STATIC", L"Hello, world!", WS_VISIBLE | WS_CHILD | SS_LEFT,
                                      10, 50, 200, 20, hwnd, (HMENU)2, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == 1) {
                SetWindowTextW(textLabel, L"Button clicked!");
            }
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
