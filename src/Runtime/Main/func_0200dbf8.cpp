#include <globaldefs.h>

struct Struct_0200d958_2 {
    void* location;
    void* unknown_4_;
    void* dtor;
    void* unknown_c_;
    long unknown_10_;
    void* unknown_14_;
};

struct Struct_0200d958 {
    unsigned long unknown_0_[16];
    char* unknown_40_;
    unsigned long unknown_44_;
    unsigned long unknown_48_;
    unsigned short unknown_4c_;
    bool unknown_4e_;
    bool unknown_4f_;
    bool unknown_50_;
};

struct Struct_0200d958_3 {
    unsigned char* unknown_0_;
    void* location;
    void* dtor;
    Struct_0200d958_2* unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
    char* fp;
    Struct_0200d958 target;
};

struct Struct_0200dbf8 {
    char* unknown_0_;
    char* unknown_4_;
    char* unknown_8_;
    void* unknown_c_;
    void* unknown_10_;
    int target;
};

struct Struct_0200dbf8_2 {
    Struct_0200dbf8 info;
    Struct_0200d958_3 context;
};

struct Struct_0200d958_4 {
    long offset;
    unsigned long base;
};

extern "C" char* func_0200f1a0(Struct_0200d958_3* context, Struct_0200dbf8* info);
extern "C" void func_0200dad4(char* arg0, Struct_0200dbf8* info);
extern "C" void func_0200f1fc(Struct_0200d958_3* context, Struct_0200dbf8* info);
extern "C" char* func_0200d958(char* p, long* value);
extern "C" char* func_0200d9e4(char* p, unsigned long* value);

static inline char* inline_0200dbf8(char* p) {
    long local;
    p = func_0200d958(p + 1, &local);
    return p + 4;
}

static inline char* inline_0200dbf8_2(char* p) {
    long local, cond;
    p = func_0200d958(p + 1, &local);
    p = func_0200d958(p, &cond);
    return p + 4;
}

static inline char* inline_0200dbf8_3(char* p) {
    long pointer;
    p = func_0200d958(p + 1, &pointer);
    return p + 4;
}

static inline char* inline_0200dbf8_4(char* p) {
    long var0;
    unsigned long elements, var2;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d9e4(p, &elements);
    p = func_0200d9e4(p, &var2);
    return p + 4;
}

static inline char* inline_0200dbf8_5(char* p) {
    long var0, offset;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &offset);
    return p + 4;
}

static inline char* inline_0200dbf8_6(char* p) {
    long var0, offset;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &offset);
    return p + 4;
}

static inline char* inline_0200dbf8_7(char* p) {
    long var0, cond, offset;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &cond);
    p = func_0200d958(p, &offset);
    return p + 4;
}

static inline char* inline_0200dbf8_8(char* p) {
    long var0, offset;
    unsigned long elements, var3;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &offset);
    p = func_0200d9e4(p, &elements);
    p = func_0200d9e4(p, &var3);
    return p + 4;
}

static inline char* inline_0200dbf8_9(char* p) {
    long var0;
    p = func_0200d958(p + 1, &var0);
    return p + 4;
}

static inline char* inline_0200dbf8_10(char* p) {
    long var0, cond;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &cond);
    return p + 4;
}

static inline char* inline_0200dbf8_11(char* p) {
    unsigned long var0;
    long var1;
    p = func_0200d9e4(p + 5, &var0);
    p = func_0200d958(p, &var1);
    return p;
}

static inline char* inline_0200dbf8_12(char* p) {
    long var0;
    p = func_0200d958(p + 1, &var0);
    return p;
}

static inline char* inline_0200dbf8_13(char* p) {
    unsigned long var0, var1;
    long var2;
    p = func_0200d9e4(p + 1, &var0);
    p = func_0200d9e4(p, &var1);
    p = func_0200d958(p, &var2);
    return p + var0 * sizeof(void*);
}

static inline char* inline_0200dbf8_14(char* p) {
    long var0, offset;
    Struct_0200d958_4 var2;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &offset);
    var2.base = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    p = func_0200d958(p + 4, &var2.offset);
    return p + 4;
}

static inline char* inline_0200dbf8_15(char* p) {
    long var0, var1, objectOffset, var3;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p, &objectOffset);
    p = func_0200d958(p + 1, &var1);
    p = func_0200d958(p, &var3);
    return p + 4;
}

static inline char* inline_0200dbf8_16(char* p) {
    long var0, var1;
    unsigned long var2;
    p = func_0200d958(p + 1, &var0);
    p = func_0200d958(p + 1, &var1);
    p = func_0200d9e4(p, &var2);
    return p + 4;
}

static inline char* inline_0200dbf8_17(char* p) {
    long value;
    p = func_0200d958(p + 1, &value);
    return p;
}

static inline void inline_0200dbf8_18(Struct_0200dbf8* info) {
    long target;
    func_0200d958(info->unknown_8_ + 1, &target);
    info->unknown_8_ += target;
}

// USA: func_0200dbf8
extern "C" ARM unsigned char func_0200dbf8(Struct_0200dbf8_2* arg0) {
    char* p;
    unsigned char action;

    for (;;) {
        if ((p = arg0->info.unknown_8_) == 0 || ((action = *p) & 0x80) != 0) {
            func_0200dad4(func_0200f1a0(&arg0->context, &arg0->info), &arg0->info);
            if (arg0->info.unknown_4_ == 0)
                return 0xff;
            func_0200f1fc(&arg0->context, &arg0->info);
            if (arg0->info.unknown_8_ != 0)
                break;
        } else {
            switch (action & 0x1f) {
                case 2: arg0->info.unknown_8_ = inline_0200dbf8(p); break;
                case 3: arg0->info.unknown_8_ = inline_0200dbf8_2(p); break;
                case 4: arg0->info.unknown_8_ = inline_0200dbf8_3(p); break;
                case 5: arg0->info.unknown_8_ = inline_0200dbf8_4(p); break;
                case 6: arg0->info.unknown_8_ = inline_0200dbf8_5(p); break;
                case 7: arg0->info.unknown_8_ = inline_0200dbf8_6(p); break;
                case 8: arg0->info.unknown_8_ = inline_0200dbf8_7(p); break;
                case 9: arg0->info.unknown_8_ = inline_0200dbf8_8(p); break;
                case 10: arg0->info.unknown_8_ = inline_0200dbf8_9(p); break;
                case 11: arg0->info.unknown_8_ = inline_0200dbf8_10(p); break;
                case 12: arg0->info.unknown_8_ = inline_0200dbf8_11(p); break;
                case 13: arg0->info.unknown_8_ = inline_0200dbf8_12(p); break;
                case 15: arg0->info.unknown_8_ = inline_0200dbf8_13(p); break;
                case 16: arg0->info.unknown_8_ = inline_0200dbf8_14(p); break;
                case 17: arg0->info.unknown_8_ = inline_0200dbf8_15(p); break;
                case 18: arg0->info.unknown_8_ = inline_0200dbf8_16(p); break;
                case 19: arg0->info.unknown_8_ = inline_0200dbf8_17(p); break;
                default:
                    return 0xff;
            }
            break;
        }
    }

    while ((action = *arg0->info.unknown_8_ & 0x1f) == 1)
        inline_0200dbf8_18(&arg0->info);
    return action;
}
