#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>


struct Struct_ov004_02153e20;

struct Struct_ov004_02153e20_2 {
    int field_0x0;
    int value;
    int unknown_8_;
    unsigned int flags;
};

struct Struct_ov004_02153e20_3 {
    Struct_ov004_02153e20_3* next;
    Struct_ov004_02153e20_2* entry;
};

struct Struct_ov004_02153e20_4 {
    char pad[0x5c];
    short x;
    short y;
};

struct Struct_ov004_02153e20_5 {
    char pad[0xc];
    unsigned char flags;
    char pad2[0x13];
    int value;
};

struct Struct_ov004_02153e20_6 {
    char pad[0x104];
    short x;
    short y;
};

class Struct_ov004_02153e20_7 {
public:
    virtual void v00(); virtual void inline_ov004_02153e20_2(); virtual void inline_ov004_02153e20_3(); virtual void inline_ov004_02153e20_4();
    virtual void v04(); virtual void inline_ov004_02153e20_6(); virtual void inline_ov004_02153e20_7(); virtual void inline_ov004_02153e20_8();
    virtual void v08(); virtual void inline_ov004_02153e20_10(); virtual void v10(); virtual void inline_ov004_02153e20_12();
    virtual void inline_ov004_02153e20_13(); virtual void inline_ov004_02153e20_14(); virtual void v14(); virtual void inline_ov004_02153e20_16();
    virtual void inline_ov004_02153e20_17(); virtual void inline_ov004_02153e20_18(); virtual void v18(); virtual void inline_ov004_02153e20_20();
    virtual void v20(); virtual void inline_ov004_02153e20_22(); virtual void inline_ov004_02153e20_23(); virtual void inline_ov004_02153e20_24();
    virtual void v24(); virtual void inline_ov004_02153e20_26(); virtual void inline_ov004_02153e20_27(); virtual void inline_ov004_02153e20_28();
    virtual void v28(); virtual void inline_ov004_02153e20_30(); virtual void v30(); virtual void inline_ov004_02153e20_32();
    virtual void inline_ov004_02153e20_33(); virtual void inline_ov004_02153e20_34(); virtual void v34(); virtual void inline_ov004_02153e20_36();
    virtual void inline_ov004_02153e20_37(); virtual void inline_ov004_02153e20_38(); virtual void v38(); virtual void inline_ov004_02153e20_40();
    virtual void v40(); virtual void inline_ov004_02153e20_42(); virtual void inline_ov004_02153e20_43(); virtual void inline_ov004_02153e20_44();
    virtual void v44(); virtual void inline_ov004_02153e20_46(); virtual void inline_ov004_02153e20_47(); virtual void inline_ov004_02153e20_48();
    virtual void v48(); virtual void inline_ov004_02153e20_50(); virtual void v50(); virtual void inline_ov004_02153e20_52();
    virtual void inline_ov004_02153e20_53(); virtual void inline_ov004_02153e20_54(); virtual void v54(); virtual void inline_ov004_02153e20_56();
    virtual void inline_ov004_02153e20_57(); virtual void inline_ov004_02153e20_58(); virtual void v58();
    virtual Struct_ov004_02153e20_3** inline_ov004_02153e20_60();
};

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_ov023_021f9d14(void* grid, void* ctx);
extern "C" void func_ov023_021f809c(void* obj, void* ctx);
extern "C" int func_ov004_02153d8c(void* ctx);

// USA: func_ov004_02153e20
extern "C" ARM int func_ov004_02153e20(void* ctx) {
    void* list = func_ov011_021849c8(ctx);
    short x, y;
    Struct_ov004_02153e20_4* var3 = (Struct_ov004_02153e20_4*)func_ov023_021f6880(list, 0x2c);
    if (!var3) return 0;
    if (func_ov023_021f6f10(var3) != 7) return 0;
    x = var3->x;
    y = var3->y;
    Struct_ov004_02153e20_7* owner = (Struct_ov004_02153e20_7*)func_ov023_021f6880(list, 0x39);
    if (!owner) return 0;
    if (func_ov023_021f6f10(owner) != 0x12) return 0;
    Struct_ov004_02153e20_3** head = owner->inline_ov004_02153e20_60();
    if (!head) return 0;
    Struct_ov004_02153e20_3* node = *head;
    if (!node) return 0;
    unsigned char* flags = Scenario_GetInstance();

    short start = x * 16;
    short i = 0;
    while (node) {
        if (i == start) break;
        i++;
        node = node->next;
    }

    for (short j = 0; j < 16; j++) {
        int id = j + 0x1a;
        Struct_ov004_02153e20_5* slot = (Struct_ov004_02153e20_5*)func_ov023_021f6880(list, id);
        if (slot && func_ov023_021f6f10(slot) == 8) {
            slot->value = 0;
            slot->flags &= ~8;
            if (!node) {
                func_ov023_021f9b30((Struct_ov004_02153e20*)var3, 0, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                slot->flags |= 8;
            } else {
                func_ov023_021f9b30((Struct_ov004_02153e20*)var3, (unsigned short)id, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                Struct_ov004_02153e20_2* entry = node->entry;
                if (entry) {
                    int bits = (unsigned short)((entry->flags << 9) >> 21);
                    if (bits > 0) {
                        if (Scenario_TestFlag((int)flags, flags + 0x8c, bits + 0x76 + 0xc00)) {
                            slot->value = entry->value;
                        }
                    }
                }
                node = node->next;
            }
        }
    }

    func_ov023_021f9d14(var3, ctx);
    Struct_ov004_02153e20_6* cursor = (Struct_ov004_02153e20_6*)func_ov023_021f6880(list, 3);
    if (!cursor) return 0;
    if (func_ov023_021f6f10(cursor) != 6) return 0;
    cursor->x = x;
    cursor->y = y;
    func_ov023_021f809c(cursor, ctx);
    func_ov004_02153d8c(ctx);
    return 0;
}
