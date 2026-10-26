#include <globaldefs.h>

struct BlockedContextList;
void UnblockContexts(struct BlockedContextList*);

extern "C" ARM void func_ov031_02206b68(void*);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_ov031_0224e22c;
struct Struct_ov031_0224e230;
extern "C" ARM void* func_ov031_02207108(Struct_ov031_0224e22c* item);
extern "C" ARM void* func_ov031_02207168(Struct_ov031_0224e230* item);

struct Struct_ov031_02206a68 { Struct_ov031_02206a68* next; };
struct Struct_ov031_02206a68_2 { char pad[0x1c]; void (*field1c)(Struct_ov031_02206a68*); };
extern Struct_ov031_02206a68_2* data_ov031_022496a4;

struct Struct_ov031_02206a68_3 {
	char pad[0x100];
	int unknown_100_;
	Struct_ov031_02206a68* unknown_104_;
	unsigned short field108;
};

struct Struct_ov031_02206a68_4 {
	char pad[0x64];
	Struct_ov031_02206a68_3* unknown_64_;
	void* field68;
	char pad2[4];
	unsigned short unknown_70_;
	char pad3;
	signed char unknown_73_;
};

// USA: func_ov031_02206a68
extern "C" ARM void func_ov031_02206a68(Struct_ov031_02206a68_4* a) {
	if (a == NULL) return;
	a->unknown_70_ = 0;
	int var0 = 1;
	signed char kind = a->unknown_73_;
	if (kind != 0 && kind != 4) var0 = 0;
	if (var0) {
		func_ov031_02206b68(a->field68);
		func_ov031_02206b68(a->unknown_64_);
	} else if (kind == 1) {
		if (a->unknown_64_->unknown_104_ != NULL) {
			Struct_ov031_02206a68* node = a->unknown_64_->unknown_104_;
			do {
				Struct_ov031_02206a68* next = node->next;
				data_ov031_022496a4->field1c(node);
				node = next;
			} while (node != NULL);
		}
		a->unknown_64_->field108 = 0;
		a->unknown_64_->unknown_100_ = 0;
		a->unknown_64_->unknown_104_ = NULL;
		UnblockContexts((struct BlockedContextList*)((char*)a->unknown_64_ + 0x10c));
		func_ov031_02206b68(a->unknown_64_);
	} else if (kind == 2) {
		func_ov031_02206b68(a->field68);
	}

	unsigned int prev = DisableIRQInterrupts();
	func_ov031_02207108((Struct_ov031_0224e22c*)a);
	func_ov031_02207168((Struct_ov031_0224e230*)a);
	data_ov031_022496a4->field1c((Struct_ov031_02206a68*)a);
	SetIRQInterruptState(prev);
}
