#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Combat/EntryGetterTypes.h"

struct Obj0201b600 { char pad0[6]; short angle; };
struct Struct_0203dce4_2;

struct HeadNode02046b24;
struct GameResources;
struct Struct_0203cec4;
struct Struct_0203fc5c;
struct Node020406f8;
struct Struct_0203de84 { int x; int y; int z; };
struct Struct_0203d028_15;
struct Npc;
struct Struct_0203e2c4_2;
struct Struct_020aeb34 { char unknown0[0x10]; int x; int y; int z; short value; };

extern "C" void* Zone3D_GetInstance(void);
extern "C" int rand(void);
extern "C" long long fix32_SinFx64c(int phase);
extern "C" long long fix32_CosFx64c(int phase);
extern "C" float _ll_sto_f(long long);
extern "C" struct Struct_0203dce4_2* func_0203cf4c();
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24**);
extern "C" struct Obj0201b600* func_0201b600(Obj0201b600*, int, unsigned short);
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2*, int);
extern "C" void func_02040648(unsigned int*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
int IsMainBrightnessTransitionActive(struct GameResources*);
int GetMainBrightnessTransitionState(struct GameResources*);
extern "C" void func_02040774(struct Struct_0203d028_15*, int, int, int);
extern "C" void func_02040b2c(struct Struct_0203e2c4_2*, int);
extern "C" void func_020406f8(struct Struct_0203de84*, struct Node020406f8*);
extern "C" void func_0203cec4(struct Struct_0203cec4*, int);
extern "C" void func_0203fc5c(struct Struct_0203fc5c*, float);
extern "C" void Npc_WalkTo(struct Npc*, int);

// USA: func_020aeb34
extern "C" ARM void func_020aeb34(void) {
    struct Struct_0203dce4_2* list;
    struct Struct_0203dce4* arr[4];
    GameResources* base;
    struct Obj0201b600* elem;
    int i;
    struct HeadNode02046b24** head;

    elem = (struct Obj0201b600*)Zone3D_GetInstance();
    list = func_0203cf4c();
    base = GetGameResources();
    head = (HeadNode02046b24**)base->fieldTaskQueue_;
    FieldTaskQueue_GetCurrentKind(head);
    elem = func_0201b600(elem, 0, 0x2a);

    if (elem == NULL) return;

    for (i = 0; i < 4; i++) {
        arr[i] = func_0203dce4(list, base->unknown_444a_[i]);
        if (arr[i] == NULL) return;
        func_02040648((unsigned int*)arr[i]);
    }

    if (FieldTaskQueue_IsEmpty((void**)head) == 0 && IsMainBrightnessTransitionActive(base) == 0 &&
        (GetMainBrightnessTransitionState(base) == 2 ||
         GetMainBrightnessTransitionState(base) == 3)) {
        if (elem->angle != 0) return;
        for (int j = 0; j < 4; j++) {
            Struct_020aeb34* s = (Struct_020aeb34*)func_02040538((Struct_0203e0a0*)arr[j]);
            func_02040774((struct Struct_0203d028_15*)arr[j], s->x, s->y, s->z);
            func_02040b2c((struct Struct_0203e2c4_2*)arr[j], s->value);
        }
        return;
    }

    base->unknown_4454_ += 2 * (rand() % 13 - 6);
    if (base->unknown_4454_ > 0x2d) base->unknown_4454_ = 0x2d;
    if (base->unknown_4454_ < 0x20) base->unknown_4454_ = 0x20;

    int var8 = 88006;
    if (elem->angle <= base->unknown_4454_) {
        elem->angle += 0x6487;
    }
    elem->angle -= base->unknown_4454_;

    int angle = elem->angle;

    for (int k = 0; k < 4; k++) {
        int phase;
        Vector3fix vecB;
        Vector3fix vecA;
        Vector3fix out;
        struct Struct_0203de84 sel;

        angle += 0x1921;
        if (angle >= 0x6487) angle -= 0x6487;
        phase = angle - 0xcc;
        if (phase <= 0) phase += 0x6487;

        vecB.x = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(phase)) / 4294967296.0f)) * 2;
        vecB.y = 0;
        vecB.z = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(phase)) / 4294967296.0f)) * 2;

        vecA.x = var8;
        struct Struct_0203dce4* entry = arr[k];
        func_020406f8(&sel, (struct Node020406f8*)entry);
        vecA.z = -0x970;
        vecA.y = sel.y;

        Vector3fix_Add(&vecA, &vecB, &out);

        if ((entry->child14) != NULL) func_0203cec4((struct Struct_0203cec4*)(entry->child14), 1);
        if ((entry->child14) != NULL) func_0203fc5c((struct Struct_0203fc5c*)(entry->child14), 0.8f);
        Npc_WalkTo((struct Npc*)entry, (int)&out);
        func_02040774((struct Struct_0203d028_15*)entry, out.x, out.y, out.z);
    }
}
