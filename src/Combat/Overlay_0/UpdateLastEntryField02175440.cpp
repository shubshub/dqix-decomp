#include <globaldefs.h>

struct Struct0205d888 {
    char pad0[0x98];
    int field98;
    void* field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};
void* Window_GetTopPane(struct Struct0205d888* p);
int WindowPane_IsReady(unsigned char* obj);
void TouchGrid_SetTouchedCell(void* obj, int value);

// USA: func_ov000_02175440
ARM void UpdateLastEntryField02175440(void* obj) {
    void* entry = Window_GetTopPane((struct Struct0205d888*)((char*)obj + 0x188));
    if (entry == 0) return;
    if (!WindowPane_IsReady((unsigned char*)entry)) return;
    if (((unsigned char*)entry)[0xc5] & 0x2) return;
    TouchGrid_SetTouchedCell((char*)obj + 0x18c, -1);
}
