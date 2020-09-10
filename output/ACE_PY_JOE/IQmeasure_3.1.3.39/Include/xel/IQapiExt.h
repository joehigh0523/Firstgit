/*! \mainpage IQapi Extension DLL (IQapiExt)
 *
 * The IQapi Extension DLL makes the functionality of MPS IF to users by exporting a few high
 * level functions.
 *
 * \section revision_sec Revision History
 *
 * \subsection revision_1_8_56_1 1.8.56.1
 * Date: 03/11/2010
 * MpsIf version: 0.0.7.2
 * IQapi version: 1.8.56
 *
 * \subsection revision_1_8_53_1 1.8.53.1
 * Date: 02/23/2010
 * MpsIf version: 0.0.7.2
 * IQapi version: 1.8.53
 *
 * \subsection revision_1_8_52_2 1.8.52.2
 * Date: 02/03/2010
 * MpsIf version: 0.0.7.2
 * IQapi version: 1.8.52
 *
 * \subsection revision_1_8_52_1 1.8.52.1
 * Date: 02/02/2010
 * MpsIf version: 0.0.7.2
 * IQapi version: 1.8.52
 *
 * \subsection revision_1_8_23_1 1.8.23.1
 * Date: 8/05/2009
 * MpsIf version: 0.0.6.4.0
 * IQapi version: 1.8.23
 *
 * \subsection revision_1_6_2_1 1.6.2.1
 * Date: 2/09/2009
 * MpsIf version: 0.0.6.4.0
 * IQapi version: 1.6.2
 *
 */

/*! \file IQapiExt.h
 * \brief IQapiExt DLL Interface functions 
 */ 

#ifndef _IQAPIEXT_H_
#define _IQAPIEXT_H_

/* IQapiExt version follows the IQapi version by appending its own number.
 * For example, if IQapi version is 1.8.65, IQapiExt version will be:
 *      1.8.65.n IQapiExt yyyy-mm-dd
 *      Note: n starts with 1
 */
#define IQAPIEXT_VERSION                "2 (2010-06-18)\n"

#if !defined (__cplusplus)
    #define IQAPI_EXT_API extern
#elif !defined (WIN32)
    #define IQAPI_EXT_API extern "C"
#elif defined(IQapiExt_EXPORTS)
    #define IQAPI_EXT_API extern "C" __declspec(dllexport)
#else
    #define IQAPI_EXT_API extern "C" __declspec(dllimport) 
#endif

#define MAX_MPTA_PORTS     4

#ifndef ON
#define ON 1
#endif

#ifndef OFF
#define OFF 0
#endif

IQAPI_EXT_API typedef enum _IQAPI_EXT_ERROR_CODES
{
	IQEXT_ERR_OK,
	IQEXT_ERR_NULL_POINTER,
    IQEXT_ERR_NULL_HNDL,
    IQEXT_ERR_MPSIF_FAILED_TO_INITIALIZE,
	//IQEXT_ERR_NO_CONNECTION,
	IQEXT_ERR_NOT_INITIALIZED,
	//IQEXT_ERR_SAVE_WAVE_FAILED,
	//IQEXT_ERR_LOAD_WAVE_FAILED,
	IQEXT_ERR_SET_TX_FAILED,
	//IQEXT_ERR_SET_WAVE_FAILED,
	//IQEXT_ERR_SET_RX_FAILED,
	IQEXT_ERR_CAPTURE_FAILED,
	//IQEXT_ERR_NO_CAPTURE_DATA,
	//IQEXT_ERR_VSA_NUM_OUT_OF_RANGE,
	//IQEXT_ERR_ANALYSIS_FAILED,
	//IQEXT_ERR_NO_VALID_ANALYSIS,
    IQEXT_ERR_MPTA_PORT_EXCEED_RANGE,
    IQEXT_ERR_MPTA_CANNOT_BE_ENABLED,
    IQEXT_ERR_MPTA_SWITCH_CAPTURE_FAILED,
    IQEXT_ERR_NO_MPTA_FOUND,
	IQEXT_ERR_FAILED_TO_CONNECT_MPTA,
	IQEXT_ERR_VSG_PORT_IS_OFF,
	IQEXT_ERR_MULTISEGMENT_WAVELOAD_FAILED,
	IQEXT_ERR_BUILD_SEQUENCE_ERROR,
	IQEXT_ERR_SEGMENT_OUT_OF_RANGE,
    IQEXT_ERR_SEGMENT_COUNT_OUT_OF_RANGE,
    IQEXT_ERR_TOO_MANY_POWER_LEVELS,
    IQEXT_ERR_TOO_MANY_SEQ_STEPS,
    IQEXT_ERR_MAXIMUM_POWER_OUT_OF_RANGE,
    IQEXT_ERR_POWER_RANGE_OUT_OF_RANGE,
    //IQEXT_ERR_NO_MOD_FILE_LOADED,
    //IQEXT_ERR_NO_CONT_FOR_MULTI_SEGMENT,
    IQEXT_ERR_FAILED_TO_CHANGE_POWER_LEVEL,
    IQEXT_ERR_PL_OFFSET_OUT_OF_RANGE,
    IQEXT_ERR_VSA_SEQUENCE_STILL_RUNNING,
	IQEXT_ERR_VSA_SEQUENCE_NOT_INITIATED,
	IQEXT_ERR_GENERAL_ERR
} IQAPI_EXT_ERROR_CODES;

