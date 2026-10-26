#include <globaldefs.h>
#include "Input/Input.h"

#pragma define_section initcode ".init" RX

extern "C" KeyManager* _ZN10KeyManagerC1Ev(KeyManager* self);
extern "C" KeyManager* _ZN10KeyManagerD1Ev(KeyManager* self);
extern "C" TouchInput* _ZN10TouchInputC1Ev(TouchInput* self);
extern "C" TouchInput* _ZN10TouchInputD1Ev(TouchInput* self);
extern "C" void func_02046724(int* field);
extern "C" void __register_global_object(void* obj, void* dtor, void* node);

extern int data_02114e04;
extern int data_02114e08;
extern int data_02114e14;

// KEEP-NAME: the ROM symbol here is the compiler-emitted static-init name, not a func_ tag.
// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void __sinit_020e66a0(void) {
    _ZN10KeyManagerC1Ev(&g_keyManager);
    __register_global_object(&g_keyManager, (void*)_ZN10KeyManagerD1Ev, &data_02114e14);
    _ZN10TouchInputC1Ev(&g_touchInput);
    __register_global_object(&g_touchInput, (void*)_ZN10TouchInputD1Ev, &data_02114e08);
    func_02046724(&data_02114e04);
}
