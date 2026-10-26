#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov002_02154bcc(int a, int b, void* obj, int idx, unsigned char arg4, unsigned char arg5);

// USA: func_ov002_0215aaa4
// KEEP-NAME
extern "C" ARM void func_ov002_0215aaa4(char* obj) {
    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)(obj + REGION_VALUE(0xe20, 0xec8)), REGION_VALUE(0x24, 0x21));
    if (e) {
        short var1 = *(short*)((char*)e + 0xac);
        short x13 = var1 * 8;
        short var3 = x13 + 6;
        short var4 = *(short*)((char*)e + 0xae);
        short var5 = var4 * 8;
        short pos[4];
        unsigned char i;
        pos[0] = var5 + 0x1a;
        pos[1] = var5 + 0x32;
        pos[2] = var5 + 0x4a;
        pos[3] = var5 + 0x62;
        for (i = 0; i < 4; i++) {
            void* p = *(void**)(obj + REGION_VALUE(0x19c0, 0x1a68));
            func_ov002_02154bcc(var3, pos[i], p, (unsigned short)(i + 7), 0xff, 0xff);
        }
    }
}
