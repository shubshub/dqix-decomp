#include <globaldefs.h>

extern "C" int* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
void MapDisplay_DrawSprite(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);

// Main, originally func_0202720c (USA 0x0202720c, EUR 0x0202721c, JPN 0x02026b70)
extern "C" ARM void MapDisplay_DrawTreasureMap(void* obj) {
    int band = 5;
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
    if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) band += 0x10;
    MapDisplay_DrawSprite(obj, band << 12, 0x5000, 0x17, 0x40, 1, 0xff, 0xff, 0x1000, 0x1000);
}
