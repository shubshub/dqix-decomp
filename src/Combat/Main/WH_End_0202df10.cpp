#include <globaldefs.h>
int IssueBattleCommandSlot2_020d503c(int);

extern char data_021015a0;
void SetStateFromField0x2_0202d664(unsigned short*);

// Main, originally SetStateAndInvokeCallback_0202df10 (USA 0x0202df10, EUR 0x0202df20, JPN 0x0202da80)
ARM int WH_End() {
    *(int*)(&data_021015a0 + 0x10) = 3;
    if (IssueBattleCommandSlot2_020d503c((int)((void*)SetStateFromField0x2_0202d664)) != 2) {
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0;
    }
    *(short*)(&data_021015a0 + 0xe) = 0;
    return 1;
}
