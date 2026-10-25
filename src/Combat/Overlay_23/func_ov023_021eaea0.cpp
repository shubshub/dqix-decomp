#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* table);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void* obj, int flag);

struct Struct_02046b38;
struct Struct_02046b38_2;
extern "C" int func_02046b38(struct Struct_02046b38* arg0, struct Struct_02046b38_2* arg1);
extern "C" bool func_0201b588(int arg0);
extern "C" int func_020ac4c0(void* arg0);

struct Struct_ov023_021eaea0 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 7;
};

// USA: func_ov023_021eaea0
extern "C" ARM int func_ov023_021eaea0(void* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021eaea0_1788=0x4ec, Enum_ov023_021eaea0_1816=0x508, Enum_ov023_021eaea0_9196=0x240c};
#else
 enum {Enum_ov023_021eaea0_1788=0x6fc, Enum_ov023_021eaea0_1816=0x718, Enum_ov023_021eaea0_9196=0x23ec};
#endif
    int var0 = 0;

    char* var1 = (char*)GetGameResources() + 0x3000;
    struct Struct_02046b38* var2 = *(struct Struct_02046b38**)(var1 + Enum_ov023_021eaea0_1788);
    struct Struct_02046b38_2* var3 = *(struct Struct_02046b38_2**)(var1 + Enum_ov023_021eaea0_1816);
    void* var4 = func_ov017_021b8478(var3);

    if (ListContainsNode(list, node) != 0) {
        void* zone = Zone3D_GetInstance();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)zone + regionalOffset2);
        DetailedTreasureMapData* detail = grotto->GetDetailedData();

        if (*((unsigned char*)var4 + 0x24) != 0) {
            if (func_0201b588(*(unsigned short*)var5) != 0 && var7 != NULL) {
                if (var7->mapType_ == 1) {
                    char var8[0xb0];
                    func_020ac4c0(var8);
                    var0 = ((struct Struct_ov023_021eaea0*)(var8 + 0xc))->unknown_0_0_;
                }
            }
        }
    }

    func_ov017_021d6134(arg0, var0);
    return 1;
}
