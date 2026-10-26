#include <globaldefs.h>

struct IndexNode_0202a9ac;
struct IndexList_0202a9ac;
extern "C" struct IndexNode_0202a9ac* DebugMenu_GetItem(struct IndexList_0202a9ac* list, int index);
extern "C" void* func_02029560(void* base);
extern "C" void* func_ov015_0218f39c(void* obj, void* param2);

struct Struct_ov015_0219011c {
	void* ptr0;
	char unknown_4_[0x38 - 0x4];
	short field38;
};

// USA: func_ov015_0219011c
extern "C" ARM void func_ov015_0219011c(struct Struct_ov015_0219011c* obj, int val) {
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
		*(int*)((char*)result + 0x18) = val;
	}
}
