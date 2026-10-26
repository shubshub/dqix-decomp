#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02160794_1136 = 0x298 };
enum { Enum_ov003_02160794_804 = 0x20c };
#else
enum { Enum_ov003_02160794_1136 = 0x470 };
enum { Enum_ov003_02160794_804 = 0x324 };
#endif

extern short data_ov003_0217f420[3];

extern "C" void func_02080828(void* obj, int id, short* outX, short* outY);
extern "C" void func_02080854(void* obj, int id, int x, int y);

struct Struct_020809a0;
extern "C" ARM void func_020809a0(struct Struct_020809a0* obj, int id, short x, short y);

// USA: func_ov003_02160794
extern "C" ARM void func_ov003_02160794(void* self) {
    short* base = *(short**)((char*)self + Enum_ov003_02160794_1136);
    if (base == 0) {
        return;
    }
    void* list = *(void**)((char*)self + Enum_ov003_02160794_804);
    for (int i = 0; i < 3; i++) {
        short* basePtr = *(short**)((char*)self + Enum_ov003_02160794_1136);
        short id = data_ov003_0217f420[i];
        short var5 = *basePtr;
        if (id > var5) {
            continue;
        }
        if (var5 >= id + 4) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            short x, y;
            func_02080828(list, id, &x, &y);
            func_02080854(list, id, x, y);
            func_020809a0((struct Struct_020809a0*)list, id, 0xd0, 0xa);
            id = (short)(id + 1);
        }
    }
}
