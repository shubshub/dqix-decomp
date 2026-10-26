#include <globaldefs.h>
#include "Resource/Brightness.h"

struct AxisFloats0203b5a0;
extern char g_sePlayer;
void SePlayer_UnloadExtraArchiveA(void* obj);
void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

struct Obj020a87d0 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3_pad;
    unsigned char field4;
    unsigned char field5;
};

// USA: func_020a87d0  (semantic: NotifyOv017AndSetFlagBit020a87d0)
extern "C" ARM void func_020a87d0(struct Obj020a87d0* obj) {
    if (obj->field4 == 1) return;
    obj->field4 = 1;

    struct AxisFloats0203b5a0* s = (struct AxisFloats0203b5a0*)GetGameResources();
    if (IsScreenNotFullyFaded((GameResources*)s, false) != 0) {
        SePlayer_UnloadExtraArchiveA(&g_sePlayer);
        SePlayer_LoadExtraArchiveA(&g_sePlayer, 0x72, 0x72);
        DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 0, 0);
    }

    signed char idx = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance());
    obj->field5 |= (1 << idx);
    func_ov017_021d1874(obj->byte0, obj->byte1, obj->byte2, 1, idx & 0xff, 0, 0);
}
