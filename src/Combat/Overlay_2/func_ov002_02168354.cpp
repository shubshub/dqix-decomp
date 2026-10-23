#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct_0201099c_3;
struct Struct_020727d8;

extern "C" unsigned char func_ov013_021847c4(void *arg0, int arg1);
extern "C" char *func_020421a0();
extern "C" int func_ov002_021574d4(void *arg0, int arg1);
extern "C" void func_ov013_02184c8c(void *arg0, void *arg1);
extern "C" void *memset(void *arg0, int arg1, unsigned int arg2);
extern "C" unsigned char func_0209a678(char *arg0, void *arg1, unsigned short *arg2);
extern "C" void *func_0202ae18();
int CheckField0NonZero_0202b7d8(int *p);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021ccc34(int id);
extern "C" void func_ov017_021cd0d8(int id, unsigned short *skills, int count);
const char *KeyTable_Get(Container020e0310 *texts, int id);
void ResetListHeader020727d8(List020727d8 *list);
extern "C" void func_020728ac(void *list, void *alloc, void *buffer, unsigned int length, int a4, int a5, int a6);
void Zero4Bytes_020e526c(void *reader);
extern "C" void func_020e5604(void *reader, void *alloc, void *buffer, unsigned int length);
void *GetFieldAt0x150_02053c6c(unsigned char *member);
extern "C" void func_02083e28(void *model, int arg);

extern "C" const char data_ov002_0216d300[];
extern "C" const char data_ov002_0216d315[];

// USA: func_ov002_02168354
extern "C" ARM void func_ov002_02168354(char *arg0) {
    unsigned int var0;
    *(unsigned int *) (arg0 + 0x247c) |= 4;
    if (func_ov013_021847c4(arg0 + 0xd70 + 0x1000, *(int *) (arg0 + 0x1ba0)) != 6) {
        return;
    }
    GameState *var1 = GameState::GetInstance();
    func_020421a0();
    *(unsigned int *) (arg0 + 0x247c) &= ~4;
    if (*(unsigned char *) (arg0 + 0x2455) == 0) {
        char *var2 =
            (char *) func_0200ff1c(var1, func_ov002_021574d4(arg0, *(short *) (arg0 + 0x1c08)));
        if (var2 != 0) {
            func_ov013_02184c8c(arg0 + 0xd70 + 0x1000, var2);
        }
        if (var2 != 0) {
            ((SafeAllocator *) (arg0 + 0x64 + 0x800))->Reset();
            *(void **) (arg0 + 0x2450) = ((SafeAllocator *) (arg0 + 0x64 + 0x800))->Allocate(0x6e);
            memset(*(void **) (arg0 + 0x2450), 0, 0x6e);
            *(unsigned char *) (arg0 + 0x2455) =
                func_0209a678(arg0 + 0x3c + 0x2400, var2, *(unsigned short **) (arg0 + 0x2450));
            if (func_0202b7d8((int *) func_0202ae18())) {
                int var3 = func_ov002_021574d4(arg0, *(short *) (arg0 + 0x1c08));
                func_ov017_021c9e00(var3, 0, 0, 0);
                func_ov017_021ccc34(var3);
                func_ov017_021cd0d8(var3, *(unsigned short **) (arg0 + 0x2450), *(unsigned char *) (arg0 + 0x2455));
            }
            if (*(unsigned char *) (arg0 + 0x2455) == 0) {
                *(int *) (arg0 + 0x1bc0) += 1;
                return;
            }
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            const char *inner = KeyTable_Get((Container020e0310 *) (self + 0x20), 0x65);
            void *file        = ExtractFileFromGP2(
                KeyTable_Get((Container020e0310 *) (self + 0x20), 0x64), inner, &size);
            *(void **) (self + 0x2448) = ((SafeAllocator *) (self + 0x64 + 0x800))->Allocate(8);
            ResetListHeader020727d8(*(List020727d8 **) (self + 0x2448));
            if (file != 0) {
                func_020728ac(*(void **) (self + 0x2448), self + 0x64 + 0x800, file, size, 0, 0, 0);
            }
            var5                       = ExtractFileFromGP2(data_ov002_0216d300, data_ov002_0216d315, &var0);
            *(void **) (arg0 + 0x244c) = ((SafeAllocator *) (arg0 + 0x64 + 0x800))->Allocate(0xc);
            func_020e526c(*(void **) (arg0 + 0x244c));
            if (var5 != 0) {
                func_020e5604(*(void **) (arg0 + 0x244c), arg0 + 0x64 + 0x800, var5, var0);
            }
            BackgroundLoader::RemoveLockGlobal();
            func_02083e28(func_02053c6c((unsigned char *) var2), 0);
        }
    }
    *(int *) (arg0 + 0x1bc0) += 1;
}
