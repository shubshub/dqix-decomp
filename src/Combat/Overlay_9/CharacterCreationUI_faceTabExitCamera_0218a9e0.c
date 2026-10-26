// The default view the face tab eases back to when leaving (seen in-game). Originally CharacterCreationUI_faceTabExitCameraPosition and CharacterCreationUI_faceTabExitCameraTarget (ZevyaDev/dqix-decomp#324;
// jpn 0x0218b9bc, values assumed equal to usa).
typedef struct Vector3fix {
    int x;
    int y;
    int z;
} Vector3fix;

const Vector3fix CharacterCreationUI_faceTabExitCameraPosition = {0xD000, 0xF800, 0x42CCC};
const Vector3fix CharacterCreationUI_faceTabExitCameraTarget = {0xD000, 0xF800, 0};
