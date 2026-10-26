#include <globaldefs.h>

struct Struct_020be53c;
extern "C" int func_020d2eb0(struct Struct_020be53c* p);
extern "C" void* func_020d2eec(void* base, int index);
struct Obj020bda58;
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bda58(struct Obj020bda58* obj, unsigned int size, Type_020bbf84 callback, int a3, int a4);
extern "C" int func_020bd7c4(int index, void* buffer, int size, int offset);
void CleanCacheRange(const void* addr, unsigned int size);
struct Struct_020be4f4;
extern "C" void func_020d2eb8(struct Struct_020be4f4* obj, int index, int value);
extern "C" void func_020be4f4(int start, int length, void* base, int index);

// USA: func_020be53c
extern "C" ARM int func_020be53c(void* obj, int index, int arg2, struct Obj020bda58* arg3) {
    int size;
    if ((int)func_020d2eec(obj, index) != 0) return 1;
    int capacity = func_020d2eb0((struct Struct_020be53c*)obj);
    int idx = *(int*)((char*)obj + 0x38) + index;
    int* entry = (int*)obj + idx;
    int end;
    int start = entry[15];
    if ((unsigned int)index < (unsigned int)(capacity - 1)) end = entry[16];
    else end = ((int*)obj)[2];
    size = end - start;
    if (arg3 == 0) return 0;
    void* allocated = func_020bda58(arg3, size + 0x20, (Type_020bbf84)&func_020be4f4, (int)obj, index);
    if (allocated == 0) return 0;
    int var7 = func_020bd7c4(arg2, allocated, size, start);
    if (size != var7) return 0;
    CleanCacheRange(allocated, size);
    func_020d2eb8((struct Struct_020be4f4*)obj, index, (int)allocated);
    return 1;
}
