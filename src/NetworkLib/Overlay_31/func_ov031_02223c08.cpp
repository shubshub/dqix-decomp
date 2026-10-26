#include <globaldefs.h>

struct Struct_ov031_02222b0c_4 {
    union {
        unsigned long unknown1_0_;
        struct { unsigned short unknown_0_; unsigned short unknown_2_; };
        struct {
            unsigned long y : 8;
            unsigned long unknown_1_0_ : 2;
            unsigned long objMode : 2;
            unsigned long unknown_1_4_ : 1;
            unsigned long colorMode : 1;
            unsigned long shape : 2;
            unsigned long x : 9;
            unsigned long unknown_3_1_ : 5;
            unsigned long size : 2;
        };
        struct {
            unsigned long unused0 : 28;
            unsigned long unknown_3_4_ : 1;
            unsigned long unknown_3_5_ : 1;
            unsigned long unused1 : 2;
        };
    };
    union {
        struct { unsigned short unknown_4_; unsigned short unknown_6_; };
        unsigned long unknown1_4_;
        struct {
            unsigned long unknown_4_0_ : 10;
            unsigned long priority : 2;
            unsigned long unknown_5_4_ : 4;
            unsigned long unknown_6_0_ : 16;
        };
    };
};
enum Enum_ov031_02223c08 {
    Enum_ov031_02223c08_0 = 0,
    Enum_ov031_02223c08_268435456 = 0x10000000,
    Enum_ov031_02223c08_536870912 = 0x20000000,
    Enum_ov031_02223c08_805306368 = 0x30000000,
    Enum_ov031_02223c08_256 = 0x100,
    Enum_ov031_02223c08_512 = 0x200,
    Enum_ov031_02223c08_768 = 0x300
};
static inline void inline_ov031_02223c08(Struct_ov031_02222b0c_4* entry, Enum_ov031_02223c08 effect, int arg2) {
    if (effect != Enum_ov031_02223c08_256 && effect != Enum_ov031_02223c08_768) {
        entry->unknown1_0_ = (entry->unknown1_0_ & 0xc1fffcff) | effect;
    } else {
        entry->unknown1_0_ = (entry->unknown1_0_ & 0xc1fffcff) | effect | (arg2 << 25);
    }
}
static inline void inline_ov031_02223c08_2(Struct_ov031_02222b0c_4* entry, int priority) {
    entry->unknown_4_ = (unsigned short)((entry->unknown_4_ & ~0xc00) | (priority << 10));
}
struct Struct_ov031_02222ce4;
struct Struct_ov031_02222b0c_3;
struct Struct_ov031_02223c08 { unsigned short x, y, width, height; };
struct Struct_ov031_02223c08_2 {
    Struct_ov031_02222b0c_3* rows[3][4];
    Struct_ov031_02222b0c_4* keys[47];
    Struct_ov031_02222b0c_4* unknown_ec_[4];
    Struct_ov031_02222ce4* unknown_fc_[2];
    Struct_ov031_02222ce4* unknown_104_[4];
    Struct_ov031_02222ce4* cursor;
    void* task;
    unsigned char input;
    unsigned char page;
    signed char unknown_11e_;
    signed char unknown_11f_;
    signed char unknown_120_;
    signed char unknown_121_;
    unsigned char repeatTimer;
    bool unknown_123_;
    bool unknown_124_;
    bool unknown_125_;
};
extern Struct_ov031_02223c08_2* data_ov031_02250bfc;
extern const unsigned char data_ov031_022489bc[4];
extern const unsigned char data_ov031_022489b4[2];
extern unsigned short* data_ov031_0224b430[3];
extern "C" void* func_ov031_0223cf4c(unsigned int, int);
extern "C" Struct_ov031_02222b0c_4* func_ov031_0223be44(int, int);
extern "C" Struct_ov031_02222ce4* func_ov031_0223be70(int, int, int);
extern "C" void func_ov031_0223bab4(Struct_ov031_02222ce4*, int, int, int);
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);
extern "C" Struct_ov031_02222b0c_3* func_ov031_0223c458(int, int, int, int, int*, int);
extern "C" void func_ov031_0223c980(Struct_ov031_02222b0c_3*, int, int, int, int, int, unsigned long, const unsigned short*);
extern "C" Struct_ov031_02222ce4* func_ov031_0223b8c4(int, int, int);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern "C" void func_ov031_02224ca4(int, int, int);
extern "C" void func_ov031_02223ff8(void*);

// USA: func_ov031_02223c08
extern "C" ARM void func_ov031_02223c08() {
    Struct_ov031_02223c08 var0 = {};
    int num;
    int var2;
    int i, j, k;
    unsigned short buf[2];
    var0.width = 17;
    var0.height = 18;
    data_ov031_02250bfc = (Struct_ov031_02223c08_2*)func_ov031_0223cf4c(sizeof(Struct_ov031_02223c08_2), 4);
    data_ov031_02250bfc->input = 0xff;
    data_ov031_02250bfc->unknown_121_ = 0;
    data_ov031_02250bfc->unknown_123_ = 1;
    data_ov031_02250bfc->unknown_124_ = 1;
    for (i = 0; i < 47; ++i) {
        data_ov031_02250bfc->keys[i] = func_ov031_0223be44(0, 0x34);
        inline_ov031_02223c08(data_ov031_02250bfc->keys[i], Enum_ov031_02223c08_512, 0);
        inline_ov031_02223c08_2(data_ov031_02250bfc->keys[i], 3);
    }
    for (i = 0; i < 4; ++i) {
        data_ov031_02250bfc->unknown_ec_[i] = func_ov031_0223be44(0, data_ov031_022489bc[i]);
        inline_ov031_02223c08(data_ov031_02250bfc->unknown_ec_[i], Enum_ov031_02223c08_512, 0);
        inline_ov031_02223c08_2(data_ov031_02250bfc->unknown_ec_[i], 3);
    }
    for (i = 0; i < 2; ++i) {
        data_ov031_02250bfc->unknown_fc_[i] = func_ov031_0223be70(0, data_ov031_022489b4[i], 1);
        func_ov031_0223bab4(data_ov031_02250bfc->unknown_fc_[i], -1, 0x200, 0);
        func_ov031_0223bcc8(data_ov031_02250bfc->unknown_fc_[i], -1, 3);
    }
    buf[1] = 0;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            data_ov031_02250bfc->rows[i][j] = func_ov031_0223c458(0, 28, 2, 0, &num, 0);
            var2 = j * 12;
            var0.x = 0;
            for (k = 0; k < 12;) {
                buf[0] = data_ov031_0224b430[i][var2];
                func_ov031_0223c980(data_ov031_02250bfc->rows[i][j], var0.x,
                    var0.y, var0.width, var0.height, 2, 0x480, buf);
                ++k;
                var0.x += 18;
                ++var2;
            }
            if (i == 0)
                data_ov031_02250bfc->unknown_104_[j] = func_ov031_0223b8c4(0, num, 1);
        }
    }
    data_ov031_02250bfc->cursor = func_ov031_0223be70(0, 0x40, 1);
    func_ov031_0223bab4(data_ov031_02250bfc->cursor, -1, 0x200, 0);
    func_ov031_0223bcc8(data_ov031_02250bfc->cursor, -1, 2);
    data_ov031_02250bfc->task = func_ov031_0223e218(0, (void*)func_ov031_02223ff8, 0, 0x78);
    func_ov031_02224ca4(data_ov031_02250bfc->page, 0, 0xc0);
}
