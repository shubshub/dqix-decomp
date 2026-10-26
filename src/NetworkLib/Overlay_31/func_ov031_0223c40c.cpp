#include <globaldefs.h>

struct Struct_ov031_0223c40c {
    char padding[0x670];
    int allocator;
    int unknown_674_[2];
};
struct Struct_ov031_0223bf2c;
extern Struct_ov031_0223c40c* data_ov031_02290d38;
extern Struct_ov031_0223c40c* data_ov031_02290d38_dup;
extern "C" void func_ov031_0223b710(int);
extern "C" void func_ov031_0223cf70(void*);
extern "C" void func_ov031_0223bf2c(Struct_ov031_0223bf2c);
typedef void (*Type_ov031_0223c40c)(int);

// USA: func_ov031_0223c40c
extern "C" ARM void func_ov031_0223c40c() {
    int i = 0;
    do {
        func_ov031_0223b710(data_ov031_02290d38->unknown_674_[i]);
        i++;
    } while (i < 2);
    ((Type_ov031_0223c40c)func_ov031_0223bf2c)(data_ov031_02290d38->allocator);
    func_ov031_0223cf70(&data_ov031_02290d38_dup);
}
