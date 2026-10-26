#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
#include "std_library_functions.h"
extern "C" void Window_ClearLayers(void*);
extern "C" void Window_FlushLayers(void*);
extern "C" void Window_TransferLayers(void*);
#define KINDS_OFFSET 0x1f98
#else
#define KINDS_OFFSET 0x1d60
#endif

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* list, int flag);

struct Struct_ov000_0217c908;
extern "C" int func_ov000_0217f910(struct Struct_ov000_0217c908* battle);
extern "C" int func_ov000_0217f3e4(struct Struct_ov000_0217c908* battle);
extern "C" void func_ov000_0217cb5c(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217ce24(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d324(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d438(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d674(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d87c(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217db4c(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217dcf0(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217de64(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217df08(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e46c(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e558(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e870(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217eb28(struct Struct_ov000_0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_02177038(struct Struct_ov000_0217c908* battle, int mode, int kind, int arg3, int arg4);

struct Struct_ov000_0217c908 {
    char pad0[0x118];
    int dirty;
    char pad1[0x188 - 0x11c];
    char entryList[KINDS_OFFSET - 0x188];
    signed char kinds[8];
    signed char unknown_1d68_;
#if defined(jpn)
    char unknown_1fa1_[0x1faa - 0x1fa1];
    unsigned short flags;
#endif
};

// USA: func_ov000_0217c908
extern "C" ARM void func_ov000_0217c908(struct Struct_ov000_0217c908* battle, int arg1, int arg2) {
    if (func_ov000_0217f910(battle) == 0) {
        Window_ClosePane((struct Entry_0205d6a0*)battle->entryList, 1);
        return;
    }
    switch (battle->kinds[battle->unknown_1d68_]) {
    case 1:
        func_ov000_0217cb5c(battle, arg1, arg2);
        break;
    case 2:
        func_ov000_0217ce24(battle, arg1, arg2);
        break;
    case 3:
        func_ov000_0217d324(battle, arg1, arg2);
        break;
    case 4:
        func_ov000_0217d438(battle, arg1, arg2);
        break;
    case 5:
        func_ov000_0217d674(battle, arg1, arg2);
        break;
    case 6:
        func_ov000_0217d87c(battle, arg1, arg2);
        break;
    case 7:
        func_ov000_0217db4c(battle, arg1, arg2);
        break;
    case 8:
        func_ov000_0217dcf0(battle, arg1, arg2);
        break;
    case 9:
        func_ov000_0217de64(battle, arg1, arg2);
        break;
    case 10:
        func_ov000_0217df08(battle, arg1, arg2);
        break;
    case 11:
        func_ov000_0217e46c(battle, arg1, arg2);
        break;
    case 23:
        func_ov000_0217e558(battle, arg1, arg2);
        break;
    case 25:
        func_ov000_0217e870(battle, arg1, arg2);
        break;
    case 12:
    case 32:
#if defined(jpn)
    case 31:
#endif
    case 41:
    case 42:
    case 43:
        func_ov000_0217eb28(battle, arg1, arg2);
        break;
    }
    if (func_ov000_0217f3e4(battle) != 0) {
        battle->dirty = 1;
    }
    func_ov000_02177038(battle, 0, battle->kinds[battle->unknown_1d68_], arg1, arg2);
#if defined(jpn)
    if (g_keyManager.TestKeysPressed(0x2000) && battle->kinds[battle->unknown_1d68_] != 1) {
        memset(battle->kinds, 0, 8);
        battle->unknown_1d68_ = 0;
        battle->kinds[battle->unknown_1d68_] = 1;
        Window_ClearLayers(battle->entryList);
        Window_FlushLayers(battle->entryList);
        Window_TransferLayers(battle->entryList);
        Window_ClosePane((struct Entry_0205d6a0*)battle->entryList, 1);
        battle->flags |= 2;
    }
#endif
}
