#pragma once
#include "iqapiDefines.h"
#include "iqapiCommon.h"
#include "AnalysisBaseAbs.h"
//////#include "iqapiHndlMatlab.h"
#include "lp_driver_enums.h"
#include <stdio.h>
#include <string.h>


class ControlBase
{
public:
    ControlBase();
    virtual ~ControlBase();

// **********************************************************************
// Implementation
// **********************************************************************

    // **********************************************************************
    // Error Handling
    // **********************************************************************
    void ResetLastErr();

    int CheckSystemError(int session, LP_Boolean_t WaitOpToBeDone = LP_ON, int errorBufferSize = 0, char *errorBuffer = NULL);

    // ****************************************************************
    // Connection Handling Functions
    // ****************************************************************    
    virtual int ConInit(char *ip1, char *ip2, char *ip3, char *ip4, iqapiTxBase **_tx_, iqapiRxBase **_rx_, iqapiCapture **_data_, bool isConOpen = false) //!< Connects to and initializes a single test system.		
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    virtual int ConClose()     //!< Closes one or more connections to the test systems.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    virtual bool ConValid()    //!< Indicates valid, open connection.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return false;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    virtual bool GetConnectionStatus() = 0;
    virtual void SetConnectionStatus(bool _connectionStatus_) = 0;
    virtual int GetNumberOfTester()
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40

    virtual int GetSession(int *session, IQV_VSA_NUM_ENUM testerNumber = IQV_VSA_NUM_1)
    { 
        *session = 0;
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int Lock(IQV_LOCK_SESSION lock, unsigned int *lockResult) = 0;

    virtual void SetConnectionType(IQV_CONNECTION_TYPE _connectionType_) = 0;
    virtual IQV_CONNECTION_TYPE GetConnectionType() = 0;

    // **********************************************************************
    // Version information
    // **********************************************************************
    virtual int GetAllVersions(char *version, int versionSize)   //!< Gets all versions related to software and hardware of the test system
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetModelNumber(char *buff, int bufflen, int testerNumber = 1)  //!< Gets the hardware version of the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetHardwareVersion(char *buff, int bufflen, int testerNumber = 1)  //!< Gets the hardware version of the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetSerialNumber(char *buff, int bufflen, int testerNumber = 1)  //!< Gets the hardware version of the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetFirmwareVersion(char *buff, int bufflen, int testerNumber = 1)  //!< Gets the hardware version of the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetCalibrationDate(char *buff, int bufflen, int testerNumber = 1)  //!< Gets the hardware version of the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int IsLicenseAvailable(const char *licenseType, bool *returnResult)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

    // **********************************************************************
    // Analysis - 
    // **********************************************************************
    virtual int LoadSignalFile(char *fileName, iqapiCapture **_data_)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int LoadSignalFileScpi(char *fileName, iqapiCapture **_data_)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int SaveSignalFile(char *fileName, IQV_SAVE_SCPI_FILE_TYPE_ENUM fileType = IQV_SAVE_IQVSA_FILE)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

    // **********************************************************************
    // HW control for TX and RX
    // **********************************************************************
    virtual int SetDefault(bool isGetStatus = false)   //!< Resets and initializes test systems
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int GetStatus() //!< Retrieves hardware status from the test system.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

    virtual int SetTxRx(IQV_SET_TX_RX_TYPE setTxRx_e)    //!< Sets Tx and Rx configurations  
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual void SetLeftPort(LP_Port_Name_t _leftPort_)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        lastErrCode = IQAPI_HW_CONTROL_ERROR;
    };    
    virtual LP_Port_Name_t GetLeftPort()
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        lastErrCode = IQAPI_HW_CONTROL_ERROR;
        return LP_RF1A;
    };    
    virtual void SetRightPort(LP_Port_Name_t _rightPort_)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        lastErrCode = IQAPI_HW_CONTROL_ERROR;
    };    
    virtual LP_Port_Name_t GetRightPort()
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        lastErrCode = IQAPI_HW_CONTROL_ERROR;
        return LP_RF2A;
    };    

// **********************************************************************
// HW TX 
// **********************************************************************
    virtual int SetTx() 	//!< Sets Tx configuration
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    // ****************************************************************    
    // Wave Generation and Downloading Functions
    // ****************************************************************    
    virtual int SetWave(char *fileName, bool autoPlay = true) //!< Downloads waveform data to VSG loaded from a file 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int SetWaveScpi(char *fileName, bool autoPlay = true) //!< Downloads waveform data to VSG loaded from a file 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    /*!< 
     * \param[in] fileName signal file name to be loaded to tester
     * \param[in] autoPlay if true (default), loaded signal file will be loaded to tester and played automatically at VSG. if false, file will only be loaded to tester, not to be played at VSG until FrameTx() function is called
     * \return    Performs the same operations as \c SetWave, and additionally sets marker information in the VSG. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    //virtual int SetWave(iqapiModulationWave *modWave = NULL) //!< Downloads waveform to the VSG using data generated by the GenerateWave() function
    //{ 
    //    sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
    //    return IQAPI_HW_CONTROL_ERROR;
    //};    
    /*!< Downloads the \c iqapiModulationWave object currently pointed to by the \c hndl->wave object, to the VSGs in a test system. 
    \note If the number of streams is less than the number of test systems, zeros will be downloaded to the remaining VSG test system. Also, if the number of streams is greater than the number of test systems, the remaining streams will be ignored in the download. This function supports legacy IQview software \c .mod files as well as the IQapi software \c .mod files. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */

    virtual int FrameTx(int numFrames)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

    virtual bool TxDone(int *errCode)    //!< Check if the frame Tx mode is complete
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return false;
    };    

