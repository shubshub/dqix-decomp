#include <globaldefs.h>

struct Struct_ov000_0217d674 {
    char pad0[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
};

struct Struct_ov000_02178d28_2 {
    char pad0[0x68];
    int unknown_68_;
    char pad6c[0x70 - 0x6c];
    signed char unknown_70_[0x17c - 0x70];
    int unknown_17c_;
    char unknown_180_[0x188 - 0x180];
#if defined(jpn)
    char elements[0x1f98 - 0x188];
#else
    char elements[0x1d60 - 0x188];
#endif
    unsigned char unknown_1d60_[8];
    signed char depth;
    char unknown_1d69_[2];
    signed char activeSum;
    char unknown_1d6c_[2];
    unsigned char unknown_1d6e_;
    char unknown_1d6f_[3];
    unsigned short flags;
};

struct SePlayer;
struct TableEntry0217f8c0;

extern struct SePlayer g_sePlayer;

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
struct Struct0217f8c0;
extern "C" struct TableEntry0217f8c0* func_ov000_0217f8c0(Struct0217f8c0*);
extern "C" int func_ov000_0217c5f4(void*);
extern "C" int func_ov000_0218155c(void*);
struct Struct_0205d81c;
extern "C" void func_ov000_0217a9d0(int, int, int, Struct_0205d81c*);
struct Struct_0205def8;
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" int func_020dd3cc(int combatantId);
extern "C" int func_ov000_0217c594(Struct_ov000_02178d28_2* menu, int limit);
extern "C" int func_ov000_0217c514(int id, int value);
extern "C" Struct_ov000_0217d674* func_ov000_02161318(Struct_ov000_02178d28_2* menu, int id);
extern "C" void func_ov000_02175258(Struct_ov000_02178d28_2* menu);
extern "C" void func_ov000_02176634(Struct_ov000_02178d28_2* menu, void* entry, int mode, int arg3, int arg4);
extern "C" void func_ov000_0217c638(Struct_ov000_02178d28_2* menu, int arg1, int arg2);

// USA: func_ov000_0217d674
extern "C" ARM void func_ov000_0217d674(Struct_ov000_02178d28_2* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    menu->activeSum = Window_GetSelectedIndex((Struct_0205c570*)menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        int id = menu->unknown_70_[menu->activeSum];
        menu->unknown_1d6e_ = 0;
        menu->unknown_68_ = func_020dd3cc(id);
        menu->unknown_68_ = func_ov000_0217c514(id, menu->unknown_68_);
        if (menu->unknown_68_ == 0) {
            menu->depth = menu->depth + 1;
            menu->unknown_1d60_[menu->depth] = 0x2b;
            func_ov000_02176634(menu, func_ov000_02161318(menu, menu->unknown_17c_), 0x2b, arg1, arg2);
            return;
        }
        menu->unknown_17c_ = id;
        Struct_ov000_0217d674* node = func_ov000_02161318(menu, id);
        if (node == NULL) {
            return;
        }
        node->unknown_10_[node->unknown_18_] = 1;
        func_ov000_02175258(menu);
        menu->depth = menu->depth + 1;
        menu->unknown_1d60_[menu->depth] = 6;
        func_ov000_02176634(menu, func_ov000_0217f8c0((Struct0217f8c0*)menu), 6, arg1, arg2);
        func_ov000_0217a9d0(6, func_ov000_0218155c(menu), 4, (Struct_0205d81c*)menu->elements);
        func_0205def8((Struct_0205def8*)menu->elements, 0, 1);
        func_0205def8((Struct_0205def8*)menu->elements, 0, 2);
        func_0205def8((Struct_0205def8*)menu->elements, 0, 5);
    } else if (func_ov000_0217c5f4(menu) != 0) {
        Window_ClosePane((Entry_0205d6a0*)menu->elements, 0);
        menu->unknown_1d60_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
    }
}
