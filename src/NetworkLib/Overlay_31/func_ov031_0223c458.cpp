#include <globaldefs.h>

struct Struct_ov031_0223c458_2 { unsigned char pad0[4]; int (*unknown_4_)(void*, int); };

struct Struct_ov031_0223c458 {
    unsigned char pad0[0x14];
    Struct_ov031_0223c458_2* unknown_14_;
    unsigned char pad1[0x18 - 0x14 - 4];
    void* unknown1_18_;
    void* field1c;
    int field20;
    int field24;
    int field28;
    short field2c;
    unsigned char pad2[0x2e - 0x2c - 2];
    unsigned char unknown1_2e_;
    unsigned char unknown_2f_;
};

extern "C" void* func_ov031_0223bfa0(int a);
extern "C" int func_ov031_0223db7c(int a, int b, int c, int* out);
extern "C" int func_020b2054(int a, int b);
extern "C" int func_020b1ec0(void* obj, int offset, int b, int c, int flag);

extern void* data_ov031_02290d38;

// USA: func_ov031_0223c458
extern "C" ARM void* func_ov031_0223c458(int a0, int a1, int a2, int a3, void** arg4, int a6) {
    unsigned char* g = (unsigned char*)data_ov031_02290d38;
    Struct_ov031_0223c458* obj = (Struct_ov031_0223c458*)func_ov031_0223bfa0(*(int*)(g + 0x670));

    obj->unknown1_2e_ = (unsigned char)a1;
    obj->unknown_2f_ = (unsigned char)a2;

    int var2;
    obj->field28 = func_ov031_0223db7c(a0, a1 * a2, a3, &var2);
    obj->field2c = (short)var2;

    int r = func_020b2054(a1, a2);
    *arg4 = (void*)r;

    int var4 = var2 << 7;
    int off = (a0 == 1) ? 0x6600000 : 0x6400000;
    func_020b1ec0(obj, off + var4, a1, a2, 4);

    obj->unknown_14_->unknown_4_(obj, 0);

    void* g2 = data_ov031_02290d38;
    obj->unknown1_18_ = obj;
    obj->field1c = (char*)g2 + a6 * 8;
    obj->field20 = 1;
    obj->field24 = 1;
    return obj;
}
