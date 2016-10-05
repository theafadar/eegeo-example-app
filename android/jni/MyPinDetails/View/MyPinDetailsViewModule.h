// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Module.h"

namespace ExampleApp
{
    namespace MyPinDetails
    {
        namespace View
        {
            class MyPinDetailsViewModule : public Module
            {
            public:
            	void Register(const TContainerBuilder& builder);
            	void RegisterLeaves();
            };
        }
    }
}
