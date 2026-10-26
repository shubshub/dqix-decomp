#include <globaldefs.h>

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
    unsigned char unknown_c0_[0x5];
    unsigned char flagsC5;
};
extern "C" struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsOpen(unsigned char* p);

struct Container0205a3d0;
struct Elem0205a3d0 {
    unsigned char pad0[0x15];
    unsigned char flags;
};
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0215c32c
extern "C" ARM void func_ov003_0215c32c(char* obj) {
	struct Elem0205a3d0* e;

	if (*(unsigned char*)(obj + 0x59f) & 1) {
		struct Struct_020e28dc* choice = *(struct Struct_020e28dc**)(obj + 0x570);
		if (choice != NULL && func_020e28dc(choice)) {
			SpriteContext_DrawEntries(obj + 0x98);
			return;
		}

		struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)(obj + 0xf4));
		if (elem == NULL) return;
		if (!WindowPane_IsOpen((unsigned char*)elem)) return;
		if (elem->flagsC5 & 0x20) return;

		short x = (short)(elem->unknown_ac_ * 8);
		short y = (short)(elem->unknown_ae_ * 8);
		x += elem->unknown_bc_;
		y += elem->unknown_be_;
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont != NULL) {
			SpriteEntryList_PlayAnimation(cont, 0);
			e = SpriteEntryList_Find(cont, 0);
			if (e != NULL) {
				e->flags |= 8;
			}
			SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, *(int*)(obj + 0x574));
			SpriteEntryList_SetPosition(cont, 0, x - 8, y - 2);
			SpriteEntryList_SetFirstObject(cont, 0, 0);
		}
		SpriteContext_DrawEntries(obj + 0x98);
		return;
	}

	{
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont == NULL) return;
		e = SpriteEntryList_Find(cont, 0);
		if (e != NULL) {
			e->flags &= ~8;
		}
	}
}
