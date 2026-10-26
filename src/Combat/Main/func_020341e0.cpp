#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct Vec3s02030fc8 {
    signed short x;
    signed short y;
    signed short z;
};
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct Struct_020341e0_2 {
    int unknown_0_[3];
};

struct Struct_020341e0_3 {
    unsigned char unknown_0_0_ : 2;
};

// USA: func_020341e0
extern "C" ARM void func_020341e0(Vec3Int_020341e0* dst, void* obj) {
    void* thing = LinkSession_GetInstance();
    (int)GetGameResources();
    if (LinkSession_IsActive((int*)thing)) {
        short field4 = *(short*)((char*)obj + 4);
        if (LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4)) {
            field4 = *(short*)((char*)obj + 4);
            signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)thing);
            if (cur != field4) {
                FlagsByte0xc1_020341e0* flags = (FlagsByte0xc1_020341e0*)((char*)obj + 0xc1);
                if (flags->lowBits2 & 1) {
                    field4 = *(short*)((char*)obj + 4);
                    void* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
                    Vec3s02030fc8 tmp;
                    Vector3fix16Copy((Vector3s*)&tmp, (Vector3s const*)((char*)entry + 8));
                    Vec3Int_020341e0 scaled;
                    scaled.v[0] = tmp.x << 7;
                    scaled.v[1] = tmp.y << 7;
                    scaled.v[2] = tmp.z << 7;
                    *dst = scaled;
                    return;
                }
            }
        }
    }
    *arg0 = *(Struct_020341e0_2*)((char*)arg1 + 0x44);
}
