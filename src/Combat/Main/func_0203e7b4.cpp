#include <globaldefs.h>
struct Struct_0203e624 { unsigned short* arr; unsigned short capacity, count, size, mask; };
struct Struct_0203e6c8 { unsigned short* arr; unsigned short capacity, count, size, mask; };
struct Struct_0203e63c { unsigned short* arr; unsigned short capacity, count, size, mask; };
extern "C" void func_0203e624(Struct_0203e624*);
extern "C" int func_0203e6c8(Struct_0203e6c8*, unsigned int);
extern "C" unsigned char func_0203e63c(Struct_0203e63c*, unsigned int);
void CleanInvalidateCacheRange(const void*, unsigned int);
// USA: func_0203e7b4
extern "C" ARM int func_0203e7b4(Struct_0203e624* header, unsigned short* list, unsigned char* output, unsigned short* input, int capacity, int width, int height, int stride) {
    func_0203e624(header);
    if (!list || !output || !input) return 0;
    header->arr = list;
    header->capacity = capacity;
    header->mask = 0xfbde;
    header->arr[0] = 0x3e0;
    header->count++;
    header->size = 1;
    unsigned short* row;
    int y;
    int x;
    int remaining;
    remaining = height;
    row = input;
    for (y = remaining; y != 0; ) {
        unsigned short* p = row;
        for (x = width; x != 0; --x) {
            func_0203e6c8((Struct_0203e6c8*)header, *p);
            p++;
        }
        --y;
        row += stride;
    }
    CleanInvalidateCacheRange(header->arr, header->count * 2);
    unsigned char* var5 = output;
    for (; remaining != 0; ) {
        unsigned char* dest = var5;
        unsigned short* p = input;
        for (x = width; x != 0; --x) {
            *dest = func_0203e63c((Struct_0203e63c*)header, *p++);
            dest++;
        }
        --remaining;
        var5 += width;
        input += stride;
    }
    CleanInvalidateCacheRange(output, width * height);
    func_0203e624(header);
    return 1;
}
