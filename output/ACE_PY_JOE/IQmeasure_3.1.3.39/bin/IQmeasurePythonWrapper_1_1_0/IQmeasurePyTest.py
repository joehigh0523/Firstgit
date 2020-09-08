from IQmeasurePyWrapper import *
from math import *

IQmeasurePythonWrapperVersion = "1.0.0"
iqxel = IQxel()
waveformDir = r"C:/LitePoint/IQlite_3.2.6.Eng3/mod/"
testerIP = "192.168.4.48"

def Fetch_Results_Seg(numOfAvg, numOfVsa, numOfStrm):
    for segment in range(1, numOfAvg + 1):
        print "spatialStreams" + str(int(iqxel.LP_Segms_GetScalarMeasurement(segment, "rateInfo_spatialStreams", 0)))
        for strm in range(numOfVsa):
            print "Stream: " + str(strm + 1)
            print "freqErrorHz = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "freqErrorHz", strm))
            print "phaseErr = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "phaseErr", strm))
            print "rateInfo_dataRateMbps = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "rateInfo_dataRateMbps", strm))
            print "PhaseNoiseDeg_RmsAll = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "PhaseNoiseDeg_RmsAll", strm))
            print "symClockErrorPpm = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "symClockErrorPpm", strm))
            print "EvmAvgAll = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "evmAvgAll", strm))
            print "EvmPilot = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "evmPilot", strm))
            print "EvmData = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "evmData", strm))
            print "IQImbal_amplDb = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "IQImbal_amplDb", strm))
            print "IQImbal_phaseDeg = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "IQImbal_phaseDeg", strm))
            print "dcLeakageDbc = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "dcLeakageDbc", strm))
        for vsaNum in range(numOfVsa):
            for strm in range(numOfStrm):
                print "VSA " + str(vsaNum) + " Strm " + str(strm + 1) + " Power = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "rxRmsPowerDb", vsaNum * 2 + strm))

def Fetch_Results_2010_ag():
    print "freqErr = " + str(iqxel.LP_GetScalarMeasurement("freqErr"))
    print "ampErrDb = " + str(iqxel.LP_GetScalarMeasurement("ampErrDb"))
    print "phaseErr = " + str(iqxel.LP_GetScalarMeasurement("phaseErr"))
    print "dataRate = " + str(iqxel.LP_GetScalarMeasurement("dataRate"))
    print "rmsPhaseNoise = " + str(iqxel.LP_GetScalarMeasurement("rmsPhaseNoise"))
    print "clockErr = " + str(iqxel.LP_GetScalarMeasurement("clockErr"))
    print "evmAll = " + str(iqxel.LP_GetScalarMeasurement("evmAll"))

def Fetch_Results_802_11b_Seg(numOfAvg):
    for segment in range(1, numOfAvg + 1):
        print "Segment " + str(segment)
        print "lockedClock = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "lockedClock"))
        print "plcpCrcFail = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "plcpCrcFail"))
        print "psduCrcFail = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "psduCrcFail"))
        print "longPreamble = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "longPreamble"))
        print "bitRateInMHz = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "bitRateInMHz"))
        print "evmPk = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "evmPk"))
        print "evmAll = " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "evmAll"))
        print "freqErr = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "freqErr"))
        print "clockErr = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "clockErr"))
        print "ampErr = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "ampErr"))
        print "ampErrDb = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "ampErrDb"))
        print "phaseErr = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "phaseErr"))
        print "rmsPhaseNoise = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "rmsPhaseNoise"))
        print "rmsPowerNoGap = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "rmsPowerNoGap"))
        print "rmsMaxAvgPower = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "rmsMaxAvgPower"))
        print "bitRate = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "bitRate"))
        print "modType = ", str(iqxel.LP_Segms_GetScalarMeasurement(segment, "modType"))

