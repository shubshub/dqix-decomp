#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_022188e4 {
	unsigned char pad0[0x1024];
	char buf[0x100];
	char* cursor;
	char* cursor2;
	unsigned char pad1[4];
	int flag;
	unsigned short value;
};

extern int data_ov031_02249f24;
extern int data_ov031_02249f2c;
extern int data_ov031_02249f38;
extern int data_ov031_02249f3c;

extern "C" int func_02005a94(char* s);

// USA: func_ov031_022188e4
extern "C" ARM int func_ov031_022188e4(void* self, const char* s) {
	Struct_ov031_022188e4* p = (Struct_ov031_022188e4*)self;
	char* tail = NULL;
	if (strlen(s) >= 0x100) {
		return 0;
	}
	strncpy(p->buf, s, 0x100);
	if (strlen(s) != strlen(p->buf)) {
		return 0;
	}
	if (strstr(p->buf, (const char*)&data_ov031_02249f24) != NULL) {
		p->cursor = p->buf + 7;
		p->flag = 0;
		p->value = 0x50;
	} else {
		char* found = strstr(p->buf, (const char*)&data_ov031_02249f2c);
		if (found == NULL) {
			return 0;
		}
		p->cursor = found + 8;
		p->flag = 1;
		p->value = 0x1bc - p->flag;
	}
	char* var3 = strstr(p->cursor, (const char*)&data_ov031_02249f38);
	if (var3 != NULL) {
		*var3 = 0;
		tail = var3 + 1;
	}
	char* var4 = strstr(p->cursor, (const char*)&data_ov031_02249f3c);
	if (var4 == NULL) {
		p->cursor2 = NULL;
	} else {
		*var4 = 0;
		p->cursor2 = var4 + 1;
	}
	if (tail != NULL) {
		p->value = func_02005a94(tail);
	}
	return 1;
}
