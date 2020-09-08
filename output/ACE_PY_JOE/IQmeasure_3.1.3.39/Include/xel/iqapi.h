/*!
    \file iqapi.h
*/
#pragma once
// ****************************************************************
// Include Files
// ****************************************************************
#include <stdlib.h>
#pragma warning( disable : 4251 )
#include "iqapiHndlBase.h"
#include "iqapiCommon.h"
#include "factoryBase.h"
#include "ControlBase.h"
#include "AnalysisBase.h"

// Start: Empty class pt99
#include "iqapiFM.h"
#include "iqapiHndlMatlab.h"
#include "DualHeadBase.h"
// End: Empty class

// ****************************************************************
// iqapi API Handle Class - Main Object
// ****************************************************************
//! Specifies parameters to control the test system hardware, perform signal analysis and generate waveform data.
class IQ_API iqapiHndl : public iqapiHndlBase
{
public:
    iqapiHndl(void);            //!< Constructor
    virtual ~iqapiHndl(void);   //!< Destructor

    // ****************************************************************
    // Function supported for Daytona
    // ****************************************************************    
    // ****************************************************************
    // Connection Handling Functions
    // ****************************************************************    
    /*!<Initializes a connection to a test system. The input must be a valid IP address, such as 192.168.100.254. This function returns 0 (IQAPI_ERR_OK) if successful; it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int ConInit(char *ip1, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA);                                    //!< Connects and initializes a single test system.		
    int ConInit(char *ip1, char *ip2, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA);                         //!< Connects and initializes to two tester systems.
    int ConInit(char *ip1, char *ip2, char *ip3, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA);              //!< Connects and initializes to three tester systems.
    int ConInit(char *ip1, char *ip2, char *ip3, char *ip4, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA);   //!< Connects and initializes to four tester systems.
    int ConOpen(char *ip1=NULL, char *ip2=NULL, char *ip3=NULL, char *ip4=NULL, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA);  //!< Connects to the test systems without initialize the test system. Not like, ConInit, this function (ConOpen) won't change the current hardware configuration.

    bool ConValid();    //!< Indicates valid, open connection.
    int ConClose();     //!< Closes one or more connections to the test systems.
    /*!< Closes a connection to a test system which was previously established with the \c ConInit function or opened with the \c ConOpen() function. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */  
    /*!< Checks the validity of a connection to a test system. This function returns a value of true if the connection is open and valid, or false if the connection is closed or invalid.
    */

    int GetAllVersions(char *version, int versionSize);     //!< Gets all versions related to software and hardware of the test system
    int GetIqapiVersion(char *version, int versionSize);    //!< Get IQapi release version information

    int GetModelNumber(char *buff, int bufflen, int testerNumber = 1);      //!< Gets the model version of the test system.
    int GetHardwareVersion(char *buff, int bufflen, int testerNumber = 1);  //!< Gets the hardware version of the test system.
    int GetFirmwareVersion(char *buff, int bufflen, int testerNumber = 1);  //!< Gets the firmware version of the test system.
    int GetCalibrationDate(char *buff, int bufflen, int testerNumber = 1);  //!< Gets the calibration date of the test system. Not applicable to Daytona tester
    int GetSerialNumber(char *buff, int bufflen, int testerNumber = 1);     //!< Gets the serial number of the tester. ex.: dtna-00015

    ////int IsLicenseAvailable(IQV_LICENSE_TYPE licenseType, bool *returnResult);  //!< Checks if license is available
    int IsLicenseAvailable(const char *licenseType, bool *returnResult);            //!< Check if SCPI tester license is available or not. 
    

