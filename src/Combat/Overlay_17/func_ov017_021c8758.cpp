#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c8758 {
    Vector3i position;
    short index;
    unsigned short id;
};

struct Struct_ov017_021c8758_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021c8758 fields;
};

// USA: func_ov017_021c8758
extern "C" ARM void func_ov017_021c8758(unsigned short id) {
#if defined(jpn)
 enum { regionalOffset=0x508 };
#else
 enum { regionalOffset=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GetGameResources();
    void* data = LinkMessageQueue_GetInstance();
    void* field = func_ov017_021b8470(*(void**)(base + 0x3000 + regionalOffset));
    if (field == NULL) {
        return;
    }

    short ids[8];
    struct Struct_ov017_021c8758_2 var5;
    struct Struct_ov017_021c8758_2 var6;

    int count = func_ov000_0215e9fc(field, ids, 8, 0x10);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(ids[i]);
        unsigned char* obj;
        if (c == NULL || (obj = *(unsigned char**)((unsigned char*)c + 0x13c)) == NULL) {
            continue;
        }
        memset(&var5, 0, sizeof(var5));
        var5.tag = 0x78;
        struct Struct_ov017_021c8758* fp = &var5.fields;
        fp->id = id;
        fp->index = ids[i];
        fp->position = *(Vector3i*)(obj + 0x10);
        func_0205e330(data, &var5, 0);
    }

    count = func_ov000_0215eb1c(field, ids, 8, 0x10);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(ids[i]);
        unsigned char* obj;
        if (c == NULL || (obj = *(unsigned char**)((unsigned char*)c + 0x13c)) == NULL) {
            continue;
        }
        memset(&var6, 0, sizeof(var6));
        var6.tag = 0x78;
        struct Struct_ov017_021c8758* fp = &var6.fields;
        fp->id = id;
        fp->index = ids[i];
        fp->position = *(Vector3i*)(obj + 0x10);
        func_0205e330(data, &var6, 0);
    }
}
