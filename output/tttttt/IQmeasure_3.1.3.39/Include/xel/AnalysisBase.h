#pragma once
#include "AnalysisBaseAbs.h"
#include "ControlBase.h"

class AnalysisBase : AnalysisBaseAbs
{
public:
    AnalysisBase(ControlBase *_hndlControl_);
    virtual ~AnalysisBase();

    // *********************************************************
    // Attribute
    // *********************************************************
    int lastErrCode;
    char lastErr[MAX_LEN_ERR_TXT];
    iqapiResult *results;

    // *********************************************************
    // Implementation
    // *********************************************************
    void ResetLastErr();
    virtual int Analyze(iqapiSignalData *userData, iqapiCapture *_data_, iqapiAnalysis *_analysis_, iqapiResult **_results_, IQV_VSA_NUM_ENUM testerNumber = IQV_VSA_NUM_1, bool setDefault = true)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_DATA_ERR;
    };    

    virtual int SetFirmwareVersion(char *fwVersion)        // The firmware version for the first tester usually. It is used to get only the result parameters that is applied to certain FW version.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_DATA_ERR;
    };    

protected:
    ControlBase *hndlControl;
};
