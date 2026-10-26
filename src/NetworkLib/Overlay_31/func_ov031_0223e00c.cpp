#include <globaldefs.h>

struct Struct_ov031_02222b0c_5 { unsigned int field0; void* field4; void* field8; unsigned int fieldC; };
struct Struct_ov031_0223e00c { void* slots; void* entries; Struct_ov031_02222b0c_5* node; char unknown_c_[16]; unsigned char unknown_1c_; char unknown_1d_[3]; char unknown_20_[16]; unsigned char unknown_30_; char unknown_31_[3]; unsigned int count; unsigned char active; char pad39[3]; void* storage; };
extern Struct_ov031_0223e00c* data_ov031_02290d9c;
extern unsigned char data_ov031_022493c0[];
extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" void* func_ov031_0223beec(int, int, int);
extern "C" void* func_ov031_0223beb8(int);
extern "C" Struct_ov031_02222b0c_5* func_ov031_0223d858();
extern "C" int func_ov031_0223d918(char*);
extern "C" int func_ov031_0223d908(char*);
typedef int (*Type_ov031_0223e00c)(Struct_ov031_02222b0c_5*, void*);
static inline Struct_ov031_0223e00c* inline_ov031_0223e00c(int offset) {
    return (Struct_ov031_0223e00c*)((char*)data_ov031_02290d9c + offset);
}

// USA: func_ov031_0223e00c
extern "C" ARM void func_ov031_0223e00c() {
    data_ov031_02290d9c = (Struct_ov031_0223e00c*)func_ov031_0223cf4c(128, 4);
    int index = 0;
    unsigned char* count = data_ov031_022493c0;
    int offset = 0;
    do {
        data_ov031_02290d9c[index].count = *count;
        data_ov031_02290d9c[index].storage = func_ov031_0223cf4c(*count * 20, 4);
        data_ov031_02290d9c[index].slots = func_ov031_0223beec(*count, (int)data_ov031_02290d9c[index].storage, 20);
        data_ov031_02290d9c[index].entries = func_ov031_0223beb8(*count);
        count++;
        data_ov031_02290d9c[index].node = func_ov031_0223d858();
        data_ov031_02290d9c[index].unknown_1c_ = 0;
        data_ov031_02290d9c[index].unknown_30_ = 255;
        reinterpret_cast<Type_ov031_0223e00c>(func_ov031_0223d918)(data_ov031_02290d9c[index].node, inline_ov031_0223e00c(offset)->unknown_c_);
        reinterpret_cast<Type_ov031_0223e00c>(func_ov031_0223d908)(data_ov031_02290d9c[index].node, inline_ov031_0223e00c(offset)->unknown_20_);
        data_ov031_02290d9c[index].active = 1;
        index++;
        offset += sizeof(Struct_ov031_0223e00c);
    } while (index < 2);
}
