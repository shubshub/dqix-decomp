#include <globaldefs.h>

extern "C" void func_ov031_0223cf70(void** slot);
extern "C" ARM void func_ov031_0223d8a0(void* p);
extern "C" void func_ov031_0223bf48(int, void*);
extern char* data_ov031_02290d9c;

// USA: func_ov031_0223e2ec
extern "C" ARM void func_ov031_0223e2ec(int index, void* obj) {
    if (*((unsigned char*)obj + 0x11) != 0) {
        func_ov031_0223cf70((void**)((char*)obj + 0xc));
    }
    func_ov031_0223d8a0(obj);
    int v = *(int*)(data_ov031_02290d9c + index * 0x40);
    func_ov031_0223bf48(v, obj);
}
