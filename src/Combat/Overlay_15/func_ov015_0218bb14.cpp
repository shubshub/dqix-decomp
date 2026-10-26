#include <globaldefs.h>

struct Struct_ov015_0218bb14 { int a; int b; };
struct Struct_ov015_0218bb14_2 { void* f0; Struct_ov015_0218bb14* arr; void* f8; int count; };

// USA: func_ov015_0218bb14
extern "C" ARM struct Struct_ov015_0218bb14* func_ov015_0218bb14(struct Struct_ov015_0218bb14_2* obj, int idx) {
	if (idx < 0) goto fail;
	if (obj->count > idx) goto success;
fail:
	return NULL;
success:
	return &obj->arr[idx];
}
