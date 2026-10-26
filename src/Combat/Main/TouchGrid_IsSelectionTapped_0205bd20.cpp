#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205bd20 {
    char pad[0x4c];
    unsigned char field4c;
    unsigned char unknown_4d_;
    unsigned char unknown_4e_;
};

// Main, originally CheckActive0205bd20 (USA 0x0205bd20, EUR 0x0205bd30, JPN 0x0205d080)
extern "C" ARM int TouchGrid_IsSelectionTapped(struct Struct_0205bd20* s, int key) {
    int result = 0;
    if (g_touchInput.pressed_ != 0 && s->unknown_4e_ == 1 && s->field4c != 0) {
        result = 1;
    }
    return result;
}
