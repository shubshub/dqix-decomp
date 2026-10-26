#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02027288_1880 = 0x6ac };
#else
enum { Enum_02027288_1880 = 0x758 };
#endif

struct Stopwatch0201fbac;
extern "C" void func_0201fbac(struct Stopwatch0201fbac* t);

struct Struct_020fdc60_5 { char raw[0x14]; };
extern struct Struct_020fdc60_5 data_020fdc60[4];

// USA: func_02027288
extern "C" ARM void func_02027288(unsigned char* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            func_0201fbac((struct Stopwatch0201fbac*)&data_020fdc60[i]);
        }
        return;
    }
    if (id >= 4) return;
    {
        int i;
        unsigned char* p;
        for (i = 0; i < 4; i++) {
            p = obj + i;
            if (id == p[Enum_02027288_1880]) {
                func_0201fbac((struct Stopwatch0201fbac*)&data_020fdc60[i]);
                return;
            }
        }
    }
}
