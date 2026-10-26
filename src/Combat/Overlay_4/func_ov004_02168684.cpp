#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov004_02170038 { unsigned int w[0x88 / 4]; };
extern struct Struct_ov004_02170038 data_ov004_02170038;
extern "C" void func_ov011_02184a24(void* target, void* buf, int kind);

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);

struct Struct_0203de84 { unsigned int v[3]; };
struct Node020406f8;
extern "C" void func_020406f8(struct Struct_0203de84* dst, struct Node020406f8* n);

struct Vec3 { int x; int y; int z; };
struct Vector3i;
int Vector3fixAngleToPoint(Vector3i const*, Vector3i const*);
struct Struct_ov004_02168684 { unsigned int w[3]; };

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

// USA: func_ov004_02168684
extern "C" ARM void func_ov004_02168684(SafeAllocator* a, void* target) {
    struct Struct_ov004_02170038 tmp = data_ov004_02170038;
    void* buf = a->Allocate(0x88);
    memcpy(buf, &tmp, 0x88);
    func_ov011_02184a24(target, buf, 0x22);

    GameState* bs = GameState::GetInstance();
    void* entry = func_0203df78(func_0203cf4c(), 0x67);
    if (!entry) return;
    GameObject* combatant = bs->GetLeader();
    if (!combatant) return;

    struct Struct_0203de84 var5;
    func_020406f8(&var5, (struct Node020406f8*)entry);
    struct Struct_ov004_02168684 selfPos;
    struct Struct_ov004_02168684 var7;
    var7 = *(struct Struct_ov004_02168684*)&var5;
    selfPos = *(struct Struct_ov004_02168684*)((char*)combatant + 0x44);
    int angle = Vector3fixAngleToPoint((Vector3i const*)&selfPos, (Vector3i const*)&var7);
    GameObject_SetFacing((struct Obj02033834*)combatant, angle);
}