IQAPI_EXT_API typedef enum tag_IQEXT_MP_TYPE
{
    IQEXT_MP_NA,                    /*!< NO MP available*/
    IQEXT_MP_PB,                    /*!< Pebble Beach*/        
    IQEXT_MP_ET,                    /*!< IQexpress/IQturbo*/
    IQEXT_MP_MPTA,                  /*!< MPTA*/
    IQEXT_MP_MIMO,                  /*!< IQmimo*/
    IQEXT_MP_MAX
} IQEXT_MP_TYPE;

//! Return IQapiExt Version
/*!
 * \param[out] buffer The buffer that holds the IQapiExt version info
 * \param[in] buf_size The buffer size
 *
 * \return IQEXT_ERR_OK if buffer is valid
 * \return IQEXT_ERR_NULL_POINTER is buffer is a NULL pointer
 */
IQAPI_EXT_API int IQEXT_GetVersion(char *buffer, int buf_size);

//! Initialize IQapiExt
/*!
 * \param[in] hndl The instance of iqapiHndl instantiated in IQmeasure
 *
 * \return IQEXT_ERR_OK if the specified iqext_hndl is not NULL; otherwise IQEXT_ERR_NULL_HNDL
 */
IQAPI_EXT_API int IQEXT_Init(iqapiHndl *hndl);

//! Initialize MpsIf
/*!
 * \param[out] mpType Returns the MP type:
 *                      - IQEXT_MP_PB: Pebble Beach (IQ201x) is present
 *                      - IQEXT_MP_ET: IQexpress or IQturbo is present
 *                      - IQEXP_MP_MIMO: IQmimo is present
 *                      - IQEXP_MP_NA: No MP is available
 * \param[out] sn Pointer to a buffer for storing the MP serial number (For IQEXT_MP_PB, the S/N is the same as the PB tester)
 * \param[in] snBufferLen Indicates the serial number buffer length
 *
 * \return IQEXT_ERR_OK if no error occurs; otherwise TODO: add error code 
 */
IQAPI_EXT_API int IQEXT_MpsInitialize(IQEXT_MP_TYPE *mpType, char *sn, int snBufferLen);

// Error handling
IQAPI_EXT_API char *IQEXT_GetErrorString(int err);
IQAPI_EXT_API char *IQEXT_GetIQapiHndlLastErrMsg();


// TODO: remove skipCount. hardcode it in code to be 10

// TODO: since rx.ampl is in _SetVsa(), how do we deal with power differences in ports
//       possible workaround to have rx.ampl in SetVsa be the maximum of all ports

