#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

#if defined(jpn)
#define data_021142c4 data_02113f64
#endif

struct Struct_020d39dc {
    unsigned char f0 : 3;
    unsigned char f1 : 1;
    unsigned char f2 : 3;
    unsigned char f3 : 1;
};

struct Struct_020d39dc_2 {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int reserved : 2;
};

struct Struct_020d39dc_3 {
#if defined(jpn)
    char name[11];
#else
    char name[16];
#endif
    struct Struct_020d39dc flags;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    struct Struct_020d39dc_2 unknown_14_;
    struct Struct_020d39dc_2 unknown_18_;
    struct Struct_020d39dc_2 unknown_1c_;
    unsigned short unknown_20_;
    unsigned short unknown_22_;
};

struct Struct_020d3cf0;
extern "C" void func_020d3cf0(struct Struct_020d3cf0* container, struct Struct_020d39dc_3* src);
extern struct Struct_020d3cf0* data_021142c4;

// USA: func_020d39dc
extern "C" ARM int func_020d39dc(Script::Parameter* params, int count) {
    struct Struct_020d39dc_3 entry;

    entry.flags.f0 = (params++)->ToInt();
    entry.unknown_11_ = (params++)->ToInt();
    strcpy(entry.name, (params++)->ToString());
    entry.flags.f1 = (params++)->ToInt();
    entry.flags.f2 = (params++)->ToInt();
    entry.unknown_12_ = (params++)->ToInt();
    entry.flags.f3 = (params++)->ToInt();

    entry.unknown_14_.f0 = (params++)->ToInt();
    entry.unknown_14_.f2 = (params++)->ToInt();
    entry.unknown_14_.f1 = (params++)->ToInt();

    entry.unknown_18_.f0 = (params++)->ToInt();
    entry.unknown_18_.f1 = (params++)->ToInt();
    entry.unknown_18_.f2 = (params++)->ToInt();

    entry.unknown_1c_.f0 = (params++)->ToInt();
    entry.unknown_1c_.f1 = (params++)->ToInt();
    entry.unknown_1c_.f2 = (params++)->ToInt();

    entry.unknown_13_ = (params++)->ToInt();
    entry.unknown_20_ = (params++)->ToInt();
    entry.unknown_22_ = (params++)->ToInt();

    func_020d3cf0(data_021142c4, &entry);
    return 1;
}
