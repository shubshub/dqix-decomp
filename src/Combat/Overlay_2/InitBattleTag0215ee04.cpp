#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0215eec0(void* base, void* dst, int flag);
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufOv0215ee04 { char pad[0xbd0]; void* buf; };

// USA: func_ov002_0215ee04
ARM void InitBattleTag0215ee04(char* base) {
    short val = 0x10;
    struct Elem_0205d81c* elem = FindElementByC40205d81c((struct Struct_0205d81c*)(base + 0xec8), val);
    if (elem) {
        val = *(short*)((char*)elem + 0xac) + *(short*)((char*)elem + 0xa8);
    }
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0xec8), 0, 2);
    func_ov002_0215be00(base, 0x12, val, 0x11);

    memset(((struct BufOv0215ee04*)(base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215eec0(base, ((struct BufOv0215ee04*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv0215ee04*)(base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);
}
