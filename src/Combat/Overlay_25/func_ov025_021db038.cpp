#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
#include "Resource/Brightness.h"

struct Struct_ov000_02161e30 { char pad0[0x8e14]; signed char outcome; char unknown_8e15_[0xb]; int mode; int count; };
struct Struct_ov025_021db038 {
    int taskId;
    char unknown_4_[0x80];
    int unknown_84_;
    char unknown_88_[0x18];
    unsigned char unknown_a0_;
    unsigned char started;
};
struct Struct_ov000_021537b8 {
    char pad0[0x30]; SafeAllocator allocator;
#if defined(jpn)
    char unknown_44_[0x138-0x30-sizeof(SafeAllocator)]; char unknown_14c_[0x218-0x138];
#else
    char unknown1_44_[0x14c-0x30-sizeof(SafeAllocator)]; char unknown_14c_[0x29c-0x14c];
#endif

#if defined(jpn)
    Struct_ov000_02161e30* battle; char unknown_21c_[8]; char display[0x9bc-0x224];
#else
    Struct_ov000_02161e30* battle; char unknown_2a0_[8]; char display[0xa40-0x2a8];
#endif

#if defined(jpn)
    Struct_ov025_021db038 task; char unknown_a60_[0xaac-0xa60];
#else
    Struct_ov025_021db038 task; char unknown_ae4_[0xb30-0xae4];
#endif

#if defined(jpn)
    char events[0xb94-0xaac]; char unknown_c18_[0xdf4-0xb94];
#else
    char events[0xc18-0xb30]; char unknown_c18_[0xe78-0xc18];
#endif

#if defined(jpn)
    unsigned char active; char unknown_df5_[0xe28-0xdf5]; int state;
#else
    unsigned char active; char unknown_e79_[0xeac-0xe79]; int state;
#endif

#if defined(jpn)
    char unknown_e2c_[0x57c8-0xe2c]; int slot;
#else
    char unknown_eb0_[0x55d8-0xeb0]; int slot;
#endif

#if defined(jpn)
    char unknown_57cc_[0x5b41-0x57cc]; unsigned char mode : 2; unsigned char flags : 6;
#else
    char unknown_55dc_[0x5951-0x55dc]; unsigned char mode : 2; unsigned char flags : 6;
#endif

};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_ov000_02160094 { char pad0[0x20]; unsigned short id; };
struct Struct_ov000_021600f8 { int flags; char pad4[8]; int value; char pad10[8]; unsigned char unknown_18_; char unknown_19_[2]; unsigned char unknown_1b_; };
#if defined(jpn)
struct MessageSystem { char pad0[0x868]; int active; };
#else
struct MessageSystem { char pad0[0x998]; int active; };
#endif

