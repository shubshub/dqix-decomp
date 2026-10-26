#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02097054_6;
struct Struct_02097054_5;
extern "C" struct Struct_02097054_6* func_02097224(struct Struct_02097054_5* c, int key);

struct Vector3i;

// USA: func_ov014_02184c08
extern "C" ARM void func_ov014_02184c08(unsigned char* obj) {
    void* b = *(void**)(obj + 0x48);
    if (b == NULL) return;
    struct Struct_02097054_6* node = func_02097224((struct Struct_02097054_5*)(obj + 0xc), *(short*)((char*)b + 0xc));
    if (node == NULL) return;

    int vecA[3];
    int vecB[3];
    int var4[3];

    vecA[0] = (int)(4096.0f * *(float*)((char*)node + 0x10));
    vecA[1] = (int)(4096.0f * *(float*)((char*)node + 0x14));
    vecA[2] = (int)(4096.0f * *(float*)((char*)node + 0x18));
    vecB[0] = 0;
    vecB[1] = (int)(4096.0f * *(float*)((char*)node + 0x1c));
    vecB[2] = 0;
    var4[0] = (int)(4096.0f * *(float*)((char*)node + 0x20));
    var4[1] = (int)(4096.0f * *(float*)((char*)node + 0x24));
    var4[2] = (int)(4096.0f * *(float*)((char*)node + 0x28));

    *(Vector3i*)((int*)(*(char**)(obj + 0x40) + 0x44)) = *(Vector3i const*)vecA;
    *(Vector3i*)((int*)(*(char**)(obj + 0x40) + 0x50)) = *(Vector3i const*)vecB;
    ((Object3D*)(*(unsigned char**)(obj + 0x40)))->SetScale((Vector3i const*)var4);
}
