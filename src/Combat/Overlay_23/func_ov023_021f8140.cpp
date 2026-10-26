#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0204c8f0;
struct Struct_ov023_021f8140 {
    char pad0[0xc];
    unsigned char unknown_c_;
    char pad1[0xe5 - 0xd];
    unsigned char unknown_e5_;
};

extern "C" void WindowPane_Update(void* entry, int arg);
extern "C" void WindowPane_Draw(struct Struct0204c8f0* lr);
extern "C" void func_ov023_021f86fc(void* obj, void* arg);

// USA: func_ov023_021f8140
extern "C" ARM void func_ov023_021f8140(struct Struct_ov023_021f8140* obj, void* arg) {
    if (obj->unknown_c_ & 0x8) return;
    int count = GameState::GetInstance()->GetTickCount();
    WindowPane_Update((char*)obj + 0x20, count);
    WindowPane_Draw((struct Struct0204c8f0*)((char*)obj + 0x20));
    if (!(obj->unknown_e5_ & 0x4)) return;
    func_ov023_021f86fc(obj, arg);
}
