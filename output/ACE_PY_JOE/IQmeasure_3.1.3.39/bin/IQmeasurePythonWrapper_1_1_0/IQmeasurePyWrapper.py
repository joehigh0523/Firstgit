import os
from ctypes import *
import string
import math
from threading import Thread, Lock

if os.name == "nt":
    IQmeasure = r'.\IQmeasure\IQmeasure_3.1.3.39\Bin'
    #IQmeasure = r'C:\LitePoint\IQmeasure\IQmeasure_3.1.3.39\bin'
    IQmeasureDll = CDLL(os.path.join(IQmeasure,'IQmeasure.dll'))
else:
    IQMEASURE_PATH = os.path.dirname(os.path.realpath(__file__))
    os.chdir(IQMEASURE_PATH)
    IQmeasureDll = CDLL(os.path.join(IQMEASURE_PATH,'libIQmeasure.so'))

MAX_BUFFER_SIZE = 1024
NO_ACK_DEFAULTPOWER = -9999

def enum(*args):
    enums = dict(zip(args, range(len(args))))
    return type('Enum', (), enums)

class IQAPI_PORT_ENUM:
    PORT_OFF   = 1
    PORT_LEFT  = 2
    PORT_RIGHT = 3
    PORT_1       = 2
    PORT_2       = 3
    PORT_3       = 4
    PORT_4       = 5
    PORT_BB    = 33
    MAX_PORT_INDEX = 34

class IQMEASURE_CAPTURE_NONBLOCKING_STATES:
    BLOCKING = 0
    ARM_TRIGGER = 1,
    CHECK_DATA = 2

