#include <globaldefs.h>

struct Struct_02081164;

extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_0208108c(void* obj, int id);
extern "C" void func_02081164(struct Struct_02081164* obj, int id, int value);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_021884cc
extern "C" ARM void func_ov014_021884cc(void* self) {
    short v = *(short*)((char*)self + 0x172);
    short adj = v + 0x10;
    if (v == 9) {
        short v2 = *(short*)((char*)self + 0x174);
        if (v2 >= 0) {
            adj = v2 - 4;
        }
    }
    func_0208103c(*(void**)((char*)self + 0xc0), 0x19, adj);
    func_0208108c(*(void**)((char*)self + 0xc0), 0x19);
    func_02081164(*(struct Struct_02081164**)((char*)self + 0xc0), 3, 1);
    func_02080c68(*(void**)((char*)self + 0xc0), 3, 1);
    func_020813ec(*(void**)((char*)self + 0xc0), 3);
}
