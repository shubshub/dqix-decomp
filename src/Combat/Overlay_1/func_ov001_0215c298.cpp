#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov001_0215ab20(int);
extern "C" void func_ov001_0215a550(int a, char* name, int b, int c);

// USA: func_ov001_0215c298
extern "C" ARM int func_ov001_0215c298(char* self, int mode) {
    int c = 0x1000;
    int b;
    int id = func_ov017_021d60f4(self);
    char* var3 = self + 0x8;
    self += 0x10;
    char* name = (char*)func_ov017_021d612c(var3);
    b = 0;
    if (mode >= 3) {
        b = func_ov017_021d60f4(self);
        self += 0x8;
    }
    if (mode >= 4) {
        c = (int)(4096.0f * func_ov017_021d6110(self));
    }
    void* ctx = func_ov001_0215ab20(id);
    if (ctx == NULL) return 0;
    func_ov001_0215a550((int)ctx, name, b, c);
    return 1;
}
