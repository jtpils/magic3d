#pragma once
#include "PointCloud3D.h"
#include <vector>
#include "Math/HomoMatrix4.h"
#include "flann/flann.h"
#include "OpenNI.h"

namespace MagicDGP
{
    class Registration
    {
    public:
        Registration();
        ~Registration();

    public:
        void ICPRegistrate(const Point3DSet* pRef, Point3DSet* pOrigin, const MagicMath::HomoMatrix4* pTransInit, MagicMath::HomoMatrix4* pTransRes);
        void ICPRegistrateEnhance(const Point3DSet* pRefPC, Point3DSet* pNewPC, const MagicMath::HomoMatrix4* pTransInit, MagicMath::HomoMatrix4* pTransRes, openni::VideoStream& depthStream);

    private:
        void ICPInitRefData(const Point3DSet* pRef);
        void ICPSamplePoint(const Point3DSet* pPC, std::vector<int>& sampleIndex);
        void ICPFindCorrespondance(const Point3DSet* pRef, const Point3DSet* pOrigin, const MagicMath::HomoMatrix4* pTransInit,
            std::vector<int>& sampleIndex,  std::vector<int>& correspondIndex);
        void ICPEnergyMinimization(const Point3DSet* pRef, const Point3DSet* pOrigin, const MagicMath::HomoMatrix4* pTransInit,
            std::vector<int>& sampleIndex, std::vector<int>& correspondIndex, MagicMath::HomoMatrix4* pTransDelta);

        void ICPSamplePointEnhance(const Point3DSet* pPC, std::vector<int>& sampleIndex, const MagicMath::HomoMatrix4* pTransform, openni::VideoStream& depthStream);
        void ICPFindCorrespondanceEnhance(const Point3DSet* pRefPC, const Point3DSet* pNewPC, const MagicMath::HomoMatrix4* pTransInit,
            std::vector<int>& sampleIndex,  std::vector<int>& correspondIndex, openni::VideoStream& depthStream);
        void ICPEnergyMinimizationEnhance(const Point3DSet* pRefPC, const Point3DSet* pNewPC, const MagicMath::HomoMatrix4* pTransInit,
            std::vector<int>& sampleIndex, std::vector<int>& correspondIndex, MagicMath::HomoMatrix4* pTransDelta);

    private:
        flann_index_t mFlannIndex;
        float* mDataSet;
        FLANNParameters mSearchPara;
        int mDepthResolutionX;
        int mDepthResolutionY;
    };


}