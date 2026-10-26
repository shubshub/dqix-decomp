#include <globaldefs.h>

extern "C" int func_ov031_0223d414(void* data);
extern "C" int func_ov031_0223d69c(void* out);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02235488(int level);
extern "C" void func_ov031_02235744(int a);

extern int data_ov031_022493b8;
extern unsigned char data_ov031_022491f4[];

struct Struct_ov031_022353b8 {
    char pad0[0x10];
    unsigned short field10;
    char unknown_12_[0x16 - 0x12];
    unsigned short unknown_16_;
    unsigned char field18;
    unsigned char unknown_19_;
    char pad1a;
    unsigned char unknown_1b_;
    unsigned char field1c;
    unsigned char unknown_1d_;
};

extern Struct_ov031_022353b8* data_ov031_02290cf4;

// USA: func_ov031_022353b8
extern "C" ARM void func_ov031_022353b8(void) {
    unsigned short buf[2];

    if (!func_ov031_0223d414(&data_ov031_022493b8)) {
        goto fail;
    }

    func_ov031_0223d69c(buf);

    {
        Struct_ov031_022353b8* p = data_ov031_02290cf4;
        if (buf[0] < p->field10 - 0x1e) {
            goto fail;
        }

        int diff = buf[1] - p->unknown_16_;
        int level = p->field18 + diff;
        if (level < 0) {
            level = 0;
        } else {
            unsigned char var4 = data_ov031_022491f4[p->unknown_1b_];
            int var5 = p->unknown_19_ - var4;
            if (level >= var5) level = var5;
        }

        func_ov031_02235488(level);
        func_ov031_02235744(level);
        data_ov031_02290cf4->unknown_1d_ = 2;
        return;
    }

fail:
    func_ov031_022368e0();
    data_ov031_02290cf4->field1c = 0;
    data_ov031_02290cf4->unknown_1d_ = 3;
}
