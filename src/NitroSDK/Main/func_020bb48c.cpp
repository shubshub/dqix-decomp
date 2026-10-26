#include <globaldefs.h>
#if defined(jpn)
#define data_0210cf84 data_0210cc3c
#define data_020f1ee8 data_020f2054
#define data_020f1eec data_020f2058
#endif

extern "C" void func_020bb444(int arg0, int i1, int i2, int arg3, int arg4);
extern "C" void func_020bb514(void);
extern "C" int func_020bb6f8(void);
extern "C" void NNS_GfdAllocFrmTexVram();

extern unsigned short data_0210cf84;
extern void* data_020f1ee8;
extern void* data_020f1eec;

// USA: func_020bb48c
extern "C" ARM void func_020bb48c(unsigned int mode, int arg1) {
    if (mode <= 2) {
        func_020bb444(4, 3, 2, 0, 1);
    } else {
        func_020bb444(4, 3, 0, 2, 1);
    }
    data_0210cf84 = (unsigned short)mode;
    func_020bb514();
    if (arg1 != 0) {
        data_020f1ee8 = (void*)&NNS_GfdAllocFrmTexVram;
        data_020f1eec = (void*)&func_020bb6f8;
    }
}