//! Setup MPTA for switch capture
/*!
 * \param[in] skipCount The number of frames to be skipped before capture. Needs to be equal to or greater than 1
 * \param[in] samplingTimeSecs The capture duration in second for the capture on each port. <=1023us
 * \param[in] portList An array specifying the list of ports at which captures will occur sequentially. (1-4)
 * \param[in] portCount Number of ports included in portList
 *
 * \return IQEXT_ERR_OK if the switch capture is successful; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_MptaSetupSwitchCapture(int skipCount,
                                               double samplingTimeSecs,
                                               int portList[], int portCount);


IQAPI_EXT_API int IQEXT_MpsTxSequenceBuild(double	powerLeveldBm[],
                                           int	    captureLengthUs[],  
                                           int		preTriggerTimeUs[],
                                           int	    skipPktCnt[],
                                           int	    captureCnt[],
                                           int		arraySize,
                                           int      rfPort,
                                           double	triggerLeveldBm);
IQAPI_EXT_API int IQEXT_MpsInitiateCapture(void);
IQAPI_EXT_API int IQEXT_MpsFinishCapture(void);

IQAPI_EXT_API int IQEXT_DBG_EnableVsaSequenceInVsgSequence(int enable=0);
IQAPI_EXT_API int IQEXT_DBG_EnableLoopbackTest();
IQAPI_EXT_API int IQEXT_DBG_GetVsaSequenceStepGainError(double stepGainError[], int arraySize);
IQAPI_EXT_API int IQEXT_DBG_KeepVsaVsgInSequenceMode(int enable);

//TODO: not expose MSWF

//! Load multi-segment wavefile to VSG
/*!
 * \param[in] sigFile A .mod or .sig file that consists of multi-segment waveforms
 * \param[in] markerFile A text file that describes the marker positions 
 *
 * \return IQEXT_ERR_OK if the multi-segment wavefile has been loaded;; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_LoadMultiSegmentWaveFile(const char *sigFile, const char *markerFile);

IQAPI_EXT_API int IQEXT_VsgSingleSegmentPlay(int segmentIndex, int packetCount);
IQAPI_EXT_API int IQEXT_VsgSingleSegmentStop();


//! Run RX PER using MPS
/*!
 * \param[in] segmentIndex[] An array each element of which specifies a segment index (0 based) of the multi-segment wavefile
 * \param[in] powerLevelStart[] An array each element of which specifies the start of power level (dBm at DUT) for 
 *                              each corresponding segment
 * \param[in] powerLevelStop[] An array each element of which specifies the stop of power level (dBm at DUT ports) for 
 *                             each corresponding segment
 * \param[in] step[] An array each element of which specifies the increment of power level (dB) for 
 *                   each corresponding segment.  Minimum step is 0.5dB.
 * \param[in] packetCount[] An array each element of which specifies the number of packets to be transmitted for
 *                          each corresponding segment.  Maximum number of packets is 32768.
 * \param[in] portMaskList[] An array specifying the list of port masks which are used for RX PER testing. 
 * \param[in] arraySize Number of elements in the array segmentIndex[], powerLevelStart[], powerLevelStop[], 
 *            step[], packetCount[], and portMaskList[].
 *
 * \return IQEXT_ERR_OK if the RX PER is successful; otherwise call IQEXT_GetErrorString() for detailed error message.
 *
 * \remark 
 *         -# All power levels are specified at the 4 DUT ports of the tester
 *         -# In most cases, the stop power level would be lower than the start power level, but it could be
 *            higher than the start power level.  In either way, step would be relative, meaning always positive.
 *         -# If only one power level is interested for RX PER, set step to 0, or make the powerLevelStop be qual 
 *            to powerLevelStart.
 *         -# The maximum accepted power range is 45dB.  If more-than-45dB range is required, please call this
 *            function twice, one on the lower end, and one on the higher range.
 *         -# The highest power level at any DUT port is limited to -14dBm.
 *         -# Every element of portMaskList[] is a bit mask determining one or more ports will be used.
 *               - Bit 0 is for DUT Port 1
 *               - Bit 1 is for DUT Port 2
 *               - Bit 2 is for DUT Port 3
 *               - Bit 3 is for DUT Port 4
 *               .
 *         For example, {1, 2, 3} will perform RX PER in the order of Port 1, Port 2, and Port 1+2.
 *         When the RX PER is performed on Port 1, Port 2, 3, and 4 are set to the "OFF" state (maximum attenuation).
 *         When the RX PER is performed on Port 1+2, Port 3 and 4 are set to the "OFF" state (maximum attenuation).
 *         -# If VSG is required to transmit continuously, please follow the procedures below:
 *            - Call IQEXT_EnableVsgRF(0) to turn off the VSG RF output
 *            - Call IQEXT_SetVsgModulation() to load the .mod file
 *            - Set portMaskList[0] to include the ports from which signal will come
 *            - Set powerLevelStart[0] to the desired power level
 *            - Set packetCount[0] to 0
 *            - Call IQEXT_MpsRxPer() with arraySize=1.  Other parameters will be ignored.
*/
IQAPI_EXT_API int IQEXT_MpsRxPer(int    segmentIndex[],
                                 double powerLevelStart[], 
                                 double powerLevelStop[], 
                                 double step[],
                                 int    packetCount[],
                                 int    portMaskList[],
                                 int    arraySize
                                 );

