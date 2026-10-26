#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

extern "C" void __clear(void* buf, int size);
extern "C" void func_ov000_02169b78(void*);

struct Variant02030b0c { int tag; int u; };

struct Struct02030b7c;

struct Struct_020341e0 { signed short x, y, z; };
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct Struct_ov000_0216b478 {
    int tag;
    int unused;
    void* unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
    unsigned char pad10;
    unsigned char unknown_11_;
    struct Struct_020341e0 vec;
    unsigned short unknown_18_;
    unsigned char unknown_1a_;
};

// USA: func_ov000_0216b478
extern "C" ARM int func_ov000_0216b478(struct Variant02030b0c* v, int count) {
    struct Struct_ov000_0216b478* node = (struct Struct_ov000_0216b478*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216b478));

    struct Struct_020341e0 var1;
    int byteVal;
    char* copied = 0;
    int flagC = 1;
    __clear(&var1, 6);

    int var5 = ((Script::Parameter*)v)->ToInt();
    byteVal = ((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt() - 0x1a;

    char* var6 = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 0x10)))->ToString();
    if (var6 != 0) {
        copied = (char*)data_ov000_02184264.alloc->Allocate(strlen(var6) + 1);
        strcpy(copied, var6);
    }

    if (count >= 4) {
        flagC = ((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 0x18)))->ToInt();
    }

    node->tag = 0;
    node->unused = 0;
    node->tag = 0x15;
    node->unknown_e_ = (unsigned short)var5;
    node->unknown_d_ = (unsigned char)byteVal;
    node->unknown_8_ = copied;
    node->unknown_c_ = (unsigned char)flagC;
    node->unknown_18_ = 0;
    node->pad10 = 0;
    Vector3fix16Copy((Vector3s*)&node->vec, (Vector3s const*)&var1);
    node->unknown_1a_ = 1;
    func_ov000_02169b78(node);
    return 1;
}
