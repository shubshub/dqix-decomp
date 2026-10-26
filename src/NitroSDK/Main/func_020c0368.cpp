#include <globaldefs.h>

extern "C" void VectorizedInvertedMemcpy(void* src, void* dest, unsigned int len);
extern "C" void func_020c04e8(void* obj);

// USA: func_020c0368
extern "C" ARM void func_020c0368(void* obj, void* src, unsigned int size) {
    unsigned int offset = *(unsigned int*)((char*)obj + 0x10) & 0x3f;
    *(unsigned long long*)((char*)obj + 0x10) += size;
    unsigned int var1 = 0x40 - offset;
    if (var1 > size) {
        if (size == 0) return;
        VectorizedInvertedMemcpy(src, (char*)obj + 0x18 + offset, size);
        return;
    }
    VectorizedInvertedMemcpy(src, (char*)obj + 0x18 + offset, var1);
    func_020c04e8(obj);
    size -= var1;
    int blocks = size >> 6;
    char* var3 = (char*)src + var1;
    if (blocks > 0) {
        do {
            VectorizedInvertedMemcpy(var3, (char*)obj + 0x18, 0x40);
            var3 += 0x40;
            func_020c04e8(obj);
            blocks--;
        } while (blocks > 0);
    }
    unsigned int tail = size & 0x3f;
    if (tail == 0) return;
    VectorizedInvertedMemcpy(var3, (char*)obj + 0x18, tail);
}
