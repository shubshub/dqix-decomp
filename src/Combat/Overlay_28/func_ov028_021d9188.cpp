#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubBG1CharacterData(int arg0, int arg1, unsigned int arg2);

struct Struct_ov028_021d9188 {
    char pad0[0x40];
    void* field40;
    char unknown_44_[0x60 - 0x44];
    int f60;
    char unknown_64_[0x6e - 0x64];
    unsigned char unknown_6e_;
    char unknown_6f_[0x80 - 0x6f];
    unsigned char unknown_80_;
};

// USA: func_ov028_021d9188
extern "C" ARM void func_ov028_021d9188(Struct_ov028_021d9188* obj) {
    if (obj->unknown_80_ == 0 || obj->field40 == 0) return;
    *(volatile unsigned int*)0x4001014 = (((obj->f60 >> 12) & 0xff) << 16) & 0x1ff0000;
    if (obj->unknown_6e_ != 0) {
        CleanInvalidateCacheRange(obj->field40, 0x8000);
        LoadToSubBG1CharacterData((int)obj->field40, 0, 0x8000);
        CleanCacheRange(obj->field40, 0x8000);
    }
    obj->unknown_6e_ = 0;
}
