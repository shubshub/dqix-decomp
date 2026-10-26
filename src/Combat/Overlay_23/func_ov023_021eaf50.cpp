#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* table);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void* obj, int flag);

struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(struct ListHead02046b38* list, struct ListNode02046b38* target);
bool ZoneId_IsGrotto(int id);
int LoadBattleBlock020ac4c0(void* dst);

struct Struct_ov023_021eaf50 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 7;
};

// USA: func_ov023_021eaf50
extern "C" ARM int func_ov023_021eaf50(void* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021eaf50_1788=0x4ec, Enum_ov023_021eaf50_1816=0x508, Enum_ov023_021eaf50_9196=0x240c};
#else
 enum {Enum_ov023_021eaf50_1788=0x6fc, Enum_ov023_021eaf50_1816=0x718, Enum_ov023_021eaf50_9196=0x23ec};
#endif
    int var0 = 0;

    char* var1 = (char*)GetGameResources() + 0x3000;
    struct Struct_02046b38* var2 = *(struct Struct_02046b38**)(var1 + Enum_ov023_021eaf50_1788);
    struct Struct_02046b38_2* var3 = *(struct Struct_02046b38_2**)(var1 + Enum_ov023_021eaf50_1816);
    void* var4 = func_ov017_021b8478(var3);

    if (ListContainsNode(list, node) != 0) {
        void* zone = Zone3D_GetInstance();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)zone + regionalOffset2);
        DetailedTreasureMapData* detail = grotto->GetDetailedData();

        if (*((unsigned char*)headerObj + 0x25) != 0) {
            if (ZoneId_IsGrotto(*(unsigned short*)zone) != 0 && detail != NULL) {
                if (detail->mapType_ == 2) {
                    char buf[0xb0];
                    LoadBattleBlock020ac4c0(buf);
                    result = ((struct BlockWord021eaf50*)(buf + 0xc))->fieldB;
                }
            }
        }
    }

    func_ov017_021d6134(arg0, var0);
    return 1;
}
