#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
struct Struct_ov000_021682ec {char p[0x49c];unsigned char special:1,rest:7;};
struct Struct_ov000_021682ec_2 {char p[0x52c];SafeAllocator first,second;};
struct Struct_ov000_021682ec_3 {char p[0x13c];int* scriptState;
#if defined(jpn)
char q[4];
#else
char q[16];
#endif
Struct_ov000_021682ec* actor;Struct_ov000_021682ec_2* allocators;};
inline int inline_ov000_021682ec(Struct_ov000_021682ec_3* unit,int value){return unit->scriptState?(*unit->scriptState=value):0;}
struct Item {signed char id;unsigned char phase;short first,second;};
struct Struct_ov000_021682ec_5 {
#if defined(jpn)
char p[0x79c6];
#else
char p[0x77d6];
#endif
Item items[4];unsigned char count;inline int inline_ov000_021682ec_2(){return count;}};
extern "C" GameObject* func_0200ff1c(GameState*,int);extern "C" int FieldTaskQueue_IsEmpty(void**);extern "C" void func_02072c9c(int,char*);
struct Struct_203dafc;extern "C" void func_0203dafc(Struct_203dafc*);struct StreamHeader;extern "C" void func_ov000_0216d1c4(int,StreamHeader*,int,int*);struct Bytes02033b88;extern "C" void GameObject_ForceMotionState(Bytes02033b88*,int);
extern "C" {int sprintf(char*,const char*,...);void func_ov000_0216867c(Struct_ov000_021682ec_5*,int);extern const char data_ov000_02183ad8[],data_ov000_02183ae0[],data_ov000_02183afb[],data_ov000_02183b03[];}
// USA: func_ov000_021682ec
extern "C" ARM void func_ov000_021682ec(Struct_ov000_021682ec_5* self){
 int count=self->count;BackgroundLoader* loader;GameState* gs;SafeAllocator* allocator;int i;Item* item;GameObject* unit; if(count==0)return;gs=GameState::GetInstance();loader=BackgroundLoader::GetInstance();void** resource=(void**)GetGameResources()->unknown_ptr_array_3700[0];
 char filename[64];ObjectArchiveLoadInfo firstInfo,secondInfo;char code[8];void* file;unsigned int size;const void* script;unsigned int scriptSize;int scriptState;
 for(i=0;i<self->inline_ov000_021682ec_2();i++){
  item=&self->items[i];
  if(item->phase==0){
   if(!FieldTaskQueue_IsEmpty(resource))return;unit=func_0200ff1c(gs,item->id);if(unit)unit->obj3D_.RemoveAllAnimationPackages();loader->AddFence();func_02072c9c(item->id,code);sprintf(filename,data_ov000_02183ad8,code);
   if(unit&&((Struct_ov000_021682ec_3*)unit)->actor->special==1)filename[0]='w';
   item->first=loader->QueueLoadFileInGP2(data_ov000_02183ae0,filename,0);sprintf(filename,data_ov000_02183afb,code);item->second=loader->QueueLoadFileInGP2(data_ov000_02183ae0,filename,0);item->phase++;
  }else if(item->phase==1){
   if(!loader->GetTaskStatus(item->first))continue;unit=func_0200ff1c(gs,item->id);
   if(unit&&loader->GetDetailedTaskStatus(item->first)==2){
    loader->GetLoadedFileByID(item->first,&file,&size);Struct_ov000_021682ec_2* allocators=((Struct_ov000_021682ec_3*)unit)->allocators;
    if(allocators&&file){allocator=&allocators->first;allocator->Reset();func_0203dafc((Struct_203dafc*)&firstInfo);firstInfo.unk_10=1;firstInfo.packageID=0;firstInfo.fileData=file;firstInfo.fileSize=size;firstInfo.allocator=allocator;unit->obj3D_.LoadFromCCHROrCMOTArchive(&firstInfo,0);}
   }
   loader->RemoveTask(item->first);item->first=0xffff;item->phase++;
  }else if(item->phase==2){
   if(!loader->GetTaskStatus(item->second))continue;unit=func_0200ff1c(gs,item->id);
   if(unit&&loader->GetDetailedTaskStatus(item->second)==2){
    loader->GetLoadedFileByID(item->second,&file,&size);Struct_ov000_021682ec_2* allocators=((Struct_ov000_021682ec_3*)unit)->allocators;
    if(allocators&&file){allocator=&allocators->second;allocator->Reset();func_0203dafc((Struct_203dafc*)&secondInfo);secondInfo.unk_10=1;secondInfo.packageID=1;secondInfo.fileData=file;secondInfo.fileSize=size;secondInfo.allocator=allocator;unit->obj3D_.LoadFromCCHROrCMOTArchive(&secondInfo,0);
     if(FindFilesInNarcBySubstring(file,data_ov000_02183b03,&script,&scriptSize,1)){func_ov000_0216d1c4((int)allocator,(StreamHeader*)script,scriptSize,&scriptState);inline_ov000_021682ec((Struct_ov000_021682ec_3*)unit,scriptState);}
     GameObject_ForceMotionState((Bytes02033b88*)unit,0);
    }
   }
   loader->RemoveTask(item->second);item->second=0xffff;func_ov000_0216867c(self,item->id);
  }
 }
}
