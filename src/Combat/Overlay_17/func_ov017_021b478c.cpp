#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"
#include "std_library_functions.h"
#include "World/GrottoTileGraph.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTable(void* obj);
extern "C" int ZoneId_IsMainGrottoFloor(int id);
extern "C" void func_0209bffc(void* obj);
extern "C" void func_0209bc84(void* obj);
struct ResetObject0209af34Struct;
extern "C" void func_0209af34(struct ResetObject0209af34Struct* obj);
extern "C" void func_0206efc4(void* obj);
struct ZeroWordAndByte0206ee60Struct;
extern "C" void func_0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
extern "C" void func_020a8e88(void* obj);

extern const char data_ov017_021d7afc[];
extern const char data_ov017_021d7b06[];
extern const char data_ov017_021d7b0d[];
extern const char data_ov017_021d7b24[];
extern const char data_ov017_021d7b3a[];

struct MonsterEntry021b478c {
    unsigned short key;
    unsigned char pad2[3];
    char name[1];
};

struct SearchTable;
extern "C" MonsterEntry021b478c* ZoneTable_FindEntry(struct SearchTable* table, int key);

struct Struct_ov017_021b478c {
    unsigned char pad0;
    unsigned char done;
    unsigned char pad2[8 - 2];
    Struct_0201a300_4* monster;
    int taskId;
    unsigned char state;
};

// USA: func_ov017_021b478c
extern "C" ARM void func_ov017_021b478c(Struct_ov017_021b478c* request) {
#if defined(jpn)
 enum {regionalOffset0=0x240c, regionalOffset1=0x40, regionalOffset2=0x5c, regionalOffset3=0x120, regionalOffset4=0x2f4, regionalOffset5=0x300, regionalOffset6=0x308, Enum_ov017_021b478c_1092=0x444};
#else
 enum {regionalOffset0=0x23ec, regionalOffset1=0x44, regionalOffset2=0x60, regionalOffset3=0x124, regionalOffset4=0x2f8, regionalOffset5=0x304, regionalOffset6=0x30c, Enum_ov017_021b478c_1060=0x424};
#endif
    GameState* battle;
    BackgroundLoader* loader;
    struct SearchTable* table;
    Zone3D* zone;
    int id;
    MonsterEntry021b478c* entry;
    char* monster;
    ActiveGrottoClass* grotto;

    battle = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    table = (struct SearchTable*)GameState_GetZoneTable(battle);
    zone = Zone3D_GetInstance();
    grotto = &zone->grotto_;
    id = request->monster->zoneId;
    entry = ZoneTable_FindEntry(table, id);

    monster = (char*)request->monster;
    func_0209bffc(monster + regionalOffset1);
    func_0209bc84(monster + regionalOffset2);
    func_0209af34((struct ResetObject0209af34Struct*)(monster + regionalOffset3));
    func_0206efc4(monster + regionalOffset4);
    func_0206ee60((struct ZeroWordAndByte0206ee60Struct*)(monster + regionalOffset5));
    func_020a8e88(monster + regionalOffset6);

    if (request->monster->zoneId == 3 || request->monster->allocator->GetSignedAllocator() == NULL) {
        request->done = 1;
        return;
    }

    if (!ZoneId_IsMainGrottoFloor(id)) {
        char name[0x14];
        char path[0x50];
        if (strlen(entry->name) < 6) {
            sprintf(name, data_ov017_021d7afc, entry->name);
        } else {
            sprintf(name, data_ov017_021d7b06, entry->name);
        }
        name[3] = 'P';
        strcpy(path, name);
        request->taskId = loader->QueueLoadFileInGP2(data_ov017_021d7b0d, path, NULL);
        request->state = 1;
        return;
    }

    if (id != battle->GetProtagonist()->obj3D_.GetField06()) {
        char var10[0x50];
        sprintf(var10, data_ov017_021d7b24, grotto->GetActiveGrottoEnviron());
        request->taskId = loader->QueueLoadFile(var10, NULL);
        request->state = 2;
        return;
    }

    if (ZoneId_IsMainGrottoFloor(id)) {
        int floor = id % 20;
        if (grotto->floorMap_.pMapData == NULL || zone->unknown_424_ != 0) {
            return;
        }
        func_0201a300(zone, floor, request->monster, 0, 0);
    }
    request->monster->loaded = 1;
    request->taskId = loader->QueueLoadFile(data_ov017_021d7b3a, NULL);
    request->state = 3;
}
