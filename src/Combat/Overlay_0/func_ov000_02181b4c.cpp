#include <globaldefs.h>

struct Struct_ov000_0215767c_9 {
    char pad0[0xe];
    short targets[3];
    unsigned char kinds[3];
    unsigned char count;
    char pad18[0x20 - 0x18];
    Struct_ov000_0215767c_9* next;
};

struct Struct_ov000_02182b04 {
    char pad0[0x14];
    Struct_ov000_0215767c_9* head;
};

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);

static inline int inline_ov000_02181b4c(int target)
{
    return target >= 0 && target <= 3;
}

// USA: func_ov000_02181b4c
extern "C" ARM int func_ov000_02181b4c(void* obj, Struct_ov000_02182b04* list, int* arg2)
{
    int count = 0;
    Struct_ov000_0215767c_9* node;
    for (node = list->head; node != NULL; node = node->next) {
        int i;
        for (i = 0; i < node->count; i++) {
            if (i > 0) {
                unsigned char kind = node->kinds[i];
                if (kind != 8 && kind != 6 && kind != 7)
                    break;
            }
            int target = node->targets[i];
            bool isNew = true;
            int* out = arg2;
            int j;
            for (j = 0; j < count; j++, out++) {
                if (*out == target) {
                    isNew = false;
                    break;
                }
            }
            if (isNew) {
                if (inline_ov000_02181b4c(target)) {
                    short buf[4];
                    count = func_ov000_0215e9fc(obj, buf, 4, 0);
                    out = arg2;
                    short* src = buf;
                    int k;
                    for (k = 0; k < count; k++) {
                        *out = *src;
                        out++;
                        src++;
                    }
                    return count;
                }
                *out = target;
                count++;
            }
        }
    }
    return count;
}
