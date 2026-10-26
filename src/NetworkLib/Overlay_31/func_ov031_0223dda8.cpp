#include <globaldefs.h>

extern "C" int DisableMainBGVRAMBanks();
extern "C" int DisableMainObjVRAMBanks();
extern "C" int DisableMainBGExtendedPaletteVRAMBanks();
extern "C" int DisableMainObjExtendedPaletteVRAMBanks();
extern "C" int DisableTextureImageVRAMBanks();
extern "C" int DisableTexturePaletteVRAMBanks();
extern "C" int DisableClearTextureVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGExtendedPaletteVRAMBanks(void);
extern "C" int DisableSubObjExtendedPaletteVRAMBanks(void);
extern "C" int DisableArm7WorkVRAMBanks(void);
extern "C" int DisableLCDCMappedVRAMBanks(void);
extern "C" void MapVRAMBanksToArm7WorkRAM(int flag);
extern "C" void func_ov031_0223df4c(void);

struct Struct_ov031_02290d68 {
	int field0;
	int field4;
	int field8;
	int fieldC;
	int field10;
	int field14;
	int field18;
	int field1c;
	int field20;
	int field24;
	int field28;
	int field2c;
	int unknown_30_;
};
extern Struct_ov031_02290d68 data_ov031_02290d68;

// USA: func_ov031_0223dda8
extern "C" ARM void func_ov031_0223dda8(void) {
	data_ov031_02290d68.field0 = DisableMainBGVRAMBanks();
	data_ov031_02290d68.field4 = DisableMainObjVRAMBanks();
	data_ov031_02290d68.field8 = DisableMainBGExtendedPaletteVRAMBanks();
	data_ov031_02290d68.fieldC = DisableMainObjExtendedPaletteVRAMBanks();
	data_ov031_02290d68.field10 = DisableTextureImageVRAMBanks();
	data_ov031_02290d68.field14 = DisableTexturePaletteVRAMBanks();
	data_ov031_02290d68.field18 = DisableClearTextureVRAMBanks();
	data_ov031_02290d68.field1c = DisableSubBGVRAMBanks();
	data_ov031_02290d68.field20 = DisableSubObjVRAMBanks();
	data_ov031_02290d68.field24 = DisableSubBGExtendedPaletteVRAMBanks();
	data_ov031_02290d68.field28 = DisableSubObjExtendedPaletteVRAMBanks();
	data_ov031_02290d68.field2c = DisableArm7WorkVRAMBanks();
	data_ov031_02290d68.unknown_30_ = DisableLCDCMappedVRAMBanks();

	MapVRAMBanksToArm7WorkRAM(data_ov031_02290d68.field2c);
	func_ov031_0223df4c();
}
