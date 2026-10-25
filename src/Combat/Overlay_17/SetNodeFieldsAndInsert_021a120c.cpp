#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Resource/ResourceNodeInsertion.h>

struct Node02046a3c;
struct List02046a3c;
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" void func_ov017_021a124c(unsigned char* obj);

// USA: func_ov017_021a120c
ARM void SetNodeFieldsAndInsert_021a120c(GameResources* resources, int mode, int selection) {
    func_ov017_021a124c((unsigned char*)resources->unknown_ptr_array_3700[2]);
    ((ResourceInsertionNode*)resources->unknown_ptr_array_3700[2])->mode = mode;
    ((ResourceInsertionNode*)resources->unknown_ptr_array_3700[2])->selection = selection;
    InsertNodeAfterHead((List02046a3c*)resources->fieldTaskQueue_,
                        (Node02046a3c*)resources->unknown_ptr_array_3700[2]);
}
