#include <globaldefs.h>

typedef void* (*Type_ov031_02212c3c)(int, int);
extern Type_ov031_02212c3c data_ov031_02290dac;
extern void (*data_ov031_02290dc0)(void*);
extern int data_ov031_02290dbc;
extern int data_ov031_02249424;
extern int data_ov031_0224c748;
extern int data_ov031_0224c750;

extern "C" {
	int func_ov031_0223fb98(void* buf, int val);
	int func_ov031_0223e454(void* dst, void* src, int n);
	int func_ov031_02240074(void* obj, void* entry, int val);
	int func_ov031_0223ede0(void** p0, void** p1, void* p2, void* p3, int p4, const char* p5);
	int func_ov031_0223f188(void* p0, void* p1);
}
struct Struct_ov031_0223edb4;
extern "C" ARM void func_ov031_0223edb4(void* p0, struct Struct_ov031_0223edb4* p1);
extern "C" ARM int func_ov031_0223e438(int x);

struct Struct_ov031_0223f264 {
	unsigned char pad0[4];
	int field4;
	unsigned char pad1[8];
	void* field10;
	int field14;
	void* field18;
	void* field1c;
	void* field20;
};

// USA: func_ov031_0223f264
extern "C" ARM void* func_ov031_0223f264(void* arg0, int val1, int val2) {
	unsigned char scratch[0xc];

	int sz = val2 << 8;
	if (sz < 0x80) {
		sz = 0x80;
	}
	void* var2 = data_ov031_02290dac(sz, 4);
	if (!var2) {
		data_ov031_02290dbc = 1;
		return 0;
	}

	int len1 = func_ov031_0223fb98(scratch, val1);
	void* buf1 = data_ov031_02290dac(func_ov031_0223e438(len1) + 1, 4);
	if (!buf1) {
		data_ov031_02290dc0(var2);
		data_ov031_02290dbc = 1;
		return 0;
	}
	int n1 = func_ov031_0223e454(buf1, scratch, len1);
	((unsigned char*)buf1)[n1] = 0;

	int len2 = func_ov031_0223fb98(scratch, val2);
	void* buf2 = data_ov031_02290dac(func_ov031_0223e438(len2) + 1, 4);
	if (!buf2) {
		data_ov031_02290dc0(buf1);
		data_ov031_02290dc0(var2);
		data_ov031_02290dbc = 1;
		return 0;
	}
	int n2 = func_ov031_0223e454(buf2, scratch, len2);
	((unsigned char*)buf2)[n2] = 0;

	struct Struct_ov031_0223f264* node;
	void* obj;
	if (!func_ov031_0223ede0((void**)&node, &obj, &data_ov031_02249424, var2, sz, 0)) {
		data_ov031_02290dc0(buf2);
		data_ov031_02290dc0(buf1);
		data_ov031_02290dc0(var2);
		return 0;
	}

	if (!func_ov031_02240074(obj, &data_ov031_0224c748, (int)buf1)) {
		goto fail;
	}
	if (!func_ov031_02240074(obj, &data_ov031_0224c750, (int)buf2)) {
		goto fail;
	}
	node->field4 = 2;
	node->field10 = arg0;
	node->field1c = buf1;
	node->field20 = buf2;
	node->field14 = val2;
	node->field18 = var2;
	if (func_ov031_0223f188(node, obj)) {
		return (void*)1;
	}
	data_ov031_02290dc0(buf2);
	data_ov031_02290dc0(buf1);
	data_ov031_02290dc0(var2);
	return 0;

fail:
	data_ov031_02290dc0(buf2);
	data_ov031_02290dc0(buf1);
	data_ov031_02290dc0(var2);
	func_ov031_0223edb4(node, (struct Struct_ov031_0223edb4*)obj);
	data_ov031_02290dbc = 1;
	return 0;
}
