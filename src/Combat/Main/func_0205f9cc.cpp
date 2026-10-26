#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

struct Struct_0205ec40 {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    int f8;
    int fc;
    int f10;
    int f14;
};

extern "C" void func_0205ec40(struct Struct_0205ec40* s);
extern "C" void func_0205ec70(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* arg3, void* arg4);
struct Node020643fc;
extern "C" void func_020643fc(void* unused, struct Node020643fc* node);

extern char g_scenario;

// USA: func_0205f9cc
extern "C" ARM int func_0205f9cc(struct Variant02030b0c* arr, int b) {
    int id = ((Script::Parameter*)&arr[0])->ToInt();
    if (id != *(int*)(&g_scenario + 0x484)) {
        return 0;
    }

    int var1 = ((Script::Parameter*)&arr[1])->ToInt();
    int var2 = ((Script::Parameter*)&arr[2])->ToInt();
    int var3 = ((Script::Parameter*)&arr[3])->ToInt();
    int var4 = ((Script::Parameter*)&arr[4])->ToInt();

    int cur = *(int*)(&g_scenario + 0x488);
    int start = var1 * 1000 + var2;
    int end = var3 * 1000 + var4;
    cur = cur * 1000 + *(int*)(&g_scenario + 0x48c);
    if (cur < start || end < cur) {
        return 0;
    }

    SafeAllocator* alloc = *(SafeAllocator**)(&g_scenario + 0x480);
    struct Struct_0205ec40* node = (struct Struct_0205ec40*)alloc->Allocate(0x18);
    if (node == NULL) {
        return 1;
    }

    func_0205ec40(node);
    node->f0 = id;
    node->f2 = var1;
    node->f3 = var3;
    node->f4 = var2;
    node->unknown_5_ = var4;
    node->unknown_6_ = ((Script::Parameter*)&arr[5])->ToInt();

    func_0205ec70(alloc, b - 6, &arr[6], &node->f8, &node->fc);

    func_020643fc(&g_scenario, (struct Node020643fc*)node);
    return 1;
}
