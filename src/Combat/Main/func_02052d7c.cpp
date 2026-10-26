#include <globaldefs.h>


#if defined(jpn)
enum { Enum_02052d7c_336 = 0x144 };
#else
enum { Enum_02052d7c_336 = 0x150 };
#endif

extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void* Scenario_GetInstance(void);

struct Struct_02052d7c {
    unsigned char pad[Enum_02052d7c_336];
    char* f150;
};

// USA: func_02052d7c
extern "C" ARM void func_02052d7c(struct Struct_02052d7c* obj, int index, short value) {
    char* ptr = obj->f150;
    if (ptr == 0) return;
    short old = *(short*)(ptr + index * 2 + 0x400 + 0x88);
    if (value == old) return;

    if (index != 7 && index != 8) {
        void* ctx = Scenario_GetInstance();
        Scenario_SetFlag(ctx, (unsigned char*)ctx + 0x8c, 0x113f, 1);
    }

    ptr = obj->f150;
    *(short*)(ptr + index * 2 + 0x400 + 0x88) = value;
    if (index != 9) return;

    ptr = obj->f150;
    if (ptr != 0) {
        ptr[0x56e] = 1;
    }
}
