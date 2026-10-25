#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct S_a0b8c;
struct Obj021e1318;
struct ObjStruct_021e1474;
struct ItemTable;
short CountNonZeroValues020a0b8c(struct S_a0b8c *s);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
void ClearObj_021e1318(struct Obj021e1318 *obj);
void InitScriptAndRun_021e133c(void *a, void *b, int c, int d, int e, short f);
void ClearElements_021e1518(void *p);
void RefreshEntryStatusFlags_021e1474(struct ObjStruct_021e1474 *obj,
                                                                                              struct ItemTable *c);
extern "C" void *ExtractFileFromGP2(const char *gp2Path, const char *innerFilePath, unsigned int *outSize);
extern "C" char data_ov002_0216cf83[];
extern "C" char data_ov002_0216cf99[];

// USA: func_ov002_0215b2c8
extern "C" ARM void func_ov002_0215b2c8(char *base) {
    unsigned int size;
    short buf[0x100];
    GameState *gs;
    char *party;
    void *src;
    int i;
    int j;
    char *sub;
    GameObject *m;
    unsigned char *data;
    short v;
    short count;
    gs    = GameState::GetInstance();
    party = (char *) GameState_GetParty(gs);
    src   = *(void **) party;
    count = CountNonZeroValues020a0b8c((struct S_a0b8c *) party);
    memset(buf, -1, sizeof(buf));
    memcpy(buf, src, count * 2);
    for (i = 0; i < *(unsigned char *) (party + 0xf7c); i++) {
        m = gs->GetPartyMemberByIndex(*(signed char *) (party + 0xf78 + i));
        if (m == NULL) continue;
        data = GetFieldAt0x150_02053c6c((unsigned char *) m);
        for (j = 0; j < 8; j++) {
            v = ((short *) (data + 0x454))[j];
            if (v > 0) {
                buf[count] = v;
                count++;
            }
        }
    }
    ((SafeAllocator *) (arg0 + 0x850))->Reset();
    var7 = arg0 + 4;
    func_ov023_021e1318((struct Struct_ov002_0215505c_2 *) (var7 + 0x800));
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    void *var12 = ExtractFileFromGP2(data_ov002_0216cf83, data_ov002_0216cf99, &var0);
    if (var12 != NULL) {
        func_ov023_021e133c(var7 + 0x800, arg0 + 0x850, (int) var12, var0, (int) var1, var11);
    }
    BackgroundLoader::RemoveLockGlobal();
    ClearElements_021e1518(sub + 0x800);
    RefreshEntryStatusFlags_021e1474(
        (struct ObjStruct_021e1474 *) (sub + 0x800), (struct ItemTable *) (base + 0x3ec + 0x400));
    *(void **) (base + 0x2534) = ((SafeAllocator *) (base + 0x850))->Allocate(0x140);
    *(void **) (base + 0x2538) = ((SafeAllocator *) (base + 0x850))->Allocate(0xa0);
}
