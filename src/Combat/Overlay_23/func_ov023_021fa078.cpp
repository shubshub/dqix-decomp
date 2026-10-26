#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

struct Struct_ov023_021fa03c;
struct Struct_ov023_021fa03c_2;
extern "C" Struct_ov023_021fa03c_2* func_ov023_021fa03c(Struct_ov023_021fa03c*);
struct Struct_ov023_021f9eb4;
extern "C" void func_ov023_021f9eb4(Struct_ov023_021f9eb4*);
extern "C" void* func_ov011_021849c8(void*);

class Struct_ov023_021fa078 {
public:
    virtual void v00(); virtual void inline_ov023_021fa078_2(); virtual void inline_ov023_021fa078_3(); virtual void inline_ov023_021fa078_4();
    virtual void v04(); virtual void inline_ov023_021fa078_6(); virtual void inline_ov023_021fa078_7(); virtual void inline_ov023_021fa078_8();
    virtual Vector3i inline_ov023_021fa078_9();
};

extern "C" Struct_ov023_021fa078* func_ov023_021f6880(void*, int);

struct Struct_ov023_021fa078_2 {
    unsigned short field0;
    unsigned char field2;
    unsigned char unknown_3_;
    int field4;
    int field8;
    int fieldc;
    Vector3i field10;
    Vector3i field1c;
};

// USA: func_ov023_021fa078
extern "C" ARM void func_ov023_021fa078(Struct_ov023_021fa03c* obj, void* ctx, unsigned short val, Vector3i* arg3, int p5, int p6) {
    Struct_ov023_021fa078_2* slot = (Struct_ov023_021fa078_2*)func_ov023_021fa03c(obj);
    if (slot == NULL) return;
    func_ov023_021f9eb4((Struct_ov023_021f9eb4*)slot);
    slot->field2 = 1;
    slot->field0 = val;
    void* base = func_ov011_021849c8(ctx);
    Struct_ov023_021fa078* node = func_ov023_021f6880(base, slot->field0);
    if (node == NULL) return;
    slot->field4 = 0;
    slot->field8 = p6;
    slot->fieldc = p5;
    slot->field10 = node->inline_ov023_021fa078_9();
    slot->field1c = *arg3;
}
