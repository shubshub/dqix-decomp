#include <globaldefs.h>

extern "C" void func_ov031_02223440(void);

struct Struct_ov031_0222d1b8 { unsigned int flags; };
extern "C" int func_ov031_0223da58(Struct_ov031_0222d1b8*);

extern "C" ARM void* func_ov031_0223c7c4(int idx);

typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);
extern "C" int LoadToMainObjStandardPalette(int, int, unsigned int);

extern "C" void func_ov031_0223cbbc(int, int);

extern "C" void func_ov031_02227520(int*, int*);
extern "C" ARM void func_ov031_022274d0(int a, int b);
extern "C" void func_ov031_0222750c(int, int);
extern "C" ARM void func_ov031_022274c0(int);

extern "C" void* func_ov031_0222ea24(void);
extern "C" void* func_ov031_0222b644(void);
extern "C" void* func_ov031_022340c0(void);

extern void* data_ov031_02290c94;
extern "C" unsigned int func_ov031_0223cf70(void**);
extern int data_ov031_0224ba64;

// USA: func_ov031_0222d1b8
extern "C" ARM void func_ov031_0222d1b8(void) {
    func_ov031_02223440();
    func_ov031_0223da58(*(Struct_ov031_0222d1b8**)((char*)data_ov031_02290c94 + 4));
    func_ov031_0223c7c4(0);
    func_ov031_022234d8((int)&data_ov031_0224ba64, (Type_ov031_022234d8)LoadToMainObjStandardPalette);
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);

    int a, b;
    func_ov031_02227520(&a, &b);
    if (b == 0) {
        func_ov031_022274d0(2, 1);
        func_ov031_0222750c(0, a);
        func_ov031_022274c0((int)func_ov031_0222ea24);
    } else {
        if (*((unsigned char*)data_ov031_02290c94 + 0x2a) == 0) {
            func_ov031_022274d0(0, 1);
            func_ov031_0222750c(1, 0);
            func_ov031_022274c0((int)func_ov031_0222b644);
        } else {
            func_ov031_022274d0(0, 0);
            func_ov031_0222750c(0, 1);
            func_ov031_022274c0((int)func_ov031_022340c0);
        }
    }
#if defined(jpn)
    func_ov031_0223cf70((void**)0x02291894);
#else
    func_ov031_0223cf70((void**)0x02290C94);
#endif
}
