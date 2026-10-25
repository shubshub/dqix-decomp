#include <globaldefs.h>
#include "Resource/GameResources.h"

void* GetField02163524(void* obj);
void* MessageSystem_GetInstance(void);
extern "C" void func_ov000_0216dbf0(void* obj, int a, int b, int c);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void MessageSystem_Stop(void* obj);
void* GetSlotPtr02160f20(void* obj);
struct S021d8a40;
void ProcessPairs_021d8a40(void* obj0, struct S021d8a40* obj1);
void IncrementCounterAndReset_021def30(unsigned char* obj);

struct Struct_ov025_021dbe10 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};
extern "C" struct Struct_ov025_021dbe10 _ZZ21inline_ov025_021dcf14vE1s;

// USA: func_ov025_021dc880
extern "C" ARM void func_ov025_021dc880(unsigned char* arg0) {
    GetGameResources();
    GetField02163524(obj);
    void* global = MessageSystem_GetInstance();

    if (_ZZ21inline_ov025_021dcf14vE1s.unknown_8_ == 0) {
#if defined(jpn)
        func_ov000_0216dbf0(arg0 + 0xb94, 0, 0, 0);
#else
        func_ov000_0216dbf0(arg0 + 0xc18, 0, 0, 0);
#endif
        func_ov000_021626a0(obj, 4, 1);
        MessageSystem_Stop(global);
        _ZZ16GetTimer021ef974vE1s.state = 1;
    }

    if (_ZZ21inline_ov025_021dcf14vE1s.unknown_8_ != 1) {
        return;
    }

    if (++_ZZ21inline_ov025_021dcf14vE1s.unknown_10_ == 15) {
        func_ov025_021d8a40(arg0, (struct Struct_ov025_021d8a40*)func_ov000_02160f20(arg0));
    }
    if (_ZZ21inline_ov025_021dcf14vE1s.unknown_10_ == 60) {
        func_ov025_021def30(arg0);
    }
}
