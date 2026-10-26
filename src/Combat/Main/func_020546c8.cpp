#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020546c8;

extern "C" void* func_02055090(struct Struct_020546c8* obj);
extern "C" void* func_020550a8(struct Struct_020546c8* p);
extern "C" void* func_020550c0(struct Struct_020546c8* p);
extern "C" void* func_020550d8(struct Struct_020546c8* obj);
extern "C" void* func_02055120(struct Struct_020546c8* arg0);
extern "C" void* func_02055138(struct Struct_020546c8* arg0);
extern "C" void* func_02055150(struct Struct_020546c8* arg0);
extern "C" int func_02055168(struct Struct_020546c8* obj);

struct Struct_020546c8_9;
extern "C" bool func_02054f3c(struct Struct_020546c8_9** out, SafeAllocator* alloc);
struct Struct_020546c8_10;
extern "C" bool func_02054ef8(struct Struct_020546c8_10** out, SafeAllocator* alloc);
struct Struct_020546c8_11;
extern "C" bool func_02054eb4(struct Struct_020546c8_11** out, SafeAllocator* alloc);
struct Struct_020546c8_12;
extern "C" int func_02054e70(struct Struct_020546c8_12** out, SafeAllocator* alloc);

struct Struct_020546c8 {
    SafeAllocator* alloc;
    void* unknown_4_;
    SignedAllocatorList listB[3];
    SignedAllocatorList unknown_2c_[3];
    SignedAllocatorList unknown_50_[3];
    SignedAllocatorList unknown_74_;
    SignedAllocatorList unknown_80_[3];
    SignedAllocatorList unknown_a4_;
    SignedAllocatorList unknown_b0_[2];
    SignedAllocatorList unknown_c8_[2];
    SignedAllocatorList unknown_e0_;
    SignedAllocatorList unknown_ec_[4];
    SignedAllocatorList listA;
};

struct Struct_020546c8_2 {
    char pad0[4];
    void* arr;
    char pad8[4];
    unsigned short count;
};

struct Struct_020546c8_3 {
    void* arrB[3];
    void* unknown_c_[3];
    void* unknown_18_[3];
    unsigned char countB[3];
    unsigned char unknown_27_[3];
    unsigned char unknown_2a_[3];
};

struct Struct_020546c8_4 {
    void* arr;
    unsigned char count;
};

struct Struct_020546c8_5 {
    void* arr[3];
    void* unknown_c_;
    unsigned char count[3];
    unsigned char unknown_13_;
};

struct Struct_020546c8_6 {
    void* arr[2];
    unsigned char count[2];
};

struct Struct_020546c8_7 {
    char pad0[4];
    void* arr;
    unsigned char count;
};

struct Struct_020546c8_8 {
    void* arr[4];
    unsigned char count[4];
};