IQAPI_EXT_API int IQEXT_MpsRxPer_PB(int    segmentIndex[],
                                    double powerLevelStart[], 
                                    double powerLevelStop[], 
                                    double step[],
                                    int    packetCount[],
                                    int    rfPort[],
                                    int    arraySize,
                                    double ackTriggerLeveldBm,
                                    bool   bNpdMode = false
                                    );

IQAPI_EXT_API int IQEXT_MpsRxPer_ET(int    segmentIndex[],
                                    double powerLevelStart[], 
                                    double powerLevelStop[], 
                                    double step[],
                                    int    packetCount[],
                                    int    portMaskList[],
                                    int    arraySize,
                                    double ackTriggerLeveldBm,
                                    double *lowestTriggerLeveldBm=NULL,
                                    bool   bNpdMode = false
                                    );

//TODO: to make an simplified version for MPTA to transmit power at specified ports
//      consider using rfPowerLevel in _SetVsg() 
//      consider using _SetFrameCnt() for number of packet to transmit

//! Retrieve RX PER results from last run of IQEXT_MpsRxPer
/*!
 * \param[in] stepIndex Specifies the step number of total steps included in IQEXT_MpsRxPer.  0 based.
 * \param[out] actualPowerLevel Returns the actual power levels for each enabled port at each power level
 * \param[out] packetSent Returns packets sent at each power level
 * \param[out] ackReceived Returns ACKs received at each power level
 * \param[out] per Returns the PER result at each power level
 * \param[out] arraySize Specifies the array size, meaning number of power levels.
 *
 * \return IQEXT_ERR_OK if the switch capture is successful; otherwise call IQEXT_GetErrorString() for detailed error message.
 *
 * \remark After finishing IQEXT_MpsRxPer(), you call IQEXT_MpsGetRxPerResults() to retrive the PER results.
 *        Each one of the total steps, specified by arraySize in IQEXT_MpsRxPer(), will correspond to
 *        a range of power levels, determined by powerLevelStart, powerLevelStop, and step in IQEXT_MpsRxPer(),
 *        and this value will be returned by arraySize in IQEXT_MpsGetRxPerResults().
 *        The returned arrays have the following sizes:
 *           - actualPowerLevel[arraySize*4]:  For the unused ports, the value is -999.00
 *           - packetSent[arraySize]
 *           - ackReceived[arraySize]
 *           - per[arraySize]
*/
IQAPI_EXT_API int IQEXT_MpsGetRxPerResults(int    stepIndex,
                                           double actualPowerLevel[], 
                                           int    packetSent[], 
                                           int    ackReceived[],
                                           double per[],
                                           int    *arraySize
                                           );
