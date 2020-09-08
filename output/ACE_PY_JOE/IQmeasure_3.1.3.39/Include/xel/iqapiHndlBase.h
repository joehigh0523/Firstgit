#pragma once
// ****************************************************************
// file : iqapiHndlBase.h
// Note : Should not contain any code that is matlab related so that GPS/FM doesn't depend on matlab ( No MCR installed for GPS/FM api ) 
//        Matlab code can be placed to iqapiHndlMatlab.h
//      Based on iqapi 1.8.75
// ****************************************************************
#define IQAPI_VERSION          "2.0.14.1"
#define IQAPI_RELEASE_DATE     "(Jun 11, 2014)"

#include "iqapiDefines.h"
//#include "ControlBase.h"
//#include "AnalysisBase.h"

// ****************************************************************
// Define statement
// ****************************************************************
//#define _INCLUDE_GF_

#ifdef _INCLUDE_GF_
//#pragma comment(lib, "FMAnalysisDll.lib")
#endif

//#define _INCLUDE_NFC_

#define  MAX_LEN_MES       512

enum WHAT_VERSION_TO_CHECK
{
   IQV_LEGACY_AND_GF_VERSION,    // Check version for WIFI/BT/WiMax and GPS/FM
   IQV_LEGACY_VERSION_ONLY,      // Check version for WIFI/BT/WiMax 
   IQV_GF_VERSION_ONLY,          // Check version for GPS/FM   
   IQV_LEGACY_VERSION_ONLY_HW18   // Check version for WIFI/BT/WiMax. HW 18X doesn't contain Flash FPGA. No need to check it
};

// ! Mac OS X needs this to correctly set up working directory when launched from the Finder (no-op on Windows)
// passing null sets it to the application directory
IQ_API int iqapiSetWorkingDirectory(char *newpath);


class iqapiCaptureHT40Data3;

class IQ_API iqapiHndlBase
{
public:
    iqapiHndlBase();
   virtual ~iqapiHndlBase() {};

	static void StartMlDebug(void); //!< \note This function is reserved for Debugger Output
	static void EndMlDebug(void);	//!< \note This function is reserved for Debugger Output

	char			lastErr[MAX_LEN_ERR_TXT]; //!< Indicates the last error message text.

   iqapiCaptureHT40Data3 *dataHt40Data3;

   //virtual int    IsLicenseAvailable(IQV_LICENSE_TYPE licenseType, bool *returnResult) = 0;  //!< Checks if license is available
   //virtual bool   IsHardwareVersion(IQV_HARDWARE_VERSION_ENUM hardwareVersion) = 0; //!< Check hardware version
   virtual int    GetStatus() { return 0;};            //!< Retrieves hardware status from the test system.   


   // ***********************************************************************
   // For SCPI tester only
   // ***********************************************************************
   virtual int GetSession(int *session, IQV_VSA_NUM_ENUM testerNumber = IQV_VSA_NUM_1) = 0;
   virtual int Lock(IQV_LOCK_SESSION lock, unsigned int *lockResult) = 0;


// Internal use
   /////virtual int    GetTxRfFreqHz(double *txRfFreqHz);   //!< Get the current transmiter frequency
   /////virtual int    MiscCmd(char *cmd, double input, double *output) = 0; //!<  This function is reserved for internal use

protected:
    //ControlBase     *controlBase;
//    AnalysisBase    *analysisBase;

};

