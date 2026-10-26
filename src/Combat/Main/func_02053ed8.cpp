#include <globaldefs.h>
#include "World/Object3D.h"

struct U16Field0x6_020375f8;
struct Vector3i;

// USA: func_02053ed8
extern "C" ARM void func_02053ed8(void* obj) {
#if defined(jpn)
    enum { regionalOffset0 = 0x150 };
#else
    enum { regionalOffset0 = 0x15c };
#endif
    *(int*)((char*)obj + regionalOffset0) = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    *(Vector3i*)((int*)((char*)obj + regionalOffset0 + 4)) = *(Vector3i const*)((int*)((char*)obj + 0x44));
    *(Vector3i*)((int*)((char*)obj + regionalOffset0 + 0x10)) = *(Vector3i const*)((int*)((char*)obj + 0x50));
}
