#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif


enum Enum_ov027_021dbdec { Enum_ov027_021dbdec_0 = 0, Enum_ov027_021dbdec_1 = 1 };

struct Struct_ov027_021dbdec {
    int w[0x20];
};

struct Struct_ov027_021dbdec_2 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned char mac[6];
    unsigned char pad10[0x36 - 0x10];
    unsigned short unknown_36_;
    Struct_ov027_021dbdec blk;
};

struct Struct_ov027_021dbdec_3 {
    unsigned char buf[0xc0];
    Struct_ov027_021dbdec_2 msg;
    unsigned char unknown_178_[0x180 - 0xc0 - sizeof(Struct_ov027_021dbdec_2)];
};

typedef void (*Type_0201282c_3)(int, void*);

struct Struct_ov027_021dbdec_4 {
    unsigned char pad0[0x40];
    unsigned char f40[0x400];
    unsigned char f440[0xc4];
    int unknown_504_;
    unsigned char unknown_508_[4];
    unsigned char unknown_50c_;
    unsigned char unknown_50d_[0x518 - 0x50d];
    unsigned short unknown_518_;
    unsigned short unknown_51a_;
    Type_0201282c_3 fn;
    int unknown_520_;
    unsigned char unknown_524_[2];
    unsigned short unknown_526_;
    unsigned short unknown_528_;
    unsigned short unknown_52a_;
    unsigned short unknown_52c_;
    unsigned char unknown_52e_[0x5e0 - 0x52e];
    unsigned short unknown_5e0_;
    unsigned short unknown_5e2_;
    int unknown_5e4_;
    int unknown_5e8_;
    int unknown_5ec_;
    unsigned char unknown_5f0_[0x10];
    Struct_ov027_021dbdec_3 entries[0x10];
};

struct Struct_ov027_021e3400 {
    void* buf;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned char mac[6];
};

struct Struct_ov027_021e33e0_5 {
    unsigned short f0;
    unsigned char pad2[6];
    Struct_ov027_021dbdec_4* ptr;
    unsigned char unknown_c_[0x14];
    Struct_ov027_021e3400 pos;
};

extern Struct_ov027_021e33e0_5 data_ov027_021e33e0;

struct Struct_ov027_021dd8ec_3 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
};

extern Struct_ov027_021dd8ec_3 data_ov027_021dd8ec;
extern Struct_ov027_021e3400 data_ov027_021e3400 __attribute__((aligned(32)));

struct Struct_020d5254;

extern "C" ARM void func_ov027_021dbdec(void* arg);
extern "C" void func_ov027_021dbd7c(void);
extern "C" void func_ov027_021db4e0(int a);
extern "C" int func_ov027_021db430(void);
extern "C" int func_ov027_021db3c0(Struct_ov027_021e3400* pos);
extern "C" void func_ov027_021dcc8c(void);
extern "C" void func_ov027_021dd0cc(int a, int b);
extern "C" int func_020d4770(int a, int b, int c);
extern "C" int func_020d54d0(void* fn, void* a, void* b, int c, unsigned short flag);
extern "C" void func_020ca3b8(const void* src, void* dst, unsigned int len);
extern "C" void HaltSystem(void);

extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
void DMAMemcpySynchronous16Bit(int chan, unsigned int src, unsigned int dst, unsigned int len);
extern "C" int func_020d6ad4(int a, int b, int c, int d, unsigned short e);
extern "C" int func_020d5254(int a, Struct_020d5254* ctx);
extern "C" int func_020d503c(int a);
extern "C" int func_020d57f4(int a, int b, int c, int d, unsigned short e, unsigned short f,
                               unsigned short g, int h, int i, int j, int k);

