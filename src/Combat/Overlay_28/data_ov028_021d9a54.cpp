#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_ov028_021d977c;
extern "C" void func_ov028_021d977c(struct Struct_ov028_021d977c* obj);
extern "C" void* func_ov028_021d979c(void* obj);
extern "C" void __register_global_object(void* a, void* b, void* c);

extern int data_ov028_021d9b14;
extern int data_ov028_021d9ae0;

// USA: func_ov028_021d9a54
extern "C" __declspec(initcode) ARM void __sinit_ov028_021d9a54(void) {
    func_ov028_021d977c((struct Struct_ov028_021d977c*)&data_ov028_021d9b14);
    __register_global_object(&data_ov028_021d9b14, (void*)func_ov028_021d979c, &data_ov028_021d9ae0);
}
