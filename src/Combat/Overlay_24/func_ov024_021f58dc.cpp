#include <globaldefs.h>

struct Struct_ov024_021fea1c { int keys[2]; };
extern "C" int func_ov000_0215fb54(int unused, int key, Struct_ov024_021fea1c* out);
extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02162d88(void* obj, int key);

struct Struct_ov024_021f58dc { char pad0; unsigned char flags : 4; unsigned char pad1 : 4; };
struct Struct_ov024_021f58dc_2 { int field0; };
struct Struct_ov024_021f58dc_3 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    char pad8[0x18 - 0x8];
    unsigned int unknown_18_0_ : 5;
    unsigned int kind : 7;
    unsigned int rest18 : 20;
};
extern Struct_ov024_021fea1c data_ov024_021fea1c[];

// USA: func_ov024_021f58dc
extern "C" ARM int func_ov024_021f58dc(Struct_ov024_021f58dc_2* obj, int id, Struct_ov024_021f58dc_3* skill, int* outCount, short* arg4) {
    void* work;
    Struct_ov024_021f58dc* gate = (Struct_ov024_021f58dc*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    work = func_ov000_02160130();
    if (!work) return 0;
    if (skill->kind == 0xc) {
        Struct_ov024_021fea1c keys;
        keys.keys[1] = data_ov024_021fea1c[30].keys[1];
        keys.keys[0] = data_ov024_021fea1c[30].keys[0];
        int count = func_ov000_0215fb54(obj->field0, skill->id, &keys);
        for (int i = 0; i < count; i++) {
            if (!func_ov000_02162d88(work, keys.keys[i])) return 0;
        }
    }
    if (gate->flags >= 2) return 0;
    *outCount = 1;
    *arg4 = id;
    return 1;
}
