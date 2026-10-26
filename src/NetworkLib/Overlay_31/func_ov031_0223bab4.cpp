#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);
struct Struct_ov031_02238370;
extern "C" unsigned char func_ov031_0223baac(Struct_ov031_02238370*);
extern "C" ARM void func_ov031_0223bab4(void* obj, int index, int val, int zero);

// USA: func_ov031_02238370
extern "C" ARM void func_ov031_02238370(Struct_ov031_02222f44_2* obj, int threshold) {
    int count = func_ov031_0223baac((Struct_ov031_02238370*)obj);
    int i = 0;
    if (count <= 0)
        return;
    int var2 = i;
    int var3 = 0x200;
    do {
        unsigned int hi, lo;
        func_ov031_0223bd28(obj, i, &hi, &lo);
        int val;
        if ((int)lo < threshold)
            goto setFull;
        if ((int)lo < 0xc0) {
            val = var2;
            goto haveVal;
        }
    setFull:
        val = var3;
    haveVal:
        func_ov031_0223bab4(obj, i, val, 0);
        i++;
    } while (i < count);
}
