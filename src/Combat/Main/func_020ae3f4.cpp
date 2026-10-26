#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_020ad61c_2 {
    char pad0[0x44];
    Vector3i position;
    char pad1[0x140 - 0x50];
    int counter;
    char pad2[0x168 - 0x144];
    int unknown_168_;
    char pad3[0x178 - 0x16c];
    int unknown_178_;
};

// USA: func_020ae3f4
extern "C" ARM void func_020ae3f4(struct Struct_020ad61c_2* obj) {
    int count = obj->counter + 1;
    obj->counter = count;
    int var1 = count * count;
    Vector3i var2;
    var2 = obj->position;
    var2.y += (int)(((float)var1 * 0.005f) * 4096.0f);
    obj->position = var2;
    obj->unknown_168_ += (int)(((float)var1 * 0.005f) * 4096.0f);
    obj->unknown_178_ += (int)(((float)var1 * 0.005f) * 4096.0f);
}
