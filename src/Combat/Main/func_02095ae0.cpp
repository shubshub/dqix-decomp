#include <globaldefs.h>

struct PackedNibbleArray0206e120;
extern "C" int func_0206e120(struct PackedNibbleArray0206e120* obj, int index);

// USA: func_02095ae0
extern "C" ARM int func_02095ae0(struct PackedNibbleArray0206e120* obj, int index) {
    int result = 1;
    int b = (func_0206e120(obj, index) == 0);
    if (!b) {
        b = (func_0206e120(obj, index) == 1);
        if (!b) {
            result = 0;
        }
    }
    return result;
}
