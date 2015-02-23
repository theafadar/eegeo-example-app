// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "AndroidNativeState.h"
#include "Types.h"
#include "AboutPage.h"
#include "AboutPageViewIncludes.h"
#include "IAboutPageViewModule.h"

namespace ExampleApp
{
    namespace AboutPage
    {
        namespace View
        {
            class AboutPageViewModule: public IAboutPageViewModule, private Eegeo::NonCopyable
            {
            private:
                AboutPageView* m_pView;
                AboutPageController* m_pController;

            public:
                AboutPageViewModule(
                    AndroidNativeState& nativeState,
                    IAboutPageViewModel& aboutPageViewModel
                );

                ~AboutPageViewModule();

                AboutPageController& GetAboutPageController() const;
                AboutPageView& GetAboutPageView() const;
            };
        }
    }
}
