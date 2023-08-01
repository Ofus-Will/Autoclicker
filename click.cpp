#include <Windows.h>
#include <stdlib.h>
#include <iostream>

int main() {
    int lmb_cps //, rmb_cps;
    bool toggle = true;

    std::cout << "Left click CPS: ";
    std::cin >> lmb_cps;

    if(lmb_cps >= 20 || lmb_cps < 1) { 
        system("cls");
        std::cout << "CPS must be between 1 and 20" << std::endl; 
        main();
    }

    system("cls");

    std::cout << "Toggle: F4" << std::endl;
    std::cout << "Left CPS: " << lmb_cps << std::endl;

    bool clicking, in_focus;
    HWND window;
    int left_delay = (2000 / lmb_cps) / 1;
    //int right_delay = (2000 / rmb_cps) / 1;

    while(true) {

        window = GetForegroundWindow();
        clicking = GetAsyncKeyState(VK_LBUTTON);
        in_focus = FindWindowA(("LWJGL"), nullptr) == window;

        if(toggle && clicking && in_focus) {
            SendMessageW(window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
            SendMessageW(window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
            Sleep(rand() % left_delay);
        }

        if(GetAsyncKeyState(VK_F4)) {
            toggle = !toggle;
            Sleep(200);
        }
    }


}