// USA: func_ov027_021dbdec
extern "C" ARM void func_ov027_021dbdec(void* arg) {
    Struct_ov027_021dbdec_2* msg = (Struct_ov027_021dbdec_2*)arg;
    Struct_ov027_021dbdec_4* obj = data_ov027_021e33e0.ptr;

    switch (msg->f0) {
    case 0:
        if (msg->f2 != 0) {
            obj->fn(0x100, msg);
        } else {
            obj->fn(0x15, msg);
            func_ov027_021dd0cc(0x1d, func_020d6ad4((int)func_ov027_021dbdec,
                data_ov027_021dd8ec.unknown_6_, data_ov027_021dd8ec.f2, data_ov027_021dd8ec.f0,
                data_ov027_021dd8ec.f4));
        }
        return;

    case 0x1d:
        if (msg->f2 != 0) {
            obj->fn(0x100, msg);
        } else {
            data_ov027_021e33e0.pos.buf = obj->f440;
            if (data_ov027_021e33e0.pos.f4 == 0) {
                data_ov027_021e33e0.pos.f4 = 1;
            }
            if (data_ov027_021e33e0.pos.unknown_6_ == 0) {
                data_ov027_021e33e0.pos.unknown_6_ = 0xc8;
            }
            data_ov027_021e33e0.pos.mac[0] = 0xff;
            data_ov027_021e33e0.pos.mac[1] = 0xff;
            data_ov027_021e33e0.pos.mac[2] = 0xff;
            data_ov027_021e33e0.pos.mac[3] = 0xff;
            data_ov027_021e33e0.pos.mac[4] = 0xff;
            data_ov027_021e33e0.pos.mac[5] = 0xff;
            obj->unknown_5e4_ = 1;
            obj->unknown_5e8_ = 1;
            func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                (Struct_020d5254*)&data_ov027_021e3400));
        }
        return;

    case 10:
        if (msg->f2 != 0) {
            obj->fn(0x100, msg);
        } else {
            switch (msg->f8) {
            case 3:
                return;

            case 5: {
                Struct_ov027_021dbdec_3* list = obj->entries;
                int i;
                for (i = 0; i < obj->unknown_5e0_; i++) {
                    int e;
                    int d;
                    int c;
                    int b;
                    int a;
                    e = 0;
                    a = 0;
                    d = 0;
                    c = 0;
                    b = 0;
                    if (msg->mac[0] == list[i].msg.mac[0] && msg->mac[1] == list[i].msg.mac[1]) a = 1;
                    if (a) {
                        if (msg->mac[2] == list[i].msg.mac[2]) b = 1;
                    }
                    if (b) {
                        if (msg->mac[3] == list[i].msg.mac[3]) c = 1;
                    }
                    if (c) {
                        if (msg->mac[4] == list[i].msg.mac[4]) d = 1;
                    }
                    if (d) {
                        if (msg->mac[5] == list[i].msg.mac[5]) e = 1;
                    }
                    if (e) {
                        list[i].msg.unknown_36_ = msg->unknown_36_;
                        list[i].msg.blk = msg->blk;
                        InvalidateDataCacheRange(&obj->entries[i], 0xc0);
                        DMAMemcpySynchronous16Bit(data_ov027_021e33e0.f0, (unsigned int)obj->f440,
                            (unsigned int)&obj->entries[i], 0xc0);
                        obj->unknown_5ec_ = i;
                        goto found;
                    }
                }
                if (i < 0x10) {
                    obj->unknown_5e0_ = i + 1;
                    func_020ca3b8(msg, &list[i].msg, 0xb8);
                    InvalidateDataCacheRange(&obj->entries[i], 0xc0);
                    DMAMemcpySynchronous16Bit(data_ov027_021e33e0.f0, (unsigned int)obj->f440,
                        (unsigned int)&obj->entries[i], 0xc0);
                    obj->unknown_5ec_ = i;
                }
            found:
                obj->fn(4, msg);
                if (obj->unknown_5e4_ == 0) return;
                if (obj->unknown_5e8_ != 0 && func_ov027_021db3c0(&data_ov027_021e3400) == 0) {
                    func_ov027_021dcc8c();
                }
                func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                    (Struct_020d5254*)&data_ov027_021e3400));
                return;
            }

            case 4:
                obj->fn(5, msg);
                if (obj->unknown_5e4_ == 0) return;
                if (obj->unknown_5e8_ != 0 && func_ov027_021db3c0(&data_ov027_021e3400) == 0) {
                    func_ov027_021dcc8c();
                }
                func_ov027_021dd0cc(0xa, func_020d5254((int)func_ov027_021dbdec,
                    (Struct_020d5254*)&data_ov027_021e3400));
                return;

            default:
                obj->fn(0x100, msg);
                return;
            }
        }
        return;

    case 11:
        if (msg->f2 != 0) {
            obj->fn(0x100, msg);
        } else {
            arg = (void*)obj->unknown_520_;
            func_ov027_021dd0cc(0xc, func_020d54d0((void*)func_ov027_021dbdec, arg, 0, 1, 0));
        }
        return;

    case 12:
        if (msg->f2 != 0) {
            obj->unknown_5e0_ = 0;
            obj->fn(0xb, msg);
        } else {
            switch (msg->f8) {
            case 6:
                obj->unknown_52a_ = 0;
                obj->unknown_528_ = 1;
                return;

            case 7:
                obj->unknown_5e2_ = *(unsigned short*)msg->mac;
                obj->fn(6, msg);
                obj->unknown_52a_ = 1;
                if (func_020d4770(1, (int)func_ov027_021dbd7c, 0) != 0) return;
                func_ov027_021dd0cc(0xe, func_020d57f4((int)func_ov027_021dbdec,
                    obj->unknown_504_, obj->unknown_51a_, (int)obj->f40, obj->unknown_518_,
                    obj->unknown_52c_ ? Enum_ov027_021dbdec_0 : Enum_ov027_021dbdec_1, 0, 0, 0, 1, 1));
                return;

            case 9:
                obj->fn(0xa, msg);
                obj->unknown_52a_ = 0;
                obj->unknown_528_ = 0;
                return;

            case 0x1a:
                return;

            default:
                obj->fn(0x100, msg);
                return;
            }
        }
        return;

    case 14:
        switch (msg->f4) {
        case 0xa:
            obj->unknown_528_ = 1;
            if (func_ov027_021db430() != 0) {
                obj->fn(0x19, 0);
            }
            return;

        case 0xc:
            return;

        case 0xd:
            return;

        default:
            obj->fn(0x100, msg);
            return;
        }
        return;

    case 15:
        obj->unknown_50c_ = 0;
        if (msg->f2 == 0) {
            obj->fn(8, msg);
        } else if (msg->f2 == 9) {
            obj->fn(0x29, msg);
        } else {
            obj->fn(0x12, msg);
        }
        if (data_ov027_021e33e0.ptr->unknown_526_ == 0) {
            obj->fn(0x19, 0);
        }
        return;

    case 1:
        if (msg->f2 != 0) {
            obj->unknown_526_ = 0;
            obj->fn(0x100, msg);
        } else {
            obj->unknown_52a_ = 0;
            data_ov027_021e33e0.ptr->unknown_528_ = 0;
            func_ov027_021dd0cc(2, func_020d503c((int)func_ov027_021dbdec));
        }
        return;

    case 2:
        if (msg->f2 != 0) {
            obj->unknown_526_ = 0;
            obj->fn(0x100, msg);
        } else {
            func_ov027_021db4e0((int)msg);
        }
        return;

    case 0x15:
        if (func_ov027_021db430() != 0) {
            obj->fn(0x19, 0);
        }
        return;

    case 0x80:
        switch (msg->f4) {
        case 0x16:
            HaltSystem();
            return;
        case 0x17:
            return;
        default:
            return;
        }
        return;

    default:
        obj->fn(0x100, msg);
        return;
    }
}
