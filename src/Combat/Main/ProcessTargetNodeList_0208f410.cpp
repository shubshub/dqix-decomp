#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { kListOffset = 0x4ec };
#else
enum { kListOffset = 0x6fc };
#endif

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LootPointList_GetInstance(void);

struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** obj);
int LootPointList_AppliesToMap(void* unused, char* str);
struct S1a0;
struct Vector3i;

struct ListNode0208f410 {
    char pad0[4];
    int vec[3];
    unsigned int f10;
    ListNode0208f410* next;
};

struct Obj0208f410 {
    char pad0[8];
    void* target;
    ListNode0208f410* head;
};

// USA: func_0208f410  (semantic: ProcessTargetNodeList_0208f410)
extern "C" ARM void func_0208f410(Obj0208f410* obj) {
    if (obj->target == 0) return;

    int ov = (int)GetGameResources();
    HeadNode02046b24** headList = *(HeadNode02046b24***)(ov + 0x3000 + kListOffset);
    if (FieldTaskQueue_GetCurrentKind(headList) == 0xa) return;
    if (TestFlags04((GameResources*)ov, 2) != 0) return;

    void* g = Zone3D_GetInstance();
    char* s = *(char**)((char*)g + 8);
    void* dataPtr = LootPointList_GetInstance();
    if (s == 0) return;
    if (LootPointList_AppliesToMap(dataPtr, s + 5) == 0) return;

    ListNode0208f410* node = obj->head;
    int flag = 1;
    while (node) {
        ((Object3D*)((S1a0*)obj->target))->SetCurrentAnimationTime(node->f10);
        *(Vector3i*)((int*)((char*)obj->target + 0x44)) = *(Vector3i const*)((int*)&node->vec);
        ((Object3D*)obj->target)->Draw(flag);
        node = node->next;
    }
}
