#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov015_02190d7c { char pad[0x1a8]; int arr[32]; int count; };
extern "C" ARM void func_ov015_021931b4(struct Struct_ov015_02190d7c* s, int v);

struct Struct_ov015_021900dc {
    void* ptr0;
    char unknown_4_[0x38 - 0x4];
    short field38;
    char unknown_3a_[0x4c - 0x3a];
    int field4c;
};
extern "C" ARM void func_ov015_021900dc(struct Struct_ov015_021900dc* obj);

extern "C" void func_ov015_02192700(void* obj, int flag);

// USA: func_ov015_02191ba0
extern "C" ARM void func_ov015_02191ba0(void* obj, int count) {
    void* cur = *(void**)((char*)obj + 0x2c);
    if (cur == 0) {
        return;
    }
    int i;
    for (i = 0; i < count; i++) {
        cur = *(void**)((char*)cur + 4);
    }
    if (cur == 0) {
        return;
    }
    *(void**)((char*)obj + 0x30) = *(void**)cur;
    unsigned char state = *(unsigned char*)((char*)*(void**)cur + 0x1c);
    switch (state) {
    case 0:
    case 1:
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)obj, *(int*)((char*)obj + 0x1a4));
        *(int*)((char*)obj + 0x1a4) = 0x22;
        func_ov015_02192700(obj, 0);
        return;
    case 2:
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)obj, *(int*)((char*)obj + 0x1a4));
        *(int*)((char*)obj + 0x1a4) = 0x21;
        func_ov015_02192700(obj, 0);
        return;
    default:
        *(int*)((char*)obj + 0x194) = 1;
        func_ov015_02192700(obj, 0);
        *(unsigned short*)((char*)*(void**)((char*)obj + 0x30) + 0x38) = 0;
        func_ov015_021900dc((struct Struct_ov015_021900dc*)*(void**)((char*)obj + 0x30));
        return;
    }
}
