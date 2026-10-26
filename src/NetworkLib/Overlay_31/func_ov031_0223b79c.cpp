#include <globaldefs.h>

struct Struct_ov031_0223b79c_2 {
    void* field_0;
    void* unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
};
struct Struct_ov031_0223b79c {
    unsigned char data[0x200];
    Struct_ov031_0223b79c_2 first;
    Struct_ov031_0223b79c_2 second;
    char* node;
    void* array;
};
extern Struct_ov031_0223b79c* data_ov031_02290d28;
extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" void func_ov031_0223beec(int, int, int);
extern "C" char* func_ov031_0223d858(void);
extern "C" void* func_ov031_0223daa4(int, int);
extern "C" int func_ov031_0223d918(char*);
extern "C" int func_ov031_0223d908(char*);
typedef int (*Type_ov031_0223b79c)(char*, void*);
typedef void* (*Type_ov031_0223b79c_2)(int, int, int);
static inline Struct_ov031_0223b79c* inline_ov000_0217fa60_2(int offset) {
    return (Struct_ov031_0223b79c*)((char*)data_ov031_02290d28 + offset);
}

// USA: func_ov031_0223b79c
extern "C" ARM void func_ov031_0223b79c(void) {
    data_ov031_02290d28 = (Struct_ov031_0223b79c*)func_ov031_0223cf4c(0x450, 4);
    int index = 0;
    int offset = 0;
    do {
        void* array = reinterpret_cast<Type_ov031_0223b79c_2>(func_ov031_0223beec)(32, (int)inline_ov000_0217fa60_2(offset)->data, 16);
        inline_ov000_0217fa60_2(offset)->array = array;
        char* node = func_ov031_0223d858();
        inline_ov000_0217fa60_2(offset)->node = node;
        void* first = func_ov031_0223daa4(index, 64);
        inline_ov000_0217fa60_2(offset)->first.unknown_8_ = first;
        char* second = (char*)func_ov031_0223daa4(index, 127) + 8;
        inline_ov000_0217fa60_2(offset)->second.unknown_8_ = second;
        reinterpret_cast<Type_ov031_0223b79c>(func_ov031_0223d918)(inline_ov000_0217fa60_2(offset)->node, &inline_ov000_0217fa60_2(offset)->first);
        reinterpret_cast<Type_ov031_0223b79c>(func_ov031_0223d908)(inline_ov000_0217fa60_2(offset)->node, &inline_ov000_0217fa60_2(offset)->second);
        offset += sizeof(Struct_ov031_0223b79c);
        index++;
    } while (index < 2);
}
