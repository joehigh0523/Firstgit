#pragma once
#include "iqapiCommon.h"

class AnalysisBaseAbs
{
public:
    AnalysisBaseAbs() {} ;
    virtual ~AnalysisBaseAbs() {};

    virtual int Analyze(iqapiSignalData *userData, iqapiCapture *_data_, iqapiAnalysis *_analysis_, iqapiResult **_results_, IQV_VSA_NUM_ENUM testerNumber = IQV_VSA_NUM_1, bool setDefault = true) = 0;

};
