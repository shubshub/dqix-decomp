#include <globaldefs.h>

struct Struct_ov031_02207230;
extern "C" int func_ov031_02207230(void* ctx, Struct_ov031_02207230* arg1);

struct Struct_ov031_02241404 {
	char pad0[2];
	unsigned short half;
	unsigned int word;
};

struct Struct_ov031_02241404_2 { char pad[4]; int flag; };

// USA: func_ov031_02241404
extern "C" ARM int func_ov031_02241404(Struct_ov031_02241404_2* self, void* ctx, unsigned int word, unsigned int arg3) {
	Struct_ov031_02241404 var0;
	var0.pad0[0] = 8;
	var0.pad0[1] = 2;
	unsigned short v = (unsigned short)arg3;
	var0.half = (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
	var0.word = word;
	int r = func_ov031_02207230(ctx, (Struct_ov031_02207230*)&var0);
	if (r < 0) {
		if (self->flag != 0) return (int)0xfffffc16;
		return ~0x3e8;
	}
	return 0;
}