IQMEASURE_ERROR_CODES = enum(
    'ERR_OK',
    'ERR_NO_CONNECTION',
    'ERR_NOT_INITIALIZED',
    'ERR_SAVE_WAVE_FAILED',
    'ERR_LOAD_WAVE_FAILED',
    'ERR_SET_TX_FAILED',
    'ERR_SET_WAVE_FAILED',
    'ERR_SET_RX_FAILED',
    'ERR_CAPTURE_FAILED',
    'ERR_NO_CAPTURE_DATA',
    'ERR_VSA_NUM_OUT_OF_RANGE',
    'ERR_ANALYSIS_FAILED',
    'ERR_NO_VALID_ANALYSIS',
    'ERR_VSG_PORT_IS_OFF',
    'ERR_NO_MOD_FILE_LOADED',
    'ERR_NO_CONT_FOR_MULTI_SEGMENT',
    'ERR_MEASUREMENT_NAME_NOT_FOUND',
    'ERR_INVALID_ANALYSIS_TYPE',
    'ERR_NO_ANALYSIS_RESULT_AVAILABLE',
    'ERR_NO_MEASUREMENT_RESULT',
    'ERR_INVALID_IP_ADDRESS',
    'ERR_GENERAL_ERR',
    'ERR_TX_NOT_DONE',
    'ERR_SET_TOKEN_FAILED',
    'ERR_TOKEN_RETRIEVAL_TIMEDOUT',
    'ERR_GET_TOKEN_FAILED',
    'ERR_INVALID_CAPTURE_INDEX',
    'ERR_VSG_POWER_EXCEED_LIMIT',
    'ERR_ANALYSIS_NULL_POINTER',
    'ERR_ANALYSIS_UNSUPPORTED_PARAM_NAME',
    'ERR_ANALYSIS_INVALID_PARAM_VALUE',
    'ERR_INVALID_DATA_CAPTURE_RANGE',
    'ERR_DATARATE_DOES_NOT_EXIST',
    'ERR_BUFFER_OVERFLOW',
    'ERR_SET_PATH_NOT_DONE',
    'ERR_FM_NOT_INITIALIZED',
    'ERR_FM_SET_TX_FAILED',
    'ERR_FM_GET_TX_FAILED',
    'ERR_FM_SET_AUDIO_TONE_FAILED',
    'ERR_FM_GET_AUDIO_TONE_FAILED',
    'ERR_FM_NO_CAPTURE_DATA',
    'ERR_FM_VSA_CAPTURE_FAILED',
    'ERR_FM_SET_RX_FAILED',
    'ERR_FM_GET_RX_FAILED',
    'ERR_FM_ANALYSIS_FAILED',
    'ERR_FM_CAPTURE_AUDIO_FAILED',
    'ERR_FM_GENERATE_AUDIO_FAILED',
    'ERR_FM_QUERY_AIM_FAILED',
    'ERR_FM_SAVE_WAV_AUDIO_FAILED',
    'ERR_FM_PLAY_AUDIO_FAILED',
    'ERR_FM_LOAD_AUDIO_FAILED',
    'ERR_FM_STOP_AUDIO_PLAY_FAILED',
    'ERR_GPS',
    'ERR_SET_MULTI_THREAD_FAILED',
    'ERR_UNKNOWN_TESTER_TYPE',
    'ERR_WRONG_TESTER_TYPE',
    'ERR_INVALID_TESTER_CONTROL',
    'ERR_NO_RESPONSE_FROM_TESTER',
    'ERR_MPTA_NOT_ENABLE',
    'ERR_MPTA_NOT_DISENABLE',
    'ERR_MPTA_SET_TXRX',
    'ERR_MPTA_CAPTURE_FAILED',
    'ERR_INVALID_TEST_TYPE',
    'ERR_INVALID_SEQUENCE_NUM',
    'ERR_TX_RX_FREQ_NOT_EQUAL',
    'ERR_INVALID_RF_PORT_SETTING',
    'ERR_INVALID_PACKET_COUNT',
    'ERR_NOT_SUPPORTED_RF_MODE',
    'ERR_EMPTY_WAVEFORM_NAME',
    'ERR_ZERO_WAVEFROM_SIZE',
    'ERR_NOT_DEFINED_CHANGE_DIRECTION_TIME',
    'ERR_WRONG_EXEC_PARAM_SIZE',
    'ERR_INVALID_PACKET_TYPE',
    'ERR_INVALID_MODULATION',
    'ERR_NOT_ENOUGH_RETURN_ACK',
    'ERR_INVALID_PARAM_SETTING',
    'ERR_UNKNOWN',
    'ERR_FUNCTION_NOT_SUPPROTED',
    'ERR_VSG_TRANSMIT_PKT_NOT_FINISHED',
    'ERR_SET_VSG_POWER_STATE_FAILED',
    'ERR_VSG_PLAY_WAVE_FAILED',
    'ERR_WAVEFORM_NOT_EXISTED_IN_TESTER',
    'ERR_INVALID_HANDLE',
    'ERR_CANNOT_FIND_TESTER_FOLDER', 
    'ERR_WAVEFORM_NOT_FOUND',
    'ERR_SET_VSA_VSG_SEPARATION_FAILED',
    'ERR_NO_VALUE_DEFINED',
    'ERR_WRONG_SCPI_RETURN_SIZE',
    'ERR_NAV_ACTIVATE_FAILED',
    'ERR_NAV_DEACTIVATE_FAILED',
    'ERR_NAV_SET_CONTINUE_WAVE_FAILED',
    'ERR_NAV_SET_MODULATE_MODE_FAILED',
    'ERR_NAV_SET_TIME_OF_WEEK_FAILED',
    'ERR_NAV_SET_GLONASS_CHANNEL_FAILED',
    'ERR_NAV_SET_POWER_FAILED',
    'ERR_NAV_LOAD_SCENARIO_FILE_FAILED',
    'ERR_NAV_PLAY_SCENARIO_FILE_FAILED',
    'ERR_INVALID_FREQ_BAND',
    'ERR_OPEN_FILE_FAILD',
    'ERR_NOT_SUPPORTED_TECHNOLOGY',
    'ERR_IQLINK_DISASSOCIATE_FAILED',
    'ERR_IQLINK_SET_TCP_FAILED',
    'ERR_IQLINK_SET_UDP_FAILED',
    'ERR_IQLINK_SET_AP_FAILED',
    'ERR_IQLINK_UPLINK_FAILED',
    'ERR_IQLINK_DOWNLINK_FAILED',
    'ERR_IQLINK_PER_FAILED')

