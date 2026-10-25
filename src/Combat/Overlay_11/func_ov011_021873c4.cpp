#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct Struct_ov011_02184c30 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};
extern "C" int func_ov011_02184c30(Struct_ov011_02184c30* arg0);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" void* func_ov023_021f6880(void* arg0, int arg1);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* arg0);
#else
extern "C" int func_ov024_021f6f10(void* arg0);
#endif
extern "C" void* func_ov023_021fa598(void* node);
int MessageSystem_GetInstance();
struct TableA68;
void* FindEntryByKey_02072a68(TableA68* table, int key);

// USA: func_ov011_021873c4
extern "C" ARM int func_ov011_021873c4(Struct_ov011_02184c30* arg0) {
    int var0 = func_ov011_02184c30(&arg0[0]);
    int var1 = func_ov011_02184c30(&arg0[1]);
    void* var2 = func_ov017_021b2164();
    void* var3 = func_ov011_021849c8(var2);
    void* var4 = func_ov023_021f6880(var3, var0);
    if (!var4) return 1;
#if defined(jpn)
    if (func_ov023_021f6f10(var4) != 4) return 1;
#else
    if (func_ov024_021f6f10(var4) != 4) return 1;
#endif
    TableA68* texts = (TableA68*)func_ov023_021fa598(node);
    if (!texts) return 1;
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    const char* text = (const char*)FindEntryByKey_02072a68(texts, (short)textKey);
#if defined(jpn)
    func_0204500c(var6, var7, 0);
    var6->unknown_998_ = 1;
    var6->unknown_17ff_.unknown_0_4_ = 1;
#else
    func_0204500c(var6, var7, 0, 0xe3);
    var6->unknown_998_ = 1;
    var6->unknown_19d2_ = 1;
#endif
    return 1;
}
