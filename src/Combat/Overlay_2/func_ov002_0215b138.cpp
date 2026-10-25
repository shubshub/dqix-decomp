#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Struct_0205def8;
struct Struct_0205d81c;
struct Struct_0205d0e0;

void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key);
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
int WindowPane_IsReady(unsigned char* obj);
void SetEntryFields02154bcc(int a, int b, void* obj, int idx, unsigned char arg5, unsigned char arg6);

// USA: func_ov002_0215b138
// KEEP-NAME
extern "C" ARM void func_ov002_0215b138(unsigned char* arg0) {
    func_0205def8((struct Struct_0205def8*)(arg0 + REGION_VALUE(0xe20, 0xec8)), 0, REGION_VALUE(0x2b, 0x28));

    if (*(int*)(arg0 + REGION_VALUE(0x1a80, 0x1bb8)) != 4 && *(int*)(arg0 + REGION_VALUE(0x1a80, 0x1bb8)) != 5) {
        return;
    }
    if (*(signed char*)(arg0 + REGION_VALUE(0x1ae8, 0x1c20)) != 4) {
        return;
    }

    struct Struct_0205d0e0* var0 = func_0205d81c((struct Struct_0205d81c*)(arg0 + REGION_VALUE(0xe20, 0xec8)), REGION_VALUE(0x2b, 0x28));
    if (var0 == 0) {
        return;
    }
    if (!WindowPane_IsReady((unsigned char*)elem)) {
        return;
    }

    int var1;
    int var2 = *(short*)((char*)var0 + 0xac);
    var1 = *(short*)((char*)var0 + 0xae);
    var1 = (short)(var1 * 8);
    var2 = (short)(var2 * 8);

    func_ov002_02154bcc(var2, var1, *(void**)(arg0 + REGION_VALUE(0x19c0, 0x1a68)), REGION_VALUE(0x28, 0x26), 0x55, 0xff);

    unsigned char var3 = *(unsigned char*)(arg0 + REGION_VALUE(0x22bd, 0x248d));
    unsigned short var4 = (unsigned short)(var3 + REGION_VALUE(0x29, 0x27));
    func_ov002_02154bcc(var2, var1, *(void**)(arg0 + REGION_VALUE(0x19c0, 0x1a68)), var4, 0x58, 0xff);

    func_0205def8((struct Struct_0205def8*)(arg0 + REGION_VALUE(0xe20, 0xec8)), 1, REGION_VALUE(0x2b, 0x28));
}
