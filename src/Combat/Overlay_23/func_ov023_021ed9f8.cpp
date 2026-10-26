#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_02195658(void);
extern "C" void* func_0207d78c(void);
extern "C" void func_ov000_02174a50(void* obj, int combatantId);
extern "C" void func_020a367c(unsigned char* obj, int index);

struct Struct_0207da94;
extern "C" void func_0207da94(struct Struct_0207da94* list, int idx);

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov000_02160fa8(void* work, int mask);

extern "C" void func_ov023_021f52c8(void* obj);
extern "C" void func_ov023_021d8b6c(void* obj);
extern "C" void func_ov023_021d8af8(void* obj);
extern "C" void func_ov023_021d8bb4(void* obj);

struct Struct_020e6d5c_2 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_2 __ptmf_null;

struct Struct_ov023_021fe148 { unsigned int fn; unsigned int unknown_4_; };
extern struct Struct_ov023_021fe148 data_ov023_021fe148[];

struct Struct_ov023_021ed9f8 {
    void* inner;
    char pad4[4];
    unsigned int flags;
};
extern "C" struct Struct_ov023_021ed9f8 _ZZ21inline_ov023_021f4c04vE1s;

struct Struct_ov023_021ed9f8_2 {
    char pad0[4];
    int f4;
    int f8;
    int fc;
};

// USA: func_ov023_021ed9f8
extern "C" ARM void func_ov023_021ed9f8(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x21c, regionalOffset1=0x371c, regionalOffset2=0xe28, regionalOffset3=0x79c1, regionalOffset4=0x5778};
#else
 enum {regionalOffset0=0x2a0, regionalOffset1=0x3760, regionalOffset2=0xeac, regionalOffset3=0x77d1, regionalOffset4=0x5588};
#endif
    GameState::GetInstance();
    int var0 = (int)BackgroundLoader::GetInstance();
    ((int)GetGameResources());
    unsigned char* p = *(unsigned char**)(obj + regionalOffset0);
    int n = func_ov017_02195658();
    if (n > 0) {
        void* q = func_0207d78c();
        func_ov000_02174a50(obj + regionalOffset1, n);
        func_020a367c(p, n & 0xff);
        func_0207da94((struct Struct_0207da94*)q, (int)(unsigned char)n);
        if (n == (signed char)p[0x2a]) {
            for (int i = 0; i < 4; i++) {
                if (func_020a35e0(p, i & 0xff)) {
                    p[0x2a] = i;
                    break;
                }
            }
        }
    }

    unsigned int flags = _ZZ21inline_ov023_021f4c04vE1s.flags;
    if (!(flags & 1)) {
        unsigned int var6 = *(volatile unsigned int*)&__ptmf_null.a;
        unsigned int var7 = *(volatile unsigned int*)&__ptmf_null.b;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x88) = var6;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x8c) = var7;
        _ZZ21inline_ov023_021f4c04vE1s.flags = flags | 1;
    }

    int idx = *(int*)(obj + regionalOffset2);
    struct Struct_ov023_021fe148* d = &data_ov023_021fe148[idx];
    void* base = obj + ((int)d->unknown_4_ >> 1);
    void* callback;
    if (d->unknown_4_ & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    int result = ((int(*)(void*))callback)(base);
    *(int*)(obj + regionalOffset2) = result;

    int var13 = 0;
    if (func_ov017_021959b4()) {
        if (*(unsigned char*)(obj + regionalOffset3) == 0) {
            func_ov000_02160fa8(obj, 0x2000000);
            var13 = 1;
        }
    }

    if (var13) {
        func_ov023_021f52c8((char*)_ZZ21inline_ov023_021f4c04vE1s.inner + 0xf4);
        if (*(void**)(obj + regionalOffset4) != NULL) {
            func_ov023_021d8b6c(*(void**)(obj + regionalOffset4));
            func_ov023_021d8af8(*(void**)(obj + regionalOffset4));
            *(void**)(obj + regionalOffset4) = NULL;
        }

        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f4 > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f4));
        }
        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f8 > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f8));
        }
        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->fc > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->fc));
        }

        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f4 = -1;
        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->f8 = -1;
        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.inner)->fc = -1;
        return;
    }

    void* entry = *(void**)(obj + regionalOffset4);
    if (entry == NULL) return;
    func_ov023_021d8bb4(entry);
}
