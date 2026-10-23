#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217dfb4_20=0x10 };
extern "C" void func_02046380(void*);
struct Struct_020465c0;
extern "C" void func_020465c0(Struct_020465c0*,int,int);
extern "C" void func_020465f0(unsigned char*,int,unsigned char);
extern "C" void func_020465d8(unsigned char*,int,unsigned char);
extern "C" void func_02042428(char*, int);
#else
enum { Enum_ov003_0217dfb4_20=0x14 };
#endif

struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205d5d0;
struct Struct_0201099c_3;

struct Struct_ov003_0217dfb4 {
    char unknown_0_[0x68];
    int unknown_68_;
};

struct Struct_ov003_0217dfb4_2 {
    char unknown_0_[Enum_ov003_0217dfb4_20];
    int unknown_14_;
    unsigned char unknown_18_[0x30 - 0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_[0x90 - 0x33];
    struct Struct_ov003_0217dfb4* unknown_90_;
    char unknown_94_[0xcc - 0x94];
    char unknown_cc_[4];
};

extern "C" void* func_02012fe4(void);
int GetGlobalField0x1c020421a0();
extern "C" void __clear(void* buf, int n);
int Window_GetSelectedIndex(struct Struct_0205c570* s);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
unsigned char* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* elem, int state);
void SetByte0xd9AndFlag0x2_0205042c(unsigned char* elem, unsigned char value);
void SetByte0xdaAndFlag0x2_02050440(unsigned char* elem, int value);
extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dfb4
extern "C" ARM void func_ov003_0217dfb4(struct Struct_ov003_0217dfb4_2* arg0) {
    char var0[0x400];
    func_02012fe4();
#if defined(jpn)
    int var1 = func_020421a0();
#else
    func_020421a0();
#endif
    __clear(var0, 0x400);
    int var2;
    int var3;
    int var4 = arg0->unknown_90_->unknown_68_;
    var2 = (var4 + 1) * 6;
    if (var2 > arg0->unknown_30_) {
        var2 = arg0->unknown_30_;
    }
    if (menu->mode == 2) {
        AppendFrameTag02041c08(buf, Window_GetSelectedIndex((struct Struct_0205c570*)menu->window) % 6, 8, 5, 5, 5);
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        AppendNameTag_02041b70(buf, i % 6, name);
        if (i != end - 1) {
            AppendString02042058(buf, data_ov003_02180c7f);
        }
    }
    if (arg0->unknown_32_ > 1) {
#if defined(jpn)
        func_02046380((void*)global);
        StoreInArray0x8b0_020465c0((StoreStruct*)global, 0, page + 1);
        StoreInArray0x8b0_020465c0((StoreStruct*)global, 1, menu->field32);
        SetByteInRange_020465f0((unsigned char*)global, 0, 2);
        SetByteInRange_020465f0((unsigned char*)global, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)global, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)global, 1, 0);
        func_02042428(buf, 8);
        AppendString02042058(buf, (const char*)KeyTable_Get((Container020e0310*)menu->names, 0xc8));
#else
        unsigned char* var6 = func_0205d81c((struct Struct_0205d81c*)arg0->unknown_90_, 0);
        if (var6 != NULL) {
            func_02050400(var6, 1);
            func_0205042c(var6, var4);
            func_02050440(var6, arg0->unknown_32_);
        }
#endif
    }
#if defined(jpn)
    func_0205d5d0((struct Struct_0205d5d0*)arg0->unknown_90_, 0, (int)var0, 1);
#else
    func_0205d5d0((struct Struct_0205d5d0*)arg0->unknown_90_, 0, (int)var0, 1, 0);
#endif
}
