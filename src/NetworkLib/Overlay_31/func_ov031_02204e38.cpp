#include <globaldefs.h>
#include <NitroSDK/Memory.h>

extern "C" void func_ov031_0220057c(unsigned int priority);
extern "C" void func_ov031_0220f0e4(int v);
extern "C" void func_ov031_02200524(int v);
extern "C" void func_ov031_02200298(void* settings);
extern "C" void func_ov031_02200aa0(void);
extern "C" int func_ov031_02205018(void);
extern "C" void func_ov031_02206c08(void);
extern "C" void func_ov031_02205000(void);
extern "C" void func_ov031_02204f94(void);

struct Struct_ov031_02204e38 {
	int mode;
	char pad4[0x14];
	void* (*alloc)(int);
	void (*unknown_1c_)(void*);
	char pad20[4];
	int unknown_24_;
	void* buffer;
	int priority;
	int width;
	int height;
};
extern Struct_ov031_02204e38* data_ov031_022496a4;

struct Struct_ov031_022496c4 {
	unsigned short pad0;
	unsigned short height;
	unsigned short unknown_4_;
	char pad6[0x12];
};
extern Struct_ov031_022496c4 data_ov031_022496c4;
extern int data_ov031_0224c9d0;

struct Struct_ov031_02204e38_2 {
	int field0;
	void* (*alloc)(int);
	void (*unknown_8_)(void*);
	void (*callback)(void);
	int (*check)(void);
	int field14;
	int field18;
	void* buffer;
	int unknown_20_;
	int width;
	int field28;
	int field2c;
};

struct Struct_ov031_0224e1c0_2 {
	int field0;
	int field4;
	int field8;
	int fieldc;
	Struct_ov031_02204e38_2 settings;
};
extern Struct_ov031_0224e1c0_2 data_ov031_0224e1c0;

enum Enum_ov031_02204e38 { Enum_ov031_02204e38_1 = 1 };

// USA: func_ov031_02204e38
extern "C" ARM void func_ov031_02204e38(void) {
	Struct_ov031_02204e38_2* settings = &data_ov031_0224e1c0.settings;
	Struct_ov031_02204e38* var1 = data_ov031_022496a4;
	void* buffer;
	int width;
	int height;
	Enum_ov031_02204e38 on;

	VectorizedMemset(settings, 0, sizeof(Struct_ov031_02204e38_2));
	data_ov031_0224e1c0.settings.alloc = var1->alloc;
	data_ov031_0224e1c0.settings.unknown_8_ = var1->unknown_1c_;
	data_ov031_0224e1c0.settings.check = func_ov031_02205018;
	data_ov031_0224e1c0.settings.field14 = 0;
	data_ov031_0224e1c0.settings.field18 = 0;
	data_ov031_0224e1c0.settings.field2c = data_ov031_0224e1c0.field0;

	if (var1->unknown_24_ != 0) {
		settings->unknown_20_ = var1->unknown_24_;
	} else {
		settings->unknown_20_ = 0x4000;
	}
	buffer = var1->buffer;
	if (buffer == NULL) {
		buffer = data_ov031_022496a4->alloc(settings->unknown_20_);
	}
	settings->buffer = buffer;

	width = var1->width != 0 ? var1->width : 0x240;
	height = var1->height != 0 ? var1->height : 0x10c0;
	data_ov031_022496c4.height = height;
	data_ov031_022496c4.unknown_4_ = height / 2;
	settings->width = width - 0x28;
	data_ov031_0224c9d0 = 0;

	on = Enum_ov031_02204e38_1;
	if (var1->mode != 0) {
		settings->field0 = 0;
		settings->callback = func_ov031_02205000;
		data_ov031_0224e1c0.field8 = on;
		settings->field28 = data_ov031_0224e1c0.field4;
	} else {
		data_ov031_0224e1c0.field8 = 0;
		settings->field0 = on;
		settings->callback = func_ov031_02204f94;
	}

	func_ov031_0220057c(var1->priority != 0 ? var1->priority : 0xb);
	func_ov031_0220f0e4((int)func_ov031_02200aa0);
	func_ov031_02200524((int)func_ov031_02206c08);
	func_ov031_02200298(settings);
}
