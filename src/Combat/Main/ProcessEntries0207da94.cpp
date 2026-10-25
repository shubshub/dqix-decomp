#include <globaldefs.h>

extern "C" void func_0207dcf0(int a);
extern "C" int memcmp(void* a, void* b, int c);
extern "C" void func_ov017_021c9c64(int a, int b);

struct Init0207d7c0;
void InitStruct0207d7c0(struct Init0207d7c0* o);

extern int data_020e8a4c;

struct Entry0207da94 {
    unsigned short h0;
    short pad2;
    signed char b4;
    char pad5[3];
    signed char arr8[4];
};

// USA: func_0207da94
ARM void ProcessEntries0207da94(struct Entry0207da94* list, int idx) {
    int i = 0;
    int falseVal = i;
    int trueVal = 1;
    int resetVal = i;
    int negOne = -1;
    for (; i < 4; list++, i++) {
        signed char v = list->arr8[idx];
        if (v == 0) continue;
        if (list->b4 < 0) {
            list->arr8[idx] = (signed char)negOne;
            continue;
        }
        {
            int flag = (v == negOne) ? trueVal : falseVal;
            list->arr8[idx] = (signed char)resetVal;
            if (flag) {
                func_0207dcf0(list->h0);
            }
        }
        if (list->b4 == idx) list->b4 = (signed char)negOne;
        {
            int found = (memcmp(list->arr8, &data_020e8a4c, 4) == 0);
            if (found) {
                func_ov017_021c9c64(list->h0, 0);
                InitStruct0207d7c0((struct Init0207d7c0*)list);
            }
        }
    }
}
