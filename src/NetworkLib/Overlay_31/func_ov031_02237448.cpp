#include <globaldefs.h>

struct Struct_ov031_02249294 { unsigned int words[17]; };
struct Struct_ov031_02237448_3 {
    void* cache;
    unsigned int unknown_4_;
    unsigned short unknown_8_;
    unsigned char unknown_a_[10];
    unsigned char signature[8];
    unsigned char field_0x1c;
    unsigned char enabled;
    unsigned short field_0x1e;
    unsigned char payload[0x24];
};
struct Struct_ov031_02237448 {
    unsigned char field_0x0[0xf00];
    unsigned char cache[0x400];
    unsigned char unknown_1300_[0x70];
    int value;
    union { Struct_ov031_02237448_3 unknown_1374_; Struct_ov031_02249294 unknown1_1374_; };
    unsigned short status;
    unsigned char unknown_13ba_[0x7ce];
    unsigned long long unknown_1b88_;
    void* callback;
};
struct Struct_ov031_02237448_2 {
    unsigned char header[4];
    unsigned char payload[22];
    unsigned short count;
    unsigned char field_0x1c[0x38];
};
Struct_ov031_02237448* data_ov031_02290d0c __attribute__((aligned(4)));
extern const Struct_ov031_02249294 data_ov031_02249294;
extern const unsigned char data_ov031_02249288[];
extern "C" void* func_ov031_0223cf4c(unsigned int, int);
extern "C" unsigned int func_ov031_0223cf70(void**);
extern "C" void func_ov031_022376fc(void);
extern "C" void func_ov031_022379f0(void);
extern "C" int func_ov031_022375cc(void);
extern "C" void OS_GetOwnerInfo(void*);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
unsigned long long GetCurrentTimestamp(void);
extern "C" int func_020d4f7c(int, int, int);
extern "C" int func_020d4848(void*);
extern "C" unsigned short func_020d4be8(void);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);

// USA: func_ov031_02237448
extern "C" ARM int func_ov031_02237448(int value) {
    Struct_ov031_02237448_2 response;
    data_ov031_02290d0c = (Struct_ov031_02237448*)func_ov031_0223cf4c(0x1ba0, 0x20);
    data_ov031_02290d0c->value = value;
    unsigned long long var1 = GetCurrentTimestamp();
    data_ov031_02290d0c->unknown_1b88_ = var1;
    if (func_020d4f7c((int)data_ov031_02290d0c, (int)func_ov031_022376fc, 3) == 2) {
        Struct_ov031_02237448* state;
        do {
            func_020d4848(&data_ov031_02290d0c->status);
        } while ((state = data_ov031_02290d0c)->status != 2);
        state->unknown1_1374_ = data_ov031_02249294;
        state->unknown_1374_.cache = state->cache;
        data_ov031_02290d0c->unknown_1374_.unknown_8_ = func_020d4be8();
        OS_GetOwnerInfo(&response);
        VectorizedInvertedMemcpy(data_ov031_02249288, data_ov031_02290d0c->unknown_1374_.signature, 8);
        data_ov031_02290d0c->unknown_1374_.enabled = 1;
        VectorizedInvertedMemcpy(response.payload, data_ov031_02290d0c->unknown_1374_.payload, response.count << 1);
        if (func_ov031_022375cc()) {
            data_ov031_02290d0c->callback = func_ov031_0223e218(0, (void*)func_ov031_022379f0, 0, 0x78);
            return 1;
        }
    }
    func_ov031_0223cf70((void**)&data_ov031_02290d0c);
    return 0;
}
