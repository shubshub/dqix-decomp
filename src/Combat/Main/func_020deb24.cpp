#include <globaldefs.h>

struct Struct_020deb08;
extern "C" short func_020deb08(struct Struct_020deb08* obj);

struct Struct_0205faf4_9 {
    unsigned short a;
    unsigned short pad2;
    unsigned short b;
    unsigned short pad6;
    int pad8;
    void* entries;
};

// USA: func_020deb24
extern "C" ARM void* func_020deb24(struct Struct_0205faf4_9* list, int index) {
    int count = func_020deb08((struct Struct_020deb08*)list);
    if (index < 0 || index >= count) {
        return NULL;
    }
    return (char*)list->entries + index * 0x20;
}
