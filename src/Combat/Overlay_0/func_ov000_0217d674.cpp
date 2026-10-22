#include <globaldefs.h>

struct Struct_ov000_0217d674 {
    char unknown_0_[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
};

struct Struct_ov000_02178d28_2 {
    char unknown_0_[0x68];
    int unknown_68_;
    char unknown_6c_[0x70 - 0x6c];
    signed char unknown_70_[0x17c - 0x70];
    int unknown_17c_;
    char unknown_180_[0x188 - 0x180];
#if defined(jpn)
    char unknown_188_[0x1f98 - 0x188];
#else
    char unknown_188_[0x1d60 - 0x188];
#endif
    unsigned char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[2];
    signed char unknown_1d6b_;
    char unknown_1d6c_[2];
    unsigned char unknown_1d6e_;
    char unknown_1d6f_[3];
    unsigned short unknown_1d72_;
};

struct SePlayer;
struct TableEntry0217f8c0;

extern struct SePlayer g_sePlayer;

struct Struct_0205c570;
int GetActiveScaledSum0205d794(Struct_0205c570*);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
struct Struct0217f8c0;
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
int CountSetBitsLow12_0x68_ov000_0218155c(void*);
struct Struct_0205d81c;
extern "C" void func_ov000_0217a9d0(int, int, int, Struct_0205d81c*);
struct Struct_0205def8;
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" int func_020dd3cc(int arg0);
extern "C" int func_ov000_0217c594(Struct_ov000_02178d28_2* arg0, int arg1);
extern "C" int func_ov000_0217c514(int arg0, int arg1);
extern "C" Struct_ov000_0217d674* func_ov000_02161318(Struct_ov000_02178d28_2* arg0, int arg1);
extern "C" void func_ov000_02175258(Struct_ov000_02178d28_2* arg0);
extern "C" void func_ov000_02176634(Struct_ov000_02178d28_2* arg0, void* arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov000_0217c638(Struct_ov000_02178d28_2* arg0, int arg1, int arg2);

// USA: func_ov000_0217d674
extern "C" ARM void func_ov000_0217d674(MenuState* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    menu->activeSum = GetActiveScaledSum0205d794((Struct_0205c570*)menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        int id = menu->slotIds[menu->activeSum];
        menu->field_0x1d6e = 0;
        menu->field_0x68 = func_020dd3cc(id);
        menu->field_0x68 = func_ov000_0217c514(id, menu->field_0x68);
        if (menu->field_0x68 == 0) {
            menu->depth = menu->depth + 1;
            menu->modeStack[menu->depth] = 0x2b;
            func_ov000_02176634(menu, func_ov000_02161318(menu, menu->currentId), 0x2b, arg1, arg2);
            return;
        }
        arg0->unknown_17c_ = var0;
        Struct_ov000_0217d674* var1 = func_ov000_02161318(arg0, var0);
        if (var1 == NULL) {
            return;
        }
        var1->unknown_10_[var1->unknown_18_] = 1;
        func_ov000_02175258(arg0);
        arg0->unknown_1d68_ = arg0->unknown_1d68_ + 1;
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 6;
        func_ov000_02176634(arg0, func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0), 6, arg1, arg2);
        func_ov000_0217a9d0(6, func_ov000_0218155c(arg0), 4, (Struct_0205d81c*)arg0->unknown_188_);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 0, 1);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 0, 2);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 0, 5);
    } else if (func_ov000_0217c5f4(arg0) != 0) {
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_188_, 0);
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
        arg0->unknown_1d68_ = arg0->unknown_1d68_ - 1;
        func_ov000_0217c638(arg0, arg1, arg2);
    }
}
