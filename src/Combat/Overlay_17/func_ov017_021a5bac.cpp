#if defined(jpn)
enum { Enum_ov017_021a5bac_16832 = 0x3fa0, Enum_ov017_021a5bac_16824 = 0x3f98, Enum_ov017_021a5bac_16828 = 0x3f9c, Enum_ov017_021a5bac_16820 = 0x3f94, Enum_ov017_021a5bac_16532 = 0x3e74, Enum_ov017_021a5bac_16528 = 0x3e70 };
#else
enum { Enum_ov017_021a5bac_16832 = 0x41c0, Enum_ov017_021a5bac_16824 = 0x41b8, Enum_ov017_021a5bac_16828 = 0x41bc, Enum_ov017_021a5bac_16820 = 0x41b4, Enum_ov017_021a5bac_16532 = 0x4094, Enum_ov017_021a5bac_16528 = 0x4090 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" unsigned int GetMainBG1CharacterBase(void);

struct Node0x20_021a5ad0;
extern "C" void func_ov017_021a5ad0(struct Node0x20_021a5ad0* arr, int count, int val);
extern "C" void func_ov017_021a5b08(struct Node0x20_021a5ad0* arr, int count);

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0* obj);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274* obj);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc* obj);
struct Obj0205d048;
extern "C" void Window_Destroy(struct Obj0205d048* obj);

extern "C" void func_ov017_021a5b48(unsigned char* base);

// USA: func_ov017_021a5bac
#pragma opt_common_subs off
extern "C" ARM void func_ov017_021a5bac(unsigned char* base) {
    if (*(int*)(base + Enum_ov017_021a5bac_16832) == 0) {
        return;
    }

    if (*(int*)(base + Enum_ov017_021a5bac_16824) != 0) {
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x100;

        if (*(int*)(base + Enum_ov017_021a5bac_16828) >= 0) {
            ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(*(int*)(base + Enum_ov017_021a5bac_16828)));
            *(int*)(base + Enum_ov017_021a5bac_16828) = -1;
        }

        volatile unsigned short* var1 = (volatile unsigned short*)0x4000050;
        *var1 = 0;
        volatile unsigned short* var2 = (volatile unsigned short*)0x4000008;
        *var2 = (*var2 & ~3) | 1;

        if (*(int*)(base + Enum_ov017_021a5bac_16820) != 0) {
            memset((void*)GetMainBG1CharacterBase(), 0, 0x20);
            func_ov017_021a5ad0((struct Node0x20_021a5ad0*)(base + Enum_ov017_021a5bac_16532), 2, 0x800);

            void* list = *(void**)(base + Enum_ov017_021a5bac_16528);
            Window_ClearLayers((struct Cont0205d1e0*)list);
            Window_FlushLayers((struct Cont0205d274*)list);
            Window_TransferLayers((struct Obj0205d2bc*)list);

            func_ov017_021a5b08((struct Node0x20_021a5ad0*)(base + Enum_ov017_021a5bac_16532), 2);

            Window_Destroy((struct Obj0205d048*)list);

            *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
        }
    }

    func_ov017_021a5b48(base);
}
