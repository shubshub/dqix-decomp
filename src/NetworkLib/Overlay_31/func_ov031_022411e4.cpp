#include <globaldefs.h>

extern "C" void (* volatile data_ov031_02290fc8)(void*);
extern "C" void* (* volatile data_ov031_02290fc4)(int, int);
extern "C" int func_ov031_022410d8(void* obj, void* arg1, int* out);
extern "C" void func_ov031_022406f8(void* obj, void* p, int a, int b);
extern "C" int func_ov031_02241534(const char* a, const char* b);
extern const char data_ov031_0224c784[];

struct Struct_ov031_022411e4 {
    unsigned char pad0[0x8];
    int field8;
    unsigned char pad12[8];
    void* field14;
};

// USA: func_ov031_022411e4
extern "C" ARM int func_ov031_022411e4(Struct_ov031_022411e4* obj, void* arg1, void** out) {
    if (obj->field8 == 0) return -1;
    if (obj->field14) {
        data_ov031_02290fc8(obj->field14);
        obj->field14 = 0;
    }
    int local;
    int v = func_ov031_022410d8(obj, arg1, &local);
    if (v >= 0) {
        void* p = data_ov031_02290fc4(v + 1, 4);
        obj->field14 = p;
        *((char*)p + v) = 0;
        func_ov031_022406f8(obj, obj->field14, local, v);
        *out = obj->field14;
        return v;
    }
    int r = func_ov031_02241534(data_ov031_0224c784, (const char*)arg1);
    if (r != 0) return -1;
    void* p = data_ov031_02290fc4(4, 4);
    obj->field14 = p;
    *((char*)p + 3) = 0;
    func_ov031_022406f8(obj, obj->field14, 9, 3);
    *out = obj->field14;
    return 3;
}
