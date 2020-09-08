//#pragma once
//#include "iqapi.h"
//
//int UnpackMeasurement11ac(void *mx_result_in, iqapiResult **result);
//
//class IQ_API iqapiAnalysis11ac : public iqapiAnalysisMimo
//{
//public:
//    iqapiAnalysis11ac(void);
//    virtual ~iqapiAnalysis11ac(void);
//
//};
//
//class IQ_API iqapiAnalysisVHT80WideBand : public iqapiAnalysis
//{
//public:	
//    iqapiAnalysisVHT80WideBand(void);	        //!< Constructor
//    virtual ~iqapiAnalysisVHT80WideBand(void); 	//!< Destructor
//
//    static const double dbResolutionBWLowerLimit;
//    IQV_WINDOW_TYPE_ENUM windowType;
//    double	dbResolutionBW;	    //!< It has to be greater or equal to 1000, Default: 100000
//
//    IQV_VSA_NUM_ENUM  vsaNum;   //!< For MIMO case, tester can capture more than 1 data set. This parameter specifies which data set to be used for doing FFT analysis. Default: IQV_VSA_NUM_1
//
//    int SetDefault();
//};
//
//class IQ_API iqapiResult11ac : public iqapiResultMimo
//{
//public:
//    iqapiResult11ac();
//    ~iqapiResult11ac();
//
//    // For VHTSigA1
//    iqapiMeasurement    *VHTSigA1Bits;
//    iqapiMeasurement    *VHTSigA1Bandwidth;
//    iqapiMeasurement    *VHTSigA1Stbc;
//
//    // For VHTSigA2
//    iqapiMeasurement    *VHTSigA2Bits;
//    iqapiMeasurement    *VHTSigA2ShortGI;
//    iqapiMeasurement    *VHTSigA2AdvancedCoding;
//    iqapiMeasurement    *VHTSigA2McsIndex;
//
//    // For VHTSigB
//    iqapiMeasurement    *VHTSigBBits;
//
//    int                 vhtSigBFieldCRC;        //	Valid.vhtSigBFieldCRC
//
//};
//
//class IQ_API iqapiResultVHT80WideBand : public iqapiResult {
//public:
//    iqapiResultVHT80WideBand();	            //!< Constructor
//    virtual ~iqapiResultVHT80WideBand();	//!< Destructor
//
//    int len_of_ffts;                //!< the length of ffts 
//    iqapiResultFFT ** ffts;
//};
