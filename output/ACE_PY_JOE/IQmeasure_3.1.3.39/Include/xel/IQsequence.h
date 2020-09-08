/*! \mainpage IQsequence Library Documentation
 *
 * The IQsequence Library adds MPS functionalities to IQmeasure
 *
 * \section revision_sec Revision History
 *
 * \subsection revision_1_8_56_2 1.8.56.3 MPS
 * Date: Apr 13, 2010
 *   -# IQapi version: 1.8.56
 *
 */

/*! \file IQsequence.h
 * \brief IQsequence Library Interface functions 
 */ 

/*! @defgroup group1 How to make an accurate measurement?
 * \image html AmplSweepWithIdealSignal.gif "Sweeping ampl Setting with Ideal Signal" width=300
 */

/*! @defgroup group2 How to re-use the capture for multiple analysis?
 * 
 */

/*! @defgroup group3 How to transmit a waveform continuously?
 * 
 */

/*! @defgroup group4 What is Packet Engine?
 * 
 */

#pragma once

#if !defined (WIN32)
    #define IQSEQUENCE_API extern "C"
#elif defined(IQMEASURE_EXPORTS)
    #define IQSEQUENCE_API extern "C" __declspec(dllexport)
#else
    #define IQSEQUENCE_API extern "C" __declspec(dllimport) 
#endif

#define MAX_MPTA_PORTS     4
#if !defined(MAXERRORLENGTH)
    #define MAXERRORLENGTH     1000
#endif

#ifndef ON
#define ON 1
#endif

#ifndef OFF
#define OFF 0
#endif


//IQSEQUENCE_API enum LP_MEASURMENT_TYPE_ENUM
//{
//    TYPE_SCALAR   = 1,                       /*!< The measurement result is of scalar type*/ 
//    TYPE_VECTOR,                             /*!< The measurement result is of vector type*/
//    TYPE_STRING,                             /*!< The measurement result is of string type*/
//    TYPE_INVALID                             /*!< Invalid type*/
//};
//

//IQSEQUENCE_API enum LP_MEASUREMENT_VSG_MODE
//{
//    VSG_NO_MOD_FILE_LOADED = 0,             /*!< No MOD file has been loaded*/
//    VSG_SINGLE_MOD_FILE,                    /*!< Single MOD file has been loaded*/
//    VSG_MULTI_SEGMENT_MOD_FILE,             /*!< Multi-segment MOD file has been loaded*/
//    VSG_INVALID_MODE                        /*!< Invalid VSG mode*/
//};




//IQSEQUENCE_API enum IQMEASURE_ERROR_CODES
//{
//	ERR_OK,
//	ERR_NO_CONNECTION,
//	ERR_NOT_INITIALIZED,
//	ERR_SAVE_WAVE_FAILED,
//	ERR_LOAD_WAVE_FAILED,
//	ERR_SET_TX_FAILED,
//	ERR_SET_WAVE_FAILED,
//	ERR_SET_RX_FAILED,
//	ERR_CAPTURE_FAILED,
//	ERR_NO_CAPTURE_DATA,
//	ERR_VSA_NUM_OUT_OF_RANGE,
//	ERR_ANALYSIS_FAILED,
//	ERR_NO_VALID_ANALYSIS,
//    ERR_MPTA_PORT_EXCEED_RANGE,
//    ERR_MPTA_CANNOT_BE_ENABLED,
//    ERR_MPTA_SWITCH_CAPTURE_FAILED,
//    ERR_NO_MPTA_FOUND,
//    ERR_NO_IQ2010_FOUND,
//	ERR_MPSIF_FAILED_TO_INITIALIZE,
//	ERR_FAILED_TO_CONNECT_MPTA,
//	ERR_VSG_PORT_IS_OFF,
//	ERR_MULTISEGMENT_WAVELOAD_FAILED,
//	ERR_BUILD_SEQUENCE_ERROR,
//	ERR_SEGMENT_OUT_OF_RANGE,
//    ERR_SEGMENT_COUNT_OUT_OF_RANGE,
//    ERR_TOO_MANY_POWER_LEVELS,
//    ERR_TOO_MANY_SEQ_STEPS,
//    ERR_MAXIMUM_POWER_OUT_OF_RANGE,
//    ERR_POWER_RANGE_OUT_OF_RANGE,
//    ERR_NO_MOD_FILE_LOADED,
//    ERR_NO_CONT_FOR_MULTI_SEGMENT,
//    ERR_PL_OFFSET_OUT_OF_RANGE,
//    ERR_MEASUREMENT_NAME_NOT_FOUND,
//    ERR_INVALID_ANALYSIS_TYPE,
//    ERR_NO_ANALYSIS_RESULT_AVAILABLE,
//    ERR_NO_MEASUREMENT_RESULT,
//    ERR_INVALID_RF_PORT,
//    ERR_INVALID_DATA_CAPTURE_RANGE,
//	ERR_VSA_SEQUENCE_STILL_RUNNING,
//	ERR_VSA_SEQUENCE_NOT_INITIATED,
//	ERR_IQAPIEXT_ERROR,
//	ERR_FM,
//	ERR_GPS,
//    ERR_GENERAL_ERR
//};