def Fetch_Results_802_11b():
    print "lockedClock = " + str(iqxel.LP_GetScalarMeasurement("lockedClock"))
    print "plcpCrcFail = " + str(iqxel.LP_GetScalarMeasurement("plcpCrcFail"))
    print "psduCrcFail = " + str(iqxel.LP_GetScalarMeasurement("psduCrcFail"))
    print "longPreamble = " + str(iqxel.LP_GetScalarMeasurement("longPreamble"))
    print "bitRateInMHz = " + str(iqxel.LP_GetScalarMeasurement("bitRateInMHz"))
    print "evmPk = " + str(iqxel.LP_GetScalarMeasurement("evmPk"))
    print "evmAll = " + str(iqxel.LP_GetScalarMeasurement("evmAll"))
    print "freqErr = ", str(iqxel.LP_GetScalarMeasurement("freqErr"))
    print "clockErr = ", str(iqxel.LP_GetScalarMeasurement("clockErr"))
    print "ampErr = ", str(iqxel.LP_GetScalarMeasurement("ampErr"))
    print "ampErrDb = ", str(iqxel.LP_GetScalarMeasurement("ampErrDb"))
    print "phaseErr = ", str(iqxel.LP_GetScalarMeasurement("phaseErr"))
    print "rmsPhaseNoise = ", str(iqxel.LP_GetScalarMeasurement("rmsPhaseNoise"))
    print "rmsPowerNoGap = ", str(iqxel.LP_GetScalarMeasurement("rmsPowerNoGap"))
    print "rmsMaxAvgPower = ", str(iqxel.LP_GetScalarMeasurement("rmsMaxAvgPower"))
    print "bitRate = ", str(iqxel.LP_GetScalarMeasurement("bitRate"))
    print "modType = ", str(iqxel.LP_GetScalarMeasurement("modType"))
    print "rmsPowerNoGap = ", str(iqxel.LP_GetScalarMeasurement("rmsPowerNoGap"))


def Fetch_Mask_Results_Seg(numOfAvg, numOfStrm):
    for seg in range(numOfAvg):
        print "Segment: " + str(seg + 1)
        spectrumMarginOffsetFreqHz = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumMarginOffsetFreqHz', 32)['real']
        spectrumCheck = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumCheck', 32)['real']
        spectrumMarginDb = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumMarginDb', 32)['real']
        spectrumAverViolationPercentage = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumAverViolationPercentage', 4)['real']
        spectrumAverObw = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumAverObw', 4)['real']
        spectrumAverObwLowerFreq = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumAverObwLowerFreq', 4)['real']
        spectrumAverObwUpperFreq = iqxel.LP_Segms_GetVectorMeasurement(seg + 1, 'spectrumAverObwUpperFreq', 4)['real']
        tmpResults = dict()
        
        for strm in range(numOfStrm):
            for region in range(len(spectrumMarginDb)):
                if spectrumMarginDb[strm * 8 + region] < 9e10:
                    if region - 4 < 0:
                        regionKeyword = '_LOWER_' + str(4 - region)
                    else:
                        regionKeyword = '_UPPER_' + str(region - 3)
                    print 'MARGIN_DB_S' + str(strm + 1) + regionKeyword + " : " + str(spectrumMarginDb[strm * 8 + region])
                    print 'MARGIN_OFFSET_FREQ_S' + str(strm + 1) + regionKeyword + " : " + str(spectrumMarginOffsetFreqHz[strm * 8 + region])
                    print 'MASK_CHECK_S' + str(strm + 1) + regionKeyword + " : " + str(spectrumCheck[strm * 8 + region])
            print 'MASK_VIOLATION_PERCENTAGE_S' + str(strm + 1) + " : " + str(spectrumAverViolationPercentage[strm])
            print 'OBW_S' + str(strm + 1) + " : " + str(spectrumAverObw[strm])
            print 'OBW_FREQ_START_S' + str(strm + 1) + " : " + str(spectrumAverObwLowerFreq[strm])
            print 'OBW_FREQ_STOP_S' + str(strm + 1) + " : " + str(spectrumAverObwUpperFreq[strm])

