#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
};

struct Struct_ov014_02186bc8 {
    char unk_0[0xb8];
    Struct_ov014_02184f78* entries_;
};

// USA: func_ov014_02187340
extern "C" ARM Struct_ov014_02184f78* func_ov014_02187340(Struct_ov014_02186bc8* self, short page)
{
    Struct_ov014_02184f78* entry = self->entries_;
    int index = 0;
    Struct_ov014_02184f78* var2 = entry;
    short var3 = 0;
    for (; entry != NULL; entry = entry->unknown_0_)
    {
        if (index == 0)
        {
            var2 = entry;
            if (var3 == page)
                break;
            var3++;
        }
        index = (short)(index + 1) % 16;
    }
    return var2;
}
