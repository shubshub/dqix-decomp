#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_ov023_021f9eb4;
extern "C" void func_ov023_021f9eb4(struct Struct_ov023_021f9eb4* o);

struct Struct_ov023_021fa108 {
    unsigned short field0;
    unsigned char field2;
    unsigned char unknown_3_;
    int field4;
    int field8;
    int fieldc;
    Vector3i field10;
    Vector3i field1c;
};

class Struct_ov023_021fa108_2 {
public:
    virtual void v00(); virtual void inline_ov023_021fa108_2(); virtual void inline_ov023_021fa108_3(); virtual void inline_ov023_021fa108_4();
    virtual void v04(); virtual void inline_ov023_021fa108_6(); virtual void inline_ov023_021fa108_7();
    virtual void inline_ov023_021fa108_8(Vector3i* pos);
};

extern "C" Struct_ov023_021fa108_2* func_ov023_021f6880(void* base, int val);
extern "C" void* func_ov011_021849c8(void* ctx);

// USA: func_ov023_021fa108
extern "C" ARM void func_ov023_021fa108(void* unused, void* ctx, struct Struct_ov023_021fa108* slot) {
    Vector3i diff;
    Vector3fix_Subtract(&slot->field1c, &slot->field10, &diff);
    Vector3fix_Normalize(&diff, &diff);

    int var1 = 0;
    if (slot->unknown_3_ == 0) {
        int t = slot->field4 + slot->field8;
        slot->field4 = t;
        if (slot->fieldc < t) {
            slot->field4 = slot->fieldc;
        }
        Vector3i var3;
        Vector3fixMultiplyScalar(&diff, slot->field4, &var3);
        Vector3fix_Add(&slot->field10, &var3, &slot->field10);
        int dist = Vector3fix_Distance(&slot->field1c, &slot->field10);
        float a = (float)slot->field4 / 4096.0f;
        float var6 = a * a;
        float c = (float)slot->field8 / 4096.0f;
        int result = (int)((var6 / (2.0f * c)) * 4096.0f);
        if (dist < result) {
            slot->unknown_3_ = 1;
        }
    } else if (slot->unknown_3_ == 1) {
        int var9 = Vector3fix_Distance(&slot->field1c, &slot->field10);
        int var10;
        if (slot->field8 < slot->field4 && (var10 = slot->field4 - slot->field8) < var9) {
            slot->field4 = var10;
            Vector3i var11;
            Vector3fixMultiplyScalar(&diff, var10, &var11);
            Vector3fix_Add(&slot->field10, &var11, &slot->field10);
        } else {
            slot->field10 = slot->field1c;
            var1 = 1;
        }
    }

    void* base = func_ov011_021849c8(ctx);
    Struct_ov023_021fa108_2* node = func_ov023_021f6880(base, slot->field0);
    if (node != NULL) {
        node->inline_ov023_021fa108_8(&slot->field10);
    }
    if (var1) {
        func_ov023_021f9eb4((struct Struct_ov023_021f9eb4*)slot);
    }
}
