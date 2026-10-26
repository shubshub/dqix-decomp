#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);
extern "C" int _ffix(float v);

extern "C" void Mat4x4_Multiply(const Matrix4x4* arg0, const Matrix4x4* arg1, Matrix4x4* out);

extern const Matrix4x4 data_ov025_021ef180;
extern const Matrix4x4 data_ov025_021ef140;
extern const Matrix4x4 data_ov025_021ef100;
extern const Matrix4x4 data_ov025_021ef0c0;
extern const Matrix4x4 data_ov025_021ef080;
extern const Matrix4x4 data_ov025_021ef1c0;

union Struct_ov025_021ee488 { struct { int x, y, z; }; int entries[3]; };

inline int inline_ov025_021ee488(int a, int b) { return FIX32_MULTIPLY(a, b); }

// USA: func_ov025_021ee488
extern "C" ARM void func_ov025_021ee488(Struct_ov025_021ee488* result, const Struct_ov025_021ee488* points, int count, int time) {
    int frame = _ffix(_fdiv(_fflt(time), 4096.0f));
    int t2;
    int var2;
    time -= frame << 12;
    t2 = inline_ov025_021ee488(time, time);
    var2 = inline_ov025_021ee488(t2, time);
    Struct_ov025_021ee488 pos;

    if (frame == 0) {
        Matrix4x4 var4 = data_ov025_021ef180;
        Matrix4x4 ctrl = data_ov025_021ef140;
        ctrl.rows[1].x = points[frame].x;
        ctrl.rows[1].y = points[frame].y;
        ctrl.rows[1].z = points[frame].z;
        ctrl.rows[2].x = points[frame + 1].x;
        ctrl.rows[2].y = points[frame + 1].y;
        ctrl.rows[2].z = points[frame + 1].z;
        ctrl.rows[3].x = points[frame + 2].x;
        ctrl.rows[3].y = points[frame + 2].y;
        ctrl.rows[3].z = points[frame + 2].z;
        Matrix4x4 var6;
        Mat4x4_Multiply(&var4, &ctrl, &var6);
        pos.x = (inline_ov025_021ee488(var2, var6.rows[0].x) + inline_ov025_021ee488(t2, var6.rows[1].x) + inline_ov025_021ee488(time, var6.rows[2].x) + var6.rows[3].x);
        pos.y = (inline_ov025_021ee488(var2, var6.rows[0].y) + inline_ov025_021ee488(t2, var6.rows[1].y) + inline_ov025_021ee488(time, var6.rows[2].y) + var6.rows[3].y);
        pos.z = (inline_ov025_021ee488(var2, var6.rows[0].z) + inline_ov025_021ee488(t2, var6.rows[1].z) + inline_ov025_021ee488(time, var6.rows[2].z) + var6.rows[3].z);
        pos.x /= 2;
        pos.y /= 2;
        pos.z /= 2;
    } else if (frame == count - 2) {
        Matrix4x4 var7 = data_ov025_021ef100;
        Matrix4x4 ctrl = data_ov025_021ef0c0;
        ctrl.rows[0].x = points[frame - 1].x;
        ctrl.rows[0].y = points[frame - 1].y;
        ctrl.rows[0].z = points[frame - 1].z;
        ctrl.rows[1].x = points[frame].x;
        ctrl.rows[1].y = points[frame].y;
        ctrl.rows[1].z = points[frame].z;
        ctrl.rows[2].x = points[frame + 1].x;
        ctrl.rows[2].y = points[frame + 1].y;
        ctrl.rows[2].z = points[frame + 1].z;
        Matrix4x4 var9;
        Mat4x4_Multiply(&var7, &ctrl, &var9);
        pos.x = (inline_ov025_021ee488(var2, var9.rows[0].x) + inline_ov025_021ee488(t2, var9.rows[1].x) + inline_ov025_021ee488(time, var9.rows[2].x) + var9.rows[3].x);
        pos.y = (inline_ov025_021ee488(var2, var9.rows[0].y) + inline_ov025_021ee488(t2, var9.rows[1].y) + inline_ov025_021ee488(time, var9.rows[2].y) + var9.rows[3].y);
        pos.z = (inline_ov025_021ee488(var2, var9.rows[0].z) + inline_ov025_021ee488(t2, var9.rows[1].z) + inline_ov025_021ee488(time, var9.rows[2].z) + var9.rows[3].z);
        pos.x /= 2;
        pos.y /= 2;
        pos.z /= 2;
    } else {
        Matrix4x4 var10 = data_ov025_021ef080;
        Matrix4x4 ctrl = data_ov025_021ef1c0;
        ctrl.rows[0].x = points[frame - 1].x;
        ctrl.rows[0].y = points[frame - 1].y;
        ctrl.rows[0].z = points[frame - 1].z;
        ctrl.rows[1].x = points[frame].x;
        ctrl.rows[1].y = points[frame].y;
        ctrl.rows[1].z = points[frame].z;
        ctrl.rows[2].x = points[frame + 1].x;
        ctrl.rows[2].y = points[frame + 1].y;
        ctrl.rows[2].z = points[frame + 1].z;
        ctrl.rows[3].x = points[frame + 2].x;
        ctrl.rows[3].y = points[frame + 2].y;
        ctrl.rows[3].z = points[frame + 2].z;
        Matrix4x4 var12;
        Mat4x4_Multiply(&var10, &ctrl, &var12);
        pos.x = (inline_ov025_021ee488(var2, var12.rows[0].x) + inline_ov025_021ee488(t2, var12.rows[1].x) + inline_ov025_021ee488(time, var12.rows[2].x) + var12.rows[3].x);
        pos.y = (inline_ov025_021ee488(var2, var12.rows[0].y) + inline_ov025_021ee488(t2, var12.rows[1].y) + inline_ov025_021ee488(time, var12.rows[2].y) + var12.rows[3].y);
        pos.z = (inline_ov025_021ee488(var2, var12.rows[0].z) + inline_ov025_021ee488(t2, var12.rows[1].z) + inline_ov025_021ee488(time, var12.rows[2].z) + var12.rows[3].z);
        pos.x /= 2;
        pos.y /= 2;
        pos.z /= 2;
    }

    COPY_ARRAY(result->entries, pos.entries);
}
