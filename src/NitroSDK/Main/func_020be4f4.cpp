#include <globaldefs.h>

struct Struct_020be4f4;
extern "C" void func_020d2eb8(struct Struct_020be4f4*, int, int);
extern "C" void* func_020d2eec(void*, int);
extern "C" void func_020d20c4(int, int);

// USA: func_020be4f4
extern "C" ARM void func_020be4f4(int start, int length, void* base, int index) {
    if (start == (int)func_020d2eec(base, index)) {
        func_020d2eb8((struct Struct_020be4f4*)base, index, 0);
    }
    func_020d20c4(start, start + length);
}
