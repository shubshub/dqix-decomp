#include <globaldefs.h>
struct Struct_021015a0_5 {
    char unknown_0_[0x10];
    int unknown_10_;
    char unknown_14_[0x18];
    int unknown_2c_, unknown_30_, unknown_34_, unknown_38_;
};
struct Struct_02101640_2 {
    char unknown_0_[0xc];
    unsigned short unknown_c_, unknown_e_, unknown_10_, unknown_12_;
    unsigned short unknown_14_, unknown_16_, unknown_18_;
    char unknown_1a_[0x18];
    unsigned short unknown_32_, unknown_34_, unknown_36_;
};
struct Ctx020d507c;
extern State0202db64 data_021015a0;
extern Command0202db64 data_02101640;
int GetOwnerDataFortuneValue_020d4b58();
int IssueBattleCommandSlot7(int, Ctx020d507c*);
void SetField0x48UnlessState9Or10_0202c848(int);
void CheckField2ThenSubmitOrError0202c864(unsigned short*);
// Main, originally func_0202db64 (USA 0x0202db64, EUR 0x0202db74, JPN 0x0202d6d4)
extern "C" ARM int WH_ParentConnect(int mode, int first, int second) {
    data_021015a0.field_0x2c = 0x340;
    data_021015a0.field_0x38 = 0x1e0;
    data_021015a0.field_0x34 = mode;
    data_021015a0.state = 3;
    data_02101640.field_0xc = first;
    data_02101640.field_0x32 = second;
    data_02101640.fortune = GetOwnerDataFortuneValue_020d4b58();
    data_02101640.field_0x34 = 0x1d4;
    data_02101640.field_0x36 = 0x74;
    data_02101640.field_0x10 = 3;
    data_02101640.field_0x16 = 0;
    data_02101640.field_0x12 = 0;
    data_02101640.field_0xe = 1;
    data_02101640.field_0x14 = mode == 2;
    if (mode == 0 || mode == 2 || mode == 4) {
        data_021015a0.state = 3;
        int result = IssueBattleCommandSlot7((int)CheckField2ThenSubmitOrError0202c864, (Ctx020d507c*)&data_02101640);
        if (result == 2) return 1;
        SetField0x48UnlessState9Or10_0202c848(result);
        data_021015a0.state = 9;
        return 0;
    }
    return 0;
}
