#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>


struct Struct_ov004_02153e20 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad28[0x34];
    short x;
    short y;
};

struct Struct_ov004_0215534c_2 {
    int field_0x0;
    int value;
    int unknown_8_;
    unsigned int flags;
};

struct Struct_ov004_0215534c_3 {
    Struct_ov004_0215534c_3* next;
    Struct_ov004_0215534c_2* entry;
};

struct Struct_ov004_0215534c_4 {
    char pad[0xc];
    unsigned char flags;
    char padD[0x13];
    int value;
};

class Struct_ov004_0215534c {
public:
	virtual void v00(); virtual void inline_ov004_0215534c_2(); virtual void inline_ov004_0215534c_3(); virtual void inline_ov004_0215534c_4();
	virtual void v04(); virtual void inline_ov004_0215534c_6(); virtual void inline_ov004_0215534c_7(); virtual void inline_ov004_0215534c_8();
	virtual void v08(); virtual void inline_ov004_0215534c_10(); virtual void v10(); virtual void inline_ov004_0215534c_12();
	virtual void inline_ov004_0215534c_13(); virtual void inline_ov004_0215534c_14(); virtual void v14(); virtual void inline_ov004_0215534c_16();
	virtual void inline_ov004_0215534c_17(); virtual void inline_ov004_0215534c_18(); virtual void v18(); virtual void inline_ov004_0215534c_20();
	virtual void v20(); virtual void inline_ov004_0215534c_22(); virtual void inline_ov004_0215534c_23(); virtual void inline_ov004_0215534c_24();
	virtual void v24(); virtual void inline_ov004_0215534c_26(); virtual void inline_ov004_0215534c_27(); virtual void inline_ov004_0215534c_28();
	virtual void v28(); virtual void inline_ov004_0215534c_30(); virtual void v30(); virtual void inline_ov004_0215534c_32();
	virtual void inline_ov004_0215534c_33(); virtual void inline_ov004_0215534c_34(); virtual void v34(); virtual void inline_ov004_0215534c_36();
	virtual void inline_ov004_0215534c_37(); virtual void inline_ov004_0215534c_38(); virtual void v38(); virtual void inline_ov004_0215534c_40();
	virtual void v40(); virtual void inline_ov004_0215534c_42(); virtual void inline_ov004_0215534c_43(); virtual void inline_ov004_0215534c_44();
	virtual void v44(); virtual void inline_ov004_0215534c_46(); virtual void inline_ov004_0215534c_47(); virtual void inline_ov004_0215534c_48();
	virtual void v48(); virtual void inline_ov004_0215534c_50(); virtual void v50(); virtual void inline_ov004_0215534c_52();
	virtual void inline_ov004_0215534c_53(); virtual void inline_ov004_0215534c_54(); virtual void v54(); virtual void inline_ov004_0215534c_56();
	virtual void inline_ov004_0215534c_57(); virtual void inline_ov004_0215534c_58(); virtual void v58();
	virtual Struct_ov004_0215534c_3** inline_ov004_0215534c_60();
};

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_ov023_021f9d14(Struct_ov004_02153e20* grid, void* ctx);
extern "C" int func_ov023_021f9b30(Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void func_ov023_021f9da0(void* self, unsigned char val);
extern "C" void func_ov023_021f6630(int ctx, int kind, short x, short y);
extern "C" int func_ov004_021552b8(void* ctx);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_ov004_0215534c
extern "C" ARM int func_ov004_0215534c(void* ctx) {
    void* list;
    short x;
    Struct_ov004_02153e20* grid;
    short y;
    Struct_ov004_0215534c* obj;
    Struct_ov004_0215534c_3** head;
    Struct_ov004_0215534c_3* node;
    unsigned char* flags;
    short i;
    short j;
    int id;
    Struct_ov004_0215534c_4* slot;

    list = func_ov011_021849c8(ctx);
    grid = (Struct_ov004_02153e20*)func_ov023_021f6880(list, 0x2c);
    if (!grid) return 0;
    if (func_ov023_021f6f10(grid) != 7) return 0;
    x = grid->x;
    y = grid->y;
    obj = (Struct_ov004_0215534c*)func_ov023_021f6880(list, 0x39);
    if (!obj) return 0;
    if (func_ov023_021f6f10(obj) != 0x12) return 0;
    head = obj->inline_ov004_0215534c_60();
    if (!head) return 0;
    node = *head;
    if (!node) return 0;
    flags = (unsigned char*)Scenario_GetInstance();

    short start = x * 16;
    i = 0;
    while (node) {
        if (i == start) break;
        i++;
        node = node->next;
    }

    for (j = 0; j < 16; j++) {
        id = j + 0x1a;
        slot = (Struct_ov004_0215534c_4*)func_ov023_021f6880(list, id);
        if (slot && func_ov023_021f6f10(slot) == 8) {
            slot->value = 0;
            slot->flags &= ~8;
            if (!node) {
                func_ov023_021f9b30(grid, 0, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                slot->flags |= 8;
            } else {
                func_ov023_021f9b30(grid, (unsigned short)id, (unsigned short)(j >> 1), (unsigned short)(j & 1));
                Struct_ov004_0215534c_2* entry = node->entry;
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

    func_ov023_021f9da0(grid, 1);
    func_ov023_021f9d14(grid, ctx);
    func_ov023_021f6630((int)ctx, 3, x, y);
    func_ov004_021552b8(ctx);
    return 0;
}
