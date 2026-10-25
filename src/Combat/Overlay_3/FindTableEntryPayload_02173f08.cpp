#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);
extern signed char data_ov003_0217fad4[];

// USA: func_ov003_02173f08
ARM void FindTableEntryPayload_02173f08(char* out1, char* out2, char* out3, char* out4) {
	signed char v = (signed char)GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
	signed char* p = data_ov003_0217fad4;
	while (1) {
		signed char tag = *p;
		if (tag < 0) { p = data_ov003_0217fad4; break; }
		if (tag == v) break;
		p++;
	}
	*out1 = p[1];
	*out2 = p[2];
	*out3 = p[3];
	*out4 = p[4];
}
