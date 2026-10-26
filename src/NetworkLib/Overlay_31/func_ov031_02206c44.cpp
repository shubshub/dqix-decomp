#include <globaldefs.h>

extern "C" int func_ov031_02206d90(void);
extern "C" void func_ov031_02200534(void);
extern "C" int func_ov031_022050c4(void);
extern "C" void func_ov031_02200524(int v);
extern void SleepCurrentContext(unsigned int milliseconds);

extern int data_ov031_0224e1c4;
extern int data_ov031_0224c9d0;

struct Struct_ov031_02206c44 {
	char pad[0x1c];
	void (*field1c)(int);
	char pad2[8];
	int field28;
};
extern Struct_ov031_02206c44* data_ov031_022496a4;

struct Struct_ov031_0224e1d0_2 {
	char pad[0x1c];
	int field1c;
};
extern Struct_ov031_0224e1d0_2 data_ov031_0224e1d0;

// USA: func_ov031_02206c44
extern "C" ARM int func_ov031_02206c44(void) {
	if (data_ov031_0224e1c4 == 0) {
		data_ov031_0224e1c4 = data_ov031_0224c9d0;
	}

	int status = func_ov031_02206d90();
	if (status == -26) {
		do {
			SleepCurrentContext(100);
			status = func_ov031_02206d90();
		} while (status == -26);
	}

	int result = func_ov031_022050c4();
	if (result >= 0) {
		func_ov031_02200534();
		func_ov031_02200524(0);
		if (data_ov031_022496a4->field28 == 0) {
			data_ov031_022496a4->field1c(data_ov031_0224e1d0.field1c);
		}
		data_ov031_022496a4 = 0;
	}

	return result;
}
