/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IInputPin : virtual public Core::IUnknown {
        enum { ID = ID_INPUT_PIN };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_INPUT_PIN_NOTIFICATION };

            virtual ~INotification() { }

            virtual void Marker(const uint32_t marker) = 0;
        };

        struct EXTERNAL ICatalog : virtual public Core::IUnknown {
            enum { ID = ID_INPUT_PIN_CATALOG };

            virtual IInputPin* IInputPinResource(const uint32_t id) = 0;
        };

        virtual ~IInputPin() { }

        virtual void Register(IInputPin::INotification* sink) = 0;
        virtual void Unregister(IInputPin::INotification* sink) = 0;

        virtual void AddMarker(const uint32_t marker) = 0;
        virtual void RemoveMarker(const uint32_t marker) = 0;
    };
}
}
