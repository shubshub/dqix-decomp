#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219bfb4_9196 = 0x240c, Enum_ov017_0219bfb4_610 = 0x282, Enum_ov017_0219bfb4_10118 = 0x27c6, Enum_ov017_0219bfb4_10116 = 0x27c4, Enum_ov017_0219bfb4_10120 = 0x27c8, Enum_ov017_0219bfb4_10100 = 0x27b4, Enum_ov017_0219bfb4_10164 = 0x27f4, Enum_ov017_0219bfb4_10166 = 0x27f6, Enum_ov017_0219bfb4_92 = 0x28, Enum_ov017_0219bfb4_2400 = 0x800 };
#else
enum { Enum_ov017_0219bfb4_9196 = 0x23ec, Enum_ov017_0219bfb4_610 = 0x262, Enum_ov017_0219bfb4_10118 = 0x2786, Enum_ov017_0219bfb4_10116 = 0x2784, Enum_ov017_0219bfb4_10120 = 0x2788, Enum_ov017_0219bfb4_10100 = 0x2774, Enum_ov017_0219bfb4_10164 = 0x27b4, Enum_ov017_0219bfb4_10166 = 0x27b6, Enum_ov017_0219bfb4_92 = 0x5c, Enum_ov017_0219bfb4_2400 = 0x960 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"


struct Struct_02013fb4;
struct Struct_020a8170;
struct Struct_020a83fc;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_020727d8;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_ov017_0219bfb4;

struct Struct_020a83fc_2 {
    char unknown_0_[0x1a];
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
    char unknown_1e_[2];
    int unknown_20_;
    int unknown_24_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
void* GameState_GetParty(GameState* gameState);
void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_0206e558(void* obj);
extern "C" int LinkSession_IsHostOrSolo(void* p);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void __clear(void* dst, unsigned int size);
void ClearStruct020a8170(Struct020a8170* s);
extern "C" void func_020a818c(void* cont, SafeAllocator* alloc);
extern "C" void func_020a8304(void* cont);
Entry020a83fc* FindEntryById020a83fc(Container020a83fc* cont, int id);
extern "C" void func_ov017_021d1a18(short a, short b, int c, int d);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
void InitStruct02070378(char* obj);
void FieldTask_InitEnterZone(unsigned char* node, int v);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void ClearFlagBytes02017d7c(void* obj);
void GameObject_ClearHidden(unsigned char* obj);
void SetFlag0x1ceBit0x4_02039d48(unsigned char* obj);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" int func_ov017_0219ff58(void* base, int a, int b, int c);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int v);
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v);
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int v);
int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
void ResetListHeader020727d8(List020727d8* list);
int GameState_GetStoryChapter(char* obj);
void SubmitAndRunScript02072928(void* list, StreamHeader* header, int length, int id, void* out, unsigned char index);
int STD_CompareString(const char* a, const char* b);
extern "C" int func_02005a94(signed char* s);
void InitState16_021ba90c(Obj021ba90c* p);
void AllocateAndCopyBuf20_021689d8(SafeAllocator* a, void* target);

extern char data_ov017_021d75d0;
extern char data_ov017_021d75dc;
extern char data_ov017_021d75fa;
extern char g_fileLoadBuffer;

static inline unsigned char inline_ov017_0219bfb4(int arg0, int arg1) {
    return arg0 * 4 + arg1;
}

