#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_ov017_021a7c28 func_ov017_021a85b8
#endif

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** unused0);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4* unused0, TailNode020469b4* src);
extern "C" void func_ov017_021a7adc(char* unused0);
extern "C" void func_ov017_021a7c28(unsigned char* unused0, unsigned char* src);

// USA: func_ov017_021a7a74
extern "C" ARM void func_ov017_021a7a74(void* unused0, unsigned char* src) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x8ec, regionalOffset2=0x978};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0xb0c, regionalOffset2=0xb98};
#endif
    int var0 = (int)GetGameResources();
    HeadNode02046b24** list = *(HeadNode02046b24***)(var0 + 0x3000 + regionalOffset0);
    int id = FieldTaskQueue_GetCurrentKind(list);
    if (id == 0x1a) {
        int* p = *(int**)(var0 + 0x3000 + regionalOffset1);
        if (*(int*)((char*)p + 0x64) != 0) {
            return;
        }
    }
    unsigned char* node = *(unsigned char**)(var0 + 0x3000 + regionalOffset2);
    func_ov017_021a7adc((char*)node);
    func_ov017_021a7c28(node, src);
    func_020469b4((TailList020469b4*)list, (TailNode020469b4*)node);
}
