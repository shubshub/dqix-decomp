#include <globaldefs.h>

extern int g_sePlayer;
void SePlayer_UnloadExtraArchiveB(void* obj);

struct Obj_021be3ec { unsigned char field0; unsigned char field1; };

// Overlay 17, originally ForwardGlobalAndSetFlag_021be3ec (USA/EUR 0x021be3ec, JPN 0x021be9ac)
ARM void FieldTask_EndSpotGrotto(Obj_021be3ec* obj) {
	SePlayer_UnloadExtraArchiveB(&g_sePlayer);
	obj->field1 = 1;
}
