#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct_02245528;
extern "C" void func_ov031_02245528(struct Struct_02245528* p, int v);
extern "C" int func_ov031_02212cbc(void* p);
extern "C" void func_ov031_022434b4(void);
extern "C" void func_ov031_022434e8(void* a, void* b);
extern "C" void func_ov031_02211b40(void* a, void* b);
extern int g_fileLoadBuffer;

struct Struct_ov031_02243c10 {
	unsigned char pad0[0x35];
	unsigned char unknown_35_;
	unsigned char pad1[0x48 - 0x36];
	void* field48;
	void* field4c;
	unsigned char pad2[0x374 - 0x50];
	unsigned char unknown_374_;
	unsigned char unknown_375_[0x37c - 0x375];
	void* ptr37c;
	unsigned int unknown_380_;
	unsigned char pad3[0x438 - 0x384];
	unsigned char unknown_438_;
	unsigned char unknown_439_;
};

// USA: func_ov031_02243c10
extern "C" ARM void func_ov031_02243c10(Struct_ov031_02243c10* obj) {
	switch (obj->unknown_35_) {
	case 0:
		if (!(obj->unknown_374_ & 1) && !(obj->unknown_374_ & 2)) goto skip374;
		if (obj->ptr37c == 0) {
			BackgroundLoader* loader = BackgroundLoader::GetInstance();
			if (loader->GetNumQueuedTasks() > 0) {
				func_ov031_02245528((struct Struct_02245528*)obj, 0);
				return;
			}
			obj->ptr37c = &g_fileLoadBuffer;
			obj->unknown_380_ = 0x30000;
		}
		memset(obj->ptr37c, 0, obj->unknown_380_);
		obj->field48 = obj->ptr37c;
	skip374:
		{
			int v = func_ov031_02212cbc(obj->field4c);
			obj->unknown_439_ = 1;
			if (v == 3) {
				obj->unknown_35_ = 8;
				obj->unknown_438_ = 1;
			} else {
				obj->unknown_35_ = 6;
			}
		}
		break;
	case 6:
		func_ov031_02211b40((void*)func_ov031_022434b4, (void*)func_ov031_022434e8);
		func_ov031_02245528((struct Struct_02245528*)obj, 2);
		break;
	case 7:
		func_ov031_02245528((struct Struct_02245528*)obj, 0);
		break;
	case 8:
		func_ov031_02245528((struct Struct_02245528*)obj, 0);
		break;
	default:
		break;
	}
}
