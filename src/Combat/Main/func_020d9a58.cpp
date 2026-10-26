#include <globaldefs.h>
#include "Resource/GameResources.h"

struct ListHead02046b60;
struct Node02046a8c;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, Node02046a8c* node);
extern "C" void func_020d9ab0(void* param);

// USA: func_020d9a58
extern "C" ARM void func_020d9a58(void* param) {
    GameResources* resources = GetGameResources();
    struct ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
    if (func_02046b60(list, 0x1c)) {
        func_02046a8c(list, static_cast<Node02046a8c*>(resources->fieldTasks_[6]));
        func_02046a8c(list, static_cast<Node02046a8c*>(resources->unknown_ptr_array_3700[3]));
    }
    func_020d9ab0(param);
}