def WiFi_Siso_loopback_Seg():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_SetTesterMode(0, [1], 1)
    print iqxel.LP_GetVersion()
    # Set VSG to use Port #1 (enumeration "2")
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_11AC_VHT40_S1_MCS8.iqvsg", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    numOfAvg = 3
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 500e-6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "savedCapture")
    ret = iqxel.LP_SetAnalysisParameterInteger("Analyze80211ac",  "useAllSignals", 1)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "powerDetectionSignals",  [1], 1)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "prefOrderSignals",  [1], 1)
    ret = iqxel.LP_Segms_Analyze80211ac(numOfAvg)
    Fetch_Results_Seg(3, 1, 1)
    ret = iqxel.LP_SetAnalysisParameterInteger("AnalyzeFFT", "useAllSignals", 1)
    ret = iqxel.LP_Segms_AnalyzeTechnologyFFT(numOfAvg, 0)
    Fetch_Mask_Results_Seg(3, 1)

def WiFi_Siso_80MHz_loopback_Seg():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_SetTesterMode(0, [1], 1)
    print iqxel.LP_GetVersion()
    # To perform "Wide", 80MHz capture, we cannot use "Loopback" mode. You'll need your DUT or another tester to play the 80 MHz signal
    # Set VSG to use Port #1 (enumeration "2")
#    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
#    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_11AC_VHT80_S1_MCS8.iqvsg", 0)
#    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
#    ret = iqxel.LP_SetFrameCnt(0)
    numOfAvg = 3
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [2, 2, 2, 2])
    # The last argument (after 160e6), when set to "6", means it will perform "Wide" capture for 80MHz signal
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 500e-6, 6, 160e6, 6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "savedCapture")
    ret = iqxel.LP_SetAnalysisParameterInteger("Analyze80211ac",  "useAllSignals", 1)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "powerDetectionSignals",  [1], 1)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "prefOrderSignals",  [1], 1)
    ret = iqxel.LP_Segms_Analyze80211ac(numOfAvg)
    Fetch_Results_Seg(3, 1, 1)
    ret = iqxel.LP_SetAnalysisParameterInteger("AnalyzeVHT80Mask", "vsaNum",  1)
    ret = iqxel.LP_Segms_AnalyzeVHT80Mask(numOfAvg)
    Fetch_Mask_Results_Seg(3, 1)

def WiFi_Mimo_loopback_M8_nxn_Seg():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_SetTesterMode(0, [1, 2], 2)
    print iqxel.LP_GetVersion()
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_11AC_VHT20_S2_MCS8.iqvsg", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    numOfAvg = 3
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 500e-6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "savedCapture")
    ret = iqxel.LP_SetAnalysisParameterInteger("Analyze80211ac",  "useAllSignals", 1)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "powerDetectionSignals",  [1, 2], 2)
    ret = iqxel.LP_SetAnalysisParameterIntegerArray("Analyze80211ac", "prefOrderSignals",  [1, 2], 2)
    ret = iqxel.LP_Segms_Analyze80211ac(numOfAvg)
    Fetch_Results_Seg(3, 2, 2)
    ret = iqxel.LP_SetAnalysisParameterInteger("AnalyzeFFT", "useAllSignals", 1)
    ret = iqxel.LP_Segms_AnalyzeTechnologyFFT(numOfAvg, 0)
    Fetch_Mask_Results_Seg(3, 2)

def CW_Loopback():
    iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    selectedModules = [1]
    iqxel.LP_SetTesterMode(0, selectedModules, 1)
    print iqxel.LP_GetVersion()
    iqxel.LP_SetVsgCw(5180e6, 0, -10.0, 2)
    iqxel.LP_EnableVsgRF(1)
    iqxel.LP_SetVsa(5180e6, 0, 3)
    iqxel.LP_VsaDataCapture(250e-6, 1)
    iqxel.LP_AnalyzeCW()
    freqOff = iqxel.LP_GetScalarMeasurement("frequency")
    print freqOff

