#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02099ef4 { int tag; union { int i; float f; } value; };

struct Variant02030b0c;

struct Struct_0201d530;
struct Vector3s;

struct Struct_02109a54 {
    unsigned char field0;
    unsigned char field1;
    short unknown_2_[3];
    short unknown_8_[3];
    unsigned char unknown_e_;
    char pad;
    short unknown_10_[3];
    short vec3[3];
};

extern struct Struct_02109a54 data_02109a54[];

// USA: func_02099ef4
extern "C" ARM int func_02099ef4(struct Struct_02099ef4* p) {
    int id;
    struct Struct_02109a54* entry;
    struct Struct_02099ef4* cursor;

    id = ((Script::Parameter*)((struct Variant02030b0c*)p))->ToInt();
    entry = &data_02109a54[id];
    entry->field0 = (unsigned char)id;

    entry->field1 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)(p + 1)))->ToInt();

    cursor = (struct Struct_02099ef4*)(Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)(p + 2)))->ToVec3fix16((Vector3s*)entry->unknown_2_);
    cursor = (struct Struct_02099ef4*)(Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)cursor))->ToVec3fix16((Vector3s*)entry->unknown_8_);

    entry->unknown_e_ = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)cursor))->ToInt();

    cursor = (struct Struct_02099ef4*)(Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)(cursor + 1)))->ToVec3fix16((Vector3s*)entry->unknown_10_);
    (Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)cursor))->ToVec3fix16((Vector3s*)entry->vec3);

    return 1;
}
