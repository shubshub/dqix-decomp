#include <globaldefs.h>

int PopCount32_020d1ae4(unsigned int);
unsigned short WH_GetBitmap(void);
void EmptyStub0202aebc(void);
int IssueBattleCommandSlot24_020d69cc(int, int, int, int, unsigned short, unsigned char);

#pragma optimize_for_size off
// Main, originally func_0202bc00 (USA 0x0202bc00, EUR 0x0202bc10, JPN 0x0202b7b0)
extern "C" ARM int LinkSession_UpdateBeacon(void* obj, int flag) {
    unsigned short* p = (unsigned short*)((char*)obj + 0x102a);
    *p = *p + 1;
    unsigned char* q = (unsigned char*)((char*)obj + 0x1029);
    int idx = (PopCount32_020d1ae4(WH_GetBitmap()) - 1) & 0xff;
    int f = flag != 0;
    *q = (*q & ~7) | (idx & 7);
    unsigned short field4 = *(unsigned short*)((char*)obj + 4);
    return IssueBattleCommandSlot24_020d69cc((int)(void*)EmptyStub0202aebc, (int)((char*)obj + 0x1014), 0x24, 0x785, field4, (unsigned char)(f & 0xff));
}
