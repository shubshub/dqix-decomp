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


struct StreamHeader;
struct Struct020a8170;
struct Struct_020a83fc;
struct TailList020469b4;
struct TailNode020469b4;
struct Struct_020727d8;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_ov017_0219bfb4;

struct Struct_020a83fc_2 {
    char pad0[0x1a];
    unsigned short x;
    unsigned short y;
    char pad1e[2];
    int posX;
    int unknown_24_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_0206e558(void* obj);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" void func_020a8170(Struct020a8170* s);
extern "C" void func_020a818c(void* cont, SafeAllocator* alloc);
extern "C" void func_020a8304(void* cont);
extern "C" Struct_020a83fc_2* func_020a83fc(Struct_020a83fc* cont, int id);
extern "C" void func_ov017_021d1a18(short a, short b, int c, int d);
extern "C" void func_ov017_021d1c2c(unsigned char a, unsigned short b);
extern "C" void func_02070378(char* obj);
extern "C" void FieldTask_InitEnterZone(unsigned char* node, int v);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_02017d7c(void* obj);
extern "C" void GameObject_ClearHidden(unsigned char* obj);
extern "C" void func_02039d48(unsigned char* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int func_ov017_0219ff58(void* base, int a, int b, int c);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int a, int b);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* obj, unsigned int v);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int v);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int v);
int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" void func_02072928(void* list, StreamHeader* header, int length, int id, void* out, unsigned char index);
extern "C" int STD_CompareString(const char* a, const char* b);
extern "C" int func_02005a94(signed char* s);
extern "C" void func_ov017_021ba90c(Struct_ov017_0219bfb4* p);
extern "C" void func_ov004_021689d8(SafeAllocator* a, void* target);

extern char data_ov017_021d75d0;
extern char data_ov017_021d75dc;
extern char data_ov017_021d75fa;
extern char g_fileLoadBuffer;

