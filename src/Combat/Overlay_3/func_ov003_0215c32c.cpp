#include <globaldefs.h>

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* arg0);

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
    unsigned char unknown_c0_[0x5];
    unsigned char unknown_c5_;
};
struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
int WindowPane_IsOpen(unsigned char* p);

struct Struct_0205a254;
struct Struct_0205a254_2 {
    unsigned char unknown_0_[0x15];
    unsigned char unknown_15_;
};
struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0215c32c
extern "C" ARM void func_ov003_0215c32c(char* arg0) {
	struct Struct_0205a254_2* var0;

	if (*(unsigned char*)(obj + 0x59f) & 1) {
		struct Outer020e28dc* choice = *(struct Outer020e28dc**)(obj + 0x570);
		if (choice != NULL && GetInnerFlagBit0020e28dc(choice)) {
			SpriteContext_DrawEntries(obj + 0x98);
			return;
		}

		struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)(obj + 0xf4));
		if (elem == NULL) return;
		if (!WindowPane_IsOpen((unsigned char*)elem)) return;
		if (elem->flagsC5 & 0x20) return;

		short x = (short)(elem->fac * 8);
		short y = (short)(elem->fae * 8);
		x += elem->fbc;
		y += elem->fbe;
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