def WiFi_11ag_loopback_Seg():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_SetTesterMode(0, [1], 1)
    print iqxel.LP_GetVersion()
    # Set VSG to use Port #1 (enumeration "2")
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_OFDM-54.iqvsg", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    numOfAvg = 3
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 500e-6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "savedCapture")
    ret = iqxel.LP_Segms_Analyze80211ag(numOfAvg)
    Fetch_Results_Seg(3, 1, 1)
    ret = iqxel.LP_SetAnalysisParameterInteger("AnalyzeFFT", "useAllSignals", 1)
    ret = iqxel.LP_Segms_AnalyzeTechnologyFFT(numOfAvg, 0)
    Fetch_Mask_Results_Seg(3, 1)

def WiFi_11ag_loopback_2010():
    ret = iqxel.LP_Init(0, 0)
#    ret = iqxel.LP_InitTester("127.0.0.1")
    ret = iqxel.LP_InitTester("192.168.100.254")
    print iqxel.LP_GetVersion()
    # Set VSG to use Port #1 (enumeration "2")
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_OFDM-54.mod", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_VsaDataCapture(1000e-6)
    ret = iqxel.LP_AnalyzePower()
    print "P_av_no_gap_all_dBm = ", str(iqxel.LP_GetScalarMeasurement("P_av_no_gap_all_dBm"))

    ret = iqxel.LP_Analyze80211ag()
    Fetch_Results_2010_ag()

def WiFi_11b_loopback_Seg():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_SetTesterMode(0, [1], 1)
    print iqxel.LP_GetVersion()
    iqxel.LP_ScpiCommandSet("VSG1")
    ret = iqxel.LP_ScpiCommandQuery("ERR:ALL?")

    # Set VSG to use Port #1 (enumeration "2")
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [4, 4, 4, 4])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_CCK-11S.iqvsg", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    numOfAvg = 1
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 1500e-6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "savedCapture")
    ret = iqxel.LP_Segms_Analyze80211b(numOfAvg)
    Fetch_Results_802_11b_Seg(numOfAvg)
    ret = iqxel.LP_SetAnalysisParameterInteger("AnalyzeFFT", "useAllSignals", 1)
    ret = iqxel.LP_Segms_AnalyzeTechnologyFFT(numOfAvg, 3)
    Fetch_Mask_Results_Seg(numOfAvg, 1)

def WiFi_11b_loopback_2010():
    ret = iqxel.LP_Init(0, 0)
    ret = iqxel.LP_InitTester("127.0.0.1")
    print iqxel.LP_GetVersion()
    # Set VSG to use Port #1 (enumeration "2")
    ret = iqxel.LP_SetVsgNxN(5775e6, [0, 0, 0, 0], [2, 2, 2, 2])
    ret = iqxel.LP_SetVsgModulation(waveformDir + "WiFi_CCK-11S.mod", 0)
    ret = iqxel.LP_EnableVsgRFNxN(1, 1, 1, 1)
    ret = iqxel.LP_SetFrameCnt(0)
    # Set VSG to use Port #2 (enumeration "3")
    ret = iqxel.LP_SetVsaNxN(5775e6, [10, 10, 10, 10], [3, 3, 3, 3])
    ret = iqxel.LP_VsaDataCapture(1500e-6)
    ret = iqxel.LP_Analyze80211b()
    Fetch_Results_802_11b()

