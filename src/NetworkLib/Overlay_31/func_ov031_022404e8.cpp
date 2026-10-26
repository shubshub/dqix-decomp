#include <globaldefs.h>

struct Struct_ov031_02240410 { void* next; };
extern "C" void func_ov031_02240410(void* obj, int idx, Struct_ov031_02240410** arg2, int* arg3);
extern "C" signed char func_ov031_0224046c(void* obj, void** arg1, int* counter);

// USA: func_ov031_022404e8
extern "C" ARM int func_ov031_022404e8(void* obj, int start, int end, int* outPtr) {
	int var0 = 0;
	if (outPtr) {
		*outPtr = -1;
	}
	if (start >= end) {
		goto fail;
	}
	Struct_ov031_02240410* node;
	int rem;
	func_ov031_02240410(obj, start, &node, &rem);
	if (start >= end) {
		goto fail;
	}
	int i = start;
	do {
		signed char c = func_ov031_0224046c(obj, (void**)&node, &rem);
		if (c == ':' && outPtr && *outPtr < 0) {
			*outPtr = i;
		}
		if (!var0) {
			if (c == '\r') {
				var0 = 1;
			}
		} else {
			if (c == '\n') {
				return (i == end - 1) ? 0 : i + 1;
			}
			var0 = 0;
		}
		i++;
	} while (i < end);
fail:
	return -1;
}
