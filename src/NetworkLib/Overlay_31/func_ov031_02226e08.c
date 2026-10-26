#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif


void* func_ov031_0223cf4c(unsigned int len, int align);
void func_020ca390(int val, void* dst, unsigned int size);
void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
void OS_GetMacAddress(void* dst);
int func_ov031_0221e7d0(int (*arg0)(int), int (*arg1)(void*));
void HaltSystem(void);
int func_ov031_02226fc8(int size);
int func_ov031_02226fd8(void* p);

typedef union {
    struct {
        unsigned char cmd;
        unsigned short len;
        unsigned char body[0x100];
    };
    unsigned short raw[0x82];
} Struct_ov031_02226e08;

typedef struct {
    unsigned short tag;
    Struct_ov031_02226e08 packet;
    short unknown_106_;
    short unknown_108_;
    short unknown_10a_;
    short unknown_10c_;
    short unknown_10e_;
    unsigned char f110[6];
} Struct_ov031_02226e08_2;

typedef struct {
    unsigned char inUse;
    Struct_ov031_02226e08_2* buf;
} Struct_ov031_02250c04;
extern Struct_ov031_02250c04 data_ov031_02250c04;
extern const unsigned char data_ov031_02248d80[0xc];

// USA: func_ov031_02226e08
ARM void func_ov031_02226e08(void) {
    Struct_ov031_02226e08 packet;

    data_ov031_02250c04.buf = (Struct_ov031_02226e08_2*)func_ov031_0223cf4c(0x26c, 4);
    data_ov031_02250c04.inUse = 0;
    func_020ca390(0, &packet, sizeof(packet));
    packet.cmd = 0x50;
    packet.len = 0xc;
    VectorizedInvertedMemcpy(data_ov031_02248d80, packet.body, 0xc);

    data_ov031_02250c04.buf->tag = 3;
    data_ov031_02250c04.buf->packet = packet;
    data_ov031_02250c04.buf->unknown_106_ = 1;
    data_ov031_02250c04.buf->unknown_108_ = -1;
    data_ov031_02250c04.buf->unknown_10a_ = 1;
    data_ov031_02250c04.buf->unknown_10c_ = -1;
    data_ov031_02250c04.buf->unknown_10e_ = -1;
    OS_GetMacAddress(data_ov031_02250c04.buf->f110);

    if (func_ov031_0221e7d0(func_ov031_02226fc8, func_ov031_02226fd8) != 0) {
        HaltSystem();
    }
}