// USA: func_ov017_0219bfb4
extern "C" ARM void func_ov017_0219bfb4(int mode, unsigned short id) {
    GameResources* res = GetGameResources();
    GameState* gs = GameState::GetInstance();
    char* party = (char*)GameState_GetParty(gs);
    char* record = (char*)GameState_GetZoneTransition(gs);
    void* search = LinkSession_GetInstance();
    char* field = (char*)Zone3D_GetInstance();
    unsigned char* flags = (unsigned char*)Scenario_GetInstance();
    char* status = field + kStatusOffset;
    TailList020469b4* list = (TailList020469b4*)res->fieldTaskQueue_;
    unsigned char* node = (unsigned char*)res->unknown_ptr_array_3700[3];
    unsigned char* marker = (unsigned char*)res->unknown_ptr_array_371c[4];
    BackgroundLoader::GetInstance()->FreeAllocations();

    unsigned short var11 = arg1;
    if (arg1 == 0) {
        var11 = *(int*)(var2 + 0x2c94);
    }

    if (LinkSession_IsGuest(search)) {
        func_0206e558(flags);
    }
    if (arg0 == 2) {
        var7[Enum_ov017_0219bfb4_610] = 0;
    }
    if (mode == 2 && LinkSession_IsHostOrSolo(search)) {
        if (Scenario_TestFlag((int)flags, flags + 0x8c, 0x2b)) {
            char buf[0x533];
            __clear(buf, 0x533);
            SafeAllocator alloc;
            alloc.ResetAllocatorPointer();
            alloc.ResetAllocatorPointer();
            alloc.CreateTypeA(buf, 0x533);
            char cont[0x10];
            ClearStruct020a8170((Struct020a8170*)cont);
            func_020a818c(cont, &alloc);
            func_020a8304(cont);
            Entry020a83fc* entry = FindEntryById020a83fc((Container020a83fc*)cont, sceneId);
            if (entry) {
                *(unsigned short*)(field + kFieldXOffset) = entry->x;
                *(unsigned short*)(field + kFieldYOffset) = entry->y;
                field[kFieldFlagOffset] = 0;
                Vector3i pos = *(Vector3i*)(field + kFieldPositionOffset);
                pos.x = entry->posX;
                pos.z = entry->posZ;
                *(Vector3i*)((int*)(field + kFieldPositionOffset)) = *(Vector3i const*)((int*)&pos);
                func_ov017_021d1a18(entry->x, entry->y, 0, 1);
            }
            var13.Destroy();
        }
        if (var11 == 0x119a) {
            *(unsigned short*)(var5 + Enum_ov017_0219bfb4_10164) = 1;
            *(unsigned short*)(var5 + Enum_ov017_0219bfb4_10166) = 0;
            func_ov017_021d1c2c(1, 0);
        }
    }

    if (node[2] == 0) {
        InitStruct02070378(record);
        *(unsigned short*)record = sceneId;
        record[0xc] = 0;
        FieldTask_InitEnterZone(node, 0);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    } else if (node[3] == 0) {
        InitStruct02070378(record);
        *(unsigned short*)record = sceneId;
        record[0xc] = 0;
    }

    ClearFlagBytes02017d7c(field);
    ((unsigned char*)record)[0x6e] |= 0x20;
    for (int i = 0; i < *(unsigned char*)(party + 0xf7c); i++) {
        GameObject* member = gs->GetPartyMemberByIndex(*(unsigned char*)(party + i + 0xf78));
        if (member) {
            if (i == 0) {
                GameObject_ClearHidden((unsigned char*)member);
                member->obj3D_.SetInheritedAlpha(0x1f);
            } else {
                func_02039d48((unsigned char*)var18);
                var18->obj3D_.SetInheritedAlpha(0);
            }
        }
    }

    if (var10[2] != 0) {
        return;
    }

    char* controller = (char*)MessageSystem_GetInstance();
    memset(*(void**)(controller + kControllerBufferOffset), 0, kControllerBufferSize);
    MessageSystem_Reset(controller);
    if (func_ov017_0219ff58(res, 0, 0, 1)) {
        unsigned char* obj = (unsigned char*)res->fieldTasks_[0x14];
        InitObjState_021b2174(obj);
        SetNameChecked_021b2ba0((S021b2ba0*)obj, &data_ov017_021d75d0);
        SetFields30And34_021b2bd0(obj, (int)AllocateAndCopyBuf20_021689d8, OVERLAY_ID(4));
        SetBit4_021b2bf4((S021b2bf4*)obj, 1);
        SetBit5_021b2c0c((S021b2c0c*)obj, 1);
        SetBit3_021b2bdc((S021b2bdc*)obj, 0);
        AppendNodeToTail(list, (TailNode020469b4*)obj);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    LoadFileIntoMemory(&data_ov017_021d75dc, &g_fileLoadBuffer, &length);
    if (length == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    char var22[8];
    func_020727d8((Struct_020727d8*)var22);
    char var23[8];
    __clear(var23, 8);
    short var24 = *(int*)(var2 + 0x2c94);
    if (arg1 != 0) {
        var24 = arg1;
    }
    int now = GameState_GetStoryChapter((char*)gs);
    for (int j = 0; j < 3; j++) {
        unsigned char fromIndex = GetScriptIndex(j, 0);
        unsigned char toIndex = GetScriptIndex(j, 1);
        char from[8];
        __clear(from, 8);
        char to[8];
        __clear(to, 8);
        SubmitAndRunScript02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, from, fromIndex);
        SubmitAndRunScript02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, to, toIndex);
        int start = 0;
        int end = 0;
        if (STD_CompareString(from, &data_ov017_021d75fa)) {
            start = func_02005a94((signed char*)from);
        }
        if (STD_CompareString(to, &data_ov017_021d75fa)) {
            end = func_02005a94((signed char*)to);
        }
        int var33 = 0;
        if (var31 == 0 && var32 == 0) {
            var33 = 1;
        } else if (var25 >= var31 && var25 <= var32) {
            var33 = 1;
        }
        if (var33) {
            unsigned char var34;
            if (var1->IsMorningDayOrEvening()) {
                var34 = (unsigned int)var26 * 4 + 2;
            } else {
                var34 = (unsigned int)var26 * 4 + 3;
            }
            SubmitAndRunScript02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, result, index);
            break;
        }
    }
    BackgroundLoader::RemoveLockGlobal();

    signed char state = 1;
    if (STD_CompareString(result, &data_ov017_021d75fa)) {
        state = func_02005a94((signed char*)result);
    }
    if (var35 != 3) {
        func_ov017_021ba90c((Struct_ov017_0219bfb4*)var10);
        var10[0x20] = arg0;
        var10[0x21] = var35;
        func_020469b4(var8, (Struct_0201bdac*)var10);
    }
}
