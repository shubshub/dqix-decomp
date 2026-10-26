#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void Window_Update(void* obj, int count);
extern "C" void func_ov023_021ecbe8(void* obj);
extern "C" void func_ov023_021ece9c(void* obj);

struct Struct_ov023_021fe0f0 { unsigned int fn; unsigned int unknown_4_; };
extern struct Struct_ov023_021fe0f0 data_ov023_021fe0f0[];

// USA: func_ov023_021eb43c
extern "C" ARM void func_ov023_021eb43c(void* obj) {
    unsigned int count = GameState::GetInstance()->GetTickCount();
    if (count == 0) count = 1;
    if (*((unsigned char*)obj + 0x431) != 0) {
        Window_Update((char*)obj + 0xc4, count);
    }
    unsigned char idx = *((unsigned char*)obj + 0x431);
    if (data_ov023_021fe0f0[idx].fn == 0) return;
    struct Struct_ov023_021fe0f0* d = &data_ov023_021fe0f0[idx];
    void* base = (char*)obj + ((int)d->unknown_4_ >> 1);
    void (*callback)(void*);
    if (d->unknown_4_ & 1) {
        callback = *(void(**)(void*))((char*)*(void**)base + d->fn);
    } else {
        callback = (void(*)(void*))d->fn;
    }
    callback(base);
    func_ov023_021ecbe8(obj);
    func_ov023_021ece9c(obj);
}
