#include <globaldefs.h>

struct Struct_ov014_021891f0 {
	unsigned short count;
	char pad2[0xa];
	int* arr;
};

typedef int (*Type_ov014_021891f0)(struct Struct_ov014_021891f0*, int*);

// USA: func_ov014_021891f0
extern "C" ARM int func_ov014_021891f0(struct Struct_ov014_021891f0* obj, Type_ov014_021891f0 callback) {
	int count;
	int* arr;
	if (obj->arr == 0 || obj->count == 0 || callback == 0) return 0;
	count = obj->count;
	arr = obj->arr;
	int i = 0;
	while (i < count) {
		callback(obj, arr);
		i++;
		arr++;
	}
	return 1;
}
