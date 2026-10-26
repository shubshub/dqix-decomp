#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
enum { kRegione8 = 0xe4 };
enum { kRegion4ea = 0x4e6 };
#else
enum { kRegione4 = 0xe4 };
enum { kRegione8 = 0xe8 };
enum { kRegion4ea = 0x4ea };
#endif

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    void* unknown_9c_;
    char pad1[0x14];
    unsigned char fieldB4;
};

extern "C" struct Struct_0205d81c* Window_GetActivePane(struct Struct_0205d81c*);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int Window_Update(void*, int);

// USA: func_ov003_021694b8
extern "C" ARM void func_ov003_021694b8(void* obj, int id) {
    struct Struct_0205d81c* entry = Window_GetActivePane((struct Struct_0205d81c*)((char*)obj + kRegione4));
    if (entry != 0) {
        if (WindowPane_IsReady((unsigned char*)entry)) {
            if (!(((unsigned char*)entry)[0xc5] & 0x2)) {
                TouchGrid_SetTouchedCell((char*)obj + kRegione8, -1);
            }
        }
    }
    *((unsigned char*)obj + kRegion4ea) = (unsigned char)Window_Update((char*)obj + kRegione4, id);
}
