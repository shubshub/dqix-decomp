#include <globaldefs.h>

extern int (*data_020f01b8[][4])(int, int);

struct Obj0204b5e8 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// Main, originally DispatchViaTable0204b5e8 (USA 0x0204b5e8, EUR 0x0204b5f8, JPN 0x0204c408)
ARM int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b) {
    return data_020f01b8[obj->lo][obj->hi](a, b);
}
