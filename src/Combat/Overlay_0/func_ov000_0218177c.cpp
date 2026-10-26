#include <globaldefs.h>

struct Struct_ov000_02160094 {
    char pad0[0x20];
    short id;
};
struct Struct_ov000_0215440c_2;
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);

struct Struct_ov000_021600f8 {
    char pad0[0xe];
    short id;
};
struct Struct_ov000_0215440c;
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

static inline int inline_ov000_02156cc4_2(int id) {
    return id >= 0 && id <= 3;
}

static inline int inline_ov000_0218177c(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// USA: func_ov000_0218177c
extern "C" ARM int func_ov000_0218177c(void* obj, void* list, int arg2, int arg3, int* out) {
    short buf[12];
    int id;
    if (arg2) {
        Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
        if (node == 0) {
            return 0;
        }
        id = node->id;
    } else {
        Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
        if (node == 0) {
            return 0;
        }
        id = node->id;
    }
    int count = 0;
    if (arg3) {
        if (inline_ov000_02156cc4_2(id)) {
            count = func_ov000_0215e9fc(obj, buf, 12, 0);
        } else if (inline_ov000_0218177c(id)) {
            count = func_ov000_0215ec1c(obj, buf, 12, 0);
        }
    } else {
        if (inline_ov000_02156cc4_2(id)) {
            count = func_ov000_0215ec1c(obj, buf, 12, 0);
        } else if (inline_ov000_0218177c(id)) {
            count = func_ov000_0215e9fc(obj, buf, 12, 0);
        }
    }
    for (int i = 0; i < count; i++) {
        out[i] = buf[i];
    }
    return count;
}
