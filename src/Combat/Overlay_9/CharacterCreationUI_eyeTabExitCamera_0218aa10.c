// The default view the eye colour tab eases back to. Originally data_ov009_0218aa10 and data_ov009_0218aa1c (ZevyaDev/dqix-decomp#324;
// jpn 0x0218b9ec, values assumed equal to usa).
typedef struct Vector3fix {
    int x;
    int y;
    int z;
} Vector3fix;

const Vector3fix CharacterCreationUI_eyeTabExitCameraPosition = {0xD000, 0xF800, 0x42CCC};
const Vector3fix CharacterCreationUI_eyeTabExitCameraTarget = {0xD000, 0xF800, 0};
