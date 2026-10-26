#include <globaldefs.h>

struct Struct_ov001_02158828;
extern "C" void func_ov001_02158828(struct Struct_ov001_02158828* obj);

struct Struct_ov001_02158e8c {
    char pad[0x30];
    int unknown_30_;
    int f34;
};

// USA: func_ov001_02158e8c
extern "C" ARM void* func_ov001_02158e8c(struct Struct_ov001_02158e8c* obj, struct Struct_ov001_02158828* p1, int mode) {
    if (p1 == NULL) {
        return NULL;
    }
    void* result = *(void**)((char*)p1 + 0x48);
    switch (mode) {
        case 0:
            if (obj->unknown_30_ == 0) {
                func_ov001_02158828(p1);
            }
            break;
        case 1:
            if (obj->f34 == 0) {
                func_ov001_02158828(p1);
            }
            break;
        case 2:
            func_ov001_02158828(p1);
            break;
        default:
            break;
    }
    return result;
}
