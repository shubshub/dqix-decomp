#include <globaldefs.h>
struct LootableContainerManager;

#pragma define_section initcode ".init" RX

extern "C" ARM char* _ZN24LootableContainerManagerC1Ev(char* obj);
ARM LootableContainerManager* ClearRegionAndReturnSelf020269d0(LootableContainerManager* obj);

extern "C" void __register_global_object(int c, int b, void* node);

extern char LootableContainerManager_mainInstance;
extern int data_02108e84;

// USA: func_020e6234
extern "C" __declspec(initcode) ARM void __sinit_020e6234(void) {
    _ZN24LootableContainerManagerC1Ev(&LootableContainerManager_mainInstance);
    __register_global_object((int)&LootableContainerManager_mainInstance, (int)ClearRegionAndReturnSelf020269d0, &data_02108e84);
}