def Fetch_BT_Results_segm(numSegments, rate, pattern):
	for segment in range(1, numSegments + 1):
		print "Segment: " + str(segment)
		print "dataRateDetect: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "dataRateDetect"))
		if pattern == 'PATTERN_PRBS9':
			print "P_av_each_burst: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "P_av_each_burst_dBm")
			print "P_pk_each_burst: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "P_pk_each_burst_dBm")
			if rate == 'RATE_LE':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "leValid")) == 1:
					print "leIsCrcOk: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "leIsCrcOk"))
					print "leFreqOffset: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "leFreqOffset"))
					if int(iqxel.LP_GetScalarMeasurement("acpErrValid")) == 1:
						for i in range(0, 11):
							print "maxPowerAcpDbm %d: %f" % (i - 5, iqxel.LP_Segms_GetScalarMeasurement(segment, "maxPowerAcpDbm", i))
				else:
					print "Not a valid LE signal";
			elif rate == 'RATE_BDR':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "valid")) == 1:
					print "bandwidth20dB: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "bandwidth20dB"))
					print "payloadErrors: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "payloadErrors"))
					print "freq_est: " + str(iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_est"))
					if int(iqxel.LP_GetScalarMeasurement("acpErrValid")) == 1:
						for i in range(11):
							print "maxPowerAcpDbm %d: %f" % (i - 5, iqxel.LP_Segms_GetScalarMeasurement(segment, "maxPowerAcpDbm", i))
				else:
					print "Not a valid BDR signal";
			elif rate == 'RATE_EDR':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrEVMvalid")) == 1:
					print "freq_deviation: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_deviation")
					print "freq_deviationpktopk: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_deviationpktopk")
					print "freq_est: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_est")
					print "freq_estHeader: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_estHeader")
					print "EdrPayloadErrors: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrPayloadErrors")
					print "EdrEVMAv: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrEVMAv")
					print "EdrEVMpk: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrEVMpk")
					print "EdrPowDiffdB: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrPowDiffdB")
					print "EdrFreqExtremeEdronly: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrFreqExtremeEdronly")
					print "EdrprobEVM99pass: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrprobEVM99pass")
					print "EdrOmegaI: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrOmegaI")
					print "EdrExtremeOmega0: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrExtremeOmega0")
					print "EdrExtremeOmegaI0: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "EdrExtremeOmegaI0")
					if int(iqxel.LP_GetScalarMeasurement("acpErrValid")) == 1:
						for i in range(11):
							print "maxPowerEdrDbm %d: %f" % (i - 5, iqxel.LP_Segms_GetScalarMeasurement(segment, "maxPowerAcpDbm", i))
				else:
					print "Not a valid EDR signal"
		elif pattern == 'PATTERN_F0':
			if rate == 'RATE_LE':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "leValid")) == 1:
					print "leIsCrcOk: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leIsCrcOk")
					print "leDeltaF1Avg: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaF1Avg")
				else:
					print "Not a valid LE signal"
			if rate == 'RATE_BDR':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "valid")) == 1:
					print "deltaF1Average: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "deltaF1Average")
					print "freq_deviation: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_deviation")
					print "freq_deviationpktopk: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_deviationpktopk")
				else:
					print "Not a valid BDR signal"
		elif pattern == 'PATTERN_AA':
			if rate == 'RATE_LE':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "leValid")) == 1:
					print "leIsCrcOk: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leIsCrcOk")
					print "leDeltaF2Max: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaF2Max")
					print "leDeltaF2Avg: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaF2Avg")
					print "leFnMax: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leFnMax")
					print "leDeltaF0FnMax: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaF0FnMax")
					print "leDeltaF1F0: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaF1F0")
					print "leDeltaFnFn_5Max: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leDeltaFnFn_5Max")
					print "leFreqDevSyncAv: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "leFreqDevSyncAv")
				else:
					print "Not a valid LE signal"
			if rate == 'RATE_BDR':
				if int(iqxel.LP_Segms_GetScalarMeasurement(segment, "valid")) == 1:
					print "freq_drift: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_drift")
					print "freq_estHeader: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "freq_estHeader")
					print "maxfreqDriftRate: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "maxfreqDriftRate")
					print "deltaF2Max: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "deltaF2Max")
					print "deltaF2Average: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "deltaF2Average")
					print "deltaF2MaxAccess: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "deltaF2MaxAccess")
					print "deltaF2AvAccess: ", iqxel.LP_Segms_GetScalarMeasurement(segment, "deltaF2AvAccess")
				else:
					print "Not a valid BDR signal"

