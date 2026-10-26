#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79de
#define REGION_OFFSET_1 0x79c6
#else
#define REGION_OFFSET_0 0x77ee
#define REGION_OFFSET_1 0x77d6
#endif


struct Struct_ov000_02168230 { signed char a; unsigned char b; short c; short d; };
extern "C" void func_ov000_02168268(struct Struct_ov000_02168230* obj);

// USA: func_ov000_02168230
extern "C" ARM void func_ov000_02168230(char* p) {
    int i;
    p[REGION_OFFSET_0] = 0;
    for (i = 0; i < 4; i++) {
        func_ov000_02168268((struct Struct_ov000_02168230*)(p + REGION_OFFSET_1 + i * 6));
    }
}
