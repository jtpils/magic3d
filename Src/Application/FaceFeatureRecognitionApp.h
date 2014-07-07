#pragma once
#include "../Common/AppBase.h"
#include "FaceFeatureRecognitionAppUI.h"
#include <vector>

namespace MagicApp
{
    class Face2DObj;
    class FaceFeatureRecognitionApp : public MagicCore::AppBase
    {
    public:
        FaceFeatureRecognitionApp();
        ~FaceFeatureRecognitionApp();

        virtual bool Enter(void);
        virtual bool Update(float timeElapsed);
        virtual bool Exit(void);
        virtual bool MouseMoved( const OIS::MouseEvent &arg );
        virtual bool MousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool MouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool KeyPressed( const OIS::KeyEvent &arg );
        virtual void WindowResized( Ogre::RenderWindow* rw );

        void OpenImage(void);

    private:
        void SetupScene(void);
        void ShutdownScene(void);
        void UpdateDisplayImage(const std::vector<double>* dpsList, const std::vector<double>* fpsList);
        void MarkPointsToImage(cv::Mat& img, const std::vector<double>* markList, 
            unsigned char blue, unsigned char green, unsigned char red, int markWidth);

    private:
        FaceFeatureRecognitionAppUI mUI;
        Face2DObj* mpF2DObj;
    };

}