    // ****************************************************************    
    // Set-up and Configuration Functions
    // ****************************************************************    
    int SetDefault();//!< Resets and initializes test systems
    /*!< Resets a test system, and initializes the associated objects in an \c iqapiHndl object. The test system and software are set to default conditions.
    \note This function does not have to be called after calling the \c ConInit() function. The \c ConInit() function resets and initializes the test system and therefore the SetDefault() function does not have to be called after calling the SetInit() function. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int SetTx(); 	//!< Sets hardware tx configuration
    /*!< Applies Tx settings to a test system, as configured in the \c iqapiTx object in \c iqapiHndl (\c hndl->tx). This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int SetRx(); //!< Sets hardware rx configuration
    /*!< Applies Rx settings to a test system, as configured in the \c iqapiRx object in \c iqapiHndl (\c hndl->rx). This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int SetTxRx(IQV_SET_TX_RX_TYPE setTxRx_e = IQV_SET_TX_RX);    //!< Sets hardwrae tx and rx configurations  
    /*!< Applies Tx and Rx settings to a test system, as configured in the \c iqapiTx and \c iqapiRx objects in \c iqapiHndl (\c hndl->tx and \c hndl->rx). This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int FrameTx(int numFrames);    //!< Starts frame Tx mode for the number of frames indicated in the \c numFrames parameter
    /*!< Transmits the number of frames indicated in the \c numFrames parameter from the test system VSG. 
    \n The \c numFrames parameter can have an integer value between 1 and 67108863.
    \n If \c numFrames=0, then the VSG  resumes continuous transmission. 
    \n This function returns a value of 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    bool TxDone(int *errCode);    //!< Indicates if the frame Tx mode is complete
     /*!< Retrieves the current Tx status of the VSGs in the test systems. This function returns true if a \c FrameTx() operation is done, or false if the VSGs are still transmitting (which will be the case during continuous Tx). The integer pointed to by \c errCode will become updated with the current error level, 0, (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int GetStatus(); //!< Retrieves hardware tx and rx configuration from the test system.
    /*!< Retrieves the current hardware status of a test system. The hardware-related objects in \c iqapiHndl will become updated with the current settings on the hardware. This could be used, for instance, to detect if another application has changed some settings on the system. This function returns a value of 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */ 
    int Agc(bool AgcAll);    //!< Performs autorange, optionally, individually for all test systems.
    /*!< Performs automatic gain control (AGC) on the VSAs in a test system. The \c iqapiRx objects of an \c iqapiHndl will get updated with the new settings, if successful. Setting the \c AgcAll value to \c TRUE causes an AGC to be performed on all the VSAs in the system; a value of \c FALSE causes an AGC to be performed only on the VSA Master. The remaining IQnxn Test Instrument VSAs will be set to the same value as the VSA Master. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer)
    */
    
    int LoadSignalFile(char *fileName); //!< Loads a signal file from PC system
    int SaveSignalFile(char *fileName, IQV_SAVE_SCPI_FILE_TYPE_ENUM fileType = IQV_SAVE_IQVSA_FILE); //!< Save a signal file to local PC system
    int LoadSignalFileScpi(char *fName); //!< Loads signal file from tester file system ( SCPI based tester only ) 

    int SetWave(char *fileName, bool autoPlay = true);      //!< Downloads waveform data to VSG loaded from a file 
    int SetWaveScpi(char *fileName, bool autoPlay = true);  //!< Downloads waveform data to VSG loaded from a file which is located in tester ( SCPI based tester only ) 
    /*!< 
     * \param[in] fileName signal file name to be loaded to tester
     * \param[in] autoPlay if true (default), loaded signal file will be loaded to tester and played automatically at VSG. if false, file will only be loaded to tester, not to be played at VSG until FrameTx() function is called
     * \return    Performs the same operations as \c SetWave, and additionally sets marker information in the VSG. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */

    // ****************************************************************    
    // Data Capture and Analysis Functions
    // ****************************************************************    
    int Capture();  //!< Performs a data capture
    /*!< Performs a data capture using the current settings applied in \c hndl->rx. If successful, \c hndl->data will point to an \c iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */	
    /*!< In an IQnxn configuration, this function performs a data capture using the current settings applied in a \c hndl->rx object, on only the requested VSA (as specified by \c vsaNum). If successful, the \c hndl->data object will point to an \c iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */	
    int Capture(double sampleTimeSecs);	//!< Performs a data capture of length indicated in the \c sampleTimeSecs parameter
    /*!< This function is implemented in the header file, and calls \c Capture(), but sets the sampling time first.
    */

    int Capture(iqapiCapture *userData); //!< Performs a data capture using the current settings applied to the  \c hndl->rx object
    /*!< Performs a data capture using the current settings applied in \c hndl->rx. If successful, userData will point to an iqapiCapture object which contains the sample data. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer)
    \note \c userData must be created before calling this function.
    */
    //Perform combined data capture (HT40 capture):
    int Capture(IQV_CAPTURE_TYPE_ENUM captureType);     //!< Use to capture HT40 

