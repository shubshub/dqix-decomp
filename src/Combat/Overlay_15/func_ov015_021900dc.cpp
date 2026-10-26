#include <globaldefs.h>

struct IndexNode_0202a9ac;
struct IndexList_0202a9ac;
extern "C" struct IndexNode_0202a9ac* DebugMenu_GetItem(struct IndexList_0202a9ac* list, int index);
extern "C" void* func_02029560(void* base);
extern "C" void* func_ov015_0218f39c(void* obj, void* param2);

struct Struct_ov015_021900dc {
	void* ptr0;
	char unknown_4_[0x38 - 0x4];
	short field38;
	char unknown_3a_[0x4c - 0x3a];
	int field4c;
};

// USA: func_ov015_021900dc
extern "C" ARM void func_ov015_021900dc(struct Struct_ov015_021900dc* obj) {
	struct IndexList_0202a9ac* list = (struct IndexList_0202a9ac*)((char*)obj->ptr0 + 0x2c4);
	struct IndexNode_0202a9ac* node = DebugMenu_GetItem(list, obj->field38);
	void* sub;
	void* result;
	if (node == 0) {
		return;
	}
	sub = func_02029560(node);
	result = func_ov015_0218f39c(obj, sub);
	if (result != 0) {
		obj->field4c = *(int*)((char*)result + 0x18);
	}
}
