#include <globaldefs.h>

struct Struct_ov031_0221c4bc {
    unsigned int field_0;
    unsigned short length;
    unsigned char text[256];
    short unknown_106_;
    short unknown_108_;
    short unknown_10a_;
    short unknown_10c_;
    short unknown_10e_;
    unsigned char padding[6];
    unsigned char status;
};
struct Struct_ov031_0224e6e0_2 {
    unsigned char padding[0x14];
    void* buffer;
};
typedef void (*Type_ov031_0221c49c)(int);
typedef void (*Type_ov031_0221c49c_2)(int);
extern Type_ov031_0221c49c data_ov031_0224f4c0;
extern Type_ov031_0221c49c_2 data_ov031_0224f4cc;
extern Struct_ov031_0224e6e0_2 data_ov031_0224e6e0;
extern int data_ov031_0224b070;
extern "C" void func_ov031_0221c49c(int);
extern "C" void func_ov031_0221c4ac(int);
extern "C" int func_ov031_0221d384(int);
extern "C" int func_ov031_0221c5ac(Struct_ov031_0221c4bc*);
extern "C" void func_ov031_0221cfdc(void);
extern "C" int func_ov031_0221e5c8(void*);

static inline void* inline_ov031_0221c4bc(int size) {
    typedef void* (*Type_ov031_0221c49c_3)(int);
    Type_ov031_0221c49c_3 allocator = (Type_ov031_0221c49c_3)func_ov031_0221c49c;
    return allocator(size);
}

// USA: func_ov031_0221c4bc
extern "C" THUMB int func_ov031_0221c4bc(Struct_ov031_0221c4bc* request) {
    int var0;
    if (request->unknown_106_ == 0 || request->unknown_106_ < -1 ||
        request->unknown_108_ < -1 || request->unknown_10a_ == 0 ||
        request->unknown_10a_ < -1 || request->unknown_10c_ < -1 ||
        request->unknown_10e_ < -1 || request->length == 0 ||
        request->length > 256 || request->text[request->length - 1] != 0)
        var0 = -1;
    else
        var0 = 0;
    if (data_ov031_0224f4c0 == 0 || data_ov031_0224f4cc == 0)
        var0 = -1;
    if (var0 == -1) {
        request->status = 15;
        func_ov031_0221cfdc();
        return -1;
    }
    data_ov031_0224e6e0.buffer = inline_ov031_0221c4bc(0x5f8);
    if (data_ov031_0224e6e0.buffer == 0) {
        request->status = 15;
        func_ov031_0221cfdc();
        return -1;
    }
    func_ov031_0221d384(-1);
    int result = func_ov031_0221c5ac(request);
    func_ov031_0221c4ac((int)data_ov031_0224e6e0.buffer);
    func_ov031_0221cfdc();
    if (data_ov031_0224b070 != -1)
        func_ov031_0221e5c8((void*)data_ov031_0224b070);
    return result;
}
