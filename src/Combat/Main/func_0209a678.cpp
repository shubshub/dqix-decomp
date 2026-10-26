#include <globaldefs.h>

extern "C" int func_02053c6c(unsigned char* member);
extern "C" int func_02083b00(unsigned char* arr, int bit);
extern "C" void func_02083acc(unsigned char* arr, int bit);

struct Struct_0209a678 {
#if defined(jpn)
    unsigned short id : 12;
    unsigned short pad1 : 4;
#else
    unsigned short id : 11;
    unsigned short pad1 : 5;
#endif
    union {
        unsigned int slot : 5;
        unsigned int raw;
    } u;
    unsigned int pad2;
};

struct Field150 {
    unsigned char pad[0x464];
    unsigned char key[0x20];
};

// USA: func_0209a678
extern "C" ARM int func_0209a678(char* table, void* member, unsigned short* arg2) {
    unsigned char* field = (unsigned char*)func_02053c6c((unsigned char*)member);
    int index = 0;
    int count = 0;
    int slot;
    int i;
    for (slot = 0; slot < 0x1a; slot++) {
        unsigned char var5 = ((Field150*)field)->key[(*(Struct_0209a678**)table)[index].u.slot];
        int j = 0;
        for (;;) {
            unsigned int var7 = ((*(Struct_0209a678**)table)[index + j].u.raw << 20) >> 25;
            if (var7 >= var5) {
                if (var5 == var7) {
                    j++;
                }
                break;
            }
            j++;
        }
        int end = index + j;
        for (i = index; i < end; i++) {
#if defined(jpn)
            Struct_0209a678* entry = &(*(Struct_0209a678**)table)[i];
            unsigned int raw = entry->u.raw;
            unsigned int var11 = (raw << 15) >> 27;
            if (var11 != 0 &&
                ((Field150*)field)->key[var11] < ((raw << 8) >> 25)) {
                continue;
            }
            unsigned short id = entry->id;
#else
            unsigned short id = (*(Struct_0209a678**)table)[i].id;
#endif
            if (func_02083b00(field, id) == 0) {
                func_02083acc(field, id);
                arg2[count] = id;
                count++;
            }
        }
        index += 0xb;
    }
    return count;
}
