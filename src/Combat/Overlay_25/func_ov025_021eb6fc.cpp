#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

struct SePlayer;
struct Struct_ov000_0215440c_2;

struct Struct_ov025_021eb6fc {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int kind : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[0xc];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int mode : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021e9778_9 {
    char unknown_0_[0x1c4];
    unsigned int flags;
};

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" Struct_ov025_021eb6fc* func_02079e2c(char* p, int key);
extern "C" int func_ov000_02163690(int id);
extern "C" unsigned char* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_ov025_021eb6fc
extern "C" ARM void func_ov025_021eb6fc(Struct_ov025_021e9778_9* obj, int force) {
    if ((obj->flags & 8) && force == 0) {
        return;
    }
    short* slot = (short*)func_ov000_02160f20(func_ov000_02160130());
    Struct_ov025_021eb6fc* entry = func_02079e2c((char*)func_020797dc(), *slot);
    if (func_ov000_02163690(*(unsigned short*)slot)) {
        force = 1;
    } else if (entry != 0 && entry->kind == 1 && entry->unknown_18_5_ == 1 && entry->mode != 2) {
        force = 1;
    }
    if (force != 0) {
        unsigned char* node = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
        if (node != 0) {
            int id = *(unsigned short*)(node + 0x20);
            int inRange;
            if (id >= 0 && id <= 3) {
                inRange = 1;
            } else {
                inRange = 0;
            }
            if (inRange) {
                SePlayer_Play(&g_sePlayer, 7, 0);
            } else {
                SePlayer_Play(&g_sePlayer, 8, 0);
            }
        }
    }
    obj->flags |= 8;
}
