// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "ICompassView.h"
#include "BidirectionalBus.h"
#include "ICompassViewModel.h"
#include "ApplyScreenControl.h"

namespace ExampleApp
{
    namespace Compass
    {
        namespace View
        {
            class CompassController : private Eegeo::NonCopyable
            {
            private:
                ICompassView& m_view;
                ICompassViewModel& m_viewModel;
                ExampleAppMessaging::TMessageBus& m_messageBus;

                Eegeo::Helpers::TCallback2<CompassController, ScreenControl::View::IScreenControlViewModel&, float> m_viewStateCallback;
                Eegeo::Helpers::TCallback1<CompassController, const CompassModeChangedMessage&> m_modeChangedHandler;
                Eegeo::Helpers::TCallback1<CompassController, const CompassHeadingUpdateMessage&> m_headingChangedHandler;
                Eegeo::Helpers::TCallback0<CompassController> m_viewCycledCallback;

                void OnViewCycled();

                void OnCompassModeChangedMessage(const CompassModeChangedMessage& message);

                void OnCompassHeadingChangedMessage(const CompassHeadingUpdateMessage& message);

                void OnScreenStateChangedCallback(ScreenControl::View::IScreenControlViewModel &viewModel, float& onScreenState);

            public:
                CompassController(  ICompassView& view,
                                    ICompassViewModel& viewModel,
                                    ExampleAppMessaging::TMessageBus& messageBus);

                ~CompassController();
            };
        }
    }
}
