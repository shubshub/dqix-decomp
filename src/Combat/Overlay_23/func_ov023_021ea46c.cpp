#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

#if defined(jpn)
struct Struct_ov023_021ea46c { char pad[0x144]; char* unknown_150_; };
#else
struct Struct_ov023_021ea46c { char pad[0x150]; char* unknown_150_; };
#endif

// USA: func_ov023_021ea46c
extern "C" ARM int func_ov023_021ea46c(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	GameState* bs = GameState::GetInstance();
	unsigned char buf[4];
	__clear(buf, 4);
	unsigned char len = GameState_GetOwnPartyOrder((char*)bs, buf);
	int count = 0;
	for (int i = 0; i < len; i++) {
		unsigned char id = buf[i];
		struct Struct_ov023_021ea46c* c = (struct Struct_ov023_021ea46c*)func_0200ff1c(bs, id);
		if (c) {
			int val = *(int*)(c->unknown_150_ + regionalOffset0);
			if ((unsigned int)val <= 9) {
				switch (val) {
					case 1:
					case 4:
					case 7:
					case 9:
						count++;
						break;
				}
			}
		}
	}
	func_ov017_021d6134(obj, count);
	return 1;
}
