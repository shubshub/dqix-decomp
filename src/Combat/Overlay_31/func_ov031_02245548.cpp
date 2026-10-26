#include <globaldefs.h>

struct Struct_ov031_02245548 {
	char pad[0x34];
	unsigned char unknown_34_;
	unsigned char unknown_35_;
	char pad2[0x374 - 0x35 - 1];
	unsigned char unknown_374_;
	char pad3[0x384 - 0x374 - 1];
	int unknown_384_;
};

// USA: func_ov031_02245548
extern "C" ARM void func_ov031_02245548(Struct_ov031_02245548* p) {
	if (p->unknown_374_ & 1) {
		switch (p->unknown_34_) {
		case 2:
			if (p->unknown_384_ < 0x3c000) p->unknown_384_ = p->unknown_384_ + 0x28;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x3c000;
			break;
		case 3:
			if (p->unknown_384_ < 0x46000) p->unknown_384_ = p->unknown_384_ + 0x51;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x46000;
			break;
		case 4:
			if (p->unknown_384_ < 0x77f33) p->unknown_384_ = p->unknown_384_ + 0xcc;
			if (p->unknown_35_ == 5) p->unknown_384_ = 0x78000;
			break;
		}
	} else if (p->unknown_374_ & 4) {
		switch (p->unknown_34_) {
		case 2:
			if (p->unknown_384_ < 0x64000) p->unknown_384_ = p->unknown_384_ + 0x51;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x64000;
			break;
		case 3:
			if (p->unknown_384_ < 0x77f85) p->unknown_384_ = p->unknown_384_ + 0x7a;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x78000;
			break;
		}
	} else if (p->unknown_374_ & 2) {
		switch (p->unknown_34_) {
		case 2:
			if (p->unknown_384_ < 0x3c000) p->unknown_384_ = p->unknown_384_ + 0x28;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x3c000;
			break;
		case 3:
			if (p->unknown_384_ < 0x46000) p->unknown_384_ = p->unknown_384_ + 0x51;
			if (p->unknown_35_ == 6) p->unknown_384_ = 0x46000;
			break;
		case 5:
			if (p->unknown_384_ < 0x77f33) p->unknown_384_ = p->unknown_384_ + 0xcc;
			if (p->unknown_35_ == 5) p->unknown_384_ = 0x78000;
			break;
		}
	}
}