IQSEQUENCE_API enum IQSEQUENCE_ERROR_CODES
{
    ERR_SEQ_OK = 0,
    ERR_MULTISEGMENT_WAVELOAD_FAILED,
    ERR_INVALID_RF_PORT,
    ERR_NO_IQ2010_FOUND,
    ERR_NO_MPTA_FOUND,
    ERR_VSA_SEQUENCE_STILL_RUNNING,
    ERR_VSA_SEQUENCE_NOT_INITIATED,
    ERR_IQAPIEXT_ERROR
};

/******************/
/* Error handling */
/******************/
IQSEQUENCE_API char *LP_GetErrorString(int err);
IQSEQUENCE_API char *LP_GetIQapiHndlLastErrMsg();



//! Initializes MPS
/*!
 * \return 0 if MPS was initialized OK; non-zero indicates MPS failed to initialize.
 * \remakr This function has to be called right after LP_InitTester()
 */
IQSEQUENCE_API int  LP_MpsInit(void);


//! Return IQsequence Version Info
/*!
 * \return 0 if MPS was initialized OK; non-zero indicates MPS failed to initialize.
 * \remakr This function is to replace LP_GetVersion()
 */
IQSEQUENCE_API int LP_MpsGetVersion(char *buffer, int buf_size);


//! Setup and perform switch capture for MIMO
/*!
 * \param[in] skipCount The number of frames to be skipped before capture. Needs to be equal to or greater than 1
 * \param[in] samplingTimeSecs The capture duration in second for the capture on each port. <=1023us
 * \param[in] portList An array specifying the list of ports at which captures will occur sequentially. (1-4)
 * \param[in] portCount Number of ports included in portList
 *
 * \return ERR_OK if the switch capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MptaSetupSwitchCapture(int skipCount,
                                            double samplingTimeSecs,
                                            int portList[], 
                                            int portCount);

//IQSEQUENCE_API int LP_MpsSetupSwitchCapture(int skipCount,
//                                           double samplingTimeSecs,
//                                           int portList[], 
//                                           int portCount);




//! Enable or disable the TX sequence during RX sequence (for loopback test)
/*!
 * \param[in] enable 1-Enable TX sequence during RX sequence;0-Disable TX sequence during RX sequence
 *
 *
 * \remark 
 *          -# This function is made for the IQ2010 loopback test only
 *			-# When enabled, LP_MpsRxPer_PB() will also execute a TX sequence which is meant to capture the packets from VSG
 *			-# The TX sequence can be configured by calling LP_MpsTxSequenceBuild() prior
 *
 * \return ERR_OK if the call is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_DBG_EnableVsaSequenceInVsgSequence(int enable=0);

IQSEQUENCE_API int LP_DBG_EnableLoopbackTest();

IQSEQUENCE_API int LP_DBG_GetVsaSequenceStepGainError(double stepGainError[], int arraySize);


//! Keep VSA/VSG in MPS mode or not
/*!
 * \param[in] enable 1-Keep VSA/VSG in MPS mode;0-Do NOT keep VSA/VSG in MPS mode
 *
 *
 * \remark 
 *          -# When VSA/VSG are kept in MPS mode, the very first TX sequence/RX sequence will bring VSA/VSG into MPS mode,
 *             but will not exit the MPS mode, so the following TX sequences/RX sequences will not need to spend time
 *             to bring VSA/VSG in MPS mode
 *			-# Otherwise, every TX sequence/RX sequence will bring VSA/VSG into MPS mode at the beginning and exit MPS
 *             mode at the end
 *
 * \return ERR_OK if the call is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_DBG_KeepVsaVsgInSequenceMode(int enable=0);


//! Build MPS VSA Sequence
/*!
 * \param[in] powerLeveldBm[] An array each element of which specifies the peak power level (dBm) at the RF ports
 * \param[in] captureLengthUs[] Capture length in us
 * \param[in] preTriggerTimeUs[] Pre-trigger time in us
 * \param[in] skipPktCnt[] Skip count before capture
 * \param[in] captureCnt[] Capture count
 * \param[in] arraySize Number of elements in the array powerLeveldBm[], captureLengthUs[], preTriggerTimeUs[], 
 *            skipPktCnt[], and captureCnt[].
 * \param[in] rfPort RF port. Valid values are 2 (RF1) and 3(RF2).
 * \param[in] triggerLeveldBm Trigger level in dBm.
 *
 * \return ERR_OK if the RX PER is successful; otherwise call LP_GetErrorString() for detailed error message.
 *
 * \remark 
 *         -# All power levels are specified at the 4 DUT ports of the tester
 *         -# In most cases, the stop power level would be lower than the start power level, but it could be
 *            higher than the start power level.  In either way, step would be relative, meaning always positive.
 *         -# If only one power level is interested for RX PER, set step to 0, or make the powerLevelStop be qual 
 *            to powerLevelStart.
 *         -# Every element of portMaskList[] is either RF1 or RF2
 *               - 2 for RF1 (or LEFT)
 *               - 3 for RF2 (or Right)
 *               .
 *         -# Every element of portMaskList[] is either RF1 or RF2
 *
 * \return ERR_OK if the switch capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MpsTxSequenceBuild(double	powerLeveldBm[],
                                        int	    captureLengthUs[],  
                                        int	    preTriggerTimeUs[],
                                        int	    skipPktCnt[],
                                        int	    captureCnt[],
                                        int	    arraySize,
                                        int     rfPort,
                                        double	triggerLeveldBm);



//! Initiate MPS VSA Sequence (IQ2010 and IQexpress/IQturbo)
/*!
 * \remark 
 *		This function starts executing the VSA sequence defined by LP_MpsTxSequenceBuild() and returns,
 *		while the tester, IQ2010, or IQexpress/IQturbo, is performing captures in the background
 *
 * \return ERR_OK if the switch capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MpsInitiateCapture(void);



//! Finish MPS VSA Sequence
/*!
 * \remark 
 *		This function transfers the captures from the tester to PC.
 *		It will wait for the VSA sequence to finish if the sequence is still running when issued.
 *
 * \return ERR_OK if the switch capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MpsFinishCapture(void);


//! Select a portion of the capture for analysis
/*!
 * \param[in] startPositionUs Start position in the capture (us) for analysis
 * \param[in] lengthUs The length (us) in the capture for analysis
 *
 * \remark This function does not support IQnxn or IQnxn_plus
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MpsSelectCaptureRange(double startPositionUs, double lengthUs);


//! Load multi-segment wavefile to VSG
/*!
 * \param[in] sigFile A .mod or .sig file that consists of multi-segment waveforms
 * \param[in] markerFile A text file that describes the marker positions 
 *
 * \return ERR_OK if the multi-segment wavefile has been loaded;; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_LoadMultiSegmentWaveFile(const char *sigFile, const char *markerFile, int reloadWave = 0);

IQSEQUENCE_API int LP_VsgSingleSegmentPlay(int segmentIndex, int packetCount);
IQSEQUENCE_API int LP_VsgSingleSegmentStop();


//! Run RX PER using MPTA
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
 * \return ERR_OK if the RX PER is successful; otherwise call LP_GetErrorString() for detailed error message.
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
 *            - Call LP_EnableVsgRF(0) to turn off the VSG RF output
 *            - Call LP_SetVsgModulation() to load the .mod file
 *            - Set portMaskList[0] to include the ports from which signal will come
 *            - Set powerLevelStart[0] to the desired power level
 *            - Set packetCount[0] to 0
 *            - Call LP_MptaRxPer() with arraySize=1.  Other parameters will be ignored.
*/
//IQSEQUENCE_API int LP_MpsRxPer(int    segmentIndex[],
//                              double powerLevelStart[], 
//                              double powerLevelStop[], 
//                              double step[],
//                              int    packetCount[],
//                              int    portMaskList[],
//                              int    arraySize
//                              );
//
////! LP_MptaRxPer -- Obsoleted
///*!
// * \remark LP_MptaRxPer() has benn renamed to LP_MpsRxPer()
// */
IQSEQUENCE_API int LP_MptaRxPer(int    segmentIndex[],
                              double powerLevelStart[], 
                              double powerLevelStop[], 
                              double step[],
                              int    packetCount[],
                              int    portMaskList[],
                              int    arraySize
                              );



