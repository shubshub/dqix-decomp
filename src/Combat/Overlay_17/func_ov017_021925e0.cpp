#include <globaldefs.h>
#include "Resource/GameResources.h"

struct SearchStruct;
struct Obj_021bd3a4 { unsigned char pad0[2]; unsigned char f2; unsigned char f3; unsigned char pad1[0x96]; unsigned char unknown_9a_; };

struct Struct_ov017_021925e0 {
    unsigned int unknown_0_0_ : 27;
    unsigned int unknown_3_3_ : 5;
};

extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" int func_ov017_021bd3a4(struct Obj_021bd3a4* obj);

// USA: func_ov017_021925e0
extern "C" ARM int func_ov017_021925e0(void) {
#if defined(jpn)
 enum {regionalOffset0=0x524, regionalOffset1=0xfd, regionalOffset2=0xf4, regionalOffset3=0xfb, regionalOffset4=0xcb};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x101, regionalOffset2=0xf8, regionalOffset3=0xff, regionalOffset4=0xcf};
#endif
    char* base = (char*)GetGameResources();
    unsigned char* obj = *(unsigned char**)(base + 0x3000 + regionalOffset0);
    if (!LinkSession_IsGuest(LinkSession_GetInstance())) {
        goto ret0;
    }
    if (func_ov017_021bd3a4((struct Obj_021bd3a4*)obj)) {
        if (*(unsigned char*)(obj + regionalOffset1) == 0) {
            goto ret0;
        }
    } else {
        goto ret0;
    }
    if (*(unsigned char*)(obj + regionalOffset1) == 0) {
        goto skip;
    }
    if (((struct Struct_ov017_021925e0*)(obj + regionalOffset2))->unknown_0_0_ & 4) {
        goto ret0;
    }
skip:
    if (obj[regionalOffset3] != 0) {
        goto ret0;
    }
    if (obj[regionalOffset4] != 2) {
        return 1;
    }
ret0:
    return 0;
}