struct SePlayer;
struct Struct_ov000_0216fe48;
struct Struct_ov000_0216fdf8;
struct Struct_ov000_0216fd0c;
struct Struct_ov000_0216fd38;
struct Struct_ov000_0216fd80;
extern "C" void* func_ov000_02160f20(void*);
extern "C" void* func_02057924();
extern "C" unsigned char* func_ov000_02163524(void*);
extern "C" unsigned char _ZZ21inline_ov025_021dcf14vE1s __attribute__((aligned(4)));
extern SePlayer g_sePlayer;
extern "C" void func_ov025_021db6dc(Struct_ov000_021537b8*);
extern "C" int func_ov000_0215fc60(char*);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" void func_ov025_021e88d8(char*);
extern "C" void func_ov025_021e8a40(char*, int, int);
extern "C" void func_ov025_021e8a4c(char*, int);
extern "C" void func_ov000_0216df00(void*, int, int, int, float);
extern "C" void func_ov000_021626a0(void*, int, int);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" void func_ov000_02160fbc(void*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov025_021dbe10(Struct_ov000_021537b8*);
extern "C" void func_ov000_0216fe48(Struct_ov000_0216fe48*);
extern "C" void func_ov000_0216fdf8(Struct_ov000_0216fdf8*, int);
extern "C" void func_ov000_0216fd0c(Struct_ov000_0216fd0c*);
extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void func_ov000_0216fd38(Struct_ov000_0216fd38*);
extern "C" int func_ov025_021e8a54(char*);
extern "C" void func_ov000_0216fd80(Struct_ov000_0216fd80*, int);
extern "C" char* func_ov000_0216fcfc(void*, int);
#if !defined(jpn)
extern "C" void func_0204500c(MessageSystem*, char*, int, int);
#endif
extern "C" void func_ov025_021eedb0(char*);
extern "C" void func_ov025_021dcf14(Struct_ov000_021537b8*);
extern "C" void func_ov025_021de124(Struct_ov000_021537b8*);
extern "C" void func_ov025_021e9fc4(char*);
extern "C" void func_ov025_021dc168(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc324(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc590(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc694(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc880(Struct_ov000_021537b8*);
extern "C" void func_ov025_021db458(Struct_ov000_021537b8*);
extern "C" void func_ov025_021db7f8(Struct_ov000_021537b8*);
extern "C" void func_ov000_02160d80(void*, int);
inline unsigned int inline_ov025_021db038(unsigned int length) { return (length + 3) & ~3; }

#if defined(jpn)
extern "C" void func_0204500c(MessageSystem*,char*,int);
#endif
// USA: func_ov025_021db038
extern "C" ARM void func_ov025_021db038(Struct_ov000_021537b8* work) {
    Struct_ov025_021db038* task;
    Struct_ov000_02161e30* battle = work->battle;
    void* list = func_ov000_02160f20(work);
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    func_02057924();
    func_ov000_02163524(work);
    _ZZ21inline_ov025_021dcf14vE1s = 0;
    task = &work->task;
    if (!work->active) _ZZ21inline_ov025_021dcf14vE1s = 1;
    if (!work->state) func_ov025_021db6dc(work);
    if (work->state == 1) {
        int id;
        Struct_ov000_021600f8* target;
        Struct_ov000_02160094* actor;
        int messageId;
        messageId = -1;
        if (func_ov000_0215fc60((char*)battle)) {
            actor = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
            target = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
            if (actor) {
                id = actor->id;
                if (battle->mode == 1 && id == 0xc0) {
                    func_ov025_021e88d8(work->display);
                    func_ov025_021e8a40(work->display, (int)&work->allocator, (int)work->unknown_14c_);
                    func_ov025_021e8a4c(work->display, (int)battle);
                    func_ov000_0216df00(work->unknown_c18_, id, 0, 0, 1.8f);
                    func_ov000_021626a0(work, 4, 0);
                    func_ov000_021626a0(work, 0, 1);
                    func_ov000_02160fa8(work, 0x1000000);
                    if (func_ov000_0215fc60((char*)battle) == 1) messageId = 0x1ee;
                    else if (func_ov000_0215fc60((char*)battle) == 2) messageId = 0x211;
                }
                if (actor->id == 0) {
                    SePlayer_Play(&g_sePlayer, 7, 0);
                    if (target) { target->flags = 0; target->unknown_18_ = 0; target->value = 0; target->unknown_1b_ = 0; }
                }
            }
        }
        func_ov025_021dbe10(work);
        if (messageId > 0) {
            func_ov000_0216fe48((Struct_ov000_0216fe48*)task);
            func_ov000_0216fdf8((Struct_ov000_0216fdf8*)task, (short)messageId);
            func_ov000_0216fd0c((Struct_ov000_0216fd0c*)task);
        }
    }
    if (func_ov000_02160fd4(work, 0x1000000)) {
        GameState* game;
        char* format;
        GameObject* actor;
        MessageSystem* messages;
        game = GameState::GetInstance();
        messages = MessageSystem_GetInstance();
        Struct_ov025_021db038* task = &work->task;
        if (!task->unknown_a0_) {
            func_ov000_0216fd38((Struct_ov000_0216fd38*)task);
            if (!task->unknown_a0_) return;
            func_ov000_0216fd80((Struct_ov000_0216fd80*)task, func_ov025_021e8a54(work->display));
            actor = func_0200ff1c(game, 0);
            format = 0;
            if (func_ov000_0215fc60((char*)battle) == 1) format = func_ov000_0216fcfc(task, 0x1ee);
            else if (func_ov000_0215fc60((char*)battle) == 2) format = func_ov000_0216fcfc(task, 0x211);
            if (!actor || !format) return;
            char* name = (char*)actor->baseStats_;
            int length = strlen(format);
            length += strlen(name);
            char* text = (char*)work->allocator.Allocate(inline_ov025_021db038(length - 1));
            if (!text) return;
            sprintf(text, format, actor->baseStats_);
#if defined(jpn)
            func_0204500c(messages, text, 0);
#else
            func_0204500c(messages, text, 0, 0xe3);
#endif

            messages->active = 1;
            return;
        }
        if (messages->active) return;
        func_ov000_02160fbc(work, 0x1000000);
        return;
    }
    func_ov025_021eedb0(work->events);
    func_ov025_021dcf14(work);
    func_ov025_021de124(work);
    func_ov025_021e9fc4(work->display);
    if (work->mode != 1) func_ov025_021dc168(work);
    if (work->state == 6) func_ov025_021dc324(work);
    if (work->state == 3) func_ov025_021dc590(work);
    if (work->state == 4) func_ov025_021dc694(work);
    if (work->state == 5) func_ov025_021dc880(work);
    func_ov025_021db458(work);
    if (work->slot != battle->count) return;
    func_ov025_021db7f8(work);
    if (work->battle->outcome == 2) func_ov000_02160d80(work, 10);
    else if (work->battle->outcome == 1) func_ov000_02160d80(work, 9);
    else {
        func_ov000_02160d80(work, 7);
        SetFlags00(resources, 0x800);
    }
    game->SetGameSpeed(0x1000);
}
