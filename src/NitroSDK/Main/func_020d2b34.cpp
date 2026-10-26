#include <globaldefs.h>

extern "C" void func_020d21f8(void);
extern "C" void func_020d220c(void);
void CleanCacheRange(const void* addr, unsigned int size);

// USA: func_020d2b34
extern "C" ARM void func_020d2b34(char* obj, int idx, char* node) {
    func_020d21f8();
    int rec = (int)obj + idx * 8;
    char* head = *(char**)(rec + 0x18);
    if (head == 0) {
        goto tail;
    }
    if (node == head) {
        func_020d220c();
        return;
    }
    {
        int slot = (int)(obj + 0x18) + idx * 8;
        char* owner = *(char**)(head + 0x18);
        if (slot == (int)owner) {
            char* t = *(char**)(rec + 0x1c);
            *(char**)(head + 0x18) = t;
            char* h2 = *(char**)(rec + 0x18);
            CleanCacheRange(h2, 0x3c);
            goto tail;
        } else {
            char* p = owner;
            if (p != 0) {
                char* var7;
                do {
                    var7 = *(char**)(p + 0x4);
                    if (slot == (int)var7) break;
                    p = var7;
                } while (var7 != 0);
            }
            char* t2 = *(char**)((obj + idx * 8) + 0x1c);
            *(char**)(p + 0x4) = t2;
            CleanCacheRange(p, 8);
        }
    }
tail:
    {
        char* var9 = (obj + 0x18) + idx * 8;
        char* var10 = *(char**)(node + 0x18);
        *(char**)(node + 0x18) = var9;
        *(char**)((obj + idx * 8) + 0x1c) = var10;
        *(char**)((obj + idx * 8) + 0x18) = node;
        func_020d220c();
        CleanCacheRange(obj, 0x3c);
        CleanCacheRange(node, 0x3c);
    }
}
