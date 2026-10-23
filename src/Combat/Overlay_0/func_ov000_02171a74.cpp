#include <globaldefs.h>

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
void Clear12Bytes020e46c4(void* buf);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
void* GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* g);
extern "C" void func_02046608(void* a, int b, int c, void* d, int e, int f, int g);

struct Struct_ov000_02171a74 {
    char unknown_0_[4];
    void* unknown_4_;
    char unknown_8_[0x28 - 8];
    int unknown_28_;
    char unknown_2c_[0x4c - 0x2c];
    int unknown_4c_;
};

// USA: func_ov000_02171a74
extern "C" ARM int func_ov000_02171a74(struct Struct_ov000_02171a74* arg0
#if !defined(jpn)
    , int arg1
#endif
) {
#if !defined(jpn)
    if (arg0->unknown_4_ == 0) {
        return -1;
    }
#endif
    int var0 = arg0->unknown_28_;
    int var1 = -1;
    if (var0 & 1) {
        var1 = 4;
    } else if (var0 & 8) {
        var1 = 2;
    } else if (var0 & 0x10) {
        var1 = 3;
    } else if (var0 & 0x80000) {
        var1 = 0x26;
    }
#if !defined(jpn)
    if (var1 < 0) {
        goto end;
    }
    {
        int val = KeyTable_Get((struct Container020e0310*)obj->field4, key);
        if (val == 0) {
            goto end;
        }
        char var3[0xc];
        func_020e46c4(var3);
        func_020e4bf4(var3, arg0->unknown_4c_);
        void* var4 = func_020421a0();
        func_02046380(var4);
        *(void**)var4 = var3;
        func_02046608(var4, 0xa, var2, (void*)arg1, 0x100, 0, 0);
    }
end:
#endif
    return var1;
}
