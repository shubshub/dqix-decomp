#include <globaldefs.h>

extern "C" int GridCursor_GetCount(void* obj);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);
struct Struct_0205bcdc {
    int field0;
    char pad[0x2c];
    int unknown_30_;
};
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);

// USA: func_0205d7a0
extern "C" ARM void func_0205d7a0(unsigned char* obj, int val) {
    int cur;
    if (obj[0x95]) {
        cur = GridCursor_GetCount(obj + 0x54);
    } else if (obj[0x94]) {
        cur = GridCursor_GetCount(obj + 0x4);
    }
    if (val < 0) {
        if (cur <= val) return;
    }
    if (obj[0x95]) {
        GridCursor_SetSelectedIndex(obj + 0x54, val);
    }
    if (obj[0x94] == 0) return;
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)(obj + 0x4), val);
}
