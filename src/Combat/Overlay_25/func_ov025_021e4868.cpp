#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S0204a438;
extern "C" void* func_0204a438(struct S0204a438* p);
extern "C" int Camera_GetKindFlags(int obj);
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
struct Struct_02059cfc_4;
struct Struct_ov008_021870e4;
extern int data_ov025_021ef988;

struct Struct_ov025_021eef58 { const char* v[8]; };
extern struct Struct_ov025_021eef58 data_ov025_021eef58;

struct Struct_ov025_021e4868 { char pad[8]; unsigned char field8; char pad1; short fieldA; };

struct Struct_ov025_021e4868_2 {
    struct Struct_ov025_021eef58 names;
    int id;
    char pad[0x1c];
};

#if defined(jpn)
enum { Enum_ov025_021e4868_28 = 0xc };
#else
enum { Enum_ov025_021e4868_28 = 0x1c };
#endif

// USA: func_ov025_021e4868
extern "C" ARM int func_ov025_021e4868(struct Struct_ov025_021e4868* p, int b, int arg2, int d) {
    struct Struct_ov025_021e4868_2 local;
    void* obj;
    unsigned int i;

    if (*(int*)((char*)&data_ov025_021ef988 + Enum_ov025_021e4868_28) & 4) {
        return 0;
    }
    GameState* battle = GameState::GetInstance();
    if (p->field8 == 0x19) {
        void* val = battle->GetCamera();
        if (Camera_GetKindFlags((int)val) & 0x10) {
            obj = func_0204a438((struct S0204a438*)val);
        } else {
            return 1;
        }
    } else {
        if (func_ov000_021820bc((void*)d, b, p->field8, (int)&local.id) != 1) {
            return 1;
        }
        obj = battle->GetGameObjectByIndex(local.id);
    }
    if (!obj) {
        return 1;
    }
    if (p->fieldA < 0x1000) {
        return *(int*)((char*)obj + 0x24) >= p->fieldA;
    }
    if (((Object3D*)((struct Struct_02059cfc_4*)obj))->HasAnimationStopped() || ((Object3D*)((struct Struct_ov008_021870e4*)obj))->HasAnimationReachedEnd()) {
        return 1;
    }
    if (((Object3D*)obj)->GetFlag(0x40000)) {
        return 1;
    }
    if (*(unsigned char*)((char*)obj + 0x19) & 1) {
        goto ReturnZero;
    }
    char* name = *(char**)((char*)obj + 0x14);
    if (!name) {
        goto ReturnZero;
    }
    local.names = data_ov025_021eef58;
    {
        const char** entry = local.names.v;
        for (i = 0; i < 8; i++, entry++) {
            if (strcmp(name, *entry) == 0) {
                return 1;
            }
        }
    }
ReturnZero:
    return 0;
}
