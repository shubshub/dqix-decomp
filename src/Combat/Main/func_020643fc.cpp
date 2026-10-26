#include <globaldefs.h>

struct Node020643fc {
    char pad0[6];
    unsigned char key;
    char unknown_7_[9];
    struct Node020643fc* sub;   // 0x10
    struct Node020643fc* next;  // 0x14
};

extern char g_scenario;

// USA: func_020643fc
extern "C" ARM void func_020643fc(void* unused, struct Node020643fc* node) {
    struct Node020643fc* cur = *(struct Node020643fc**)(&g_scenario + 0x47c);
    struct Node020643fc* prev;
    if (cur == NULL) {
        *(struct Node020643fc**)(&g_scenario + 0x47c) = node;
        return;
    }
    while (cur != NULL) {
        if (cur->key == node->key) {
            while (cur->sub != NULL) cur = cur->sub;
            cur->sub = node;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) prev->next = node;
}