//! IQ201X ACK-based RX PER Test
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
 * \param[in] rfPort[] An array specifying the RF ports used for RX PER testing. 
 * \param[in] arraySize Number of elements in the array segmentIndex[], powerLevelStart[], powerLevelStop[], 
 *            step[], packetCount[], and portMaskList[].
 *
 * \return ERR_OK if the RX PER is successful; otherwise call LP_GetErrorString() for detailed error message.
 *
 * \remark 
 *         -# arraySize is always 1 for IQ2010.  Parameters are declared as arrays for consistence with IQmimo
 *         -# All power levels are specified at the 4 DUT ports of the tester
 *         -# In most cases, the stop power level would be lower than the start power level, but it could be
 *            higher than the start power level.  In either way, step would be relative, meaning always positive.
 *         -# If only one power level is interested for RX PER, set step to 0, or make the powerLevelStop be qual 
 *            to powerLevelStart.
 *         -# Every element of portMaskList[] is either RF1 or RF2
 *               - 2 for RF1 (or LEFT)
 *               - 3 for RF2 (or Right)
 *               .
 *         -# Every element of portMaskList[] is either RF1 or RF2
 */
IQSEQUENCE_API int LP_MpsRxPer_PB(int    segmentIndex[],
                              double powerLevelStart[], 
                              double powerLevelStop[], 
                              double step[],
                              int    packetCount[],
                              int    rfPort[],
                              int    arraySize,
                              double ackTriggerLeveldBm,
                              bool bNpdMode = false
                              );
