#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct TaggedNumber02184c30 {
    int type;
    union { int unknown_0_; float unknown1_0_; } value;
};
extern "C" int func_ov011_02184c30(TaggedNumber02184c30* value);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void* context);
extern "C" void* func_ov023_021f6880(void* list, int key);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* node);
#else
extern "C" int func_ov024_021f6f10(void* node);
#endif
extern "C" void* func_ov023_021fa598(void* node);
extern "C" int MessageSystem_GetInstance();
struct TableA68;
extern "C" void* func_02072a68(TableA68* table, int key);

// USA: func_ov011_021873c4
extern "C" ARM int func_ov011_021873c4(TaggedNumber02184c30* arguments) {
    int var0 = func_ov011_02184c30(&arguments[0]);
    int var1 = func_ov011_02184c30(&arguments[1]);
    void* context = func_ov017_021b2164();
    void* list = func_ov011_021849c8(context);
    void* node = func_ov023_021f6880(list, var0);
    if (!node) return 1;
#if defined(jpn)
    if (func_ov023_021f6f10(node) != 4) return 1;
#else
    if (func_ov024_021f6f10(node) != 4) return 1;
#endif
    TableA68* texts = (TableA68*)func_ov023_021fa598(node);
    if (!texts) return 1;
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    const char* text = (const char*)func_02072a68(texts, (short)var1);
#if defined(jpn)
    func_0204500c(messages, text, 0);
    messages->active = 1;
    messages->flags17ff.flag4 = 1;
#else
    func_0204500c(messages, text, 0, 0xe3);
    messages->active = 1;
    messages->unknown_19d2_ = 1;
#endif
    return 1;
}
