#include <windows.h>
#include <shobjidl.h>

// Global variables
HINSTANCE hInst;
HWND hWnd;
ITaskbarList3* pTaskbarList = nullptr;
bool isIndeterminate = false;

// Function to register the window class
ATOM MyRegisterClass(HINSTANCE hInstance);

// Function to initialize the instance
BOOL InitInstance(HINSTANCE, int);

// Window procedure function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Function to flash the taskbar button
void FlashTaskbar(HWND hWnd);

// Function to set taskbar progress state to indeterminate
void SetIndeterminateProgress(HWND hWnd);

// Function to clear taskbar progress
void ClearTaskbarProgress(HWND hWnd);

// Function to initialize taskbar interface
void InitializeTaskbar();

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // Register the window class
    MyRegisterClass(hInstance);

    // Initialize the instance
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    // Initialize taskbar interface
    InitializeTaskbar();

    // Main message loop
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Release taskbar interface
    if (pTaskbarList)
    {
        pTaskbarList->Release();
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = L"MainMenu";
    wcex.lpszClassName = L"TaskbarFlashWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    hWnd = CreateWindowW(L"TaskbarFlashWindowClass", L"Taskbar Flash Example", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Create the menu
    HMENU hMenu = CreateMenu();
    HMENU hSubMenu = CreatePopupMenu();

    AppendMenu(hSubMenu, MF_STRING, 1, L"Flash Taskbar");
    AppendMenu(hSubMenu, MF_STRING, 2, L"Indeterminate Progress");
    AppendMenu(hSubMenu, MF_STRING, 3, L"Clear Progress");

    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hSubMenu, L"Options");

    SetMenu(hWnd, hMenu);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case 1:
            FlashTaskbar(hWnd);
            break;
        case 2:
            SetIndeterminateProgress(hWnd);
            break;
        case 3:
            ClearTaskbarProgress(hWnd);
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
        // TODO: Add any drawing code that uses hdc here...
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

void FlashTaskbar(HWND hWnd)
{
    FLASHWINFO fwi;
    fwi.cbSize = sizeof(FLASHWINFO);
    fwi.hwnd = hWnd;
    fwi.dwFlags = FLASHW_ALL; // Remove FLASHW_TIMERNOFG to allow flashing even if focused
    fwi.uCount = 5; // Number of flashes
    fwi.dwTimeout = 0; // Default cursor blink rate

    FlashWindowEx(&fwi);
}

void SetIndeterminateProgress(HWND hWnd)
{
    if (pTaskbarList)
    {
        pTaskbarList->SetProgressState(hWnd, TBPF_INDETERMINATE);
    }
}

void ClearTaskbarProgress(HWND hWnd)
{
    if (pTaskbarList)
    {
        pTaskbarList->SetProgressState(hWnd, TBPF_NOPROGRESS);
    }
}

void InitializeTaskbar()
{
    // Initialize COM
    if (SUCCEEDED(CoInitialize(nullptr)))
    {
        // Create an instance of the taskbar list interface
        if (FAILED(CoCreateInstance(CLSID_TaskbarList, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pTaskbarList))))
        {
            pTaskbarList = nullptr;
        }
        else
        {
            // Initialize the taskbar interface
            pTaskbarList->HrInit();
        }
    }
}