def Bluetooth_Loopback():
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTester(testerIP)
    print iqxel.LP_GetVersion()
    dutPowerLevel = 0.0
    ret = iqxel.LP_SetVsg(2402e6, dutPowerLevel, 2)
    ret = iqxel.LP_EnableVsgRF(1)
    peakToAverageRatio = 3
    ret = iqxel.LP_SetVsaBluetooth(2402e6, (dutPowerLevel+peakToAverageRatio), 3)
    numOfAvg = 3
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_3DH5_prbs9_Fs80M.iqvsg")
    frameCnt = 0
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture(numOfAvg, 3000e-6)
    ret = iqxel.LP_Segms_SaveVsaSignalFile(0, "BT_Capture.sig")
    datarate = 0
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    ret = Fetch_BT_Results_segm(numOfAvg, 'RATE_EDR', 'PATTERN_PRBS9')
# BDR PRBS9
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1DH5_prbs9_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    Fetch_BT_Results_segm(numOfAvg, 'RATE_BDR', 'PATTERN_PRBS9')

# BDR F0
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1DH5_00001111_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    ret = Fetch_BT_Results_segm(numOfAvg, 'RATE_BDR', 'PATTERN_F0')

#		// BDR AA
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1DH5_1010_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    Fetch_BT_Results_segm(numOfAvg, 'RATE_BDR', 'PATTERN_AA');

#		// LE PRBS9
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1LE_prbs9_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    Fetch_BT_Results_segm(numOfAvg, 'RATE_LE', 'PATTERN_PRBS9')

#		// LE F0
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1LE_11110000_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    Fetch_BT_Results_segm(numOfAvg, 'RATE_LE', 'PATTERN_F0')

#		// LE AA
    ret = iqxel.LP_SetVsgModulation(waveformDir + "BT_1LE_1010_Fs80M.iqvsg")
    ret = iqxel.LP_SetFrameCnt(0)
    ret = iqxel.LP_Segms_VsaDataCapture( numOfAvg, 3000e-6 )
    ret = iqxel.LP_Segms_AnalyzeBluetooth(numOfAvg, datarate, "AllPlus")
    Fetch_BT_Results_segm(numOfAvg, 'RATE_LE', 'PATTERN_AA')

    ret = iqxel.LP_EnableVsgRF(0)
    ret = iqxel.LP_Term()

