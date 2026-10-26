#include <globaldefs.h>

struct Struct_02040468;
struct Struct_0203f008_2;
extern "C" struct Struct_0203f008_2* func_02040468(struct Struct_02040468* list, int index);

struct Struct_0203f008 {
    struct Struct_02040468* list;
    char pad4[0x24];
    short index;
};

// USA: func_0203f008
extern "C" ARM struct Struct_0203f008_2* func_0203f008(struct Struct_0203f008* actor) {
    if (actor->list == NULL) return NULL;
    return func_02040468(actor->list, actor->index);
}
