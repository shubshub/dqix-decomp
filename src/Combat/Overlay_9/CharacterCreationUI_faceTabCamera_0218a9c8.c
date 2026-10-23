// The close-up CharacterCreationUI_HandleFace eases the camera to on entering the tab (seen in-game: the camera
// reaches exactly these values and the head fills the screen). Originally data_ov009_0218a9c8 and data_ov009_0218a9d4 (ZevyaDev/dqix-decomp#324;
// jpn 0x0218b9a4, values assumed equal to usa).
typedef struct Vector3fix {
    int x;
    int y;
    int z;
} Vector3fix;

const Vector3fix CharacterCreationUI_faceTabCameraPosition = {0x9000, 0x12800, 0x2F000};
const Vector3fix CharacterCreationUI_faceTabCameraTarget = {0x9000, 0x12800, 0};
