#include <globaldefs.h>

union Value_02163f60 { int i; float f; };
struct TaggedValue_02163f60 { int type; Value_02163f60 value; };

extern "C" int func_ov017_021d60f4(TaggedValue_02163f60* a);
extern "C" float func_ov017_021d6110(TaggedValue_02163f60* a);
extern "C" void* Zone3D_GetInstance(void);
struct Entry02019508;
struct Base02019508;
ARM struct Entry02019508* FindEntryByKeys02019508(struct Base02019508* base, int key1, int key2);

// USA: func_ov001_02163f60  (semantic: SetScaledVec3FieldsAlt_02163f60)
extern "C" ARM int func_ov001_02163f60(TaggedValue_02163f60* obj) {
	int key1 = func_ov017_021d60f4(obj);
	int key2 = func_ov017_021d60f4((TaggedValue_02163f60*)((char*)obj + 0x8));
	void* g = Zone3D_GetInstance();
	if (!g) {
		return 0;
	}
	struct Entry02019508* e = FindEntryByKeys02019508((struct Base02019508*)g, key1, key2);
	if (!e) {
		return 0;
	}
	float x = func_ov017_021d6110((TaggedValue_02163f60*)((char*)obj + 0x10));
	*(int*)((char*)e + 0x14) = (int)(4096.0f * x);
	float y = func_ov017_021d6110((TaggedValue_02163f60*)((char*)obj + 0x18));
	*(int*)((char*)e + 0x18) = (int)(4096.0f * y);
	float z = func_ov017_021d6110((TaggedValue_02163f60*)((char*)obj + 0x20));
	*(int*)((char*)e + 0x1c) = (int)(4096.0f * z);
	return 1;
}
