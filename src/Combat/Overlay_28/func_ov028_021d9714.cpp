#include <globaldefs.h>

extern int data_ov028_021d9aec;
extern int data_ov028_021d9b14;
struct Struct_020c949c;
extern "C" void func_020c949c(Struct_020c949c*);
extern "C" void func_ov028_021d94e4(void* p);

// USA: func_ov028_021d9714
extern "C" ARM void func_ov028_021d9714(void) {
    func_020c949c((Struct_020c949c*)&data_ov028_021d9aec);
    func_ov028_021d94e4(&data_ov028_021d9b14);
}
