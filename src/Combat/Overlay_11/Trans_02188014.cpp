#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z19CharacterModel_InitPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

void* MessageSystem_GetInstance();
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

// USA: func_ov011_02188014  (semantic: Trans_02188014)
extern "C" ARM int func_ov011_02188014(struct TaggedNumber02184c30* params, int count) {
    int value = GetTaggedValueAsInt_02184c30(&params[0]);
    *(int*)((char*)MessageSystem_GetInstance() + R(0x86c, 0x99c)) = value;
    return 1;
}
