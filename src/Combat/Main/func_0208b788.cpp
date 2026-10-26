#include <globaldefs.h>
struct Struct_0208b788 { int x, y; float scale; unsigned short value; unsigned short pad; };
struct Struct_020e8d0c { Struct_0208b788 rows[3]; };
extern Struct_020e8d0c data_020e8d0c;
// USA: func_0208b788
extern "C" ARM void func_0208b788(int index, float arg1, Struct_0208b788* out, int adjust) {
    Struct_020e8d0c table = data_020e8d0c;
    if (adjust) table.rows[0].scale = 1.2f;
    Struct_0208b788* start = &table.rows[index];
    Struct_0208b788* end = &table.rows[index + 1];
    out->x = (int)((float)start->x + arg1 * (float)(end->x - start->x));
    out->y = (int)((float)start->y + arg1 * (float)(end->y - start->y));
    out->scale = start->scale + arg1 * (end->scale - start->scale);
    out->value = (unsigned int)((float)(unsigned int)start->value + arg1 * (float)(end->value - start->value));
}