    int ContCapture(IQV_DC_CONT_ENUM mode, int vsaNum = 1); //!< Performs continuous data capture modes; this function is reserved for future use
    int Analyze(iqapiSignalData *userData, bool setDefault = true); //!< Analyzes the data from the user using the current settings
    /*!< Performs analysis on the \c iqapiCapture object pointed to by \c userData, using the analysis parameters pointed to by the \c hndl->analysis object. If successful, the \c hndl->results object will point to a result object (derived from iqapiResult) of the type specified by the \c hndl->analysis object. For instance, if after a data capture \c hndl-analysis points to an \c iqapiAnalysisOFDM object, \c hndl->analyze object will cause \c hndl->results object to point to an object of type \c iqapiResultOFDM. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */
    int Analyze(bool setDefault = true); //!< Analyzes the current capture buffer using the current settings
    /*!< Performs analysis on the \c iqapiCapture object pointed to by the \c hndl->data object, using the analysis parameters pointed to by the \c hndl->analysis object. If successful, the \c hndl->results object will point to a result object (derived from the \c iqapiResult object) of the type specified by the \c hndl->analysis object. For instance, if after a data capture the \c hndl-analysis object points to an \c iqapiAnalysisOFDM object, the \c hndl->analyze object will cause the \c hndl->results object to point to an object of type \c iqapiResultOFDM. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    * \param[in] setDefault Resets the current active analysis module to factory defaults
    */

    IQV_CAPTURE_DATA_HANDLING_ENUM GetCaptureDataHandling();                                //!< Get the current type of capture data handling
    void SetCaptureDataHandling(IQV_CAPTURE_DATA_HANDLING_ENUM _captureDataHandling_);      //!< It can control if the data shoudl be copied back to the hndl->data object. Usually, no need to copy the captured data back to the data object for saving time

    // ****************************************************************    
    // iqapiHndl Member Variables
    // ****************************************************************    
    iqapiRxBase			*rxBase;    //!< base class for Rx
    iqapiRx             *rx;        //!< Indicates test system Rx and VSA settings
    /*!< Represents the Rx settings in test system. The top level members represent parameters that apply to all VSAs in a test system. Members of the VSA object array apply uniquely to each test unit within a test system.
    */   

    iqapiTxBase			*txBase;    //!< base class for Tx 
    iqapiTx 			*tx;        //!< Indicates test system Tx and VSG settings

    iqapiTxXstream      *txXstream; //!< tx configuration for x stream tester

    /*!< Represents the Tx settings in a test system. The top level members represent parameters that apply to all VSGs in a LitePoint Test Instrument. Members of the vsg object array apply uniquely to each test unit within a test system.
    */
    iqapiCapture	*data;  //!< Indicates local data capture storage
    /*!< Stores captured sample data and is used as input to the analysis functions. */
    iqapiAnalysis	*analysis; //!< Indicates local analysis parameters
    /*!< Performs a specific type of analysis and returns a specific type of analysis result; used by \c hndl->Analyze().
    \note The \c iqapiAnalysis is a base class for the various Analysis classes and should NOT be used directly.
    */
    iqapiResult		*results; //!< Indicates local measurement results.
    /*!< If a call to \c hndl->Analyze() function is successful, the \c hndl->result object will point to a derived \c iqapiResult class. 
    \note the \c iqapiResult object is a base class for the various Result classes and should NOT be used directly.
    */
    int			    nTesters; //!< Indicates number of connected test systems.
    /*!< This field indicates the number of test systems to which a connection is open. This field should not be changed by the user.
    */ 

    // ****************************************************************    
    // The following functions are used for SCPI based tester only
    // For SCPI based tester with using iqapi structure
    // Map the left/right port to a specific SCPI based tester port
    // ****************************************************************    
    void SetLeftPort(LP_Port_Name_t _leftPort_);            //!< Set the left port of the tester to SCPI tester port
    LP_Port_Name_t GetLeftPort();                           //!< Get the left port of the tester to scpi tester port
    void SetRightPort(LP_Port_Name_t _rightPort_);          //!< Set the right port of the tester to SCPI tester port
    LP_Port_Name_t GetRightPort();                          //!< Get the right port of the tester to scpi tester port

    void SetDriverLogFile(int logOn, char driver_log_file[], char tcp_log_file[]);  //!< For generating log file from lower layer (instrument driver). 
    /*!< 
     * \param[in] logOn 1, turn on log; 0 turn off log, 
     * \param[in] driver_log_file instrument driver log file path and name
     * \param[in] tcp_log_file TCP layer log file path and name
    */


    // Internall used variables 
    FactoryBase     *hndlFactory;       //!< handle of factory to create control and analysis for differnet type of tester
    ControlBase     *hndlControl;       //!< handle for HW control
    AnalysisBase    *hndlAnalysis;      //!< handle for analysis 

    DualHeadBase    *pDualHead;         //!< Dual head object used for sharing tester between 2 different programs
	DualHeadBase    *pDualHeadToken;    //!< Dual head object used for sharing tester between 2 different programs  (exists for FW >= 1.10)


private: 
    bool        connected;  

