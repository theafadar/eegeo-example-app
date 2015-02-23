// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "MyPinCreation.h"
#include "IMyPinCreationModule.h"
#include "Modules.h"
#include "VectorMathDecl.h"
#include "Camera.h"
#include "Rendering.h"
#include "Terrain.h"
#include "IIdentity.h"
#include "SearchResultMenu.h"
#include "Menu.h"
#include "Search.h"
#include "IdTypes.h"
#include "MyPins.h"
#include "MyPinCreationModelObserver.h"
#include "MyPinCreationViewStateChangedHandler.h"
#include "MyPinCreationViewSavePinHandler.h"
#include "BidirectionalBus.h"
#include "IReactionControllerModel.h"

namespace ExampleApp
{
    namespace MyPinCreation
    {
        namespace SdkModel
        {
            class MyPinCreationModule : public IMyPinCreationModule
            {
            public:
                MyPinCreationModule(MyPins::SdkModel::IMyPinsService& myPinsService,
                                    Eegeo::Helpers::IIdentityProvider& identityProvider,
                                    ExampleApp::Menu::View::IMenuViewModel& primaryMenuViewModel,
                                    ExampleApp::Menu::View::IMenuViewModel& secondaryMenuViewModel,
                                    Search::SdkModel::ISearchQueryPerformer& searchQueryPerformer,
                                    ExampleApp::Menu::View::IMenuViewModel& searchResultMenuViewModel,
                                    Search::SdkModel::ISearchRefreshService& searchRefreshService,
                                    ExampleAppMessaging::TMessageBus& messageBus,
                                    Reaction::View::IReactionControllerModel& reactionControllerModel);

                ~MyPinCreationModule();

                IMyPinCreationModel& GetMyPinCreationModel() const;
                View::IMyPinCreationInitiationViewModel& GetMyPinCreationInitiationViewModel() const;
                View::IMyPinCreationConfirmationViewModel& GetMyPinCreationConfirmationViewModel() const;
                View::IMyPinCreationCompositeViewModel& GetMyPinCreationCompositeViewModel() const;

                ScreenControl::View::IScreenControlViewModel& GetInitiationScreenControlViewModel() const;
                ScreenControl::View::IScreenControlViewModel& GetConfirmationScreenControlViewModel() const;

                OpenableControl::View::IOpenableControlViewModel& GetObservableOpenableControl() const;

            private:

                MyPinCreationModel* m_pMyPinCreationModel;
                View::MyPinCreationInitiationViewModel* m_pMyPinCreationInitiationViewModel;
                View::MyPinCreationConfirmationViewModel* m_pMyPinCreationConfirmationViewModel;
                View::MyPinCreationCompositeViewModel* m_pMyPinCreationCompositeViewModel;
                MyPinCreationModelObserver* m_pMyPinCreationModelObserver;
                MyPinCreationViewStateChangedHandler* m_pMyPinCreationViewStateChangedHandler;
                MyPinCreationViewSavePinHandler* m_pMyPinCreationViewSavePinHandler;
            };
        }
    }
}
