import os
from ctypes import *
import string
import math
from threading import Thread, Lock

class IQmeasureUtility:
    def __init__(self):
        return        

    def LP_GetLPWaveformFileName(self, standard, bandwidth, dataRate, streams = 1, longPreamble = 0):
        if standard == "AC":
            fname = "WiFi_11AC_VHT" + str(bandwidth) + "_S" + str(streams) + "_" + str(dataRate) + ".iqvsg"
        elif standard == "N":
            fname = "WiFi_HT" + str(bandwidth) + "_" + str(dataRate) + ".iqvsg"
        else:
            if longPreamble == 0:
                longOrShort = 'S'
            else:
                longOrShort = 'L'
            if dataRate == 1 or dataRate == 2:
                formatFamily = "DSSS"
                fname = "WiFi_" + formatFamily + "-" + str(dataRate) + longOrShort + ".iqvsg"
            elif dataRate == 5.5 or dataRate == 11:
                formatFamily = 'CCK'
                fname = "WiFi_" + formatFamily + "-" + str(dataRate).replace('.', '_') + longOrShort + ".iqvsg"
            else:
                formatFamily = "OFDM"
                fname = "WiFi_" + formatFamily + "-" + str(dataRate) + ".iqvsg"
        
        return fname
    
    def LP_GetLPWaveformFileNameBT(self, packet_type, bit_pattern):
        bitPatternStr = 'prbs9'
        if bit_pattern == 'F0':
            if packet_type == 'LE':
                bitPatternStr = '11110000'
            else:
                bitPatternStr = '00001111'
        elif bit_pattern == 'AA':
            bitPatternStr = '1010'
        
        if packet_type == 'LE':
            fname = 'BT_1LE_' + bitPatternStr + '_Fs80M.iqvsg'
        else:
            fname = 'BT_' + packet_type + '_' + bitPatternStr + '_Fs80M.iqvsg'
        return fname
    
    def LP_FindPathlossLoss(self, lossTable, freq):
        if freq in lossTable:
            return lossTable[freq]
        else:
            closestUpperDist = 9999
            closestLowerDist = 9999
            closestUpperFreq = 0
            closestLowerFreq = 0
            for k in lossTable:
                if k > freq and k - freq < closestUpperDist:
                    closestUpperDist = k - freq
                    closestUpperFreq = k
                elif k < freq and freq - k < closestLowerDist:
                    closestLowerDist = freq - k
                    closestLowerFreq = k
                    
            loss = ((lossTable[closestUpperFreq] - lossTable[closestLowerFreq]) *
                    ((freq - closestLowerFreq) / (closestUpperFreq - closestLowerFreq))) + lossTable[closestLowerFreq]
            return loss
    
    def GetMultiPacketsResults(self, numOfPackets, keyword, logType, index = 1):
        resultList = []
        for seg in range(numOfPackets):
            resultList.append(self.LP_Segms_GetScalarMeasurement(seg + 1, keyword, index))
        return self.AverageTestResult(resultList, logType)

    def AverageTestResult(self, resultArray, logType):
        NA_DOUBLE = -99999
        if len(resultArray) == 0:
            return {}
        else:
            maxVal = max(resultArray)
            minVal = min(resultArray)
            avgVal = 0
            if logType == "Linear":
                avgVal = sum(resultArray) / float(len(resultArray))
            elif logType == "Linear_Sum":
                for i in range(len(resultArray)):
                    avgVal = avgVal + pow(10, resultArray[i] / 10)
                if avgVal != 0:
                    avgVal = 10 * math.log10(avgVal)
                else:
                    avgVal = NA_DOUBLE
            elif logType == "LOG_20_EVM":
                for i in range(len(resultArray)):
                    avgVal = avgVal + math.pow(pow(10, resultArray[i] / 20), 2)
                avgVal = math.sqrt(avgVal / len(resultArray))
                if avgVal != 0:
                    avgVal = 20 * math.log10(avgVal)
                else:
                    avgVal = NA_DOUBLE
            else:
                if logType == "LOG_10":
                    deno = 10
                else:
                    deno = 20
                for i in range(len(resultArray)):
                    avgVal = avgVal + math.pow(10, resultArray[i] / deno)
                avgVal = avgVal / len(resultArray)
                if avgVal != 0:
                    avgVal = deno * math.log10(avgVal)
                else:
                    avgVal = NA_DOUBLE

            return {'avg' : avgVal, 'min' : minVal, 'max' : maxVal}

    def AddDataToResultList(self, currentResult, keyword, stream, value):
        if not keyword in currentResult:
            currentResult[keyword] = dict()
        if not stream in currentResult[keyword]:
            currentResult[keyword][stream] = []
        currentResult[keyword][stream].append(value)

    def AverageMeasurementResult(self, segmentData):
        averagedResult = dict()
        for measurement in segmentData:
            if not measurement in averagedResult:
                averagedResult[measurement] = dict()
            if 'POWER_DBM_RMS' in measurement and not 0 in segmentData[measurement]:
                if len(segmentData[measurement]) > 1:
                    sumList = [-1e300] * len(segmentData[measurement][segmentData[measurement].keys()[0]])
                    for strm in segmentData[measurement]:
                        sumList = [self.AverageTestResult(x, "Linear_Sum")['avg'] for x in zip(sumList, segmentData[measurement][strm])]
                    segmentData[measurement][0] = sumList

            for strm in segmentData[measurement]:
                if 'EVM_DB' in measurement:
                    averagedResult[measurement][strm] = self.AverageTestResult(segmentData[measurement][strm], "LOG_20")
                elif 'AMP_ERR_DB' in measurement or 'SPECTRAL_FLATNESS_MIN_MARGIN_CARRIER' in measurement or 'DBM' in measurement:
                    averagedResult[measurement][strm] = self.AverageTestResult(segmentData[measurement][strm], "LOG_10")
                else:
                    averagedResult[measurement][strm] = self.AverageTestResult(segmentData[measurement][strm], "Linear")

        return averagedResult
