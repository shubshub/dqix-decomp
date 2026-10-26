#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov016_0218de60_2 {
    short id;
    short kind;
    char* name;
    char* resource;
    char* option;
#if !defined(jpn)
    bool enabled;
    bool alternate;
#endif
    short priority;
    int value;
    Struct_ov016_0218de60_2* next;
};
struct Struct_ov016_0218de60 {
    Struct_ov016_0218de60_2* head;
    unsigned int count;
    SafeAllocator* allocator;
};
extern Struct_ov016_0218de60* data_ov016_0219d1bc;
extern "C" void func_ov016_0218e020(Struct_ov016_0218de60*, void*);

// USA: func_ov016_0218de60
extern "C" ARM int func_ov016_0218de60(Script::Parameter* params, int count) {
    SafeAllocator* allocator = data_ov016_0219d1bc->allocator;
    Struct_ov016_0218de60_2 node;
    memset(&node, 0, sizeof(node));
    node.id = params[0].ToInt();
    node.kind = params[1].ToInt();
    const char* text = params[2].ToString();
    if (text) {
        node.name = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.name) strcpy(node.name, text);
    }
    text = params[3].ToString();
    if (text && strlen(text)) {
        node.resource = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.resource) strcpy(node.resource, text);
    }
    text = params[4].ToString();
    if (text && strlen(text)) {
        node.option = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.option) strcpy(node.option, text);
    }
    node.priority = params[5].ToInt();
    params += 6;
    node.value = (params++)->ToInt();
#if !defined(jpn)
    count -= 7;
    if (count > 0) {
        node.enabled = (params++)->ToInt() != 0;
        --count;
    } else {
        node.enabled = true;
    }
    if (count > 0) node.alternate = params->ToInt() != 0;
    else node.alternate = false;
#endif
    func_ov016_0218e020(data_ov016_0219d1bc, &node);
    return 1;
}
