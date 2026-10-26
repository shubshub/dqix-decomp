#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void* unused);
struct Vector3i;
extern "C" void* LinkSession_GetInstance(void);
extern int data_020e8d48;

struct Struct_0208f748 { int x, y, z; };
struct Struct_0208f748_2 { char pad[0xc]; unsigned char flag:4; };

// USA: func_0208f748
extern "C" ARM int func_0208f748(unsigned char* obj) {
    void* p = Zone3D_GetInstance(obj);
    Struct_0208f748_2* q = (Struct_0208f748_2*)*(void**)((char*)p + 8);
    if (q->flag != 0) return 0;
    GameState* battle = GameState::GetInstance();
    battle->GetProtagonist();
    ((int)GetGameResources());
    LinkSession_GetInstance();
    GrottoStruct* grotto = battle->GetGrottoStruct();
    Struct_0208f748 var4;
    *(Vector3i*)((int*)&var4) = *(Vector3i const*)(&grotto->entranceX);
    Struct_0208f748 var5 = *(Struct_0208f748*)&data_020e8d48;
    *(Vector3i*)((int*)(obj + 0x4c)) = *(Vector3i const*)((int*)&var4);
    ((Object3D*)(obj + 8))->SetScale((Vector3i const*)&var5);
    ((Object3D*)(obj + 8))->SetAnimationByIndex(0, 0);
    ((Object3D*)(obj + 8))->MakeVisible();
    obj[0xb6] = 1;
    return 1;
}
