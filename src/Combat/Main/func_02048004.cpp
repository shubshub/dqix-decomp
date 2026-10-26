#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// USA: func_02048004
extern "C" ARM void func_02048004(Foo02048004* src, Foo02048004* dst)
{
    dst->unknown_6_ = src->unknown_6_;
    dst->w8 = src->w8;
    dst->unknown_c_ = src->unknown_c_;
    dst->unknown_10_ = src->unknown_10_;
    dst->nameTable.count = src->nameTable.count;
    dst->nameTable.entries = src->nameTable.entries;
    dst->f4 = src->f4;
    dst->unknown_84_1_ = src->unknown_84_1_;
    dst->bit0 = src->bit0;
}
