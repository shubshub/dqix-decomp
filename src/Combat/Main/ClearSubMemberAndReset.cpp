#include <globaldefs.h>

void ZoneTable_Clear(unsigned int*);
extern "C" void func_0200f3a4(void*);

// GameState's zone table: 16-byte entries keyed by zone id (a SearchTable), which Zone3D::SwitchZone and
// FieldTask_EnterZone look a zone up in (GameState_GetZoneTable returns its address)
enum { kGameStateZoneTableOffset = 0x468 };

// KEEP-NAME
// USA: func_02012200
ARM char* ClearSubMemberAndReset_02012200(char* gameState) {
    ZoneTable_Clear((unsigned int*)(gameState + kGameStateZoneTableOffset));
    func_0200f3a4(gameState);
    return gameState;
}
