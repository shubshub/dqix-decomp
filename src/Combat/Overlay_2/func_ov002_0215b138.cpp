#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Struct_0205def8;
struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" void func_0205def8(struct Struct_0205def8* s, int clear, int key);
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void func_ov002_02154bcc(int a, int b, void* obj, int idx, unsigned char arg4, unsigned char arg5);

// USA: func_ov002_0215b138
// KEEP-NAME
extern "C" ARM void func_ov002_0215b138(unsigned char* obj) {
    func_0205def8((struct Struct_0205def8*)(obj + REGION_VALUE(0xe20, 0xec8)), 0, REGION_VALUE(0x2b, 0x28));

    if (*(int*)(obj + REGION_VALUE(0x1a80, 0x1bb8)) != 4 && *(int*)(obj + REGION_VALUE(0x1a80, 0x1bb8)) != 5) {
        return;
    }
    if (*(signed char*)(obj + REGION_VALUE(0x1ae8, 0x1c20)) != 4) {
        return;
    }

    struct Elem_0205d81c* elem = func_0205d81c((struct Struct_0205d81c*)(obj + REGION_VALUE(0xe20, 0xec8)), REGION_VALUE(0x2b, 0x28));
    if (elem == 0) {
        return;
    }
    if (!WindowPane_IsReady((unsigned char*)elem)) {
        return;
    }

    int b;
    int a = *(short*)((char*)elem + 0xac);
    b = *(short*)((char*)elem + 0xae);
    b = (short)(b * 8);
    a = (short)(a * 8);

    func_ov002_02154bcc(a, b, *(void**)(obj + REGION_VALUE(0x19c0, 0x1a68)), REGION_VALUE(0x28, 0x26), 0x55, 0xff);

    unsigned char byteVal = *(unsigned char*)(obj + REGION_VALUE(0x22bd, 0x248d));
    unsigned short idx2 = (unsigned short)(byteVal + REGION_VALUE(0x29, 0x27));
    func_ov002_02154bcc(a, b, *(void**)(obj + REGION_VALUE(0x19c0, 0x1a68)), idx2, 0x58, 0xff);

    func_0205def8((struct Struct_0205def8*)(obj + REGION_VALUE(0xe20, 0xec8)), 1, REGION_VALUE(0x2b, 0x28));
}
