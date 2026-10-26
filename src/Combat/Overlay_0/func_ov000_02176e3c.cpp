#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xc5];
    unsigned char flags;
};

struct BattleMenu {
    char pad0[0x118];
    int mode;
    char unknown_11c_[0x188 - 0x11c];
    char elements[1];
};

extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c* list, int key);
extern "C" void func_ov000_02177330(void*);
extern "C" void func_ov000_02177558(void*);
extern "C" void func_ov000_02177798(void*);
extern "C" void func_ov000_02177a7c(void*);
extern "C" void func_ov000_02177cb8(void*);
extern "C" void func_ov000_02177f28(void*);
extern "C" void func_ov000_0217819c(void*);
extern "C" void func_ov000_021785fc(void*);
extern "C" int func_ov000_0217542c(void*);
extern "C" void func_ov000_02176498(void* obj, int flag);
extern "C" void func_ov000_021788d8(void*, int, int);
extern "C" void func_ov000_02178cbc(void* menu, int a, int b);
extern "C" void func_ov000_02179128(void* menu, int a, int b);
extern "C" void func_ov000_021795e0(void* menu, int a, int b);
extern "C" void func_ov000_02179a14(void*, int, int);
extern "C" void func_ov000_02179c6c(void*, int);
extern "C" void func_ov000_0217a0a4(BattleMenu* menu, int a);
extern "C" void func_ov000_0217a628(void*, int, int);

// USA: func_ov000_02176e3c
extern "C" ARM void func_ov000_02176e3c(BattleMenu* menu, int arg, int slot, int arg3, int arg4, unsigned char highlight) {
    Elem_0205d81c* elem = func_0205d81c(
        (Struct_0205d81c*)menu->elements, (unsigned char)slot);
    if (elem == 0) {
        return;
    }
    int var1 = menu->mode;
    int var2 = (elem->flags & 2) ? 1 : 0;
    menu->mode = 1;
    if (var2) {
        menu->mode = 2;
    }
    if (highlight) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    switch (slot) {
    case 1:
        func_ov000_02177330(menu);
        break;
    case 2:
        func_ov000_02177558(menu);
        break;
    case 3:
        func_ov000_02177798(menu);
        break;
    case 4:
        func_ov000_02177a7c(menu);
        break;
    case 5:
        func_ov000_02177cb8(menu);
        break;
    case 6:
        func_ov000_02177f28(menu);
        break;
    case 7:
        func_ov000_0217819c(menu);
        break;
    case 8:
        func_ov000_021785fc(menu);
        break;
    case 13:
        if (arg != 0) {
            func_ov000_02176498((void*)arg, func_ov000_0217542c(menu));
        }
        break;
    case 14:
        func_ov000_021788d8(menu, arg, arg4);
        break;
    case 15:
        func_ov000_02178cbc(menu, arg3, arg4);
        break;
    case 16:
        func_ov000_02179128(menu, arg3, arg4);
        break;
    case 17:
        func_ov000_021795e0(menu, arg3, arg4);
        break;
    case 18:
    case 19:
    case 20:
        func_ov000_02179a14(menu, arg, arg3);
        break;
    case 21:
        func_ov000_02179c6c(menu, arg);
        break;
    case 23:
        func_ov000_0217a0a4(menu, arg);
        break;
    case 25:
        func_ov000_0217a628(menu, arg, arg4);
        break;
    }
    menu->mode = var1;
}
