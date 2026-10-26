#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ab20(int);
extern "C" void func_ov017_021d6148(void* node, float v);

struct Struct_ov001_0215ffc0 { char pad[0x80]; int a, b, c; };

// USA: func_ov001_0215ffc0
extern "C" ARM int func_ov001_0215ffc0(char* obj, int count) {
    char* var0 = obj;
    obj = obj + 8;
    int idx = func_ov017_021d60f4(var0);
    Struct_ov001_0215ffc0* e = (Struct_ov001_0215ffc0*)func_ov001_0215ab20(idx);
    if (e == NULL) return 0;
    float v1 = (float)e->a / 4096.0f;
    float v2 = (float)e->b / 4096.0f;
    float v3 = (float)e->c / 4096.0f;
    if (count >= 2) {
        func_ov017_021d6148(obj, v1);
        obj += 8;
    }
    if (count >= 3) {
        func_ov017_021d6148(obj, v2);
        obj += 8;
    }
    if (count >= 4) {
        func_ov017_021d6148(obj, v3);
    }
    return 1;
}
