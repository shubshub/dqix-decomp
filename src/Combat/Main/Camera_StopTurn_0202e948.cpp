#include <globaldefs.h>

// Stops the camera's turn: +0x20e is the angle the target turns around the position each frame, +0x210 the
// frames left (Camera_UpdateAnimations steps it).
// Main, originally ClearFields0x20e0x210_0202e948 (USA 0x0202e948, EUR 0x0202e958, JPN 0x0202e4b8)
ARM void Camera_StopTurn(unsigned char* camera) {
    *(unsigned short*)(camera + 0x20e) = 0;
    *(unsigned short*)(camera + 0x210) = 0;
}
