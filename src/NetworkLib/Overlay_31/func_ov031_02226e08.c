#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif


void* func_ov031_0223cf4c(unsigned int arg0, int arg1);
void func_020ca390(int val, void* dst, unsigned int size);
void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
void OS_GetMacAddress(void* dst);
int func_ov031_0221e7d0(int (*allocate)(int), int (*release)(void*));
void HaltSystem(void);
int TailCallWith32_02226fc8(int size);
int func_ov031_02226fd8(void* p);

typedef union {
    struct {
        unsigned char unknown_0_;
        unsigned short unknown_2_;
        unsigned char unknown_4_[0x100];
    };
    unsigned short unknown1_0_[0x82];
} Struct_ov031_02226e08;

typedef struct {
    unsigned short unknown_0_;
    Struct_ov031_02226e08 unknown_2_;
    short unknown_106_;
    short unknown_108_;
    short unknown_10a_;
    short unknown_10c_;
    short unknown_10e_;
    unsigned char unknown_110_[6];
} Struct_ov031_02226e08_2;

typedef struct {
    unsigned char unknown_0_;
    Struct_ov031_02226e08_2* unknown_4_;
} Struct_ov031_02250c04;
extern Struct_ov031_02250c04 data_ov031_02250c04;
extern const unsigned char data_ov031_02248d80[0xc];

// USA: func_ov031_02226e08
ARM void func_ov031_02226e08(void) {
    Struct_ov031_02226e08 var0;

    data_ov031_02250c04.unknown_4_ = (Struct_ov031_02226e08_2*)func_ov031_0223cf4c(0x26c, 4);
    data_ov031_02250c04.unknown_0_ = 0;
    func_020ca390(0, &var0, sizeof(var0));
    var0.unknown_0_ = 0x50;
    var0.unknown_2_ = 0xc;
    VectorizedInvertedMemcpy(data_ov031_02248d80, var0.unknown_4_, 0xc);

    data_ov031_02250c04.buf->tag = 3;
    data_ov031_02250c04.buf->packet = packet;
    data_ov031_02250c04.buf->f106 = 1;
    data_ov031_02250c04.buf->f108 = -1;
    data_ov031_02250c04.buf->f10a = 1;
    data_ov031_02250c04.buf->f10c = -1;
    data_ov031_02250c04.buf->f10e = -1;
    OS_GetMacAddress(data_ov031_02250c04.buf->f110);

    if (func_ov031_0221e7d0(TailCallWith32_02226fc8, func_ov031_02226fd8) != 0) {
        HaltSystem();
    }
}
