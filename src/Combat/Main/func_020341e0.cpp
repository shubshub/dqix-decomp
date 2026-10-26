#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct Struct_020341e0 {
    signed short x;
    signed short y;
    signed short z;
};
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct Struct_020341e0_2 {
    int v[3];
};

struct Struct_020341e0_3 {
    unsigned char unknown_0_0_ : 2;
};

// USA: func_020341e0
extern "C" ARM void func_020341e0(Struct_020341e0_2* dst, void* obj) {
    void* thing = LinkSession_GetInstance();
    (int)GetGameResources();
    if (LinkSession_IsActive((int*)thing)) {
        short field4 = *(short*)((char*)obj + 4);
        if (LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4)) {
            field4 = *(short*)((char*)obj + 4);
            signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)thing);
            if (cur != field4) {
                Struct_020341e0_3* flags = (Struct_020341e0_3*)((char*)obj + 0xc1);
                if (flags->unknown_0_0_ & 1) {
                    field4 = *(short*)((char*)obj + 4);
                    void* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
                    Struct_020341e0 tmp;
                    Vector3fix16Copy((Vector3s*)&tmp, (Vector3s const*)((char*)entry + 8));
                    Struct_020341e0_2 var6;
                    var6.v[0] = tmp.x << 7;
                    var6.v[1] = tmp.y << 7;
                    var6.v[2] = tmp.z << 7;
                    *dst = var6;
                    return;
                }
            }
        }
    }
    *dst = *(Struct_020341e0_2*)((char*)obj + 0x44);
}
