#include "GameState/GameState.h"
// The camera's field of view (+0x58, degrees fx32) and its ease: the target (+0x1f0) and the time left (+0x1f4),
// which Camera_EaseFieldOfViewTo starts.
struct AngleTrig0202e9a4 { unsigned char padding0[0x58]; int fieldOfView; unsigned char padding5c[0x194]; int fieldOfViewTarget; unsigned fieldOfViewEaseTime; };
extern "C" void Camera_SetFieldOfView(AngleTrig0202e9a4*,int);
extern "C" {
#if defined(jpn)
extern unsigned data_02104040;
#define InterpolationCounter data_02104040
#else
extern unsigned data_02104300;
#define InterpolationCounter data_02104300
#endif
// Moves the field of view linearly towards its target by the frame's share of the time left.
// Main, originally func_0202f0e0 (USA 0x0202f0e0, EUR 0x0202f0f0, JPN 0x0202ec50)
void Camera_UpdateFieldOfViewEase(AngleTrig0202e9a4* camera) {
 if(!camera->fieldOfViewEaseTime) return;
 unsigned elapsed=GameState::GetInstance()->GetEffectiveDeltaTime();
 int fieldOfView=camera->fieldOfView;
 int result;
 if(elapsed>=camera->fieldOfViewEaseTime) { camera->fieldOfViewEaseTime=0; result=camera->fieldOfViewTarget; }
 else {
  float start=(float)fieldOfView;
  float difference=(float)(camera->fieldOfViewTarget-fieldOfView);
  float fraction=(float)elapsed/(float)camera->fieldOfViewEaseTime;
  result=(int)(start+difference*fraction);
  camera->fieldOfViewEaseTime-=elapsed;
  ++InterpolationCounter;
 }
 Camera_SetFieldOfView(camera,result);
}
}
