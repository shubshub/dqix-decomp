#include <globaldefs.h>

extern "C" {
    int func_ov031_0223e9d4(void*, void*, int, int);
    int func_ov031_02240074(void*, void*, int);
    void func_ov031_0223e454(void*, void*, int);
    int func_ov031_0223fb48(const char*);
    void func_ov031_0223ea84(void);
    int func_ov031_02240890(int, int, void*, int, void*, void*);
}

extern "C" int func_ov031_0223fa60(void);
extern "C" void func_ov031_0223faa8(void);
extern "C" void func_ov031_0223fb60(void*, unsigned int);

struct Struct_ov031_0223edb4;
extern "C" void func_ov031_0223edb4(void* p0, struct Struct_ov031_0223edb4* p1);

struct Struct_ov031_0223ede0;
extern "C" int func_ov031_022400e8(Struct_ov031_0223ede0*, int, int);

struct Struct_ov031_0223ede0_2;
extern "C" int func_ov031_02240050(Struct_ov031_0223ede0_2*, int, int);

typedef void* (*Type_ov031_02212c3c)(int, int);
extern Type_ov031_02212c3c data_ov031_02290dac;
extern void (*data_ov031_02290dc0)(void*);
extern int data_ov031_02290dbc;
extern int data_ov031_02290db8;
extern int data_ov031_02290db0;
extern int data_ov031_02290e88;
extern int data_ov031_02290e94;
extern int data_ov031_0224c6b0;
extern int data_ov031_0224c6d0;
extern int data_ov031_02290e28;
extern int data_ov031_0224c6dc;
extern int data_ov031_02290dd4;
extern int data_ov031_0224c6e4;
extern int data_ov031_0224c6f0;
extern int data_ov031_02290e0c;
extern int data_ov031_02290da8;
extern int data_ov031_0224c6f8;
extern int data_ov031_0224c700;
extern int data_ov031_0224c708;
extern int data_ov031_02290de0;
extern int data_ov031_0224c710;
struct Struct_ov031_02290dc8 { int f0; int f4; int f8; };
extern Struct_ov031_02290dc8 data_ov031_02290dc8;
extern int data_ov031_0224c718;
extern int data_ov031_0224c720;
extern int data_ov031_0224c728;
extern int data_ov031_02290da4;
extern int data_ov031_0224c730;
extern int data_ov031_02290df4;
extern char data_ov031_02290eac[0x59];
extern int data_ov031_0224c738;

// USA: func_ov031_0223ede0
extern "C" ARM int func_ov031_0223ede0(void** p0, void** p1, void* p2, void* p3, int p4, const char* p5) {
    if (!func_ov031_0223e9d4(&data_ov031_02290e88, &data_ov031_02290e94, (int)p2, (int)p3)) {
        data_ov031_02290dbc = 8;
        return 0;
    }
    void* node = data_ov031_02290dac(0x24, 4);
    if (!node) {
        data_ov031_02290dbc = 1;
        return 0;
    }
    *(int*)((char*)node + 8) = data_ov031_02290db8;
    *(int*)((char*)node + 0xc) = 0;
    if (!func_ov031_0223fa60()) {
        data_ov031_02290dc0(node);
        data_ov031_02290dbc = 2;
        return 0;
    }
    int r5 = func_ov031_02240890(data_ov031_02290db0, 1, p3, p4, (void*)func_ov031_0223ea84, node);
    if (!r5) {
        func_ov031_0223faa8();
        data_ov031_02290dc0(node);
        data_ov031_02290dbc = 3;
        return 0;
    }
    *p0 = node;
    *p1 = (void*)r5;
    if (!func_ov031_022400e8((Struct_ov031_0223ede0*)r5, (int)&data_ov031_0224c6b0, 1)) goto fail;
    if (!func_ov031_02240050((Struct_ov031_0223ede0_2*)r5, (int)&data_ov031_0224c6d0, (int)&data_ov031_02290e28)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c6dc, (int)&data_ov031_02290dd4)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c6e4, (int)&data_ov031_02290e88)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c6f0, (int)&data_ov031_02290e0c)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c6f8, data_ov031_02290da8)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c700, (int)&data_ov031_02290e94)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c708, (int)&data_ov031_02290de0)) goto fail;
    if (!func_ov031_02240074((void*)r5, &data_ov031_0224c710, (int)p2)) goto fail;
    if (data_ov031_02290dc8.f0) {
        if (!func_ov031_02240074((void*)r5, &data_ov031_0224c718, data_ov031_02290dc8.f0)) goto fail;
    }
    if (data_ov031_02290dc8.f4) {
        if (!func_ov031_02240074((void*)r5, &data_ov031_0224c720, data_ov031_02290dc8.f4)) goto fail;
    }
    if (data_ov031_02290dc8.f8) {
        if (!func_ov031_02240074((void*)r5, &data_ov031_0224c728, data_ov031_02290dc8.f8)) goto fail;
    }
    if (data_ov031_02290da4) {
        if (!func_ov031_02240074((void*)r5, &data_ov031_0224c730, (int)&data_ov031_02290df4)) goto fail;
    }
    if (p5) {
        int len = func_ov031_0223fb48(p5);
        if (len > 0x40) {
            data_ov031_02290dbc = 7;
            func_ov031_0223edb4(node, (struct Struct_ov031_0223edb4*)r5);
            return 0;
        }
        func_ov031_0223fb60(data_ov031_02290eac, 0x59);
        func_ov031_0223e454(data_ov031_02290eac, (void*)p5, len);
        if (!func_ov031_02240074((void*)r5, &data_ov031_0224c738, (int)&data_ov031_02290eac)) goto fail;
    }
    return 1;
fail:
    func_ov031_0223edb4(node, (struct Struct_ov031_0223edb4*)r5);
    data_ov031_02290dbc = 1;
    return 0;
}
