#include <globaldefs.h>

extern "C" int DisableMainBGVRAMBanks();
extern "C" int DisableMainObjVRAMBanks();
extern "C" void DisableSubBGVRAMBanks();
extern "C" void DisableSubObjVRAMBanks(void);
extern "C" void func_ov031_0223df4c();
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToMainBGExtendedPalette(int mode);
extern "C" void MapVRAMBanksToMainObjExtendedPalette(unsigned int flag);
extern "C" void MapVRAMBanksToTextureImage(int v);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToClearTextures(int mode);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBGExtendedPalette(unsigned short value);
extern "C" void MapVRAMBanksToSubObjExtendedPalette(unsigned short value);
extern "C" void MapVRAMBanksToLCDC(unsigned short mask);

struct Struct_ov031_02290d68_2 {
    int field0, field4, field8, fieldc, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, unknown_30_;
};
extern Struct_ov031_02290d68_2 data_ov031_02290d68;

typedef void (*Type_ov031_0223de5c)(int);

// USA: func_ov031_0223de5c
extern "C" ARM void func_ov031_0223de5c() {
    DisableMainBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableSubObjVRAMBanks();
    func_ov031_0223df4c();

    MapVRAMBanksToMainBG(data_ov031_02290d68.field0);
    MapVRAMBanksToMainObj(data_ov031_02290d68.field4);
    MapVRAMBanksToMainBGExtendedPalette(data_ov031_02290d68.field8);
    MapVRAMBanksToMainObjExtendedPalette(data_ov031_02290d68.fieldc);
    MapVRAMBanksToTextureImage(data_ov031_02290d68.field10);
    MapVRAMBanksToTexturePalette(data_ov031_02290d68.field14);
    MapVRAMBanksToClearTextures(data_ov031_02290d68.field18);
    MapVRAMBanksToSubBG(data_ov031_02290d68.field1c);
    ((Type_ov031_0223de5c)MapVRAMBanksToSubObj)(data_ov031_02290d68.field20);
    ((Type_ov031_0223de5c)MapVRAMBanksToSubBGExtendedPalette)(data_ov031_02290d68.field24);
    ((Type_ov031_0223de5c)MapVRAMBanksToSubObjExtendedPalette)(data_ov031_02290d68.field28);
    ((Type_ov031_0223de5c)MapVRAMBanksToLCDC)(data_ov031_02290d68.unknown_30_);

    *(volatile unsigned short *)0x4000050 = 0;
    *(volatile unsigned short *)0x4001050 = 0;
    *(volatile unsigned int *)0x4000010 = 0;
    *(volatile unsigned int *)0x4000014 = 0;
    *(volatile unsigned int *)0x4000018 = 0;
    *(volatile unsigned int *)0x400001c = 0;
    *(volatile unsigned int *)0x4001010 = 0;
    *(volatile unsigned int *)0x4001014 = 0;
    *(volatile unsigned int *)0x4001018 = 0;
    *(volatile unsigned int *)0x400101c = 0;
}
