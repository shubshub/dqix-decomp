#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* p);

struct LocalEvt021ce494 {
	unsigned char tag;
	unsigned char pad[0x13];
};

// USA: func_ov017_021ce494
ARM void EnqueueEventTag40IfNotBusy_021ce494(void) {
	void* x = LinkSession_GetInstance();
	if (LinkSession_IsHostOrSolo(x) != 0) {
		return;
	}
	if (GameState::GetInstance()->GetPartyMemberByIndex(0xce) != NULL) {
		return;
	}
	LocalEvt021ce494 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x28;
	func_0205e330(p, &buf, 0);
}
