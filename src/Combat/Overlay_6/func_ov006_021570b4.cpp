#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_021570b4_2196 = 0x714 };
#else
enum { Enum_ov006_021570b4_2196 = 0x894 };
#endif

struct Struct_ov006_02156e54 {
    char graphics[0x70];
    int task;
    short item;
    short x;
    short y;
    unsigned char loading;
};

struct Struct_ov006_02154614 {
    char unknown0[Enum_ov006_021570b4_2196];
    Struct_ov006_02156e54 ingredients[4];
};

// USA: func_ov006_021570b4
extern "C" ARM int func_ov006_021570b4(char* storage) {
    Struct_ov006_02154614* var0 = (Struct_ov006_02154614*)storage;
    Struct_ov006_02156e54* ingredient = var0->ingredients;
    int loading = 0;
    for (unsigned char i = 0; i < 4; i++, ingredient++) {
        loading = (loading | ingredient->loading) != 0;
    }
    return loading;
}