class IQxel:
    def __init__(self):
        return
        
    def CreateResults(self, errCode, resultDict = None):
        if errCode != 0:
            errorStr = self.LP_GetErrorString(errCode)
            if errCode != IQMEASURE_ERROR_CODES.ERR_TX_NOT_DONE:
                print( "Error", errorStr)
            return { 'err' : errCode, 'errDesc' : errorStr, 'output' : None }
        else:
            return { 'err' : 0, 'errDesc' : 'N/A', 'output' : resultDict }
        
    def LP_GetErrorString(self, err):
        func = IQmeasureDll.LP_GetErrorString
        func.argtypes = [ c_int ]
        func.restype = c_char_p
        return func(err)        

    def LP_Init(self, testerType = 1, testerControlMethod = 1):
        func = IQmeasureDll.LP_Init
        func.argtypes = [ c_int, c_int ]
        func.restype = c_int
        return self.CreateResults(func(testerType, testerControlMethod))
        
    def LP_Term(self):
        func = IQmeasureDll.LP_Term
        func.restype = c_int
        return self.CreateResults(func())
        
    def LP_GetVersion(self):
        bufStr = create_string_buffer(MAX_BUFFER_SIZE)
        func = IQmeasureDll.LP_GetVersion
        func.argtypes = [ c_char_p, c_int ]
        func.restype = c_bool
        ret = func(bufStr, MAX_BUFFER_SIZE)
        return self.CreateResults(0, { 'version' : bufStr.value })
    
    def LP_InitTester(self, ipAddress, connectionType = 0):
        func = IQmeasureDll.LP_InitTester
        func.argtypes = [ c_char_p, c_int ]
        func.restype = c_int
        ret = func(ipAddress, connectionType)
        return self.CreateResults(ret)
        
    def LP_SetVsg(self, rfFreqHz, rfPowerLeveldBm, port, setGapPowerOff = True, dFreqShiftHz = 0.0):
        func = IQmeasureDll.LP_SetVsg
        func.argtypes = [ c_double, c_double, c_int, c_bool, c_double ]
        func.restype = c_int
        ret = func(rfFreqHz, rfPowerLeveldBm, port, setGapPowerOff, dFreqShiftHz)
        return self.CreateResults(ret)
    
    def LP_SetVsgModulation(self, modFileName, loadInternalWaveform = 0):
        func = IQmeasureDll.LP_SetVsgModulation
        func.argtypes = [ c_char_p, c_int ]
        func.restype = c_int
        return self.CreateResults(func(modFileName, loadInternalWaveform))
    
    def LP_EnableVsgRF(self, enabled):
        func = IQmeasureDll.LP_EnableVsgRF
        func.argtypes = [ c_int ]
        func.restype = c_int
        return self.CreateResults(func(enabled))
    
    def LP_SetFrameCnt(self, frameCnt):
        func = IQmeasureDll.LP_SetFrameCnt
        func.argtypes = [ c_int ]
        func.restype = c_int
        return self.CreateResults(func(frameCnt))
    
    def LP_SetPathLossTable(self, VSGtableIndex, VSAtableIndex):
        func = IQmeasureDll.LP_SetPathLossTable
        func.argtypes = [ ARRAY(c_uint, len(VSGtableIndex)), ARRAY(c_uint, len(VSAtableIndex)) ]
        func.restype = c_int
        ret = func((c_uint * len(VSGtableIndex))(*VSGtableIndex), (c_uint * len(VSAtableIndex))(*VSAtableIndex))
        return self.CreateResults(ret)

    def LP_TxDone(self):
        func = IQmeasureDll.LP_TxDone
        func.restype = c_int
        return self.CreateResults(func())
    
    def LP_SetVsa(self, rfFreqHz, rfAmplDb, port, extAttenDb=0, triggerLevelDb=-25, triggerPreTime=10e-6, dFreqShiftHz = 0.0):
        func = IQmeasureDll.LP_SetVsa
        func.argtypes = [ c_double, c_double, c_int, c_double, c_double, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(rfFreqHz, rfAmplDb, port, extAttenDb, triggerLevelDb, triggerPreTime, dFreqShiftHz))
    
    def LP_VsaDataCapture(self, samplingTimeSecs, triggerType=6, sampleFreqHz=160e6, ht40Mode=0, nonBlockingState=IQMEASURE_CAPTURE_NONBLOCKING_STATES.BLOCKING):
        func = IQmeasureDll.LP_VsaDataCapture
        func.argtypes = [ c_double, c_int, c_double, c_int, c_int ]
        func.restype = c_int
        return self.CreateResults(func(samplingTimeSecs, triggerType, sampleFreqHz, ht40Mode, nonBlockingState))
    
    def LP_SaveVsaSignalFile(self, sigFileName):
        func = IQmeasureDll.LP_SaveVsaSignalFile
        func.argtypes = [ c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(sigFileName))
    
    def LP_AnalyzePower(self, T_interval = 0.0, max_pow_diff_dB = 0.0):
        func = IQmeasureDll.LP_AnalyzePower
        func.argtypes = [ c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(T_interval, max_pow_diff_dB))
    
    def LP_GetScalarMeasurement(self, measurement, index = 0):
        func = IQmeasureDll.LP_GetScalarMeasurement
        func.argtypes = [ c_char_p, c_int ]
        func.restype = c_double
        return func(measurement, index)

    def LP_Analyze80211ag(self, ph_corr_mode=2, ch_estimate=1, sym_tim_corr=2, freq_sync=2,
                                ampl_track=1, prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Analyze80211ag
        func.argtypes = [ c_int, c_int, c_int, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(ph_corr_mode, ch_estimate, sym_tim_corr, freq_sync, ampl_track, prePowStartSec, prePowStopSec))

    def LP_Analyze80211n(self, sType = "EWC", mode = "nxn", enablePhaseCorr = 1, enableSymTimingCorr = 1, enableAmplitudeTracking = 0,
                          decodePSDU = 0, enableFullPacketChannelEst = 0, referenceFile="", packetFormat = 0, frequencyCorr = 2,
                          prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Analyze80211n
        func.argtypes = [ c_char_p, c_char_p, c_int, c_int, c_int, c_int, c_int, c_char_p, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(sType, mode, enablePhaseCorr, enableSymTimingCorr, enableAmplitudeTracking,
                          decodePSDU, enableFullPacketChannelEst, referenceFile, packetFormat, frequencyCorr,
                          prePowStartSec, prePowStopSec))

    def LP_Analyze80211b(self, eq_taps = 1,
                               DCremove11b_flag = 0,
                               method_11b       = 1,
                               prePowStartSec = 8.8e-6,
                               prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Analyze80211b
        func.argtypes = [ c_int, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(eq_taps, DCremove11b_flag, method_11b, prePowStartSec, prePowStopSec))

    def LP_Analyze80211ac(self, mode ="nxn", enablePhaseCorr = 1, enableSymTimingCorr = 1, enableAmplitudeTracking = 0,
                          decodePSDU = 0, enableFullPacketChannelEst = 0, frequencyCorr = 2, referenceFile=None, packetFormat = 0,
                          numberOfPacketToAnalysis = 1, prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Analyze80211ac
        func.argtypes = [ c_char_p, c_int, c_int, c_int, c_int, c_int, c_int, c_char_p, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(mode, enablePhaseCorr, enableSymTimingCorr, enableAmplitudeTracking,
                          decodePSDU, enableFullPacketChannelEst, frequencyCorr, referenceFile, packetFormat,
                          numberOfPacketToAnalysis, prePowStartSec, prePowStopSec))
        
    def LP_GetVectorMeasurement(self, measurement, bufferLength):
        func = IQmeasureDll.LP_GetVectorMeasurement
        realValueArray = (c_double * bufferLength)()
        imagValueArray = (c_double * bufferLength)()
        func.argtypes = [ c_char_p, ARRAY(c_double, bufferLength), ARRAY(c_double, bufferLength), c_int ]
        func.restype = c_int
        ret = func(measurement, realValueArray, imagValueArray, bufferLength)
        if ret <= 0:
            return self.CreateResults(IQMEASURE_ERROR_CODES.ERR_NO_MEASUREMENT_RESULT)
        realList = [realValueArray[i] for i in range(ret)]
        imagList = [imagValueArray[i] for i in range(ret)]
        resultDict = {}
        resultDict['real'] = realList
        resultDict['imag'] = imagList
        return resultDict
    
    def LP_AnalyzeTechnologyFFT(self, technology=99, NFFT=0, res_bw=100e3, window_type=None):
        func = IQmeasureDll.LP_AnalyzeTechnologyFFT
        func.argtypes = [ c_int, c_double, c_double, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(technology, NFFT, res_bw, window_type))

    def LP_AnalyzeFFT(self, NFFT=0, res_bw=100e3, window_type=None):
        func = IQmeasureDll.LP_AnalyzeTechnologyFFT
        func.argtypes = [ c_double, c_double, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(NFFT, res_bw, window_type))

    def LP_AnalyzePowerRampOFDM(self):
        func = IQmeasureDll.LP_AnalyzePowerRampOFDM
        func.argtypes = [ ]
        func.restype = c_int
        return self.CreateResults(func())
    
    def LP_SetVsaBluetooth(self, rfFreqHz, rfAmplDb, port, triggerLevelDb=-25, triggerPreTime=10e-6):
        func = IQmeasureDll.LP_SetVsaBluetooth
        func.argtypes = [ c_double, c_double, c_int, c_double, c_double]
        func.restype = c_int
        return self.CreateResults(func(rfFreqHz, rfAmplDb, port, triggerLevelDb, triggerPreTime))
        
    def LP_AnalyzeBluetooth(self, data_rate = 0, analysis_type = "All"):
        func = IQmeasureDll.LP_AnalyzeBluetooth
        func.argtypes = [ c_double, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(data_rate, analysis_type))

    def LP_AnalyzeCW(self):
        func = IQmeasureDll.LP_AnalyzeCW
        func.restype = c_int
        return self.CreateResults(func())

    def LP_ScpiCommandSet(self, scpiCommand):
        func = IQmeasureDll.LP_ScpiCommandSet
        func.argtypes = [ c_char_p ]
        func.restype = c_int
        ret = func(scpiCommand)
        return self.CreateResults(ret)


    def LP_ScpiCommandQuery(self, query, max_size=MAX_BUFFER_SIZE):
        response = create_string_buffer(max_size)
        actual_size = c_uint()
        func = IQmeasureDll.LP_ScpiCommandQuery
        func.argtypes = [ c_char_p, c_uint, c_char_p, POINTER(c_uint) ]
        func.restype = c_int
        ret = func(query, max_size, response, byref(actual_size))
        return self.CreateResults(ret, response.value)

    def LP_Segms_VsaDataCapture(self, numSegms, samplingTimeSecs, triggerType=6, sampleFreqHz=160e6,
                                          ht40Mode=0, nonBlockingState = 0):
        func = IQmeasureDll.LP_Segms_VsaDataCapture
        func.argtypes = [ c_int, c_double, c_int, c_double, c_int, c_int ]
        func.restype = c_int
        return self.CreateResults(func(numSegms, samplingTimeSecs, triggerType, sampleFreqHz, ht40Mode, nonBlockingState))
        
    def LP_Segms_AnalyzePower(self, numSegsToAnalyze):
        func = IQmeasureDll.LP_Segms_AnalyzePower
        func.argtypes = [ c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegsToAnalyze, 3.2e-6, 15.0))
    
    def LP_Segms_GetScalarMeasurement(self, segment_index, measurement, index = 0):
        func = IQmeasureDll.LP_Segms_GetScalarMeasurement
        func.argtypes = [ c_int, c_char_p, c_int ]
        func.restype = c_double
        return func(segment_index, measurement, index)

    def LP_Segms_GetVectorMeasurement(self, segment_index, measurement, bufferLength):
        func = IQmeasureDll.LP_Segms_GetVectorMeasurement
        realValueArray = (c_double * bufferLength)()
        imagValueArray = (c_double * bufferLength)()
        func.argtypes = [ c_int, c_char_p, ARRAY(c_double, bufferLength), ARRAY(c_double, bufferLength), c_int ]
        func.restype = c_int
        ret = func(segment_index, measurement, realValueArray, imagValueArray, bufferLength)
        if ret <= 0:
            return self.CreateResults(IQMEASURE_ERROR_CODES.ERR_NO_MEASUREMENT_RESULT)
        realList = [realValueArray[i] for i in range(ret)]
        imagList = [imagValueArray[i] for i in range(ret)]
        resultDict = {}
        resultDict['real'] = realList
        resultDict['imag'] = imagList
        return resultDict
    
    def LP_Segms_SaveVsaSignalFile(self, segment_index, sigFileName):
        func = IQmeasureDll.LP_Segms_SaveVsaSignalFile
        func.argtypes = [ c_int, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(segment_index, sigFileName))
    
    def LP_Segms_Analyze80211ac(self, numSegmsToAnalyze, mode ="nxn", enablePhaseCorr = 1, enableSymTimingCorr = 1, enableAmplitudeTracking = 0,
                          decodePSDU = 0, enableFullPacketChannelEst = 0, frequencyCorr = 2, referenceFile=None, packetFormat = 0,
                          numberOfPacketToAnalysis = 1, prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Segms_Analyze80211ac
        func.argtypes = [ c_int, c_char_p, c_int, c_int, c_int, c_int, c_int, c_int, c_char_p, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, mode, enablePhaseCorr, enableSymTimingCorr, enableAmplitudeTracking,
                          decodePSDU, enableFullPacketChannelEst, frequencyCorr, referenceFile, packetFormat,
                          numberOfPacketToAnalysis, prePowStartSec, prePowStopSec))
        
    def LP_Segms_Analyze80211ag(self, numSegmsToAnalyze, ph_corr_mode=2, ch_estimate=1, sym_tim_corr=2, freq_sync=2,
                                ampl_track=1, prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Segms_Analyze80211ag
        func.argtypes = [ c_int, c_int, c_int, c_int, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, ph_corr_mode, ch_estimate, sym_tim_corr, freq_sync, ampl_track, prePowStartSec, prePowStopSec))
        
    def LP_Segms_Analyze80211p(self, numSegmsToAnalyze, ph_corr_mode=2, ch_estimate=1, sym_tim_corr=2, freq_sync=2,
                               ampl_track=1, prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Segms_Analyze80211p
        func.argtypes = [ c_int, c_int, c_int, c_int, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, ph_corr_mode, ch_estimate, sym_tim_corr, freq_sync, ampl_track, prePowStartSec, prePowStopSec))
        
    def LP_Segms_Analyze80211n(self, numSegmsToAnalyze, sType = "EWC", mode = "nxn", enablePhaseCorr = 1, enableSymTimingCorr = 1, enableAmplitudeTracking = 0,
                          decodePSDU = 0, enableFullPacketChannelEst = 0, referenceFile="", packetFormat = 0, frequencyCorr = 2,
                          prePowStartSec = 8.8e-6, prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Segms_Analyze80211n
        func.argtypes = [ c_int, c_char_p, c_char_p, c_int, c_int, c_int, c_int, c_int, c_char_p, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, sType, mode, enablePhaseCorr, enableSymTimingCorr, enableAmplitudeTracking,
                          decodePSDU, enableFullPacketChannelEst, referenceFile, packetFormat, frequencyCorr,
                          prePowStartSec, prePowStopSec))

    def LP_Segms_Analyze80211b(self, numSegmsToAnalyze, eq_taps = 1,
                                         DCremove11b_flag = 0,
                                         method_11b       = 1,
                                         prePowStartSec = 8.8e-6,
                                         prePowStopSec = 15.2e-6):
        func = IQmeasureDll.LP_Segms_Analyze80211b
        func.argtypes = [ c_int, c_int, c_int, c_int, c_double, c_double ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, eq_taps, DCremove11b_flag, method_11b, prePowStartSec, prePowStopSec))

    def LP_Segms_AnalyzeTechnologyFFT(self, numSegmsToAnalyze, technology, NFFT = 0, res_bw = 100e3, window_type = None):
        func = IQmeasureDll.LP_Segms_AnalyzeTechnologyFFT
        func.argtypes = [ c_int, c_int, c_double, c_double, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, technology, NFFT, res_bw, window_type))
    
    def LP_Segms_AnalyzeVHT80Mask(self, numSegmsToAnalyze):
        func = IQmeasureDll.LP_Segms_AnalyzeVHT80Mask
        func.argtypes = [ c_int ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze))
    
    def LP_Segms_AnalyzeBluetooth(self, numSegmsToAnalyze = 1, data_rate = 0, analysis_type = "All"):
        func = IQmeasureDll.LP_Segms_AnalyzeBluetooth
        func.argtypes = [ c_int, c_double, c_char_p ]
        func.restype = c_int
        return self.CreateResults(func(numSegmsToAnalyze, data_rate, analysis_type))

    def LP_InitTesterN(self, ipAddresses, numOfTesters ):
        num_mods_per_ip = c_int()
        func = IQmeasureDll.LP_InitTesterN
        func.argtypes = [ c_char_p, c_int, POINTER(c_int) ]
        func.restype = c_int
        ret = func(ipAddresses, numOfTesters, byref(num_mods_per_ip))
        return self.CreateResults(ret, { 'NumberOfModulePerIP' : num_mods_per_ip.value })
    
    def LP_SetTesterMode(self, signalMode, selectedModules, numOfSelectedModules ):
        func = IQmeasureDll.LP_SetTesterMode
        func.argtypes = [ c_int, ARRAY(c_int, numOfSelectedModules), c_int ]
        func.restype = c_int
        ret = func(signalMode, (c_int * len(selectedModules))(*selectedModules), numOfSelectedModules)
        return self.CreateResults(ret)
    
    def LP_SetVsgNxN(self, rfFreqHz, rfPowerLeveldBmList, portList, dFreqShiftHz = 0.0 ):
        func = IQmeasureDll.LP_SetVsgNxN
        func.argtypes = [ c_double, ARRAY(c_double, 4), ARRAY(c_int, 4), c_double ]
        func.restype = c_int
        ret = func(rfFreqHz, (c_double * len(rfPowerLeveldBmList))(*rfPowerLeveldBmList), (c_int * len(portList))(*portList), dFreqShiftHz)
        return self.CreateResults(ret)

    def LP_SetVsgCw(self, sineFreqHz, offsetFrequencyMHz, rfPowerLeveldBm, port):
        func = IQmeasureDll.LP_SetVsgCw
        func.argtypes = [ c_double, c_double, c_double, c_int ]
        func.restype = c_int
        return self.CreateResults(func(sineFreqHz, offsetFrequencyMHz, rfPowerLeveldBm, port))
    
    def LP_EnableVsgRFNxN(self, rx1Enabled = 1, rx2Enabled = 1, rx3Enabled = 1, rx4Enabled = 1):
        func = IQmeasureDll.LP_EnableVsgRFNxN
        func.argtypes = [ c_int, c_int, c_int, c_int ]
        func.restype = c_int
        return self.CreateResults(func(rx1Enabled, rx2Enabled, rx3Enabled, rx4Enabled))
            
    def LP_SetVsaNxN(self, rfFreqHz, rfAmplDb, port, extAttenDb=0, triggerLevelDb=-25, triggerPreTime=10e-6, dFreqShiftHz = 0.0):
        func = IQmeasureDll.LP_SetVsaNxN
        func.argtypes = [ c_double, ARRAY(c_double, 4), ARRAY(c_int, 4), c_double, c_double, c_double, c_double ]
        func.restype = c_int
        ret = func(rfFreqHz, (c_double * len(rfAmplDb))(*rfAmplDb), (c_int * len(port))(*port), extAttenDb, triggerLevelDb, triggerPreTime, dFreqShiftHz)
        return self.CreateResults(ret)

    def LP_SetVsaAmplitudeToTolerance(self, amplitudeToleranceDb):
        func = IQmeasureDll.LP_SetVsaAmplitudeTolerance
        func.argtypes = [ c_double ]
        func.restype = c_int
        return func(amplitudeToleranceDb)

    def LP_SetAnalysisParameterInteger(self, measurement, parameter, value):
        func = IQmeasureDll.LP_SetAnalysisParameterInteger
        func.argtypes = [ c_char_p, c_char_p, c_int ]
        func.restype = c_int
        return func(measurement, parameter, value)

    def LP_SetAnalysisParameterIntegerArray(self, measurement, parameter, value, valuesize):
        func = IQmeasureDll.LP_SetAnalysisParameterIntegerArray
        func.argtypes = [ c_char_p, c_char_p, ARRAY(c_int, valuesize), c_int ]
        func.restype = c_int
        return func(measurement, parameter, (c_int * valuesize)(*value), valuesize)

    def LP_AnalyzeZigbee(self):
        func = IQmeasureDll.LP_AnalyzeZigbee
        func.restype = c_int
        return self.CreateResults(func())

        
