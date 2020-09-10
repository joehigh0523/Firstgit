// IQmeasureTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IQmeasure.h"
#include "DebugAlloc.h"
#include "math.h"
#include "time.h"
#include <string>
#include <vector>
#include "IQmeasureTest.h"

#include <Windows.h>
#include <process.h>
#include <stdio.h>

#include <tchar.h>

#include <iostream>
#include <sstream>

using std::vector;
using std::string;


#ifndef NA_NUMBER
#define NA_NUMBER -99999.99
#endif

char    errMsg[MAX_BUFFER_SIZE];
int		Tag_runTime = 1;
char    g_csvFileName[128] = {'\0'};
BOOL    bExitFlag = FALSE;
char    g_IP_addr[128] = {'\0'};
char    g_IP_addr_1[128] = {'\0'};
char    g_IP_addr_2[128] = {'\0'};
char    g_IP_addr_3[128] = {'\0'};
char    g_IP_addr_4[128] = {'\0'};
int		ciTesterControlMode = 1;
int		ciTesterType = 1;
int     g_ConnectionType = 1;
int		g_isNewInitTesterInterface = 0;
int     g_DH_TOKEN_ID = 0;
int	    g_DH_PORT=0;



typedef struct
{
	vector<string>		LP_Init;
	vector<string>		LP_Term;
	vector<string>		LP_GetIQapiHndl;
	vector<string>		LP_InitTester;
	vector<string>		LP_InitTester2;
	vector<string>		LP_InitTester3;
	vector<string>		LP_InitTester4;
	vector<string>		LP_ConClose;
	vector<string>		LP_ConOpen;
	vector<string>		LP_GetErrorString;
	vector<string>		LP_GetVersion;
	vector<string>		LP_GetIQapiHndlLastErrMsg;
	vector<string>		LP_DualHead_ConOpen;
	vector<string>		LP_DualHead_GetTokenID;
	vector<string>		LP_DualHead_ConClose;
	vector<string>		LP_DualHead_ObtainControl;
	vector<string>		LP_DualHead_ReleaseControl;
	vector<string>		LP_FM_SetFrequency;
	vector<string>		LP_FM_SetCarrierPower;
	vector<string>		LP_SetVsg_GapPower;
	vector<string>		LP_SetVsg_PowerLevel;
	vector<string>		LP_SetVsgCw;
	vector<string>		LP_SaveSignalArrays;
	vector<string>		LP_SaveIQDataToModulationFile;
	vector<string>		LP_SetVsg;
	vector<string>		LP_SetVsgModulation;
	vector<string>		LP_EnableVsgRF;
	vector<string>		LP_SetVsa;
	vector<string>		LP_VsaDataCapture;
	vector<string>		LP_SaveVsaSignalFile;
	vector<string>		LP_AnalyzeFFT;
	vector<string>		LP_AnalyzePower;
	vector<string>		LP_Analyze80211ac;
	vector<string>		LP_SetAnalysisParameterInteger;
	vector<string>		LP_SetAnalysisParameterIntegerArray;
	vector<string>		LP_CopyVsaCaptureData;
	vector<string>		LP_LoadVsaSignalFile;
	vector<string>		LP_SaveVsaGeneratorFile;
	vector<string>		LP_SetVsaBluetooth;
	vector<string>		LP_SetVsaTriggerTimeout;
	vector<string>		LP_SetVsaAmplitudeTolerance;
	vector<string>		LP_Agc;
	vector<string>		LP_SetFrameCnt;
	vector<string>		LP_TxDone;
	vector<string>		LP_EnableSpecifiedVsgRF;
	vector<string>		LP_EnableSpecifiedVsaRF;
	vector<string>		LP_GetVsaSettings;
	vector<string>		LP_GetSampleData;
	vector<string>		LP_SelectCaptureRangeForAnalysis;
	vector<string>		LP_Analyze80216d;
	vector<string>		LP_Analyze80216e;
	vector<string>		LP_Analyze80211p;
	vector<string>		LP_Analyze80211ag;
	vector<string>		LP_Analyze80211n;
	vector<string>		LP_AnalyzeMimo;
	vector<string>		LP_Analyze80211b;
	vector<string>		LP_AnalyzeCCDF;
	vector<string>		LP_AnalyzeCW;
	vector<string>		LP_AnalyzeCWFreq;
	vector<string>		LP_AnalysisWave;
	vector<string>		LP_AnalyzeSidelobe;
	vector<string>		LP_AnalyzePowerRampOFDM;
	vector<string>		LP_AnalyzePowerRamp80211b;
	vector<string>		LP_AnalyzeBluetooth;
	vector<string>		LP_AnalyzeZigbee;
	vector<string>		LP_AnalyzeDECT;
	vector<string>		LP_AnalyzeHT40Mask;
	vector<string>      LP_AnalyzeGPRFSpectrum;
	vector<string>		LP_GetScalarMeasurement;
	vector<string>		LP_GetVectorMeasurment;
	vector<string>		LP_GetStringMeasurment;
	vector<string>		LP_GetStringMeasurement;
	vector<string>		LP_PlotDataCapture;
	vector<string>		LP_Plot;
	vector<string>		LP_StartIQmeasureTimer;
	vector<string>		LP_StopIQmeasureTimer;
	vector<string>		LP_ReportTimerDurations;
	vector<string>		LP_SetTesterHwVersion;
	vector<string>		LP_GetTesterHwVersion;
	vector<string>		LP_SetLpcPath;
	vector<string>		LP_FM_SetVsg;
	vector<string>		LP_FM_GetVsgSettings;
	vector<string>		LP_FM_SetAudioSingleTone;
	vector<string>		LP_FM_SetAudioToneArray;
	vector<string>		LP_FM_DeleteAudioTones;
	vector<string>		LP_FM_StartVsg;
	vector<string>		LP_FM_StopVsg;
	vector<string>		LP_FM_SetVsgDistortion;
	vector<string>		LP_FM_GetVsgDistortion;
	vector<string>		LP_FM_StartVsgInterference;
	vector<string>		LP_FM_GetVsgInterferenceSettings;
	vector<string>		LP_FM_StopVsgInterference;
	vector<string>		LP_FM_SetVsa;
	vector<string>		LP_FM_GetVsaSettings;
	vector<string>		LP_FM_VsaDataCapture;
	vector<string>		LP_FM_Analyze_RF;
	vector<string>		LP_FM_Analyze_Demod;
	vector<string>		LP_FM_Analyze_Audio_Mono;
	vector<string>		LP_FM_Analyze_Audio_Stereo;
	vector<string>		LP_FM_GetScalarMeasurement;
	vector<string>		LP_FM_GetVectorMeasurement;
	vector<string>		LP_FM_AudioDataCapture;
	vector<string>		LP_FM_LoadAudioCapture;
	vector<string>		LP_FM_AudioStimulusGenerateAndPlayMultiTone;
	vector<string>		LP_FM_AudioStimulusGenerateAndPlaySingleTone;
	vector<string>		LP_FM_StopAudioPlay;
	vector<string>		LP_SaveVsaSignalFileText;
	vector<string>		LP_SaveTruncateCapture;
	vector<string>		LP_PwrCalFastGetElement;
	vector<string>		LP_FM_SetAudioToneModeAmplitude;
	vector<string>		LP_SetVsg_triggerType;
	vector<string>		LP_AnalyzeVHT80Mask;
	vector<string>		LP_FastCalGetPowerData;
	vector<string>		LP_PwrCalFreeElement;
	vector<string>		LP_FastCalMeasPower;
	vector<string>      SetTesterHwVersion;
	vector<string>		LP_GetVectorMeasurement;
	vector<string>		GetTesterHwVersion;
	vector<string>		LP_FM_SetAudioToneArrayDeviation;
	vector<string>		LP_GetScalarMeasurment;
	vector<string>		LP_AnalyzeZigbeeTerm;
	vector<string>		LP_PwrCalFastGetElemen;
	vector<string>		LP_FM_GetAudioToneArray;
	vector<string>		LP_others;
}strcutResult;

void QA_Multithread(vector<string>* testerIPVector);

static void set_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)color);
}

unsigned int GetElapsedMSec(lp_time_t start, lp_time_t end)
{
	unsigned int time_ms = (unsigned int) (
			(end.time - start.time) * 1000
			+ (end.millitm - start.millitm)
			);
	return time_ms;
}

void CheckReturnCode( int returnCode, char *functionName)
{
	if( ERR_OK!=returnCode )
	{
		//TODO
		if( NULL!=functionName )
		{
			sprintf_s(errMsg, MAX_BUFFER_SIZE, "%s returned error: %d", functionName, returnCode);
		}
		else
		{
			sprintf_s(errMsg, MAX_BUFFER_SIZE, "Error code: %d", returnCode);
		}
		throw errMsg;
	}
	else
		printf("%s, return OK.\n", functionName);

	return;
}

void PrintErrorStatus( int status, char * pFunctionName )
{
	printf("***************************************************************\n");
	if ( status != IQMT_ERR_OK )
	{
		printf("* Function %s\t\t FAILED with errors!!!!\n", pFunctionName );
	}
	else
	{
		printf("* Function %s\t\t PASSED with no errors.\n", pFunctionName );
	}
	printf("***************************************************************\n");
}

int splitAsDoubles(char* stringToSplit, double *doubleArray, int dataNumExpected=0, char * delimiters=",")
{
	//split an input string, interpret each segment as a double, and return all double values to doubleArray[]

	char *XP = NULL;
	int num  = 0;       // how many sub_string obtained
	XP = strtok(stringToSplit, delimiters);
	while (XP != NULL)
	{
		doubleArray[num] = atof(XP);
		XP = strtok (NULL, ",;");
		num++;
		if ((dataNumExpected>0) && (num == dataNumExpected)) break;
	}
	return num;
}


double evmLinearAverage(double *resultArray, int averageTimes, double &averageResult, double &maxResult, double &minResult)
{
	int err=0;
	averageResult = 0.0;
	maxResult = minResult = resultArray[0];
	for (int i=0; i<averageTimes; i++)
	{
		if (resultArray[i]<minResult)
			minResult=resultArray[i];
		if (resultArray[i]>maxResult)
			maxResult=resultArray[i];
		averageResult+=resultArray[i];
	}
	averageResult=averageResult/averageTimes;

	return err;
}

