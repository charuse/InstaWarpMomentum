#pragma once
#include "syati.h"

class InstaWarpMomentum : public AreaObj {
public:
    InstaWarpMomentum(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual const char* getManagerName() const;

    MarioActor *pMarioActor;
    TVec3f wPos;
    TVec3f wRot;
    char dest[0xF];
    bool mWarping;
    bool mCanWarp;
};