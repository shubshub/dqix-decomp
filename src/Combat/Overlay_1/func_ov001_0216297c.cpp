#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" unsigned short GetMainBGVRAMBanks(void);
extern "C" unsigned short GetSubBGVRAMBanks(void);

struct Struct_ov001_0216297c {
    volatile unsigned short unknown_0_;
    volatile unsigned short unknown_2_;
    volatile unsigned short unknown_4_;
    volatile unsigned short unknown_6_;
};

struct Struct_ov001_02165cb8 {
    char pad[0x98];
    volatile unsigned short unknown_98_;
    volatile unsigned short unknown_9a_;
    volatile unsigned short unknown_9c_;
    volatile unsigned short unknown_9e_;
    char pad2[8];
    volatile unsigned short unknown_a8_;
    volatile unsigned short unknown_aa_;
    volatile unsigned short unknown_ac_;
    volatile unsigned short unknown_ae_;
};
extern struct Struct_ov001_02165cb8 data_ov001_02165cb8;

struct Struct_ov001_021658b8_12 {
    char pad[0x494];
    int unknown_494_;
    char pad2[8];
    int unknown_4a0_;
    int unknown_4a4_;
    char pad3[8];
    int unknown_4b0_;
};
extern struct Struct_ov001_021658b8_12 data_ov001_021658b8;

// USA: func_ov001_0216297c
extern "C" ARM int func_ov001_0216297c(void* obj) {
    int r = func_ov017_021d60f4(obj);
    if (r == 0) {
        data_ov001_021658b8.unknown_494_ = GetMainBGVRAMBanks();
        struct Struct_ov001_0216297c* reg = (struct Struct_ov001_0216297c*)0x04000008;
        struct Struct_ov001_02165cb8* dst = &data_ov001_02165cb8;
        volatile short v0, v1, v2, v3;
        {
            unsigned short raw = reg->unknown_0_;
            v0 = raw; v0;
            dst->unknown_98_ = raw; v0;
        }
        {
            unsigned short raw = reg->unknown_2_;
            dst->unknown_9a_ = raw;
            v1 = raw; v1;
        }
        {
            unsigned short raw = reg->unknown_4_;
            v2 = raw; v2;
            dst->unknown_9c_ = raw; v2;
        }
        {
            unsigned short raw = reg->unknown_6_;
            v3 = raw;
            dst->unknown_9e_ = raw;
            v3;
        }
        data_ov001_021658b8.unknown_4a0_ = (*(volatile unsigned int*)0x04000000 & 0x1f00) >> 8;
    } else if (r == 1) {
        data_ov001_021658b8.unknown_4a4_ = GetSubBGVRAMBanks();
        struct Struct_ov001_0216297c* reg = (struct Struct_ov001_0216297c*)0x04001008;
        struct Struct_ov001_02165cb8* dst = &data_ov001_02165cb8;
        volatile short v0, v1, v2, v3;
        {
            unsigned short raw = reg->unknown_0_;
            v0 = raw;
            dst->unknown_a8_ = raw;
            v0;
        }
        {
            unsigned short raw = reg->unknown_2_;
            dst->unknown_aa_ = raw;
            v1 = raw; v1;
        }
        {
            unsigned short raw = reg->unknown_4_;
            v2 = raw; v2;
            dst->unknown_ac_ = raw; v2;
        }
        {
            unsigned short raw = reg->unknown_6_;
            v3 = raw;
            dst->unknown_ae_ = raw;
            v3;
        }
        data_ov001_021658b8.unknown_4b0_ = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
    }
    return 1;
}
