#include <globaldefs.h>

// GameObject::currentStats_'s status word (ModifiableCombatStats +0x14)
struct S_10088_inner {
    char unk[0x14];
    int flags;
};

// The GameObject (this file's copy of the field it uses)
struct S_10088 {
    char unk[0x138];
    struct S_10088_inner* currentStats_;
};

// USA: func_02010088
ARM int IsFlag10088Set_02010088(struct S_10088* object) {
    return (object->currentStats_->flags & 1) != 0;
}
