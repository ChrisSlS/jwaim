#ifndef HELPER_H
#define HELPER_H

#include <cmath>
#include <iostream>
#include <libconfig.h++>

#include "types.h"
#include "offsets.h"
#include "remote.h"
#include "settings.h"
#include "atomic"
namespace helper
{
        bool WorldToScreen(const Vector &vecOrigin, Vector &vecScreen, float *pflViewMatrix );
        void clampAngle(QAngle *angle);
        void Smoothing(QAngle* source,QAngle* target, float percentSmoothing);
        float getDistanceFov(QAngle*delta, Vector* sourcePos,Vector* targetPos);
        QAngle calcAngle(Vector *source, Vector *target);
        bool IgnoreWeapon(int iWeaponID);
        bool ShouldAutoShoot(int iWeaponID);
        void resolve(Entity* ent,Vector* target, float lby);
        std::string getConfigValue(std::string property, libconfig::Config &cfg);
        BoneMatrix getBones(void* bonePtr, int bone);
        Vector WorldToScreen_(const Vector &camerapos,const Vector &enemy, const QAngle &myvang, float FOV);
        float fShootDistance(int bone);
        Vector RecoilCrosshair(QAngle &vpunch, float FOV);
        std::string AtomicBoolToString(std::atomic<bool> *b);
        Vector AimLine(QAngle &angle, const Vector &pos);
        Vector BonePos(unsigned long m_pStudioBonesPtr, int bone, remote::Handle &csgo);
}

#endif // HELPER_H
