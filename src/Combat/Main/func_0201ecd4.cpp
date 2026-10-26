#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Struct_0201ecd4 {
    unsigned short id;
    unsigned char flags;
    unsigned char unknown_3_;
    char* text;
    Struct_0201ecd4* next;
};
struct Struct_020fdc40_3 { Struct_0201ecd4* head; SafeAllocator* allocator; int unknown_8_; };
extern Struct_020fdc40_3 data_020fdc40;
// USA: func_0201ecd4
extern "C" ARM int func_0201ecd4(Script::Parameter* parameter, int count) {
    if (!data_020fdc40.head) return 0;
    Struct_0201ecd4* node = (Struct_0201ecd4*)data_020fdc40.allocator->Allocate(12);
    node->id = parameter->ToInt();
    parameter++;
    const char* text = (parameter++)->ToString();
    if (!text) return 0;
    node->text = (char*)data_020fdc40.allocator->Allocate(strlen(text) + 1);
    strcpy(node->text, text);
    node->flags = 0;
    if (count >= 3) {
        node->flags = parameter->ToInt();
        node->flags &= 31;
        parameter++;
    }
    node->unknown_3_ = 0;
    if (count >= 4) node->unknown_3_ = parameter->ToInt();
    node->next = 0;
    Struct_0201ecd4* tail = data_020fdc40.head;
    while (tail->next) tail = tail->next;
    tail->next = node;
    return 1;
}
