#include <globaldefs.h>

struct Element020de650;
struct ItemTable;
extern "C" Element020de650* ItemTable_Find(ItemTable*, int);

extern "C" void func_ov023_021dcba4(void*);

struct Struct_ov003_02178910 {
    char pad0[0x48];
    ItemTable* field48;
    Element020de650* field4c;
#if defined(jpn)
    char unknown_50_[0x680];
#else
    char unknown1_50_[0x704];
#endif
    int field754;
    char unknown_758_[0x18];
    short field770;
    unsigned short unknown_772_;
    unsigned short field774;
    unsigned char unknown_776_;
};

// USA: func_ov023_021dcae0
extern "C" ARM void func_ov023_021dcae0(struct Struct_ov003_02178910* obj, int val) {
    if (obj->unknown_776_ == 0 || (obj->field774 & 4) == 0) {
        obj->unknown_772_ = val;
        if (obj->field754 <= 0 || obj->unknown_776_ == 0) {
            obj->field770 = val;
            return;
        }
    }
    short v = obj->field770;
    if (v == val) {
        if (obj->field48 != NULL) {
            Element020de650* found = ItemTable_Find(obj->field48, v);
            if (obj->field4c != found) obj->field4c = found;
        }
    } else {
        func_ov023_021dcba4(obj);
    }
}