// **********************************************************************
// HW RX
// **********************************************************************
    virtual int SetRx() //!< Sets Rx configuration
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    int Capture(iqapiCapture **_data_)  //!< Performs a data capture
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    /*!< Performs a data capture using the current settings applied in \c hndl->rx. If successful, \c hndl->data will point to an \c iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */	
    virtual int Capture(iqapiCapture *userData, iqapiCapture **_data_) //!< Performs a data capture using the current settings applied to the  \c hndl->rx object
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    /*!< Performs a data capture using the current settings applied in \c hndl->rx. If successful, userData will point to an iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer)
    \note \c userData must be created before calling this function.
    */
    int Capture(int vsaNum, iqapiCapture **_data_) //!< Performs a data capture on a single VSA in an IQnxn test system configuration
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    /*!< In an IQnxn configuration, this function performs a data capture using the current settings applied in a \c hndl->rx object, on only the requested VSA (as specified by \c vsaNum). If successful, the \c hndl->data object will point to an \c iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */	
    int Capture(double sampleTimeSecs, iqapiCapture **_data_)	//!< Performs a data capture of length indicated in the \c sampleTimeSecs parameter
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' .Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40
    /*!< This function is implemented in the header file, and calls \c Capture(), but sets the sampling time first.
    */


    virtual int Capture(IQV_CAPTURE_TYPE_ENUM captureType, iqapiCapture **_data_)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40

    virtual int ContCapture(IQV_DC_CONT_ENUM mode, iqapiCapture **_data_, int vsaNum = 1) //!< Performs continuous data capture modes; this function is reserved for future use
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40

    virtual int Agc(bool AgcAll)    //!< Performs autorange, optionally, individually for all test systems.
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };     //!< Use to do normal capture or wide band capture for HT20 or HT40

// **********************************************************************
// Control information
// **********************************************************************
    virtual void GetObject(iqapiSignalData **_data_) 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
    };    
    virtual void SetObject(iqapiCaptureHT40Data3 *_dataHt40Data3_) 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
    };    
    virtual void GetObject(iqapiCaptureHT40Data3 **_dataHt40Data3_) 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
    };    
    
    virtual int GetMasterIP(char *_masterIP_, unsigned int _masterIP_size) 
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
    virtual int IsLicenseAvailable(IQV_LICENSE_TYPE licenseType, bool *returnResult)  //!< Checks if license is available
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    
	virtual bool FastLicenseChecker(IQV_LICENSE_TYPE licenseType, bool init = false)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return false;
    };    

    IQV_CAPTURE_DATA_HANDLING_ENUM GetCaptureDataHandling(); 
    void SetCaptureDataHandling(IQV_CAPTURE_DATA_HANDLING_ENUM _captureDataHandling_); 

// **********************************************************************
// Analysis function
// **********************************************************************
    virtual void SetObject(AnalysisBaseAbs *_analysisBaseAbs_)
    { 
        analysisBaseAbs = _analysisBaseAbs_;
    };    

// ****************************************************************    
// Internal Functions
// ****************************************************************    
    // ****************************************************************    
    // iqapiHndl Misc Functions
    // ****************************************************************    
    int   MiscMwCmd(char *cmd, int index=-1, double value=-1) //!<  This function is reserved for internal use
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

    int GetTemperature(IQV_VSA_NUM_ENUM vsaNum, double *paTemperature, double *ifTemperature, double *swTemperature, double *vsaGainTemperature, double *vsgGainOffsetTemperature)
    { 
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    };    

// **********************************************************************
// General function for SCPI tester only
// **********************************************************************
    virtual int ScpiCommandSetInBinary(const char *scpiCommand, unsigned int binary_data_size, const char* binary_data)  //!< Used SCPI 'SET' command contains binary data (SCPI command which doesn't have any response back from the tester) directly. 
    {
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    }
    virtual int ScpiCommandSet(char *scpiCommand) //!< Sending any SCPI command to tester
    {
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    }
    virtual int ScpiCommandQuery(char query[], unsigned int max_size, char response[], unsigned int *actual_size)
    {
        sprintf_s(lastErr, MAX_LEN_ERR_TXT, "Error: function '%s' Not implemented yet.\nfile name: %s\nline number: %d\n", __FUNCTION__, __FILE__, __LINE__);
        return IQAPI_HW_CONTROL_ERROR;
    }

// **********************************************************************
// Attribute
// **********************************************************************
public:
    int     lastErrCode;
    char    lastErr[MAX_LEN_ERR_TXT];

protected:
    bool     connectionStatus;      // connection status

private:
    AnalysisBaseAbs *analysisBaseAbs;
    IQV_CAPTURE_DATA_HANDLING_ENUM captureDataHandling;
};
