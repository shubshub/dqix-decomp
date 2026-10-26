#include <globaldefs.h>

struct Struct_ov023_021e257c_2 {
	short key;
	unsigned char kind;
	unsigned char unknown_3_0_ : 4;
	unsigned char unknown_3_4_ : 4;
	char pad4[4];
	short unknown_8_;
	short unknown_a_;
	void* ptrC;
	unsigned char unknown_10_0_ : 4;
	unsigned char unknown_10_4_ : 1;
	unsigned char unknown_10_5_ : 1;
	unsigned char unknown_10_6_ : 1;
	unsigned char unknown_10_7_ : 1;
	char unknown_11_[3];
};

struct Struct_ov023_021e257c {
	char pad0[4];
	void* state;
	char pad8[4];
	Struct_ov023_021e257c_2* entries;
	char pad10[6];
	unsigned short unknown_16_;
	char pad18[0x48 - 0x18];
	short field48;
	short unknown_4a_;
};

struct Struct_ov023_021e257c_3;
extern "C" ARM void* func_ov023_021e27f8(struct Struct_ov023_021e257c_3* obj, int key);
extern "C" ARM void func_ov023_021e2030(int a, int arg1, int arg2, void* cursor);
extern "C" int func_ov023_021e2c38(void* obj, int val);
extern "C" void func_ov023_021e2b5c(void* obj, int key, short* out1, short* out2);
extern "C" void func_0204f914(void* a, int nibble, int y, int x, int arg4, int arg5);
extern "C" int Font_GetTextWidth(void* ptr, int flag);
extern "C" void func_0204f41c(void* a, int y, int x, void* ptrC, int loNibble, int hiNibble, short* arg6, short* arg7, int zero);
extern "C" void func_0204f7e8(void* a, int y, int x, void* ptrC, int loNibble, int hiNibble, short* arg6, short* arg7, int arg8, int arg9, bool arg10, bool arg11);

#if defined(jpn)
extern "C" void __clear(void*, int);
extern "C" int sprintf(char*,const char*,...);
extern char data_ov023_021fcf44[];
extern "C" void func_02050678(void*,int,int,void*,int,int,short*,short*);
extern "C" void func_02050cc0(void*,int,int,void*,int,int,short*,short*,int,int,bool,bool);
#endif

extern "C" ARM void func_ov023_021e257c(struct Struct_ov023_021e257c* obj) {
	if (obj->state == 0) return;
	unsigned short i;
	for (i = 0; i < obj->unknown_16_; i++) {
		Struct_ov023_021e257c_2* elem = &obj->entries[i];
		void* found = func_ov023_021e27f8((struct Struct_ov023_021e257c_3*)obj, elem->key);
		if (!found) continue;
		if (!func_ov023_021e2c38(obj, *(short*)found)) continue;
		short y, x;
		func_ov023_021e2b5c(obj, elem->key, &y, &x);

#if defined(jpn)
		unsigned nibble;
		short var5;
		nibble=elem->unknown_3_0_;
		var5=(short)(nibble+1);
		if(nibble==0xc) var5=0x14;
		void* state=obj->state;
#else
		short var5 = obj->field48;
		int nibble = elem->unknown_3_0_;
		void* state = obj->state;
		if (var5 == 0) var5 = (short)(nibble + 1);
		if (nibble == 0xc) {
			var5 = obj->unknown_4a_;
			if (var5 == 0) var5 = 0x14;
		}
#endif
		*(short*)((char*)state + 0xb4) = (short)nibble;
		*(short*)((char*)state + 0xb6) = var5;

		switch (elem->kind) {
		case 0: {
			int var8 = (short)(y + elem->unknown_8_);
			int var9 = (short)(x + elem->unknown_a_);
			func_0204f914(obj->state, elem->unknown_3_4_, y, x, var8, var9);
			break;
		}
		case 1: {
#if defined(jpn)
			char buffer[0x400];
			__clear(buffer,0x400);
			sprintf(buffer,data_ov023_021fcf44,*(short*)((char*)found+0x14),elem->ptrC);
			func_02050678(obj->state,y,x,buffer,elem->unknown_3_0_,elem->unknown_3_4_,&elem->unknown_8_,&elem->unknown_a_);
#else
			if (*((unsigned char*)found + 0x16) & 0x8) y -= Font_GetTextWidth(elem->ptrC, 0) >> 1;
			if (*((unsigned char*)found + 0x16) & 0x10) y -= Font_GetTextWidth(elem->ptrC, 0);
			func_0204f41c(obj->state, y, x, elem->ptrC, elem->unknown_3_0_, elem->unknown_3_4_, &elem->unknown_8_, &elem->unknown_a_, 0);
#endif
			break;
		}
		case 2: {
#if defined(jpn)
			func_02050cc0
#else
			func_0204f7e8
#endif
			(obj->state, y, x, elem->ptrC, elem->unknown_3_0_, elem->unknown_3_4_, &elem->unknown_8_, &elem->unknown_a_,
				elem->unknown_10_4_, elem->unknown_10_0_, elem->unknown_10_5_, elem->unknown_10_6_);
			break;
		}
#if !defined(jpn)
		case 3:
			func_ov023_021e2030((int)obj->state, y, x, elem->ptrC);
			break;
#endif
		}
	}
}
