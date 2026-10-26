#include <globaldefs.h>

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0215c464
extern "C" ARM void func_ov003_0215c464(char* obj) {
	struct Elem0205a3d0* e;

	if (*(unsigned char*)(obj + 0x59f) & 2) {
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont != NULL) {
			SpriteEntryList_PlayAnimation(cont, 1);
			e = SpriteEntryList_Find(cont, 1);
			if (e != NULL) {
				*(unsigned char*)((char*)e + 0x15) |= 8;
			}
			SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, *(int*)(obj + 0x574));
			SpriteEntryList_SetPosition(cont, 1, 0xd7, 0x96);
			SpriteEntryList_SetFirstObject(cont, 1, 6);
		}
		SpriteContext_DrawEntries(obj + 0x98);
		return;
	}

	{
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont == NULL) return;
		e = SpriteEntryList_Find(cont, 1);
		if (e != NULL) {
			*(unsigned char*)((char*)e + 0x15) &= ~8;
		}
	}
}
