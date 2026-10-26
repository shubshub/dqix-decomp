#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/ProcessorContext.h"

struct ProcessorContext;

typedef void* (*Type_ov031_022192c0)(const char* tag, unsigned int size);
typedef void (*Type_ov031_022192c0_2)(const char* tag, void* p, int flags);

struct Struct_ov031_022192c0_2 {
    char pad0[0x1004];
    int state;
    char unknown_1008_[0x1108 - 0x1008];
    Type_ov031_022192c0 alloc;
    Type_ov031_022192c0_2 unknown_110c_;
    char unknown_1110_[0x1114 - 0x1110];
    char* unknown_1114_;
    char* unknown_1118_;
};

struct Struct_ov031_022192c0_3 {
    char pad0[0x1020];
    int state;
    char unknown_1024_[0x112c - 0x1024];
    int unknown_112c_;
    char unknown_1130_[0x1a08 - 0x1130];
    char* location;
    char unknown_1a0c_[0x1b38 - 0x1a0c];
    ProcessorContext context;
};

struct Struct_ov031_0224e624 {
    const char* unknown_0_;
    int method;
    int unknown_8_;
    Type_ov031_022192c0 alloc;
    Type_ov031_022192c0_2 unknown_10_;
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov031_0224e60c_3 {
    Struct_ov031_022192c0_2* base;
    int unknown_4_;
    int f8;
    int fc;
    int f10;
    Struct_ov031_022192c0_3* unknown_14_;
    Struct_ov031_0224e624 req;
};

struct Struct_ov031_0224e640 {
    unsigned short f0;
    char pad2[0x34 - 2];
    unsigned char f34;
    char unknown_35_[0x40 - 0x35];
    Type_ov031_022192c0 alloc;
    Type_ov031_022192c0_2 unknown_44_;
};

struct Struct_ov031_022192c0 {
    unsigned long long ticks;
    int pad[3];
};

extern "C" int func_ov031_02217c00(Struct_ov031_022192c0_3* arg0, Struct_ov031_0224e624* req);
extern "C" void func_ov031_022183b4(Struct_ov031_022192c0_3* arg0);
extern "C" void func_ov031_0221a1d4(int result);
extern "C" int func_ov031_02217d1c(Struct_ov031_022192c0_3* arg0);
extern "C" void func_ov031_02217db4(Struct_ov031_022192c0_3* arg0, int priority);
extern "C" int func_ov031_02218b8c(Struct_ov031_022192c0_3* arg0, int flag);
extern "C" char* func_ov031_02218e2c(Struct_ov031_022192c0_3* arg0, const char* key);
extern "C" int func_02005a94(const char* s);
extern "C" int func_ov031_022175dc(void* buf);
extern "C" int func_ov031_022178b4(Struct_ov031_022192c0_3* arg0, void* buf, int flag);
extern "C" int func_ov031_02218604(Struct_ov031_022192c0_3* arg0, const char* name, const char* value, int len);
extern "C" void func_ov031_0221ae00(Struct_ov031_022192c0* out);
extern "C" int func_ov031_022167c8(Struct_ov031_0224e640* session, Struct_ov031_022192c0_3* arg1);
extern "C" void func_ov031_02216a84();
extern "C" int func_ov031_02216ab4();
extern "C" void func_ov031_02216b00(int* out);
extern "C" void func_ov031_02216a2c();
extern "C" int func_ov031_02218e84(void* self, int key, char* buf, int size);
extern "C" int func_ov031_02218710(Struct_ov031_022192c0_3* arg0, char* body);

#if defined(jpn)
#define data_ov031_0224a170 data_ov031_0224ad70
#define data_ov031_0224a198 data_ov031_0224ad98
#endif
extern Struct_ov031_0224e60c_3 data_ov031_0224e60c;
extern Struct_ov031_0224e624 data_ov031_0224e624;
extern Struct_ov031_0224e640 data_ov031_0224e640;
extern const char* data_ov031_0224a010;
extern const char* data_ov031_02249b54;
extern int data_020f3390;
extern char data_ov031_0224a124[];
extern char data_ov031_0224a130[];
extern char data_ov031_0224a150[];
extern char data_ov031_0224a158[];
extern char data_ov031_0224a160[];
extern char data_ov031_0224a170[];
extern char data_ov031_0224a178[];
extern char data_ov031_0224a180[];
extern char data_ov031_0224a18c[];
extern char data_ov031_0224a190[];
extern char data_ov031_0224a198[];
extern char data_ov031_0224a06c[];
extern char data_ov031_0224a088[];
extern char data_ov031_0224a0bc[];
extern char data_ov031_0224a0d8[];
extern char data_ov031_0224a0e4[];
extern char data_ov031_0224a0f4[];
extern char data_ov031_0224a104[];
extern char data_ov031_0224a1a0[];
extern char data_ov031_0224a1ac[];
extern char data_ov031_0224a1b8[];

#define G data_ov031_0224e60c

#define FAIL(code)                          \
    {                                       \
        func_ov031_022183b4(G.unknown_14_);        \
        func_ov031_0221a1d4(code);          \
        goto done;                          \
    }

// USA: func_ov031_022192c0
extern "C" ARM void func_ov031_022192c0(void) {
    int code;
    Type_ov031_022192c0 alloc = G.base->alloc;
    Type_ov031_022192c0_2 var2 = G.base->unknown_110c_;
    char* var3 = 0;
    char* pass = 0;
    char* var5 = 0;
    unsigned int var6 = 0;
    char* location;
    int var8;
    int var9;
    unsigned int wait;
    char* var11;
    char* var12;
    int var13;
    int status;
    char* var15;
    char* var16;
    char* var17;
    int info[0x71];
    char body[0x94];
    Struct_ov031_022192c0 now;
    char numBuf[4];

    for (;;) {
        G.req.unknown_0_ = data_ov031_0224a010;
        G.req.method = 1;
        G.req.unknown_8_ = 0x1000;
        G.req.alloc = alloc;
        G.req.unknown_10_ = var2;
        G.req.unknown_18_ = 20000;
        G.base->state = -2;
        if (func_ov031_02217c00(G.unknown_14_, &data_ov031_0224e624) != 0) FAIL(1);
        if (func_ov031_02217d1c(G.unknown_14_) != 0) FAIL(1);
        func_ov031_02217db4(G.unknown_14_, GetContextPriority(data_02111304.activeContext) - 1);
        if (G.unknown_14_->context.uniqueID != 0) AwaitContextCompletion(&G.unknown_14_->context);
        switch (G.unknown_14_->state) {
        case 2:
            G.base->state = -1;
        default:
            FAIL(3);
        case 8:
            break;
        }
        if (func_ov031_02218b8c(G.unknown_14_, 0) != 1) FAIL(2);

        code = func_02005a94(func_ov031_02218e2c(G.unknown_14_, data_ov031_0224a124));
        if (data_020f3390 == 0x22) {
            func_ov031_0221a1d4(2);
            goto done;
        }
        switch (code) {
        case 200:
            G.f8 = G.unknown_14_->unknown_112c_;
            break;
        case 302:
            G.unknown_4_ = 1;
            if (G.base->unknown_1118_ != 0) {
                G.base->state = -6;
                func_ov031_022183b4(G.unknown_14_);
                G.req.unknown_0_ = data_ov031_02249b54;
                G.req.method = 0;
                G.req.unknown_8_ = 0x200;
                G.req.alloc = alloc;
                G.req.unknown_10_ = var2;
                G.req.unknown_18_ = 20000;
                if (strcmp(data_ov031_02249b54, data_ov031_0224a130) != 0) G.req.unknown_14_ = 1;
                if (func_ov031_02217c00(G.unknown_14_, &data_ov031_0224e624) != 0) FAIL(1);
                if (func_ov031_022175dc(body) == 0 || func_ov031_022178b4(G.unknown_14_, body, 1) == 0) FAIL(8);
                if (func_ov031_02218604(G.unknown_14_, data_ov031_0224a150, data_ov031_0224a158, 7) != 0 ||
                    (var15 = G.base->unknown_1118_,
                     func_ov031_02218604(G.unknown_14_, data_ov031_0224a160, var15, strlen(var15)) != 0)) FAIL(8);
                var2(data_ov031_0224a088, G.base->unknown_1118_, 0);
                G.base->unknown_1118_ = 0;
                if (func_ov031_02217d1c(G.unknown_14_) != 0) FAIL(1);
                func_ov031_02217db4(G.unknown_14_, GetContextPriority(data_02111304.activeContext) - 1);
                if (G.unknown_14_->context.uniqueID != 0) AwaitContextCompletion(&G.unknown_14_->context);
                switch (G.unknown_14_->state) {
                case 2:
                    G.base->state = -1;
                default:
                    FAIL(3);
                case 8:
                    FAIL(7);
                }
            } else {
                location = G.unknown_14_->location;
                if (location == 0) FAIL(2);
                G.base->unknown_1114_ = (char*)alloc(data_ov031_0224a0bc, strlen(location) + 1);
                var11 = G.base->unknown_1114_;
                if (var11 == 0) FAIL(4);
                strncpy(var11, location, strlen(location) + 1);
            }
            break;
        default:
            FAIL(10);
        }

        func_ov031_022183b4(G.unknown_14_);
        func_ov031_0221ae00(&now);
        if (now.ticks == var6) {
            G.base->state = -3;
            data_ov031_0224e640.f0 = 0;
            data_ov031_0224e640.f34 = 0;
            data_ov031_0224e640.alloc = G.base->alloc;
            data_ov031_0224e640.unknown_44_ = G.base->unknown_110c_;
            if (func_ov031_022167c8(&data_ov031_0224e640, G.unknown_14_) != 0) {
                func_ov031_0221a1d4(5);
                goto done;
            }
            func_ov031_02216a84();
            if (func_ov031_02216ab4() != 0x15) {
                if (func_ov031_02216ab4() == 9) {
                    G.base->state = -1;
                } else {
                    func_ov031_02216b00(info);
                    if (G.fc == 1 && (info[0] == (int)0xffffa4fa || func_ov031_02216ab4() == 0xb)) {
                        G.base->state = 0;
                        func_ov031_02216a2c();
                        func_ov031_0221a1d4(0xb);
                        goto done;
                    }
                    G.base->state = info[0];
                }
                func_ov031_02216a2c();
                func_ov031_0221a1d4(6);
                goto done;
            }
            func_ov031_02216a2c();
        }
        if (code == 200) {
            G.base->state = 0;
            func_ov031_0221a1d4(0xb);
            goto done;
        }

        G.base->state = -4;
        G.req.unknown_0_ = data_ov031_02249b54;
        G.req.method = 0;
        G.req.unknown_8_ = 0x1000;
        G.req.alloc = alloc;
        G.req.unknown_10_ = var2;
        G.req.unknown_18_ = 40000;
        if (strcmp(data_ov031_02249b54, data_ov031_0224a130) != 0) G.req.unknown_14_ = 1;
        if (func_ov031_02217c00(G.unknown_14_, &data_ov031_0224e624) != 0) FAIL(1);
        if (func_ov031_022175dc(body) == 0 || func_ov031_022178b4(G.unknown_14_, body, 1) == 0) FAIL(8);
        if (func_ov031_02218604(G.unknown_14_, data_ov031_0224a150, data_ov031_0224a170, 5) != 0 ||
            (var16 = G.base->unknown_1114_,
             func_ov031_02218604(G.unknown_14_, data_ov031_0224a178, var16, strlen(var16)) != 0)) FAIL(8);
        var2(data_ov031_0224a06c, G.base->unknown_1114_, 0);
        G.base->unknown_1114_ = 0;
        if (func_ov031_02217d1c(G.unknown_14_) != 0) FAIL(1);
        func_ov031_02217db4(G.unknown_14_, GetContextPriority(data_02111304.activeContext) - 1);
        if (G.unknown_14_->context.uniqueID != 0) AwaitContextCompletion(&G.unknown_14_->context);
        switch (G.unknown_14_->state) {
        case 3:
            func_ov031_022183b4(G.unknown_14_);
            if (G.fc == 1) {
                G.base->state = 0;
                func_ov031_0221a1d4(0xb);
            } else {
                func_ov031_0221a1d4(3);
            }
            goto done;
        case 2:
            G.base->state = -1;
        default:
            FAIL(3);
        case 8:
            break;
        }
        if (func_ov031_02218b8c(G.unknown_14_, 0) != 1) FAIL(2);

        code = func_02005a94(func_ov031_02218e2c(G.unknown_14_, data_ov031_0224a124));
        if (data_020f3390 == 0x22) FAIL(2);
        if (code != 200) {
            func_ov031_022183b4(G.unknown_14_);
            if (G.fc == 1 && code == 302) {
                G.base->state = 0;
                func_ov031_0221a1d4(0xb);
            } else {
                func_ov031_0221a1d4(2);
            }
            goto done;
        }

        if (func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a180, numBuf, 4) <= 0) FAIL(9);
        status = func_02005a94(numBuf);
        if (data_020f3390 == 0x22) FAIL(9);
        if (G.fc == 1 && status == 0x72) {
            G.base->state = 0;
            func_ov031_0221a1d4(0xb);
            goto done;
        }
        if (status >= 100) FAIL(6);

        var8 = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a18c, 0, 0);
        if (var8 <= 0) FAIL(9);
        var9 = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a190, 0, 0);
        if (var9 <= 0) FAIL(9);
        var13 = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a198, 0, 0);
        var3 = (char*)alloc(data_ov031_0224a0d8, var8 + 1);
        if (var3 == 0) FAIL(4);
        pass = (char*)alloc(data_ov031_0224a0e4, var9 + 1);
        if (pass == 0) FAIL(4);
        if (var13 > 0) {
            var5 = (char*)alloc(data_ov031_0224a0f4, var13 + 1);
            if (var5 == 0) FAIL(4);
        }
        code = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a18c, var3, var8 + 1);
        if (code < 0) FAIL(9);
        var3[code] = 0;
        code = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a190, pass, var9 + 1);
        if (code < 0) FAIL(9);
        pass[code] = 0;
        wait = 0;
        if (var13 > 0) {
            code = func_ov031_02218e84(G.unknown_14_, (int)data_ov031_0224a198, var5, var13 + 1);
            if (code < 0) FAIL(9);
            var5[code] = 0;
            code = func_02005a94(var5);
            if (data_020f3390 == 0x22) FAIL(9);
            wait = code * 1000;
            if ((int)wait > 180000) wait = 180000;
        }
        func_ov031_022183b4(G.unknown_14_);

        G.base->state = -5;
        G.req.unknown_0_ = var3;
        G.req.method = 0;
        G.req.unknown_8_ = 0x1000;
        G.req.alloc = alloc;
        G.req.unknown_10_ = var2;
        G.req.unknown_18_ = 120000;
        if (func_ov031_02217c00(G.unknown_14_, &data_ov031_0224e624) != 0) FAIL(1);
        if (func_ov031_02218710(G.unknown_14_, pass) != 0) FAIL(8);
        if (func_ov031_02217d1c(G.unknown_14_) != 0) FAIL(1);
        func_ov031_02217db4(G.unknown_14_, GetContextPriority(data_02111304.activeContext) - 1);
        if (G.unknown_14_->context.uniqueID != 0) AwaitContextCompletion(&G.unknown_14_->context);
        switch (G.unknown_14_->state) {
        case 2:
            G.base->state = -1;
        default:
            FAIL(3);
        case 8:
            break;
        }
        if (func_ov031_02218b8c(G.unknown_14_, 1) != 1) FAIL(2);
        var17 = G.unknown_14_->location;
        if (var17 == 0) FAIL(2);
        G.base->unknown_1118_ = (char*)alloc(data_ov031_0224a104, strlen(var17) + 1);
        var12 = G.base->unknown_1118_;
        if (var12 == 0) FAIL(4);
        strncpy(var12, var17, strlen(var17) + 1);
        func_ov031_022183b4(G.unknown_14_);
        SleepCurrentContext(wait);
    }

done:
    if (var3 != 0) var2(data_ov031_0224a1a0, var3, 0);
    if (pass != 0) var2(data_ov031_0224a1ac, pass, 0);
    if (var5 == 0) return;
    var2(data_ov031_0224a1b8, var5, 0);
}
