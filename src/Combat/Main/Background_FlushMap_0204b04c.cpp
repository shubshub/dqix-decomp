#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

extern unsigned int data_020e7b98[][4];

struct Struct_0204b04c {
    char unknown_0_[0x14];
    void* unknown_14_;
    unsigned int unknown_18_;
    char unknown_1c_[3];
    unsigned char unknown_1f_;
};

static inline unsigned int inline_0204b04c(unsigned int arg0, unsigned int arg1) {
    return data_020e7b98[arg0][arg1];
}

// Main, originally func_0204b04c (USA 0x0204b04c, EUR 0x0204b05c, JPN 0x0204be6c)
extern "C" ARM void Background_FlushMap(Obj0204b04c* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    CleanInvalidateCacheRange(p, GetSize(obj->byte1f, obj->field18));
}