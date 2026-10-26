#include <globaldefs.h>

#if defined(jpn)
enum { ContainerOffset = 0x8c };
#else
enum { ContainerOffset = 0x6c };
#endif
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);

struct Node0201b754 {
    unsigned char pad0[0x2c];
    unsigned short unknown_2c_;
    unsigned char unknown_2e_[0x42];
    struct Node0201b754* unknown_70_;
};

// USA: func_0201b754
extern "C" ARM struct Node0201b754* func_0201b754(void* obj, int key) {
    struct Node0201b754* node = (struct Node0201b754*)ZoneFeatures_GetFirstOfType((unsigned char*)((char*)obj + ContainerOffset), (unsigned int)(0xa));
    while (node != 0) {
        if (node->unknown_2c_ == key) return node;
        node = node->unknown_70_;
    }
    return 0;
}
