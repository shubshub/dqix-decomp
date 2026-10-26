#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/MessageUpdate.h"
#include "Resource/MessageSystem.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"

struct SearchStruct0202c1a4;
struct HeadNode02046b24;
struct FieldTaskQueue;
struct Obj0208b088;
struct Struct_0203dd20_2;
struct Struct_020579b4;
struct ResetObj020d7a5c;
struct Struct_ov017_021d82fc_6 { char unknown_0_[0xe]; unsigned char active; };
extern "C" void* LinkSession_GetInstance();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" Struct_020579b4* func_02057924();
extern "C" void* NumberPopups_GetInstance();
extern "C" void* func_0203cf4c();
extern "C" void* func_02010768(void*);
extern "C" int MessageSystem_GetInstance();
extern "C" ResetObj020d7a5c* TextQueue_GetInstance();
extern "C" void* func_020e2ff8();
extern "C" void func_ov017_0218d8cc(GameResources*);
extern "C" unsigned char func_0200fb9c(char*);
extern "C" int func_0201201c(void*);
void Stub(GameResources*);
extern "C" void func_ov017_021941fc(GameResources*);
extern "C" void GameObject_ApplyPendingControl(void*);
extern "C" void func_ov017_0219a674(unsigned char*);
extern "C" void Zone3D_Update(void*);
extern "C" void func_020d9834(int);
extern "C" void MapDisplay_Update(void*);
extern "C" void func_ov017_021a624c(GameResources*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_ov017_0219a6b8(GameResources*);
extern "C" void func_020966e0(void*);
extern "C" void FieldTaskQueue_Update(FieldTaskQueue*);
extern "C" void func_020a654c(GameResources*);
extern "C" void func_020ac9ac(GameResources*);
extern "C" void func_02011b68(GameState*);
extern "C" int Camera_GetKindFlags(int);
extern "C" void FollowCamera_Update(void*);
extern "C" void func_ov000_0216d464(void*);
extern "C" void func_0204a170(void*);
extern "C" void func_ov017_0218d0ec(GameResources*);
extern "C" int LinkSession_IsActive(int*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_021a205c(GameResources*);
extern "C" int func_ov017_02196430(GameResources*);
extern "C" int func_ov017_02196c4c(GameResources*);
extern "C" void func_ov017_021c25ac(GameResources*);
extern "C" void func_ov017_021a476c(GameResources*);
extern "C" void func_ov017_0219755c(unsigned char*);
extern "C" void func_ov017_021a51a4(GameResources*);
extern "C" void func_ov017_021c05f4(GameResources*, int, int, int);
extern "C" void* func_0208e9e8();
extern "C" void func_0208ec78(void*);
extern "C" void func_0208f4e4(unsigned char*);
extern "C" void* func_0208a9b4();
extern "C" void func_0208b088(Obj0208b088*);
extern "C" void func_0203dd20(Struct_0203dd20_2*);
extern "C" void func_ov017_0218d06c(GameResources*);
extern "C" void func_020da2fc(Struct_ov017_021d82fc_6*);
extern "C" void func_020579b4(Struct_020579b4*, int);
extern "C" void func_ov017_02192700(GameResources*);
extern "C" void func_020d7b04(ResetObj020d7a5c*);
extern "C" void func_ov028_021d9734();
extern "C" void func_ov017_0219ca88(GameResources*);
extern "C" void func_ov017_02191bdc(unsigned char*, int);
extern "C" void func_ov017_02199f08(GameResources*);
extern "C" void func_ov017_0219aa7c(GameResources*);
extern "C" int* func_020936f8();
extern "C" void func_02093b90(int*, unsigned int);
extern "C" void func_ov017_021a4e48(unsigned char*);
void UpdateBrightnessTransitions(GameResources*);
extern "C" void func_020e30f0(void*);
extern "C" void func_ov017_0218d818(unsigned char*);
extern Struct_ov017_021d82fc_6 data_ov017_021d82fc;

// USA: func_ov017_0218cbd4
extern "C" ARM void func_ov017_0218cbd4(GameResources* self) {
    GameState* state = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    Zone3D* world = Zone3D_GetInstance();
    Struct_020579b4* array = func_02057924();
    NumberPopups_GetInstance();
    GameObject* actor = state->GetLeader();
    unsigned int ticks = state->GetTickCount();
    Struct_0203dd20_2* scales = (Struct_0203dd20_2*)func_0203cf4c();
    void** field = (void**)func_02010768(state);
    MessageSystem* message = (MessageSystem*)MessageSystem_GetInstance();
    ResetObj020d7a5c* reset = TextQueue_GetInstance();
    void* entries = func_020e2ff8();
    func_ov017_0218d8cc(self);
    int paused = 0;
    if (func_0200fb9c((char*)state) == 6 || func_0201201c(state) == 5) paused = 1;
    int dispatch = 0;
    if (TestFlags00(self, 0x4000)) dispatch = 1;
    Stub(self);
    func_ov017_021941fc(self);
    if (!paused) {
        GameObject_ApplyPendingControl(actor);
        (*(Vector3i*)(self->unknown_432c + 0x1c)) = actor->obj3D_.position_;
    }
    func_ov017_0219a674((unsigned char*)&self->interactionSelection);
    if (!TestFlags00(self, 4)) {
        Zone3D_Update(world);
        if (dispatch) func_020d9834(1);
    }
    if (!paused && *field) Zone3D_Update(*field);
    MapDisplay_Update(self->unknown_ptr_36d0);
    func_ov017_021a624c(self);
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) != 3)
        func_ov017_0219a6b8(self);
    if (message->active && !((unsigned char*)self->fieldTasks_[13])[2]) {
        message->func_020444d4(ticks);
    }
    func_020966e0(self->unknown_ptr_4328);
    FieldTaskQueue_Update((FieldTaskQueue*)self->fieldTaskQueue_);
    func_020a654c(self);
    func_020ac9ac(self);
    func_02011b68(state);
    void* animation = state->GetCamera();
    if (animation) {
        if (Camera_GetKindFlags((int)animation) & 4) FollowCamera_Update(animation);
        else if (Camera_GetKindFlags((int)animation) & 8) func_ov000_0216d464(animation);
        else if (Camera_GetKindFlags((int)animation) & 16) func_0204a170(animation);
    }
    func_ov017_0218d0ec(self);
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) != 3) {
        if (!LinkSession_IsActive((int*)search) || LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) == 0)
            func_ov017_021a205c(self);
    }
    int stateA = func_ov017_02196430(self);
    int stateB = func_ov017_02196c4c(self);
    if (stateA == 2 || stateB == 2) self->unknown_42e3[5] = 0;
    if (!paused) {
        func_ov017_021c25ac(self);
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) != 3 &&
            FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) != 2 && !self->fieldButtonState[0]) {
            func_ov017_021a476c(self);
            func_ov017_0219755c((unsigned char*)self);
            func_ov017_021a51a4(self);
            func_ov017_021c05f4(self, 1, 0, 1);
        }
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->fieldTaskQueue_) != 3) {
            func_0208ec78(func_0208e9e8());
            func_0208f4e4((unsigned char*)world->unk_2664);
        }
        if (!((unsigned char*)self->fieldTasks_[13])[2]) func_0208b088((Obj0208b088*)func_0208a9b4());
        func_0203dd20(scales);
        if (dispatch) func_020d9834(0);
        func_ov017_0218d06c(self);
        if (dispatch) func_020d9834(0);
        if (data_ov017_021d82fc.active) func_020da2fc(&data_ov017_021d82fc);
        func_020579b4(array, ticks);
        if (!world->unknown_424_) func_ov017_02192700(self);
        if (!TestFlags00(self, 16))
            FieldTaskQueue_Update((FieldTaskQueue*)self->unknown_ptr_array_3700[0]);
        if (!TestFlags00(self, 128))
            FieldTaskQueue_Update((FieldTaskQueue*)self->unknown_ptr_array_3700[1]);
        func_020d7b04(reset);
        if (TestFlags00(self, 0x1000)) func_ov028_021d9734();
        if (dispatch) func_020d9834(1);
    }
    func_ov017_0219ca88(self);
    func_ov017_02191bdc((unsigned char*)self, 0);
    if (!paused) {
        func_ov017_02199f08(self);
        func_ov017_0219aa7c(self);
    }
    int* var16 = func_020936f8();
    func_02093b90(var16, state->GetTickCount());
    func_ov017_021a4e48((unsigned char*)self);
    UpdateBrightnessTransitions(self);
    if (dispatch) func_020d9834(0);
    func_020e30f0(entries);
    func_ov017_0218d818((unsigned char*)self);
}
