#include <globaldefs.h>


extern "C" unsigned char* Scenario_GetInstance(void* obj, int val);
extern "C" int ZoneVisitedFlag_GetFieldZoneIndex(int x);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int ZoneVisitedFlag_FindExtraZoneIndex(int key);
extern "C" int _s32_div_f(int a, int b);

struct Obj_0201bb78 { unsigned short field0; };

// USA: func_0201bb78
extern "C" ARM int func_0201bb78(struct Obj_0201bb78* obj, unsigned int val) {
    unsigned char* ctx = Scenario_GetInstance(obj, val);
    int result = 0;
    if (val >= 20000 && val <= 0x752f) {
        int t = ZoneVisitedFlag_GetFieldZoneIndex(val);
        if (t >= 0) {
            result = Scenario_TestFlag((int)ctx, ctx + 0x8c, t + 0x5a + 0xa00);
        }
    } else if (val >= 100 && val <= 0x270f) {
        int q = _s32_div_f(val, 100);
        if (q < 100) {
            result = Scenario_TestFlag((int)ctx, ctx + 0x8c, q + 0x96 + 0xa00);
        }
    } else if (val == 10000) {
        result = Scenario_TestFlag((int)ctx, ctx + 0x8c, 0x2b);
    } else {
        int t = ZoneVisitedFlag_FindExtraZoneIndex(obj->field0);
        if (t >= 0) {
            result = Scenario_TestFlag((int)ctx, ctx + 0x8c, t + 0x5a + 0xa00);
        }
    }
    return result;
}
