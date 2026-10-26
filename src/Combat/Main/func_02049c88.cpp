#include <globaldefs.h>
#include "Graphics/AlphaTween.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct Struct_02049c88 { int x; int y; int z; };
struct Struct_02049520_2 { unsigned char field0; unsigned char field1; unsigned short field2; unsigned short field4; unsigned char field6; };
struct Struct_02049c88_2 {
    int field0;
    Struct_02049c88 position;
    Struct_02049c88 direction;
    unsigned char unknown_1c_[4];
    int flags;
    char unknown24[0x1c];
    Struct_02049c88 unknown_40_;
    unsigned char unknown_4c_;
    unsigned char unknown_4d_;
    Struct_02049520_2 fields;
    unsigned char unknown_56_;
    char unknown_57_;
    char unknown_58_[6];
    char unknown_5e_[2];
    AlphaTween alpha;
    int field68;
    unsigned char unknown_6c_;
    char unknown_6d_[3];
};
struct Struct_02049c88_3 { GameObject base; Struct_02049c88_2* state; };
extern "C" void func_02049550(Struct_02049520_2*);

// USA: func_02049c88
extern "C" ARM void func_02049c88(Struct_02049c88_3* object, Struct_02049c88_2* state) {
    object->state = state;
    if (!object->state) return;
    memset(object->state, 0, 0x70);
    object->state->field0 = 0;
    Struct_02049c88* position = &object->state->position;
    position->x = 0;
    position->y = 0;
    position->z = 0;
    Struct_02049c88* direction = &object->state->direction;
    direction->x = 0;
    direction->y = 0;
    direction->z = 0;
    Struct_02049c88* vector = &object->state->unknown_40_;
    vector->x = 0;
    vector->y = 0;
    vector->z = 0;
    object->state->flags = 0;
    object->state->unknown_4c_ = 0;
    object->state->unknown_1c_[0] = 0xff;
    object->state->unknown_1c_[1] = 0xff;
    object->state->unknown_1c_[2] = 0xff;
    object->state->unknown_1c_[3] = 0xff;
    object->state->unknown_56_ = 1;
    func_02049550(&object->state->fields);
    object->state->alpha.Reset();
    memset(object->state->unknown_58_, 0, 6);
    object->state->field68 = 0;
    object->state->unknown_6c_ = 0xff;
}
