#include <globaldefs.h>

struct Struct_ov024_021fea1c { int unknown_0_; int x1; };
extern "C" int func_ov000_0215fb54(int unused, int key, Struct_ov024_021fea1c* out);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02162d88(void* obj, int key);

struct Struct_ov024_021f5478 { char pad0; unsigned char flags : 4; unsigned char pad1 : 4; };
struct Struct_ov024_021f5478_2 { int field0; };
struct Struct_ov024_021f5478_3 {
    int field0;
    unsigned int key : 12;
    unsigned int pad4 : 20;
    char pad8[0x10];
    unsigned int pad18 : 5;
    unsigned int kind : 7;
    unsigned int unknown_19_4_ : 20;
};
extern const Struct_ov024_021fea1c data_ov024_021fea1c[];

// USA: func_ov024_021f5478
extern "C" ARM int func_ov024_021f5478(struct Struct_ov024_021f5478_2* obj, int id, struct Struct_ov024_021f5478_3* action, int* outCount, short* arg4) {
    void* work;
    struct Struct_ov024_021f5478* gate = (struct Struct_ov024_021f5478*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    work = func_ov000_02160130();
    if (!work) return 0;
    if (action->kind == 0xc) {
        Struct_ov024_021fea1c out;
        out.x1 = data_ov024_021fea1c[37].x1;
        out.unknown_0_ = data_ov024_021fea1c[37].unknown_0_;
        int count = func_ov000_0215fb54(obj->field0, action->key, &out);
        for (int i = 0; i < count; i++) {
            if (!func_ov000_02162d88(work, (&out.unknown_0_)[i])) return 0;
        }
    }
    if (gate->flags >= 4) return 0;
    *outCount = 1;
    *arg4 = id;
    return 1;
}
