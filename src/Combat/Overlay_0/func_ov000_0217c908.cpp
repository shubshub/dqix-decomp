#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
#include "std_library_functions.h"
extern "C" void _Z18Window_ClearLayersP12Cont0205d1e0(void*);
extern "C" void _Z18Window_FlushLayersP12Cont0205d274(void*);
extern "C" void _Z21Window_TransferLayersP11Obj0205d2bc(void*);
#define KINDS_OFFSET 0x1f98
#else
#define KINDS_OFFSET 0x1d60
#endif

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0* list, int flag);

struct Struct_ov000_0217c908;
extern "C" int func_ov000_0217f910(struct Struct_ov000_0217c908* arg0);
extern "C" int func_ov000_0217f3e4(struct Struct_ov000_0217c908* arg0);
extern "C" void func_ov000_0217cb5c(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217ce24(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217d324(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217d438(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217d674(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217d87c(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217db4c(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217dcf0(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217de64(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217df08(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217e46c(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217e558(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217e870(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217eb28(struct Struct_ov000_0217c908* arg0, int arg1, int arg2);
extern "C" void func_ov000_02177038(struct Struct_ov000_0217c908* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_ov000_0217c908 {
    char unknown_0_[0x118];
    int unknown_118_;
    char unknown_11c_[0x188 - 0x11c];
    char unknown_188_[KINDS_OFFSET - 0x188];
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
#if defined(jpn)
    char unknown_1fa1_[0x1faa - 0x1fa1];
    unsigned short unknown_1faa_;
#endif
};

// USA: func_ov000_0217c908
extern "C" ARM void func_ov000_0217c908(struct Battle0217c908* battle, int arg1, int arg2) {
    if (func_ov000_0217f910(battle) == 0) {
        Window_ClosePane((struct Entry_0205d6a0*)battle->entryList, 1);
        return;
    }
    switch (arg0->unknown_1d60_[arg0->unknown_1d68_]) {
    case 1:
        func_ov000_0217cb5c(arg0, arg1, arg2);
        break;
    case 2:
        func_ov000_0217ce24(arg0, arg1, arg2);
        break;
    case 3:
        func_ov000_0217d324(arg0, arg1, arg2);
        break;
    case 4:
        func_ov000_0217d438(arg0, arg1, arg2);
        break;
    case 5:
        func_ov000_0217d674(arg0, arg1, arg2);
        break;
    case 6:
        func_ov000_0217d87c(arg0, arg1, arg2);
        break;
    case 7:
        func_ov000_0217db4c(arg0, arg1, arg2);
        break;
    case 8:
        func_ov000_0217dcf0(arg0, arg1, arg2);
        break;
    case 9:
        func_ov000_0217de64(arg0, arg1, arg2);
        break;
    case 10:
        func_ov000_0217df08(arg0, arg1, arg2);
        break;
    case 11:
        func_ov000_0217e46c(arg0, arg1, arg2);
        break;
    case 23:
        func_ov000_0217e558(arg0, arg1, arg2);
        break;
    case 25:
        func_ov000_0217e870(arg0, arg1, arg2);
        break;
    case 12:
    case 32:
#if defined(jpn)
    case 31:
#endif
    case 41:
    case 42:
    case 43:
        func_ov000_0217eb28(arg0, arg1, arg2);
        break;
    }
    if (func_ov000_0217f3e4(arg0) != 0) {
        arg0->unknown_118_ = 1;
    }
    func_ov000_02177038(arg0, 0, arg0->unknown_1d60_[arg0->unknown_1d68_], arg1, arg2);
#if defined(jpn)
    if (g_keyManager.TestKeysPressed(0x2000) && battle->kinds[battle->kindIndex] != 1) {
        memset(battle->kinds, 0, 8);
        battle->kindIndex = 0;
        battle->kinds[battle->kindIndex] = 1;
        _Z18Window_ClearLayersP12Cont0205d1e0(battle->entryList);
        _Z18Window_FlushLayersP12Cont0205d274(battle->entryList);
        _Z21Window_TransferLayersP11Obj0205d2bc(battle->entryList);
        Window_ClosePane((struct Entry_0205d6a0*)battle->entryList, 1);
        battle->flags |= 2;
    }
#endif
}
