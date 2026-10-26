#include <globaldefs.h>

struct Struct_ov031_02230330 { unsigned short x, y; };
struct Struct_ov031_02248f60 { Struct_ov031_02230330 pos; Struct_ov031_02230330 size; };
struct Struct_ov031_02290ca0_15 {
	unsigned char unk0;
	unsigned char unknown_1_;
	unsigned char unk2;
	unsigned char unknown_3_;
	unsigned short field4;
};

extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" int func_ov031_0223d49c(Struct_ov031_02248f60* p);
extern "C" int func_ov031_0223d634(Struct_ov031_02248f60* box);

extern Struct_ov031_02248f60 data_ov031_022493b8;
extern Struct_ov031_02290ca0_15 data_ov031_02290ca0;
extern const unsigned char data_ov031_02248f5c[4] = {2, 3, 7, 8};
extern const Struct_ov031_02248f60 data_ov031_02248f60 = {{204, 52}, {28, 24}};
extern const Struct_ov031_02248f60 data_ov031_02248f68 = {{143, 52}, {44, 24}};
extern const Struct_ov031_02248f60 data_ov031_02248f70 = {{192, 52}, {44, 24}};
extern unsigned char data_ov031_0224903c[];
extern Struct_ov031_02248f60 data_ov031_02248fea[3];

// USA: func_ov031_02230330
extern "C" ARM int func_ov031_02230330(void) {
	Struct_ov031_02248f60 box;

	if (!func_ov031_0223d49c(&data_ov031_022493b8)) return 0xe;

	{
		int var1 = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
		int i = 0;
		box = data_ov031_02248f60;
		do {
			if (var1 != 2 && var1 != 6) {
				if (func_ov031_0223d634(&box)) return data_ov031_0224903c[var1];
			}
			box.pos.y += 0x1d;
			i++;
			var1++;
		} while (i < 4);
	}
	{
		int var3 = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
		int i = 0;
		do {
			if (var3 == 2) {
				int off = i * 0x1d;
				box = data_ov031_02248f70;
				box.pos.y += off;
				if (func_ov031_0223d634(&box)) return 2;
				box = data_ov031_02248f68;
				box.pos.y += off;
				if (func_ov031_0223d634(&box)) return 3;
				break;
			}
			i++;
			var3++;
		} while (i < 4);
	}
	{
		int var6 = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
		int i = 0;
		do {
			if (var6 == 6) {
				int off = i * 0x1d;
				box = data_ov031_02248f70;
				box.pos.y += off;
				if (func_ov031_0223d634(&box)) return 7;
				box = data_ov031_02248f68;
				box.pos.y += off;
				if (func_ov031_0223d634(&box)) return 8;
				break;
			}
			i++;
			var6++;
		} while (i < 4);
	}
	{
		Struct_ov031_02248f60* p = data_ov031_02248fea;
		int i = 0;
		do {
			if (func_ov031_0223d49c(p)) return i + 0xb;
			i++;
			p++;
		} while (i < 3);
	}
	return 0xe;
}