IQSEQUENCE_API int LP_MpsRxPer_ET(int    segmentIndex[],
                              double powerLevelStart[], 
                              double powerLevelStop[], 
                              double step[],
                              int    packetCount[],
                              int    portMaskList[],
                              int    arraySize,
                              double ackTriggerLeveldBm,
                              double *lowestTriggerLeveldBm=NULL,
                              bool bNpdMode = false
                              );


//! Retrieve RX PER results from last run of LP_MpsRxPer
/*!
 * \param[in] stepIndex Specifies the step number of total steps included in LP_MptaRxPer.  0 based.
 * \param[out] actualPowerLevel Returns the actual power levels for each enabled port at each power level
 * \param[out] packetSent Returns packets sent at each power level
 * \param[out] ackReceived Returns ACKs received at each power level
 * \param[out] per Returns the PER result at each power level
 * \param[out] arraySize Specifies the array size, meaning number of power levels.
 *
 * \return ERR_OK if the switch capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 *
 * \remark After finishing LP_MptaRxPer(), you call LP_MptaGetRxPerResults() to retrive the PER results.
 *        Each one of the total steps, specified by arraySize in LP_MptaRxPer(), will correspond to
 *        a range of power levels, determined by powerLevelStart, powerLevelStop, and step in LP_MptaRxPer(),
 *        and this value will be returned by arraySize in LP_MptaGetRxPerResults().
 *        The returned arrays have the following sizes:
 *           - actualPowerLevel[arraySize*4]:  For the unused ports, the value is -999.00
 *           - packetSent[arraySize]
 *           - ackReceived[arraySize]
 *           - per[arraySize]
*/
//IQSEQUENCE_API int LP_MpsGetRxPerResults(int    stepIndex,
//                                        double actualPowerLevel[], 
//                                        int    packetSent[], 
//                                        int    ackReceived[],
//                                        double per[],
//                                        int    *arraySize
//                                        );
//
////! LP_MptaGetRxPerResults -- Obsoleted
///*!
// * \remark LP_MptaGetRxPerResults() has benn renamed to LP_MpsGetRxPerResults()
// */
IQSEQUENCE_API int LP_MptaGetRxPerResults(int    stepIndex,
                                         double actualPowerLevel[], 
                                         int    packetSent[], 
                                         int    ackReceived[],
                                         double per[],
                                         int    *arraySize
                                         );

