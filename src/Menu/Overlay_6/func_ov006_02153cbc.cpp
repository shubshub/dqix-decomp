#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct Struct_ov006_02153cbc {
    short item;
    unsigned short selected : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};
struct Struct_ov006_02153cbc_2 {
    char unknown_0_[0x10];
    unsigned int flags;
};
struct Struct_ov006_02153cbc_3 {
    char unknown_0_[0x68];
    char unknown_68_[0x48];
};
extern "C" {
extern "C" void func_ov006_02153e54(Struct_ov006_02153cbc*);
void func_ov006_02153e8c(void*, Struct_ov006_02153cbc*);
int func_ov006_02154138(void*);
bool func_020ac2d4(int, short*, Struct_ov006_02153cbc*, int);
void func_020ac104(void*, Struct_ov006_02153cbc*, int);
extern "C" Struct_ov006_02153cbc_2* func_02071d60(void*, short);
extern "C" bool func_020ac0b4(unsigned int*);
extern "C" void func_020ac08c(unsigned int*);
extern "C" int func_020ac4c0(void*);
extern "C" void func_020a0228(void*, int);
extern "C" int func_020ac494(void*);
}
extern "C" ARM void func_ov006_02153cbc(void* state, short selectedItem, short arg2, void* arg3)
{
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    Struct_ov006_02153cbc entry;
    func_ov006_02153e54(&entry);
    if (func_020ac2d4(0, &selectedItem, &entry, 1)) {
        entry.selected = 1;
        entry.unknown_2_1_ = 1;
        func_020ac104(g_fileLoadBuffer, &entry, 1);
        func_ov006_02153e8c(state, &entry);
        if (arg3) {
            Struct_ov006_02153cbc_2* record = func_02071d60(arg3, selectedItem);
            if (record) record->flags |= 0x400000;
        }
    }
    if (arg2 > 0) {
        func_ov006_02153e54(&entry);
        if (func_020ac2d4(0, &arg2, &entry, 1)) {
            entry.item = arg2;
            entry.unknown_2_1_ = 1;
            func_020ac104(g_fileLoadBuffer, &entry, 1);
            func_ov006_02153e8c(state, &entry);
            if (arg3) {
                Struct_ov006_02153cbc_2* record = func_02071d60(arg3, arg2);
                if (record) record->flags |= 0x400000;
            }
            func_ov006_02154138(state);
        }
    }
    unsigned int count = 0;
    if (func_020ac0b4(&count)) {
        count++;
        if (count > 99999) count = 99999;
        func_020ac08c(&count);
        Struct_ov006_02153cbc_3 work;
        func_020ac4c0(&work);
        func_020a0228(work.unknown_68_, 1);
        func_020ac494(&work);
    }
    BackgroundLoader::RemoveLockGlobal();
}