IQAPI_EXT_API int IQEXT_MpsGetRxPerResults_PB(int    stepIndex,
                                              double actualPowerLevel[], 
                                              int    packetSent[], 
                                              int    ackReceived[],
                                              double ackRespMax[],
                                              double ackRespMin[],
                                              double per[],
                                              int    *arraySize
                                              );
IQAPI_EXT_API int IQEXT_MpsGetRxPerResults_ET(int    stepIndex,
                                              double actualPowerLevel[], 
                                              int    packetSent[], 
                                              int    ackReceived[],
                                              double ackRespMax[],
                                              double ackRespMin[],
                                              double per[],
                                              int    *arraySize
                                              );


IQAPI_EXT_API int IQEXT_MpsResetRxPerResults();

//! Set Power Level Offset between 4 DUT ports for IQEXT_MpsRxPer()
/*!
 * \param[in] port1 Power level offset (dB) for DUT port 1 
 * \param[in] port2 Power level offset (dB) for DUT port 2 
 * \param[in] port3 Power level offset (dB) for DUT port 3 
 * \param[in] port4 Power level offset (dB) for DUT port 4 
 *
 * \remark Without specifying those offsets, IQEXT_MpsRxPer() will apply same power levels to all 4 DUT ports.  
 *         However, if the individual DUT ports require different power levels, IQEXT_MpsSetDutPortPowerLevelOffset()
 *         can be used to adjust the power level for each port by introducing an offset.
 *         New offset settings will take effective for next call of IQEXT_MpsRxPer().
 *         The allowed offset range is +/-6dB
 *         Note: 
 *            - The offsets will not take effect until the next call of IQEXT_MpsRxPer
 *            - This function has no effect on IQEXT_SetVsgCw()
 * \return IQEXT_ERR_OK if offsets are set; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_MpsSetDutPortPowerLevelOffset(double port1, double port2, double port3, double port4);

//! Retrieve the Serial Number of MPTA connected
/*!
 * \param[out] serialNumber A pointer to the buffer that will hold the serial number
 * \param[in] bufSize The buffer size for storing the serial number
 *
 * \return IQEXT_ERR_OK if the serial number has been sucessfully retrieved; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_MptaGetSerialNumber(char *serialNumber, int bufSize);

//! Set MPTA attenuation
/*!
 * \param[in] port Port number of MPTA (1-4)
 * \param[in] attn The attenuation (dB) to set
 * \param[out] error The error between the actual attenuation and required attenuation (dB)
 *
 * \return IQEXT_ERR_OK if the serial number has been sucessfully retrieved; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_MptaSetAtta(int port, double attn, double *error);

//! Set Multi-port CW power
/*!
 * \param[in] rfFreqHz Center frequency (Hz)
 * \param[in] cwPower The CW power (dBm)
 *
 * \return IQEXT_ERR_OK if the serial number has been sucessfully retrieved; otherwise call IQEXT_GetErrorString() for detailed error message.
 */
IQAPI_EXT_API int IQEXT_MpsSetVsgCW(double rfFreqHz, double cwPower);

//TODO: Have SetVsgCw work with MPTA
//      Have another function return acutal transmitted power per port

// Debugging Functions


//! Toggle the display of MPTA debugging info
/*!
 * \param[in] enableDebug Turn on/off (true/false) the MPTA debugging info
 *
 * \return IQEXT_ERR_OK
 */
IQAPI_EXT_API int IQEXT_MptaPrintDebug(bool enableDebug);

IQAPI_EXT_API int IQEXT_StartIQapiExtTimer();
IQAPI_EXT_API int IQEXT_StopIQapiExtTimer();
IQAPI_EXT_API int IQEXT_ReportTimerDurations();
IQAPI_EXT_API int IQEXT_VsaSingleCapture(double rfAmplDb, double samplingTimeSecs, int triggerType=6, double sampleFreqHz=80e6, int ht40Mode=OFF);
IQAPI_EXT_API int IQEXT_MpsSetAttn(double freqInMhz, int rfPort, double *attn);
IQAPI_EXT_API int IQEXT_MpsRxPer_Stop_ET(void);

#endif // #if !defined(_IQAPIEXT_H_)