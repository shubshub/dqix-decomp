#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct Struct_02034104 {
    unsigned char unknown_0_0_ : 2;
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
                    Struct_02034104* flags = (Struct_02034104*)((char*)obj + 0xc1);
                    if (flags->unknown_0_0_ & 1) {
                        field4 = object->actorIndex_;
                        SearchEntry0202c178* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
                        Vector3fix16 tmp;
#if defined(jpn)
                        tmp.x = entry->x;
                        tmp.y = entry->y;
                        tmp.z = entry->z;
#else
                        Vector3fix16Copy(&tmp, (const Vector3fix16*)&entry->x);
#endif
                        Vector3fix var7;
                        var7.x = tmp.x << 7;
                        var7.y = tmp.y << 7;
                        var7.z = tmp.z << 7;
                        return var7;
                    }
                }
            }
        }
    }
    return object->position_;
}