static inline unsigned char inline_ov017_0219bfb4(int slot, int offset) {
    return slot * 4 + offset;
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
    char* status = field + Enum_ov017_0219bfb4_9196;
    TailList020469b4* list = (TailList020469b4*)res->fieldTaskQueue_;
    unsigned char* node = (unsigned char*)res->unknown_ptr_array_3700[3];
    unsigned char* marker = (unsigned char*)res->unknown_ptr_array_371c[4];
    BackgroundLoader::GetInstance()->FreeAllocations();

    unsigned short var11 = id;
    if (id == 0) {
        var11 = *(int*)(party + 0x2c94);
    }

    if (LinkSession_IsGuest(search)) {
        func_0206e558(flags);
    }
    if (mode == 2) {
        status[Enum_ov017_0219bfb4_610] = 0;
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
            func_020a8170((Struct020a8170*)cont);
            func_020a818c(cont, &alloc);
            func_020a8304(cont);
            Struct_020a83fc_2* entry = func_020a83fc((Struct_020a83fc*)cont, var11);
            if (entry) {
                *(unsigned short*)(field + Enum_ov017_0219bfb4_10118) = entry->x;
                *(unsigned short*)(field + Enum_ov017_0219bfb4_10116) = entry->y;
                field[Enum_ov017_0219bfb4_10120] = 0;
                Vector3i pos = *(Vector3i*)(field + Enum_ov017_0219bfb4_10100);
                pos.x = entry->posX;
                pos.z = entry->unknown_24_;
                *(Vector3i*)((int*)(field + Enum_ov017_0219bfb4_10100)) = *(Vector3i const*)((int*)&pos);
                func_ov017_021d1a18(entry->x, entry->y, 0, 1);
            }
            alloc.Destroy();
        }
        if (var11 == 0x119a) {
            *(unsigned short*)(field + Enum_ov017_0219bfb4_10164) = 1;
            *(unsigned short*)(field + Enum_ov017_0219bfb4_10166) = 0;
            func_ov017_021d1c2c(1, 0);
        }
    }

    if (node[2] == 0) {
        func_02070378(record);
        *(unsigned short*)record = var11;
        record[0xc] = 0;
        FieldTask_InitEnterZone(node, 0);
        func_020469b4(list, (TailNode020469b4*)node);
    } else if (node[3] == 0) {
        func_02070378(record);
        *(unsigned short*)record = var11;
        record[0xc] = 0;
    }

    func_02017d7c(field);
    ((unsigned char*)record)[0x6e] |= 0x20;
    for (int i = 0; i < *(unsigned char*)(party + 0xf7c); i++) {
        GameObject* member = gs->GetPartyMemberByIndex(*(unsigned char*)(party + i + 0xf78));
        if (member) {
            if (i == 0) {
                GameObject_ClearHidden((unsigned char*)member);
                member->obj3D_.SetInheritedAlpha(0x1f);
            } else {
                func_02039d48((unsigned char*)member);
                member->obj3D_.SetInheritedAlpha(0);
            }
        }
    }

    if (marker[2] != 0) {
        return;
    }

    char* controller = (char*)MessageSystem_GetInstance();
    memset(*(void**)(controller + Enum_ov017_0219bfb4_92), 0, Enum_ov017_0219bfb4_2400);
    MessageSystem_Reset(controller);
    if (func_ov017_0219ff58(res, 0, 0, 1)) {
        unsigned char* obj = (unsigned char*)res->fieldTasks_[0x14];
        func_ov017_021b2174(obj);
        func_ov017_021b2ba0((Struct_0206f81c_2*)obj, &data_ov017_021d75d0);
        func_ov017_021b2bd0(obj, (int)func_ov004_021689d8, OVERLAY_ID(4));
        func_ov017_021b2bf4((Struct_0206f81c_3*)obj, 1);
        func_ov017_021b2c0c((Struct_0206f81c_4*)obj, 1);
        func_ov017_021b2bdc((Struct_0206f81c_5*)obj, 0);
        func_020469b4(list, (TailNode020469b4*)obj);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    LoadFileIntoMemory(&data_ov017_021d75dc, &g_fileLoadBuffer, &length);
    if (length == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    char scripts[8];
    func_020727d8((Struct_020727d8*)scripts);
    char result[8];
    __clear(result, 8);
    short scriptId = *(int*)(party + 0x2c94);
    if (id != 0) {
        scriptId = id;
    }
    int now = GameState_GetStoryChapter((char*)gs);
    for (int j = 0; j < 3; j++) {
        unsigned char fromIndex = inline_ov017_0219bfb4(j, 0);
        unsigned char toIndex = inline_ov017_0219bfb4(j, 1);
        char from[8];
        __clear(from, 8);
        char to[8];
        __clear(to, 8);
        func_02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, from, fromIndex);
        func_02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, to, toIndex);
        int start = 0;
        int end = 0;
        if (STD_CompareString(from, &data_ov017_021d75fa)) {
            start = func_02005a94((signed char*)from);
        }
        if (STD_CompareString(to, &data_ov017_021d75fa)) {
            end = func_02005a94((signed char*)to);
        }
        int inRange = 0;
        if (start == 0 && end == 0) {
            inRange = 1;
        } else if (now >= start && now <= end) {
            inRange = 1;
        }
        if (inRange) {
            unsigned char index;
            if (gs->IsMorningDayOrEvening()) {
                index = (unsigned int)j * 4 + 2;
            } else {
                index = (unsigned int)j * 4 + 3;
            }
            func_02072928(scripts, (StreamHeader*)&g_fileLoadBuffer, length, scriptId, result, index);
            break;
        }
    }
    BackgroundLoader::RemoveLockGlobal();

    signed char state = 1;
    if (STD_CompareString(result, &data_ov017_021d75fa)) {
        state = func_02005a94((signed char*)result);
    }
    if (state != 3) {
        func_ov017_021ba90c((Struct_ov017_0219bfb4*)marker);
        marker[0x20] = mode;
        marker[0x21] = state;
        func_020469b4(list, (TailNode020469b4*)marker);
    }
}