IQSEQUENCE_API int LP_MpsGetRxPerResults_PB(int    stepIndex,
                                           double actualPowerLevel[], 
                                           int    packetSent[], 
                                           int    ackReceived[],
                                           double ackRespMax[],
                                           double ackRespMin[],
                                           double per[],
                                           int    *arraySize
                                           );

IQSEQUENCE_API int LP_MpsGetRxPerResults_ET(int    stepIndex,
                                           double actualPowerLevel[], 
                                           int    packetSent[], 
                                           int    ackReceived[],
                                           double ackRespMax[],
                                           double ackRespMin[],
                                           double per[],
                                           int    *arraySize
                                           );


//IQSEQUENCE_API int LP_MpsResetRxPerResults();
IQSEQUENCE_API int LP_MptaResetRxPerResults();

//! Set Power Level Offset between 4 DUT ports for LP_MptaRxPer()
/*!
 * \param[in] port1 Power level offset (dB) for DUT port 1 
 * \param[in] port2 Power level offset (dB) for DUT port 2 
 * \param[in] port3 Power level offset (dB) for DUT port 3 
 * \param[in] port4 Power level offset (dB) for DUT port 4 
 *
 * \remark Without specifying those offsets, LP_MptaRxPer() will apply same power levels to all 4 DUT ports.  
 *         However, if the individual DUT ports require different power levels, LP_MptaSetDutPortPowerLevelOffset()
 *         can be used to adjust the power level for each port by introducing an offset.
 *         New offset settings will take effective for next call of LP_MptaRxPer().
 *         The allowed offset range is +/-6dB
 *         Note: 
 *            - The offsets will not take effect until the next call of LP_MptaRxPer
 *            - This function has no effect on LP_SetVsgCw()
 * \return ERR_OK if offsets are set; otherwise call LP_GetErrorString() for detailed error message.
 */

//IQSEQUENCE_API int LP_MpsSetDutPortPowerLevelOffset(double port1, double port2, double port3, double port4);
//
////! LP_MptaSetDutPortPowerLevelOffset -- Obsoleted
///*!
// * \remark LP_MptaSetDutPortPowerLevelOffset() has benn renamed to LP_MpsSetDutPortPowerLevelOffset()
// */
IQSEQUENCE_API int LP_MptaSetDutPortPowerLevelOffset(double port1, double port2, double port3, double port4);

//! Retrieve the Serial Number of MPTA connected
/*!
 * \param[out] serialNumber A pointer to the buffer that will hold the serial number
 * \param[in] bufSize The buffer size for storing the serial number
 *
 * \return ERR_OK if the serial number has been sucessfully retrieved; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MptaGetSerialNumber(char *serialNumber, int bufSize);

//! Check if MPTA connected
/*!
 * \param[out] mptaConnected Return 1 if MPTA connected; otherwise 0
 *
 * \return ERR_OK if the serial number has been sucessfully retrieved; otherwise call LP_GetErrorString() for detailed error message.
 */
IQSEQUENCE_API int LP_MptaConnected(int *mptaConnected);

IQSEQUENCE_API int LP_GetSampleData(int vsaNum, double bufferReal[], double bufferImag[], int bufferLength);

/*****************************/
/* Result Handling Functions */
/*****************************/

/***********************/
/* Debugging Functions */
/***********************/


//! Toggle the display of MPTA debugging info
/*!
 * \param[in] enableDebug Turn on/off (true/false) the MPTA debugging info
 *
 * \return ERR_OK
 */
IQSEQUENCE_API int LP_MptaPrintDebug(bool enableDebug);

IQSEQUENCE_API int LP_VsaSingleCapture(double rfAmpl, double samplingTimeSecs, int triggerType=6, double sampleFreqHz=80e6, int ht40Mode=OFF);

IQSEQUENCE_API int LP_MpsSetAttn(double freqInMhz, int rfPort, double *attn);

IQSEQUENCE_API int LP_UpdateModFileName(char *fileName);

IQSEQUENCE_API int LP_GetTesterType(int *testerType);

IQSEQUENCE_API int LP_MpsRxPer_Stop_ET(void);