def Zigbee_Loopback():
    # Initialize the IQTester 
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    selectedModules = [1];
    ret = iqxel.LP_SetTesterMode(0, selectedModules, 1)
    print iqxel.LP_GetVersion()
    dutPowerLevel = -20;
    # Setup VSG
    ret = iqxel.LP_SetVsg(2442e6, dutPowerLevel, 3)
    # Load waveform file
    ret = iqxel.LP_SetVsgModulation(waveformDir + "zigbee_250k_15bytes_80M.iqvsg", 0)
    # Turn on VSG 
    ret = iqxel.LP_EnableVsgRF(1)
    #  Send packet, continuous transmission
    ret = iqxel.LP_SetFrameCnt(0)
    #  Setup VSA
    peakToAverageRatio = 3;
    ret = iqxel.LP_SetVsa(2442e6, dutPowerLevel + peakToAverageRatio, 2)
    #  Perform VSA Capture
    ret = iqxel.LP_VsaDataCapture(500e-6, 6)
    # Save sig file for debug
    ret = iqxel.LP_SaveVsaSignalFile(".\\log\\Zigbee_Capture.sig")
    # Analyze Zigbee 
    datarate = 0;
    ret = iqxel.LP_AnalyzeZigbee()
    
    # Retrieve Test Results
    print "Datarate: ",("{0:.1f}".format( iqxel.LP_GetScalarMeasurement("rateInfo_dataRatebps"))),"kbps"
    print "avg_Peak_Power: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("rxPeakPowerDbm"))),"dBm"
    print "avg_Power: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement( "rxRmsPowerNoGapDbm"))),"dBm"
    
    print "EVM_All: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("evmAll"))),"%"
    print "EVM_PSDU: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("evmPsdu"))),"%"
    print "EVM_SHR_PHR: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("evmShrPhr"))),"%"
    print "EVM_Offset_All: ",("{0:.2f}".format( iqxel.LP_GetScalarMeasurement("evmAllOffset"))),"%"
    print "EVM_Offset_PSDU: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("evmOffsetPsduDb"))),"%"
    print "EVM_Offset_SHR_PHR: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("evmOffsetShrPhrDb"))),"%"
    
    print "Phase_Error: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("phaseNoiseDegRmsAll"))),"deg"
    print "Frequency_Error: ",("{0:.2f}".format( iqxel.LP_GetScalarMeasurement("freqOffsetFineHz"))),"Hz"
    print "Symbol_Clock_Error: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("symClockErrorPpm"))),"ppm"
    print "LO_Leakage: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("loLeakageDeg"))),"dB"
    print "Modulation_Index: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("sigType"))),"deg"
    print "Length_of_PSDU: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("psduLength"))),"bytes"
    print "Num_of_Symbols: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("numSymbols"))),"deg"
    
    # Analyze Power     
    ret = iqxel.LP_AnalyzePower()
    # Power Measurement Results

    print "valid: ", ("{0:.0f}".format(iqxel.LP_GetScalarMeasurement("valid")))," "
    print "P_av_each_burst_dBm: ",("{0:.2f}".format( iqxel.LP_GetScalarMeasurement("P_av_each_burst_dBm"))),"dBm"
    print "P_av_each_burst: ", ("{0:.6f}".format(iqxel.LP_GetScalarMeasurement("P_av_each_burst"))),"mw"
    print "P_pk_each_burst_dBm: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("P_pk_each_burst_dBm"))),"dBm"
    print "P_pk_each_burst: ", ("{0:.6f}".format(iqxel.LP_GetScalarMeasurement("P_pk_each_burst"))),"mw"
    print "P_av_all_dBm: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("P_av_all_dBm"))),"dBm"
    print "P_av_all: ", ("{0:.6f}".format(iqxel.LP_GetScalarMeasurement("P_av_all"))),"mw"
    print "P_peak_all_dBm: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("P_peak_all_dBm"))),"dBm"
    print "P_peak_all: ", ("{0:.6f}".format(iqxel.LP_GetScalarMeasurement("P_peak_all"))),"mw"
    print "P_av_no_gap_all_dBm: ", ("{0:.2f}".format(iqxel.LP_GetScalarMeasurement("P_av_no_gap_all_dBm"))),"dBm"
    print "P_av_no_gap_all: ", ("{0:.6f}".format(iqxel.LP_GetScalarMeasurement("P_av_no_gap_all"))),"mw"
    ret = iqxel.LP_EnableVsgRF(0)
    ret = iqxel.LP_Term()


def Scpi_Test():
    # Initialize the IQTester 
    ret = iqxel.LP_Init()
    ret = iqxel.LP_InitTesterN(testerIP, 1)
    ret = iqxel.LP_ScpiCommandSet("VSA12;FREQ:cent 2412000000")
    print iqxel.LP_ScpiCommandQuery("*IDN?")

if __name__ == '__main__':
#    WiFi_Siso_loopback_Seg()
#    WiFi_Siso_80MHz_loopback_Seg()
    WiFi_11ag_loopback_Seg()
#    WiFi_11b_loopback_Seg()
#    WiFi_11ag_loopback_2010()
#    WiFi_Mimo_loopback_M8_nxn_Seg()
#    Bluetooth_Loopback()
#    CW_Loopback()
#    Zigbee_Loopback()
    Scpi_Test()
