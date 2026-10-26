#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Struct_ov011_02184a18;
extern "C" unsigned short func_ov011_02184a18(struct Struct_ov011_02184a18* obj);

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void func_ov011_02184a40(void* a, int b);

extern "C" void* func_ov023_021f6880(void* base, int key);
extern "C" int func_ov023_021f9bc8(void* obj);
extern "C" unsigned short func_ov023_021f6f10(void* obj);
extern "C" struct Vec3 func_ov023_021f8b78(void* src, void* arg1);

class Struct_ov023_021f98e0_2 {
public:
    virtual void v00(); virtual void inline_ov023_021f98e0_46(); virtual void inline_ov023_021f98e0_47(); virtual void inline_ov023_021f98e0_48();
    virtual void v04(); virtual void inline_ov023_021f98e0_50(); virtual void inline_ov023_021f98e0_51(); virtual void inline_ov023_021f98e0_52();
    virtual struct Vec3 inline_ov023_021f98e0_53();
    virtual void inline_ov023_021f98e0_54(); virtual void v10(); virtual void inline_ov023_021f98e0_56(); virtual void inline_ov023_021f98e0_57();
    virtual void inline_ov023_021f98e0_58(); virtual void v14(); virtual void inline_ov023_021f98e0_60(); virtual void inline_ov023_021f98e0();
    virtual void inline_ov023_021f98e0_2(); virtual void v18(); virtual void inline_ov023_021f98e0_4();
    virtual int inline_ov023_021f98e0_5();
    virtual void inline_ov023_021f98e0_6(); virtual void inline_ov023_021f98e0_7(); virtual void inline_ov023_021f98e0_8(); virtual void v24();
    virtual void inline_ov023_021f98e0_10(); virtual void inline_ov023_021f98e0_11(); virtual void inline_ov023_021f98e0_12(); virtual void v28();
    virtual void inline_ov023_021f98e0_14(); virtual void v30(); virtual void inline_ov023_021f98e0_16(); virtual void inline_ov023_021f98e0_17();
    virtual void inline_ov023_021f98e0_18(); virtual void v34(); virtual void inline_ov023_021f98e0_20(); virtual void inline_ov023_021f98e0_21();
    virtual void inline_ov023_021f98e0_22(); virtual void v38(); virtual void inline_ov023_021f98e0_24(); virtual void v40();
    virtual void inline_ov023_021f98e0_26(); virtual void inline_ov023_021f98e0_27(); virtual void inline_ov023_021f98e0_28(); virtual void v44();
    virtual void inline_ov023_021f98e0_30(); virtual void inline_ov023_021f98e0_31(); virtual void inline_ov023_021f98e0_32(); virtual void v48();
    virtual void inline_ov023_021f98e0_34(); virtual void v50();
    virtual struct Vec3 inline_ov023_021f98e0_36();
};

class Struct_ov023_021f98e0 {
public:
    virtual void v00(); virtual void inline_ov023_021f98e0_38(); virtual void inline_ov023_021f98e0_39(); virtual void inline_ov023_021f98e0_40();
    virtual void v04(); virtual void inline_ov023_021f98e0_42(); virtual void inline_ov023_021f98e0_43();
    virtual void inline_ov023_021f98e0_44(struct Vec3* v);
};

// USA: func_ov023_021f98e0
extern "C" ARM void func_ov023_021f98e0(void* a, void* b) {
    unsigned short var0 = func_ov011_02184a18((struct Struct_ov011_02184a18*)b);
    void* var1 = func_ov011_021849c8(b);
    Struct_ov023_021f98e0* var2 = (Struct_ov023_021f98e0*)func_ov023_021f6880(var1, var0);

    unsigned short var3 = (*(unsigned short**)((char*)a + 0x20))[func_ov023_021f9bc8(a)];
    Struct_ov023_021f98e0_2* var4 = (Struct_ov023_021f98e0_2*)func_ov023_021f6880(var1, var3);

    if (var2 != 0 && var4 != 0) {
        if (func_ov023_021f6f10(var4) == 0) {
            struct Vec3 var5 = var4->inline_ov023_021f98e0_53();
            struct Vec3 vecB = var4->inline_ov023_021f98e0_36();
            Vector3fix_Add(&var5, (struct Vec3*)((char*)a + 0x2c), &var5);
            Vector3fix_Add(&var5, &vecB, &var5);
            var2->inline_ov023_021f98e0_44(&var5);
        } else if (func_ov023_021f6f10(var4) == 8) {
            struct Vec3 var7 = func_ov023_021f8b78(var4, b);
            struct Vec3 vecB = var4->inline_ov023_021f98e0_36();
            Vector3fix_Add(&var7, (struct Vec3*)((char*)a + 0x2c), &var7);
            Vector3fix_Add(&var7, &vecB, &var7);
            var2->inline_ov023_021f98e0_44(&var7);
        } else if (func_ov023_021f6f10(var4) == 1) {
            struct Vec3 var9 = var4->inline_ov023_021f98e0_53();
            struct Vec3 vecB = var4->inline_ov023_021f98e0_36();
            Vector3fix_Add(&var9, (struct Vec3*)((char*)a + 0x2c), &var9);
            Vector3fix_Add(&var9, &vecB, &var9);
            var2->inline_ov023_021f98e0_44(&var9);
        }

        int count = var4->inline_ov023_021f98e0_5();
        if (count > 0) {
            func_ov011_02184a40(b, count);
        }
    }

    *(int*)((char*)a + 0x38) = 0;
}
