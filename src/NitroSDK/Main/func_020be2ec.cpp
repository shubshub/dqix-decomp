#include <globaldefs.h>

#include "NitroSDK/Memory.h"

extern "C" int func_020bd8ac(unsigned int index);
extern "C" void func_020bd8d4(unsigned int index, int value);
extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);
extern "C" void* func_020bd444(void);
void CleanCacheRange(const void* addr, unsigned int size);

struct Obj020bda58;
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bda58(struct Obj020bda58* obj, unsigned int size, Type_020bbf84 callback, int a3, int a4);
extern "C" void func_020be4d4(int a0, int a1, int a2, int a3);

struct Struct_02110374 {
    char unknown_0_[0x38];
    unsigned int field38;
};
extern struct Struct_02110374 data_02110374;

// USA: func_020be2ec
extern "C" ARM void* func_020be2ec(unsigned int index, struct Obj020bda58* obj, int flag) {
    unsigned int var0;
    void* entry = (void*)func_020bd8ac(index);
    if (entry != NULL) {
        goto done;
    }
    if (func_020bd7c4(index, &data_02110374, 0x3c, 0) != 0x3c) {
        return NULL;
    }
#if defined(jpn)
    struct Struct_02110374* hdr = (struct Struct_02110374*)0x02110014;
#else
    struct Struct_02110374* hdr = (struct Struct_02110374*)0x02110374;
#endif
    unsigned int var3 = hdr->field38;
    unsigned int var4 = var3 * 4;
    var0 = var4 * 2;
    if (obj == NULL) {
        return NULL;
    }
    void* ctx = flag ? func_020bd444() : NULL;
    entry = func_020bda58(obj, var0 + 0x5c, (Type_020bbf84)&func_020be4d4, (int)ctx, index);
    if (entry == NULL) {
        return NULL;
    }
    int var6 = func_020bd7c4(index, entry, var4 + 0x3c, 0);
    if (var6 != (int)var4 + 0x3c) {
        return NULL;
    }
    unsigned int count = *(unsigned int*)((char*)entry + 0x38);
    VectorizedInvertedMemcpy((char*)entry + 0x3c, (char*)entry + 0x3c + count * 4, var4);
    VectorizedMemset((char*)entry + 0x3c, 0, var4);
    CleanCacheRange(entry, var0 + 0x3c);
    if (flag) {
        func_020bd8d4(index, (int)entry);
    }
done:
    return entry;
}
