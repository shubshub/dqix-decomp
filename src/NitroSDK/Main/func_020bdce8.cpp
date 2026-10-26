#include <globaldefs.h>

struct Struct_020bdce8_2 {
    unsigned char type;
    unsigned char key;
    unsigned short pad;
    int val;
};

struct Struct_020bdce8 {
    unsigned int count;
    Struct_020bdce8_2 entries[1];
};

extern "C" Struct_020bdce8* func_020bd710(int id);
extern "C" int func_020bddec(int val, int key, int arg2, int flag, int* out);
extern "C" int func_020bde70(int val, int key, int arg2, int flag, int* out);
extern "C" int func_020bded0(int val, int key, int arg2, int flag, int* out);
extern "C" int func_020be010(int, unsigned int, int, int, int*);

// USA: func_020bdce8
extern "C" ARM int func_020bdce8(int id, int arg1) {
    Struct_020bdce8* list = func_020bd710(id);
    if (list == 0) {
        return 1;
    }

    int* a = 0;
    int* b = 0;
    int* c = 0;
    int* d = 0;
    unsigned int i = 0;
    Struct_020bdce8_2* entry;

    if (i < list->count) {
        entry = list->entries;
        do {
            int ret;
            switch (entry->type) {
            case 0:
                ret = func_020bddec(entry->val, entry->key, arg1, 1, a);
                if (ret != 0) return ret;
                break;
            case 3:
                ret = func_020bde70(entry->val, entry->key, arg1, 1, b);
                if (ret != 0) return ret;
                break;
            case 1:
                ret = func_020bded0(entry->val, entry->key, arg1, 1, c);
                if (ret != 0) return ret;
                break;
            case 2:
                ret = func_020be010(entry->val, entry->key, arg1, 1, d);
                if (ret != 0) return ret;
                break;
            }
            entry++;
            i++;
        } while (i < list->count);
    }
    return 0;
}
