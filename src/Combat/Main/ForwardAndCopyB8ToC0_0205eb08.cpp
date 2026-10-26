#include <globaldefs.h>

void SoundPlayer_RestoreHeapState(void* obj, int arg2);

struct Obj0205eb08 {
    char pad_00[0xb8];
    int field_b8;
    char pad_bc[4];
    int field_c0;
};

// USA: func_0205eb08
ARM void ForwardAndCopyB8ToC0_0205eb08(struct Obj0205eb08* obj) {
    SoundPlayer_RestoreHeapState(obj, obj->field_b8);
    obj->field_c0 = obj->field_b8;
}
