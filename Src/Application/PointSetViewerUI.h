#pragma once
#include "MyGUI.h"

namespace MagicApp
{
    class PointSetViewerUI
    {
    public:
        PointSetViewerUI();
        ~PointSetViewerUI();

        void Setup();
        void Shutdown();

    private:
        void OpenPointSet(MyGUI::Widget* pSender);
        void BackToHomepage(MyGUI::Widget* pSender);
        void OpenMesh3D(MyGUI::Widget* pSender); //just for test

    private:
        MyGUI::VectorWidgetPtr mRoot;
    };
}