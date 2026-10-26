#include <globaldefs.h>

struct Struct_ov031_02290ca0_8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    struct Struct_ov031_0222f6f8* ctx;
};

struct Struct_ov031_0222f6f8 {
    void* field0;
    void* pad4;
    void* field8;
    void* unknown_c_[2];
    void* unknown_14_;
    void* unknown_18_[7];
    void* field34;
    void* unknown_38_;
    void* field3c;
    unsigned char field40;
};

extern struct Struct_ov031_02290ca0_8 data_ov031_02290ca0;
extern int data_ov031_0224bb64;
extern void* data_ov031_02290ca8;

extern "C" int func_ov031_0223c054(int);
extern "C" ARM int func_ov031_0223e2e0(int, void*);
extern "C" int func_ov031_0223da58(void* obj);
extern "C" void func_ov031_022238cc(void);
extern "C" void* func_ov031_0223c7c4(int idx);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_02234f08(void);
extern "C" void func_ov031_0223b710(void* a);
extern "C" void func_ov031_022234d8(int a0, void (*cb)(int, int, unsigned int));
extern "C" void func_ov031_0223cbbc(int channel, int mask);
extern "C" unsigned int func_ov031_0223cf70(void** a);
extern "C" void func_ov031_02235194(void);

extern "C" void LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" int func_ov031_0221b158(void* p);
extern "C" char* func_ov031_02235c70(void);
extern "C" void func_ov031_02236094(int a);
extern "C" void* VectorizedMemset(void* dst, int val, int n);
extern "C" void func_ov031_0222750c(int, int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222cbe0(void);
extern "C" void func_ov031_0222d720(void);
extern "C" void func_ov031_02233a00(void);
extern "C" void func_ov031_02230f00(void);
extern "C" void func_ov031_02232508(void);
extern "C" void func_ov031_02233248(void);

// USA: func_ov031_0222f6f8
extern "C" ARM void func_ov031_0222f6f8(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;

    func_ov031_0223e2e0(0, data_ov031_02290ca0.ctx->field0);
    func_ov031_0223e2e0(1, data_ov031_02290ca0.ctx->field3c);

    int i = 0;
    do {
        void* p = data_ov031_02290ca0.ctx->unknown_18_[i];
        func_ov031_0223da58(p);
        i++;
    } while (i < 7);
    if (data_ov031_02290ca0.ctx->field34 != 0) {
        func_ov031_0223da58(data_ov031_02290ca0.ctx->field34);
    }

    func_ov031_02235194();
    func_ov031_0223c7c4(0);
    func_ov031_022238cc();

    if (data_ov031_02290ca0.ctx->field40 != 0xc) func_ov031_02223440();

    func_ov031_02234f08();
    func_ov031_0223b710(data_ov031_02290ca0.ctx->field8);

    int j = 0;
    do {
        void* p = data_ov031_02290ca0.ctx->unknown_c_[j];
        func_ov031_0223b710(p);
        j++;
    } while (j < 2);

    func_ov031_022234d8((int)&data_ov031_0224bb64, LoadToMainObjStandardPalette);

    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x1d);

    *(volatile unsigned int*)0x4000010 = 0;
    *(volatile unsigned int*)0x4000018 = 0;
    *(volatile unsigned short*)0x400000c = (*(volatile unsigned short*)0x400000c & 0x43) | 0xe10;

    int flag = 0;
    switch (data_ov031_02290ca0.ctx->field40) {
    case 0:
    case 1:
        func_ov031_0222750c(data_ov031_02290ca0.ctx->field40, flag);
        func_ov031_022274d0(2, 0);
        func_ov031_022274c0((int)func_ov031_0222cbe0);
        break;
    case 4: case 5: case 6: case 9: case 10: {
        unsigned int v = data_ov031_02290ca0.ctx->field40;
        int r4 = v - 4;
        if (v >= 9) r4 -= 2;
        func_ov031_022274d0(2, 0);
        func_ov031_0222750c(r4, 0);
        func_ov031_022274c0((int)func_ov031_0222d720);
        break;
    }
    case 11: {
        unsigned char* base = (unsigned char*)func_ov031_02235c70();
        int bits = func_ov031_0221b158(base + 0xf0);
        base[0xd0] = (unsigned char)bits;
        if (base[0xf5] != 0) {
            VectorizedMemset(base + 0xc0, 0, 4);
            VectorizedMemset(base + 0xc4, 0, 4);
            VectorizedMemset(base + 0xf0, 0, 4);
            base[0xd0] = 0;
        }
        if (base[0xf6] != 0) {
            VectorizedMemset(base + 0xc8, 0, 8);
        }
        func_ov031_022274d0(2, 0);
        func_ov031_0222750c(0, 0);
        func_ov031_022274c0((int)func_ov031_02233a00);
        break;
    }
    case 12:
        func_ov031_022274d0(flag, flag);
        func_ov031_022274c0((int)func_ov031_02230f00);
        break;
    case 13:
        if (data_ov031_02290ca0.unknown_1_ == 0) {
            flag = 1;
            func_ov031_022274d0(2, flag);
            func_ov031_022274c0((int)func_ov031_02232508);
        } else {
            func_ov031_02236094(((unsigned char*)func_ov031_02235c70())[0xf4]);
            flag = 1;
            func_ov031_022274d0(0, flag);
            func_ov031_022274c0((int)func_ov031_02233248);
        }
        break;
    }

    func_ov031_0223cf70((void**)&data_ov031_02290ca8);
}
