#include <globaldefs.h>

extern "C" void func_ov028_021d9494(void* obj);
extern "C" void func_ov028_021d9530(void* obj, void* alloc);
extern "C" void func_ov028_021d9668(void* obj);

struct Struct_020c93bc;
extern "C" void func_020c93bc(struct Struct_020c93bc* p);
extern "C" void func_020c93d0(void*, int, int, void*, void*);

extern int data_ov028_021d9b14;
extern int data_ov028_021d9aec;

// USA: func_ov028_021d96bc
extern "C" ARM void func_ov028_021d96bc(void* alloc) {
    func_ov028_021d9494(&data_ov028_021d9b14);
    func_ov028_021d9530(&data_ov028_021d9b14, alloc);
    func_020c93bc((struct Struct_020c93bc*)&data_ov028_021d9aec);
    func_020c93d0(&data_ov028_021d9aec, 0xd7, 0x1e, (void*)func_ov028_021d9668, &data_ov028_021d9b14);
}
