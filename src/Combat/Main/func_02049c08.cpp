#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void __clear(void* destination, int size);

struct Struct_02049c08 {
    int unknown0;
    Vector3i vector4;
    Vector3i unknown_10_;
};

struct Struct_02049c08_2 {
    GameObject base;
    Struct_02049c08* unknown_13c_;
};

extern "C" ARM Vector3i func_02049c08(Struct_02049c08_2* object) {
    Vector3i result;
    __clear(&result, sizeof(result));
    if (object->unknown_13c_ == NULL) return result;
    fix32_t x = object->unknown_13c_->unknown_10_.x;
    fix32_t z = object->unknown_13c_->unknown_10_.z;
    result.x = x;
    result.y = 0xcc;
    result.z = z;
    return result;
}
