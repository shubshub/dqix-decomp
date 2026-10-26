#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

extern "C" int func_ov000_0216f728(unsigned short*);
extern "C" void Camera_SetOrbitVector(void*, int*);
extern "C" int Camera_GetRoll(void*);
extern "C" void Camera_SetRoll(unsigned char*, int);
extern "C" {
void Camera_SetOrbit(void*,int,int,int);
extern int data_ov000_02183fc8;
struct Struct_ov000_02184270_2 { unsigned short unknown_0_,kind; int unknown_4_,value8,valueC,value10,unknown_14_; };
extern Struct_ov000_02184270_2 data_ov000_02184270;
extern const int data_ov000_02183268[];
extern const int data_ov000_02183298[];
extern const short data_ov000_0218325c[];
}
struct Struct_ov000_0216ea38 {
    char p0[0x10]; Vector3i position; char p1[0x70-0x1c]; Vector3i angles;
    char p2[0x260-0x7c]; unsigned char initialized,state,first,second;
    char p3[0x27c-0x264]; unsigned short* info;
};

// USA: func_ov000_0216ea38
extern "C" ARM void func_ov000_0216ea38(Struct_ov000_0216ea38* obj) {
    if (!obj->initialized) return;
    GameState* gs = GameState::GetInstance();
    data_ov000_02184270.value10 += 0xcc;
    data_ov000_02184270.unknown_14_ += 0x14;
    data_ov000_02184270.unknown_4_ += 4;
    GameObject* a = gs->GetGameObjectByIndex(obj->first);
    GameObject* b = gs->GetGameObjectByIndex(obj->second);
    if (!a || !b) return;
    int var3 = a->obj3D_.GetHeight(), var4 = b->obj3D_.GetHeight();
    int var5 = 0;
    if (var3 >= 0x2000) var5 = 1;
    if (var4 >= 0x2000) var5 = 0;
    if (var4 < 0x2000 && var3 < 0x2000) var5 = data_ov000_02184270.unknown_0_ % 2;
    Vector3i pa(a->obj3D_.position_), pb(b->obj3D_.position_), direction, result, offset;
    Vector3fix_Subtract(&pb, &pa, &direction);
    int length = Vector3fix_Length(&direction);
    if (length) Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000,length), &direction);
    if (length / 2 > 0x3000) Vector3fixMultiplyScalar(&direction,0x2000,&offset);
    else Vector3fixMultiplyScalar(&direction,length/2,&offset);
    if (!var5) {
        Vector3fix_Add(&pa,&offset,&result);
        int h = a->obj3D_.GetHeight();
        result.y = (int)((float)result.y + 0.75f*(float)h);
    } else {
        Vector3fixMultiplyScalar(&offset,-0x1000,&offset);
        Vector3fix_Add(&pb,&offset,&result);
        int h = b->obj3D_.GetHeight();
        result.y = (int)((float)result.y + 0.75f*(float)h);
    }
    if (result.y > 0x1000) result.y = 0x1000;
    Vector3i moved, delta, old(obj->position);
    Vector3fix_Subtract(&result,&old,&delta);
    int distance = Vector3fix_Length(&delta);
    Vector3fixMultiplyScalar(&delta,0xcc,&delta);
    int step = Vector3fix_Length(&delta);
    if (data_ov000_02184270.value10 < step)
        Vector3fixMultiplyScalar(&delta,fix32_Divide(data_ov000_02184270.value10,step),&delta);
    Vector3fix_Add(&old,&delta,&moved);
    if (data_ov000_02184270.kind == 0) {
        if (distance < 0x5000) obj->state = 1;
    } else data_ov000_02184270.kind--;
    Vector3i angles(obj->angles);
    int firstAngle,var21,var22,var23;
    if (!var5) {
        int angle = fix32_Atan2(direction.x,direction.z);
        firstAngle = fix32ReduceAngle0To2Pi((int)(11581.19921875f + (float)angle));
        var22 = fix32ReduceAngle0To2Pi((int)((float)angle - 11581.19921875f));
        var21 = fix32abs(fix32SignedAngleDistance(angles.x,firstAngle));
        var23 = fix32abs(fix32SignedAngleDistance(angles.x,var22));
    } else {
        int angle = fix32_Atan2(direction.x,direction.z);
        firstAngle = fix32ReduceAngle0To2Pi((int)(12868.0f + (11581.19921875f + (float)angle)));
        var22 = fix32ReduceAngle0To2Pi((int)(12868.0f + ((float)angle - 11581.19921875f)));
        var21 = fix32abs(fix32SignedAngleDistance(angles.x,firstAngle));
        var23 = fix32abs(fix32SignedAngleDistance(angles.x,var22));
    }
    if (var21 >= var23) firstAngle = var22;
    int desiredY = 0x1000;
    int desiredZ;
    if (data_ov000_02184270.unknown_0_ < 30) {
        float var28 = (float)Vector3fix_Distance(&pa,&pb);
        var28 *= 1.6f;
        desiredZ = (int)var28;
        if (desiredZ < 0x7000) desiredZ = 0x7000;
    } else {
        int index = (obj->first + obj->second) % 3;
        desiredZ = data_ov000_02183268[index];
        desiredY = data_ov000_02183298[index];
    }
    int inRange = func_ov000_0216f728(obj->info);
    if (var4 > 0x2800) {
        result.y = var4 / 2;
        if (result.y < 0x2800) result.y = 0x2800;
        moved.y = result.y;
        desiredY = data_ov000_02184270.value8;
        if (!inRange) firstAngle = fix32ReduceAngle0To2Pi(firstAngle + data_ov000_02184270.valueC);
        if (desiredZ < 0x8000) desiredZ = 0x8000;
    }
    int desiredTail = data_ov000_0218325c[(obj->first + obj->second) % 5];
    if (data_ov000_02183fc8) {
        obj->position = result;
        Camera_SetOrbit(obj,firstAngle,desiredY,desiredZ);
        Camera_SetRoll((unsigned char*)obj,desiredTail);
        data_ov000_02183fc8 = 0;
    } else {
        if (moved.y > 0x2000) moved.y = 0x2000;
        obj->position = moved;
        Vector3i next(angles);
        int difference = (int)(0.05f*(float)fix32SignedAngleDistance(angles.x,firstAngle));
        int limit = data_ov000_02184270.unknown_14_;
        if (limit < fix32abs(difference)) {
            if (difference > 0) difference = limit;
            else difference = -limit;
        }
        next.x = fix32ReduceAngle0To2Pi(angles.x+difference);
        next.y = (int)((float)angles.y + 0.02f*(float)(desiredY-angles.y));
        next.z = (int)((float)angles.z + 0.02f*(float)(desiredZ-angles.z));
        Camera_SetOrbitVector(obj,&next.x);
        int change, var36;
        int tail = Camera_GetRoll(obj);
        float var38 = (float)fix32SignedAngleDistance(tail,desiredTail);
        var38 *= 0.1f;
        change = (int)var38;
        var36 = data_ov000_02184270.unknown_4_;
        if (var36 < fix32abs(change)) {
            if (change > 0) change = var36;
            else change = -var36;
        }
        if (change) Camera_SetRoll((unsigned char*)obj,(short)fix32ReduceAngle0To2Pi(change+tail));
    }
}
