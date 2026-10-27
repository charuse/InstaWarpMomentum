#include "InstaWarpMomentum.h"
using namespace MR;

InstaWarpMomentum::InstaWarpMomentum(const char *pName) : AreaObj(pName) {
    wPos = (0.0f, 0.0f, 0.0f), wRot = wPos;
    mWarping = false;
    mCanWarp = true;
}

void InstaWarpMomentum::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    connectToSceneAreaObj(this);
    pMarioActor = MarioAccess::getPlayerActor();
    snprintf(dest, sizeof(dest), "InstaWarpPos%02d", mObjArg0);
}

void InstaWarpMomentum::movement() {
    if (isInVolume(*getPlayerPos())) {
        if (mCanWarp) {
            mCanWarp = false;
            if (findNamePos(dest, &wPos, &wRot)) {
                mWarping = true;
                TVec3f vel = pMarioActor->mVelocity;
                pMarioActor->mTranslation = TVec3f(wPos.x, wPos.y, wPos.z);
                pMarioActor->mVelocity = vel + TVec3f(0.008f, 0.008f, 0.008f);
                mWarping = false;
            }
            mCanWarp = true;
        }
    }
}

const char* InstaWarpMomentum::getManagerName() const {
    return "InstaWarpMomentum";
}