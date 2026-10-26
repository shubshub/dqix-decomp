#include <globaldefs.h>

struct Struct_020e8994 {
    int field0;
    int field4;
};

extern "C" struct Struct_020e8994 data_020e8994[];

struct Struct_02076ccc {
    char pad[0x130];
    int unknown_130_;
    int unknown_134_;
    char unknown_138_[0x14];
    unsigned int field_14c;
};

// USA: func_02076ccc
extern "C" ARM bool func_02076ccc(void* arg0, int mode) {
    struct Struct_02076ccc* obj = (struct Struct_02076ccc*)arg0;
    if (obj->unknown_130_ == mode) {
        return true;
    }
    struct Struct_020e8994* e = &data_020e8994[mode];
    void* base = (char*)obj + (e->field4 >> 1);
    void* callback;
    if (e->field4 & 1) {
        void** var4 = (void**)*(void**)base;
        callback = *(void**)((char*)var4 + e->field0);
    } else {
        callback = (void*)e->field0;
    }
    if (((int (*)(void*))callback)(base) == 0) {
        return false;
    }
    obj->unknown_134_ = obj->unknown_130_;
    obj->unknown_130_ = mode;
    obj->field_14c = 0;
    return true;
}
