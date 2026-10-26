#include <globaldefs.h>

int LinkSession_IsActive(int*);

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

int TrySetMode02076ccc(void*, int);

extern "C" void* LinkSession_GetInstance(void* obj);
extern "C" unsigned short func_02078e60(void* obj, char* out);

struct Obj02078d84 {
    char pad1[0x138];
    unsigned char field138;
    char pad2[0x13];
    unsigned int field14c;
    char pad3[0x14];
    unsigned short field164;
};

// USA: func_02078d84
ARM void UpdateActorMode02078d84(struct Obj02078d84* obj) {
    void* s = LinkSession_GetInstance(obj);
    if (LinkSession_IsActive((int*)s) != 0) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)s) != 0) {
            return;
        }
    }
    if (obj->field14c <= 0xbb8) {
        return;
    }
    char localFlag = 0;
    switch (obj->field138) {
    case 0:
        TrySetMode02076ccc(obj, 1);
        return;
    case 1:
    case 3:
    case 4:
    case 5:
#if !defined(jpn)
        if (TrySetMode02076ccc(obj, 2) != 0) {
            return;
        }
        obj->field164 = func_02078e60(obj, &localFlag);
#endif
        TrySetMode02076ccc(obj, 2);
        return;
    case 2:
        obj->field164 = func_02078e60(obj, &localFlag);
        TrySetMode02076ccc(obj, 3);
        return;
    }
}
