#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"

// A ZoneResourceTreeRecord (World/ZoneResourceTree.h): the element's offset from its parent, its turn about y and
// its scale (4.12 shorts), as this function combines them with the parent's
struct ZoneResourceTreeRecordTransform
{
    char unknown_0_[8];
    Vector3fix position;
    char unknown_14_[2];
    int16_t angleY;
    char unknown_18_[2];
    int16_t scaleX;
    int16_t scaleY;
    int16_t scaleZ;
};

// A BmdjSceneElement (World/BmdjScriptNode.h; also declared as ZoneResourceRuntimeNode in World/ZoneResourceTree.h),
// with BmdjSceneElement's field names, and ZoneResourceRuntimeNode's where that header only has an offset name
// (source, firstChild, next); scale (+0x14) is in BmdjSceneElement's unknown14. The world transform this function
// computes (angle, position, scale) from the element's source record and its parent's
struct BmdjSceneElementTransform
{
    char unknown_0_[6];
    int16_t angle;
    Vector3fix position;
    Vector3fix scale;
    ZoneResourceTreeRecordTransform* source;
    char unknown_24_[8];
    BmdjSceneElementTransform* firstChild;
    BmdjSceneElementTransform* next;
};

// Main, originally func_02013158 (USA 0x02013158, EUR 0x02013168, JPN 0x02012f20)
extern "C" ARM void BmdjSceneElement_ComputeTransforms(BmdjSceneElementTransform* self, const Vector3fix* parentPosition, int* parentAngle,
                                  const Vector3fix* parentScale)
{
    Matrix3x3 rotation;
    int sine;
    int cosine;
    BmdjSceneElementTransform* sibling;
    cosine = fix32cos(*parentAngle);
    sine = fix32sin(*parentAngle);
    Mat3x3_WriteRotationY(&rotation, sine, cosine);
    if (self->source != 0)
    {
        Vector3fix offset;
        Mat3x3_ApplyToVector(&self->source->position, &rotation, &offset);
        Vector3fix_Add(&offset, parentPosition, &self->position);
        self->angle = (int16_t)fix32ReduceAngle0To2Pi(*parentAngle + self->source->angleY);
        self->scale.x = FIX32_MULTIPLY(self->source->scaleX, parentScale->x);
        self->scale.y = FIX32_MULTIPLY(self->source->scaleY, parentScale->y);
        self->scale.z = FIX32_MULTIPLY(self->source->scaleZ, parentScale->z);
    }
    sibling = self->next;
    if (sibling != 0)
    {
        while (sibling != 0)
        {
            Vector3fix siblingOffset;
            int siblingAngle;
            if (sibling->source != 0)
            {
                Mat3x3_ApplyToVector(&sibling->source->position, &rotation, &siblingOffset);
                Vector3fix_Add(&siblingOffset, parentPosition, &sibling->position);
                sibling->angle = (int16_t)fix32ReduceAngle0To2Pi(*parentAngle + sibling->source->angleY);
                sibling->scale.x = FIX32_MULTIPLY(sibling->source->scaleX, parentScale->x);
                sibling->scale.y = FIX32_MULTIPLY(sibling->source->scaleY, parentScale->y);
                sibling->scale.z = FIX32_MULTIPLY(sibling->source->scaleZ, parentScale->z);
            }
            if (sibling->firstChild != 0)
            {
                siblingAngle = sibling->angle;
                BmdjSceneElement_ComputeTransforms(sibling->firstChild, &sibling->position, &siblingAngle, &sibling->scale);
            }
            sibling = sibling->next;
        }
    }
    if (self->firstChild != 0)
    {
        int angle;
        angle = self->angle;
        BmdjSceneElement_ComputeTransforms(self->firstChild, &self->position, &angle, &self->scale);
    }
}
