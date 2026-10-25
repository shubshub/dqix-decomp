#include <globaldefs.h>
#include <std_library_functions.h>


extern "C" char *Scenario_GetInstance(void);
extern "C" int func_ov002_02161920(void *self);
int Scenario_TestFlag(int, unsigned char*, int);

struct Struct_ov002_0216c9ae {
    short unknown_0_[9];
};
extern "C" const struct Struct_ov002_0216c9ae data_ov002_0216c9ae;

// USA: func_ov002_02156080
extern "C" ARM void func_ov002_02156080(void *self, short *out, short *outCount) {
    char *save               = Scenario_GetInstance();
    int mode                 = func_ov002_02161920(self);
    struct List02156080 list = data_ov002_0216c9ae;
    short n                  = 0;
    for (short i = 0; i < 9; i++) {
        int ok = 1;
        switch (i) {
            case 2: ok = Scenario_TestFlag((int)save, (unsigned char*)(save + 0x8c), 0x119c) != 0 ? 1 : 0; break;
            case 6: ok = 0; break;
            case 8:
                if (var1 != 2) var5 = 0;
                break;
        }
        if (var5) {
            var2.unknown_0_[var3] = var4;
            var3++;
        }
    }
    memcpy(arg1, &var2, 0x12);
    *arg2 = var3;
}
