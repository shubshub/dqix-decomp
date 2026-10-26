#include <globaldefs.h>

struct Container020e0310;
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

extern char data_ov003_0217fe7f;

// USA: func_ov003_0215be70
extern "C" ARM void func_ov003_0215be70(char* base, char* dst, int flag) {
	int i;
	struct Container020e0310* c;
	signed char cursor;

	if (dst == NULL) return;

	cursor = *(signed char*)(base + 0x586);
	if (flag) {
		Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
	}
	Text_AppendCursorTag(dst, cursor);

	c = (struct Container020e0310*)(base + 0x64);
	for (i = 0; i < 2; i++) {
		int name = KeyTable_Get(c, (short)(i + 0x14));
		Text_AppendNTag(dst, i, (const char*)name);
		if (i != 1) {
			Text_Append(dst, &data_ov003_0217fe7f);
		}
	}
}