// USA: func_020546c8
extern "C" ARM void func_020546c8(struct Struct_020546c8* sl) {
    struct Struct_020546c8_2* var0 = (struct Struct_020546c8_2*)func_02055090(sl);
    if (var0 != NULL && var0->count != 0) {
        struct Struct_020546c8_9* pA = NULL;
        if (func_02054f3c(&pA, sl->alloc)) {
            sl->listA.InsertAtEnd((SignedAllocatorHeader*)pA);
            *(int*)pA = (int)var0->arr;
            for (int i = 1; i < var0->count; i++) {
                pA = NULL;
                if (func_02054f3c(&pA, sl->alloc)) {
                    sl->listA.InsertAtEnd((SignedAllocatorHeader*)pA);
                    *(int*)pA = (int)((char*)var0->arr + i * 0x1c);
                }
            }
        }
    }

    struct Struct_020546c8_3* var3 = (struct Struct_020546c8_3*)func_020550a8(sl);
    if (var3 != NULL) {
        for (int sb = 0; sb < 3; sb++) {
            if (var3->countB[sb] != 0) {
                struct Struct_020546c8_10* pB = NULL;
                if (func_02054ef8(&pB, sl->alloc)) {
                    sl->listB[sb].InsertAtEnd((SignedAllocatorHeader*)pB);
                    *(int*)pB = (int)var3->arrB[sb];
                    for (int j = 1; j < var3->countB[sb]; j++) {
                        pB = NULL;
                        if (func_02054ef8(&pB, sl->alloc)) {
                            sl->listB[sb].InsertAtEnd((SignedAllocatorHeader*)pB);
                            *(int*)pB = (int)((char*)var3->arrB[sb] + j * 8);
                        }
                    }
                }
            }
            if (var3->unknown_27_[sb] != 0) {
                struct Struct_020546c8_10* var7 = NULL;
                if (func_02054ef8(&var7, sl->alloc)) {
                    sl->unknown_2c_[sb].InsertAtEnd((SignedAllocatorHeader*)var7);
                    *(int*)var7 = (int)var3->unknown_c_[sb];
                    for (int j = 1; j < var3->unknown_27_[sb]; j++) {
                        var7 = NULL;
                        if (func_02054ef8(&var7, sl->alloc)) {
                            sl->unknown_2c_[sb].InsertAtEnd((SignedAllocatorHeader*)var7);
                            *(int*)var7 = (int)((char*)var3->unknown_c_[sb] + j * 8);
                        }
                    }
                }
            }
            if (var3->unknown_2a_[sb] != 0) {
                struct Struct_020546c8_10* var9 = NULL;
                if (func_02054ef8(&var9, sl->alloc)) {
                    sl->unknown_50_[sb].InsertAtEnd((SignedAllocatorHeader*)var9);
                    *(int*)var9 = (int)var3->unknown_18_[sb];
                    for (int j = 1; j < var3->unknown_2a_[sb]; j++) {
                        var9 = NULL;
                        if (func_02054ef8(&var9, sl->alloc)) {
                            sl->unknown_50_[sb].InsertAtEnd((SignedAllocatorHeader*)var9);
                            *(int*)var9 = (int)((char*)var3->unknown_18_[sb] + j * 8);
                        }
                    }
                }
            }
        }
    }

    struct Struct_020546c8_4* var11 = (struct Struct_020546c8_4*)func_020550c0(sl);
    if (var11 != NULL && var11->count != 0) {
        struct Struct_020546c8_10* var12 = NULL;
        if (func_02054ef8(&var12, sl->alloc)) {
            sl->unknown_74_.InsertAtEnd((SignedAllocatorHeader*)var12);
            *(int*)var12 = (int)var11->arr;
            for (int i = 1; i < var11->count; i++) {
                var12 = NULL;
                if (func_02054ef8(&var12, sl->alloc)) {
                    sl->unknown_74_.InsertAtEnd((SignedAllocatorHeader*)var12);
                    *(int*)var12 = (int)((char*)var11->arr + i * 8);
                }
            }
        }
    }

    struct Struct_020546c8_5* var14 = (struct Struct_020546c8_5*)func_020550d8(sl);
    if (var14 != NULL) {
        for (int sb = 0; sb < 3; sb++) {
            if (var14->count[sb] != 0) {
                struct Struct_020546c8_10* var16 = NULL;
                if (func_02054ef8(&var16, sl->alloc)) {
                    sl->unknown_80_[sb].InsertAtEnd((SignedAllocatorHeader*)var16);
                    *(int*)var16 = (int)var14->arr[sb];
                    for (int j = 1; j < var14->count[sb]; j++) {
                        var16 = NULL;
                        if (func_02054ef8(&var16, sl->alloc)) {
                            sl->unknown_80_[sb].InsertAtEnd((SignedAllocatorHeader*)var16);
                            *(int*)var16 = (int)((char*)var14->arr[sb] + j * 8);
                        }
                    }
                }
            }
        }
        if (var14->unknown_13_ != 0) {
            struct Struct_020546c8_11* var18 = NULL;
            if (func_02054eb4(&var18, sl->alloc)) {
                sl->unknown_a4_.InsertAtEnd((SignedAllocatorHeader*)var18);
                *(int*)var18 = (int)var14->unknown_c_;
                for (int i = 1; i < var14->unknown_13_; i++) {
                    var18 = NULL;
                    if (func_02054eb4(&var18, sl->alloc)) {
                        sl->unknown_a4_.InsertAtEnd((SignedAllocatorHeader*)var18);
                        *(int*)var18 = (int)((char*)var14->unknown_c_ + i * 0x10);
                    }
                }
            }
        }
    }

    struct Struct_020546c8_6* var20 = (struct Struct_020546c8_6*)func_02055120(sl);
    if (var20 != NULL) {
        for (int var21 = 0; var21 < 2; var21++) {
            if (var20->count[var21] != 0) {
                struct Struct_020546c8_10* var22 = NULL;
                if (func_02054ef8(&var22, sl->alloc)) {
                    sl->unknown_b0_[var21].InsertAtEnd((SignedAllocatorHeader*)var22);
                    *(int*)var22 = (int)var20->arr[var21];
                    for (int j = 1; j < var20->count[var21]; j++) {
                        var22 = NULL;
                        if (func_02054ef8(&var22, sl->alloc)) {
                            sl->unknown_b0_[var21].InsertAtEnd((SignedAllocatorHeader*)var22);
                            *(int*)var22 = (int)((char*)var20->arr[var21] + j * 8);
                        }
                    }
                }
            }
        }
    }

    struct Struct_020546c8_6* var24 = (struct Struct_020546c8_6*)func_02055138(sl);
    if (var24 != NULL) {
        for (int var25 = 0; var25 < 2; var25++) {
            if (var24->count[var25] != 0) {
                struct Struct_020546c8_11* var26 = NULL;
                if (func_02054eb4(&var26, sl->alloc)) {
                    sl->unknown_c8_[var25].InsertAtEnd((SignedAllocatorHeader*)var26);
                    *(int*)var26 = (int)var24->arr[var25];
                    for (int j = 1; j < var24->count[var25]; j++) {
                        var26 = NULL;
                        if (func_02054eb4(&var26, sl->alloc)) {
                            sl->unknown_c8_[var25].InsertAtEnd((SignedAllocatorHeader*)var26);
                            *(int*)var26 = (int)((char*)var24->arr[var25] + j * 0x10);
                        }
                    }
                }
            }
        }
    }

    struct Struct_020546c8_7* r7s = (struct Struct_020546c8_7*)func_02055150(sl);
    if (r7s != NULL && r7s->count != 0) {
        struct Struct_020546c8_12* var29 = NULL;
        if (func_02054e70(&var29, sl->alloc)) {
            sl->unknown_e0_.InsertAtEnd((SignedAllocatorHeader*)var29);
            *(int*)var29 = (int)r7s->arr;
            for (int i = 1; i < r7s->count; i++) {
                var29 = NULL;
                if (func_02054e70(&var29, sl->alloc)) {
                    sl->unknown_e0_.InsertAtEnd((SignedAllocatorHeader*)var29);
                    *(int*)var29 = (int)((char*)r7s->arr + i * 0xc);
                }
            }
        }
    }

    struct Struct_020546c8_8* var31 = (struct Struct_020546c8_8*)func_02055168(sl);
    if (var31 != NULL) {
        for (int var32 = 0; var32 < 4; var32++) {
            if (var31->count[var32] != 0) {
                struct Struct_020546c8_10* var33 = NULL;
                if (func_02054ef8(&var33, sl->alloc)) {
                    sl->unknown_ec_[var32].InsertAtEnd((SignedAllocatorHeader*)var33);
                    *(int*)var33 = (int)var31->arr[var32];
                    for (int j = 1; j < var31->count[var32]; j++) {
                        var33 = NULL;
                        if (func_02054ef8(&var33, sl->alloc)) {
                            sl->unknown_ec_[var32].InsertAtEnd((SignedAllocatorHeader*)var33);
                            *(int*)var33 = (int)((char*)var31->arr[var32] + j * 8);
                        }
                    }
                }
            }
        }
    }
}
