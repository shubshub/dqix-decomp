#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "Combat/EntryGetterTypes.h"

extern "C" void* func_0203cf4c(void);

struct Struct_0203dce4_2;
struct Struct_0203dce4;
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);

// USA: func_020656e4
ARM int MessageSystem::func_020656e4(int arg0) {
    if (!unknown_19b6_) return 0;

    struct Struct_0203dce4* entry = func_0203dce4(
        (struct Struct_0203dce4_2*)func_0203cf4c(),
        selectedEntry);
    if (entry == NULL) return 0;

    int result = 1;
    func_02040af0(entry,
        unknown_1844_);

    if (func_020409e0(entry) ==
        func_02040a20(entry)) {
        unknown_19b6_ = 0;
        result = 0;
    }
    return result;
}
