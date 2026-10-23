#if defined(jpn)
enum { Enum_ov017_021b5dc4_1536 = 0x620, Enum_ov017_021b5dc4_716 = 0x27c };
#else
enum { Enum_ov017_021b5dc4_1536 = 0x600, Enum_ov017_021b5dc4_716 = 0x2cc };
#endif

#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

struct Struct_ov017_0218d618_2;
extern "C" int func_ov017_0218d618(struct Struct_ov017_0218d618_2* arg0);

extern "C" void* func_02012fe4(void);
extern "C" int func_020100a8(GameState* arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern AllocatorUnion data_02114e20;

struct Struct_02012fa4;
extern "C" void func_02047230(struct Struct_02012fa4* arg0);

struct State0207dfc8;
void CopyState0207dfc8(struct State0207dfc8* src, struct State0207dfc8* dst);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
void Forward02047b30(void* a, int b, int c, int d);

// USA: func_ov017_021b5dc4
extern "C" ARM int func_ov017_021b5dc4(char* arg0) {
    if (*(unsigned char*)(arg0 + 0x54) != 0) {
        if (!func_ov017_0218d618((struct Struct_ov017_0218d618_2*)((char*)GetGameResources())))
            return 3;
    } else {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(self + 0x28)) != 0) {
            if (loader->GetDetailedTaskStatus(*(int*)(self + 0x28)) == BackgroundLoader::TaskStatus_Complete) {
                void* outPtr;
                unsigned int outSize;
                loader->GetLoadedFileByID(*(int*)(self + 0x28), &outPtr, &outSize);
                void* allocated = AllocateAligned4_02012d88(&data_02114e20, 0x100);
                if (outSize != 0 && allocated != 0) {
                    ((SafeAllocator*)(self + 0x40))->CreateTypeA(allocated, 0x100);
                    GameState* battle = GameState::GetInstance();
                    char* base = (char*)func_02012fe4();
                    int idx = GetField0x3acValue_020100a8(battle);
                    char* p = base + RegionOffset600 + idx * 0x88;
                    *(int*)(self + 0x20) = (int)p;
                    MaybeInvoke0204719c_02047230((struct Foo02048004*)*(int*)(self + 0x20));
                    func_0204719c((struct Foo02048004*)*(int*)(self + 0x20));
                    unsigned char local[0x70];
                    short* mid = (short*)(((char*)GetGameResources()) + RegionOffset2cc);
                    CopyState0207dfc8((struct State0207dfc8*)((char*)mid + 0x230), (struct State0207dfc8*)local);
                    VramState_Restore((char*)local);
                    Forward02047b30((void*)*(int*)(self + 0x20), (int)outPtr, (int)outSize, (int)(self + 0x40));
                    VramState_Save((char*)local);
                }
            }
            var0->RemoveTask(*(int*)(arg0 + 0x28));
            *(int*)(arg0 + 0x28) = -1;
        }
    }
    return (*(int*)(arg0 + 0x28) < 0) ? 4 : 3;
}
