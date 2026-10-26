#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_02012de8;
struct Struct_02015438;

unsigned long long GetCurrentTimestamp(void);
FlagWord02046708* GlobalFlags_GetInstance();
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
extern "C" void* LinkSession_GetInstance(void);
void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" void func_ov017_02195ecc(unsigned char* obj, int mode);
void MaybeUpdateOrDispatchEntry_021959ec(void* obj);
void SetActiveDmaChannel020c3a0c(int ch);
extern "C" void func_ov017_02195bbc(unsigned char* obj);
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
void DispatchByFlag020d9834(int flag);
extern "C" void func_ov017_021960b8(unsigned char* obj);

// USA: func_ov017_02195a20
extern "C" ARM void func_ov017_02195a20(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_02195a20_17546=0x41da,Enum_ov017_02195a20_14076=0x34ec};
#else
 enum {Enum_ov017_02195a20_17546=0x448a,Enum_ov017_02195a20_14076=0x36fc};
#endif
    GetCurrentTimestamp();
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    void* search = LinkSession_GetInstance();
    G3X_Reset();
    G3X_ResetMtxStack();
    RenderConfig::Reset();
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
    DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
    if (TestFlags04((GameResources*)arg0, 0x2000)) {
        DISP3DCNT &= 0xcfdf;
    } else {
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x20;
    }
    if (arg0[Enum_ov017_02195a20_17546] == 0) {
        func_ov017_02195ecc(arg0, 1);
    }
    func_ov017_021959ec(arg0);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    LightingManager::GetInstance()->SubmitToRenderConfig();

    int useDma = FlagWord_TestBits(flags, 0x800000);
    if (useDma) {
        SetActiveDmaChannel020c3a0c(-1);
    }
    func_ov017_02195bbc(arg0);
    if (var2) {
        func_020c3a0c(0);
    }
    if (FieldTaskQueue_GetCurrentKind(*(HeadNode02046b24***)(obj + regionalList)) == 0x16) {
        func_ov017_02195ecc(obj, 2);
    }
    if (var2) {
        while (1) {
            int line = VCOUNT;
            if (LinkSession_IsHostOrSolo(search) && line < 0xd2) break;
            if (LinkSession_IsGuest(search) && (line < 0xbe || line > 0xf0)) break;
            DispatchByFlag020d9834(0);
        }
    }
    func_ov017_021960b8(arg0);
    if (arg0[Enum_ov017_02195a20_17546] != 0) {
        func_ov017_02195ecc(arg0, 1);
    }
}
