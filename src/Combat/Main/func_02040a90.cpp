#include <globaldefs.h>

struct Struct_0203ce00;
struct Struct_020415c4;
struct Struct_02041654;

extern "C" int func_0203ce00(struct Struct_0203ce00* obj);
extern "C" int func_020415c4(struct Struct_020415c4* obj);
extern "C" int func_02041654(struct Struct_02041654* obj);

struct Struct_02040a90 {
    char pad[0x14];
    struct Struct_0203ce00* child14;
    struct Struct_020415c4* unknown_18_;
    struct Struct_02041654* child1c;
};

// USA: func_02040a90
extern "C" ARM int func_02040a90(struct Struct_02040a90* obj) {
    if (obj->child14 != NULL) return func_0203ce00(obj->child14);
    if (obj->unknown_18_ != NULL) return func_020415c4(obj->unknown_18_);
    if (obj->child1c != NULL) return func_02041654(obj->child1c);
    return 0;
}
