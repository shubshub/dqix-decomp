#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct FlagsByte0xc1_02034104 {
    unsigned char lowBits2 : 2;
};

// USA: func_02034104
extern "C" ARM Vector3fix func_02034104(void* obj) {
    Object3D* object = (Object3D*)obj;
    void* thing = LinkSession_GetInstance();
    GetGameResources();
    if (LinkSession_IsActive((int*)thing)) {
        if (LinkSession_IsHostOrSolo(thing)) {
            short field4 = object->actorIndex_;
            if (LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4)) {
                field4 = object->actorIndex_;
                signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)thing);
                if (cur != field4) {
                    FlagsByte0xc1_02034104* flags = (FlagsByte0xc1_02034104*)((char*)obj + 0xc1);
                    if (flags->lowBits2 & 1) {
                        field4 = object->actorIndex_;
                        SearchEntry0202c178* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
                        Vector3fix16 tmp;
#if defined(jpn)
                        var6.x = var5->unknown_8_;
                        var6.y = var5->unknown_a_;
                        var6.z = var5->unknown_c_;
#else
                        Vector3fix16Copy(&var6, (const Vector3fix16*)&var5->unknown_8_);
#endif
                        Vector3fix var7;
                        var7.x = var6.x << 7;
                        var7.y = var6.y << 7;
                        var7.z = var6.z << 7;
                        return var7;
                    }
                }
            }
        }
    }
    return var0->position_;
}
