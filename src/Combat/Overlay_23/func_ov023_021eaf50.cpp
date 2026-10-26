#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* table);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void* obj, int flag);

struct ListHead02046b38;
struct ListNode02046b38;
extern "C" int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" bool ZoneId_IsGrotto(int id);
extern "C" int func_020ac4c0(void* dst);

struct Struct_ov023_021eaf50 {
    unsigned int fieldA : 7;
    unsigned int fieldB : 7;
};

// USA: func_ov023_021eaf50
extern "C" ARM int func_ov023_021eaf50(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x508, regionalOffset2=0x240c};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0x718, regionalOffset2=0x23ec};
#endif
    int result = 0;

    char* base = (char*)GetGameResources() + 0x3000;
    struct ListHead02046b38* list = *(struct ListHead02046b38**)(base + regionalOffset0);
    struct ListNode02046b38* node = *(struct ListNode02046b38**)(base + regionalOffset1);
    void* var4 = func_ov017_021b8478(node);

    if (func_02046b38(list, node) != 0) {
        void* zone = Zone3D_GetInstance();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)zone + regionalOffset2);
        DetailedTreasureMapData* detail = grotto->GetDetailedData();

        if (*((unsigned char*)var4 + 0x25) != 0) {
            if (ZoneId_IsGrotto(*(unsigned short*)zone) != 0 && detail != NULL) {
                if (detail->mapType_ == 2) {
                    char buf[0xb0];
                    func_020ac4c0(buf);
                    result = ((struct Struct_ov023_021eaf50*)(buf + 0xc))->fieldB;
                }
            }
        }
    }

    func_ov017_021d6134(obj, result);
    return 1;
}
