#include <globaldefs.h>

struct Struct_02084e78 {
    unsigned int charm : 10;
    unsigned int magicalMight : 10;
    unsigned int magicalMending : 10;
};

// USA: func_02084ee8
extern "C" ARM float func_02084ee8(void* param0) {
    float sum = 0.0f;
    int i = 0;
    while (i < 0xb) {
        char* rec = (char*)param0 + (i << 5);
        if (*(short*)(rec + 0x1ac) > 0) {
            char* base = *(char**)(rec + 0x194);
            struct Struct_02084e78* ptr = (struct Struct_02084e78*)(base + 0xc);
            unsigned int var5 = ptr->charm;
            sum = sum + ((float)var5 / 10.0f);
        }
        i++;
    }
    return sum;
}
