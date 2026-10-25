#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_02245528;
extern "C" void func_ov031_02245528(struct Struct_02245528* arg0, int arg1);
extern "C" int func_ov031_02212cbc(void* arg0);
extern "C" void func_ov031_022434b4(void);
void FreeIfNonNull_022434e8(void* a, void* b);
void SetGlobalFields_02211b40(void* a, void* b);
extern int g_fileLoadBuffer;

struct Struct_ov031_02243c10 {
	unsigned char unknown_0_[0x35];
	unsigned char unknown_35_;
	unsigned char unknown_36_[0x48 - 0x36];
	void* unknown_48_;
	void* unknown_4c_;
	unsigned char unknown_50_[0x374 - 0x50];
	unsigned char unknown_374_;
	unsigned char unknown_375_[0x37c - 0x375];
	void* unknown_37c_;
	unsigned int unknown_380_;
	unsigned char unknown_384_[0x438 - 0x384];
	unsigned char unknown_438_;
	unsigned char unknown_439_;
};

// USA: func_ov031_02243c10
extern "C" ARM void func_ov031_02243c10(Struct_ov031_02243c10* arg0) {
	switch (arg0->unknown_35_) {
	case 0:
		if (!(arg0->unknown_374_ & 1) && !(arg0->unknown_374_ & 2)) goto skip374;
		if (arg0->unknown_37c_ == 0) {
			BackgroundLoader* var0 = BackgroundLoader::GetInstance();
			if (var0->GetNumQueuedTasks() > 0) {
				func_ov031_02245528((struct Struct_02245528*)arg0, 0);
				return;
			}
			obj->ptr37c = &g_fileLoadBuffer;
			obj->size380 = 0x30000;
		}
		memset(arg0->unknown_37c_, 0, arg0->unknown_380_);
		arg0->unknown_48_ = arg0->unknown_37c_;
	skip374:
		{
			int var1 = func_ov031_02212cbc(arg0->unknown_4c_);
			arg0->unknown_439_ = 1;
			if (var1 == 3) {
				arg0->unknown_35_ = 8;
				arg0->unknown_438_ = 1;
			} else {
				arg0->unknown_35_ = 6;
			}
		}
		break;
	case 6:
		func_ov031_02211b40((void*)func_ov031_022434b4, (void*)func_ov031_022434e8);
		func_ov031_02245528((struct Struct_02245528*)arg0, 2);
		break;
	case 7:
		func_ov031_02245528((struct Struct_02245528*)arg0, 0);
		break;
	case 8:
		func_ov031_02245528((struct Struct_02245528*)arg0, 0);
		break;
	default:
		break;
	}
}
