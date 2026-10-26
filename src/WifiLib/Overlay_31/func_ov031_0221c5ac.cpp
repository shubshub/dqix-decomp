#include <globaldefs.h>

struct Struct_ov031_0221c5ac_2 {
    int state;
};

struct Struct_ov031_0221c5ac_5 {
    int unknown_0_;
    int length;
    int pad8;
    unsigned char data[0x5dc];
};

struct Struct_ov031_0224e6e0_3 {
    int f0;
    void* handle;
    int f8;
    Struct_ov031_0221c5ac_2* status;
    int error;
    Struct_ov031_0221c5ac_5* packet;
    char pad18[0x2c - 0x18];
    unsigned int flags;
    int unknown_30_;
    unsigned int addr;
    unsigned int mask;
};

struct Struct_ov031_0224e700 {
    char pad0[0x1c];
    signed char connected;
};

struct Struct_ov031_0224b070 {
    int unknown_0_;
    int active;
};

struct Struct_ov031_022460dc {
    short unknown_0_;
    short wait;
};

struct Struct_ov031_0221c5ac_3 {
    unsigned char len;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned int addr;
};

struct Struct_ov031_0221c5ac_4 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov031_0221c5ac_6 {
    int head;
    short count;
    short limit;
};

struct Struct_ov031_0221c5ac_7 {
    unsigned int unknown_0_;
    int f4;
    int f8;
    int fc;
    unsigned int unknown_10_;
};

struct Struct_ov031_0221c5ac {
    char pad0[0x106];
    short unknown_106_;
    short unknown_108_;
    short unknown_10a_;
    short unknown_10c_;
    short unknown_10e_;
    char config[6];
    unsigned char state;
};

extern "C" void func_ov031_0221e52c(void* dst, int value, unsigned int length);
extern "C" void func_ov031_0221d008(Struct_ov031_0221c5ac* self);
extern "C" void func_ov031_0221d060(int value);
extern "C" void func_ov031_0221cfdc(void);
extern "C" int func_ov031_0221d384(int id);
extern "C" void func_ov031_0221c4ac(void* arg);
extern "C" int func_ov031_0221e964(void* out);
extern "C" int func_ov031_0221d294(void* handle);
extern "C" void func_ov031_0221ecac(unsigned int arg);
extern "C" int func_ov031_0221d310(void* obj);
extern "C" void* func_ov031_0221c49c(int arg);
extern "C" int func_ov031_0221eadc(void* obj, Struct_ov031_0221c5ac_2* status);
extern "C" int func_ov031_0221e480(unsigned int addr, unsigned int mask, unsigned int arg2);
extern "C" void func_ov031_0221d354(int kind, void* buf, void* config);
extern "C" int func_ov031_0221e5b4(int arg0, int type, int arg2);
extern "C" int func_ov031_0221e5b0(int arg0, int level, int name, void* value, int size);
extern "C" unsigned int func_ov031_0221e5d0(unsigned int value);
extern "C" unsigned short func_ov031_0221e5f8(short value);
extern "C" int func_ov031_0221e5bc(int arg0, Struct_ov031_0221c5ac_3* addr, int size);
extern "C" int func_ov031_0221e5c8(int arg0);
extern "C" int func_ov031_0221e4d8(void);
extern "C" unsigned int func_ov031_0221cfc4(unsigned int a, unsigned int b);
extern "C" int func_ov031_0221dc68(int mode, Struct_ov031_0221c5ac_7* req, void* buf, int arg3);
extern "C" void func_ov031_0221e6d4(Struct_ov031_0221c5ac_6* arg0);
extern "C" void func_ov031_0221e6e0(int head, Struct_ov031_0221c5ac_6* arg1);
extern "C" int func_ov031_0221e54c(int arg0, Struct_ov031_0221c5ac_6* arg1, void* arg2, void* arg3, Struct_ov031_0221c5ac_4* tv);
extern "C" int func_ov031_0221e538(int arg0, void* buf, int size, int flags, Struct_ov031_0221c5ac_3* from, int* arg5);
extern "C" int func_ov031_0221e638(unsigned short value);
extern "C" int func_ov031_0221d3b0(int mode, Struct_ov031_0221c5ac_5* packet, int* arg2, void* buf, int arg4);
extern "C" int func_ov031_0221d06c(void);
extern "C" int func_ov031_0221d078(Struct_ov031_0221c5ac* self);

extern Struct_ov031_022460dc data_ov031_022460dc;
extern Struct_ov031_0224e6e0_3 data_ov031_0224e6e0;
extern int data_ov031_0224e6e4;
extern Struct_ov031_0224b070 data_ov031_0224b070;
extern Struct_ov031_0224e700 data_ov031_0224e700;

