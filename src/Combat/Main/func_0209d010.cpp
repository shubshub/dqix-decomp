#include <globaldefs.h>

struct Struct_0209cf44 {
    int type;
    union {
        int unknown2_0_;
        float unknown_0_;
        Struct_0209cf44* unknown1_0_;
    } value;
};

extern "C" void* func_0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209ebe4(void*, int, int);

// USA: func_0209d010
extern "C" ARM int func_0209d010(void* arg0) {
    void* manager = func_0209dccc();
    if (manager == NULL) return 0;
    Struct_0209cf44* arguments = (Struct_0209cf44*)arg0;
    int var2 = func_ov017_021d60f4(&arguments[0]);
    int var3 = func_ov017_021d60f4(&arguments[1]);
    func_0209ebe4(manager, var2, var3);
    return 1;
}
