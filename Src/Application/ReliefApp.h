#pragma once
#include "../Common/AppBase.h"
#include "ReliefAppUI.h"
#include "../DGP/ViewTool.h"
#include "../DGP/Mesh3D.h"

namespace MagicApp
{
    class ReliefApp : public MagicCore::AppBase
    {
    public:
        ReliefApp();
        ~ReliefApp();

        virtual bool Enter(void);
        virtual bool Update(float timeElapsed);
        virtual bool Exit(void);
        virtual bool MouseMoved( const OIS::MouseEvent &arg );
        virtual bool MousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool MouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool KeyPressed( const OIS::KeyEvent &arg );
        bool ImportMesh3D();
        void GenerateRelief();
        void ExportReliefMesh();

    private:
        void SetupScene(void);
        void ShutdownScene(void);


    private:
        ReliefAppUI mUI;
        MagicDGP::ViewTool mViewTool;
        MagicDGP::LightMesh3D* mpLightMesh;
    };
}