static inline Struct_ov031_0221c5ac_2* inline_ov031_0221c5ac_4(void) {
    return (Struct_ov031_0221c5ac_2*)func_ov031_0221c49c(0x58);
}

// USA: func_ov031_0221c5ac
extern "C" THUMB int func_ov031_0221c5ac(Struct_ov031_0221c5ac* self) {
    unsigned char config[0x18] __attribute__((aligned(4)));
    unsigned char info[0x3c];
    Struct_ov031_0221c5ac_7 req;
    Struct_ov031_022460dc var3 = {-1, -1};
    Struct_ov031_022460dc var4 = {0, 0};
    int var5;
    int var6;
    Struct_ov031_0221c5ac_3 from;
    int var8;
    Struct_ov031_0221c5ac_6 var9;
    Struct_ov031_0221c5ac_4 tv;
    Struct_ov031_0221c5ac_3 sa;
    int ret;
    int mode;
    int res;
    unsigned int addr;
    Struct_ov031_0221c5ac_5* packet;
    int var17;
    int var18;
    int var19;
    int result;
    short i;
    short wait;
    int st;
    int var24;

    mode = 0;
    var5 = 1;
    var6 = 0;
    addr = 0;
    func_ov031_0221e52c(config, 0, 0x18);

    var3.unknown_0_ = self->unknown_106_;
    if (var3.unknown_0_ == -1) {
        var3.unknown_0_ = 10;
    }
    var4.unknown_0_ = self->unknown_10a_;
    if (var4.unknown_0_ == -1) {
        var4.unknown_0_ = 10;
    }
    var3.wait = self->unknown_108_;
    if (var3.wait == -1) {
        var3.wait = 100;
    }
    var4.wait = self->unknown_10c_;
    if (var4.wait == -1) {
        var4.wait = 100;
    }
    var19 = self->unknown_10e_;
    if (var19 == -1) {
        var19 = 2000;
    }

    func_ov031_0221d008(self);
    if ((data_ov031_0224e6e0.flags & 1) != 1) {
        func_ov031_0221d060(0x13);
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }

    i = 0;
    func_ov031_0221d384(0);
    wait = var3.wait;
    for (;;) {
        if (data_ov031_0224e6e0.handle != 0) {
            func_ov031_0221c4ac(data_ov031_0224e6e0.handle);
            data_ov031_0224e6e0.handle = 0;
        }
        if (func_ov031_0221e964(&data_ov031_0224e6e4) == -1) {
            self->state = 0xf;
            func_ov031_0221cfdc();
            return -1;
        }
        st = func_ov031_0221d294(data_ov031_0224e6e0.handle);
        if (st == 4) {
            self->state = 2;
            func_ov031_0221cfdc();
            return -1;
        }
        if (st == 0) {
            break;
        }
        if (i >= var3.unknown_0_) {
            self->state = 1;
            func_ov031_0221cfdc();
            return -1;
        }
        func_ov031_0221ecac(wait);
        i++;
    }

    func_ov031_0221d384(1);
    func_ov031_0221e52c(info, 0, 0x3c);
    if (func_ov031_0221d310(info) != 0) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    data_ov031_0224e6e0.status = inline_ov031_0221c5ac_4();
    if (data_ov031_0224e6e0.status == 0) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    func_ov031_0221e52c(data_ov031_0224e6e0.status, 0, 0x58);
    i = 0;
    if (var3.unknown_0_ > 0) {
        do {
            st = func_ov031_0221eadc(info, data_ov031_0224e6e0.status);
            if (st == -1) {
                self->state = 0xf;
                func_ov031_0221cfdc();
                return -1;
            }
            if (st == 0) {
                if (st != 0 || data_ov031_0224e6e0.status->state == 1) {
                    break;
                }
            }
            func_ov031_0221ecac(wait);
            i++;
        } while (i < var3.unknown_0_);
    }
    if (i == var3.unknown_0_) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }

    if (func_ov031_0221e480(0xc0a80b65, 0xffffff00, 0xc0a80b65) != 0) {
        func_ov031_0221d060(0xc);
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    func_ov031_0221cfdc();
    func_ov031_0221d354(3, config, self->config);
    var24 = func_ov031_0221e5b4(2, 2, 0);
    data_ov031_0224b070.unknown_0_ = var24;
    if (var24 < 0) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    if (func_ov031_0221e5b0(var24, 0xffff, 1, &var5, 4) < 0) {
        func_ov031_0221d060(0xb);
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    func_ov031_0221e52c(&sa, 0, 8);
    sa.unknown_1_ = 2;
    sa.addr = func_ov031_0221e5d0(0xc0a80b65);
    sa.unknown_2_ = func_ov031_0221e5f8(0x5790);
    if (func_ov031_0221e5bc(data_ov031_0224b070.unknown_0_, &sa, 8) < 0) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }

    for (;;) {
        packet = data_ov031_0224e6e0.packet;
        func_ov031_0221e52c(&req, 0, 0x14);
        req.unknown_10_ = 0xc0a80b65;
        req.unknown_0_ = 0xc0a80b01;
        var17 = var19 / 1000;
        var18 = var19 % 1000 * 1000;
        for (;;) {
            if (mode == 1 && data_ov031_0224e700.connected != 1) {
                if (data_ov031_0224b070.unknown_0_ != -1) {
                    func_ov031_0221e5c8(data_ov031_0224b070.unknown_0_);
                }
                data_ov031_0224b070.unknown_0_ = -1;
                if (func_ov031_0221e4d8() != 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                data_ov031_0224e6e0.handle = func_ov031_0221c49c(0x58);
                if (data_ov031_0224e6e0.handle == 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                for (;;) {
                    if (data_ov031_0224e6e0.handle != 0) {
                        func_ov031_0221c4ac(data_ov031_0224e6e0.handle);
                        data_ov031_0224e6e0.handle = 0;
                    }
                    ret = func_ov031_0221e964(&data_ov031_0224e6e4);
                    if (ret == -1) {
                        self->state = 0xf;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    st = func_ov031_0221d294(data_ov031_0224e6e0.handle);
                    if (st == 4) {
                        self->state = 2;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    if (st == 0) {
                        break;
                    }
                    if (i >= var3.unknown_0_) {
                        self->state = 1;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    func_ov031_0221ecac(wait);
                    i++;
                }
                if (ret == -1) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                data_ov031_0224e6e0.status = inline_ov031_0221c5ac_4();
                if (data_ov031_0224e6e0.status == 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                func_ov031_0221e52c(data_ov031_0224e6e0.status, 0, 0x58);
                i = 0;
                if (var3.unknown_0_ > 0) {
                    do {
                        st = func_ov031_0221eadc(info, data_ov031_0224e6e0.status);
                        if (st == -1) {
                            self->state = 0xf;
                            func_ov031_0221cfdc();
                            return -1;
                        }
                        if (st == 0) {
                            if (st != 0 || data_ov031_0224e6e0.status->state == 1) {
                                break;
                            }
                        }
                        func_ov031_0221ecac(wait);
                        i++;
                    } while (i < var3.unknown_0_);
                }
                if (i == var3.unknown_0_) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                addr = func_ov031_0221cfc4(data_ov031_0224e6e0.addr, data_ov031_0224e6e0.mask);
                if (func_ov031_0221e480(addr, data_ov031_0224e6e0.mask, addr) != 0) {
                    func_ov031_0221d060(0xc);
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                data_ov031_0224e700.connected = 1;
                func_ov031_0221cfdc();
                var24 = func_ov031_0221e5b4(2, 2, 0);
                data_ov031_0224b070.unknown_0_ = var24;
                if (var24 < 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                if (func_ov031_0221e5b0(var24, 0xffff, 1, &var5, 4) < 0) {
                    func_ov031_0221d060(0xb);
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                func_ov031_0221e52c(&sa, 0, 8);
                sa.unknown_1_ = 2;
                sa.addr = func_ov031_0221e5d0(addr);
                sa.unknown_2_ = func_ov031_0221e5f8(0x5790);
                if (func_ov031_0221e5bc(data_ov031_0224b070.unknown_0_, &sa, 8) < 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
            }

            if (func_ov031_0221dc68(mode, &req, config, data_ov031_0224b070.unknown_0_) == -1) {
                func_ov031_0221d060(mode + 0x1000);
                self->state = 0xf;
                func_ov031_0221cfdc();
                return -1;
            }
            func_ov031_0221e52c(packet, 0, 0x5f8);
            func_ov031_0221e6d4(&var9);
            func_ov031_0221e6e0(data_ov031_0224b070.unknown_0_, &var9);
            tv.unknown_0_ = var17;
            tv.unknown_4_ = var18;
            if (func_ov031_0221e54c(data_ov031_0224b070.unknown_0_ + 1, &var9, 0, 0, &tv) > 0) {
                break;
            }
            if (++var6 > var4.unknown_0_) {
                if (mode == 0) {
                    func_ov031_0221d060(0xf);
                } else if (mode == 1) {
                    func_ov031_0221d060(0x10);
                } else {
                    func_ov031_0221d060(0x11);
                }
                result = -1;
                goto end;
            }
            func_ov031_0221ecac(var4.wait);
        }

        var8 = 8;
        st = func_ov031_0221e538(data_ov031_0224b070.unknown_0_, packet->data, 0x5dc, 0, &from, &var8);
        packet->unknown_0_ = data_ov031_0224b070.unknown_0_;
        packet->length = func_ov031_0221e638(st);
        res = func_ov031_0221d3b0(mode, packet, &var6, config, data_ov031_0224b070.unknown_0_);
        if (res == 100) {
            result = 0;
            goto end;
        }
        if (res == -1) {
            result = -1;
            goto end;
        }
        if (mode != res) {
            if (res == 2) {
                if (data_ov031_0224b070.unknown_0_ != -1) {
                    func_ov031_0221e5c8(data_ov031_0224b070.unknown_0_);
                }
                data_ov031_0224b070.unknown_0_ = -1;
                if (func_ov031_0221e4d8() != 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                i = 0;
                func_ov031_0221d384(4);
                for (;;) {
                    if (data_ov031_0224e6e0.handle != 0) {
                        func_ov031_0221c4ac(data_ov031_0224e6e0.handle);
                        data_ov031_0224e6e0.handle = 0;
                    }
                    if (func_ov031_0221e964(&data_ov031_0224e6e4) == -1) {
                        self->state = 0xf;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    st = func_ov031_0221d294(data_ov031_0224e6e0.handle);
                    if (st == 4) {
                        self->state = 2;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    if (st == 0) {
                        break;
                    }
                    if (i >= var3.unknown_0_) {
                        self->state = 1;
                        func_ov031_0221cfdc();
                        return -1;
                    }
                    func_ov031_0221ecac(wait);
                    i++;
                }
                data_ov031_0224e6e0.status = inline_ov031_0221c5ac_4();
                if (data_ov031_0224e6e0.status == 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                func_ov031_0221e52c(data_ov031_0224e6e0.status, 0, 0x58);
                i = 0;
                if (var3.unknown_0_ > 0) {
                    do {
                        st = func_ov031_0221eadc(info, data_ov031_0224e6e0.status);
                        if (st == -1) {
                            self->state = 0xf;
                            func_ov031_0221cfdc();
                            return -1;
                        }
                        if (st == 0) {
                            if (st != 0 || data_ov031_0224e6e0.status->state == 1) {
                                break;
                            }
                        }
                        func_ov031_0221ecac(wait);
                        i++;
                    } while (i < var3.unknown_0_);
                }
                if (i == var3.unknown_0_) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                if (func_ov031_0221e480(addr, data_ov031_0224e6e0.mask, addr) != 0) {
                    func_ov031_0221d060(0xc);
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                func_ov031_0221cfdc();
                var24 = func_ov031_0221e5b4(2, 2, 0);
                data_ov031_0224b070.unknown_0_ = var24;
                if (var24 < 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                if (func_ov031_0221e5b0(var24, 0xffff, 1, &var5, 4) < 0) {
                    func_ov031_0221d060(0xb);
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
                func_ov031_0221e52c(&sa, 0, 8);
                sa.unknown_1_ = 2;
                sa.addr = func_ov031_0221e5d0(addr);
                sa.unknown_2_ = func_ov031_0221e5f8(0x5790);
                if (func_ov031_0221e5bc(data_ov031_0224b070.unknown_0_, &sa, 8) < 0) {
                    self->state = 0xf;
                    func_ov031_0221cfdc();
                    return -1;
                }
            }
            mode = res;
            continue;
        }
        mode = res;
        if (var6 > var4.unknown_0_) {
            if (mode == 0) {
                func_ov031_0221d060(0xf);
            } else if (mode == 1) {
                func_ov031_0221d060(0x10);
            } else {
                func_ov031_0221d060(0x11);
            }
            result = -1;
            goto end;
        }
        func_ov031_0221ecac(var4.wait);
    }

end:
    if (data_ov031_0224b070.unknown_0_ != -1) {
        func_ov031_0221e5c8(data_ov031_0224b070.unknown_0_);
    }
    data_ov031_0224b070.unknown_0_ = -1;
    if (func_ov031_0221e4d8() != 0) {
        self->state = 0xf;
        func_ov031_0221cfdc();
        return -1;
    }
    if (result != 0) {
        unsigned char code;
        switch (func_ov031_0221d06c()) {
        case 15:
            code = 3;
            break;
        case 16:
            code = 4;
            break;
        case 17:
            code = 5;
            break;
        case 20:
            code = 7;
            break;
        case 21:
            code = 8;
            break;
        default:
            code = 0xf;
            break;
        }
        self->state = code;
        func_ov031_0221cfdc();
        return -1;
    }
    if (func_ov031_0221d078(self) != 0) {
        self->state = 6;
        func_ov031_0221cfdc();
        return -1;
    }
    return 0;
}