void WiFi_11ag_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_OFDM-54.iqvsg"), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 10;
		CheckReturnCode( LP_SetVsa(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsaBluetooth()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture(SAMPLING_TIME_SEC, VSA_TRIGGER_TYPE), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		CheckReturnCode( LP_SaveVsaSignalFile("WiFi_Capture.sig"), "LP_SaveVsaSignalFile()" );

		double result;
		CheckReturnCode( LP_AnalyzePower(), "LP_AnalyzePower()" );

		result = LP_GetScalarMeasurement("valid");
		printf("valid=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst");
		printf("P_av_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
		printf("P_av_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst");
		printf("P_pk_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
		printf("P_pk_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all");
		printf("P_av_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all");
		printf("P_peak_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all");
		printf("P_av_no_gap_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all_dBm");
		printf("P_av_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all_dBm");
		printf("P_peak_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
		printf("P_av_no_gap_all_dBm=%.3f \n", result);

		//------------------------//
		//  Perform WiFi analysis //
		//------------------------//
		CheckReturnCode( LP_Analyze80211ag(), "LP_Analyze80211ag()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		result = LP_GetScalarMeasurement("psduCrcFail");
		printf("psduCrcFail=%.3f \n", result);

		result = LP_GetScalarMeasurement("dataRate");
		printf("Datarate=%.1f Mbps\n", result);

		result = LP_GetScalarMeasurement("numSymbols");
		printf("numSymbols=%.3f \n", result);

		result = LP_GetScalarMeasurement("numPsduBytes");
		printf("numPsduBytes=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmAll");
		printf("EVM_All=%.3f dB\n", result);

		result = LP_GetScalarMeasurement("evmData");
		printf("evmData=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmPilot");
		printf("evmPilot=%.3f \n", result);

		result = LP_GetScalarMeasurement("codingRate");
		printf("codingRate=%.3f \n", result);

		result = LP_GetScalarMeasurement("freqErr");
		printf("freqErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("clockErr");
		printf("clockErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErr");
		printf("ampErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErrDb");
		printf("ampErrDb=%.3f \n", result);

		result = LP_GetScalarMeasurement("phaseErr");
		printf("phaseErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPhaseNoise");
		printf("rmsPhaseNoise=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPowerNoGap");
		printf("Power_NoGap=%.3f dBm\n", result);

		result = LP_GetScalarMeasurement("rmsPower");
		printf("rmsPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("pkPower");
		printf("pkPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsMaxAvgPower");
		printf("rmsMaxAvgPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("dcLeakageDbc");
		printf("dcLeakageDbc=%.3f \n", result);

		double hhEstRealArray [MAX_BUFFER_SIZE] = {0.0};
		double hhEstImagArray [MAX_BUFFER_SIZE] = {0.0};
		double psduRealArray [MAX_BUFFER_SIZE] = {0.0};
		double psduImagArray [MAX_BUFFER_SIZE] = {0.0};
		double startPointersRealArray [MAX_BUFFER_SIZE] = {0.0};
		double startPointersImagArray [MAX_BUFFER_SIZE] = {0.0};
		double plcpRealArray [MAX_BUFFER_SIZE] = {0.0};
		double plcpImagArray [MAX_BUFFER_SIZE] = {0.0};

		int hhEstArrayLength = LP_GetVectorMeasurement("hhEst", hhEstRealArray, hhEstImagArray, MAX_BUFFER_SIZE);
		int psduArrayLength = LP_GetVectorMeasurement("psdu", psduRealArray, psduImagArray, MAX_BUFFER_SIZE);
		int startPointersArrayLength = LP_GetVectorMeasurement("startPointers", startPointersRealArray, startPointersImagArray, MAX_BUFFER_SIZE);
		int plcpArrayLength = LP_GetVectorMeasurement("plcp", plcpRealArray, plcpImagArray, MAX_BUFFER_SIZE);

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "-wifi-ag" );
}

void WiFi_11b_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(1,1), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_CCK-5_5S.iqvsg"), "LP_SetVsgModulation()" );//TODO change to 11b modulation file

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 10;
		CheckReturnCode( LP_SetVsa(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsaBluetooth()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture(SAMPLING_TIME_SEC, VSA_TRIGGER_TYPE), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		CheckReturnCode( LP_SaveVsaSignalFile("WiFi_Capture.iqvsa"), "LP_SaveVsaSignalFile()" );

		double result;
		CheckReturnCode( LP_AnalyzeSidelobe(), "LP_AnalyzeSidelobe()" );
		
		result = LP_GetScalarMeasurement("peak_2_left");
		printf("peak_2_left=%.3f \n", result);

		result = LP_GetScalarMeasurement("peak_1_left");
		printf("peak_1_left=%.3f \n", result);

		result = LP_GetScalarMeasurement("peak_center");
		printf("peak_center=%.3f \n", result);

		result = LP_GetScalarMeasurement("peak_2_right");
		printf("peak_2_right=%.3f \n", result);

		result = LP_GetScalarMeasurement("peak_1_right");
		printf("peak_2_right=%.3f \n", result);

		CheckReturnCode( LP_AnalyzePower(), "LP_AnalyzePower()" );

		result = LP_GetScalarMeasurement("valid");
		printf("valid=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst");
		printf("P_av_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
		printf("P_av_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst");
		printf("P_pk_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
		printf("P_pk_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all");
		printf("P_av_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all");
		printf("P_peak_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all");
		printf("P_av_no_gap_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all_dBm");
		printf("P_av_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all_dBm");
		printf("P_peak_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
		printf("P_av_no_gap_all_dBm=%.3f \n", result);

		//------------------------//
		//  Perform WiFi analysis //
		//------------------------//
		CheckReturnCode( LP_Analyze80211b(), "LP_Analyze80211b()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		result = LP_GetScalarMeasurement("lockedClock");
		printf("lockedClock=%.3f \n", result);

		result = LP_GetScalarMeasurement("plcpCrcFail");
		printf("plcpCrcFail=%.3f \n", result);

		result = LP_GetScalarMeasurement("psduCrcFail");
		printf("psduCrcFail=%.3f \n", result);

		result = LP_GetScalarMeasurement("longPreamble");
		printf("longPreamble=%.3f \n", result);

		result = LP_GetScalarMeasurement("bitRateInMHz");
		printf("bitRateInMHz=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmPk");
		printf("evmPk=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmAll");
		printf("evmAll=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmInPreamble");
		printf("evmInPreamble=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmInPsdu");
		printf("evmInPsdu=%.3f \n", result);

		result = LP_GetScalarMeasurement("freqErr");
		printf("freqErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("clockErr");
		printf("clockErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErr");
		printf("ampErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErrDb");
		printf("ampErrDb=%.3f \n", result);

		result = LP_GetScalarMeasurement("phaseErr");
		printf("phaseErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPhaseNoise");
		printf("rmsPhaseNoise=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPowerNoGap");
		printf("rmsPowerNoGap=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPower");
		printf("rmsPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("pkPower");
		printf("pkPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsMaxAvgPower");
		printf("rmsMaxAvgPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("bitRate");
		printf("bitRate=%.3f \n", result);

		result = LP_GetScalarMeasurement("modType");
		printf("modType=%.3f \n", result);

		double evmInPlcpRealArray [MAX_BUFFER_SIZE] = {0.0};
		double evmInPlcpImagArray [MAX_BUFFER_SIZE] = {0.0};
		double evmErrRealArray [MAX_BUFFER_SIZE] = {0.0};
		double evmErrImagArray [MAX_BUFFER_SIZE] = {0.0};
		double loLeakageDbRealArray [MAX_BUFFER_SIZE] = {0.0};
		double loLeakageDbImagArray [MAX_BUFFER_SIZE] = {0.0};

		int evmInPlcpArrayLength = LP_GetVectorMeasurement("evmInPlcp", evmInPlcpRealArray, evmInPlcpImagArray, MAX_BUFFER_SIZE);
		int evmErrArrayLength = LP_GetVectorMeasurement("evmErr", evmErrRealArray, evmErrImagArray, MAX_BUFFER_SIZE);
		int loLeakageDbArrayLength = LP_GetVectorMeasurement("loLeakageDb", loLeakageDbRealArray, loLeakageDbImagArray, MAX_BUFFER_SIZE);

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "-wifi-b" );
}


void WiFi_11ah_Loopback()
{
	int	   status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester
	double freqAh = 900e6;
	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(1,1), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(freqAh, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_11AH_BW1_3Mbps.iqvsg"), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 10;
		CheckReturnCode( LP_SetVsa(freqAh, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsaBluetooth()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture(SAMPLING_TIME_SEC*8, VSA_TRIGGER_TYPE), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		CheckReturnCode( LP_SaveVsaSignalFile("WiFi_11ah_Capture.iqvsa"), "LP_SaveVsaSignalFile()" );

		double result;
		CheckReturnCode( LP_AnalyzePower(), "LP_AnalyzePower()" );

		result = LP_GetScalarMeasurement("valid");
		printf("valid=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst");
		printf("P_av_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
		printf("P_av_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst");
		printf("P_pk_each_burst=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
		printf("P_pk_each_burst_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all");
		printf("P_av_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all");
		printf("P_peak_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all");
		printf("P_av_no_gap_all=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_all_dBm");
		printf("P_av_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_peak_all_dBm");
		printf("P_peak_all_dBm=%.3f \n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
		printf("P_av_no_gap_all_dBm=%.3f \n", result);

		//------------------------//
		//  Perform WiFi analysis //
		//------------------------//
		CheckReturnCode( LP_Analyze80211ah(), "LP_Analyze80211ah()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		result = LP_GetScalarMeasurement("psduCrcFail");
		printf("psduCrcFail=%.3f \n", result);

		result = LP_GetScalarMeasurement("dataRate");
		printf("Datarate=%.1f Mbps\n", result);

		result = LP_GetScalarMeasurement("numSymbols");
		printf("numSymbols=%.3f \n", result);

		result = LP_GetScalarMeasurement("numPsduBytes");
		printf("numPsduBytes=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmAll");
		printf("EVM_All=%.3f dB\n", result);

		result = LP_GetScalarMeasurement("evmData");
		printf("evmData=%.3f \n", result);

		result = LP_GetScalarMeasurement("evmPilot");
		printf("evmPilot=%.3f \n", result);

		result = LP_GetScalarMeasurement("codingRate");
		printf("codingRate=%.3f \n", result);

		result = LP_GetScalarMeasurement("freqErr");
		printf("freqErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("clockErr");
		printf("clockErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErr");
		printf("ampErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("ampErrDb");
		printf("ampErrDb=%.3f \n", result);

		result = LP_GetScalarMeasurement("phaseErr");
		printf("phaseErr=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPhaseNoise");
		printf("rmsPhaseNoise=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsPowerNoGap");
		printf("Power_NoGap=%.3f dBm\n", result);

		result = LP_GetScalarMeasurement("rmsPower");
		printf("rmsPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("pkPower");
		printf("pkPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("rmsMaxAvgPower");
		printf("rmsMaxAvgPower=%.3f \n", result);

		result = LP_GetScalarMeasurement("dcLeakageDbc");
		printf("dcLeakageDbc=%.3f \n", result);

		double hhEstRealArray [MAX_BUFFER_SIZE] = {0.0};
		double hhEstImagArray [MAX_BUFFER_SIZE] = {0.0};
		double psduRealArray [MAX_BUFFER_SIZE] = {0.0};
		double psduImagArray [MAX_BUFFER_SIZE] = {0.0};
		double startPointersRealArray [MAX_BUFFER_SIZE] = {0.0};
		double startPointersImagArray [MAX_BUFFER_SIZE] = {0.0};
		double plcpRealArray [MAX_BUFFER_SIZE] = {0.0};
		double plcpImagArray [MAX_BUFFER_SIZE] = {0.0};

		int hhEstArrayLength = LP_GetVectorMeasurement("hhEst", hhEstRealArray, hhEstImagArray, MAX_BUFFER_SIZE);
		int psduArrayLength = LP_GetVectorMeasurement("psdu", psduRealArray, psduImagArray, MAX_BUFFER_SIZE);
		int startPointersArrayLength = LP_GetVectorMeasurement("startPointers", startPointersRealArray, startPointersImagArray, MAX_BUFFER_SIZE);
		int plcpArrayLength = LP_GetVectorMeasurement("plcp", plcpRealArray, plcpImagArray, MAX_BUFFER_SIZE);

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "-wifi-ah" );
}

void Zigbee_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		//the second parameter (0: using IQApi, 1: using SCPI), STRONGLY recommend using SCPI.
		CheckReturnCode( LP_Init(ciTesterType, ciTesterControlMode), "LP_Init()" ); //changed hard coded testerType & control mode

		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );

		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)
			printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/zigbee_250k_15bytes_80M.iqvsg",0), "LP_SetVsgModulation()" ); //changed waveform path to be relative
		

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 3;
		CheckReturnCode( LP_SetVsa(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsa()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture( SAMPLING_TIME_SEC, VSA_TRIGGER_TYPE), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		//CheckReturnCode( LP_SaveVsaSignalFile("BT_Capture.sig"), "LP_SaveVsaSignalFile()" );
		CheckReturnCode( LP_SaveVsaSignalFile(".\\log\\Zigbee_Capture.sig"), "LP_SaveVsaSignalFile()" );

		//-----------------------------//
		//  Perform Zigbee analysis //
		//-----------------------------//
		double datarate = 0;	// 0 (auto), or 1, 2, 3
		CheckReturnCode( LP_AnalyzeZigbee(), "LP_AnalyzeZigbee()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		double result;
		result = LP_GetScalarMeasurement("rateInfo_dataRatebps",0);
		printf("Datarate=%.1f kbps\n", result/1000);
		result = LP_GetScalarMeasurement("rxPeakPowerDbm",0);
		printf("avg_Peak_Power=%.2f dBm\n", result);
		result = LP_GetScalarMeasurement("rxRmsPowerNoGapDbm",0);
		printf("avg_Power=%.2f dBm\n", result);
		result = LP_GetScalarMeasurement("evmAll",0);
		//changing the unit of EVM measurements from 'dB' to '%' -Aditya 12/01/15
		printf("EVM_All=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("evmPsdu",0);
		printf("EVM_PSDU=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("evmShrPhr",0);
		printf("EVM_SHR_PHR=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("evmAllOffset",0);
		printf("EVM_Offset_All=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("evmOffsetPsduDb",0);
		printf("EVM_Offset_PSDU=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("evmOffsetShrPhrDb",0);
		printf("EVM_Offset_SHR_PHR=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("phaseNoiseDegRmsAll",0);
		printf("Phase_Error=%.2f deg\n", result);
		result = LP_GetScalarMeasurement("freqOffsetFineHz",0);
		printf("Frequency_Error=%.2f Hz\n", result);
		result = LP_GetScalarMeasurement("symClockErrorPpm",0);
		printf("Symbol_Clock_Error=%.2f ppm\n", result);
		result = LP_GetScalarMeasurement("loLeakageDeg",0);
		printf("LO_Leakage=%.2f dB\n", result);
		result = LP_GetScalarMeasurement("sigType",0);
		printf("Modulation_Index=%.2f \n", result);
		result = LP_GetScalarMeasurement("psduLength",0);
		printf("Length_of_PSDU=%.2f bytes\n", result);
		result = LP_GetScalarMeasurement("numSymbols",0);
		printf("Num_of_Symbols=%.2f \n", result);


		double specofreqReal[MAX_BUFFER_SIZE]= {0.0};
		double specofreqImag[MAX_BUFFER_SIZE]= {0.0};
		double specReal[MAX_BUFFER_SIZE] = {0.0};
		double specImag[MAX_BUFFER_SIZE] = {0.0};
		LP_GetVectorMeasurement("x",specofreqReal,specofreqImag,MAX_BUFFER_SIZE);
		LP_GetVectorMeasurement("y",specReal,specImag,MAX_BUFFER_SIZE);
		
		

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "zigbee" );
}

void WiSUN_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		//the second parameter (0: using IQApi, 1: using SCPI), STRONGLY recommend using SCPI
		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" );

		CheckReturnCode( LP_InitTester("192.168.13.176"), "LP_InitTester()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
 		CheckReturnCode( LP_SetVsg(FREQ_HZ, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WISUN_2FSK_50K_Fs20M.iqvsg",0), "LP_SetVsgModulation()" );
		

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 3;
		CheckReturnCode( LP_SetVsa(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsa()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture( 10e-3, 6, 20e6), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		//CheckReturnCode( LP_SaveVsaSignalFile("BT_Capture.sig"), "LP_SaveVsaSignalFile()" );
		CheckReturnCode( LP_SaveVsaSignalFile(".\\log\\Zigbee_Capture.iqvsa"), "LP_SaveVsaSignalFile()" );

		//-----------------------------//
		//  Perform Zigbee analysis //
		//-----------------------------//
		double datarate = 0;	// 0 (auto), or 1, 2, 3
		CheckReturnCode( LP_AnalyzeWiSUN(FSK, MOD_2FSK), "LP_AnalyzeWiSUN()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		double result;
		result = LP_GetScalarMeasurement("rateInfo_dataRatebps",0);
		printf("Datarate=%.1f kbps\n", result/1000);
		result = LP_GetScalarMeasurement("rxPeakPowerDbm",0);
		printf("avg_Peak_Power=%.2f dBm\n", result);
		result = LP_GetScalarMeasurement("rxRmsPowerNoGapDbm",0);
		printf("avg_Power=%.2f dBm\n", result);
		result = LP_GetScalarMeasurement("max_freqDeviation",0);
		printf("max_freqDeviation=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("min_freqDeviation",0);
		printf("min_freqDeviation=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("rms_zeroCrossingErr",0);
		printf("rms_zeroCrossingErr=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("peak_zeroCrossingErr",0);
		printf("peak_zeroCrossingErr=%.2f%%\n", result);
		result = LP_GetScalarMeasurement("carrier_freq_offset",0);
		printf("carrier_freq_offset=%.2f Hz\n", result);
		result = LP_GetScalarMeasurement("symClockErrorPpm",0);
		printf("symClockErrorPpm=%.2f ppm\n", result);
		result = LP_GetScalarMeasurement("symClockJitterPpm",0);
		printf("symClockJitterPpm=%.2f ppm\n", result);
		//result = LP_GetScalarMeasurement("freqOffsetFineHz",0);
		//printf("Frequency_Error=%.2f Hz\n", result);
		//result = LP_GetScalarMeasurement("symClockErrorPpm",0);
		//printf("Symbol_Clock_Error=%.2f ppm\n", result);
		//result = LP_GetScalarMeasurement("loLeakageDeg",0);
		//printf("LO_Leakage=%.2f dB\n", result);
		result = LP_GetScalarMeasurement("sigType",0);
		printf("Modulation_Index=%.2f \n", result);
		result = LP_GetScalarMeasurement("psduLength",0);
		printf("Length_of_PSDU=%.2f bytes\n", result);
		result = LP_GetScalarMeasurement("numSymbols",0);
		printf("Num_of_Symbols=%.2f \n", result);


		double specofreqReal[MAX_BUFFER_SIZE]= {0.0};
		double specofreqImag[MAX_BUFFER_SIZE]= {0.0};
		double specReal[MAX_BUFFER_SIZE] = {0.0};
		double specImag[MAX_BUFFER_SIZE] = {0.0};
		LP_GetVectorMeasurement("x",specofreqReal,specofreqImag,MAX_BUFFER_SIZE);
		LP_GetVectorMeasurement("y",specReal,specImag,MAX_BUFFER_SIZE);
		
		

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "zigbee" );
}

void FM_Test()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		//the second parameter (0: using IQApi, 1: using SCPI)
		//const int ciTesterControlMode = 1;
		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" );

		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_FM_DeleteAudioTones(), "LP_FM_DeleteAudioTones()" );

		
		//-------------//
		//  Setup VSG  //
		//-------------//
 		CheckReturnCode( LP_FM_SetVsg(100000000, -35, 1, 75000, 1, 7500, 1, 2000, 3), "LP_FM_SetVsg()" );		

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_FM_SetAudioSingleTone(1000, 0, 100, 1), "LP_FM_SetAudioSingleTone()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		CheckReturnCode( LP_FM_StartVsg(), "LP_FM_StartVsg()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		CheckReturnCode( LP_FM_StopVsg(), "LP_FM_StopVsg()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "FM" );
}

void Bluetooth_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		//the second parameter (0: using IQApi, 1: using SCPI)
		//const int ciTesterControlMode = 1;
		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" );

		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ, dutPowerLevel, PORT_LEFT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/2DH1_000088C0FFEE.iqvsg"), "LP_SetVsgModulation()" );
		
		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 3;
		CheckReturnCode( LP_SetVsaBluetooth(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_RIGHT), "LP_SetVsaBluetooth()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture( SAMPLING_TIME_SEC, VSA_TRIGGER_TYPE), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		//CheckReturnCode( LP_SaveVsaSignalFile("BT_Capture.sig"), "LP_SaveVsaSignalFile()" );
		CheckReturnCode( LP_SaveVsaSignalFile(".\\log\\BT_Capture"), "LP_SaveVsaSignalFile()" );

		//-----------------------------//
		//  Perform Bluetooth analysis //
		//-----------------------------//
		double datarate = 0;	// 0 (auto), or 1, 2, 3
		CheckReturnCode( LP_AnalyzeBluetooth(datarate), "LP_AnalyzeBluetooth()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		double result;
		result = LP_GetScalarMeasurement("dataRateDetect",0);
		printf("Datarate=%.1f Mbps\n", result);
		result = LP_GetScalarMeasurement("valid",0);
		result = LP_GetScalarMeasurement("bandwidth20dB",0);
		result = LP_GetScalarMeasurement("deltaF1Average",0);
		result = LP_GetScalarMeasurement("deltaF2Max",0);
		result = LP_GetScalarMeasurement("deltaF2Average",0);
		result = LP_GetScalarMeasurement("deltaF2MaxAccess",0);
		result = LP_GetScalarMeasurement("deltaF2AvAccess",0);
		result = LP_GetScalarMeasurement("EdrEVMAv",0);
		printf("EDR_DEVM_Av=%.3f %c\n", result*100, '%');
		result = LP_GetScalarMeasurement("EdrEVMpk",0);
		printf("EDR_DEVM_Peak=%.3f %c\n", result*100, '%');
		result = LP_GetScalarMeasurement("EdrEVMvalid",0);
		result = LP_GetScalarMeasurement("EdrPowDiffdB",0);
		printf("EDR_Diff_Power=%.3f dB\n", result);
		result = LP_GetScalarMeasurement("freq_deviation",0);
		result = LP_GetScalarMeasurement("freq_deviationpktopk",0);
		result = LP_GetScalarMeasurement("freq_estHeader",0);
		result = LP_GetScalarMeasurement("EdrFreqExtremeEdronly",0);
		result = LP_GetScalarMeasurement("EdrprobEVM99pass",0);
		result = LP_GetScalarMeasurement("EdrEVMvsTime",0);
		result = LP_GetScalarMeasurement("validInput",0);
		result = LP_GetScalarMeasurement("maxfreqDriftRate",0);
		result = LP_GetScalarMeasurement("payloadErrors",0);

		result = LP_GetScalarMeasurement("max_freq_est",0);
		printf("max_freq_estk=%.3f Hz\n", result);
		result = LP_GetScalarMeasurement("max_freq_drift",0);
		printf("max_freq_drift=%.3f Hz\n", result);
		result = LP_GetScalarMeasurement("max_freq_estHeader",0);
		printf("max_freq_estHeader=%.3f Hz\n", result);
		result = LP_GetScalarMeasurement("max_EdrExtremeOmega0",0);
		printf("max_EdrOmegaI=%.3f Hz\n", result);
		result = LP_GetScalarMeasurement("max_EdrOmegaI",0);
		printf("max_EdrOmegaI=%.3f Hz\n", result);
		result = LP_GetScalarMeasurement("max_EdrExtremeOmegaI0",0);
		printf("max_EdrExtremeOmegaI0=%.3f Hz\n", result);
		

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "bt" );
}

void Fft_Loopback()
{

	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ_5G, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_11AC_VHT80_S1_MCS5.iqvsg",0), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0; //100;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 10;
		CheckReturnCode( LP_SetVsa(FREQ_HZ, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsa()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		int vsaTrigger = 6;
		CheckReturnCode( LP_VsaDataCapture(SAMPLING_TIME_SEC, vsaTrigger), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		CheckReturnCode( LP_SaveVsaSignalFile("SNR_Capture.sig"), "LP_SaveVsaSignalFile()" );

		CheckReturnCode( LP_AnalyzeTechnologyFFT(), "LP_AnalyzeFFT()");

		double result;
		result = LP_GetScalarMeasurement("valid");
		printf("valid=%.3f \n", result);

		result = LP_GetScalarMeasurement("length");
		printf("length=%.3f \n", result);

		result = LP_GetScalarMeasurement("spectrumAverViolationPercentage");
		printf("spectrumAverViolationPercentage=%.3f \n", result);

		result = LP_GetScalarMeasurement("spectrumAverObw");
		printf("spectrumAverObw=%.3f \n", result);

		result = LP_GetScalarMeasurement("spectrumAverObwLowerFreq");
		printf("spectrumAverObwLowerFreq=%.3f \n", result);

		result = LP_GetScalarMeasurement("spectrumAverObwUpperFreq");
		printf("spectrumAverObwUpperFreq=%.3f \n", result);

		double xRealArray [MAX_BUFFER_SIZE] = {0.0};
		double xImagArray [MAX_BUFFER_SIZE] = {0.0};
		double yRealArray [MAX_BUFFER_SIZE] = {0.0};
		double yImagArray [MAX_BUFFER_SIZE] = {0.0};

		int xArrayLength = LP_GetVectorMeasurement("x", xRealArray, xImagArray, MAX_BUFFER_SIZE);
		int yArrayLength = LP_GetVectorMeasurement("y", yRealArray, yImagArray, MAX_BUFFER_SIZE);

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );

	}
	catch(char *msg)
	{
		printf("Exception thrown: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf("Exception thrown without msg!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "fft" );

}

void DECT_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = 0;		// Estimated RMS power level at IQTester

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		//the second parameter (0: using IQApi, 1: using SCPI)
		//const int ciTesterControlMode = 1;
		CheckReturnCode( LP_Init(IQTYPE_XEL, ciTesterControlMode), "LP_Init()" );

		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(1888.704e6, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("/DECT/DECT_DL_P32_Fs10M.iqvsg", 1), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int band = 1;
		int carrier = 5;
		int peakToAverageRatio = 3;
		CheckReturnCode( LP_SetVsaDECT(1888.704e6, (dutPowerLevel+peakToAverageRatio), PORT_LEFT), "LP_SetVsaDECT()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		CheckReturnCode( LP_VsaDataCapture( 0.05, 6, 10e6), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
	
		CheckReturnCode( LP_SaveVsaSignalFile("DECT_Capture"), "LP_SaveVsaSignalFile()" );

		//-----------------------------//
		//  Perform Bluetooth analysis //
		//-----------------------------//
		
		CheckReturnCode( LP_AnalyzeDECT("All"), "LP_AnalyzeDECT()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		double result;
		result = LP_GetScalarMeasurement("P_av_all",0);
		printf("P_av_all=%.2f dBm\n", result);
		result = LP_GetScalarMeasurement("Avg_Frequency_Offset",0);
		printf("Avg_Frequency_Offset=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Drift",0);
		printf("Avg_Frequency_Drift=%.2f kHz/Slot\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_Peak",0);
		printf("Avg_Frequency_Deviation_Peak=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Power_vs_Time_Chk",0);
		printf("Avg_Power_vs_Time_Chk=%d\n", int(result));
		result = LP_GetScalarMeasurement( "Timing_Accuracy", 0 );
		printf("Timing_Accuracy= %f ppm\n", result);

		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_Tot_Neg",0);
		printf("Avg_Frequency_Deviation_Tot_Neg=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_Tot_Pos",0);
		printf("Avg_Frequency_Deviation_Tot_Pos=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_S_Neg",0);
		printf("Avg_Frequency_Deviation_S_Neg=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_S_Pos",0);
		printf("Avg_Frequency_Deviation_S_Pos=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_B_Neg",0);
		printf("Avg_Frequency_Deviation_B_Neg=%.2f kHz\n", result/1e3);
		result = LP_GetScalarMeasurement("Avg_Frequency_Deviation_B_Pos",0);
		printf("Avg_Frequency_Deviation_B_Pos=%.2f kHz\n", result/1e3);
		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "dect" );
}


void WiFi_11ac_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double  bufferReal[MAX_BUFFER_SIZE], bufferImag[MAX_BUFFER_SIZE];
	double  *IData, *QData;
	IData = new double [280000];
	QData = new double [280000];
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester
	double cableLoss = 1; //dB of path loss
	double maxCaptureTime=0.0, minCaptureTime=1e6, maxAnalysisTime=0.0, minAnalysisTime=1e6;
	bool licenseAvailable;


	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );

		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("\n%s\n\n", buffer);
		
		LP_CheckLicense("WLANAC",&licenseAvailable);

		if(licenseAvailable)
		{
			printf("WLANAC license is available!\n");
		}
		else
		{
			printf("WLANAC license is not available!\n");
		}


		//-------------//
		//  Setup VSG  //
		//-------------//
		CheckReturnCode( LP_SetVsg(FREQ_HZ_5G, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//
		CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_11AC_VHT80_S1_MCS5.iqvsg",0), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0; //100;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );


		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 10;

		double samplingRate = 160e6;

		double refLevels[3] = {(dutPowerLevel+peakToAverageRatio-cableLoss),(dutPowerLevel+peakToAverageRatio-cableLoss),(dutPowerLevel+peakToAverageRatio-cableLoss)};
		
		CheckReturnCode( LP_SetVsa(FREQ_HZ_5G, (dutPowerLevel+peakToAverageRatio-cableLoss), PORT_LEFT), "LP_SetVsa()" );
		

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		double captureTime =500e-6;
		CheckReturnCode( LP_VsaDataCapture(captureTime, 13,160e6), "LP_VsaDataCapture()" ); //trigger type was 2, only for instrument driver? in IQapi, it is for external trigger?

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//

		CheckReturnCode( LP_GetSampleData(0,IData,QData,280000), "LP_GetSampleData()" );
		char saveCapturedName1[MAX_BUFFER_SIZE] = "WiFi_11ac.iqvsa";
		char saveCapturedName2[MAX_BUFFER_SIZE] = "WiFi_11ac.iqvsg";
		char saveCapturedName3[MAX_BUFFER_SIZE] = "WiFi_11ac.txt";
		CheckReturnCode( LP_SaveVsaSignalFile(saveCapturedName1), "LP_SaveVsaSignalFile()" );
		CheckReturnCode( LP_SaveVsaGeneratorFile(saveCapturedName2), "LP_SaveVsaGeneratorFile()" );
		CheckReturnCode( LP_SaveVsaSignalFileText(saveCapturedName3), "LP_SaveVsaSignalFileText()" );


		////-------------------------//
		////  Perform CCDF analysis //
		////-------------------------//
		double result;

		CheckReturnCode( LP_AnalyzeCCDF(), "LP_AnalyzeCCDF()");

		result = ::LP_GetVectorMeasurement("prob", bufferReal, bufferImag, MAX_BUFFER_SIZE);
		result = ::LP_GetVectorMeasurement("power_rel_dB", bufferReal, bufferImag, MAX_BUFFER_SIZE);

		//-------------------------//
		//  Perform Power analysis //
		//-------------------------//

		CheckReturnCode( LP_AnalyzePower(3.2e-6, 15.0), "LP_AnalyzePower()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		
		result = LP_GetScalarMeasurement("valid"); //result not right yet.
		printf("valid: %.0f\n", result);

		result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
		printf("P_av_each_burst_dBm: %.2f dBm\n", result);
		result = LP_GetScalarMeasurement("P_av_each_burst");
		printf("P_av_each_burst: %.6f mw\n", result);

		result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
		printf("P_pk_each_burst_dBm: %.2f dBm\n", result);
		result = LP_GetScalarMeasurement("P_pk_each_burst");
		printf("P_pk_each_burst: %.6f mw\n", result);

		result = LP_GetScalarMeasurement("P_av_all_dBm");
		printf("P_av_all_dBm: %.2f dBm\n", result);
		result = LP_GetScalarMeasurement("P_av_all");
		printf("P_av_all: %.6f mw\n", result);

		result = LP_GetScalarMeasurement("P_peak_all_dBm");
		printf("P_peak_all_dBm: %.2f dBm\n", result);
		result = LP_GetScalarMeasurement("P_peak_all");
		printf("P_peak_all: %.6f mw\n", result);

		result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
		printf("P_av_no_gap_all_dBm: %.2f dBm\n", result);
		result = LP_GetScalarMeasurement("P_av_no_gap_all");
		printf("P_av_no_gap_all: %.6f mw\n", result);


		//-------------------------//
		//  Perform 11ac analysis //
		//-------------------------//

		CheckReturnCode( LP_Analyze80211ac(), "LP_Analyze80211ac()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//

		result = LP_GetScalarMeasurement("packetDetection");
		if (result == 0)
		{
			printf("\nValid Packet Header Detection: %s \n", "FALSE");
		}
		else
			printf("\nValid Packet Header Detection: %s \n", "TRUE");

		result = LP_GetScalarMeasurement("acquisition");
		if (result == 0)
		{
			printf("Valid HT Packet Detection: %s \n", "FALSE");
		}
		else
			printf("Valid HT Packet Detection: %s \n", "TRUE");


		result = LP_GetScalarMeasurement("psduCRC");
		if (result == 1)
		{
			printf("PSDU CRC: %s \n", "PASS");
		}
		else
			printf("PSDU CRC: %s \n", "FAIL");

		result = LP_GetScalarMeasurement("demodulation");
		if (result == 0)
		{
			printf("Streams Demodulated: %s \n\n", "FALSE");
		}
		else
			printf("Streams Demodulated: %s \n\n", "TRUE");


		result = LP_GetScalarMeasurement("freqErrorHz");
		printf("Frequency Error: %.2f Hz\n", result);

		result = LP_GetScalarMeasurement("symClockErrorPpm");
		printf("Symbol Clock Error: %.2f ppm\n", result);

		result = LP_GetScalarMeasurement("PhaseNoiseDeg_RmsAll");
		printf("RMS Phase Noise: %.2f deg\n", result);

		result = LP_GetScalarMeasurement("IQImbal_amplDb");
		printf("IQ Imbalance Amp: %.2f dB \n", result);

		result = LP_GetScalarMeasurement("IQImbal_phaseDeg");
		printf("IQ Imbalance phase: %0.2f deg \n", result);

		result = LP_GetScalarMeasurement("dcLeakageDbc");
		printf("LO leakage: %.2f dBc\n\n", result);

		double bandwidthMhz = LP_GetScalarMeasurement("rateInfo_bandwidthMhz");
		printf("Signal Bandwidth: %0.2f MHz\n", bandwidthMhz);

		result = LP_GetScalarMeasurement("rateInfo_spatialStreams");
		printf("Number of Spatial Streams: %1.0f \n", result);

		result = LP_GetScalarMeasurement("rateInfo_spaceTimeStreams");
		printf("Number of SpaceTime Streams: %1.0f \n", result);

		result = LP_GetScalarMeasurement("rateInfo_dataRateMbps");
		printf("Datarate: %0.2f Mbps\n", result);

		result = LP_GetScalarMeasurement("rxRmsPowerDb");
		printf("Power_NoGap: %.3f dBm\n", result);


		result = LP_GetScalarMeasurement("evmAvgAll");
		printf("EVM Avg All: %.3f dB\n\n", result);

		result = ::LP_GetVectorMeasurement("channelEst", bufferReal, bufferImag, MAX_BUFFER_SIZE);
		if (result <= 0)
		{
			printf("Channel Estimation returns an error\n");
		}
		else
		{
			//cacluate the spectrum flatness.
			printf("Channel Estimation returns a vector with %3.0f elements\n", result);
			int numSubcarrier = 256; //number of Subcarrier for 80MHz
			double  *carrierPwr;
			int centerStart, centerEnd, sideStart, sideEnd;
			//iqPwr  = (double *) malloc (result * sizeof (double));
			carrierPwr     = (double *) malloc (numSubcarrier * sizeof (double));
			double avgCenterPwr=0.0, avgSidePwr=0.0, avgPwrSpectral=0.0;
			double maxCarrierPwr = -999.9, minCenterCarrierPwr = 99.9, minSideCarrierPwr = 99.9;

			if (bandwidthMhz == 20.0)
			{
				numSubcarrier = 64;
				centerStart   = CARRIER_1;
				centerEnd     = CARRIER_16;
				sideStart     = CARRIER_17;
				sideEnd       = CARRIER_28;
			}
			else
			{
				if (bandwidthMhz == 40.0)
				{
					numSubcarrier = 128;
					centerStart   = CARRIER_2;
					centerEnd     = CARRIER_42;
					sideStart     = CARRIER_43;
					sideEnd       = CARRIER_58;
				}
				else
				{
					numSubcarrier = 256;
					centerStart   = CARRIER_2;
					centerEnd     = CARRIER_84;
					sideStart     = CARRIER_85;
					sideEnd       = CARRIER_122;
				}
			}
			if (result != numSubcarrier)
			{
				printf("Channel estimation results does not match number of subcarriers for %2.0f MHz signal.\n", bandwidthMhz);
			}
			else
			{
				for (int carrier=0;carrier<result;carrier++) //only one stream here.
				{
					carrierPwr[carrier] = bufferReal[carrier]*bufferReal[carrier]+ bufferImag[carrier]*bufferImag[carrier];
				}
				// average power in the center
				for ( int i=centerStart;i<=centerEnd;i++)
				{
					avgCenterPwr = avgCenterPwr + carrierPwr[i] + carrierPwr[numSubcarrier-i];
				}
				// average power on side lobe.
				for (int i=sideStart;i<=sideEnd;i++)
				{
					avgSidePwr = avgSidePwr + carrierPwr[i] + carrierPwr[numSubcarrier-i];
				}

				avgPwrSpectral = avgCenterPwr+ avgSidePwr;

				avgCenterPwr = avgCenterPwr/((centerEnd-centerStart+1)*2);
				if (0!=avgCenterPwr)
				{
					avgCenterPwr = 10.0 * log10 (avgCenterPwr);
				}
				else
				{
					avgCenterPwr= 0;
				}
				avgPwrSpectral = avgPwrSpectral/((sideEnd-centerStart+1)*2);
				if (0!=avgPwrSpectral)
				{
					avgPwrSpectral = 10.0 * log10 (avgPwrSpectral);
				}
				else
				{
					avgPwrSpectral = 0;
				}

				for (int carrier=0;carrier<numSubcarrier;carrier++)
				{
					if (0!=carrierPwr[carrier])
					{
						carrierPwr[carrier] = 10.0 * log10 (carrierPwr[carrier]);
						if (carrierPwr[carrier]>maxCarrierPwr)
						{
							maxCarrierPwr = carrierPwr[carrier];
						}
						if ( (carrier>=centerStart && carrier <=centerEnd) || (carrier>=numSubcarrier-centerEnd && carrier <= numSubcarrier-centerStart) )
						{
							if(carrierPwr[carrier]< minCenterCarrierPwr)
							{
								minCenterCarrierPwr = carrierPwr[carrier];
							}
						}
						if ((carrier>=sideStart && carrier <=sideEnd) || (carrier>=numSubcarrier-sideEnd && carrier <=numSubcarrier-sideStart) )
						{
							if(carrierPwr[carrier]< minSideCarrierPwr)
							{
								minSideCarrierPwr = carrierPwr[carrier];
							}
						}
					}
					else
					{
						carrierPwr[carrier] = 0;
					}
				}
				printf("The maximum deviation is %0.2f dB\n", maxCarrierPwr-avgCenterPwr);
				printf("The minimum deviation are %0.2f dB in the center, %0.2f dB in the far side\n", minCenterCarrierPwr-avgCenterPwr, minSideCarrierPwr-avgCenterPwr);
				printf("The LO Leakage is %0.2f dBc \n", carrierPwr[0] - avgPwrSpectral - 10 * log10((double)((sideEnd-centerStart+1)*2)) );
			}

		}

		printf("11AC VHT Sig field Info:\n");
		result = LP_GetScalarMeasurement("VHTSigA1Bandwidth");
		printf("VHTSigA1Bandwidth=%1.0f. Means: %3.0f MHz\n", result, pow(2,result)*20);

		result = LP_GetScalarMeasurement("VHTSigA1Stbc");
		printf("VHTSigA1Stbc=%1.0f. Means: ", result);
		if(result == 0)
		{
			printf("STBC is not enabled for all streams.\n");
		}
		else
			printf("STBC is enabled for all streams.\n");

		result = LP_GetScalarMeasurement("VHTSigA2ShortGI");
		printf("VHTSigA2ShortGI=%1.0f\n", result);
		result = LP_GetScalarMeasurement("VHTSigA2AdvancedCoding");
		printf("VHTSigA2AdvancedCoding=%1.0f\n", result);
		result = LP_GetScalarMeasurement("VHTSigA2McsIndex");
		printf("VHTSigA2McsIndex=%1.0f\n", result);

		result = LP_GetScalarMeasurement("vhtSigBFieldCRC");
		printf("vhtSigBFieldCRC=%1.0f\n\n", result);

		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );
		printf("\n");

	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}

	free(IData);
	free(QData);
	CheckReturnCode( LP_Term(), "LP_Term()" );
	ReadLogFiles();
	PrintErrorStatus( status, "ac" );
}

void WiFi_11ac_80plus80_Loopback()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double dutPowerLevel = -10;		// Estimated RMS power level at IQTester
	double cableLoss = 1; //dB of path loss
	double maxCaptureTime=0.0, minCaptureTime=1e6, maxAnalysisTime=0.0, minAnalysisTime=1e6;

	try
	{

	//----------------------------//
	//   Initialize the IQTester  //
	//----------------------------//

	CheckReturnCode(LP_Init(1, 1), "LP_Init()");

	CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
	int selectedModules[2] = {1,2};
	CheckReturnCode( LP_SetTesterMode(NON_CONT_80_80MHZ_SIGNAL, selectedModules, 2), "LP_SetTesterMode()" );

	if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("\n%s\n\n", buffer);

	//-------------//
	//  Setup VSG  //
	//-------------//

	// Set the speration between two 80MHz signal, minimum seperation is 80Mhz
	// This will set both VSG and VSA
	// For 160Mhz contiguous mode, do not have to call this function.
	
	CheckReturnCode(LP_SetVsaVsgSeperation(120e6), "LP_SetVsaVsgSeperation()");

	CheckReturnCode(LP_SetVsg(FREQ_HZ_5G, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()");

	//--------------------//
	// Load waveform file //
	//--------------------//
	// need to load 160 BW signal file, for both 160Mhz contiguous and 80+80 non-contiguous
	// can get the 160BW waveform from tester "File" -> "waveform" ->"WiFi" or generate the VSG tab,"Wav Gen "

	CheckReturnCode(LP_SetVsgModulation("../../iqvsg/WiFi_11AC_VHT160_S1_MCS9.iqvsg"), "LP_SetVsgModulation()");

	//------------------------------------------//
	//   Send packet, continuous transmission   //
	//------------------------------------------//
	int frameCnt = 0; //100;	// number of frame to send, 0 means continuous transmission.
	CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

	//---------------//
	//  Turn on VSG  //
	//---------------//
	CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );


	//----------------//
	//   Setup VSA    //
	//----------------//
	int peakToAverageRatio = 10;

	double samplingRate = 160e6;

	CheckReturnCode( LP_SetVsa(FREQ_HZ_5G, (dutPowerLevel+peakToAverageRatio-cableLoss), PORT_LEFT), "LP_SetVsa()" );


	//----------------------//
	//  Perform VSA capture //
	//----------------------//
	double captureTime =500e-6;
	CheckReturnCode( LP_VsaDataCapture(captureTime, 13,160e6,7), "LP_VsaDataCapture()" ); //trigger type was 2, only for instrument driver? in IQapi, it is for external trigger?

	// afterwards, all analysis and measurement result is same as previous IQxel80; note, if in 80+80, the seperation is equal or less than 120Mhz, FFT analysis will fail

	CheckReturnCode( LP_Analyze80211ac(), "LP_Analyze80211ac()");
	double result = LP_GetScalarMeasurement("evmAvgAll");
	printf("EVM average: %.3f\n", result);

	CheckReturnCode( LP_AnalyzeFFT(), "LP_AnalyzeFFT()");

	//----------------//
	//  Turn off VSG  //
	//----------------//
	CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );
	printf("\n");

	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}

	CheckReturnCode( LP_Term(), "LP_Term()" );
	PrintErrorStatus( status, "ac80plus80" );
}

void CW_Test()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[1] = {1};
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		double vsgPowerdBm = -10;
		double freqHz = 2442e6;
		double offsetFreqHz = 0;

		CheckReturnCode( LP_SetVsgCw(freqHz, offsetFreqHz, vsgPowerdBm, PORT_RIGHT), "LP_SetVsg()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //
		//------------------------------------------//
		int frameCnt = 0; //100;	// number of frame to send, 0 means continuous transmission.
		CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		CheckReturnCode( LP_SetVsa(FREQ_HZ, vsgPowerdBm, PORT_LEFT), "LP_SetVsa()" );

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		int vsaTrigger = 1;
		double samplingTime = 0.001;
		CheckReturnCode( LP_VsaDataCapture(samplingTime, vsaTrigger), "LP_VsaDataCapture()" );

		//---------------------------//
		//  Save sig file for debug  //
		//---------------------------//
		CheckReturnCode( LP_AnalyzeCW(), "LP_AnalyzeCW()");

		double result = LP_GetScalarMeasurement("frequency");
		printf("frequency error: %.2f Hz\n", result);

		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );

		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );

	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "cw" );
}


void NFC_FreqSweep_Test(){
    
    try
    {
        //----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = ERR_OK;
		char response[MAX_BUFFER_SIZE] = {0};
		unsigned int actualSize = 0;

        CheckReturnCode( LP_Init(2,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );

		printf("Please make sure no device on the test coil!\n");
		printf("Press any key to continue...\n");
		getchar();

        //-------------------------------//
        //  Frequency Sweep Calibration  //
        //-------------------------------//
        CheckReturnCode( LP_NFC_FreqSweepCal(), "LP_NFC_FreqSweepCal()" );

		//-----------------------------------//
        //  Save Calibration Reference File  //
        //-----------------------------------//
        CheckReturnCode( LP_NFC_SaveCalRefFile(".\\Log\\CalRefFile.iqvsa"), "LP_NFC_SaveCalRefFile()" );

        printf("Please place the DUT on the test coil\n");
		printf("Press any key to continue...\n");
		getchar();
		
		//---------------------------------------//
        //          Frequency Sweep Test         //
        //---------------------------------------//
        CheckReturnCode( LP_NFC_FreqSweep(), "LP_NFC_FreqSweep" );

		//----------------------------------//
        // Load Calibration Reference File  //
        //----------------------------------//
        //CheckReturnCode( LP_NFC_LoadCalRefFile(".\\Log\\CalRefFile.iqvsa"), "LP_NFC_SaveCalRefFile()" );

        //---------------------------------------//
        //          Frequency Sweep Test         //
        //---------------------------------------//
        //CheckReturnCode( LP_NFC_FreqSweep(), "LP_NFC_FreqSweep" );

		double bandwidth_3dB_lowerFreq = LP_GetScalarMeasurement("3dB_bandwidth_lowerFreq");
		double bandwidth_3dB_upperFreq = LP_GetScalarMeasurement("3dB_bandwidth_upperFreq");
		double bandwidth_3dB = LP_GetScalarMeasurement("3dB_bandwidth");
		double freq_peakLevel = LP_GetScalarMeasurement("freq_peakLevel");
		double freq_geometric = LP_GetScalarMeasurement("freq_geometric");
		double Q_peakLevel = LP_GetScalarMeasurement("Q_peakLevel");
		double Q_geometric = LP_GetScalarMeasurement("Q_geometric");
		printf("3dB_bandwidth_lowerFreq = %f\n 3dB_bandwidth_upperFreq = %f\n 3dB_bandwidth = %f\n freq_peakLevel = %f\n freq_geometric = %f\n Q_peakLevel = %f\n Q_geometric = %f\n", bandwidth_3dB_lowerFreq, bandwidth_3dB_upperFreq, bandwidth_3dB, freq_peakLevel, freq_geometric, Q_peakLevel, Q_geometric);

		double xRealArray [MAX_BUFFER_SIZE] = {0.0};
		double xImagArray [MAX_BUFFER_SIZE] = {0.0};
		double yRealArray [MAX_BUFFER_SIZE] = {0.0};
		double yImagArray [MAX_BUFFER_SIZE] = {0.0};
		
		int bufferSizeX = ::LP_GetVectorMeasurement("freqSweep_offsetFreq", xRealArray, xImagArray, MAX_BUFFER_SIZE);
		int bufferSizeY = ::LP_GetVectorMeasurement("freqSweep_returnLoss", yRealArray, yImagArray, MAX_BUFFER_SIZE);
		bufferSizeY = ::LP_GetVectorMeasurement("freqSweep_normalized_returnLoss", yRealArray, yImagArray, MAX_BUFFER_SIZE);

        //----------------------------//
        //   Disconnect the IQTester  //
        //----------------------------//
        CheckReturnCode( LP_Term(), "LP_Term()" );
      }catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
            printf("ERROR!");
    }
}

void NFC_TargetWaveformAnalysis_Test(){
    
    try
    {
        //----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = ERR_OK;
		char response[MAX_BUFFER_SIZE] = {0};
		unsigned int actualSize = 0;
		NFC_STANDARD standard = NFCB;

        CheckReturnCode( LP_Init(2,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );

		for (int i = 0; i < 7; i++)
		{
			if ( 0 == i )
			{
				standard = NFCA;
			}
			else if ( 1 == i )
			{
				standard = NFCB;
			}
			else if ( 2 == i )
			{
				standard = NFCF;
			}
			else if ( 3 == i )
			{
				standard = NFCA;
			}
			else if ( 4 == i )
			{
				standard = FACT;
			}
			else if ( 5 == i )
			{
				standard = APAS;
			}
			else if ( 6 == i )
			{
				standard = FPAS;
			}
			//--------------------------------------//
			//  Setup for Target Waveform Analysis  //
			//--------------------------------------//
			if ( NFCF == standard || FACT == standard || FPAS == standard )
			{
				CheckReturnCode( LP_NFC_Setup_TargetWaveformAnalysis( standard, R212, 20, 0), "LP_NFC_Setup_TargetWaveformAnalysis()" );
			}
			else
			{
				CheckReturnCode( LP_NFC_Setup_TargetWaveformAnalysis( standard, R106, 20, 0), "LP_NFC_Setup_TargetWaveformAnalysis()" );
			}

			//-----------------------------------------------//
			//  Capture following Initial Phase of Protocol  //
			//-----------------------------------------------//
			CheckReturnCode( LP_NFC_InitProtocolCapture(0.03, R13M56), "LP_NFC_InitProtocolCapture()" );

			//---------------------------------------//
			//          Parametric		 Test         //
			//---------------------------------------//
			CheckReturnCode( LP_NFC_AnalyzeSignal(TARGET, standard), "LP_NFC_AnalyzeSignal" );

			if ( AACT == standard || FACT == standard )
			{
				double dataRate_measured = LP_GetScalarMeasurement("dataRate_measured");
				double dataRate_nominal = LP_GetScalarMeasurement("dataRate_nominal");
				double mod_index = LP_GetScalarMeasurement("mod_index");
				double mod_depth = LP_GetScalarMeasurement("mod_depth");
				double carrier_freq_offset = LP_GetScalarMeasurement("carrier_freq_offset");
				double rise_time = LP_GetScalarMeasurement("rise_time");
				double fall_time = LP_GetScalarMeasurement("fall_time");
				double rise_overshoot = LP_GetScalarMeasurement("rise_overshoot");
				double rise_undershoot = LP_GetScalarMeasurement("rise_undershoot");
				double fall_overshoot = LP_GetScalarMeasurement("fall_overshoot");
				double fall_undershoot = LP_GetScalarMeasurement("fall_undershoot");
				printf("dataRate_measured = %f\ndataRate_nominal = %f\nmod_index = %f\nmod_depth = %f\ncarrier_freq_offset = %f\nrise_time = %f\nfall_time = %f\nrise_overshoot = %f\nrise_undershoot = %f\nfall_overshoot = %f\nfall_undershoot = %f\n", dataRate_measured, dataRate_nominal, mod_index, mod_depth, carrier_freq_offset, rise_time, fall_time, rise_overshoot, rise_undershoot, fall_overshoot, fall_undershoot);
				//double carrierFreq = LP_GetScalarMeasurement("carrierFreq");
				//double fieldStrength = LP_GetScalarMeasurement("fieldStrength");
				//printf("carrierFreq = %f\nfieldStrength = %f\n", carrierFreq, fieldStrength);
			}
			else
			{
				double dataRate_measured = LP_GetScalarMeasurement("dataRate_measured");
				double dataRate_nominal = LP_GetScalarMeasurement("dataRate_nominal");
				double frameDelayTime = LP_GetScalarMeasurement("frameDelayTime");
				double volt_peak_loadMod = LP_GetScalarMeasurement("volt_peak_loadMod");
				double loadMod = LP_GetScalarMeasurement("loadMod");
				double subcarrier_freq = LP_GetScalarMeasurement("subcarrier_freq");
				double mod_index = LP_GetScalarMeasurement("mod_index");
				double mod_depth = LP_GetScalarMeasurement("mod_depth");
				//double carrier_freq_offset = LP_GetScalarMeasurement("carrier_freq_offset");
				printf("dataRate_measured = %f\ndataRate_nominal = %f\nframeDelayTime = %f\nvolt_peak_loadMod = %f\nloadMod = %f\nsubcarrier_freq = %f\nmod_index = %f\nmod_depth = %f\n", dataRate_measured, dataRate_nominal, frameDelayTime, volt_peak_loadMod, loadMod, subcarrier_freq, mod_index, mod_depth);
			}
			
			if ( standard != NFCA && standard != AACT && standard != APAS )
			{
				double CRC = LP_GetScalarMeasurement("CRC");
				printf("CRC = %d\n", (unsigned int)CRC);
			}
			if ( standard == NFCB )
			{
				double TR0 = LP_GetScalarMeasurement("TR0");
				printf("TR0 = %f\n", TR0);
			}

			double xRealArray [MAX_BUFFER_SIZE] = {0.0};
			double xImagArray [MAX_BUFFER_SIZE] = {0.0};
			double yRealArray [MAX_BUFFER_SIZE] = {0.0};
			double yImagArray [MAX_BUFFER_SIZE] = {0.0};
			double zRealArray [MAX_BUFFER_SIZE] = {0.0};
			double zImagArray [MAX_BUFFER_SIZE] = {0.0};

			int bufferSizeX = ::LP_GetVectorMeasurement("payLoad_bits", xRealArray, xImagArray, MAX_BUFFER_SIZE);
			int bufferSizeY = ::LP_GetVectorMeasurement("time_RFenvelope", yRealArray, yImagArray, MAX_BUFFER_SIZE);
			int	bufferSizeZ = ::LP_GetVectorMeasurement("magnitude_RFenvelope", zRealArray, zImagArray, MAX_BUFFER_SIZE);
		}


        //----------------------------//
        //   Disconnect the IQTester  //
        //----------------------------//
        CheckReturnCode( LP_Term(), "LP_Term()" );
      }catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
            printf("ERROR!");
    }
}

void NFC_InitiatorWaveformAnalysis_Test(){
    
    try
    {
        //----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

		int  err  = ERR_OK;
		char response[MAX_BUFFER_SIZE] = {0};
		unsigned int actualSize = 0;
		NFC_STANDARD standard = NFCB;

		CheckReturnCode( LP_Init(2,1), "LP_Init()" );      
		CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );

		for (int i = 0; i < 7; i++)
		{
			if ( 0 == i )
			{
				standard = NFCA;
			}
			else if ( 1 == i )
			{
				standard = NFCB;
			}
			else if ( 2 == i )
			{
				standard = NFCF;
			}
			else if ( 3 == i )
			{
				standard = NFCA;
			}
			else if ( 4 == i )
			{
				standard = FACT;
			}
			else if ( 5 == i )
			{
				standard = APAS;
			}
			else if ( 6 == i )
			{
				standard = FPAS;
			}
			//--------------------------------------//
			//  Setup for Target Waveform Analysis  //
			//--------------------------------------//
			if ( 0 == i )
			{
				if ( NFCF == standard || FACT == standard || FPAS == standard )
				{
					CheckReturnCode( LP_NFC_Setup_InitiatorWaveformAnalysis( standard, R212), "LP_NFC_Setup_InitiatorWaveformAnalysis()" );
				}
				else
				{
					CheckReturnCode( LP_NFC_Setup_InitiatorWaveformAnalysis( standard, R106), "LP_NFC_Setup_InitiatorWaveformAnalysis()" );
				}
			}
			//-----------------------------------------------//
			//  Capture following Initial Phase of Protocol  //
			//-----------------------------------------------//
			if ( 0 == i )
			{
				CheckReturnCode( LP_NFC_InitProtocolCapture(0.2, R13M56), "LP_NFC_InitProtocolCapture()" );
			}

			//---------------------------------------//
			//          Frequency Sweep Test         //
			//---------------------------------------//
			CheckReturnCode( LP_NFC_AnalyzeSignal(INITIATOR, standard), "LP_NFC_AnalyzeSignal" );

			double dataRate_measured = LP_GetScalarMeasurement("dataRate_measured");
			double dataRate_nominal = LP_GetScalarMeasurement("dataRate_nominal");
			double mod_index = LP_GetScalarMeasurement("mod_index");
			double mod_depth = LP_GetScalarMeasurement("mod_depth");
			double carrier_freq_offset = LP_GetScalarMeasurement("carrier_freq_offset");
			double rise_time = LP_GetScalarMeasurement("rise_time");
			double fall_time = LP_GetScalarMeasurement("fall_time");
			double rise_overshoot = LP_GetScalarMeasurement("rise_overshoot");
			double rise_undershoot = LP_GetScalarMeasurement("rise_undershoot");
			double fall_overshoot = LP_GetScalarMeasurement("fall_overshoot");
			double fall_undershoot = LP_GetScalarMeasurement("fall_undershoot");
			printf("dataRate_measured = %f\ndataRate_nominal = %f\nmod_index = %f\nmod_depth = %f\ncarrier_freq_offset = %f\nrise_time = %f\nfall_time = %f\nrise_overshoot = %f\nrise_undershoot = %f\nfall_overshoot = %f\nfall_undershoot = %f\n", dataRate_measured, dataRate_nominal, mod_index, mod_depth, carrier_freq_offset, rise_time, fall_time, rise_overshoot, rise_undershoot, fall_overshoot, fall_undershoot);
			double carrierFreq = LP_GetScalarMeasurement("carrierFreq");
			double fieldStrength = LP_GetScalarMeasurement("fieldStrength");
			printf("carrierFreq = %f\nfieldStrength = %f\n", carrierFreq, fieldStrength);

			if ( standard == NFCA )
			{
				double T1 = LP_GetScalarMeasurement("T1");
				double T2 = LP_GetScalarMeasurement("T2");
				double T3 = LP_GetScalarMeasurement("T3");
				double T4 = LP_GetScalarMeasurement("T4");
				double T5 = LP_GetScalarMeasurement("T5");
				printf("T1 = %fus\nT2 = %fus\nT3 = %fus\nT4 = %fus\nT5 = %fus\n", T1*1e6, T2*1e6, T3*1e6, T4*1e6, T5*1e6);
			}
			else if ( standard != NFCA && standard != APAS )
			{
				double CRC = LP_GetScalarMeasurement("CRC");
				printf("CRC = %d\n", (unsigned int)CRC);
			}

			double xRealArray [MAX_BUFFER_SIZE] = {0.0};
			double xImagArray [MAX_BUFFER_SIZE] = {0.0};
			double yRealArray [MAX_BUFFER_SIZE] = {0.0};
			double yImagArray [MAX_BUFFER_SIZE] = {0.0};
			double zRealArray [MAX_BUFFER_SIZE] = {0.0};
			double zImagArray [MAX_BUFFER_SIZE] = {0.0};

			int bufferSizeX = ::LP_GetVectorMeasurement("payLoad_bits", xRealArray, xImagArray, MAX_BUFFER_SIZE);
			int bufferSizeY = ::LP_GetVectorMeasurement("time_RFenvelope", yRealArray, yImagArray, MAX_BUFFER_SIZE);
			int	bufferSizeZ = ::LP_GetVectorMeasurement("magnitude_RFenvelope", zRealArray, zImagArray, MAX_BUFFER_SIZE);
		}
        //----------------------------//
        //   Disconnect the IQTester  //
        //----------------------------//
        CheckReturnCode( LP_Term(), "LP_Term()" );
      }catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
            printf("ERROR!");
    }
}

// GPS testing for Continue Wave function
/* 
   Step 1. LP_Init()
   Step 2. LP_InitTester(IP_ADDR)
   Step 3. LP_GPS_SetActivate()
   Step 4. LP_GPS_ContinueWave(Target Power, Pathloss, IQV_TRIGGER_STATE_INT)
   Step 5. Sleep for a while
   Step 6. LP_GPS_SetDeactivate()
   Step 7. LP_Term()
*/
void GPS_ContinueWave(){
    
    try
    {
        //----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = ERR_OK;

        CheckReturnCode( LP_Init(1,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );

        //-----------------------------------------------------------
        //----------------//
        //  Activate GPS  //
        //----------------//
        // calling this function to prepared the GPS at the default situation.
        CheckReturnCode( LP_GPS_SetActivate(), "LP_GPS_SetActivate()" );
		CheckReturnCode( LP_Glonass_SetDeactivate(), "LP_Glonass_SetDeactivate()" );
		CheckReturnCode( LP_COMPASS_SetDeactivate(), "LP_COMPASS_SetDeactivate()" );

        //---------------------------------------//
        // Set Continuous Wave transmit function //
        //---------------------------------------//
        // calling this function to send the GPS signal with what satellite info that you indicated,
        // with the target power that your DUT wanna get &
        // with the pathloss &
        // set the trigger state as internal.
        CheckReturnCode( LP_GPS_ContinueWave(-80, 1, IQV_TRIGGER_STATE_INT, 10), "LP_GPS_ContinueWave()");
        
        // After above steps are complete, setup the GPS DUT to the right receive mode and perform test
        // After test is done do the next steps in IQMeasure

        //------------------//
        //  DeActivate GPS  //
        //------------------//
        // sleep for a while till the DUT get the correct information
        Sleep(10000);

        // If you have to stop the GPS transmit, please call this function "LP_GPS_SetDeactivate()",
        // or the tester will still transmit the signal.
        CheckReturnCode( LP_GPS_SetDeactivate(), "LP_GPS_SetDeactivate()" );
        //-----------------------------------------------------------

        //----------------------------//
        //   Disconnect the IQTester  //
        //----------------------------//
        CheckReturnCode( LP_Term(), "LP_Term()" );
      }catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
            printf("ERROR!");
    }

}

// GPS testing for Modulated Mode function
/* 
   Step 1. LP_Init()
   Step 2. LP_InitTester(IP_ADDR)
   Step 3. LP_GPS_SetActivate()
   Step 4. LP_GPS_ModulatedMode(
                IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF, 
                Pathloss, 
                Target Power Array, 
                satellite Number Array, 
                doppler Frequency, 
                IQV_TRIGGER_STATE_INT)
   Step 5. Sleep for a while
   Step 6. LP_GPS_SetDeactivate()
   Step 7. LP_Term()
*/
void GPS_ModulatedMode(){
    try
    {
		//----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = IQAPI_ERR_OK;

        CheckReturnCode( LP_Init(1,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );
        
        //-----------------------------------------------------------
        //----------------//
        //  Activate GPS  //
        //----------------//
        // calling this function to prepared the GPS at the default situation.
		CheckReturnCode( LP_Glonass_SetDeactivate(), "LP_Glonass_SetDeactivate()" );
		CheckReturnCode( LP_COMPASS_SetDeactivate(), "LP_COMPASS_SetDeactivate()" );
		CheckReturnCode( LP_GPS_SetActivate(), "LP_GPS_SetActivate()" );

        //---------------------------------------//
        // Set Continuous Wave transmit function //
        //---------------------------------------//
        // calling this function to send the GPS signal with what satellite info that you indicated,
        // preparing those : 
        // set the CA Code modulation is (IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF or IQV_OPERATION_MODE_MODULATION) &
        // with the pathloss &
        // with the target power array of each satellite that your DUT wanna get & 
        // with the satellite number array to inform the data &
        // set the trigger state as internal.
        double powerA = -120;
		double relativePower[6] = {0,0,0,0,0,0};
        int satelliteNumA[6] = {11,2,3,4,5,6};
		int modulationType[6] = {IQV_TRIGGER_STATE_INT,0,0,0,0,0};
		int freqOffset[6] = {0,0,0,0,0,0};
       /* CheckReturnCode( LP_GPS_ModulatedMode(
            IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF, 
            5, 
            powerA, 
            satelliteNumA, 
            4000, 
            IQV_TRIGGER_STATE_INT), "LP_GPS_ModulatedMode()" );*/
		CheckReturnCode( LP_GPS_ModulationMode(powerA, satelliteNumA, relativePower, modulationType, freqOffset), "LP_GPS_ModulationMode()" );

        // After above steps are complete, setup the GPS DUT to the right receive mode and perform test
        // After test is done do the next steps in IQMeasure
        
        //------------------//
        //  DeActivate GPS  //
        //------------------//
        // sleep for a while till the DUT get the correct information
        Sleep(15000);

        // If you have to stop the GPS transmit, please call this function "LP_GPS_SetDeactivate()",
        // or the tester will still transmit the signal.
        CheckReturnCode( LP_GPS_SetDeactivate(), "LP_GPS_SetDeactivate()" );
        //-----------------------------------------------------------
       
        //----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
		printf("ERROR!");
    }

}


// GPS testing for Modulated Mode function
/* 
   Step 1. LP_Init()
   Step 2. LP_InitTester(IP_ADDR)
   Step 3. LP_GPS_SetActivate()
   Step 4. LP_GPS_ModulatedMode(
                IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF, 
                Pathloss, 
                Target Power Array, 
                satellite Number Array, 
                doppler Frequency, 
                IQV_TRIGGER_STATE_INT)
   Step 5. Sleep for a while
   Step 6. LP_GPS_SetDeactivate()
   Step 7. LP_Term()
*/
void GPS_ScenarioMode(){
    try
    {
		//----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = IQAPI_ERR_OK;

        CheckReturnCode( LP_Init(1,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );
        
        //-----------------------------------------------------------
        //----------------//
        //  Activate GPS  //
        //----------------//
        // calling this function to prepared the GPS at the default situation.
		CheckReturnCode( LP_Glonass_SetDeactivate(), "LP_Glonass_SetDeactivate()" );
		CheckReturnCode( LP_COMPASS_SetDeactivate(), "LP_COMPASS_SetDeactivate()" );
		CheckReturnCode( LP_GPS_SetActivate(), "LP_GPS_SetActivate()" );

        //---------------------------------------//
        // Set Continuous Wave transmit function //
        //---------------------------------------//
        // calling this function to send the GPS signal with what satellite info that you indicated,
        // preparing those : 
        // set the CA Code modulation is (IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF or IQV_OPERATION_MODE_MODULATION) &
        // with the pathloss &
        // with the target power array of each satellite that your DUT wanna get & 
        // with the satellite number array to inform the data &
        // set the trigger state as internal.
        double powerDbm = -120;
		double relativePower = 0;
		int triggerType = 0;

        CheckReturnCode( LP_GPS_IQXEL_LoadScenarioFile("IQNavScenarioFile2008241_3600_sec.xml", TRIG_IMM), "LP_GPS_IQXEL_LoadScenarioFile()" );
		CheckReturnCode( LP_GPS_IQXEL_PlayScenarioFile(powerDbm, relativePower), "LP_GPS_IQXEL_PlayScenarioFile()" );

        // After above steps are complete, setup the GPS DUT to the right receive mode and perform test
        // After test is done do the next steps in IQMeasure
        
        //------------------//
        //  DeActivate GPS  //
        //------------------//
        printf("\nWait for DUT to locate. Press any key to contiue...\n");
        getchar();

        // If you have to stop the GPS transmit, please call this function "LP_GPS_SetDeactivate()",
        // or the tester will still transmit the signal.
        CheckReturnCode( LP_GPS_SetDeactivate(), "LP_GPS_SetDeactivate()" );
        //-----------------------------------------------------------
       
        //----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
		printf("ERROR!");
    }

}


// COMPASS testing for Continue Wave function
/* 
   Step 1. LP_Init()
   Step 2. LP_InitTester(IP_ADDR)
   Step 3. LP_GPS_SetActivate()
   Step 4. LP_GPS_ContinueWave(Target Power, Pathloss, IQV_TRIGGER_STATE_INT)
   Step 5. Sleep for a while
   Step 6. LP_GPS_SetDeactivate()
   Step 7. LP_Term()
*/
void COMPASS_ContinueWave(){
    
    try
    {
        //----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = ERR_OK;

        CheckReturnCode( LP_Init(1,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );

        //-----------------------------------------------------------
        //----------------//
        //  Activate GPS  //
        //----------------//
        // calling this function to prepared the GPS at the default situation.
        CheckReturnCode( LP_COMPASS_SetActivate(), "LP_GPS_SetActivate()" );

        //---------------------------------------//
        // Set Continuous Wave transmit function //
        //---------------------------------------//
        // calling this function to send the GPS signal with what satellite info that you indicated,
        // with the target power that your DUT wanna get &
        // with the pathloss &
        // set the trigger state as internal.
        CheckReturnCode( LP_COMPASS_ContinueWave(-80, 1, IQV_TRIGGER_STATE_INT, 0), "LP_GPS_ContinueWave()");
        
        // After above steps are complete, setup the GPS DUT to the right receive mode and perform test
        // After test is done do the next steps in IQMeasure

        //------------------//
        //  DeActivate GPS  //
        //------------------//
        // sleep for a while till the DUT get the correct information
        Sleep(10000);

        // If you have to stop the GPS transmit, please call this function "LP_GPS_SetDeactivate()",
        // or the tester will still transmit the signal.
        CheckReturnCode( LP_COMPASS_SetDeactivate(), "LP_GPS_SetDeactivate()" );
        //-----------------------------------------------------------

        //----------------------------//
        //   Disconnect the IQTester  //
        //----------------------------//
        CheckReturnCode( LP_Term(), "LP_Term()" );
      }catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
            printf("ERROR!");
    }

}

// COMPASS testing for Modulated Mode function
/* 
   Step 1. LP_Init()
   Step 2. LP_InitTester(IP_ADDR)
   Step 3. LP_GPS_SetActivate()
   Step 4. LP_GPS_ModulatedMode(
                IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF, 
                Pathloss, 
                Target Power Array, 
                satellite Number Array, 
                doppler Frequency, 
                IQV_TRIGGER_STATE_INT)
   Step 5. Sleep for a while
   Step 6. LP_GPS_SetDeactivate()
   Step 7. LP_Term()
*/
void COMPASS_ModulatedMode(){
    try
    {
		//----------------------------//
        //   Initialize the IQTester  //
        //----------------------------//

        int  err  = IQAPI_ERR_OK;

        CheckReturnCode( LP_Init(1,1), "LP_Init()" );      
        CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );
        
        //-----------------------------------------------------------
        //----------------//
        //  Activate GPS  //
        //----------------//
        // calling this function to prepared the GPS at the default situation.
        CheckReturnCode( LP_COMPASS_SetActivate(), "LP_GPS_SetActivate()" );

        //---------------------------------------//
        // Set Continuous Wave transmit function //
        //---------------------------------------//
        // calling this function to send the GPS signal with what satellite info that you indicated,
        // preparing those : 
        // set the CA Code modulation is (IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF or IQV_OPERATION_MODE_MODULATION) &
        // with the pathloss &
        // with the target power array of each satellite that your DUT wanna get & 
        // with the satellite number array to inform the data &
        // set the trigger state as internal.
        double powerA = -130;
        int satelliteNumA[6] = {1,0,0,0,0,0};
		int modType[6] = {IQV_TRIGGER_STATE_INT,0,0,0,0,0};
		int freqOffset[6] = {0,0,0,0,0,0};
		int NHCode = 0;
		double relativeGain[6] = {0,0,0,0,0,0};

        CheckReturnCode( LP_COMPASS_ModulationMode(
            modType, 
            powerA,
			freqOffset,
			NHCode,
			satelliteNumA,
			relativeGain), "LP_GPS_ModulationMode()" );

        // After above steps are complete, setup the GPS DUT to the right receive mode and perform test
        // After test is done do the next steps in IQMeasure
        
        //------------------//
        //  DeActivate GPS  //
        //------------------//
        // sleep for a while till the DUT get the correct information
        Sleep(15000);

        // If you have to stop the GPS transmit, please call this function "LP_GPS_SetDeactivate()",
        // or the tester will still transmit the signal.
        CheckReturnCode( LP_COMPASS_SetDeactivate(), "LP_GPS_SetDeactivate()" );
        //-----------------------------------------------------------
       
        //----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}catch(char *msg){
        printf("ERROR: %s\n", msg);
    }catch(...){
		printf("ERROR!");
    }

}

void Glonass_Test()
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(1,1), "LP_Init()" );
		CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );
		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("%s\n", buffer);

		printf("\r\n\r\n"
				"=========================================\r\n"
				"=             TESTING GLONASS\r\n"
				"=========================================\r\n");


		printf("\r\n[Activating GPS] ... ");

		printf("OK\r\n");
		CheckReturnCode( LP_Glonass_SetActivate(), "LP_Glonass_SetActivate()" );

		//CheckReturnCode( LP_PrintGlonassParameters(), "LP_PrintGlonassParameters()" );

		CheckReturnCode( LP_Glonass_SetRfOutput(IQV_RF_OUTPUT_ON), "LP_Glonass_SetRfOutput()" );
		CheckReturnCode( LP_Glonass_SetOperationMode(IQV_OPERATION_MODE_CW), "LP_Glonass_SetOperationMode()" );
		CheckReturnCode( LP_Glonass_SetPower(-80), "LP_Glonass_SetPower()" );

		// IQV_GLONASS_FREQUENCY_CHANNEL is -7
		CheckReturnCode( LP_Glonass_SetFrequency( -7 ), "LP_Glonass_SetFrequency()" );

		// IQV_GLONASS_FREQUENCY_CHANNEL_1602000000Hz is 0
		CheckReturnCode( LP_Glonass_SetFrequency( 0 ), "LP_Glonass_SetFrequency()" );

		CheckReturnCode( LP_Glonass_SetPower(-60), "LP_Glonass_SetPower()" );

		CheckReturnCode( LP_Glonass_SetRfOutput(IQV_RF_OUTPUT_OFF), "LP_Glonass_SetRfOutput()" );

		CheckReturnCode( LP_Glonass_SetRfOutput(IQV_RF_OUTPUT_ON), "LP_Glonass_SetRfOutput()" );

		CheckReturnCode( LP_Glonass_SetOperationMode(IQV_OPERATION_MODE_MODULATION_OFF), "LP_Glonass_SetOperationMode()" );

		CheckReturnCode( LP_Glonass_SetOperationMode(IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF), "LP_Glonass_SetOperationMode()" );

		CheckReturnCode( LP_Glonass_SetOperationMode(IQV_OPERATION_MODE_MODULATION), "LP_Glonass_SetOperationMode()" );

		CheckReturnCode( LP_Glonass_SetPower(-100), "LP_Glonass_SetPower()" );

		CheckReturnCode( LP_Glonass_SetPower(-130), "LP_Glonass_SetPower()" );

		CheckReturnCode( LP_Glonass_ContinueWave(-70, 0, IQV_TRIGGER_STATE_INT, 0), "LP_Glonass_SetPower()" );
		
		//CheckReturnCode( LP_PrintGlonassParameters(), "LP_PrintGlonassParameters()" );

		CheckReturnCode( LP_Glonass_SetDeactivate(), "LP_Glonass_SetDeactivate()" );
		//----------------------------//
		//   Disconnect the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Term(), "LP_Term()" );
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	PrintErrorStatus( status, "GLONASS" );
}

void ReadLogFiles (void)
{
	FILE *fp = NULL;
	char strLine[MAX_BUFFER_SIZE] = {'\0'};
	strcutResult sResult;

	//_mkdir(".\\Log");
	fopen_s(&fp,".\\Log\\Log_all.txt", "r");
	//fopen_s(&fp,".\\Log\\Log_all.txt", "w");//Luke 2012-08-02
	if (!fp)  //Log_all.txt is not exsited
	{
		//printf("[ERROR]  No \"Log_all.txt\"!");
		//printf("\nPress Any Key to exit...\n");
		//_getch();
		printf("[ERROR]  No \"Log_all.txt\"!\n");

	}
	else   // Log_all.txt existed
	{
		//sResult.LP_Init.clear();
		while (fgets(strLine,MAX_BUFFER_SIZE,fp) != NULL)
		{

			if (strstr(strLine,"[IQMEASURE],"))  // Context we need
			{
				if( strstr(strLine, "[LP_Init]"))
				{
					sResult.LP_Init.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_InitTester]"))
				{
					sResult.LP_InitTester.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetVersion]"))
				{
					sResult.LP_GetVersion.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsg"))
				{
					sResult.LP_SetVsg.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsgModulation]"))
				{
					sResult.LP_SetVsgModulation.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_EnableVsgRF]"))
				{
					sResult.LP_EnableVsgRF.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsa]"))
				{
					sResult.LP_SetVsa.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_VsaDataCapture]"))
				{
					sResult.LP_VsaDataCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveVsaSignalFile]"))
				{
					sResult.LP_SaveVsaSignalFile.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnayzeFFT]"))
				{
					sResult.LP_AnalyzeFFT.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzePower]"))
				{
					sResult.LP_AnalyzePower.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80211ac]"))
				{
					sResult.LP_Analyze80211ac.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Term]"))
				{
					sResult.LP_Term.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetIQapiHndl]"))
				{
					sResult.LP_GetIQapiHndl.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_InitTester2]"))
				{
					sResult.LP_InitTester2.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_InitTester3]"))
				{
					sResult.LP_InitTester3.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_InitTester4]"))
				{
					sResult.LP_InitTester4.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_ConClose]"))
				{
					sResult.LP_ConClose.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_ConOpen]"))
				{
					sResult.LP_ConOpen.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetErrorString]"))
				{
					sResult.LP_GetErrorString.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetIQapiHndlLastErrMsg]"))
				{
					sResult.LP_GetIQapiHndlLastErrMsg.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_DualHead_ConOpen]"))
				{
					sResult.LP_DualHead_ConOpen.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_DualHead_GetTokenID]"))
				{
					sResult.LP_DualHead_GetTokenID.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_DualHead_ConClose]"))
				{
					sResult.LP_DualHead_ConClose.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_DualHead_ObtainControl]"))
				{
					sResult.LP_DualHead_ObtainControl.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_DualHead_ReleaseControl]"))
				{
					sResult.LP_DualHead_ReleaseControl.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetFrequency]"))
				{
					sResult.LP_FM_SetFrequency.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetCarrierPower]"))
				{
					sResult.LP_FM_SetCarrierPower.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsg_GapPower]"))
				{
					sResult.LP_SetVsg_GapPower.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsg_PowerLevel]"))
				{
					sResult.LP_SetVsg_PowerLevel.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsgCw]"))
				{
					sResult.LP_SetVsgCw.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveSignalArrays]"))
				{
					sResult.LP_SaveSignalArrays.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveIQDataToModulationFile]"))
				{
					sResult.LP_SaveIQDataToModulationFile.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetAnalysisParameterInteger]"))
				{
					sResult.LP_SetAnalysisParameterInteger.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetAnalysisParameterIntegerArray]"))
				{
					sResult.LP_SetAnalysisParameterIntegerArray.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_CopyVsaCaptureData]"))
				{
					sResult.LP_CopyVsaCaptureData.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_LoadVsaSignalFile]"))
				{
					sResult.LP_LoadVsaSignalFile.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveVsaGeneratorFile]"))
				{
					sResult.LP_SaveVsaGeneratorFile.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsaBluetooth]"))
				{
					sResult.LP_SetVsaBluetooth.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsaTriggerTimeout]"))
				{
					sResult.LP_SetVsaTriggerTimeout.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsaAmplitudeTolerance]"))
				{
					sResult.LP_SetVsaAmplitudeTolerance.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Agc]"))
				{
					sResult.LP_Agc.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetFrameCnt]"))
				{
					sResult.LP_SetFrameCnt.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_TxDone]"))
				{
					sResult.LP_TxDone.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_EnableSpecifiedVsgRF]"))
				{
					sResult.LP_EnableSpecifiedVsgRF.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_EnableSpecifiedVsaRF]"))
				{
					sResult.LP_EnableSpecifiedVsaRF.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetVsaSettings]"))
				{
					sResult.LP_GetVsaSettings.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetSampleData]"))
				{
					sResult.LP_GetSampleData.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SelectCaptureRangeForAnalysis]"))
				{
					sResult.LP_SelectCaptureRangeForAnalysis.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80216d]"))
				{
					sResult.LP_Analyze80216d.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80216e]"))
				{
					sResult.LP_Analyze80216e.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80211p]"))
				{
					sResult.LP_Analyze80211p.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80211ag]"))
				{
					sResult.LP_Analyze80211ag.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80211n]"))
				{
					sResult.LP_Analyze80211n.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeMimo]"))
				{
					sResult.LP_AnalyzeMimo.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Analyze80211b]"))
				{
					sResult.LP_Analyze80211b.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeCCDF]"))
				{
					sResult.LP_AnalyzeCCDF.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeCW]"))
				{
					sResult.LP_AnalyzeCW.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeCWFreq]"))
				{
					sResult.LP_AnalyzeCWFreq.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalysisWave]"))
				{
					sResult.LP_AnalysisWave.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeSidelobe]"))
				{
					sResult.LP_AnalyzeSidelobe.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzePowerRampOFDM]"))
				{
					sResult.LP_AnalyzePowerRampOFDM.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzePowerRamp80211b]"))
				{
					sResult.LP_AnalyzePowerRamp80211b.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeBluetooth]"))
				{
					sResult.LP_AnalyzeBluetooth.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeZigbee]"))
				{
					sResult.LP_AnalyzeZigbeeTerm.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeHT40Mask]"))
				{
					sResult.LP_AnalyzeHT40Mask.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetScalarMeasurment]"))
				{
					sResult.LP_GetScalarMeasurment.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetVectorMeasurment]"))
				{
					sResult.LP_GetVectorMeasurment.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetStringMeasurment]"))
				{
					sResult.LP_GetStringMeasurment.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetScalarMeasurement]"))
				{
					sResult.LP_GetScalarMeasurement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetVectorMeasurement]"))
				{
					sResult.LP_GetVectorMeasurement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_GetStringMeasurement]"))
				{
					sResult.LP_GetStringMeasurement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_PlotDataCapture]"))
				{
					sResult.LP_PlotDataCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_Plot]"))
				{
					sResult.LP_Plot.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_StartIQmeasureTimer]"))
				{
					sResult.LP_StartIQmeasureTimer.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_StopIQmeasureTimer]"))
				{
					sResult.LP_StopIQmeasureTimer.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_ReportTimerDurations]"))
				{
					sResult.LP_ReportTimerDurations.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[SetTesterHwVersion]"))
				{
					sResult.SetTesterHwVersion.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[GetTesterHwVersion]"))
				{
					sResult.GetTesterHwVersion.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetLpcPath]"))
				{
					sResult.LP_SetLpcPath.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetVsg]"))
				{
					sResult.LP_FM_SetVsg.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetVsgSettings]"))
				{
					sResult.LP_FM_GetVsgSettings.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetAudioSingleTone]"))
				{
					sResult.LP_FM_SetAudioSingleTone.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetAudioToneArray]"))
				{
					sResult.LP_FM_SetAudioToneArray.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetAudioToneArrayDeviation]"))
				{
					sResult.LP_FM_SetAudioToneArrayDeviation.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetAudioToneArray]"))
				{
					sResult.LP_FM_GetAudioToneArray.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_DeleteAudioTones]"))
				{
					sResult.LP_FM_DeleteAudioTones.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_StartVsg]"))
				{
					sResult.LP_FM_StartVsg.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_StopVsg]"))
				{
					sResult.LP_FM_StopVsg.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetVsgDistortion]"))
				{
					sResult.LP_FM_SetVsgDistortion.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetVsgDistortion]"))
				{
					sResult.LP_FM_GetVsgDistortion.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_StartVsgInterference]"))
				{
					sResult.LP_FM_StartVsgInterference.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetVsgInterferenceSettings]"))
				{
					sResult.LP_FM_GetVsgInterferenceSettings.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_StopVsgInterference]"))
				{
					sResult.LP_FM_StopVsgInterference.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetVsa]"))
				{
					sResult.LP_FM_SetVsa.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetVsaSettings]"))
				{
					sResult.LP_FM_GetVsaSettings.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_VsaDataCapture]"))
				{
					sResult.LP_FM_VsaDataCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_Analyze_RF]"))
				{
					sResult.LP_FM_Analyze_RF.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_Analyze_Demod]"))
				{
					sResult.LP_FM_Analyze_Demod.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_Analyze_Audio_Mono]"))
				{
					sResult.LP_FM_Analyze_Audio_Mono.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_Analyze_Audio_Stereo]"))
				{
					sResult.LP_FM_Analyze_Audio_Stereo.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetScalarMeasurement]"))
				{
					sResult.LP_FM_GetScalarMeasurement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_GetVectorMeasurement]"))
				{
					sResult.LP_FM_GetVectorMeasurement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_AudioDataCapture]"))
				{
					sResult.LP_FM_AudioDataCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_LoadAudioCapture]"))
				{
					sResult.LP_FM_LoadAudioCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_AudioStimulusGenerateAndPlayMultiTone]"))
				{
					sResult.LP_FM_AudioStimulusGenerateAndPlayMultiTone.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_AudioStimulusGenerateAndPlaySingleTone]"))
				{
					sResult.LP_FM_AudioStimulusGenerateAndPlaySingleTone.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_StopAudioPlay]"))
				{
					sResult.LP_FM_StopAudioPlay.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveVsaSignalFileText]"))
				{
					sResult.LP_SaveVsaSignalFileText.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SaveTruncateCapture]"))
				{
					sResult.LP_SaveTruncateCapture.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_PwrCalFastGetElemen]"))
				{
					sResult.LP_PwrCalFastGetElemen.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FM_SetAudioToneModeAmplitude]"))
				{
					sResult.LP_FM_SetAudioToneModeAmplitude.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_SetVsg_triggerType]"))
				{
					sResult.LP_SetVsg_triggerType.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_AnalyzeVHT80Mask]"))
				{
					sResult.LP_AnalyzeVHT80Mask.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FastCalGetPowerData]"))
				{
					sResult.LP_FastCalGetPowerData.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_PwrCalFreeElement]"))
				{
					sResult.LP_PwrCalFreeElement.push_back(strLine);
					continue;
				}
				else if (strstr(strLine, "[LP_FastCalMeasPower]"))
				{
					sResult.LP_FastCalMeasPower.push_back(strLine);
					continue;
				}
				else
					sResult.LP_others.push_back(strLine);
			}
			else  //Context we don't need
			{
				continue;
			}
		}
		fclose(fp);
	}

	//Write to csv file
	fopen_s(&fp,g_csvFileName,"w+");
	if ( !fp)
	{
		//printf("[ERROR]  Open csv file failed!");
		//printf("\nPress Any Key to exit...\n");
		//_getch();
		printf("[ERROR]  Open csv file failed!\n");
	}


	if ( fp )
	{
		for (unsigned int i=0; i<sResult.GetTesterHwVersion.size();i++)
			fprintf(fp,"%s",sResult.GetTesterHwVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Agc.size();i++)
			fprintf(fp,"%s",sResult.LP_Agc.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalysisWave.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalysisWave.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211ac.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80211ac.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211ag.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80211ag.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211b.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80211b.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211n.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80211n.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211p.size();i++)
			fprintf(fp,"%s",sResult.GetTesterHwVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80211p.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80216d.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80216d.size();i++)
			fprintf(fp,"%s",sResult.LP_Analyze80216e.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Analyze80216e.size();i++)
			fprintf(fp,"%s",sResult.GetTesterHwVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeBluetooth.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeBluetooth.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeCCDF.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeCCDF.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeCW.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeCW.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeCWFreq.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeCWFreq.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeFFT.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeFFT.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeHT40Mask.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeHT40Mask.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeMimo.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeMimo.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzePower.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzePower.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzePowerRamp80211b.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzePowerRamp80211b.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzePowerRampOFDM.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzePowerRampOFDM.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeSidelobe.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeSidelobe.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeVHT80Mask.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeVHT80Mask.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeZigbee.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeZigbee.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_ConClose.size();i++)
			fprintf(fp,"%s",sResult.LP_ConClose.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_ConOpen.size();i++)
			fprintf(fp,"%s",sResult.LP_ConOpen.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_CopyVsaCaptureData.size();i++)
			fprintf(fp,"%s",sResult.LP_CopyVsaCaptureData.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_DualHead_ConClose.size();i++)
			fprintf(fp,"%s",sResult.LP_DualHead_ConClose.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_DualHead_ConOpen.size();i++)
			fprintf(fp,"%s",sResult.LP_DualHead_ConOpen.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_DualHead_GetTokenID.size();i++)
			fprintf(fp,"%s",sResult.LP_DualHead_GetTokenID.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_DualHead_ObtainControl.size();i++)
			fprintf(fp,"%s",sResult.LP_DualHead_ObtainControl.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_DualHead_ReleaseControl.size();i++)
			fprintf(fp,"%s",sResult.LP_DualHead_ReleaseControl.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_EnableSpecifiedVsaRF.size();i++)
			fprintf(fp,"%s",sResult.LP_EnableSpecifiedVsaRF.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_EnableSpecifiedVsgRF.size();i++)
			fprintf(fp,"%s",sResult.LP_EnableSpecifiedVsgRF.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_EnableVsgRF.size();i++)
			fprintf(fp,"%s",sResult.LP_EnableVsgRF.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FastCalGetPowerData.size();i++)
			fprintf(fp,"%s",sResult.LP_FastCalGetPowerData.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FastCalMeasPower.size();i++)
			fprintf(fp,"%s",sResult.LP_FastCalMeasPower.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_Analyze_Audio_Mono.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_Analyze_Audio_Mono.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_Analyze_Audio_Stereo.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_Analyze_Audio_Stereo.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_Analyze_Demod.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_Analyze_Demod.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_Analyze_RF.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_Analyze_RF.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_AudioDataCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_AudioDataCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_AudioStimulusGenerateAndPlayMultiTone.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_AudioStimulusGenerateAndPlayMultiTone.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_AudioStimulusGenerateAndPlaySingleTone.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_AudioStimulusGenerateAndPlaySingleTone.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_DeleteAudioTones.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_DeleteAudioTones.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetAudioToneArray.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetAudioToneArray.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetScalarMeasurement.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetScalarMeasurement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetVectorMeasurement.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetVectorMeasurement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetVsaSettings.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetVsaSettings.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetVsgDistortion.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetVsgDistortion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetVsgInterferenceSettings.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetVsgInterferenceSettings.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_GetVsgSettings.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_GetVsgSettings.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_LoadAudioCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_LoadAudioCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetAudioSingleTone.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetAudioSingleTone.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetAudioToneArray.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetAudioToneArray.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetAudioToneArrayDeviation.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetAudioToneArrayDeviation.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetAudioToneArrayDeviation.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetAudioToneArrayDeviation.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetAudioToneModeAmplitude.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetAudioToneModeAmplitude.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetCarrierPower.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetCarrierPower.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetFrequency.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetFrequency.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetVsa.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetVsa.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetVsg.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetVsg.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_SetVsgDistortion.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_SetVsgDistortion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_StartVsg.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_StartVsg.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_StartVsgInterference.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_StartVsgInterference.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_StopAudioPlay.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_StopAudioPlay.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_StopVsgInterference.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_StopVsgInterference.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_StopVsg.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_StopVsg.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_FM_VsaDataCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_FM_VsaDataCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetErrorString.size();i++)
			fprintf(fp,"%s",sResult.LP_GetErrorString.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetIQapiHndl.size();i++)
			fprintf(fp,"%s",sResult.LP_GetIQapiHndl.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetIQapiHndlLastErrMsg.size();i++)
			fprintf(fp,"%s",sResult.LP_GetIQapiHndlLastErrMsg.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetSampleData.size();i++)
			fprintf(fp,"%s",sResult.LP_GetSampleData.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetScalarMeasurement.size();i++)
			fprintf(fp,"%s",sResult.LP_GetScalarMeasurement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetScalarMeasurment.size();i++)
			fprintf(fp,"%s",sResult.LP_GetScalarMeasurment.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetStringMeasurement.size();i++)
			fprintf(fp,"%s",sResult.LP_GetStringMeasurement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetStringMeasurment.size();i++)
			fprintf(fp,"%s",sResult.LP_GetStringMeasurment.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetTesterHwVersion.size();i++)
			fprintf(fp,"%s",sResult.LP_GetTesterHwVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetVectorMeasurement.size();i++)
			fprintf(fp,"%s",sResult.LP_GetVectorMeasurement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetVectorMeasurment.size();i++)
			fprintf(fp,"%s",sResult.LP_GetVectorMeasurment.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetVersion.size();i++)
			fprintf(fp,"%s",sResult.LP_GetVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_GetVsaSettings.size();i++)
			fprintf(fp,"%s",sResult.LP_GetVsaSettings.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Init.size();i++)
			fprintf(fp,"%s",sResult.LP_Init.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_InitTester.size();i++)
			fprintf(fp,"%s",sResult.LP_InitTester.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_InitTester2.size();i++)
			fprintf(fp,"%s",sResult.LP_InitTester2.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_InitTester3.size();i++)
			fprintf(fp,"%s",sResult.LP_InitTester3.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_InitTester4.size();i++)
			fprintf(fp,"%s",sResult.LP_InitTester4.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_LoadVsaSignalFile.size();i++)
			fprintf(fp,"%s",sResult.LP_LoadVsaSignalFile.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_AnalyzeZigbeeTerm.size();i++)
			fprintf(fp,"%s",sResult.LP_AnalyzeZigbeeTerm.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_others.size();i++)
			fprintf(fp,"%s",sResult.LP_others.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Plot.size();i++)
			fprintf(fp,"%s",sResult.LP_Plot.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_PlotDataCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_PlotDataCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_PwrCalFastGetElemen.size();i++)
			fprintf(fp,"%s",sResult.LP_PwrCalFastGetElemen.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_PwrCalFastGetElement.size();i++)
			fprintf(fp,"%s",sResult.LP_PwrCalFastGetElement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_PwrCalFreeElement.size();i++)
			fprintf(fp,"%s",sResult.LP_PwrCalFreeElement.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_ReportTimerDurations.size();i++)
			fprintf(fp,"%s",sResult.LP_ReportTimerDurations.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveIQDataToModulationFile.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveIQDataToModulationFile.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveSignalArrays.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveSignalArrays.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveTruncateCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveTruncateCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveVsaGeneratorFile.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveVsaGeneratorFile.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveVsaSignalFile.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveVsaSignalFile.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SaveVsaSignalFileText.size();i++)
			fprintf(fp,"%s",sResult.LP_SaveVsaSignalFileText.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SelectCaptureRangeForAnalysis.size();i++)
			fprintf(fp,"%s",sResult.LP_SelectCaptureRangeForAnalysis.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetAnalysisParameterInteger.size();i++)
			fprintf(fp,"%s",sResult.LP_SetAnalysisParameterInteger.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetAnalysisParameterIntegerArray.size();i++)
			fprintf(fp,"%s",sResult.LP_SetAnalysisParameterIntegerArray.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetFrameCnt.size();i++)
			fprintf(fp,"%s",sResult.LP_SetFrameCnt.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetLpcPath.size();i++)
			fprintf(fp,"%s",sResult.LP_SetLpcPath.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetTesterHwVersion.size();i++)
			fprintf(fp,"%s",sResult.LP_SetTesterHwVersion.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsa.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsa.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsaAmplitudeTolerance.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsaAmplitudeTolerance.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsaBluetooth.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsaBluetooth.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsaTriggerTimeout.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsaTriggerTimeout.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsg.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsg.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsg_GapPower.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsg_GapPower.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsg_PowerLevel.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsg_PowerLevel.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsg_triggerType.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsg_triggerType.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsgCw.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsgCw.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_SetVsgModulation.size();i++)
			fprintf(fp,"%s",sResult.LP_SetVsgModulation.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_StartIQmeasureTimer.size();i++)
			fprintf(fp,"%s",sResult.LP_StartIQmeasureTimer.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_StopIQmeasureTimer.size();i++)
			fprintf(fp,"%s",sResult.LP_StopIQmeasureTimer.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_Term.size();i++)
			fprintf(fp,"%s",sResult.LP_Term.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_TxDone.size();i++)
			fprintf(fp,"%s",sResult.LP_TxDone.at(i).c_str());
		for (unsigned int i=0; i<sResult.LP_VsaDataCapture.size();i++)
			fprintf(fp,"%s",sResult.LP_VsaDataCapture.at(i).c_str());
		for (unsigned int i=0; i<sResult.SetTesterHwVersion.size();i++)
			fprintf(fp,"%s",sResult.SetTesterHwVersion.at(i).c_str());

		fclose(fp);

	}

}

void QA_Multithread(vector<string>* testerIPVector)
{
   std::cout << "QA_Multithread called" << std::endl;
   std::cout << "testerIPVector->size() = " << testerIPVector->size() << std::endl;

   unsigned int i;

   HANDLE handles[4];
   size_t handle_count = 0;

	LP_SetConcurrency();
   for (i = 0; i < testerIPVector->size(); i++)
   	{
       std::cout << "ip = " << (*testerIPVector)[i] << std:: endl;

	   char *pIp = (char*)(*testerIPVector)[i].c_str();

	   std::cout << "pIp = " << pIp << std::endl;

	   handles[i] = (HANDLE)_beginthreadex(0, 0, &WiFi_11ac_Loopback_multithread, pIp , 0, 0);
	   ++handle_count;
   	}

   for ( i = 0; i < handle_count; ++i )
   {
		WaitForSingleObject( handles[i], INFINITE );
		CloseHandle( handles[i] );
   }
}


//#define DO_SIMPLE_MT_TEST 1

unsigned int  __stdcall WiFi_11ac_Loopback_multithread(void *data)
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];
	double  bufferReal[MAX_BUFFER_SIZE], bufferImag[MAX_BUFFER_SIZE];
	double  *IData, *QData;
	double dutPowerLevel = -20;		// Estimated RMS power level at IQTester
	double cableLoss = 1; //dB of path loss
	double maxCaptureTime=0.0, minCaptureTime=1e6, maxAnalysisTime=0.0, minAnalysisTime=1e6;
	bool licenseAvailable;

	
//	std::string testerIP = static_cast<string*>(data);
	char *pTesterIP = (char*)(data);
	//std::string testerIP = "192.168.14.75";

	unsigned int num_runs = 4;

    std::cout << "WiFi_11ac_Loopback_multithread called, pTesterIP = " << pTesterIP << std::endl;

	for ( size_t _run = 0; _run < num_runs; ++_run )
	{

		IData = new double [280000];
		QData = new double [280000];

		try
		{


			//----------------------------//
			//   Initialize the IQTester  //
			//----------------------------//

			int testerControl = 1;		// use IQmeasure_SCPI

	DWORD _thread_id = GetCurrentThreadId();
			CheckReturnCode( LP_Init(IQTYPE_XEL, testerControl), "LP_Init()" );

#if !defined DO_SIMPLE_MT_TEST
			CheckReturnCode( LP_InitTesterN((char*) data), "LP_InitTesterN()" );
     		int selectedModules[1] = {1};
	    	CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );

			if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)	printf("\n%s\n\n", buffer);
		
			LP_CheckLicense("WLANAC",&licenseAvailable);
			if(licenseAvailable)
			{
				printf("WLANAC license is available!\n");
			}
			else
			{
				printf("WLANAC license is not available!\n");
			}


			//-------------//
			//  Setup VSG  //
			//-------------//
			CheckReturnCode( LP_SetVsg(FREQ_HZ_5G, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

			//--------------------//
			// Load waveform file //
			//--------------------//

			CheckReturnCode( LP_SetVsgModulation("../../iqvsg/WiFi_11AC_VHT80_S1_MCS5.iqvsg",0), "LP_SetVsgModulation()" );

			//---------------//
			//  Turn on VSG  //
			//---------------//
			CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

			//------------------------------------------//
			//   Send packet, continuous transmission   //
			//------------------------------------------//
			int frameCnt = 0; //100;	// number of frame to send, 0 means continuous transmission.
			CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );


			//----------------//
			//   Setup VSA    //
			//----------------//
			int peakToAverageRatio = 10;

			double samplingRate = 160e6;
			
			CheckReturnCode( LP_SetVsa(FREQ_HZ_5G, (dutPowerLevel+peakToAverageRatio-cableLoss), PORT_LEFT), "LP_SetVsa()" );

			//----------------------//
			//  Perform VSA capture //
			//----------------------//
			double captureTime =500e-6;
			CheckReturnCode( LP_VsaDataCapture(captureTime, 13,160e6), "LP_VsaDataCapture()" ); //trigger type was 2, only for instrument driver? in IQapi, it is for external trigger?

			//---------------------------//
			//  Save sig file for debug  //
			//---------------------------//

			CheckReturnCode( LP_GetSampleData(0,IData,QData,280000), "LP_GetSampleData()" );
			char saveCapturedName1[MAX_BUFFER_SIZE] = "WiFi_11ac.iqvsa";
			char saveCapturedName2[MAX_BUFFER_SIZE] = "WiFi_11ac.iqvsg";
			char saveCapturedName3[MAX_BUFFER_SIZE] = "WiFi_11ac.txt";
			CheckReturnCode( LP_SaveVsaSignalFile(saveCapturedName1), "LP_SaveVsaSignalFile()" );
			CheckReturnCode( LP_SaveVsaGeneratorFile(saveCapturedName2), "LP_SaveVsaGeneratorFile()" );
			CheckReturnCode( LP_SaveVsaSignalFileText(saveCapturedName3), "LP_SaveVsaSignalFileText()" );


			////-------------------------//
			////  Perform CCDF analysis //
			////-------------------------//
			double result;

			CheckReturnCode( LP_AnalyzeCCDF(), "LP_AnalyzeCCDF()");

			result = ::LP_GetVectorMeasurement("prob", bufferReal, bufferImag, MAX_BUFFER_SIZE);
			result = ::LP_GetVectorMeasurement("power_rel_dB", bufferReal, bufferImag, MAX_BUFFER_SIZE);

			//-------------------------//
			//  Perform Power analysis //
			//-------------------------//

			CheckReturnCode( LP_AnalyzePower(3.2e-6, 15.0), "LP_AnalyzePower()" );

			//-------------------------//
			//  Retrieve Test Results  //
			//-------------------------//
		
			result = LP_GetScalarMeasurement("valid"); //result not right yet.
			printf("valid: %.0f\n", result);

			result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
			printf("P_av_each_burst_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_each_burst");
			printf("P_av_each_burst: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
			printf("P_pk_each_burst_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_pk_each_burst");
			printf("P_pk_each_burst: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_av_all_dBm");
			printf("P_av_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_all");
			printf("P_av_all: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_peak_all_dBm");
			printf("P_peak_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_peak_all");
			printf("P_peak_all: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
			printf("P_av_no_gap_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_no_gap_all");
			printf("P_av_no_gap_all: %.6f mw\n", result);


			//-------------------------//
			//  Perform 11ac analysis //
			//-------------------------//

			CheckReturnCode( LP_Analyze80211ac(), "LP_Analyze80211ac()" );

			//-------------------------//
			//  Retrieve Test Results  //
			//-------------------------//

			result = LP_GetScalarMeasurement("packetDetection");
			if (result == 0)
			{
				printf("\nValid Packet Header Detection: %s \n", "FALSE");
			}
			else
				printf("\nValid Packet Header Detection: %s \n", "TRUE");

			result = LP_GetScalarMeasurement("acquisition");
			if (result == 0)
			{
				printf("Valid HT Packet Detection: %s \n", "FALSE");
			}
			else
				printf("Valid HT Packet Detection: %s \n", "TRUE");


			result = LP_GetScalarMeasurement("psduCRC");
			if (result == 1)
			{
				printf("PSDU CRC: %s \n", "PASS");
			}
			else
				printf("PSDU CRC: %s \n", "FAIL");

			result = LP_GetScalarMeasurement("demodulation");
			if (result == 0)
			{
				printf("Streams Demodulated: %s \n\n", "FALSE");
			}
			else
				printf("Streams Demodulated: %s \n\n", "TRUE");


			result = LP_GetScalarMeasurement("freqErrorHz");
			printf("Frequency Error: %.2f Hz\n", result);

			result = LP_GetScalarMeasurement("symClockErrorPpm");
			printf("Symbol Clock Error: %.2f ppm\n", result);

			result = LP_GetScalarMeasurement("PhaseNoiseDeg_RmsAll");
			printf("RMS Phase Noise: %.2f deg\n", result);

			result = LP_GetScalarMeasurement("IQImbal_amplDb");
			printf("IQ Imbalance Amp: %.2f dB \n", result);

			result = LP_GetScalarMeasurement("IQImbal_phaseDeg");
			printf("IQ Imbalance phase: %0.2f deg \n", result);

			result = LP_GetScalarMeasurement("dcLeakageDbc");
			printf("LO leakage: %.2f dBc\n\n", result);

			double bandwidthMhz = LP_GetScalarMeasurement("rateInfo_bandwidthMhz");
			printf("Signal Bandwidth: %0.2f MHz\n", bandwidthMhz);

			result = LP_GetScalarMeasurement("rateInfo_spatialStreams");
			printf("Number of Spatial Streams: %1.0f \n", result);

			result = LP_GetScalarMeasurement("rateInfo_spaceTimeStreams");
			printf("Number of SpaceTime Streams: %1.0f \n", result);

			result = LP_GetScalarMeasurement("rateInfo_dataRateMbps");
			printf("Datarate: %0.2f Mbps\n", result);

			result = LP_GetScalarMeasurement("rxRmsPowerDb");
			printf("Power_NoGap: %.3f dBm\n", result);


			result = LP_GetScalarMeasurement("evmAvgAll");
			printf("EVM Avg All: %.3f dB\n\n", result);

			result = ::LP_GetVectorMeasurement("channelEst", bufferReal, bufferImag, MAX_BUFFER_SIZE);
			if (result <= 0)
			{
				printf("Channel Estimation returns an error\n");
			}
			else
			{
				//cacluate the spectrum flatness.
				printf("Channel Estimation returns a vector with %3.0f elements\n", result);
				int numSubcarrier = 256; //number of Subcarrier for 80MHz
				double  *carrierPwr;
				int centerStart, centerEnd, sideStart, sideEnd;
				//iqPwr  = (double *) malloc (result * sizeof (double));
				carrierPwr     = (double *) malloc (numSubcarrier * sizeof (double));
				double avgCenterPwr=0.0, avgSidePwr=0.0, avgPwrSpectral=0.0;
				double maxCarrierPwr = -999.9, minCenterCarrierPwr = 99.9, minSideCarrierPwr = 99.9;

				if (bandwidthMhz == 20.0)
				{
					numSubcarrier = 64;
					centerStart   = CARRIER_1;
					centerEnd     = CARRIER_16;
					sideStart     = CARRIER_17;
					sideEnd       = CARRIER_28;
				}
				else
				{
					if (bandwidthMhz == 40.0)
					{
						numSubcarrier = 128;
						centerStart   = CARRIER_2;
						centerEnd     = CARRIER_42;
						sideStart     = CARRIER_43;
						sideEnd       = CARRIER_58;
					}
					else
					{
						numSubcarrier = 256;
						centerStart   = CARRIER_2;
						centerEnd     = CARRIER_84;
						sideStart     = CARRIER_85;
						sideEnd       = CARRIER_122;
					}
				}
				if (result != numSubcarrier)
				{
					printf("Channel estimation results does not match number of subcarriers for %2.0f MHz signal.\n", bandwidthMhz);
				}
				else
				{
					for (int carrier=0;carrier<result;carrier++) //only one stream here.
					{
						carrierPwr[carrier] = bufferReal[carrier]*bufferReal[carrier]+ bufferImag[carrier]*bufferImag[carrier];
					}
					// average power in the center
					for ( int i=centerStart;i<=centerEnd;i++)
					{
						avgCenterPwr = avgCenterPwr + carrierPwr[i] + carrierPwr[numSubcarrier-i];
					}
					// average power on side lobe.
					for (int i=sideStart;i<=sideEnd;i++)
					{
						avgSidePwr = avgSidePwr + carrierPwr[i] + carrierPwr[numSubcarrier-i];
					}

					avgPwrSpectral = avgCenterPwr+ avgSidePwr;

					avgCenterPwr = avgCenterPwr/((centerEnd-centerStart+1)*2);
					if (0!=avgCenterPwr)
					{
						avgCenterPwr = 10.0 * log10 (avgCenterPwr);
					}
					else
					{
						avgCenterPwr= 0;
					}
					avgPwrSpectral = avgPwrSpectral/((sideEnd-centerStart+1)*2);
					if (0!=avgPwrSpectral)
					{
						avgPwrSpectral = 10.0 * log10 (avgPwrSpectral);
					}
					else
					{
						avgPwrSpectral = 0;
					}

					for (int carrier=0;carrier<numSubcarrier;carrier++)
					{
						if (0!=carrierPwr[carrier])
						{
							carrierPwr[carrier] = 10.0 * log10 (carrierPwr[carrier]);
							if (carrierPwr[carrier]>maxCarrierPwr)
							{
								maxCarrierPwr = carrierPwr[carrier];
							}
							if ( (carrier>=centerStart && carrier <=centerEnd) || (carrier>=numSubcarrier-centerEnd && carrier <= numSubcarrier-centerStart) )
							{
								if(carrierPwr[carrier]< minCenterCarrierPwr)
								{
									minCenterCarrierPwr = carrierPwr[carrier];
								}
							}
							if ((carrier>=sideStart && carrier <=sideEnd) || (carrier>=numSubcarrier-sideEnd && carrier <=numSubcarrier-sideStart) )
							{
								if(carrierPwr[carrier]< minSideCarrierPwr)
								{
									minSideCarrierPwr = carrierPwr[carrier];
								}
							}
						}
						else
						{
							carrierPwr[carrier] = 0;
						}
					}
					printf("The maximum deviation is %0.2f dB\n", maxCarrierPwr-avgCenterPwr);
					printf("The minimum deviation are %0.2f dB in the center, %0.2f dB in the far side\n", minCenterCarrierPwr-avgCenterPwr, minSideCarrierPwr-avgCenterPwr);
					printf("The LO Leakage is %0.2f dBc \n", carrierPwr[0] - avgPwrSpectral - 10 * log10((double)((sideEnd-centerStart+1)*2)) );
				}

			}

			printf("11AC VHT Sig field Info:\n");
			result = LP_GetScalarMeasurement("VHTSigA1Bandwidth");
			printf("VHTSigA1Bandwidth=%1.0f. Means: %3.0f MHz\n", result, pow(2,result)*20);

			result = LP_GetScalarMeasurement("VHTSigA1Stbc");
			printf("VHTSigA1Stbc=%1.0f. Means: ", result);
			if(result == 0)
			{
				printf("STBC is not enabled for all streams.\n");
			}
			else
				printf("STBC is enabled for all streams.\n");

			result = LP_GetScalarMeasurement("VHTSigA2ShortGI");
			printf("VHTSigA2ShortGI=%1.0f\n", result);
			result = LP_GetScalarMeasurement("VHTSigA2AdvancedCoding");
			printf("VHTSigA2AdvancedCoding=%1.0f\n", result);
			result = LP_GetScalarMeasurement("VHTSigA2McsIndex");
			printf("VHTSigA2McsIndex=%1.0f\n", result);

			result = LP_GetScalarMeasurement("vhtSigBFieldCRC");
			printf("vhtSigBFieldCRC=%1.0f\n\n", result);

			//----------------//
			//  Turn off VSG  //
			//----------------//
			CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );
			printf("\n");

#endif

		}
		catch(...)
		{
			status = IQMT_ERR_FUNCTION_FAIL;
		}

		//free(IData);
		//free(QData);
		delete [] IData;
		delete [] QData;
		CheckReturnCode( LP_Term(), "LP_Term()" );

		//printf(">>>>>>>> flow run %d done. \n", _run );

	}	// runs loop

	ReadLogFiles();
	PrintErrorStatus( status, "ac" );

	return 0;
}

void zWave_Loopback(void)
{
	int		status	=	IQMT_ERR_OK;
	char   buffer[MAX_BUFFER_SIZE];	
	double dutPowerLevel = -10;		// Estimated RMS power level at IQTester
	double power_check_tolerance=2;   //  (units=dB), the tolerance of expected measured power 
	double cableLoss = 1;           //dB of path loss
	double maxCaptureTime=0.0, minCaptureTime=1e6, maxAnalysisTime=0.0, minAnalysisTime=1e6;
	double freqHz;
	double freq_error_limit=27e-6;  // the Tx frequency error shall not exceed 27ppm from G.9959
	double  bufferReal[MAX_BUFFER_SIZE], bufferImag[MAX_BUFFER_SIZE];


	try
	{	
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//
		CheckReturnCode( LP_Init(ciTesterType, ciTesterControlMode), "LP_Init()" );

		CheckReturnCode( LP_InitTester(IP_ADDR), "LP_InitTester()" );


		if (LP_GetVersion(buffer, MAX_BUFFER_SIZE)==true)
			printf("\n%s\n\n", buffer);



		freqHz = 908e6;  //high Z-Wave channel 


		string tempString = "ZWAVE_R1_Fs20M";
		//-------------//
		//  Setup VSG  //
		//-------------//

		CheckReturnCode( LP_SetVsg(freqHz, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

		//--------------------//
		// Load waveform file //
		//--------------------//

		string modFileName="../../iqvsg/";
		modFileName+=tempString;
		modFileName+=".iqvsg";


		printf("\n Loading mode file %s  \n", modFileName.c_str());
		printf(" testing frequency %.0f MHz \n\n",freqHz/1000000);

		CheckReturnCode( LP_SetVsgModulation((char*)modFileName.c_str()), "LP_SetVsgModulation()" );

		//---------------//
		//  Turn on VSG  //
		//---------------//
		CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

		//------------------------------------------//
		//   Send packet, continuous transmission   //				
		//------------------------------------------//
		int frameCnt = 0;	// number of frame to send, 0 means continuous transmission.
		int err =0;
		CheckReturnCode( LP_SetFrameCnt(0), "LP_SetFrameCnt()" );

		//----------------//
		//   Setup VSA    //
		//----------------//
		int peakToAverageRatio = 5;    // this parameter may need to be modified; victor

		double samplingRate;       
		double captureTime;

		samplingRate = 20e6;


		/* the trigger level and trigger pre-time we keep it for flexibility; use default now */
		/* note that the following function did not setup the correct "g_moduleForPowerAnalysis" for powerAnalyzer */
		CheckReturnCode( LP_SetVsa(freqHz, (dutPowerLevel+peakToAverageRatio-cableLoss), PORT_LEFT, 0, -25, 10e-6), "LP_SetVsa()" ); 

		//----------------------//
		//  Perform VSA capture //
		//----------------------//
		captureTime = 5e-2;
		CheckReturnCode( LP_VsaDataCapture(captureTime, 6, samplingRate), "LP_VsaDataCapture()" );
		CheckReturnCode( LP_SaveVsaSignalFile("zWave_capture"), "LP_SaveVsaSignalFile()" );

		//-------------------------//
		//  Retrieve Test Results  //
		//-------------------------//
		double result1,result2,result3,result4,result5,result6,result7,result8,result9,result10,result11,result12,result13,
			result14,result15,result16,result17;

		LP_SelectCaptureRangeForAnalysis(0,0,1,1);  //the first two parameters are for IQ2010, the second two are for IQxel

		CheckReturnCode( LP_AnalyzeTechnologyPower(4), "LP_AnalyzeTechnologyPower()" );

		result1 = LP_GetScalarMeasurement("valid"); 
		printf("valid: %.0f\n", result1);

		result2 = LP_GetScalarMeasurement("P_av_each_burst");
		printf("P_av_each_burst: %.6f mw\n", result2);

		result3 = LP_GetScalarMeasurement("P_av_no_gap_all");
		printf("P_av_no_gap_all: %.6f mw\n", result3);

		result4 = LP_GetScalarMeasurement("P_av_max_dBm");
		printf("P_av_max: %.2f dBm\n", result4);


		result5 = LP_GetScalarMeasurement("P_av_min_dBm");
		printf("P_av_min: %.2f dBm\n", result5);

		result6 = LP_GetScalarMeasurement("P_pk_each_burst");
		printf("P_pk_each_burst: %.6f mw\n", result6);

		result7 = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
		printf("P_av_no_gap_all_dBm: %.2f dBm\n", result7);

		if(abs(dutPowerLevel- result7)>power_check_tolerance)
			CheckReturnCode(ERR_ANALYSIS_FAILED,"the measured power is abnormal");																		

		//Z-Wave analysis
		printf("\nUsing ZWAVE analysis, analysisZWAVE\n");
		CheckReturnCode(LP_AnalyzeZwave(1),"LP_AnalyzeZwave()");

		result8 = LP_GetScalarMeasurement("psduCRC");
		printf("Z-WAVE TXQ CRC: %.2f \n", result8);
		
		result9 = LP_GetScalarMeasurement("dataRate")/1000;
		printf("Z-WAVE TXQ Data rate: %.2f kbps\n", result9);
		
		result10 = LP_GetScalarMeasurement("avg_rms_rms_freqDeviation");
		printf("Z-WAVE TXQ AVER rms freq_devi: %.2f PCT\n", result10);
		
		result11 = LP_GetScalarMeasurement("avg_max_freqDeviation");
		printf("Z-WAVE TXQ AVER MAX freq_devi: %.2f PCT\n", result11);
		
		result12 = LP_GetScalarMeasurement("avg_min_freqDeviation");
		printf("Z-WAVE TXQ AVER min freq_devi: %.2f PCT\n", result12);
		
		result13 = LP_GetScalarMeasurement("avg_rms_zeroCrossingErr");
		printf("Z-WAVE TXQ AVER rms zero-crossing error: %.2f PCT\n", result13);
		
		result14 = LP_GetScalarMeasurement("avg_peak_zeroCrossingErr");
		printf("Z-WAVE TXQ AVER peak zero-crossing error: %.2f PCT\n", result14);
		
		result15 = LP_GetScalarMeasurement("avg_carrier_freq_offset");
		printf("Z-WAVE TXQ AVER freq_offset: %.4f Hz\n", result15);
		
		if(abs(result15)> (freqHz*freq_error_limit))
			CheckReturnCode(ERR_ANALYSIS_FAILED,"the Tx frequency offset is abnormal");;

		result16 = LP_GetScalarMeasurement("avg_symClockErrorPpm");
		printf("Z-WAVE TXQ AVER symbol clock error: %.3f ppm\n", result16);
		
		result17 = LP_GetScalarMeasurement("avg_symClockJitterPpm");
		printf("Z-WAVE TXQ AVER symbol clock jitter: %.3f ppm\n", result17);
		
		
		int length = 1000; // preset length of data
		double max_spectral_data=-1000;
		int max_spectral_data_idx=0;
		length = LP_GetVectorMeasurement("y", bufferReal, bufferImag, 4096);
		
		//----------------//
		//  Turn off VSG  //
		//----------------//
		CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );
		
	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}

	CheckReturnCode( LP_Term(), "LP_Term()" );

	PrintErrorStatus( status, "QA_ZWAVE" );
}

void config_get_result_idx(RESULT_INDEX* target_idx,int segment_idx, int pkt_idx, int user_idx, int stream_idx, int chain_idx)
{
    target_idx->segment_index=segment_idx;
    target_idx->packet_index=pkt_idx;
    target_idx->user_index=user_idx;
    target_idx->stream_index=stream_idx;
    target_idx->chain_index=chain_idx;

    return;
}

void WiFi_11ax_Loopback()
{
	int	    status	=	IQMT_ERR_OK;
	//char    buffer[MAX_BUFFER_SIZE];
	double  *bufferReal = new double [MAX_BUFFER_SIZE];
					
    double  *IData, *QData;
	IData = new double [280000*2];
	QData = new double [280000*2];
	double dutPowerLevel = -10;		// Estimated RMS power level at IQTester
	double cableLoss = 1; //dB of path loss
	bool licenseAvailable;
	string modFileName     = "";
	string tempString     = "";
	PACKET_FORMAT packetFormat;
	bool includeTRFrame = FALSE;
	string toneMatrix = "";
    WAVEGEN_OFDM_COMMON_SETTINGS *ofdmCommonSettings = new WAVEGEN_OFDM_COMMON_SETTINGS();
    WAVEGEN_OFDM_USER_SETTINGS *ofdmUserSettings = new WAVEGEN_OFDM_USER_SETTINGS[6];
    WAVEGEN_TFR_USER_SETTINGS *ftfUserSettings = new WAVEGEN_TFR_USER_SETTINGS[3];

	try
	{
		//----------------------------//
		//   Initialize the IQTester  //
		//----------------------------//

		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" );
		CheckReturnCode( LP_InitTesterN(IP_ADDR, 1), "LP_InitTesterN()" );
		int selectedModules[4] = {1,2,3,4};
		CheckReturnCode( LP_SetTesterMode(CONT_160MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );

		LP_CheckLicense("WLAN_AX",&licenseAvailable);
		if(licenseAvailable)
		{
			printf("802.11ax license is available!\n");
		}
		else
		{
			printf("802.11ax license is not available!\n");
		}

		for (int signal_id = 1; signal_id <= 11; signal_id++)
		{
            printf("\n============================ signal_id = %d ============================\n", signal_id);

			switch(signal_id)
			{
			case(1)://SU
				tempString = "WIFI_11AX_SU";
				packetFormat = HE_SU;
				includeTRFrame = FALSE;
				break;
			case(2)://DL MU-OFDMA
				tempString = "WIFI_11AX_DL_6_users";
				packetFormat = HE_MU;
				includeTRFrame = FALSE;
				break;
			case(3):///UL Triggered PPDU/DL MU-OFDMA
				tempString = "WIFI_11AX_TRIGGER";
				packetFormat = HE_SU;
				includeTRFrame = TRUE;
				break;		
			case(4):
				tempString = "WIFI_11AX_ERAN_SU";
				packetFormat = HE_ERAN_SU;
				includeTRFrame = TRUE;
				break;		
			case(5)://UL Triggered PPDU
				tempString = "WIFI_11AX_TRIG_FRAME";
				packetFormat = HE_SU;
				includeTRFrame = TRUE;
				break;		
			case(6):
				tempString = "WIFI_11AX_TRIG_BASED_PPDU_1_USER_SS1_3ANTENNA";
				packetFormat = HE_TR;
				includeTRFrame = FALSE;
				CheckReturnCode( LP_SetTesterMode(CONT_160MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
				break;	
			case(7):
				tempString = "WIFI_11AX_TRIG_BASED_PPDU_1_USER_SS2";
				packetFormat = HE_TR;
				includeTRFrame = FALSE;
				CheckReturnCode( LP_SetTesterMode(CONT_160MHZ_SIGNAL, selectedModules, 2), "LP_SetTesterMode()" );
				break;	
			case(8):
				tempString = "WIFI_11AX_TRIG_BASED_PPDU_3_USER_DEGR";
				packetFormat = HE_TR;
				includeTRFrame = FALSE;
				CheckReturnCode( LP_SetTesterMode(CONT_160MHZ_SIGNAL, selectedModules, 4), "LP_SetTesterMode()" );
				break;
			case(9):
				tempString = "WIFI_11AX_HEMU_ARG_TRIG_FRAME";
				packetFormat = HE_MU;
				includeTRFrame = TRUE;
				CheckReturnCode( LP_SetTesterMode(CONT_160MHZ_SIGNAL, selectedModules, 1), "LP_SetTesterMode()" );
				break;
			case(10):
				tempString = "WIFI_11AX_HEMU_UMRS";
				packetFormat = HE_MU;
				includeTRFrame = FALSE;
				break;
			case(11):
				tempString = "WIFI_11AX_TRIG_BASED_PPDU_2_USER_RU_SMAP";
				packetFormat = HE_TR;
				includeTRFrame = FALSE;
				break;
			}
			//-------------//
			//  Setup VSG  //
			//-------------//
			CheckReturnCode( LP_SetVsg(FREQ_HZ_5G, dutPowerLevel, PORT_RIGHT), "LP_SetVsg()" );

			//--------------------//
			// Load waveform file //
			//--------------------//
			memset(ofdmCommonSettings, 0, sizeof(WAVEGEN_OFDM_COMMON_SETTINGS));

			ofdmCommonSettings->numOfUsers = 1;         // default value
			ofdmCommonSettings->cbw = 20e6;             // default value 
			ofdmCommonSettings->packetPreGap  = 10e-6; // default value 
			ofdmCommonSettings->packetPostGap = 3.0e-5; // default value 
			ofdmCommonSettings->GILTF = GILTF1;         // default value 
			ofdmCommonSettings->ELTF = 0;               // default value
			ofdmCommonSettings->BSSColor = 63;          // default value
            ofdmCommonSettings->STBC = 0;

			sprintf_s(ofdmCommonSettings->sigBcBits, "%s", "00000000");
			sprintf_s(ofdmCommonSettings->ruAlloc, "%s", "(1,1,0,1,0,1,1,0,1)");
			sprintf_s(ofdmCommonSettings->powerBoostFac, "%s", "(1,1,2,1,0.5,1,1,1,1)");

			ofdmCommonSettings->sigBmcs =1;             // default value
			ofdmCommonSettings->MAC_Header_MPDU_State = MAC_HEADER_MPDU_ALL;   // default value
			ofdmCommonSettings->bw_eran = 0;            // default value
			ofdmCommonSettings->spatialMapping = SMAP_NONE;
			ofdmCommonSettings->numOfExtraAnt = 0;      // default value

			// setting for trigger frame or trigger based ppdu
			ofdmCommonSettings->aFactorTFR = 4;     // default value
			ofdmCommonSettings->PEDisambTFR = false;// default value
			ofdmCommonSettings->extranSymLDPCTFR = false;// default value

			if(includeTRFrame)
			{
				ofdmCommonSettings->numOfUsersTFR = 1;  // default value
				ofdmCommonSettings->cbwTFR = 20000000;  // default value
				ofdmCommonSettings->giltfTFR = GILTF1;  // default value	
				ofdmCommonSettings->triggeredLengthTFR = 0x010;
				ofdmCommonSettings->APTxPowerTFR = -20; // default value
				ofdmCommonSettings->numOfHELTFsymTFR = 1;// default value
				ofdmCommonSettings->MUMIMOLTFmodeTFR = false; // default value
				ofdmCommonSettings->mPADTFR = 0;         // default value
				ofdmCommonSettings->csRequiredTFR = false;    // default value
				ofdmCommonSettings->extranSymLDPCTFR = false; // default value
				ofdmCommonSettings->codingParmaTFR = false;   // default vale
			}
			if(HE_MU == packetFormat)
			{
				ofdmCommonSettings->CRU = DISABLE_ALL;        // default value
			}
			ofdmCommonSettings->duration = 0x0001;

			if(1 == signal_id)
			{
				ofdmCommonSettings->packetPreGap  = 10e-6;
				ofdmCommonSettings->packetPostGap = 500e-6;
				ofdmCommonSettings->GILTF = GILTF0;
			}
			else if (2 == signal_id)
			{
				ofdmCommonSettings->GILTF = GILTF0;
				ofdmCommonSettings->ELTF = 1;
				ofdmCommonSettings->cbw = 20e6;
				ofdmCommonSettings->sigBmcs =4;
				ofdmCommonSettings->numOfUsers = 6;
				ofdmCommonSettings->CRU = ENABLE_ALL;
			}
			else if (3 == signal_id)
			{
				ofdmCommonSettings->duration = 0x0000;
				sprintf_s(ofdmCommonSettings->ruAlloc, "%s", "(1)");
				ofdmCommonSettings->aFactorTFR = 4;
				ofdmCommonSettings->triggeredLengthTFR = 100;
			}
			else if (4 == signal_id)
			{
				ofdmCommonSettings->packetPreGap  = 10e-6;
				ofdmCommonSettings->packetPostGap = 500e-6;
				ofdmCommonSettings->GILTF = GILTF0;
				ofdmCommonSettings->aFactorTFR = 2;
				ofdmCommonSettings->PEDisambTFR = true;
				ofdmCommonSettings->APTxPowerTFR = 12;
				ofdmCommonSettings->numOfHELTFsymTFR = 2;
				ofdmCommonSettings->MUMIMOLTFmodeTFR = true;
				ofdmCommonSettings->mPADTFR = 0;
			}
			else if (5 == signal_id)
			{		
				ofdmCommonSettings->GILTF = GILTF0;
				ofdmCommonSettings->duration = 0x0000;
				sprintf_s(ofdmCommonSettings->ruAlloc, "%s", "(1)");
				ofdmCommonSettings->numOfUsersTFR = 3;
				ofdmCommonSettings->cbwTFR = 40000000;
				ofdmCommonSettings->aFactorTFR = 2;
				ofdmCommonSettings->triggeredLengthTFR = 200;
				ofdmCommonSettings->PEDisambTFR = true;
				ofdmCommonSettings->APTxPowerTFR = 10;
				ofdmCommonSettings->numOfHELTFsymTFR = 8;
				ofdmCommonSettings->MUMIMOLTFmodeTFR = true;
				ofdmCommonSettings->mPADTFR = 1;
				ofdmCommonSettings->csRequiredTFR = true;
				ofdmCommonSettings->extranSymLDPCTFR = true;
			}
			else if (7 == signal_id)
			{
				ofdmCommonSettings->cbw = 80e6;			
				ofdmCommonSettings->ELTF = 6;
			}
			else if (8 == signal_id)
			{
				ofdmCommonSettings->cbw = 80e6;
				ofdmCommonSettings->numOfUsers = 3;
				ofdmCommonSettings->GILTF = GILTF2;
				ofdmCommonSettings->ELTF = 2;
				ofdmCommonSettings->codingParmaTFR = true;
				ofdmCommonSettings->aFactorTFR = 4;
				ofdmCommonSettings->extranSymLDPCTFR = true;
				ofdmCommonSettings->legacySigLength = 619;
				ofdmCommonSettings->PEDisambTFR = true;
			}
			else if (9 == signal_id)
			{
				ofdmCommonSettings->numOfUsers = 3;
				sprintf_s(ofdmCommonSettings->ruAlloc, "%s", "(1, 1, 1)");
				ofdmCommonSettings->duration = 0x0000;
				ofdmCommonSettings->numOfUsersTFR = 3;
				ofdmCommonSettings->triggeredLengthTFR = 200;
				ofdmCommonSettings->cbwTFR = 40000000;
				ofdmCommonSettings->APTxPowerTFR = 10;
				ofdmCommonSettings->giltfTFR = GILTF0;	
				ofdmCommonSettings->aFactorTFR = 2;
				ofdmCommonSettings->PEDisambTFR = TRUE;
				ofdmCommonSettings->MUMIMOLTFmodeTFR = TRUE;
				ofdmCommonSettings->numOfHELTFsymTFR = 8;
				ofdmCommonSettings->csRequiredTFR = TRUE;
				ofdmCommonSettings->extranSymLDPCTFR = TRUE;
				ofdmCommonSettings->mPADTFR = 1;
				ofdmCommonSettings->MAC_Header_MPDU_State = MAC_HEADER_MPDU_INDI;
				sprintf_s(ofdmCommonSettings->powerBoostFac, "%s", "(1)");
			}
			else if(10 == signal_id)
			{
				ofdmCommonSettings->numOfUsers = 2;
				sprintf_s(ofdmCommonSettings->ruAlloc, "%s", "(1, 1)");
			}
			else if(11 == signal_id)
			{
				toneMatrix = "(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)";
				ofdmCommonSettings->numOfUsers = 2;
				ofdmCommonSettings->codingParmaTFR = TRUE;
				ofdmCommonSettings->legacySigLength = 619;
				ofdmCommonSettings->GILTF = GILTF2;
				ofdmCommonSettings->PEDisambTFR = TRUE;
				ofdmCommonSettings->extranSymLDPCTFR = TRUE;
				ofdmCommonSettings->aFactorTFR = 4;
				// tones setting
				ofdmCommonSettings->numOfExtraAnt = 2;
				ofdmCommonSettings->spatialMapping = SMAP_TONES;
				ofdmCommonSettings->spatialMappingMatrix = (char*)toneMatrix.c_str();
			}

			memset(ofdmUserSettings, 0x0, sizeof(WAVEGEN_OFDM_USER_SETTINGS) * 6);
			memset(ftfUserSettings, 0x0, sizeof(WAVEGEN_TFR_USER_SETTINGS) * 3);

			if(1 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 0;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 200;
				ofdmUserSettings[0].numOfMPDU = 1;
				ofdmUserSettings[0].psduType = PSDU_RANDOM;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "010000C0FFEE");
				ofdmUserSettings[0].stationID = 1;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].mpduQosEnab[0] = ENAB_AUTO;
			}
			else if(2 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 7;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 2000;
				ofdmUserSettings[0].psduType = PSDU_RANDOM;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "010000C0FFEE");
				ofdmUserSettings[0].stationID = 1;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].numOfMPDU  = 1;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;

				ofdmUserSettings[1].numOfSST = 1;
				ofdmUserSettings[1].mcs = 3;
				ofdmUserSettings[1].coding = CODING_BCC;
				ofdmUserSettings[1].mpduPsduLength[0] = 1000;
				ofdmUserSettings[1].psduType = PSDU_RANDOM;
				ofdmUserSettings[1].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[1].macAddr[0], "%s", "020000C0FFEE");
				ofdmUserSettings[1].stationID = 2;
				ofdmUserSettings[1].mped = 0;
				ofdmUserSettings[1].numOfMPDU  = 1;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				ofdmUserSettings[1].htControlEnable = ENAB_OFF;

				ofdmUserSettings[2].numOfSST = 1;
				ofdmUserSettings[2].mcs = 0;
				ofdmUserSettings[2].coding = CODING_BCC;
				ofdmUserSettings[2].mpduPsduLength[0] = 200;
				ofdmUserSettings[2].psduType = PSDU_RANDOM;
				ofdmUserSettings[2].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[2].macAddr[0], "%s", "030000C0FFEE");
				ofdmUserSettings[2].stationID = 3;
				ofdmUserSettings[2].mped = 0;
				ofdmUserSettings[2].numOfMPDU  = 1;
				ofdmUserSettings[2].mpduPsduLength[0] = 400;
				ofdmUserSettings[2].htControlEnable = ENAB_OFF;

				ofdmUserSettings[3].numOfSST = 1;
				ofdmUserSettings[3].mcs = 7;
				ofdmUserSettings[3].coding = CODING_BCC;
				ofdmUserSettings[3].mpduPsduLength[0] = 2000;
				ofdmUserSettings[3].psduType = PSDU_RANDOM;
				ofdmUserSettings[3].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[3].macAddr[0], "%s", "040000C0FFEE");
				ofdmUserSettings[3].stationID = 4;
				ofdmUserSettings[3].mped = 0;
				ofdmUserSettings[3].numOfMPDU  = 1;
				ofdmUserSettings[3].mpduPsduLength[0] = 400;
				ofdmUserSettings[3].htControlEnable = ENAB_OFF;

				ofdmUserSettings[4].numOfSST = 1;
				ofdmUserSettings[4].mcs = 3;
				ofdmUserSettings[4].coding = CODING_BCC;
				ofdmUserSettings[4].mpduPsduLength[0] = 1000;
				ofdmUserSettings[4].psduType = PSDU_RANDOM;
				ofdmUserSettings[4].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[4].macAddr[0], "%s", "050000C0FFEE");
				ofdmUserSettings[4].stationID = 5;
				ofdmUserSettings[4].mped = 0;
				ofdmUserSettings[4].numOfMPDU  = 1;
				ofdmUserSettings[4].mpduPsduLength[0] = 400;
				ofdmUserSettings[4].htControlEnable = ENAB_OFF;

				ofdmUserSettings[5].numOfSST = 1;
				ofdmUserSettings[5].mcs = 0;
				ofdmUserSettings[5].coding = CODING_BCC;
				ofdmUserSettings[5].mpduPsduLength[0] = 200;
				ofdmUserSettings[5].psduType = PSDU_RANDOM;
				ofdmUserSettings[5].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[5].macAddr[0], "%s", "060000C0FFEE");
				ofdmUserSettings[5].stationID = 6;
				ofdmUserSettings[5].mped = 0;
				ofdmUserSettings[5].numOfMPDU  = 1;
				ofdmUserSettings[5].mpduPsduLength[0] = 400;
				ofdmUserSettings[5].htControlEnable = ENAB_OFF;
			}
			else if (3 == signal_id)
			{
				ofdmUserSettings[0].psduType = PSDU_RANDOM;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				//ofdmUserSettings[0].psduBits = "00000000";
				ofdmUserSettings[0].mcs = 2;
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].dcm = FALSE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].psduCRC = TRUE;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

				ftfUserSettings[0].startingSSTTFR = 1;
				ftfUserSettings[0].numOfSSTTFR = 1;
				ftfUserSettings[0].codingTFR = CODING_BCC;
				ftfUserSettings[0].mcsTFR = 0;
				ftfUserSettings[0].RUIndexTFR = 0;
				ftfUserSettings[0].dcmTFR = FALSE;
				ftfUserSettings[0].targetRSSITFR = -1.100000e+002;
				sprintf_s(ftfUserSettings[0].AID12TFR, "%s", "000");
			}
			else if (4 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 0;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 200;
				ofdmUserSettings[0].psduType = PSDU_RANDOM;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "010000C0FFEE");
				ofdmUserSettings[0].stationID = 1;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

				sprintf_s(ftfUserSettings[0].AID12TFR, "%s", "fff");
				ftfUserSettings[0].targetRSSITFR = -50;
				ftfUserSettings[0].RUIndexTFR = 0;
				ftfUserSettings[0].startingSSTTFR = 1;
				ftfUserSettings[0].numOfSSTTFR = 1;
			}
			else if (5 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 0;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 200;
				ofdmUserSettings[0].psduType = PSDU_RANDOM;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "010000C0FFEE");
				ofdmUserSettings[0].stationID = 1;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

				sprintf_s(ftfUserSettings[0].AID12TFR, "%s", "fff");
				sprintf_s(ftfUserSettings[1].AID12TFR, "%s", "111");
				sprintf_s(ftfUserSettings[2].AID12TFR, "%s", "a94");
				ftfUserSettings[0].RUIndexTFR = 0;
				ftfUserSettings[1].RUIndexTFR = 18;
				ftfUserSettings[2].RUIndexTFR = 9;
				ftfUserSettings[0].codingTFR = CODING_BCC;
				ftfUserSettings[1].codingTFR = CODING_BCC;
				ftfUserSettings[2].codingTFR = CODING_LDPC;
				ftfUserSettings[0].mcsTFR = 11;
				ftfUserSettings[1].mcsTFR = 5;
				ftfUserSettings[2].mcsTFR = 0;
				ftfUserSettings[0].dcmTFR = true;
				ftfUserSettings[1].dcmTFR = false;
				ftfUserSettings[2].dcmTFR = true;
				ftfUserSettings[0].startingSSTTFR = 1;
				ftfUserSettings[1].startingSSTTFR = 3;
				ftfUserSettings[2].startingSSTTFR = 7;
				ftfUserSettings[0].numOfSSTTFR = 2;
				ftfUserSettings[1].numOfSSTTFR = 4;
				ftfUserSettings[2].numOfSSTTFR = 1;
				ftfUserSettings[0].targetRSSITFR = -50;
				ftfUserSettings[1].targetRSSITFR = -70;
				ftfUserSettings[2].targetRSSITFR = -100;
			}
			else if (6 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 1;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].psduType = PSDU_PN9;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].delayDEGR = 0;
				ofdmUserSettings[0].frequencyDEGR = 0;
				ofdmUserSettings[0].symbolClockDEGR = 0;
				ofdmUserSettings[0].powerDEGR =0;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].RUIndex = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;
                ofdmUserSettings[0].dcm = 1;

			}
			else if (7 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 2;
				ofdmUserSettings[0].mcs = 2;
				ofdmUserSettings[0].coding = CODING_LDPC;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].psduType = PSDU_PN9;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].RUIndex = 62;
				ofdmUserSettings[0].delayDEGR = 0;
				ofdmUserSettings[0].frequencyDEGR = 100;
				ofdmUserSettings[0].symbolClockDEGR = 0;
				ofdmUserSettings[0].powerDEGR =0;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

			}
			else if (8 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 2;
				ofdmUserSettings[0].mcs = 5;
				ofdmUserSettings[0].coding = CODING_LDPC;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].psduType = PSDU_ALL0;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].RUIndex = 53;
				ofdmUserSettings[0].delayDEGR = 0.1e-6;
				ofdmUserSettings[0].frequencyDEGR = 100;
				ofdmUserSettings[0].symbolClockDEGR = 0;
				ofdmUserSettings[0].powerDEGR =0;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

				ofdmUserSettings[1].numOfSST = 1;
				ofdmUserSettings[1].mcs = 9;
				ofdmUserSettings[1].coding = CODING_BCC;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				ofdmUserSettings[1].psduType = PSDU_ALL0;
				ofdmUserSettings[1].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[1].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[1].stationID = 1;
				ofdmUserSettings[1].RUIndex = 54;
				ofdmUserSettings[1].delayDEGR = 0;
				ofdmUserSettings[1].frequencyDEGR = -100;
				ofdmUserSettings[1].symbolClockDEGR = -10;
				ofdmUserSettings[1].powerDEGR = -3;
				ofdmUserSettings[1].mped = 0;
				ofdmUserSettings[1].htControlEnable = ENAB_OFF;
				ofdmUserSettings[1].numOfMPDU = 1;

				ofdmUserSettings[2].numOfSST = 4;
				ofdmUserSettings[2].mcs = 11;
				ofdmUserSettings[2].coding = CODING_LDPC;
				ofdmUserSettings[2].mpduPsduLength[0] = 400;
				ofdmUserSettings[2].psduType = PSDU_PN15;
				ofdmUserSettings[2].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[2].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[2].stationID = 2;
				ofdmUserSettings[2].RUIndex = 62;
				ofdmUserSettings[2].delayDEGR = -0.1e-6;
				ofdmUserSettings[2].frequencyDEGR = 0;
				ofdmUserSettings[2].symbolClockDEGR = 5;
				ofdmUserSettings[2].powerDEGR = -6;
				ofdmUserSettings[2].mped = 0;
				ofdmUserSettings[2].htControlEnable = ENAB_OFF;
				ofdmUserSettings[2].numOfMPDU = 1;

			}
			else if (9 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[1].numOfSST = 1;
				ofdmUserSettings[2].numOfSST = 1;

				ofdmUserSettings[0].mcs = 8;
				ofdmUserSettings[1].mcs = 2;
				ofdmUserSettings[2].mcs = 2;

				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				ofdmUserSettings[2].mpduPsduLength[0] = 400;

				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[1].coding = CODING_BCC;
				ofdmUserSettings[2].coding = CODING_BCC;

				ofdmUserSettings[0].psduType = PSDU_ALL0;
				ofdmUserSettings[1].psduType = PSDU_ALL0;
				ofdmUserSettings[2].psduType = PSDU_ALL1;

				ofdmUserSettings[0].psduCRC = TRUE;
				ofdmUserSettings[1].psduCRC = TRUE;
				ofdmUserSettings[2].psduCRC = TRUE;

				ofdmUserSettings[0].userAllocTFR  = 1;
				ofdmUserSettings[1].userAllocTFR  = 0;
				ofdmUserSettings[2].userAllocTFR  = 2;

				ofdmUserSettings[0].numOfMPDU  = 1;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				//sprintf_s(ofdmUserSettings[0].mpduMacAddr[0][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[0].mpduFrameControl[0], "%s", "0800");

				ofdmUserSettings[1].numOfMPDU  = 2;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				//sprintf_s(ofdmUserSettings[1].mpduMacAddr[0][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[1].mpduFrameControl[0], "%s", "0800");
				ofdmUserSettings[1].mpduPsduLength[1] = 400;
				//sprintf_s(ofdmUserSettings[1].mpduMacAddr[1][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[1].mpduFrameControl[1], "%s", "0800");

				ofdmUserSettings[2].numOfMPDU  = 3;
				ofdmUserSettings[2].mpduPsduLength[0] = 400;
				//sprintf_s(ofdmUserSettings[2].mpduMacAddr[0][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[2].mpduFrameControl[0], "%s", "0800");
				ofdmUserSettings[2].mpduPsduLength[1] = 400;
				//sprintf_s(ofdmUserSettings[2].mpduMacAddr[1][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[2].mpduFrameControl[1], "%s", "0800");
				ofdmUserSettings[2].mpduPsduLength[2] = 400;
				//sprintf_s(ofdmUserSettings[2].mpduMacAddr[2][0], "%s", "CFFFABCDE154");
				//sprintf_s(ofdmUserSettings[2].mpduFrameControl[2], "%s", "0800");

				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				sprintf_s(ofdmUserSettings[1].macAddr[0], "%s", "FFFFFFFFFFFF");
				sprintf_s(ofdmUserSettings[2].macAddr[0], "%s", "FFFFFFFFFFFF");

				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[1].stationID = 1;
				ofdmUserSettings[2].stationID = 2;

				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[1].mped = 0;
				ofdmUserSettings[2].mped = 0;

				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[1].htControlEnable = ENAB_OFF;
				ofdmUserSettings[2].htControlEnable = ENAB_OFF;

				sprintf_s(ftfUserSettings[0].AID12TFR, "%s", "fff");
				sprintf_s(ftfUserSettings[1].AID12TFR, "%s", "111");
				sprintf_s(ftfUserSettings[2].AID12TFR, "%s", "a94");
				ftfUserSettings[0].RUIndexTFR = 0;
				ftfUserSettings[1].RUIndexTFR = 18;
				ftfUserSettings[2].RUIndexTFR = 9;
				ftfUserSettings[0].codingTFR = CODING_BCC;
				ftfUserSettings[1].codingTFR = CODING_BCC;
				ftfUserSettings[2].codingTFR = CODING_LDPC;
				ftfUserSettings[0].mcsTFR = 11;
				ftfUserSettings[1].mcsTFR = 5;
				ftfUserSettings[2].mcsTFR = 0;
				ftfUserSettings[0].dcmTFR = true;
				ftfUserSettings[1].dcmTFR = false;
				ftfUserSettings[2].dcmTFR = true;
				ftfUserSettings[0].startingSSTTFR = 1;
				ftfUserSettings[1].startingSSTTFR = 3;
				ftfUserSettings[2].startingSSTTFR = 7;
				ftfUserSettings[0].numOfSSTTFR = 2;
				ftfUserSettings[1].numOfSSTTFR = 4;
				ftfUserSettings[2].numOfSSTTFR = 1;
				ftfUserSettings[0].targetRSSITFR = -50;
				ftfUserSettings[1].targetRSSITFR = -70; 
				ftfUserSettings[2].targetRSSITFR = -100;
			}
			else if(10 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 8;
				ofdmUserSettings[0].coding = CODING_BCC;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].psduType = PSDU_ALL0;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].numOfMPDU  = 1;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;

				ofdmUserSettings[1].numOfSST = 1;
				ofdmUserSettings[1].mcs = 2;
				ofdmUserSettings[1].coding = CODING_BCC;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				ofdmUserSettings[1].psduType = PSDU_ALL0;
				ofdmUserSettings[1].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[1].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[1].stationID = 1;
				ofdmUserSettings[1].mped = 0;
				ofdmUserSettings[1].numOfMPDU  = 1;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;

				// configure MAC header
				ofdmUserSettings[0].htControlEnable = ENAB_ON;
				ofdmUserSettings[1].htControlEnable = ENAB_ON;

				// configure HT Control UMRS
				ofdmUserSettings[0].umrsNumOfSymbol = 2;
				ofdmUserSettings[0].umrsRuin = 10;
				ofdmUserSettings[0].umrsPow = -10;
				ofdmUserSettings[0].umrsRssi = -70;
				ofdmUserSettings[0].umrsMcs = 1;
				
				ofdmUserSettings[1].umrsNumOfSymbol = 4;
				ofdmUserSettings[1].umrsRuin = 20;
				ofdmUserSettings[1].umrsPow = -20;
				ofdmUserSettings[1].umrsRssi = -60;
				ofdmUserSettings[1].umrsMcs = 2;
			}
			else if(11 == signal_id)
			{
				ofdmUserSettings[0].numOfSST = 1;
				ofdmUserSettings[0].mcs = 5;
				ofdmUserSettings[0].coding = CODING_LDPC;
				ofdmUserSettings[0].mpduPsduLength[0] = 400;
				ofdmUserSettings[0].psduType = PSDU_ALL0;
				ofdmUserSettings[0].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[0].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[0].stationID = 0;
				ofdmUserSettings[0].RUIndex = 0;
				ofdmUserSettings[0].mped = 0;
				ofdmUserSettings[0].htControlEnable = ENAB_OFF;
				ofdmUserSettings[0].numOfMPDU = 1;

				ofdmUserSettings[1].numOfSST = 1;
				ofdmUserSettings[1].mcs = 9;
				ofdmUserSettings[1].coding = CODING_BCC;
				ofdmUserSettings[1].mpduPsduLength[0] = 400;
				ofdmUserSettings[1].psduType = PSDU_ALL0;
				ofdmUserSettings[1].psduCRC = TRUE;
				sprintf_s(ofdmUserSettings[1].macAddr[0], "%s", "FFFFFFFFFFFF");
				ofdmUserSettings[1].stationID = 1;
				ofdmUserSettings[1].RUIndex = 2;
				ofdmUserSettings[1].mped = 0;
				ofdmUserSettings[1].htControlEnable = ENAB_OFF;
				ofdmUserSettings[1].numOfMPDU = 1;
			}

			WAVEGEN_OFDM_SETTINGS ofdmSettings;
			ofdmSettings.commonSettings = *ofdmCommonSettings;
			ofdmSettings.perUserSettings = ofdmUserSettings;
			ofdmSettings.perTFRUserSettings = (includeTRFrame)? ftfUserSettings : NULL;
			WIFI_STAN wifiStandard = WIFI_AX;

            // Need ..\\iqvsg folder in local PC.
			CheckReturnCode( LP_WaveGen_OFDM(wifiStandard, packetFormat, &ofdmSettings, includeTRFrame, (char *) tempString.c_str(), TRUE, "..\\iqvsg"), "LP_WaveGen_OFDM()" );			

			//--------------------//
			// Load waveform file //
			//--------------------//

			modFileName  = "../iqvsg/";
			modFileName += tempString;
			modFileName += ".iqvsg";

			CheckReturnCode( LP_SetVsgModulation((char *)modFileName.c_str(),0), "LP_SetVsgModulation()" );

			//---------------//
			//  Turn on VSG  //
			//---------------//
			CheckReturnCode( LP_EnableVsgRF(1), "LP_EnableVsgRF()" );

			//------------------------------------------//
			//   Send packet, continuous transmission   //
			//------------------------------------------//
			int frameCnt = 0; 	// number of frame to send, 0 means continuous transmission.
			CheckReturnCode( LP_SetFrameCnt(frameCnt), "LP_SetFrameCnt()" );


			//----------------//
			//   Setup VSA    //
			//----------------//
			int peakToAverageRatio = 10;

			double rfLev;

			CheckReturnCode( LP_SetVsa(FREQ_HZ_5G, (dutPowerLevel+peakToAverageRatio-cableLoss), PORT_LEFT), "LP_SetVsa()" );
			CheckReturnCode( LP_SetVsa_Trigger(), "LP_SetVsa_Trigger()" );
			CheckReturnCode( LP_Agc(&rfLev), "LP_Agc()" );
			printf("Reference level is %.3f\n", rfLev);


			//----------------------//
			//  Perform VSA capture //
			//----------------------//
			double captureTime =4000e-6;
			CheckReturnCode( LP_VsaDataCapture(captureTime, 13,160e6), "LP_VsaDataCapture()" ); //trigger type was 2, only for instrument driver? in IQapi, it is for external trigger?

			//---------------------------//
			//  Save sig file for debug  //
			//---------------------------//

			//CheckReturnCode( LP_GetSampleData(0,IData,QData,280000*2), "LP_GetSampleData()" );
			//char saveCapturedName1[MAX_BUFFER_SIZE] = "WiFi_11ax.iqvsa";
			//char saveCapturedName2[MAX_BUFFER_SIZE] = "WiFi_11ax.iqvsg";
			//char saveCapturedName3[MAX_BUFFER_SIZE] = "WiFi_11ax.txt";
			//CheckReturnCode( LP_SaveVsaSignalFile(saveCapturedName1), "LP_SaveVsaSignalFile()" );
			//CheckReturnCode( LP_SaveVsaGeneratorFile(saveCapturedName2), "LP_SaveVsaGeneratorFile()" );
			//CheckReturnCode( LP_SaveVsaSignalFileText(saveCapturedName3), "LP_SaveVsaSignalFileText()" );

			//-------------------------//
			//  Perform Power analysis //
			//-------------------------//

			CheckReturnCode( LP_AnalyzePower(3.2e-6, 15.0), "LP_AnalyzePower()" );

			//-------------------------//
			//  Retrieve Test Results  //
			//-------------------------//

			double result;
			result = LP_GetScalarMeasurement("valid"); //result not right yet.
			printf("valid: %.0f\n", result);

			result = LP_GetScalarMeasurement("P_av_each_burst_dBm");
			printf("P_av_each_burst_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_each_burst");
			printf("P_av_each_burst: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_pk_each_burst_dBm");
			printf("P_pk_each_burst_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_pk_each_burst");
			printf("P_pk_each_burst: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_av_all_dBm");
			printf("P_av_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_all");
			printf("P_av_all: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_peak_all_dBm");
			printf("P_peak_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_peak_all");
			printf("P_peak_all: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("P_av_no_gap_all_dBm");
			printf("P_av_no_gap_all_dBm: %.2f dBm\n", result);
			result = LP_GetScalarMeasurement("P_av_no_gap_all");
			printf("P_av_no_gap_all: %.6f mw\n", result);

			result = LP_GetScalarMeasurement("start_sec");
			printf("start_sec: %.6f sec\n", result);
			result = LP_GetScalarMeasurement("stop_sec");
			printf("stop_sec: %.6f sec\n", result);


			//-------------------------//
			//  Perform 11ax analysis //
			//-------------------------//
			Analysis_11AX_Params analysisParams;

			analysisParams.numSegmsToAnalyze = 1;
			analysisParams.numOfPacketToSkip = 0;
			analysisParams.numOfPacketToAnalyze = 1;
			sprintf(analysisParams.mode,"nxn");
			analysisParams.enablePhaseCorr = 1;
			analysisParams.enableSymTimingCorr = 1;
			analysisParams.enableAmplitudeTracking = 0;
			analysisParams.decodePSDU = 1;
			analysisParams.enableFullPacketChannelEst = 0;
			analysisParams.frequencyCorr = 2;
			analysisParams.enablePreambleAveraging = 0;
			analysisParams.packetFormat = PKT_AUTO;
			analysisParams.prePowStartSec = 8.8e-6;
			analysisParams.prePowStopSec = 15.2e-6;
			analysisParams.num_user_triggered = 0;
			analysisParams.A_factor = ofdmCommonSettings->aFactorTFR ;
			
            int mcs_aus[1] = {11};
            int ruin_aus[1]={18};
            int num_SS[1] = {1};
            OFDM_CODING triggered_coding[1] = {CODING_BCC};
            int primary_80MHz[1] = {1};
            int DCM_aus[1] = {0};

			if(signal_id == 3)
			{
				mcs_aus[0] = 11;
				ruin_aus[0] = 18;
				num_SS[0] = 1;
				triggered_coding[0] = CODING_BCC;
				primary_80MHz[0] = 1;
                DCM_aus[0] = 0;
                
				analysisParams.num_user_triggered = 1;
				analysisParams.GILTF = GILTF2;
				analysisParams.A_factor = 4;
				analysisParams.PE_Disambiguity = 1;
				analysisParams.NLTF = 1;
				analysisParams.extra_symbol_LDPC = 0;
				analysisParams.DCM = DCM_aus;
				analysisParams.MCS_alloc_user = mcs_aus;
				analysisParams.RUindex_alloc_user = ruin_aus;
				analysisParams.num_SS_user = num_SS;
				analysisParams.triggered_coding_user = triggered_coding;
				analysisParams.primary_80MHz_user = primary_80MHz;
			}
			else if( 6 == signal_id)
			{
				mcs_aus[0] = 1;
				ruin_aus[0] = 0;
				num_SS[0] = 1;
				triggered_coding[0] = CODING_BCC;
				primary_80MHz[0] = 1;
				DCM_aus[0] = 1;

				analysisParams.GILTF = GILTF1;
				analysisParams.NLTF = 1;
				analysisParams.MCS_alloc_user = mcs_aus;
				analysisParams.RUindex_alloc_user = ruin_aus;
				analysisParams.num_SS_user = num_SS;
				analysisParams.primary_80MHz_user =primary_80MHz ;
				analysisParams.triggered_coding_user = triggered_coding;
                analysisParams.DCM = DCM_aus;
				analysisParams.num_user_triggered = ofdmCommonSettings->numOfUsers;
			}
			else if( 7 == signal_id)
			{
				mcs_aus[0] = 2;
				ruin_aus[0] = 62;
				num_SS[0] = 2;
				triggered_coding[0] = CODING_LDPC;
				primary_80MHz[0] = 1;
                DCM_aus[0] = 0;

				analysisParams.GILTF = GILTF1;
				analysisParams.NLTF = 8;//ofdmCommonSettings->ELTF + 2;
                analysisParams.extra_symbol_LDPC = 1;
                analysisParams.PE_Disambiguity = 0;
				analysisParams.MCS_alloc_user = mcs_aus;
				analysisParams.RUindex_alloc_user = ruin_aus;
				analysisParams.num_SS_user = num_SS;
				analysisParams.triggered_coding_user = triggered_coding;
				analysisParams.primary_80MHz_user = primary_80MHz;
                analysisParams.DCM = DCM_aus;
				analysisParams.num_user_triggered = ofdmCommonSettings->numOfUsers;
			}
			else if( 8 == signal_id)
			{
				mcs_aus[0] = 5;
				ruin_aus[0] = 53;
				num_SS[0] = 2;
				triggered_coding[0] = CODING_LDPC;
				primary_80MHz[0] = 1;
                DCM_aus[0] = 0;

				analysisParams.GILTF = GILTF2;
				analysisParams.NLTF = 6;
				analysisParams.MCS_alloc_user = mcs_aus;
				analysisParams.RUindex_alloc_user = ruin_aus;
				analysisParams.num_SS_user = num_SS;
				analysisParams.triggered_coding_user = triggered_coding;
				analysisParams.primary_80MHz_user = primary_80MHz ;
				analysisParams.DCM = DCM_aus;
                analysisParams.num_user_triggered = 1;// currently max is one ofdmCommonSettings->numOfUsers;
				analysisParams.PE_Disambiguity = 1;
				analysisParams.extra_symbol_LDPC = 1;
			}
			else if( 11 == signal_id)
			{
                mcs_aus[0] = 5;
				ruin_aus[0] = 0;
				num_SS[0] = 1;
				triggered_coding[0] = CODING_LDPC;
				primary_80MHz[0] = 1;
                DCM_aus[0] = 0;

				analysisParams.GILTF = GILTF2;
				analysisParams.NLTF = 1;
				analysisParams.MCS_alloc_user = mcs_aus;
				analysisParams.RUindex_alloc_user = ruin_aus;
				analysisParams.num_SS_user = num_SS;
				analysisParams.triggered_coding_user = triggered_coding;
				analysisParams.primary_80MHz_user = primary_80MHz ;
				analysisParams.DCM = DCM_aus;
                analysisParams.num_user_triggered = 1;// currently max is one ofdmCommonSettings->numOfUsers;
				analysisParams.PE_Disambiguity = 1;
				analysisParams.extra_symbol_LDPC = 1;
			}
			CheckReturnCode( LP_Analyze80211ax(&analysisParams), "LP_Analyze80211ax()" );

			//-------------------------//
			//  Retrieve Test Results  //
			//-------------------------//

			RESULT_INDEX  target_idx;
			config_get_result_idx(&target_idx, 1,1,-1,-1,-1);

			double num_users = 0;
			double MU_state = 0;
			double wifi_pkt_format = 0;
			double coding_rate_result, num_spatialStreams, num_spatialStreams_user;//, evm_per_user;

			num_users = LP_GetScalarResult("multi_user_num", target_idx);
			MU_state = LP_GetScalarResult("MU_state", target_idx);
			wifi_pkt_format = LP_GetScalarResult("wifi_packet_format", target_idx);
			if(wifi_pkt_format == HE_SU)
			{
				printf("This is a Single-user waveform \n");
			}
			else if(wifi_pkt_format == HE_ERAN_SU)
			{
				printf("This is a extended range waveform \n");
			}
			else if(wifi_pkt_format == HE_MU)
			{
				printf("This is a Multi-user waveform \n");
			}
			else if(wifi_pkt_format == HE_TR)
			{
				printf("This is a HE-TRIGGER waveform \n");
			}
            else
            {
                printf("This is a unknown type waveform \n");
            }

            for(int idx=1; idx<=num_users ;idx++)
			{
				config_get_result_idx(&target_idx, 1,1,idx,1,1);

				result = LP_GetScalarResult("psduCRC",target_idx);
				if (result == 1)
				{
					printf("PSDU USER%d CRC: %s \n",idx ,"PASS");
				}
				else
				{
					printf("PSDU USER%d CRC: %s \n", idx , "FAIL");
				}

				result = LP_GetScalarResult("rateInfo_dataRateMbps",target_idx);
				printf("Datarate_User%d: %0.2f Mbps\n", idx , result);

				result = LP_GetScalarResult("vhtSigA2McsIndex",target_idx);
				printf("VHTSigA2McsIndex_User%d=%1.0f\n", idx, result);

				if(MU_state == 1)
				{
					result = LP_GetScalarResult("VHTSigBFieldCRC",target_idx);
					printf("vhtSigBFieldCRC_User%d=%1.0f\n", idx, result);
					result = LP_GetScalarResult("ru_index",target_idx);
					printf("ru_index: %.0f \n\n", result);
					result = LP_GetScalarResult("ru_size",target_idx);
					printf("ru_size: %.0f \n\n", result);
				}

				coding_rate_result = LP_GetScalarResult("codingRate",target_idx);
				printf("codingRate_User%d=%1.0f,  [0=1/2, 1=2/3, 2=3/4, 3=5/6, 4=1/4] \n", idx, coding_rate_result);

				result = LP_GetScalarResult("numPsduBytes",target_idx);
				printf("numPsduBytes_User%d: %.2f \n", idx, result);

				result = LP_GetScalarResult("vhtSigA2AdvancedCoding",target_idx);
				printf("VHTSigA2AdvancedCoding_User%d=%1.0f , [0=BCC, 1=LDPC] \n\n", idx,result);
			}

			config_get_result_idx(&target_idx, 1,1,1,1,1);

			result = LP_GetScalarResult("freqErrorHz",target_idx);
			printf("Frequency Error: %.2f Hz\n", result);
			result = LP_GetScalarResult("symClockErrorPpm",target_idx);
			printf("Symbol Clock Error: %.2f ppm\n", result);
			result = LP_GetScalarResult("PhaseNoiseDeg_RmsAll",target_idx);
			printf("RMS Phase Noise: %.2f deg\n", result);
			result = LP_GetScalarResult("IQImbal_amplDb",target_idx);
			printf("IQ Imbalance Amp: %.2f dB \n", result);
			result = LP_GetScalarResult("IQImbal_phaseDeg",target_idx);
			printf("IQ Imbalance phase: %0.2f deg \n", result);
			result = LP_GetScalarResult("dcLeakageDbc",target_idx);
			printf("LO leakage: %.2f dBc\n\n", result);
			double bandwidthMhz = LP_GetScalarResult("rateInfo_bandwidthMhz",target_idx);
			printf("Signal Bandwidth: %0.2f MHz\n", bandwidthMhz);
			result = LP_GetScalarResult("rateInfo_spatialStreams",target_idx);
			printf("Number of Spatial Streams: %1.0f \n", result);
			num_spatialStreams = result;

			result = LP_GetScalarResult("rateInfo_spaceTimeStreams",target_idx);
			printf("Number of SpaceTime Streams: %1.0f \n", result);

			result = LP_GetScalarResult("packet_extension_duration",target_idx);
			printf("PED: %.6f S\n\n", result);
			result = LP_GetScalarResult("afactor",target_idx);
			printf("AFactor: %.0f \n\n", result);

			int numberOfTones = 0;
			numberOfTones = (int) LP_GetScalarResult("numberOfTones",target_idx);
			printf("numberOfTones: %d \n\n", numberOfTones);

			double num_signal = LP_GetScalarResult("num_of_signal",target_idx);

			for(int idx = 1;idx <= num_signal; idx++)
			{
				config_get_result_idx(&target_idx, 1,1,1,1,idx);

				result = LP_GetScalarResult("IQImbal_amplDb",target_idx);
				printf("IQImbal_amplDb: %.3f dBm\n", result);

				result = LP_GetScalarResult("IQImbal_phaseDeg",target_idx);
				printf("IQImbal_phaseDeg: %.3f DEG\n", result);

				result = LP_GetScalarResult("dcLeakageDbc",target_idx);
				printf("dcLeakageDbc: %.3f dB\n", result);
			}

			for(int idx = 1; idx <= num_users; idx++)
			{
				config_get_result_idx(&target_idx, 1, 1, idx, 1, 1);
				num_spatialStreams_user = LP_GetScalarResult("rateInfo_spatialStreams_User",target_idx);
				printf("Number of Spatial Streams: %1.0f for user%d\n", num_spatialStreams_user, idx);

				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					target_idx.stream_index = num_stream;
					result = LP_GetScalarResult("evmAvgAll",target_idx);
					printf("EVM Avg All_USER%d_Stream%d: %.3f dB\n\n", idx, num_stream, result);
				}
			}

			/////////////////// Test vector results///////////////////////////
			int length = 1000; // preset length of data

			for(int idx = 1; idx <= num_users ;idx++)
			{
				//double  buffer[MAX_BUFFER_SIZE*10]; //, bufferImag[MAX_BUFFER_SIZE];
				target_idx.user_index = idx;
				config_get_result_idx(&target_idx, 1,1,idx,1,1);
				length = LP_GetVectorResult("user_constellation_real", target_idx, IData, 280000*2);
				length = LP_GetVectorResult("psdu",target_idx, IData, 280000*2);
			}

			config_get_result_idx(&target_idx, 1,1,1,1,1);
			length = LP_GetVectorResult("spectralFlatness",target_idx, bufferReal, MAX_BUFFER_SIZE);
			length = LP_GetVectorResult("spectralFlatnessHighLimit", target_idx, bufferReal, MAX_BUFFER_SIZE);
			length = LP_GetVectorResult("spectralFlatnessLowLimit", target_idx, bufferReal, MAX_BUFFER_SIZE);
			length = LP_GetVectorResult("offsetTones", target_idx, bufferReal, MAX_BUFFER_SIZE);
			if(length != numberOfTones)
			{
				printf("number of result %d offsetTones is not same as numberOfTones %d \n\n", length, numberOfTones);
			}

			length = LP_GetVectorResult("siga_bits", target_idx, bufferReal, MAX_BUFFER_SIZE);

			if ((int) wifi_pkt_format==HE_MU)
			{
				length = LP_GetVectorResult("sigb_bits", target_idx, bufferReal, MAX_BUFFER_SIZE);

				for(int idx = 1;idx <= num_signal; idx++)
				{
					for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
					{
						int resultLen = 0;
						config_get_result_idx(&target_idx, 1,1,1,num_stream,idx);
						resultLen = LP_GetVectorResult("ru_power",target_idx, bufferReal, MAX_BUFFER_SIZE);
						printf("ru_power_SIGNal%d_STReam%d: ", idx, num_stream);
						for(int i=0; i<resultLen; i++)
						{
                            if (bufferReal[i] <= 40)
							    printf("%.3f ", bufferReal[i]);
                            else
                                printf("NA "); // No allocated RU.
						}
						printf("\n\n");
					}
				}
			}
			else if((int) wifi_pkt_format==HE_TR)
			{
				length = LP_GetVectorResult("evm_high_limit_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
				length = LP_GetVectorResult("avg_evm_all_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
				length = LP_GetVectorResult("worst_case_margin", target_idx, bufferReal, MAX_BUFFER_SIZE);
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,1);
					length = LP_GetVectorResult("evm_all_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
				}
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,1);
					length = LP_GetVectorResult("worst_case_margin", target_idx, bufferReal, MAX_BUFFER_SIZE);
				}			
			}

			for(int idx = 1;idx <= num_signal; idx++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx);
					result = LP_GetScalarResult("rxRmsPowerDb",target_idx);
					printf("SIGNAL%d_STREAM%d_rxRmsPowerDb: %.2f dBm\n", idx, num_stream,result);
				}
			}

			for(int idx = 1;idx <= num_signal; idx++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx);
					result = LP_GetScalarResult("rmsPowerNoGap",target_idx);
					printf("SIGNAL%d_STREAM%d_rmsPowerNoGap: %.2f dBm\n", idx, num_stream,result);
				}
			}

			for(int idx = 1;idx <= num_signal; idx++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx);
					result = LP_GetScalarResult("max_power",target_idx);
					printf("SIGNAL%d_STREAM%d_max_power: %.2f dBm\n", idx, num_stream,result);
				}
			}

			for(int idx = 1;idx <= num_signal; idx++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx);
					result = LP_GetScalarResult("min_power",target_idx);
					printf("SIGNAL%d_STREAM%d_min_power: %.2f dBm\n", idx, num_stream,result);
				}
			}

// start of TX_PER_TEST

			//----------------------//
			//  Perform VSA capture //
			//----------------------//
			captureTime =1000e-6 * 50;
			CheckReturnCode( LP_VsaDataCapture(captureTime, 13,160e6), "LP_VsaDataCapture()" ); //trigger type was 2, only for instrument driver? in IQapi, it is for external trigger?

			//-------------------------//
			//  Perform Power analysis //
			//-------------------------//
			CheckReturnCode( LP_AnalyzePower(3.2e-6, 15.0), "LP_AnalyzePower()" );

			//-------------------------//
			//  Perform 11ax analysis  //
			//-------------------------//
			analysisParams.numOfPacketToAnalyze = 2;
			CheckReturnCode( LP_SelectCaptureRangeForAnalysis(0, captureTime, 0, analysisParams.numOfPacketToAnalyze), "LP_SelectCaptureRangeForAnalysis()" );		
			CheckReturnCode( LP_Analyze80211ax(&analysisParams), "LP_Analyze80211ax()" );

			//-------------------------//
			//  Retrieve Test Results  //
			//-------------------------//
			config_get_result_idx(&target_idx, 1,1,-1,-1,-1);

			num_users = LP_GetScalarResult("multi_user_num", target_idx);
			num_signal = LP_GetScalarResult("num_of_signal",target_idx);
			// fetch packet results
			for(int idx=1; idx<=num_users ;idx++) 
			{
				for(int idx_perPacket = 0; idx_perPacket < analysisParams.numOfPacketToAnalyze; idx_perPacket++)
				{
					config_get_result_idx(&target_idx, 1,idx_perPacket+1,idx,1,1);
					result = LP_GetScalarResult("psduCRC", target_idx);
					if (result)
					{
						printf("PSDU USER%d PACKET%d CRC: %s \n",idx ,idx_perPacket, "PASS");
					}
					else
					{
						printf("PSDU USER%d PACKET%d CRC: %s \n", idx ,idx_perPacket, "FAIL");
					}

					if(MU_state == 1)
					{
						result = LP_GetScalarResult("VHTSigBFieldCRC", target_idx);
						printf("vhtSigBFieldCRC_User%d_Packet%d=%1.0f\n", idx, idx_perPacket, result);
						result = LP_GetScalarResult("ru_index",target_idx);
						printf("ru_index_User%d_Packet%d=%1.0f\n", idx, idx_perPacket, result);
						result = LP_GetScalarResult("ru_size",target_idx);
						printf("ru_size_User%d_Packet%d=%1.0f\n", idx, idx_perPacket, result);
					}

					coding_rate_result = LP_GetScalarResult("codingRate",target_idx);
					printf("codingRate_User%d_PACKET%d=%1.0f,  [0=1/2, 1=2/3, 2=3/4, 3=5/6, 4=1/4] \n", idx, idx_perPacket, coding_rate_result);

					result = LP_GetScalarResult("vhtSigA2AdvancedCoding",target_idx);
					printf("VHTSigA2AdvancedCoding_User%d_PACKET%d=%1.0f , [0=BCC, 1=LDPC] \n\n", idx,idx_perPacket, result);

					result = LP_GetScalarResult("vhtSigA2McsIndex",target_idx);
					printf("VHTSigA2McsIndex_User%d_PACKET%d=%1.0f\n", idx, idx_perPacket, result);

					result = LP_GetScalarResult("numPsduBytes",target_idx);
					printf("numPsduBytes_User%d_PACKET%d: %.2f \n", idx, idx_perPacket, result);

					length = LP_GetVectorResult("user_constellation_real", target_idx, IData, 280000 * 2);
					length = LP_GetVectorResult("psdu",target_idx, IData, 280000 * 2);

					config_get_result_idx(&target_idx, 1,idx_perPacket+1,idx,1,1);
					if((MU_state == 1) || ((0 == MU_state) && (0 == idx_perPacket)))
					{
						num_spatialStreams_user = LP_GetScalarResult("rateInfo_spatialStreams_User",target_idx);
						printf("Number of Spatial Streams: %1.0f for user%d\n", num_spatialStreams_user, idx);
						for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
						{
							config_get_result_idx(&target_idx, 1,idx_perPacket+1,idx,num_stream,1);
							result = LP_GetScalarResult("evmAvgAll",target_idx);
							printf("EVM Avg All_USER%d_Stream%d: %.3f dB\n\n", idx, num_stream, result);
						}
					}
				}
			}

			for(int idx_perPacket = 1; idx_perPacket < analysisParams.numOfPacketToAnalyze+1; idx_perPacket++)
			{
				config_get_result_idx(&target_idx, 1,idx_perPacket,1,1,1);

				result = LP_GetScalarResult("numberOfTones",target_idx);
				printf("PACKET%d numberOfTones: %d \n\n", idx_perPacket, (int) result);

				length = LP_GetVectorResult("offsetTones", target_idx, bufferReal, MAX_BUFFER_SIZE);
				if(length != result)
				{
					printf("PACKET%d number of result %d offsetTones is not same as numberOfTones %d \n\n", idx_perPacket, length, result);
				}

				length = LP_GetVectorResult("siga_bits", target_idx, bufferReal, MAX_BUFFER_SIZE);

				if ((int) wifi_pkt_format==HE_MU)
				{
					length = LP_GetVectorResult("sigb_bits", target_idx, bufferReal, MAX_BUFFER_SIZE);

					for(int idx = 1;idx <= num_signal; idx++)
					{
						for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
						{
							int resultLen = 0;
							config_get_result_idx(&target_idx, 1,idx_perPacket,1,num_stream,idx);
							resultLen = LP_GetVectorResult("ru_power",target_idx, bufferReal, MAX_BUFFER_SIZE);
							printf("PACKET%d_ru_power_SIGNal%d_STReam%d: ", idx_perPacket, idx, num_stream);
							for(int i=0; i<resultLen; i++)
							{
								if (bufferReal[i] <= 40)
							        printf("%.3f ", bufferReal[i]);
                                else
                                    printf("NA "); // No allocated RU.
							}
							printf("\n\n");
						}
					}
				}
				else if((int) wifi_pkt_format==HE_TR)
				{
					length = LP_GetVectorResult("evm_high_limit_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
					for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
					{
						config_get_result_idx(&target_idx, 1,idx_perPacket,1,num_stream,1);
						length = LP_GetVectorResult("evm_all_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
					}
				}

				for(int idx_signal = 1;idx_signal <= num_signal; idx_signal++)
				{
					config_get_result_idx(&target_idx, 1,idx_perPacket,1,1,idx_signal);
					result = LP_GetScalarResult("IQImbal_amplDb",target_idx);
					printf("PACKET%d_SIGNAL%d IQImbal_amplDb: %.3f dBm\n", idx_perPacket, idx_signal, result);

					result = LP_GetScalarResult("IQImbal_phaseDeg",target_idx);
					printf("PACKET%d_SIGNAL%d IQImbal_phaseDeg: %.3f DEG\n", idx_perPacket, idx_signal, result);

					result = LP_GetScalarResult("dcLeakageDbc",target_idx);
					printf("PACKET%d_SIGNAL%d dcLeakageDbc: %.3f dB\n", idx_perPacket, idx_signal, result);
				}
			}

			for(int idx_perPacket = 1; idx_perPacket < analysisParams.numOfPacketToAnalyze+1; idx_perPacket++)
			{
				for(int idx = 1;idx <= num_signal; idx++)
				{
					for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
					{
						config_get_result_idx(&target_idx, 1,idx_perPacket,1,num_stream,idx);
						result = LP_GetScalarResult("rxRmsPowerDb",target_idx);
						printf("PACKET%d_SIGNAL%d_STREAM%d_rxRmsPowerDb: %.2f dBm\n", idx_perPacket, idx, num_stream,result);
					}
				}
			}

			for(int idx_signal = 1;idx_signal <= num_signal; idx_signal++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx_signal);
					result = LP_GetScalarResult("rmsPowerNoGap",target_idx);
					printf("SIGNAL%d_STREAM%d_rmsPowerNoGap: %.2f dBm\n", idx_signal, num_stream,result);
				}
			}

			for(int idx_signal = 1;idx_signal <= num_signal; idx_signal++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx_signal);
					result = LP_GetScalarResult("max_power",target_idx);
					printf("SIGNAL%d_STREAM%d_max_power: %.2f dBm\n", idx_signal, num_stream,result);
				}
			}

			for(int idx_signal = 1;idx_signal <= num_signal; idx_signal++)
			{
				for(int num_stream = 1; num_stream <= num_spatialStreams; num_stream++)
				{
					config_get_result_idx(&target_idx, 1,1,1,num_stream,idx_signal);
					result = LP_GetScalarResult("min_power",target_idx);
					printf("SIGNAL%d_STREAM%d_min_power: %.2f dBm\n", idx_signal, num_stream,result);
				}
			}

			config_get_result_idx(&target_idx, 1,1,1,1,1);
			length = LP_GetVectorResult("avg_evm_all_26tone_RU", target_idx, bufferReal, MAX_BUFFER_SIZE);
			config_get_result_idx(&target_idx, 1,1,1,1,1);
			length = LP_GetVectorResult("worst_case_margin", target_idx, bufferReal, MAX_BUFFER_SIZE);
			// reset num of numOfPacketToAnalyze for other test
			analysisParams.numOfPacketToAnalyze = 1;
			CheckReturnCode( LP_SelectCaptureRangeForAnalysis(0, captureTime, 0, analysisParams.numOfPacketToAnalyze), "LP_SelectCaptureRangeForAnalysis()" );	
// end of TX_PER_TEST
			//----------------//
			//  Turn off VSG  //
			//----------------//
			CheckReturnCode( LP_EnableVsgRF(0), "LP_EnableVsgRF()" );
			printf("\n");
		}

	}
	catch(char *msg)
	{
		printf(">>>>>>>>ERROR: %s\n", msg);
		status = IQMT_ERR_FUNCTION_FAIL;
	}
	catch(...)
	{
		printf(">>>>>>>>ERROR!");
		status = IQMT_ERR_FUNCTION_FAIL;
	}

    delete [] bufferReal;
	delete [] IData;
	delete [] QData;
    delete ofdmCommonSettings;
    delete [] ofdmUserSettings;
    delete [] ftfUserSettings;
	CheckReturnCode( LP_Term(), "LP_Term()" );
	ReadLogFiles();
	PrintErrorStatus( status, "ac" );
}

void WiFi_11ax_TriggerBasedTesting()
{
	
	try
	{
		// The following code show how to setup a trigger based timing test for SISO

		char meas_type[MAX_BUFFER_SIZE] = {"Timing"};
		//char meas_type[MAX_BUFFER_SIZE] = {"CFO"}; // CFO test
		//char meas_type[MAX_BUFFER_SIZE] = {"Power Control"}; // Power control test
		int selected_modules[2] = {1,2}; // Specify list of modules VSA/VSG1, VSA/VSG2
		SeqBuildParams input_params_1;
		double buffer[MAX_BUFFER_SIZE];
		char temp_buffer[MAX_BUFFER_SIZE];
		RESULT_INDEX resultIndex;

		// Set input params
		input_params_1.rfPort[0] = 4; // Set RF port
		input_params_1.rfPort[1] = 4; 
		input_params_1.rfPort[2] = 4; 
		input_params_1.rfPort[3] = 4; 
		input_params_1.rfFreqHz = 5210e6; // Set frequence
		input_params_1.RXtargetPowerLeveldBm[0] = -51; // Target power level for trigger frame
		input_params_1.TXtargetPowerLeveldBm[0] = 24; // Target power level for UL PPDU
		input_params_1.numOfPowerLevels = 1; // Size of RX/TX tables
		input_params_1.TXpacketPARdB = 10; // Peak-to-average ratio
		input_params_1.triggerleveldB = -25; // Trigger level relative to reference level
		input_params_1.packetCount = 10; // Transmit 10 trigger frame from VSG
		input_params_1.captureLengthUs = 54; // Capture time
		input_params_1.preTriggerTimeUs = 10; // Pre-trigger time
		input_params_1.skipPktCnt = 7; // Number of packets to skip from DUT
		input_params_1.captureCnt = 3; // Number of packets to capture from DUT
		input_params_1.dataRateType = 23; // MCS9. Used to distinguish OFDM vs DSSS
		input_params_1.bandwidthType = 2; // Used to determine wide bandwidth
		input_params_1.diversityCDD = 0; // 0: non-CDD mode (SISO, MIMO, or SISO in MIMO) analysis. 1: CCD mode analysis
		sprintf_s(input_params_1.waveformFileName, MAX_BUFFER_LEN, "%s", "C:\\SVN\\IQfact+_Unified_11AX\\Bin_win\\iqvsg\\MP_WiFi_11AC_VHT80_S1_MCS9.iqvsg");
		for (int i=0; i<MAX_NUM_PORTS; i++)
		{
			input_params_1.cableLoss[i] = 7;
		}

		// Set analysis parameters
		input_params_1.standard = WIFI_AX;
		input_params_1.numSegmsToAnalyze = 1;
		input_params_1.numOfPacketToSkip = 0;
		input_params_1.numOfPacketToAnalyze = 0;
		input_params_1.enablePhaseCorr = 0;
		input_params_1.enableSymTimingCorr = 0;
		input_params_1.enableAmplitudeTracking = 1;
		input_params_1.decodePSDU = 0;
		input_params_1.enableFullPacketChannelEst = 1;
		input_params_1.frequencyCorr = IQV_MIMO_FREQ_SYNC_LONG;
		input_params_1.enablePreambleAveraging = 0;
		input_params_1.packetFormat = HE_SU;
		input_params_1.prePowStartSec = 0;
		input_params_1.prePowStopSec = 0;
		sprintf_s(input_params_1.mode, MAX_RESPONSE, "nxn");

		// Begin sequence building
		CheckReturnCode( LP_Init(IQTYPE_XEL, 1), "LP_Init()" ); // Init IQmeasure
		CheckReturnCode( LP_InitTesterN("192.168.13.117"), "LP_InitTester()" ); // Init tester
		CheckReturnCode( LP_SetTesterMode(UP_TO_80MHZ_SIGNAL, selected_modules, 1), "LP_SetTesterMode()" ); // Set tester mode
		CheckReturnCode(LP_Meas_InitSeqBuilder(meas_type), "LP_Meas_InitSeqBuilder()"); // Init sequence builder
		CheckReturnCode(LP_Meas_SetSeqinputParams(&input_params_1), "LP_Meas_SetSeqinputParams()"); // Set input params. Call multiple times for multiple sequence steps
		CheckReturnCode(LP_Meas_BuildAndExecute(), "LP_Meas_BuildAndExecute()"); // Build sequence
		CheckReturnCode(LP_Meas_CheckSeqStatus(), "LP_Meas_CheckSeqStatus()"); // Check sequence for errors aver_freqErr

		// Fetch Results
		resultIndex.segment_index = 1;
		resultIndex.packet_index = 1;
		resultIndex.user_index = 1;
		resultIndex.stream_index = 1;
		resultIndex.chain_index = 1;
		LP_GetVectorResult("ack_timing_max_min", resultIndex, buffer, MAX_BUFFER_SIZE);
		sprintf_s(temp_buffer, MAX_BUFFER_SIZE, "Maximum Time: %.2f us\n", buffer[0]);
		printf(temp_buffer);
		sprintf_s(temp_buffer, MAX_BUFFER_SIZE, "Minimum Time: %.2f us\n", buffer[1]);
		printf(temp_buffer);

	}
	catch(char *msg)
	{
		printf("ERROR: %s\n", msg);
	}
	catch(...)
	{
		printf("ERROR: Unknown Error!\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	bool forceExitAfterRun = false;

	// Get number of runs to do between query prompts.  Read from the .ini file.  Default value is 1.
	char	_s_buffer[128] = { '\0' };
	size_t _num_runs = 1;
	GetPrivateProfileStringA( "TESTER_SETUP", "NUM_RUNS", NULL, _s_buffer, sizeof(_s_buffer), ".\\QA_Setup.ini" );
	if ( strlen(  _s_buffer ) > 0 )
	{
		std::stringstream _ss( _s_buffer );
		_ss >> _num_runs;
	}

	size_t loop_1_count = 0;

	while (FALSE == bExitFlag)
	{

		size_t loop_2_count = 0;

		for ( unsigned int _ix = 0; _ix < _num_runs; ++_ix )		// Loop number of runs.
		{

			_mkdir( ".\\Log" );
			DeleteFile(_T(".\\Log\\Log_all.txt"));

			Sleep(1000);

			// check for -exit option after function argument; if there then exit immediately after run with no query
			forceExitAfterRun = false;
			if (argc > 2 )
			{
				if ( 0 == wcscmp( argv[2], _T( "-exit" ) ) )
				{
					forceExitAfterRun = true;
				}
			}

			if( argc>1 )
			{
                if( 0==wcscmp(argv[1],_T("-wifi-ag")) )
				{
					WiFi_11ag_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-wifi-b")) )
				{
					WiFi_11b_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-wifi-ah")) )
				{
					WiFi_11ah_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-bt")) )
				{
					Bluetooth_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-dect")) )
				{
					DECT_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-fft")) )
				{
					Fft_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-all")) )
				{
					printf("\n-------------------------\nStarting WiFi...\n\n");
					WiFi_11ag_Loopback();
					WiFi_11b_Loopback();
					WiFi_11ac_Loopback();

					printf("\n-------------------------\nStarting Bluetooth...\n\n");
					Bluetooth_Loopback();

					printf("\n-------------------------\nStarting FFT...\n\n");
					Fft_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-wifi-ac")) )
				{
					WiFi_11ac_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-wifi-ac80plus80")) )
				{
					WiFi_11ac_80plus80_Loopback();
				}
				else if( 0==wcscmp(argv[1],_T("-cw")) )
				{
					CW_Test();
				}
				else if (0==wcscmp(argv[1],_T("-zigbee")) )
				{
					Zigbee_Loopback();
				}
				else if (0==wcscmp(argv[1],_T("-wisun")) )
				{
					WiSUN_Loopback();
				}
				else if (0==wcscmp(argv[1],_T("-zwave")) )
				{
					zWave_Loopback();
				}
				else if (0==wcscmp(argv[1],_T("-fm")) )
				{
					FM_Test();
				}
				else if ( 0==wcscmp(argv[1],_T("-NFC_FreqSweep")) )
				{
					NFC_FreqSweep_Test();
				}
				else if ( 0==wcscmp(argv[1],_T("-NFC_Target")) )
				{
					NFC_TargetWaveformAnalysis_Test();
				}
				else if ( 0==wcscmp(argv[1],_T("-NFC_Initiator")) )
				{
					NFC_InitiatorWaveformAnalysis_Test();
				}
				else if( 0 == wcscmp(argv[1], _T("-GPS_CW")) )
				{
					GPS_ContinueWave();
				}
				else if( 0 == wcscmp(argv[1], _T("-GPS_Mod")) )
				{
					GPS_ModulatedMode();
				}
				else if( 0 == wcscmp(argv[1], _T("-GPS_SCENARIO")) )
				{
					GPS_ScenarioMode();
				}
				else if( 0 == wcscmp(argv[1], _T("-COMPASS_CW")) )
				{
					COMPASS_ContinueWave();
				}
				else if( 0 == wcscmp(argv[1], _T("-COMPASS_Mod")) )
				{
					COMPASS_ModulatedMode();
				}
				else if( 0 == wcscmp(argv[1], _T("-GLONASS")) ){
					Glonass_Test();
				}
				else if( 0 == wcscmp(argv[1], _T("-wifi-ax")) ){
					WiFi_11ax_Loopback();
				}
				else if( 0 == wcscmp(argv[1], _T("-wifi-ax_trigger")) ){
					WiFi_11ax_TriggerBasedTesting();
				}
				else if (0 == wcscmp(argv[1],_T("-multithread")))
				{
					vector<string> IP;
					std::string tmpStr;
					IP.clear();

					std::cout << "\n-multithread is detected, argc = " << argc << std::endl;

					for (int tmpInt = 2; tmpInt < argc; tmpInt++)
					{
						//tmpStr = argv[tmpInt];
						std::wstring test(argv[tmpInt]);
						string test2(test.begin(), test.end());
						IP.push_back(test2);
					}

					QA_Multithread(&IP);// for debug 
				}			
				else
				{
					//do nothing
				}  //end
				//QA end

			}

			Tag_runTime +=1;
			//End

			set_color(CM_YELLOW);

			++loop_2_count;

		}// Loop number of runs.

		if ( forceExitAfterRun )
		{
			bExitFlag = TRUE;
		}
		else
		{
			++loop_1_count;  printf( "Loop_1 count = %d\n", loop_1_count );  

			printf("\nPress any key to continue (x or Esc to exit)....\n");
			char ch;
			while (!_kbhit())
				Sleep(100);

			ch = toupper(_getch());
			if (ch=='X' || ch==ASCII_ESC)
			{
				bExitFlag = TRUE;
			}
		}
		if ( bExitFlag == TRUE )
		{
			system("taskkill /f /im LitePointConnectivityServer.exe");
		}
	}

	return 0;
}


