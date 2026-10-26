#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;

extern "C" void func_0209953c(unsigned short);

struct Struct_0206ed44;
struct Struct_0206ed44_2;
extern "C" void func_0206eeec(struct Struct_0206ed44* list, struct Struct_0206ed44_2* node);

struct Struct_02108d04 {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct Struct_02108d04 data_02108d04;

struct Struct_0206ed44_3 {
    short key;
    unsigned char f2;
    unsigned char f3;
    int f4;
    short f8;
    short fa;
    short fc;
};

// USA: func_0206ed44
extern "C" ARM int func_0206ed44(void* param0) {
    struct Struct_0206ed44_3* node;
    int i;
    short* arr;
    int key;
    key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    arr = (short*)data_02108d04.field8;
    if (arr != 0) {
        for (i = 0; i < data_02108d04.field0; i++) {
            if (arr[i] == key) break;
        }
        if (i == data_02108d04.field0) {
            return 1;
        }
    }
    node = (struct Struct_0206ed44_3*)((SafeAllocator*)data_02108d04.field4)->Allocate(0x14);
    if (node == 0) {
        func_0209953c(2);
        return 0;
    }
    node->key = (short)key;
    node->f2 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    node->f3 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    node->f4 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x18)))->ToInt();
    node->f8 = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x20)))->ToFloat());
    node->fa = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();
    node->fc = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x30)))->ToInt();
    if (((unsigned int)node->f4 << 26 >> 29) == 0) {
        node->f4 &= ~7;
    }
    func_0206eeec((struct Struct_0206ed44*)data_02108d04.fieldC, (struct Struct_0206ed44_2*)node);
    return 1;
}
