#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

namespace {
struct Struct_ov023_021e761c {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknown_134_[0x5dc - 0x78 - sizeof(CreationWindow)];
    int unknown_5dc_;
};
}

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);

struct Cont0205d228;
extern "C" void Window_DrawPanes(Cont0205d228*);

struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);

extern "C" int SpriteContext_DrawSprite(void*, void*);

#if defined(jpn)
#define func_ov023_021e761c func_ov023_021e7868
extern "C" void func_ov023_021e7868(void* obj);
#endif

// USA: func_ov023_021e761c
// JPN: func_ov023_021e7868
extern "C" ARM void func_ov023_021e761c(void *obj) {
	Struct_ov023_021e761c* state = static_cast<Struct_ov023_021e761c*>(obj);
	if (state->unknown_5dc_ == 0) return;

	Window_ClearLayers(((Cont0205d1e0*)(&state->window)));
	Window_DrawPanes(((Cont0205d228*)(&state->window)));
	Window_FlushLayers(((Cont0205d274*)(&state->window)));

#if !defined(jpn)
	char* base = static_cast<char*>(obj);
	if (*(int*)(base + 0x3c) != 2) return;
	if (*(int*)(base + 0x604) == 0) return;

	char *p = *(char**)(base + 0x608);
	if (p == NULL) return;

	unsigned char flag = *(unsigned char*)(base + 0x60d);
	int kind;
	if (flag != 0) {
		unsigned char idx = *(unsigned char*)(base + 0x60c);
		p = p + idx * 0x28;
		kind = idx + 3;
	} else {
		p = p + 0x50;
		kind = 5;
	}
	*(unsigned char*)(p + 0x22) = (unsigned char)kind;
	*(int*)(p + 0x14) = 0xd0000;
	*(int*)(p + 0x18) = 0x10000;

	SpriteContext_DrawSprite(*(void**)(base + 0x604), p);
#endif
}

#if defined(jpn)
#undef func_ov023_021e761c
#endif
