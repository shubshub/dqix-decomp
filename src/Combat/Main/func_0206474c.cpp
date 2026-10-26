#include <globaldefs.h>

struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
extern "C" int func_0206e31c(int, int);
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_0206e260(PackedNibbleArray0206e260*, int);

// USA: func_0206474c
extern "C" ARM int func_0206474c(PackedNibbleArray0206e120* data, int index, int mode) {
    if (!func_0206e31c((int)data, index)) return 0;
    switch (mode) {
    case -1: return func_0206e120(data, index) == 0;
    case 0: return func_0206e120(data, index) == 2;
    case 1: return func_0206e260((PackedNibbleArray0206e260*)data, index);
    case 2: return func_0206e120(data, index) == 3;
    case 3: return func_0206e120(data, index) == 1;
    case 5: return func_0206e120(data, index) == 0;
    default: return 0;
    }
}
