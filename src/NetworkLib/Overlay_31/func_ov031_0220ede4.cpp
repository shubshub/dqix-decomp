#include <globaldefs.h>

extern "C" int func_ov031_0220d60c(void);
extern "C" int func_ov031_0220f368(unsigned char *a, unsigned char *b);

struct Struct_ov031_0220ede4 {
    unsigned char pad0[0xc];
    Struct_ov031_0220ede4 *next;
    unsigned char pad10[4];
};

struct Struct_ov031_0220ede4_2 {
    unsigned char pad0[4];
    Struct_ov031_0220ede4 *head;
};

// USA: func_ov031_0220ede4
extern "C" ARM Struct_ov031_0220ede4 *func_ov031_0220ede4(unsigned char *key) {
    char *base = (char *)func_ov031_0220d60c() + 0x2000;
    Struct_ov031_0220ede4 *node = NULL;
    Struct_ov031_0220ede4_2 *var2 = *(Struct_ov031_0220ede4_2 **)(base + 0x270);
    if (key == NULL) return node;
    if (var2 != NULL) {
        unsigned int cnt = *(unsigned int *)(base + 0x274);
        if (cnt > 0xc) {
            node = var2->head;
            if (node != NULL) {
                do {
                    if (func_ov031_0220f368((unsigned char *)node + 0x14, key) != 0) break;
                    node = node->next;
                } while (node != NULL);
            }
        }
    }
    return node;
}
