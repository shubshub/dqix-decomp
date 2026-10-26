#include <globaldefs.h>

struct Struct_02080fa8;
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);

// USA: func_ov003_0215f5e8
extern "C" ARM void func_ov003_0215f5e8(void* obj, int index, int count) {
    if (count <= 4) {
        return;
    }
    int aligned = count + 3;
    aligned = aligned & ~3u;
    func_02080b40(obj, 0xd3);
    func_02080b40(obj, 0xd4);
    func_02080b40(obj, 0xd5);
    func_02080fa8((struct Struct_02080fa8*)obj, 0xd4, index + 1);
    func_02080fa8((struct Struct_02080fa8*)obj, 0xd5, aligned / 4);
}
