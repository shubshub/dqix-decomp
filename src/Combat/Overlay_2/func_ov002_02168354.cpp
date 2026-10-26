#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Container020e0310;
struct Struct_020727d8;

extern "C" unsigned char func_ov013_021847c4(void *obj, int a);
extern "C" char *MessageSystem_GetInstance();
extern "C" int func_ov002_021574d4(void *self, int index);
extern "C" void func_ov013_02184c8c(void *menu, void *member);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned char func_0209a678(char *table, void *member, unsigned short *arg2);
extern "C" void *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *p);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021ccc34(int id);
extern "C" void func_ov017_021cd0d8(int id, unsigned short *arg1, int count);
extern "C" const char *KeyTable_Get(Container020e0310 *texts, int id);
extern "C" void func_020727d8(Struct_020727d8 *list);
extern "C" void func_020728ac(void *list, void *alloc, void *buffer, unsigned int length, int a4, int a5, int a6);
extern "C" void func_020e526c(void *reader);
extern "C" void func_020e5604(void *reader, void *alloc, void *buffer, unsigned int length);
extern "C" void *func_02053c6c(unsigned char *member);
extern "C" void PartyMember_RecalculateStats(void *model, int arg);

extern "C" const char data_ov002_0216d300[];
extern "C" const char data_ov002_0216d315[];

// USA: func_ov002_02168354
extern "C" ARM void func_ov002_02168354(char *self) {
    unsigned int size;
    *(unsigned int *) (self + 0x247c) |= 4;
    if (func_ov013_021847c4(self + 0xd70 + 0x1000, *(int *) (self + 0x1ba0)) != 6) {
        return;
    }
    GameState *gs = GameState::GetInstance();
    MessageSystem_GetInstance();
    *(unsigned int *) (self + 0x247c) &= ~4;
    if (*(unsigned char *) (self + 0x2455) == 0) {
        char *member =
            (char *) func_0200ff1c(gs, func_ov002_021574d4(self, *(short *) (self + 0x1c08)));
        if (member != 0) {
            func_ov013_02184c8c(self + 0xd70 + 0x1000, member);
        }
        if (member != 0) {
            ((SafeAllocator *) (self + 0x64 + 0x800))->Reset();
            *(void **) (self + 0x2450) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(0x6e);
            memset(*(void **) (self + 0x2450), 0, 0x6e);
            *(unsigned char *) (self + 0x2455) =
                func_0209a678(self + 0x3c + 0x2400, member, *(unsigned short **) (self + 0x2450));
            if (LinkSession_IsActive((int *) LinkSession_GetInstance())) {
                int id = func_ov002_021574d4(self, *(short *) (self + 0x1c08));
                func_ov017_021c9e00(id, 0, 0, 0);
                func_ov017_021ccc34(id);
                func_ov017_021cd0d8(id, *(unsigned short **) (self + 0x2450), *(unsigned char *) (self + 0x2455));
            }
            if (*(unsigned char *) (self + 0x2455) == 0) {
                *(int *) (self + 0x1bc0) += 1;
                return;
            }
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            const char *inner = KeyTable_Get((Container020e0310 *) (self + 0x20), 0x65);
            void *file        = ExtractFileFromGP2(
                KeyTable_Get((Container020e0310 *) (self + 0x20), 0x64), inner, &size);
            *(void **) (self + 0x2448) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(8);
            func_020727d8(*(Struct_020727d8 **) (self + 0x2448));
            if (file != 0) {
                func_020728ac(*(void **) (self + 0x2448), self + 0x64 + 0x800, file, size, 0, 0, 0);
            }
            file                       = ExtractFileFromGP2(data_ov002_0216d300, data_ov002_0216d315, &size);
            *(void **) (self + 0x244c) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(0xc);
            func_020e526c(*(void **) (self + 0x244c));
            if (file != 0) {
                func_020e5604(*(void **) (self + 0x244c), self + 0x64 + 0x800, file, size);
            }
            BackgroundLoader::RemoveLockGlobal();
            PartyMember_RecalculateStats(func_02053c6c((unsigned char *) member), 0);
        }
    }
    *(int *) (self + 0x1bc0) += 1;
}
