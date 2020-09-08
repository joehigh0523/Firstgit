#pragma once
#include "ControlBase.h"
#include "analysisBase.h"
#include "DualHeadBase.h"

enum TesterType_e
{
    TesterTypeLegacy_e,
    TesterTypeDaytona_e,
    TesterTypeXStream_e
};

class FactoryBase
{
public:
    FactoryBase();
    virtual ~FactoryBase();

    virtual ControlBase *CreateControl() = 0;
    virtual AnalysisBase *CreateAnalysis(ControlBase *ctrlBase) = 0;
    virtual DualHeadBase *CreateDualHead(bool lock = true) = 0;
};
