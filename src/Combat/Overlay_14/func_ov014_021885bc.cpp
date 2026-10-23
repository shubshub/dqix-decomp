#if defined(jpn)
#define func_ov014_021885bc func_ov014_0218948c
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

void ClearSublistEntriesFlag1_02080bac(void* obj, int id);
void ClearSublistEntriesFlag2_0208065c(void* obj, int id);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
void AddSublistEntryFlag2_020806b0(void* obj, int id);
void SetEntryFlagById02080b2c(void* obj, int id);
void SetOrClearEntryFlag0x102081130(void* obj, int id, int flag);
extern "C" int func_020813ec(void* obj, int id);
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
struct ListHeadStruct021874f8;
short CountLinkedListNodes_021874f8(struct ListHeadStruct021874f8* obj);
struct S02187520;
short FindIndexDiv16_02187520(struct S02187520* s);

struct Struct_ov014_021885bc {
    struct Struct_ov014_021885bc* unknown_0_;
    char unknown_4_[4];
    int unknown_8_;
    char unknown_c_[0x13 - 0xc];
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
};

// USA: func_ov014_021885bc
extern "C" ARM void func_ov014_021885bc(void* arg0) {
    void* var0 = *(void**)((char*)arg0 + 0xc0);
    short var1 = *(short*)((char*)arg0 + 0x176);
    *(short*)((char*)var0 + LOW_REGION(0x2a, 0x36)) = var1;
    func_02080bac(var0, 5);
    func_0208065c(var0, 5);

    struct SubEntry021885bc* node = *(struct SubEntry021885bc**)((char*)self + 0xbc);
    short id = 0x1b;
    short count = 0;
    for (; count < 0x10; id++, count++) {
        if (node != NULL) {
            int v = KeyTable_Get((struct Container020e0310*)((char*)self + 0xe0), 0x15);
            SetEntryFirstField02080f8c((struct Container02080f8c*)list, id, v);
            if (node->flagBit1) {
                SetEntryFirstField02080f8c((struct Container02080f8c*)*(void**)((char*)self + 0xc0), id, node->field8);
            }
            var2 = var2->unknown_0_;
        } else {
            func_020806b0(var0, var3);
            func_02080b2c(var0, var3);
        }
    }

    short var6 = func_ov014_021874f8((struct Struct_ov014_02186bc8_3*)arg0);
    short var7 = (short)(func_ov014_02187520((struct Struct_ov014_021872dc*)arg0) + 1);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x2b, var7);
    short var8 = (short)((var6 + 0xf) / 0x10);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x2d, var8);
    int var9 = (var6 > 0x10) ? 1 : 0;
    func_02081130(var0, 5, var9);
    func_020813ec(var0, 5);
}
