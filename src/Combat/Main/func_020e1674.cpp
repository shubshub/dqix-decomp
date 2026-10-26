#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubObjStandardPalette(int arg0, int arg1, unsigned int arg2);

struct Struct_020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Struct_020e1674_2 {
    char pad[4];
    struct Struct_020e1674* ptr;
};

// USA: func_020e1674
extern "C" ARM void func_020e1674(struct Struct_020e1674_2* obj, int idx, int sel) {
    int off, addr;
    if (sel < 0 || sel >= 2) return;
    addr = (int)((char*)obj + 0x22 + sel * 2);
    off = idx * 2;
    CleanInvalidateCacheRange((const void*)(addr), 2);
    off += 0x1c0;
    if (obj->ptr->flag == 0) {
        LoadToMainObjStandardPalette(addr, off, 2);
    } else {
        LoadToSubObjStandardPalette(addr, off, 2);
    }
    CleanCacheRange((const void*)(addr), 2);
}
