#include <globaldefs.h>
#include <NitroSDK/Memory.h>
#include <NitroSDK/ProcessorContext.h>

struct Struct_ov031_02205d10 {
    unsigned char padding[0xf8];
    int unknown_f8_;
    unsigned short capacity;
};
struct Struct_ov031_02205d10_2 {
    unsigned char padding[8];
    unsigned char kind;
    unsigned char unknown_9_[0x64 - 9];
    Struct_ov031_02205d10* buffer;
    unsigned char unknown_68_[8];
    short flags;
    signed char unknown_72_;
    signed char state;
};
struct Struct_ov031_02205d10_3 {
    unsigned int field0;
    Struct_ov031_02205d10_2* object;
    unsigned char padding[8];
    void* output;
    unsigned int length;
    unsigned short* unknown_18_;
    unsigned int* unknown_1c_;
};
extern "C" const void* func_ov031_0220357c(unsigned int*);
extern "C" void func_ov031_02203670(unsigned int);
extern "C" int func_ov031_02205b48(Struct_ov031_02205d10_2*, void*, unsigned int, unsigned short*, unsigned int*);
extern "C" void func_ov031_02205ebc(Struct_ov031_02205d10_2*);

// USA: func_ov031_02205d10
extern "C" ARM int func_ov031_02205d10(Struct_ov031_02205d10_3* request) {
    Struct_ov031_02205d10_2* object = request->object;
    Struct_ov031_02205d10* buffer = object->buffer;
    unsigned int var2 = buffer->unknown_f8_;
    unsigned int length = request->length;
    void* output = request->output;
    unsigned short* var5 = request->unknown_18_;
    unsigned int* var6 = request->unknown_1c_;
    unsigned int available;
    const void* data;
    for (;;) {
        data = func_ov031_0220357c(&available);
        if (!data || (int)(available - var2) > 0) break;
        int closed = 1;
        if (object->state != 0 && object->state != 4) closed = 0;
        if (closed && object->kind != 4) {
            data = 0;
            break;
        }
        SleepCurrentContext(10);
    }
    if (object->flags & 128) return -15;
    if (object->state == 4) {
        if (!data) return 0;
        if (length > available) length = available;
        VectorizedInvertedMemcpy(data, output, length);
        func_ov031_02203670(length);
        return length;
    }
    int result;
    if (data) result = func_ov031_02205b48(object, output, length, var5, var6);
    else result = 0;
    if (result <= 0) return result;
    if (buffer->unknown_f8_ >= buffer->capacity) func_ov031_02205ebc(object);
    return result;
}
