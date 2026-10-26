#include <globaldefs.h>

struct Struct_02040468;
struct Struct_0203f008_2;
struct Struct_0203f0fc_2;

extern "C" ARM struct Struct_0203f008_2* func_02040468(struct Struct_02040468* list, int index);
extern "C" ARM int func_02040184(struct Struct_0203f0fc_2* table, const char* name);

struct Struct_0203f0fc {
    struct Struct_02040468* field0;
    char pad[0x24];
    short field28;
};

// USA: func_0203f0fc
extern "C" ARM int func_0203f0fc(struct Struct_0203f0fc* obj, const char* name) {
    struct Struct_0203f008_2* element;
    short index = obj->field28;
    if (index < 0) {
        return -1;
    }
    element = func_02040468(obj->field0, index);
    if (element == NULL) {
        return -1;
    }
    return func_02040184((struct Struct_0203f0fc_2*)((char*)element + 0x10), name);
}
