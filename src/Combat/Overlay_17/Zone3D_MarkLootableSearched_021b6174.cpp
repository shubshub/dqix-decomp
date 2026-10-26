#include <globaldefs.h>



extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Zone3D_BreakLootable(void* obj, int index);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);
struct Obj02028c14;
extern "C" void ZoneRecord_SetLootableSearched(struct Obj02028c14* obj, int index);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

// Overlay 17, originally func_ov017_021b6174 (USA/EUR 0x021b6174, JPN 0x021b6728)
extern "C" ARM void Zone3D_MarkLootableSearched(int zoneId, int lootableIndex, int containerId) {
	void* zone = Zone3D_GetInstance();
	void* progress = Scenario_GetInstance();
	unsigned short currentZoneId = *(unsigned short*)zone;
	if (zoneId == currentZoneId) {
		Zone3D_BreakLootable(zone, lootableIndex);
	}
	struct Entry_02028bd0* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), zoneId);
	if (entry != NULL) {
		ZoneRecord_SetLootableSearched((struct Obj02028c14*)entry, lootableIndex);
	}
	Scenario_SetFlag(progress, (unsigned char*)progress + 0x8c, containerId + 0x9e + 0x700, 1);
}
