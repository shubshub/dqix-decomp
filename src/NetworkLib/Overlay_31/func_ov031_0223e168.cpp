#include <globaldefs.h>

struct Struct_ov031_0223e168_3 {
	int field0;
	Struct_ov031_0223e168_3* next;
	void (*fn)(Struct_ov031_0223e168_3*, int);
	int arg;
};

struct Struct_ov031_0223e168_2 {
	int field0;
	void* field4;
	char pad0[8];
	Struct_ov031_0223e168_3* head;
	char pad1[0x20 - 0x14];
	Struct_ov031_0223e168_3 unknown_20_;
	char pad2[0x34 - 0x30];
	int count;
	unsigned char unknown_38_;
	char pad3[0x40 - 0x39];
};

extern Struct_ov031_0223e168_2* data_ov031_02290d9c;

struct Struct_ov031_0223e168;
extern "C" int func_ov031_0223bfa0(Struct_ov031_0223e168* p);
extern "C" void func_ov031_0223e2ec(int index, void* obj);

// USA: func_ov031_0223e168
extern "C" ARM void func_ov031_0223e168(int idx) {
	Struct_ov031_0223e168_2* base = data_ov031_02290d9c;
	Struct_ov031_0223e168_2* elem = &base[idx];
	if (elem->unknown_38_ == 0) return;

	Struct_ov031_0223e168_3* node = elem->head;
	Struct_ov031_0223e168_3* var3 = &elem->unknown_20_;
	if (node != var3) {
		do {
			node->fn(node, node->arg);
			base = data_ov031_02290d9c;
			var3 = &base[idx].unknown_20_;
			node = node->next;
		} while (node != var3);
	}

	Struct_ov031_0223e168_2* elem2 = &base[idx];
	int count = elem2->count;
	int var6 = idx << 6;
	int i = 0;
	if (count <= 0) return;

	do {
		Struct_ov031_0223e168_2* cur = (Struct_ov031_0223e168_2*)(var6 + (int)base);
		void* obj = (void*)func_ov031_0223bfa0((Struct_ov031_0223e168*)cur->field4);
		if (obj == 0) return;
		func_ov031_0223e2ec(idx, obj);
		base = data_ov031_02290d9c;
		cur = (Struct_ov031_0223e168_2*)(var6 + (int)base);
		count = cur->count;
		i++;
	} while (i < count);
}
