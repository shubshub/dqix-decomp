#include <globaldefs.h>

extern "C" int SpriteContext_DrawSprite(void*, void*);

// USA: func_ov023_021e31e4
ARM int SetShiftedFieldsAndCallTwice_021e31e4(void* obj, int a, int b, int c, short d) {
	char* ctx = *(char**)((char*)obj + 0xcc);
	*(int*)(ctx + 0xb4) = a << 12;
	*(int*)(ctx + 0xb8) = b << 12;
	*(unsigned char*)(ctx + 0xc2) = 0x78;
	*(unsigned char*)(ctx + 0xc6) = 2;
	SpriteContext_DrawSprite(*(void**)((char*)obj + 0xc8), ctx + 0xa0);
	ctx = *(char**)((char*)obj + 0xcc);
	*(int*)(ctx + 0xdc) = c << 12;
	*(int*)(ctx + 0xe0) = d << 12;
	*(unsigned char*)(ctx + 0xea) = 0x77;
	*(unsigned char*)(ctx + 0xee) = 2;
	return SpriteContext_DrawSprite(*(void**)((char*)obj + 0xc8), ctx + 0xc8);
}
