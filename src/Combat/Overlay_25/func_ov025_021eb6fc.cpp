#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

struct SePlayer;
struct List02160094;

struct Struct_ov025_021eb6fc {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[0xc];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021e9778_9 {
    char unknown_0_[0x1c4];
    unsigned int unknown_1c4_;
};

void* GetActiveCombatWork_ov000_02160130(void);
void* GetSlotPtr02160f20(void* obj);
Entry021eb6fc* SearchBothTables02079e2c(char* p, int key);
int IsMatchingID02163690(int id);
unsigned char* GetNodeAtIndex02160094(List02160094*, int);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_ov025_021eb6fc
extern "C" ARM void func_ov025_021eb6fc(Struct_ov025_021e9778_9* arg0, int arg1) {
    if ((arg0->unknown_1c4_ & 8) && arg1 == 0) {
        return;
    }
    short* var0 = (short*)func_ov000_02160f20(func_ov000_02160130());
    Struct_ov025_021eb6fc* var1 = func_02079e2c((char*)func_020797dc(), *var0);
    if (func_ov000_02163690(*(unsigned short*)var0)) {
        arg1 = 1;
    } else if (var1 != 0 && var1->unknown_9_0_ == 1 && var1->unknown_18_5_ == 1 && var1->unknown_19_4_ != 2) {
        arg1 = 1;
    }
    if (arg1 != 0) {
        unsigned char* var2 = func_ov000_02160094((Struct_ov000_0215440c_2*)var0, 0);
        if (var2 != 0) {
            int var3 = *(unsigned short*)(var2 + 0x20);
            int var4;
            if (var3 >= 0 && var3 <= 3) {
                var4 = 1;
            } else {
                var4 = 0;
            }
            if (inRange) {
                SePlayer_Play(&g_sePlayer, 7, 0);
            } else {
                SePlayer_Play(&g_sePlayer, 8, 0);
            }
        }
    }
    arg0->unknown_1c4_ |= 8;
}
