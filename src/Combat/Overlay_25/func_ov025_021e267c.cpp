#if defined(jpn)
enum { Enum_ov025_021e267c_12 = 0x4 };
#else
enum { Enum_ov025_021e267c_12 = 0xc };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" unsigned char func_ov025_021e8ba4(void* obj);
struct ObjectArchiveLoadInfo;

struct Struct_ov025_021e267c;
struct Struct_0208f410;

struct Struct_203dafc {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
};
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

struct Struct_ov025_021e267c_2;
struct Struct_ov025_021e267c_3 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* next;
};
extern "C" void func_ov025_021e8bac(struct Struct_ov025_021e267c_2* obj, struct Struct_ov025_021e267c_3* node);

extern int data_ov025_021ef988;

// USA: func_ov025_021e267c
extern "C" ARM void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag) {
    GameState* battle = GameState::GetInstance();
    void* var1 = *(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e267c_12);
    void* entry = func_ov025_021e8a54((char*)var1);
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    if (!combatant) return;
    struct Struct_ov025_021e267c_3* node = (struct Struct_ov025_021e267c_3*)((SafeAllocator*)entry)->Allocate(0xc);
    if (!node) return;
    char* name = *(char**)((char*)combatant + 0x14);
    char buf[0x20];
    if (name) {
        strcpy(buf, name);
    }
    void* ptr = (void*)((Object3D*)((struct Struct_ov025_021e267c*)combatant))->GetCurrentAnimationTime();
    struct Struct_203dafc s;
    func_0203dafc(&s);
    void* var9 = *(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e267c_12);
    s.fieldc = (int)entry;
    s.field4 = arg1;
    s.field8 = arg2;
    s.field10 = 1;
    unsigned char b = func_ov025_021e8ba4(var9);
    s.field1c = b + 4;
    combatant->obj3D_.LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&s, (int (*)(BCFG::AnimationRecord*))flag);
    if (name) {
        combatant->obj3D_.SetAnimationByName((char const*)buf, 0);
        ((Object3D*)((struct Struct_0208f410*)combatant))->SetCurrentAnimationTime((unsigned int)ptr);
    }
    node->byte0 = 0;
    node->unknown_2_ = combatantId;
    node->unknown_4_ = s.field1c;
    void* var11 = *(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e267c_12);
    func_ov025_021e8bac((struct Struct_ov025_021e267c_2*)var11, node);
}