    //IQV_CAPTURE_DATA_HANDLING_ENUM captureDataHandling; //!< Indicates captured data.
    /*!< IQV_DATA_IN_MATLAB&mdash;In some cases, the user does not have to pass the data back from MATLAB to the \c iqapi function to test the application. To save time, the captured data is stored in MATLAB. All subsequent operations will be carried out on the captured data in MATLAB.	
    \n IQV_DATA_IN_IQAPI&mdash;After data capture, a copy of the captured data can be obtained from the \c iqapi function in the object \c data
    */

    char *masterIP;
    void ResetLastErr();        // Reset the last error code and buffer

public:
    // ***********************************************************************************
    // For SCPI tester only :
    // ***********************************************************************************
    int GetSession(int *session, IQV_VSA_NUM_ENUM testerNumber = IQV_VSA_NUM_1);                            //!< Get session number. it is used to communicate with the tester through TCP manager layer
    int ScpiCommandSetInBinary(const char *scpiCommand, unsigned int binary_data_size, const char* binary_data);  //!< Used SCPI 'SET' command contains binary data (SCPI command which doesn't have any response back from the tester) directly. 
    int ScpiCommandSet(char *scpiCommand);                                                                  //!< Used SCPI 'SET' command (SCPI command which doesn't have any response back from the tester) directly.
    int ScpiCommandQuery(char query[], unsigned int max_size, char response[], unsigned int *actual_size);  //!< Used SCPI 'GET' command (SCPI command which have any response back from the tester) directly.

    // ***********************************************************************************
    // Internal use : 
    // ***********************************************************************************
    //bool    SetToken(unsigned int token, unsigned int value);
    int     Lock(IQV_LOCK_SESSION lock, unsigned int *lockResult);      //!< Used to lock/unlock/force unlock the tester so that other program cannot use it. It is  to make sure otehr program won't disturb the result of the current program

private:
    // ***********************************************************************************
    // For SCPI tester only :
    // ***********************************************************************************
    bool isConOpen;

public:
    // ***********************************************************************************
    // Obsolete : Not applicable to SCPI based tester. Exist for backward compatibility for now. 
    // ***********************************************************************************
    // Start Obsolete pt99
    // Note: The following functions defined are obsolete. Just for backward compilation purpose
    iqapiHndlFm *hndlFm;
    int ConInitBySerialNumber(char *ip1, char *sn1, char *sn2, char *sn3=NULL, char *sn4=NULL);   //!< For IQ2010 used as nxn system
    int ConInitBySerialNumber(char *ip1, char *sn1, IQV_CONNECTION_TYPE connectionType = IQV_CONNECTION_DAYTONA); //!< For IQ201x only. Allow to specify which tester ( if more than one tester connected to the PC) to be connecetd. Note: By default, the tester connected has the port number to be 4000. For connecting to the second tester, the port number has to be different than 4000. Ex., Say 4001, then, ip1 should be specified along with a port number. like, 127.0.0.1:4001
    int GetFpgaVersion(char *buff, int bufflen, IQV_FPGA_TYPE fpgaType, int testerNumber = 1);   //!< Gets FPGA version for the specified FPGA type 
    void SetLpcPath(char *litePointConnectionPath); //!< Set the path that is used to invoke LitePoint Connectivity server. Note: this LPC server is used to invoke fw_server.exe and GF_fwserver.exe for IQ201x in the same folder as LPC server
    char *GetLpcPath();                             //!< Get the path that is used to invoke LitePoint Connectivity Server.
    int SetWave(iqapiModulationWave *modWave = NULL); //!< Downloads waveform to the VSG using data generated by the GenerateWave() function
    // End Obsolete

private:
    // ****************************************************************    
    // iqapiHndl Firmware server
    // **************************************************************** 
    char            pbPort[6];      //<! N/A for SCPI based tester

};

// ***********************************************************************************
// Obsolete : Not applicable to SCPI based tester. Exist for backward compatibility for now. 
// ***********************************************************************************
// Start Obsolete pt99 
// Note: The following functions defined are obsolete ( NOT IMPLEMENTED ). Just for backward compilation purpose 
IQ_API int iqapiInit(bool enableJvmAndJit = true);
IQ_API int iqapiTerm(void);
IQ_API int iqapiPlot(int figNum, double *x, double *y, int length, char *plotArgs, char *title, char *xtitle, char *ytitle, int keepPlot=0);
IQ_API int iqapiVersion(char *versionStr, int nMaxChars);
IQ_API_EXT_C int iqapiSetAnalysisMode(const char *key);  //!< Internal use only
// End Obsolete
