#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0209cb94_2;
struct Struct_0209cb94;
extern "C" void func_0209ccc8(struct Struct_0209cb94*, struct Struct_0209cb94_2*);
extern int data_02109be0;

// USA: func_0209cb94
extern "C" ARM int func_0209cb94(struct Variant02030b0c* p) {
    int value = ((Script::Parameter*)p)->ToInt();
    func_0209ccc8((struct Struct_0209cb94*)&data_02109be0, (struct Struct_0209cb94_2*)&value);
    return 1;
}
