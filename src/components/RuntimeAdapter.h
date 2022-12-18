#pragma once

#include "runtime-sdk/RuntimeAdapterIf.h"

class RuntimeAdapter : public RuntimeAdapterIf
{
	RuntimeAdapter();
	~RuntimeAdapter();

    virtual void startApplications() override;
    virtual void stopApplications() override;
    virtual void subscribe() override;
};
