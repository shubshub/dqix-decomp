#include <globaldefs.h>
#include "Resource/Brightness.h"

struct AxisFloats0203b5f8;
int MessageSystem_GetInstance(void);
extern char* data_ov004_02171010;
struct SelectionState {
#if defined(jpn)
    unsigned char unknown[0x19f4];
#else
    unsigned char unknown[0x18f4];
#endif
    unsigned char entryCount;
    unsigned char unknownF5;
    short page;
    short pageCount;
    unsigned char unknownFA[2];
    unsigned char mode;
};
void SetByteFieldAt0x765_02026420(unsigned char* obj, unsigned char value);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
int ToggleFlag8OnTwoObjs_021651c8(void* a1);

#if defined(jpn)
enum { StatusOffset021652e8 = 0x868, ObjectOffset021652e8 = 0x4c0 };
// USA: func_ov004_021652e8
extern "C" ARM int func_ov004_02165b78(void* a1) {
#else
enum { StatusOffset021652e8 = 0x998, ObjectOffset021652e8 = 0x6d0 };
// USA: func_ov004_021652e8
ARM int UpdateAxisFlagAndDispatch_021652e8(void* a1) {
#endif
    struct AxisFloats0203b5f8* axis = (struct AxisFloats0203b5f8*)GetGameResources();
    if (!IsBrightnessZero((GameResources*)axis, false) || !IsBrightnessZero((GameResources*)axis, true)) return 0;
    if (*(void**)((char*)MessageSystem_GetInstance() + StatusOffset021652e8) != NULL) return 0;

    {
        SelectionState* selection = (SelectionState*)data_ov004_02171010;
        unsigned char v = selection->entryCount;
        if (v == 0) return 0;

        unsigned char* mode = &selection->mode;
        v = selection->mode;
        if (v == 0) {
            *mode = 1;
        } else if (v == 1) {
            *mode = 0;
        }

        unsigned char* fieldObj = *(unsigned char**)((char*)GetGameResources() + 0x3000 + ObjectOffset021652e8);
        unsigned char v2 = ((SelectionState*)data_ov004_02171010)->mode;
        if (v2 == 1) {
            SetByteFieldAt0x765_02026420(fieldObj, 0);
        } else if (v2 == 0) {
            SetByteFieldAt0x765_02026420(fieldObj, 1);
        }

        ToggleFlag8OnTwoObjs_021651c8(a1);
        SePlayer_Play(&g_sePlayer, 1, 0);
        return 0;
    }
}
