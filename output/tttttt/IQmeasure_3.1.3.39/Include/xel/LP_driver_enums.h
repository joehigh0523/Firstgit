/*
  Litepoint Instrument Driver
  (C) Litepoint 2011, All rights reserved
*/
#ifndef LP_DRIVER_ENUMS_H
#define LP_DRIVER_ENUMS_H
#ifdef __cplusplus
extern "C" {
#endif

enum LP_Boolean_t {          /* Boolean in  */
    LP_OFF,                  /* OFF,        OFF mode */
    LP_ON,                   /* ON,         ON mode */ 
    MAX_BOOLEAN
};
extern const char*           BooleanToString(LP_Boolean_t val);
extern const char*           BooleanToSCPI(LP_Boolean_t val);
extern LP_Boolean_t          ScpiToBoolean(const char* val);

enum LP_ALC_Source_t {       /* ALC_source in POWer:ALC:SOURce? */
    LP_ALC_SOURCE_INT,       /* INT,        Internal feedback */ 
    MAX_ALC_SOURCE
};
extern const char*           ALC_SourceToString(LP_ALC_Source_t val);
extern const char*           ALC_SourceToSCPI(LP_ALC_Source_t val);
extern LP_ALC_Source_t       ScpiToALC_Source(const char* val);

enum LP_ALC_State_t {        /* ALC_state in POWer:ALC[:STATe], POWer:ALC[:STATe]? */
    LP_ALC_STATE_SING,       /* SING,       One correction cycle and hold */
    LP_ALC_STATE_AUT,        /* AUT,        Continuous periodic correction cycles */
    LP_ALC_STATE_OFF,        /* OFF,        No correction cycles */
    LP_ALC_STATE_TCR,        /* TCR,        Creates an ALC table */
    LP_ALC_STATE_TABL,       /* TABL,       Use existing correction in ALC TABLE */ 
    MAX_ALC_STATE
};
extern const char*           ALC_StateToString(LP_ALC_State_t val);
extern const char*           ALC_StateToSCPI(LP_ALC_State_t val);
extern LP_ALC_State_t        ScpiToALC_State(const char* val);

enum LP_ActivityType_t {     /* ActivityType in CSTatus[:NBLocked]? */
    LP_CAPT,                 /* CAPT,       Waiting for capture */
    LP_CALC,                 /* CALC,       Calculating */
    LP_SEQ,                  /* SEQ,        Executing Sequence */
    LP_APPL,                 /* APPL,       Executing Applet */
    LP_INACTIVE,             /* INACTIVE,   No activity */ 
    MAX_ACTIVITYTYPE
};
extern const char*           ActivityTypeToString(LP_ActivityType_t val);
extern const char*           ActivityTypeToSCPI(LP_ActivityType_t val);
extern LP_ActivityType_t     ScpiToActivityType(const char* val);

enum LP_Aggregation_t {      /* Aggregation in CONFigure:WAVE:OFDM:AGGRegation, CONFigure:WAVE:OFDM:AGGRegation? */
    LP_AGGREGATION_OFF,      /* OFF,        Always OFF */
    LP_AGGREGATION_ON,       /* ON,         Always ON */
    LP_AGGREGATION_AUTO,     /* AUTO,       AUTO setting */ 
    MAX_AGGREGATION
};
extern const char*           AggregationToString(LP_Aggregation_t val);
extern const char*           AggregationToSCPI(LP_Aggregation_t val);
extern LP_Aggregation_t      ScpiToAggregation(const char* val);

enum LP_Applet_Step_Output_Config_t { /* Applet_Step_Output_Config in APPLet:DEBug:STEP:CONFiguration, APPLet:DEBug:STEP:CONFiguration? */
    LP_APPLET_STEP_NONE,     /* NONE,       No output */
    LP_APPLET_STEP_LAST,     /* LAST,       Output the last command executed */
    LP_APPLET_STEP_NEXT,     /* NEXT,       Output the next command to execute */
    LP_APPLET_STEP_ALL,      /* ALL,        Output both the last and next command */ 
    MAX_APPLET_STEP_OUTPUT_CONFIG
};
extern const char*           Applet_Step_Output_ConfigToString(LP_Applet_Step_Output_Config_t val);
extern const char*           Applet_Step_Output_ConfigToSCPI(LP_Applet_Step_Output_Config_t val);
extern LP_Applet_Step_Output_Config_t ScpiToApplet_Step_Output_Config(const char* val);

enum LP_BF_Report_Action_t { /* BF_Report_Action in CONFigure:WAVE:PSDU:BFACtion:ACTion, CONFigure:WAVE:PSDU:BFACtion:ACTion? */
    LP_CSI,                  /* CSI,        CSI */
    LP_UNC,                  /* UNC,        Uncompressed V matrix */
    LP_COMP,                 /* COMP,       Compressed V matrix */ 
    MAX_BF_REPORT_ACTION
};
extern const char*           BF_Report_ActionToString(LP_BF_Report_Action_t val);
extern const char*           BF_Report_ActionToSCPI(LP_BF_Report_Action_t val);
extern LP_BF_Report_Action_t ScpiToBF_Report_Action(const char* val);

enum LP_BT_Data_Rate_t {     /* BT_Data_Rate in CONFigure:DRATe, CONFigure:DRATe? */
    LP_BT_DATA_RATE_AUTO,    /* AUTO,       BT Data Rate Auto Detect */
    LP_BT_DATA_RATE_1MBPS,   /* 1MBPS,      BT Data Rate 1Mbps */
    LP_BT_DATA_RATE_2MBPS,   /* 2MBPS,      BT Data Rate 2Mbps */
    LP_BT_DATA_RATE_3MBPS,   /* 3MBPS,      BT Data Rate 3Mbps */
    LP_BT_DATA_RATE_LEN,     /* LEN,        BT Low Energy */ 
    MAX_BT_DATA_RATE
};
extern const char*           BT_Data_RateToString(LP_BT_Data_Rate_t val);
extern const char*           BT_Data_RateToSCPI(LP_BT_Data_Rate_t val);
extern LP_BT_Data_Rate_t     ScpiToBT_Data_Rate(const char* val);

enum LP_Band_t {             /* Band in CONFigure:BAND, CONFigure:BAND? */
    LP_00001,                /* 00001,      1880 - 1978 MHz, 2010 - 2025 MHz */
    LP_00010,                /* 00010,      1880 - 1925 MHz, 2010 - 2025 MHz */
    LP_00011,                /* 00011,      1880 - 1900 MHz, 1915 - 1940 MHz, 2010 - 2025 MHz */
    LP_00100,                /* 00100,      1880 - 1900 MHz, 1935 - 1960 MHz, 2010 - 2025 MHz */
    LP_00101,                /* 00101,      1880 - 1900 MHZ, 1955 - 1980 MHz, 2010 - 2025 MHz */
    LP_01000,                /* 01000,      902 - 928 MHz (US ISM) */
    LP_01001,                /* 01001,      2400 - 2483.5 MHz (US ISM) */ 
    MAX_BAND
};
extern const char*           BandToString(LP_Band_t val);
extern const char*           BandToSCPI(LP_Band_t val);
extern LP_Band_t             ScpiToBand(const char* val);

enum LP_Baseband_Filter_t {  /* Baseband_Filter in CONFigure:WAVE:OFDM:FILTer, CONFigure:WAVE:OFDM:FILTer? */
    LP_BBAND_FLTR_NONE,      /* NONE,       No Filtering */
    LP_BBAND_FLTR_RRC,       /* RRC,        Root Raised Cosine Filter */ 
    MAX_BASEBAND_FILTER
};
extern const char*           Baseband_FilterToString(LP_Baseband_Filter_t val);
extern const char*           Baseband_FilterToSCPI(LP_Baseband_Filter_t val);
extern LP_Baseband_Filter_t  ScpiToBaseband_Filter(const char* val);

enum LP_CSET_t {             /* CSET in APPLet[:DEFine]:PARameter[:ADD]? */
    LP_CSET,                 /* CSET,       Mark parameter as compound */ 
    MAX_CSET
};
extern const char*           CSETToString(LP_CSET_t val);
extern const char*           CSETToSCPI(LP_CSET_t val);
extern LP_CSET_t             ScpiToCSET(const char* val);

enum LP_CSI_BF_Report_Bits_t { /* CSI_BF_Report_Bits in CONFigure:WAVE:PSDU:BFACtion:CSI:NBITs, CONFigure:WAVE:PSDU:BFACtion:CSI:NBITs? */
    LP_CSI_BF_RB_BITS4,      /* BITS4,      4 Bits */
    LP_CSI_BF_RB_BITS5,      /* BITS5,      5 Bits */
    LP_CSI_BF_RB_BITS6,      /* BITS6,      6 Bits */
    LP_CSI_BF_RB_BITS8,      /* BITS8,      8 Bits */ 
    MAX_CSI_BF_REPORT_BITS
};
extern const char*           CSI_BF_Report_BitsToString(LP_CSI_BF_Report_Bits_t val);
extern const char*           CSI_BF_Report_BitsToSCPI(LP_CSI_BF_Report_Bits_t val);
extern LP_CSI_BF_Report_Bits_t ScpiToCSI_BF_Report_Bits(const char* val);

enum LP_Channel_Estimation_Type_t { /* Channel_Estimation_Type in CONFigure:OFDM:CESTimation, CONFigure:OFDM:CESTimation? */
    LP_CHAN_ESTIMATION_LTF,   /* LTF,       Long Training Field */
    LP_CHAN_ESTIMATION_DATA,   /* DATA,     Data Part */ 
    MAX_CHANNEL_ESTIMATION_TYPE
};
extern const char*           Channel_Estimation_TypeToString(LP_Channel_Estimation_Type_t val);
extern const char*           Channel_Estimation_TypeToSCPI(LP_Channel_Estimation_Type_t val);
extern LP_Channel_Estimation_Type_t ScpiToChannel_Estimation_Type(const char* val);

enum LP_Channel_Type_t {     /* Channel_Type in WAVE:CHANnel:TYPE? */
    LP_TGN,                  /* TGN,        WiFi TGn channel models */ 
    MAX_CHANNEL_TYPE
};
extern const char*           Channel_TypeToString(LP_Channel_Type_t val);
extern const char*           Channel_TypeToSCPI(LP_Channel_Type_t val);
extern LP_Channel_Type_t     ScpiToChannel_Type(const char* val);

enum LP_Channel_t {          /* Channel in CHANnel?, [SYSTem:][COMMunicate:]REMote:CINFormation? */
    LP_CHAN1,                /* CHAN1,      Measurement CHAN1 */
    LP_CHAN2,                /* CHAN2,      Measurement CHAN2 */
    LP_CHAN3,                /* CHAN3,      Measurement CHAN3 */
    LP_CHAN4,                /* CHAN4,      Measurement CHAN4 */
    LP_CHAN5,                /* CHAN5,      Measurement CHAN5 */
    LP_CHAN6,                /* CHAN6,      Measurement CHAN6 */
    LP_CHAN7,                /* CHAN7,      Measurement CHAN7 */
    LP_CHAN8,                /* CHAN8,      Measurement CHAN8 */
    LP_CHAN9,                /* CHAN9,      Measurement CHAN9 */
    LP_CHAN10,               /* CHAN10,     Measurement CHAN10 */
    LP_CHAN11,               /* CHAN11,     Measurement CHAN11 */
    LP_CHAN12,               /* CHAN12,     Measurement CHAN12 */
    LP_CHAN13,               /* CHAN13,     Measurement CHAN13 */
    LP_CHAN14,               /* CHAN14,     Measurement CHAN14 */
    LP_CHAN15,               /* CHAN15,     Measurement CHAN15 */
    LP_CHAN16,               /* CHAN16,     Measurement CHAN16 */
    LP_CHAN17,               /* CHAN17,     Measurement CHAN17 */
    LP_CHAN18,               /* CHAN18,     Measurement CHAN18 */
    LP_CHAN19,               /* CHAN19,     Measurement CHAN19 */
    LP_CHAN20,               /* CHAN20,     Measurement CHAN20 */
    LP_CHAN21,               /* CHAN21,     Measurement CHAN21 */
    LP_CHAN22,               /* CHAN22,     Measurement CHAN22 */
    LP_CHAN23,               /* CHAN23,     Measurement CHAN23 */
    LP_CHAN24,               /* CHAN24,     Measurement CHAN24 */
    LP_CHAN25,               /* CHAN25,     Measurement CHAN25 */
    LP_CHAN26,               /* CHAN26,     Measurement CHAN26 */
    LP_CHAN27,               /* CHAN27,     Measurement CHAN27 */
    LP_CHAN28,               /* CHAN28,     Measurement CHAN28 */
    LP_CHAN29,               /* CHAN29,     Measurement CHAN29 */
    LP_CHAN30,               /* CHAN30,     Measurement CHAN30 */
    LP_CHAN31,               /* CHAN31,     Measurement CHAN31 */
    LP_CHAN32,               /* CHAN32,     Measurement CHAN32 */
    LP_CHAN33,               /* CHAN33,     Measurement CHAN33 */
    LP_CHAN34,               /* CHAN34,     Measurement CHAN34 */
    LP_CHAN35,               /* CHAN35,     Measurement CHAN35 */
    LP_CHAN36,               /* CHAN36,     Measurement CHAN36 */
    LP_CHAN37,               /* CHAN37,     Measurement CHAN37 */
    LP_CHAN38,               /* CHAN38,     Measurement CHAN38 */
    LP_CHAN39,               /* CHAN39,     Measurement CHAN39 */
    LP_CHAN40,               /* CHAN40,     Measurement CHAN40 */ 
    MAX_CHANNEL
};
extern const char*           ChannelToString(LP_Channel_t val);
extern const char*           ChannelToSCPI(LP_Channel_t val);
extern LP_Channel_t          ScpiToChannel(const char* val);

enum LP_Clear_capture_memory_mode_t { /* Clear_capture_memory_mode in SEQuence:CMEMory, SEQuence:CMEMory? */
    LP_MEM_MODE_OFF,         /* OFF,        Disable clear capture memory mode */
    LP_MEM_MODE_ON,          /* ON,         Enable clear capture memory mode */
    LP_MEM_MODE_PASS,        /* PASS,       Enable clear capture memory mode for successful calculations only */ 
    MAX_CLEAR_CAPTURE_MEMORY_MODE
};
extern const char*           Clear_capture_memory_modeToString(LP_Clear_capture_memory_mode_t val);
extern const char*           Clear_capture_memory_modeToSCPI(LP_Clear_capture_memory_mode_t val);
extern LP_Clear_capture_memory_mode_t ScpiToClear_capture_memory_mode(const char* val);

enum LP_Clock_Rate_t {       /* Clock_Rate in CONFigure:TXQuality:CLOCk, CONFigure:TXQuality:CLOCk?, CONFigure:WAVE:CLOCk, CONFigure:WAVE:CLOCk? */
    LP_1,                    /* 1,          Clock Rate 1 */
    LP_1_2,                  /* 1_2,        Clock Rate 1/2 */
    LP_1_4,                  /* 1_4,        Clock Rate 1/4 */
    LP_1_5,                  /* 1_5,        Clock Rate 1/5 */
    LP_1_8,                  /* 1_8,        Clock Rate 1/8 */
    LP_1_10,                 /* 1_10,       Clock Rate 1/10 */ 
    MAX_CLOCK_RATE
};
extern const char*           Clock_RateToString(LP_Clock_Rate_t val);
extern const char*           Clock_RateToSCPI(LP_Clock_Rate_t val);
extern LP_Clock_Rate_t       ScpiToClock_Rate(const char* val);

enum LP_Coding_t {           /* Coding in CONFigure:WAVE:OFDM:CODing, CONFigure:WAVE:OFDM:CODing? */
    LP_BCC,                  /* BCC,        Coding Type BCC */
    LP_LDPC,                 /* LDPC,       Coding Type LDPC */
    LP_NONE,                 /* NONE,       Coding Type NONE */ 
    MAX_CODING
};
extern const char*           CodingToString(LP_Coding_t val);
extern const char*           CodingToSCPI(LP_Coding_t val);
extern LP_Coding_t           ScpiToCoding(const char* val);

enum LP_Command_Type_t {     /* Command_Type in APPLet[:DEFine]:CTYPe, APPLet[:DEFine]:CTYPe? */
    LP_QUER,                 /* QUER,       Query Command */
    LP_SET,                  /* SET,        Set Command */
    LP_ACT,                  /* ACT,        Action Command */
    LP_SPA,                  /* SPA,        Set Command of a Set/Query Pair */
    LP_QPA,                  /* QPA,        Query Command of a Set/Query Pair */
    LP_SQU,                  /* SQU,        Set/Query Command */ 
    MAX_COMMAND_TYPE
};
extern const char*           Command_TypeToString(LP_Command_Type_t val);
extern const char*           Command_TypeToSCPI(LP_Command_Type_t val);
extern LP_Command_Type_t     ScpiToCommand_Type(const char* val);

enum LP_Compressed_BF_Report_Bits_t { /* Compressed_BF_Report_Bits in CONFigure:WAVE:PSDU:BFACtion:COMPressed:NBITs, CONFigure:WAVE:PSDU:BFACtion:COMPressed:NBITs? */
    LP_COMP_BF_RB_BITS1_3,   /* BITS1_3,    1 bit for Psi, 3 bits for Phi */
    LP_COMP_BF_RB_BITS2_4,   /* BITS2_4,    2 bit for Psi, 4 bits for Phi */
    LP_COMP_BF_RB_BITS3_5,   /* BITS3_5,    3 bit for Psi, 5 bits for Phi */
    LP_COMP_BF_RB_BITS4_6,   /* BITS4_6,    4 bit for Psi, 6 bits for Phi */ 
    MAX_COMPRESSED_BF_REPORT_BITS
};
extern const char*           Compressed_BF_Report_BitsToString(LP_Compressed_BF_Report_Bits_t val);
extern const char*           Compressed_BF_Report_BitsToSCPI(LP_Compressed_BF_Report_Bits_t val);
extern LP_Compressed_BF_Report_Bits_t ScpiToCompressed_BF_Report_Bits(const char* val);

enum LP_Coupling_Mode_t {    /* Couplings_mode in MEASure:COUPling[:MODE], MEASure:COUPling[:MODE]? */
    LP_COUPLING_AC,          /* AC,         AC mode */
    LP_COUPLING_DC,          /* DC,         DC mode */ 
    MAX_COUPLING_MODE
};
extern const char*           Coupling_ModeToString(LP_Coupling_Mode_t val);
extern const char*           Coupling_ModeToSCPI(LP_Coupling_Mode_t val);
extern LP_Coupling_Mode_t    ScpiToCoupling_Mode(const char* val);

enum LP_Data_Byte_Order_t {  /* Byte_Order in FORMat:READings:BORDer, FORMat:READings:BORDer? */
    LP_BYTE_ORDER_NORM,      /* NORM,       Output byte order is little-endian format */
    LP_BYTE_ORDER_SWAP,      /* SWAP,       Output byte order is big-endian format */ 
    MAX_DATA_BYTE_ORDER
};
extern const char*           Data_Byte_OrderToString(LP_Data_Byte_Order_t val);
extern const char*           Data_Byte_OrderToSCPI(LP_Data_Byte_Order_t val);
extern LP_Data_Byte_Order_t  ScpiToData_Byte_Order(const char* val);

enum LP_Data_Format_t {      /* Data_Format in FORMat:READings:DATA, FORMat:READings:DATA? */
    LP_ASC,                  /* ASC,        Output data is ASCII format */
    LP_NR3,                  /* NR3,        Output data is ASCII exponential notation format */
    LP_PACK,                 /* PACK,       Output data is binary number array format */ 
    MAX_DATA_FORMAT
};
extern const char*           Data_FormatToString(LP_Data_Format_t val);
extern const char*           Data_FormatToSCPI(LP_Data_Format_t val);
extern LP_Data_Format_t      ScpiToData_Format(const char* val);

enum LP_Documentation_classification_t { /* Documentation_classification in APPLet[:DEFine]:INTernal, APPLet[:DEFine]:INTernal? */
    LP_PDOC,                 /* PDOC,       Public documentation */
    LP_IDOC,                 /* IDOC,       Internal documentation */
    LP_NDOC,                 /* NDOC,       No documentation */ 
    MAX_DOCUMENTATION_CLASSIFICATION
};
extern const char*           Documentation_classificationToString(LP_Documentation_classification_t val);
extern const char*           Documentation_classificationToSCPI(LP_Documentation_classification_t val);
extern LP_Documentation_classification_t ScpiToDocumentation_classification(const char* val);

enum LP_EDR_Roll_Off_t {     /* EDR_Roll_Off in CONFigure:WAVE:EROFf, CONFigure:WAVE:EROFf? */
    LP_30PCT,                /* 30PCT,      Mod Index 0.3 */
    LP_35PCT,                /* 35PCT,      Mod Index 0.35 */
    LP_40PCT,                /* 40PCT,      Mod Index 0.4 */
    LP_45PCT,                /* 45PCT,      Mod Index 0.45 */
    LP_50PCT,                /* 50PCT,      Mod Index 0.5 */ 
    MAX_EDR_ROLL_OFF
};
extern const char*           EDR_Roll_OffToString(LP_EDR_Roll_Off_t val);
extern const char*           EDR_Roll_OffToSCPI(LP_EDR_Roll_Off_t val);
extern LP_EDR_Roll_Off_t     ScpiToEDR_Roll_Off(const char* val);

enum LP_EVM_METHOD_t {       /* EVM_METHOD in CONFigure:DSSS:EVM:METHod, CONFigure:DSSS:EVM:METHod? */
    LP_STANDARD,             /* STANDARD,   EVM Method Standard */
    LP_RMS,                  /* RMS,        EVM Method RMS */
    LP_STANDARD_2007,        /* STANDARD_2007, EVM Method Standard 2007 */ 
    MAX_EVM_METHOD
};
extern const char*           EVM_METHODToString(LP_EVM_METHOD_t val);
extern const char*           EVM_METHODToSCPI(LP_EVM_METHOD_t val);
extern LP_EVM_METHOD_t       ScpiToEVM_METHOD(const char* val);

enum LP_Filter_Length_Selection_Mode_t { /* Filter_Length_Selection_Mode in CONFigure[:POWer][:PHASe]:FLENgth, CONFigure[:POWer][:PHASe]:FLENgth? */
    LP_FILTER_MODE_AUTO,     /* AUTO,       Automatically Chosen */
    LP_FILTER_MODE_USER,     /* USER,       User Defined */ 
    MAX_FILTER_LENGTH_SELECTION_MODE
};
extern const char*           Filter_Length_Selection_ModeToString(LP_Filter_Length_Selection_Mode_t val);
extern const char*           Filter_Length_Selection_ModeToSCPI(LP_Filter_Length_Selection_Mode_t val);
extern LP_Filter_Length_Selection_Mode_t ScpiToFilter_Length_Selection_Mode(const char* val);

enum LP_Frequency_Correction_Type_t { /* Frequency_Correction_Type in CONFigure:OFDM:TRACking:FREQuency, CONFigure:OFDM:TRACking:FREQuency? */
    LP_FREQ_CORR_STF,        /* STF,        Short Training Field */
    LP_FREQ_CORR_LTF,        /* LTF,        Long Training Field */
    LP_FREQ_CORR_SIG,        /* SIG,        Long Training Field and Signaling Fields */
    LP_FREQ_CORR_DATA,       /* DATA,       Whole Packet */ 
    MAX_FREQUENCY_CORRECTION_TYPE
};
extern const char*           Frequency_Correction_TypeToString(LP_Frequency_Correction_Type_t val);
extern const char*           Frequency_Correction_TypeToSCPI(LP_Frequency_Correction_Type_t val);
extern LP_Frequency_Correction_Type_t ScpiToFrequency_Correction_Type(const char* val);

enum LP_GPRF_POWER_t {       /* Filter_Type in CONFigure[:POWer][:PHASe]:FILTer, CONFigure[:POWer][:PHASe]:FILTer? */
    LP_GPRF_NONE,            /* NONE,        */
    LP_GPRF_GAUSS,           /* GAUSS,       */
    LP_GPRF_RRC,             /* RRC,         */ 
    MAX_GPRF_POWER
};
extern const char*           GPRF_POWERToString(LP_GPRF_POWER_t val);
extern const char*           GPRF_POWERToSCPI(LP_GPRF_POWER_t val);
extern LP_GPRF_POWER_t       ScpiToGPRF_POWER(const char* val);

enum LP_Group_module_name_t { /* Group_module_name in [MODule:]MVSAALL[:ACTive]:LIST:DEFine?, [MODule:]MVSGALL[:ACTive]:LIST:DEFine? */
 
    MAX_GROUP_MODULE_NAME
};
extern const char*           Group_module_nameToString(LP_Group_module_name_t val);
extern const char*           Group_module_nameToSCPI(LP_Group_module_name_t val);
extern LP_Group_module_name_t ScpiToGroup_module_name(const char* val);

enum LP_IF_BW_t {            /* IF_BW in CONFigure:IFBW, CONFigure:IFBW? */
    LP_1150KHZ,              /* 1150KHZ,    BT IF BW 1.15MHz */
    LP_1300KHZ,              /* 1300KHZ,    BT IF BW 1.3MHz */
    LP_1450KHZ,              /* 1450KHZ,    BT IF BW 1.45MHz */
    LP_1600KHZ,              /* 1600KHZ,    BT IF BW 1.6MHz */
    LP_2000KHZ,              /* 2000KHZ,    BT IF BW 2.0MHz */ 
    MAX_IF_BW
};
extern const char*           IF_BWToString(LP_IF_BW_t val);
extern const char*           IF_BWToSCPI(LP_IF_BW_t val);
extern LP_IF_BW_t            ScpiToIF_BW(const char* val);

enum LP_Instance_t {         /* Instance in [MODule:]MVSAALL[:ACTive]:INSTance, [MODule:]MVSAALL[:ACTive]:INSTance?, [MODule:]MVSGALL[:ACTive]:INSTance, [MODule:]MVSGALL[:ACTive]:INSTance? */
    LP_INSTANCE_ALL,         /* ALL,        All Instances */
    LP_INSTANCE_INST1,       /* INST1,      Instance 1 */
    LP_INSTANCE_INST2,       /* INST2,      Instance 2 */ 
    MAX_INSTANCE
};
extern const char*           InstanceToString(LP_Instance_t val);
extern const char*           InstanceToSCPI(LP_Instance_t val);
extern LP_Instance_t         ScpiToInstance(const char* val);

enum LP_LE_Payload_Type_Detection_t { /* LE_Payload_Type_Detection in CONFigure:LENergy:PTDetection, CONFigure:LENergy:PTDetection? */
    LP_PATT,                 /* PATT,       Detect Payload Type from Patterns of Payload Bits */
    LP_HEAD,                 /* HEAD,       Detect Payload Type from Payload Header */ 
    MAX_LE_PAYLOAD_TYPE_DETECTION
};
extern const char*           LE_Payload_Type_DetectionToString(LP_LE_Payload_Type_Detection_t val);
extern const char*           LE_Payload_Type_DetectionToSCPI(LP_LE_Payload_Type_Detection_t val);
extern LP_LE_Payload_Type_Detection_t ScpiToLE_Payload_Type_Detection(const char* val);

enum LP_MAC_Address_Enable_t { /* MAC_Address_Enable in CONFigure:WAVE:PSDU:MACHeader:ADDRess{1:4}:ENABle, CONFigure:WAVE:PSDU:MACHeader:ADDRess{1:4}:ENABle? */
    LP_MACADD_ENABLE_OFF,    /* OFF,        Always OFF */
    LP_MACADD_ENABLE_ON,     /* ON,         Always ON */
    LP_MACADD_ENABLE_AUTO,   /* AUTO,       AUTO setting */ 
    MAX_MAC_ADDRESS_ENABLE
};
extern const char*           MAC_Address_EnableToString(LP_MAC_Address_Enable_t val);
extern const char*           MAC_Address_EnableToSCPI(LP_MAC_Address_Enable_t val);
extern LP_MAC_Address_Enable_t ScpiToMAC_Address_Enable(const char* val);

enum LP_MIMO_Analysis_Mode_t { /* MIMO_Analysis_Mode in CONFigure:OFDM:MIMO, CONFigure:OFDM:MIMO? */
    LP_MIMO_ANALYSIS_NXN,    /* NXN,        NXN MIMO Analysis */
    LP_MIMO_ANALYSIS_COMP,   /* COMP,       Composite MIMO Analysis */
    LP_MIMO_ANALYSIS_SING,   /* SING,       Single-Signal Analysis */
    LP_MIMO_ANALYSIS_EVMS,   /* EVMS,       EVM per Signal */ 
    MAX_MIMO_ANALYSIS_MODE
};
extern const char*           MIMO_Analysis_ModeToString(LP_MIMO_Analysis_Mode_t val);
extern const char*           MIMO_Analysis_ModeToSCPI(LP_MIMO_Analysis_Mode_t val);
extern LP_MIMO_Analysis_Mode_t ScpiToMIMO_Analysis_Mode(const char* val);

enum LP_MPS_mode_t {         /* MPS_mode in MPS:MODE, MPS:MODE?, MPS:MODE? */
    LP_MPS_OFF,              /* OFF,         */
    LP_MPS_FPT,              /* FPT,        First Packet Timeout */
    LP_MPS_FST,              /* FST,        Fixed Slot Time */
    LP_MPS_FAC,              /* FAC,        Fixed Ack Count */
    LP_MPS_FPC,              /* FPC,        Fixed Packet Count */
    LP_MPS_MDSY,             /* MDSY,       Multi DUT Synchronization */
    LP_MPS_CCSY,             /* CCSY,       Clear Channel Synchronization */ 
    MAX_MPS_MODE
};
extern const char*           MPS_modeToString(LP_MPS_mode_t val);
extern const char*           MPS_modeToSCPI(LP_MPS_mode_t val);
extern LP_MPS_mode_t         ScpiToMPS_mode(const char* val);

enum LP_Marker_Type_t {      /* Marker_source in MARKer:EXTernal{1:4}, MARKer:EXTernal{1:4}?, MARKer:EXTernal{1:4}, MARKer:EXTernal{1:4}?, MARKer:EXTernal{1:4}, MARKer:EXTernal{1:4}:SOURce, MARKer:EXTernal{1:4}:SOURce?, MARKer:EXTernal{1:4}? */
    LP_MKR_DET,              /* DET,         */
    LP_MKR_VAL,              /* VAL,        Valid trigger detection */
    LP_MKR_VID,              /* VID,        Signal detection above threshold and immediately following configured gap */
    LP_MKR_SWM,              /* SWM,        Software marker */
    LP_MKR_VSGM,             /* VSGM,       Start of a waveform. Repeats with the repeat of waveform. */
    LP_MKR_VSGD,             /* VSGD,       End of a waveform */
    LP_MKR_VSAD,             /* VSAD,       Capture is complete */
    LP_MKR_RFD1,             /* RFD1,       Wideband RF power threshold detection on port RF1 */
    LP_MKR_RFD2,             /* RFD2,       Wideband RF power threshold detection on port RF2 */
    LP_MKR_RFD3,             /* RFD3,        */
    LP_MKR_RFD4,             /* RFD4,        */
    LP_MKR_WSM1,             /* WSM1,       Programmable marker in wave segment. Repeats with the repeat of wave segment. */
    LP_MKR_WSM2,             /* WSM2,       Programmable marker in wave segment. Repeats with the repeat of wave segment. */
    LP_MKR_WLD,              /* WLD,        End of wavelist. Repeats with the repeat of wavelist. */
    LP_MKR_OFF,              /* OFF,        Power is set off */
    LP_MKR_AOFF,             /* AOFF,        */
    LP_MKR_HIGH,             /* HIGH,       Marker is set high */
    LP_MKR_LOW,              /* LOW,        Marker is set low */
    LP_MKR_PWM,              /* PWM,        Pulse Width Modulated signal of the specified duty cycle synchronized with the 10 MHz reference */
    LP_MKR_10MH,             /* 10MH,       10MHz reference */
    LP_MKR_INP,              /* INP,        Digital I/O is set to input */
    LP_MKR_RFD1A,            /* RFD1A,       */
    LP_MKR_RFD2A,            /* RFD2A,       */
    LP_MKR_RFD3A,            /* RFD3A,       */
    LP_MKR_RFD4A,            /* RFD4A,       */
    LP_MKR_RFD1B,            /* RFD1B,       */
    LP_MKR_RFD2B,            /* RFD2B,       */
    LP_MKR_RFD3B,            /* RFD3B,       */
    LP_MKR_RFD4B,            /* RFD4B,       */
    LP_MKR_RFD1C,            /* RFD1C,       */
    LP_MKR_RFD2C,            /* RFD2C,       */
    LP_MKR_RFD3C,            /* RFD3C,       */
    LP_MKR_RFD4C,            /* RFD4C,       */
    LP_MKR_RFD1D,            /* RFD1D,       */
    LP_MKR_RFD2D,            /* RFD2D,       */
    LP_MKR_RFD3D,            /* RFD3D,       */
    LP_MKR_RFD4D,            /* RFD4D,       */
    LP_MKR_SLOT,             /* SLOT%d,     Marker is sent from the specified slot */
    LP_MKR_TIM,              /* TIM%d,      Timer expiration */
    LP_MKR_TIM1,             /* TIM1,        */
    LP_MKR_TIM2,             /* TIM2,        */
    LP_MKR_TIM3,             /* TIM3,        */
    LP_MKR_TIM4,             /* TIM4,        */ 
    MAX_MARKER_TYPE
};
extern const char*           Marker_TypeToString(LP_Marker_Type_t val);
extern const char*           Marker_TypeToSCPI(LP_Marker_Type_t val);
extern LP_Marker_Type_t      ScpiToMarker_Type(const char* val);

enum LP_Mode_t {             /* Mode in [SYSTem:][COMMunicate:][SESSion:]OBUFfer[:MODE], [SYSTem:][COMMunicate:][SESSion:]OBUFfer[:MODE]? */
    LP_BUFFER_MODE_OFF,      /* OFF,        No output buffering */
    LP_BUFFER_MODE_SING,     /* SING,       Buffer all output from a single command before output to socket */
    LP_BUFFER_MODE_ALL,      /* ALL,        Buffer all commands in a program message before output to socket */ 
    MAX_MODE
};
extern const char*           ModeToString(LP_Mode_t val);
extern const char*           ModeToSCPI(LP_Mode_t val);
extern LP_Mode_t             ScpiToMode(const char* val);

enum LP_Modulation_Type_t {  /* Modulation_Type in CONFigure:STANdard, CONFigure:STANdard?, CONFigure:WAVE:STANdard, CONFigure:WAVE:STANdard? */
    LP_OQPSK,                /* OQPSK,      Modulation Type OQPSK */
    LP_BPSK915,              /* BPSK915,    Modulation Type BPSK 915 MHz */
    LP_BPSK868,              /* BPSK868,    Modulation Type BPSK 868 MHz */ 
    MAX_MODULATION_TYPE
};
extern const char*           Modulation_TypeToString(LP_Modulation_Type_t val);
extern const char*           Modulation_TypeToSCPI(LP_Modulation_Type_t val);
extern LP_Modulation_Type_t  ScpiToModulation_Type(const char* val);

enum LP_Module_Subtype_t {   /* Module_Subtype in STYPe?, STYPe?, STYPe?, STYPe? */
    LP_MD0,                  /* MD0,        MD0 */
    LP_MD0_U1,               /* MD0_U1,     MD0-U1 */
    LP_MD0_V2,               /* MD0_V2,     MD0-V2 */
    LP_MD0_V3,               /* MD0_V3,     MD0-V3 */
    LP_MD1,                  /* MD1,        MD1 */
    LP_MD3,                  /* MD3,        MD3 */
    LP_MD7,                  /* MD7,        MD7 */
    LP_MD8,                  /* MD8,        MD8 */
    LP_MD9,                  /* MD9,        MD9 */
    LP_MDB,                  /* MDB,         */
    LP_MDC,                  /* MDC,         */
    LP_MDD,                  /* MDD,        MDD */
    LP_MDE,                  /* MDE,        MDE */
    LP_MDF,                  /* MDF,        MDF */
    LP_MDJ,                  /* MDJ,        MDJ */
    LP_MDK,                  /* MDK,         */
    LP_MDL,                  /* MDL,         */
    LP_MDN,                  /* MDN,         */
    LP_AA00,                 /* AA00,       AA00 */
    LP_AA01,                 /* AA01,       AA01 */
    LP_AA02,                 /* AA02,       AA02 */
    LP_AA03,                 /* AA03,       AA03 */
    LP_AA04,                 /* AA04,        */
    LP_AA05,                 /* AA05,        */
    LP_AA06,                 /* AA06,       AA06 */ 
    MAX_MODULE_SUBTYPE
};
extern const char*           Module_SubtypeToString(LP_Module_Subtype_t val);
extern const char*           Module_SubtypeToSCPI(LP_Module_Subtype_t val);
extern LP_Module_Subtype_t   ScpiToModule_Subtype(const char* val);

enum LP_Module_name_t {      /* Module_name in [MODule:]MROUT:DEFine?, [MODule:]MVSA:DEFine?, [MODule:]MVSG:DEFine? */
    LP_VSA1,                 /* VSA1,        */
    LP_VSA2,                 /* VSA2,        */
    LP_VSA3,                 /* VSA3,        */
    LP_VSA4,                 /* VSA4,        */
    LP_VSG1,                 /* VSG1,        */
    LP_VSG2,                 /* VSG2,        */
    LP_VSG3,                 /* VSG3,        */
    LP_VSG4,                 /* VSG4,        */
    LP_ROUT1,                /* ROUT1,       */
    LP_ROUT2,                /* ROUT2,       */
    LP_ROUT3,                /* ROUT3,       */
    LP_ROUT4,                /* ROUT4,       */ 
    MAX_MODULE_NAME
};
extern const char*           Module_nameToString(LP_Module_name_t val);
extern const char*           Module_nameToSCPI(LP_Module_name_t val);
extern LP_Module_name_t      ScpiToModule_name(const char* val);

enum LP_Module_t {           /* Module in APPLet:MODule[:STARt], [MODule:]AMODules?, [MODule:]CMODules?, [MODule:]MODule?, SEQuence:EXECute:TSTamp:MODule?, [SYSTem:][COMMunicate:]REMote:AMODules? */
    LP_MOD_SYS,              /* SYS,        SYS Module */
    LP_MOD_VSG1,             /* VSG1,        */
    LP_MOD_VSG2,             /* VSG2,        */
    LP_MOD_VSA1,             /* VSA1,        */
    LP_MOD_VSA2,             /* VSA2,        */
    LP_MOD_ROUT1,            /* ROUT1,       */
    LP_MOD_ROUT2,            /* ROUT2,       */
    LP_MOD_BP,               /* BP,         BP Module */
    LP_MOD_GSM,              /* GSM,         */
    LP_MOD_WCDMA,            /* WCDMA,       */
    LP_MOD_CDMA2K,           /* CDMA2K,      */
    LP_MOD_LTE,              /* LTE,         */
    LP_MOD_LTE_BS,           /* LTE_BS,      */
    LP_MOD_GPRF,             /* GPRF,       GPRF Module */
    LP_MOD_BT,               /* BT,         BT Module */
    LP_MOD_WIFI,             /* WIFI,       WIFI Module */
    LP_MOD_TDSCDMA,          /* TDSCDMA,     */
    LP_MOD_LTEBS,            /* LTEBS,       */
    LP_MOD_WCDMABS,          /* WCDMABS,     */
    LP_MOD_OFF,              /* OFF,         */
    LP_MOD_ZIGBEE,           /* ZIGBEE,     ZIGBEE Module */
    LP_MOD_DECT,             /* DECT,       DECT Module */
    LP_MOD_DIGI,             /* DIGI%d,      */
    LP_MOD_DEF,              /* DEF%d,       */
    LP_MOD_COMB,             /* COMB%d,      */
    LP_MOD_SNIC,             /* SNIC,        */
    LP_MOD_PSUP,             /* PSUP%d,      */
    LP_MOD_TPUT,             /* TPUT,        */
    LP_MOD_NFCC,             /* NFCC%d,      */
    LP_MOD_NFC,              /* NFC,         */
    LP_MOD_GNSS,             /* GNSS%d,      */
    LP_MOD_LFC,              /* LFC%d,       */
    LP_MOD_PUSH,             /* PUSH%d,      */
    LP_MOD_CELL,             /* CELL%d,      */
    LP_MOD_TESTMEAS,         /* TESTMEAS,    */ 
    MAX_MODULE
};
extern const char*           ModuleToString(LP_Module_t val);
extern const char*           ModuleToSCPI(LP_Module_t val);
extern LP_Module_t           ScpiToModule(const char* val);

enum LP_NSYMbols_Mode_t {    /* Number_of_Symbols_Mode in CONFigure:OFDM:NSYMbols, CONFigure:OFDM:NSYMbols? */
    LP_NSYM_LSIG,            /* LSIG,       SIG Field */
    LP_NSYM_POW,             /* POW,        Signal Power */
    LP_NSYM_USER,            /* USER,       User Defined */ 
    MAX_NSYMBOLS_MODE
};
extern const char*           NSYMbols_ModeToString(LP_NSYMbols_Mode_t val);
extern const char*           NSYMbols_ModeToSCPI(LP_NSYMbols_Mode_t val);
extern LP_NSYMbols_Mode_t    ScpiToNSYMbols_Mode(const char* val);

enum LP_Number_of_Chips_Mode_t { /* Number_of_Chips_Mode in CONFigure:DSSS:NCHips, CONFigure:DSSS:NCHips? */
    LP_NCHIPS_PLCP,          /* PLCP,       PLCP Defined Number */
    LP_NCHIPS_USER,          /* USER,       User Defined */ 
    MAX_NUMBER_OF_CHIPS_MODE
};
extern const char*           Number_of_Chips_ModeToString(LP_Number_of_Chips_Mode_t val);
extern const char*           Number_of_Chips_ModeToSCPI(LP_Number_of_Chips_Mode_t val);
extern LP_Number_of_Chips_Mode_t ScpiToNumber_of_Chips_Mode(const char* val);

enum LP_Number_of_Equilizer_Taps_t { /* Number_of_Equilizer_Taps in CONFigure:DSSS:ETAPs, CONFigure:DSSS:ETAPs? */
    LP_TAP_OFF,              /* OFF,        Equalizer Taps Off */
    LP_TAP_TAP5,             /* TAP5,       Equalizer Taps = 5 */
    LP_TAP_TAP7,             /* TAP7,       Equalizer Taps = 7 */
    LP_TAP_TAP9,             /* TAP9,       Equalizer Taps = 9 */ 
    MAX_NUMBER_OF_EQUILIZER_TAPS
};
extern const char*           Number_of_Equilizer_TapsToString(LP_Number_of_Equilizer_Taps_t val);
extern const char*           Number_of_Equilizer_TapsToSCPI(LP_Number_of_Equilizer_Taps_t val);
extern LP_Number_of_Equilizer_Taps_t ScpiToNumber_of_Equilizer_Taps(const char* val);

enum LP_PSDU_Setting_t {     /* PSDU_Setting in CONFigure:WAVE:PSDU:DATA:TYPE, CONFigure:WAVE:PSDU:DATA:TYPE?, CONFigure:WAVE:PSDU:DATA:TYPE, CONFigure:WAVE:PSDU:DATA:TYPE? */
    LP_PSDU_USER,            /* USER,       User Defined Bits */
    LP_PSDU_ALL0,            /* ALL0,       All 0 bits */
    LP_PSDU_ALL1,            /* ALL1,       All 1 bits */
    LP_PSDU_ALT01,           /* ALT01,      Alternate 0 1 bits */
    LP_PSDU_ALT10,           /* ALT10,      Alternate 1 0 bits */
    LP_PSDU_RANDOM,          /* RANDOM,     Random Bits */
    LP_PSDU_PN9,             /* PN9,        PN9 sequence */
    LP_PSDU_PN15,            /* PN15,       PN15 sequence */ 
    MAX_PSDU_SETTING
};
extern const char*           PSDU_SettingToString(LP_PSDU_Setting_t val);
extern const char*           PSDU_SettingToSCPI(LP_PSDU_Setting_t val);
extern LP_PSDU_Setting_t     ScpiToPSDU_Setting(const char* val);

enum LP_Packet_Detect_Ramp_Requirement_t { /* Packet_Detect_Ramp_Requirement in CONFigure:PDETection:RAMP, CONFigure:PDETection:RAMP?, CONFigure:PDETection:RAMP, CONFigure:PDETection:RAMP?, CONFigure:PDETection:RAMP, CONFigure:PDETection:RAMP? */
    LP_PACKET_RAMP_NONE,     /* NONE,       No ramp requirements */
    LP_PACKET_RAMP_UP,       /* UP,         Up ramp required */
    LP_PACKET_RAMP_UPDOWN,   /* UPDOWN,     Both up and down ramp required */ 
    MAX_PACKET_DETECT_RAMP_REQUIREMENT
};
extern const char*           Packet_Detect_Ramp_RequirementToString(LP_Packet_Detect_Ramp_Requirement_t val);
extern const char*           Packet_Detect_Ramp_RequirementToSCPI(LP_Packet_Detect_Ramp_Requirement_t val);
extern LP_Packet_Detect_Ramp_Requirement_t ScpiToPacket_Detect_Ramp_Requirement(const char* val);

enum LP_Packet_Format_t {    /* Packet_Format in CONFigure:OFDM:PFORmat, CONFigure:OFDM:PFORmat? */
    LP_PACKET_FORMAT_AUTO,   /* AUTO,       Automatic Detection */
    LP_PACKET_FORMAT_NONH,   /* NONH,       Non-HT */
    LP_PACKET_FORMAT_MIX,    /* MIX,        HT-Mixed */
    LP_PACKET_FORMAT_GRE,    /* GRE,        HT-Greenfield */
    LP_PACKET_FORMAT_VHT,    /* VHT,        VHT */
    LP_PACKET_FORMAT_TVHT,   /* TVHT,       TVHT */
    LP_PACKET_FORMAT_S1G1,   /* S1G1,       S1G-1MHz */
    LP_PACKET_FORMAT_S1GS,   /* S1GS,       S1G-Short */
    LP_PACKET_FORMAT_S1GL,   /* S1GL,       S1G-Long */ 
    MAX_PACKET_FORMAT
};
extern const char*           Packet_FormatToString(LP_Packet_Format_t val);
extern const char*           Packet_FormatToSCPI(LP_Packet_Format_t val);
extern LP_Packet_Format_t    ScpiToPacket_Format(const char* val);

enum LP_Packet_Type_t {      /* Packet_Type in CONFigure:WAVE:PTYPe, CONFigure:WAVE:PTYPe?, CONFigure:WAVE:PTYPe, CONFigure:WAVE:PTYPe? */
    LP_GEN_PACKET_TYPE_P00,   /* P00,       P00 */
    LP_GEN_PACKET_TYPE_P32,   /* P32,       P32 */
    LP_GEN_PACKET_TYPE_P80,   /* P80,       P80 */
    LP_GEN_PACKET_TYPE_P00J_80,   /* P00J_80, P00j (j=80) */
    LP_GEN_PACKET_TYPE_P00J_640,   /* P00J_640, P00j (j=640) */
    LP_GEN_PACKET_TYPE_P00J_672,   /* P00J_672, P00j (j=672) */
    LP_GEN_PACKET_TYPE_P00J,   /* P00J,     P00j (j=any) */ 
    MAX_PACKET_TYPE
};
extern const char*           Packet_TypeToString(LP_Packet_Type_t val);
extern const char*           Packet_TypeToSCPI(LP_Packet_Type_t val);
extern LP_Packet_Type_t      ScpiToPacket_Type(const char* val);

enum LP_Parameter_reference_type_t { /* Parameter_reference_type in APPLet[:DEFine]:PARameter[:ADD], APPLet[:DEFine]:PARameter[:ADD]? */
    LP_PARAM_TYPE_VAL,       /* VAL,        Pass by value */
    LP_PARAM_TYPE_REF,       /* REF,        Pass by reference */ 
    MAX_PARAMETER_REFERENCE_TYPE
};
extern const char*           Parameter_reference_typeToString(LP_Parameter_reference_type_t val);
extern const char*           Parameter_reference_typeToSCPI(LP_Parameter_reference_type_t val);
extern LP_Parameter_reference_type_t ScpiToParameter_reference_type(const char* val);

enum LP_Parameter_type_t {   /* Parameter_data_type in APPLet[:DEFine]:PARameter[:ADD], APPLet[:DEFine]:PARameter[:ADD]? */
    LP_TYPE_DOUB,            /* DOUB,       Parameter type of double */
    LP_TYPE_SINT,            /* SINT,       Parameter type of integer */
    LP_TYPE_UINT,            /* UINT,       Parameter type of unsigned integer */
    LP_TYPE_STR,             /* STR,        Parameter type of quoted string */
    LP_TYPE_USTR,            /* USTR,       Parameter type of unquoted string */
    LP_TYPE_BOOL,            /* BOOL,       Parameter type of boolean */
    LP_TYPE_MOD,             /* MOD,        Parameter type of module */
    LP_TYPE_BYTE,            /* BYTE,       Parameter type of byte */ 
    MAX_PARAMETER_TYPE
};
extern const char*           Parameter_typeToString(LP_Parameter_type_t val);
extern const char*           Parameter_typeToSCPI(LP_Parameter_type_t val);
extern LP_Parameter_type_t   ScpiToParameter_type(const char* val);

enum LP_Payload_Type_t {     /* Payload_Type in CONFigure:WAVE:PDTYpe, CONFigure:WAVE:PDTYpe? */
    LP_PAYLOAD_ALT10,        /* ALT10,      Alternating 1 0 */
    LP_PAYLOAD_ALL1,         /* ALL1,       All 1 */
    LP_PAYLOAD_ALL0,         /* ALL0,       All 0 */
    LP_PAYLOAD_FOUR1FOUR0,   /* FOUR1FOUR0, 11110000 */
    LP_PAYLOAD_USER,         /* USER,       User defined */
    LP_PAYLOAD_RANDOM,       /* RANDOM,     PRBS9 */ 
    MAX_PAYLOAD_TYPE
};
extern const char*           Payload_TypeToString(LP_Payload_Type_t val);
extern const char*           Payload_TypeToSCPI(LP_Payload_Type_t val);
extern LP_Payload_Type_t     ScpiToPayload_Type(const char* val);

enum LP_Port_Name_t {        /* Port_name in RFCorrection:LOSS?, RFCorrection:STATe, RFCorrection:STATe?, RFCorrection:USE, RFCorrection:USE?, RFCorrection:LOSS?, RFCorrection:STATe, RFCorrection:STATe?, RFCorrection:USE, RFCorrection:USE?, PORT:CORRection{1:40}:USE, PORT:CORRection[:CONFiguration]:STATe, PORT:CORRection[:CONFiguration]:STATe?, PORT:MPS:RX[:CONFiguration], PORT:RESource, PORT[:RESource]:MAP?, PORT:RESource? */
    LP_STRM1A,               /* STRM1A,      */
    LP_RF1A,                 /* RF1A,       RF port 1A */
    LP_RF2A,                 /* RF2A,       RF port 2A */
    LP_RF3A,                 /* RF3A,       RF port 3A */
    LP_RF4A,                 /* RF4A,       RF port 4A */
    LP_STRM1B,               /* STRM1B,      */
    LP_RF1,                  /* RF1,         */
    LP_RF2,                  /* RF2,         */
    LP_RF3,                  /* RF3,         */
    LP_RF4,                  /* RF4,         */
    LP_BB,                   /* BB,         BaseBand port */
    LP_RF1B,                 /* RF1B,       RF port 1B */
    LP_RF2B,                 /* RF2B,       RF port 2B */
    LP_RF3B,                 /* RF3B,       RF port 3B */
    LP_RF4B,                 /* RF4B,       RF port 4B */ 
    MAX_PORT_NAME
};
extern const char*           Port_NameToString(LP_Port_Name_t val);
extern const char*           Port_NameToSCPI(LP_Port_Name_t val);
extern LP_Port_Name_t        ScpiToPort_Name(const char* val);

enum LP_Port_t {             /* Resource1 in PORT:CORRection{1:40}:USE, PORT:CORRection[:CONFiguration]:STATe, PORT:CORRection[:CONFiguration]:STATe?, PORT:MPS:RX[:CONFiguration], PORT:RESource, PORT[:RESource]:MAP?, PORT:RESource?, MARKer:EXTernal{1:4}, MARKer:EXTernal{1:4}?, HSET:ALL, HSET:FREQuency, HSET:FREQuency?, HSET:RLEVel, HSET:ALL, HSET:FREQuency, HSET:FREQuency?, HSET:RLEVel, HSET:ALL, HSET:FREQuency, HSET:FREQuency?, HSET:RLEVel, HSET:ALL, HSET:FREQuency, HSET:FREQuency?, HSET:RLEVel */
    LP_PORT_VSG1,            /* VSG1,        */
    LP_PORT_VSG2,            /* VSG2,        */
    LP_PORT_VSG11,           /* VSG11,       */
    LP_PORT_VSG12,           /* VSG12,       */
    LP_PORT_VSA1,            /* VSA1,        */
    LP_PORT_VSA2,            /* VSA2,        */
    LP_PORT_VSA11,           /* VSA11,       */
    LP_PORT_VSA12,           /* VSA12,       */
    LP_PORT_OFF,             /* OFF,        OFF parameter */
    LP_PORT_MVSA1,           /* MVSA1,       */
    LP_PORT_MVSA2,           /* MVSA2,       */
    LP_PORT_MVSG1,           /* MVSG1,       */
    LP_PORT_MVSG2,           /* MVSG2,       */
    LP_PORT_MVSAALL,         /* MVSAALL,    MVSAALL Module */
    LP_PORT_MVSGALL,         /* MVSGALL,    MVSGALL Module */ 
    MAX_PORT
};
extern const char*           PortToString(LP_Port_t val);
extern const char*           PortToSCPI(LP_Port_t val);
extern LP_Port_t             ScpiToPort(const char* val);

enum LP_Preamble_Setting_t { /* Preamble_Setting in CONFigure:WAVE:DSSS:PREamble, CONFigure:WAVE:DSSS:PREamble? */
    LP_PREAMBLE_OFF,         /* OFF,        Preamble OFF */
    LP_PREAMBLE_SHORT,       /* SHORT,      Short Preamble */
    LP_PREAMBLE_LONG,        /* LONG,       Long Preamble */ 
    MAX_PREAMBLE_SETTING
};
extern const char*           Preamble_SettingToString(LP_Preamble_Setting_t val);
extern const char*           Preamble_SettingToSCPI(LP_Preamble_Setting_t val);
extern LP_Preamble_Setting_t ScpiToPreamble_Setting(const char* val);

enum LP_Preamble_Type_t {    /* Preamble_Type in CONFigure:WAVE:OFDM:PREamble, CONFigure:WAVE:OFDM:PREamble?, CONFigure:WAVE:PREamble, CONFigure:WAVE:PREamble? */
    LP_PREAMB_TYPE_NORM,     /* NORM,       Normal */
    LP_PREAMB_TYPE_PROL,     /* PROL,       Prolonged */ 
    MAX_PREAMBLE_TYPE
};
extern const char*           Preamble_TypeToString(LP_Preamble_Type_t val);
extern const char*           Preamble_TypeToSCPI(LP_Preamble_Type_t val);
extern LP_Preamble_Type_t    ScpiToPreamble_Type(const char* val);

enum LP_Ramp_Up_Type_t {     /* Ramp_Up_Type in CONFigure:WAVE:DSSS:RAMP:TYPE, CONFigure:WAVE:DSSS:RAMP:TYPE? */
    LP_RAMP_NONE,            /* NONE,       No Ramp Added */
    LP_RAMP_LINEAR,          /* LINEAR,     Linear Ramp */
    LP_RAMP_COSINE,          /* COSINE,     Cosine Ramp */ 
    MAX_RAMP_UP_TYPE
};
extern const char*           Ramp_Up_TypeToString(LP_Ramp_Up_Type_t val);
extern const char*           Ramp_Up_TypeToSCPI(LP_Ramp_Up_Type_t val);
extern LP_Ramp_Up_Type_t     ScpiToRamp_Up_Type(const char* val);

enum LP_Reference_Oscillator_t { /* Reference_Oscillator in ROSCillator[:SOURce], ROSCillator[:SOURce]? */
    LP_REF_INTERNAL,         /* INT,        Reference oscillator is internally generated */
    LP_REF_EXTERNAL,         /* EXT,        Reference oscillator is externally supplied */ 
    MAX_REFERENCE_OSCILLATOR
};
extern const char*           Reference_OscillatorToString(LP_Reference_Oscillator_t val);
extern const char*           Reference_OscillatorToSCPI(LP_Reference_Oscillator_t val);
extern LP_Reference_Oscillator_t ScpiToReference_Oscillator(const char* val);

enum LP_Response_data_type_t { /* Response_data_type in APPLet[:DEFine]:RESPonse[:ADD], APPLet[:DEFine]:RESPonse[:ADD]? */
    LP_DOUB,                 /* DOUB,       Response type of double */
    LP_FLO,                  /* FLO,        Response type of float */
    LP_INT,                  /* INT,        Response type of integer */
    LP_UINT,                 /* UINT,       Response type of unsigned integer */
    LP_STR,                  /* STR,        Response type of string */
    LP_USTR,                 /* USTR,       Response type of unquoted string */
    LP_ARB,                  /* ARB,        Response type of arbitrary length block */ 
    MAX_RESPONSE_DATA_TYPE
};
extern const char*           Response_data_typeToString(LP_Response_data_type_t val);
extern const char*           Response_data_typeToSCPI(LP_Response_data_type_t val);
extern LP_Response_data_type_t ScpiToResponse_data_type(const char* val);

enum LP_Seed_Type_t {        /* Seed_Type in WAVE:DEGRadation:SEED, WAVE:DEGRadation:SEED? */
    LP_SEED_TYPE_RANDOM,     /* RANDOM,     Randomly generated seed. */
    LP_SEED_TYPE_FIXED,      /* FIXED,      Fixed seed */ 
    MAX_SEED_TYPE
};
extern const char*           Seed_TypeToString(LP_Seed_Type_t val);
extern const char*           Seed_TypeToSCPI(LP_Seed_Type_t val);
extern LP_Seed_Type_t        ScpiToSeed_Type(const char* val);

enum LP_Sequence_Control_Enable_t { /* Sequence_Control_Enable in CONFigure:WAVE:PSDU:MACHeader:SEQuence:ENABle, CONFigure:WAVE:PSDU:MACHeader:SEQuence:ENABle? */
    LP_SEQCON_ENABLE_OFF,    /* OFF,        Always OFF */
    LP_SEQCON_ENABLE_ON,     /* ON,         Always ON */
    LP_SEQCON_ENABLE_AUTO,   /* AUTO,       AUTO setting */ 
    MAX_SEQUENCE_CONTROL_ENABLE
};
extern const char*           Sequence_Control_EnableToString(LP_Sequence_Control_Enable_t val);
extern const char*           Sequence_Control_EnableToSCPI(LP_Sequence_Control_Enable_t val);
extern LP_Sequence_Control_Enable_t ScpiToSequence_Control_Enable(const char* val);

enum LP_Signal_Direction_t { /* Signal_Direction in CONFigure:PDETection:DIRection, CONFigure:PDETection:DIRection?, CONFigure:WAVE:DIRection, CONFigure:WAVE:DIRection? */
    LP_SIGNAL_DIR_DL,        /* DL,         Downlink */
    LP_SIGNAL_DIR_UL,        /* UL,         Uplink */
    LP_SIGNAL_DIR_ANY,       /* ANY,        Any */ 
    MAX_SIGNAL_DIRECTION
};
extern const char*           Signal_DirectionToString(LP_Signal_Direction_t val);
extern const char*           Signal_DirectionToSCPI(LP_Signal_Direction_t val);
extern LP_Signal_Direction_t ScpiToSignal_Direction(const char* val);

enum LP_Signal_Type_t {      /* Signal_Type in CONFigure:SPECtrum:SIGNal, CONFigure:SPECtrum:SIGNal? */
    LP_SIGNAL_TYPE_CW,       /* CW,         Continuous Wave; generates high-resolution spectrum */
    LP_SIGNAL_TYPE_NB,       /* NB,         Narrow Band; generates mid-resolution spectrum */
    LP_SIGNAL_TYPE_WB,       /* WB,         Wide Band; generates low-resolution spectrum */ 
    MAX_SIGNAL_TYPE
};
extern const char*           Signal_TypeToString(LP_Signal_Type_t val);
extern const char*           Signal_TypeToSCPI(LP_Signal_Type_t val);
extern LP_Signal_Type_t      ScpiToSignal_Type(const char* val);

enum LP_Smoothing_Bit_t {    /* Smoothing_Bit in CONFigure:WAVE:OFDM:SMOothing, CONFigure:WAVE:OFDM:SMOothing? */
    LP_SB_OFF,               /* OFF,        Always OFF */
    LP_SB_ON,                /* ON,         Always ON */
    LP_SB_AUTO,              /* AUTO,       AUTO setting */ 
    MAX_SMOOTHING_BIT
};
extern const char*           Smoothing_BitToString(LP_Smoothing_Bit_t val);
extern const char*           Smoothing_BitToSCPI(LP_Smoothing_Bit_t val);
extern LP_Smoothing_Bit_t    ScpiToSmoothing_Bit(const char* val);

enum LP_Spectrum_Limits_Type_t { /* Spectrum_Limits_Type in CONFigure:SPECtrum:HLIM:TYPE, CONFigure:SPECtrum:HLIM:TYPE? */
    LP_SL_AUTO,              /* AUTO,       Automatic limits */
    LP_SL_UNII4,             /* UNII4,      UNII-4 band limits specified for 802.11p */ 
    MAX_SPECTRUM_LIMITS_TYPE
};
extern const char*           Spectrum_Limits_TypeToString(LP_Spectrum_Limits_Type_t val);
extern const char*           Spectrum_Limits_TypeToSCPI(LP_Spectrum_Limits_Type_t val);
extern LP_Spectrum_Limits_Type_t ScpiToSpectrum_Limits_Type(const char* val);

enum LP_Spectrum_Margin_Mode_t { /* Spectrum_Margin_Frequency_Range_Mode in CONFigure:SPECtrum:FRANges:MODE, CONFigure:SPECtrum:FRANges:MODE? */
    LP_SPECTRUM_MARGIN_AUTO,   /* AUTO,     Auto Spectrum Margin Frequency Ranges */
    LP_SPECTRUM_MARGIN_USER,   /* USER,     User Spectrum Margin Frequency Ranges */ 
    MAX_SPECTRUM_MARGIN_MODE
};
extern const char*           Spectrum_Margin_ModeToString(LP_Spectrum_Margin_Mode_t val);
extern const char*           Spectrum_Margin_ModeToSCPI(LP_Spectrum_Margin_Mode_t val);
extern LP_Spectrum_Margin_Mode_t ScpiToSpectrum_Margin_Mode(const char* val);

enum LP_Spectrum_Mode_t {    /* Spectrum_Limits_Mode in CONFigure:SPECtrum:HLIMit, CONFigure:SPECtrum:HLIMit? */
    LP_SPECTRUM_MODE_AUTO,   /* AUTO,       Auto Spectrum High Limits */
    LP_SPECTRUM_MODE_CBW,    /* CBW,        CBW based Spectrum High Limits */ 
    MAX_SPECTRUM_MODE
};
extern const char*           Spectrum_ModeToString(LP_Spectrum_Mode_t val);
extern const char*           Spectrum_ModeToSCPI(LP_Spectrum_Mode_t val);
extern LP_Spectrum_Mode_t    ScpiToSpectrum_Mode(const char* val);

enum LP_Start_one_or_more_t { /* Start_one_or_more in APPLet[:DEFine]:RESPonse[:ADD]? */
    LP_STAR,                 /* STAR,       Start of a response with one or more elements */ 
    MAX_START_ONE_OR_MORE
};
extern const char*           Start_one_or_moreToString(LP_Start_one_or_more_t val);
extern const char*           Start_one_or_moreToSCPI(LP_Start_one_or_more_t val);
extern LP_Start_one_or_more_t ScpiToStart_one_or_more(const char* val);

enum LP_TGn_Channel_Model_t { /* TGn_Channel_Model in WAVE:CHANnel:TGN:MODel, WAVE:CHANnel:TGN:MODel? */
    LP_TGN_CHANNEL_MODEL_A,   /* A,         WiFi TGn channel model A */
    LP_TGN_CHANNEL_MODEL_B,   /* B,         WiFi TGn channel model B */
    LP_TGN_CHANNEL_MODEL_C,   /* C,         WiFi TGn channel model C */
    LP_TGN_CHANNEL_MODEL_D,   /* D,         WiFi TGn channel model D */
    LP_TGN_CHANNEL_MODEL_E,   /* E,         WiFi TGn channel model E */
    LP_TGN_CHANNEL_MODEL_F,   /* F,         WiFi TGn channel model F */ 
    MAX_TGN_CHANNEL_MODEL
};
extern const char*           TGn_Channel_ModelToString(LP_TGn_Channel_Model_t val);
extern const char*           TGn_Channel_ModelToSCPI(LP_TGn_Channel_Model_t val);
extern LP_TGn_Channel_Model_t ScpiToTGn_Channel_Model(const char* val);

enum LP_Timer_Source_t {     /* Timer_source in TIMer:SOURce, TIMer:SOURce?, TIMer:SOURce, TIMer:SOURce? */
    LP_TIMER_SRC_IMM,        /* IMM,        Triggers when armed */
    LP_TIMER_SRC_TIM,        /* TIM,        Triggers when the configured timer expiration occurs */
    LP_TIMER_SRC_VID,        /* VID,        Triggers when an RF signal transition of the configured slope, level, and gap time occurs at baseband */
    LP_TIMER_SRC_EXT1,       /* EXT1,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TIMER_SRC_EXT2,       /* EXT2,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TIMER_SRC_EXT3,       /* EXT3,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TIMER_SRC_EXT4,       /* EXT4,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TIMER_SRC_RFDOR2,     /* RFDOR2,      */
    LP_TIMER_SRC_RFDOR3,     /* RFDOR3,      */
    LP_TIMER_SRC_RFDOR4,     /* RFDOR4,      */
    LP_TIMER_SRC_MTXD,       /* MTXD,        */
    LP_TIMER_SRC_MRXD,       /* MRXD,        */
    LP_TIMER_SRC_RFD1,       /* RFD1,       Triggers when Wideband RF power threshold detection occurs on port RF1 */
    LP_TIMER_SRC_RFD2,       /* RFD2,       Triggers when Wideband RF power threshold detection occurs on port RF2 */
    LP_TIMER_SRC_RFD1A,      /* RFD1A,       */
    LP_TIMER_SRC_RFD2A,      /* RFD2A,       */ 
    MAX_TIMER_SOURCE
};
extern const char*           Timer_SourceToString(LP_Timer_Source_t val);
extern const char*           Timer_SourceToSCPI(LP_Timer_Source_t val);
extern LP_Timer_Source_t     ScpiToTimer_Source(const char* val);

enum LP_Transmit_Power_Class_t { /* Transmit_Power_Class in CONFigure:POWer:CLASs, CONFigure:POWer:CLASs? */
    LP_TRANSMIT_POWER_CLASS_A,   /* A,      Transmit power class A */
    LP_TRANSMIT_POWER_CLASS_B,   /* B,      Transmit power class B */
    LP_TRANSMIT_POWER_CLASS_C,   /* C,      Transmit power class C */
    LP_TRANSMIT_POWER_CLASS_D,   /* D,      Transmit power class D */ 
    MAX_TRANSMIT_POWER_CLASS
};
extern const char*           Transmit_Power_ClassToString(LP_Transmit_Power_Class_t val);
extern const char*           Transmit_Power_ClassToSCPI(LP_Transmit_Power_Class_t val);
extern LP_Transmit_Power_Class_t ScpiToTransmit_Power_Class(const char* val);

enum LP_Trigger_Mode_t {     /* Trigger_mode in TRIGger:MODE, TRIGger:MODE?, TRIGger:MODE, TRIGger:MODE? */
    LP_TRIG_MODE_SSH,        /* SSH,        Generates a single trigger when the configured trigger event occurs */
    LP_TRIG_MODE_MPAC,       /* MPAC,       Generates a trigger every time the configured packet event occurs */
    LP_TRIG_MODE_MSH,        /* MSH,        Generates a trigger every time the configured packet event occurs */ 
    MAX_TRIGGER_MODE
};
extern const char*           Trigger_ModeToString(LP_Trigger_Mode_t val);
extern const char*           Trigger_ModeToSCPI(LP_Trigger_Mode_t val);
extern LP_Trigger_Mode_t     ScpiToTrigger_Mode(const char* val);

enum LP_Trigger_Slope_t {    /* Timer_Slope in QWAit:SLOPe, QWAit:SLOPe?, TIMer:SLOPe, TIMer:SLOPe?, TRIGger:SLOPe, TRIGger:SLOPe?, QWAit:SLOPe, QWAit:SLOPe?, TIMer:SLOPe, TIMer:SLOPe?, TRIGger:SLOPe, TRIGger:SLOPe? */
    LP_TRIG_SLOPE_POS,       /* POS,        Signal transition is rising edge */
    LP_TRIG_SLOPE_NEG,       /* NEG,        Signal transition is falling edge */ 
    MAX_TRIGGER_SLOPE
};
extern const char*           Trigger_SlopeToString(LP_Trigger_Slope_t val);
extern const char*           Trigger_SlopeToSCPI(LP_Trigger_Slope_t val);
extern LP_Trigger_Slope_t    ScpiToTrigger_Slope(const char* val);

enum LP_Trigger_Source_t {   /* Trigger_source in QWAit:SOURce, QWAit:SOURce?, TRIGger:SOURce, TRIGger:SOURce?, QWAit:SOURce, QWAit:SOURce?, TRIGger:SOURce, TRIGger:SOURce? */
    LP_TRIG_SRC_IMM,         /* IMM,        Triggers when armed */
    LP_TRIG_SRC_TIM,         /* TIM,        Triggers when the configured timer expiration occurs */
    LP_TRIG_SRC_VID,         /* VID,        Triggers when an RF signal transition of the configured slope, level, and gap time occurs at baseband */
    LP_TRIG_SRC_INT1,        /* INT1,        */
    LP_TRIG_SRC_INT2,        /* INT2,        */
    LP_TRIG_SRC_EXT1,        /* EXT1,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TRIG_SRC_EXT2,        /* EXT2,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TRIG_SRC_EXT3,        /* EXT3,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TRIG_SRC_EXT4,        /* EXT4,       Triggers when a signal transition of the configured slope occurs on the specified external line */
    LP_TRIG_SRC_RFD1,        /* RFD1,       Triggers when Wideband RF power threshold detection occurs on port RF1 */
    LP_TRIG_SRC_RFD2,        /* RFD2,       Triggers when Wideband RF power threshold detection occurs on port RF2 */
    LP_TRIG_SRC_RFD3,        /* RFD3,        */
    LP_TRIG_SRC_RFD4,        /* RFD4,        */
    LP_TRIG_SRC_RFDOR2,      /* RFDOR2,      */
    LP_TRIG_SRC_RFDOR3,      /* RFDOR3,      */
    LP_TRIG_SRC_RFDOR4,      /* RFDOR4,      */
    LP_TRIG_SRC_RFD1A,       /* RFD1A,       */
    LP_TRIG_SRC_RFD2A,       /* RFD2A,       */
    LP_TRIG_SRC_RFD3A,       /* RFD3A,       */
    LP_TRIG_SRC_RFD4A,       /* RFD4A,       */
    LP_TRIG_SRC_RFD1B,       /* RFD1B,       */
    LP_TRIG_SRC_RFD2B,       /* RFD2B,       */
    LP_TRIG_SRC_RFD3B,       /* RFD3B,       */
    LP_TRIG_SRC_RFD4B,       /* RFD4B,       */
    LP_TRIG_SRC_RFD1C,       /* RFD1C,       */
    LP_TRIG_SRC_RFD2C,       /* RFD2C,       */
    LP_TRIG_SRC_RFD3C,       /* RFD3C,       */
    LP_TRIG_SRC_RFD4C,       /* RFD4C,       */
    LP_TRIG_SRC_RFD1D,       /* RFD1D,       */
    LP_TRIG_SRC_RFD2D,       /* RFD2D,       */
    LP_TRIG_SRC_RFD3D,       /* RFD3D,       */
    LP_TRIG_SRC_RFD4D,       /* RFD4D,       */
    LP_TRIG_SRC_EXTOR,       /* EXTOR,       */
    LP_TRIG_SRC_RFDOR,       /* RFDOR,       */ 
    MAX_TRIGGER_SOURCE
};
extern const char*           Trigger_SourceToString(LP_Trigger_Source_t val);
extern const char*           Trigger_SourceToSCPI(LP_Trigger_Source_t val);
extern LP_Trigger_Source_t   ScpiToTrigger_Source(const char* val);

enum LP_Trigger_Type_t {     /* Trigger_type in QWAit:TYPE, QWAit:TYPE?, TRIGger:TYPE, TRIGger:TYPE?, QWAit:TYPE, QWAit:TYPE?, TRIGger:TYPE, TRIGger:TYPE? */
    LP_TRIGGER_TYPE_EDGE,    /* EDGE,       Edge trigger */
    LP_TRIGGER_TYPE_LEV,     /* LEV,        Level trigger */ 
    MAX_TRIGGER_TYPE
};
extern const char*           Trigger_TypeToString(LP_Trigger_Type_t val);
extern const char*           Trigger_TypeToSCPI(LP_Trigger_Type_t val);
extern LP_Trigger_Type_t     ScpiToTrigger_Type(const char* val);

enum LP_Uncompressed_BF_Report_Bits_t { /* Uncompressed_BF_Report_Bits in CONFigure:WAVE:PSDU:BFACtion:UNCompressed:NBITs, CONFigure:WAVE:PSDU:BFACtion:UNCompressed:NBITs? */
    LP_UNCOMP_BF_RB_BITS2,   /* BITS2,      2 Bits */
    LP_UNCOMP_BF_RB_BITS4,   /* BITS4,      4 Bits */
    LP_UNCOMP_BF_RB_BITS6,   /* BITS6,      6 Bits */
    LP_UNCOMP_BF_RB_BITS8,   /* BITS8,      8 Bits */ 
    MAX_UNCOMPRESSED_BF_REPORT_BITS
};
extern const char*           Uncompressed_BF_Report_BitsToString(LP_Uncompressed_BF_Report_Bits_t val);
extern const char*           Uncompressed_BF_Report_BitsToSCPI(LP_Uncompressed_BF_Report_Bits_t val);
extern LP_Uncompressed_BF_Report_Bits_t ScpiToUncompressed_BF_Report_Bits(const char* val);

enum LP_Unit_t {             /* Unit in CONFigure:RESampled:UNIT, CONFigure:RESampled:UNIT? */
    LP_NORM,                 /* NORM,       Normal; square root of milliwatts */
    LP_VOLT,                 /* VOLT,       Volt */ 
    MAX_UNIT
};
extern const char*           UnitToString(LP_Unit_t val);
extern const char*           UnitToSCPI(LP_Unit_t val);
extern LP_Unit_t             ScpiToUnit(const char* val);

enum LP_Virtual_instrument_t { /* Virtual_instrument in [SYSTem:]VI[:SELect], [SYSTem:]VI[:SELect]? */
    LP_VI_OFF,               /* OFF,        Virtual instrument off */
    LP_VI_VI1,               /* VI1,        Virtual instrument 1 */
    LP_VI_VI2,               /* VI2,        Virtual instrument 2 */
    LP_VI_VI3,               /* VI3,        Virtual instrument 3 */
    LP_VI_VI4,               /* VI4,        Virtual instrument 4 */
    LP_VI_VI5,               /* VI5,        Virtual instrument 5 */
    LP_VI_VI6,               /* VI6,        Virtual instrument 6 */
    LP_VI_VI7,               /* VI7,        Virtual instrument 7 */
    LP_VI_VI8,               /* VI8,        Virtual instrument 8 */ 
    MAX_VIRTUAL_INSTRUMENT
};
extern const char*           Virtual_instrumentToString(LP_Virtual_instrument_t val);
extern const char*           Virtual_instrumentToSCPI(LP_Virtual_instrument_t val);
extern LP_Virtual_instrument_t ScpiToVirtual_instrument(const char* val);

enum LP_WIFI_Band_t {        /* TGn_Band in WAVE:CHANnel:TGN:BAND, WAVE:CHANnel:TGN:BAND?, CONFigure[:CHANnel]:BAND, CONFigure[:CHANnel]:BAND? */
    LP_2G4,                  /* 2G4,        2.4 GHz Band */
    LP_5G,                   /* 5G,         5 GHz Band */ 
    MAX_WIFI_BAND
};
extern const char*           WIFI_BandToString(LP_WIFI_Band_t val);
extern const char*           WIFI_BandToSCPI(LP_WIFI_Band_t val);
extern LP_WIFI_Band_t        ScpiToWIFI_Band(const char* val);

enum LP_WiFi_Data_Rate_t {   /* WiFi_Data_Rate in CONFigure:WAVE:DSSS:DRATe, CONFigure:WAVE:DSSS:DRATe? */
    LP_RATE1,                /* RATE1,      Bit Rate 1 Mbps */
    LP_RATE2,                /* RATE2,      Bit Rate 2 Mbps */
    LP_RATE5_5,              /* RATE5_5,    Bit Rate 5.5 Mbps */
    LP_RATE11,               /* RATE11,     Bit Rate 11 Mbps */ 
    MAX_WIFI_DATA_RATE
};
extern const char*           WiFi_Data_RateToString(LP_WiFi_Data_Rate_t val);
extern const char*           WiFi_Data_RateToSCPI(LP_WiFi_Data_Rate_t val);
extern LP_WiFi_Data_Rate_t   ScpiToWiFi_Data_Rate(const char* val);

enum LP_WiFi_MAC_Frame_Contol_Mode_t { /* WiFi_MAC_Frame_Contol_Mode in CONFigure:WAVE:PSDU:MACHeader:FCONtrol:MODE, CONFigure:WAVE:PSDU:MACHeader:FCONtrol:MODE? */
    LP_WIFI_MODE_PRESET,     /* PRESET,     Preset Frame Control Type */
    LP_WIFI_MODE_USER,       /* USER,       User defined bits for Frame Control Field */ 
    MAX_WIFI_MAC_FRAME_CONTOL_MODE
};
extern const char*           WiFi_MAC_Frame_Contol_ModeToString(LP_WiFi_MAC_Frame_Contol_Mode_t val);
extern const char*           WiFi_MAC_Frame_Contol_ModeToSCPI(LP_WiFi_MAC_Frame_Contol_Mode_t val);
extern LP_WiFi_MAC_Frame_Contol_Mode_t ScpiToWiFi_MAC_Frame_Contol_Mode(const char* val);

enum LP_WiFi_MAC_Frame_Contol_Type_t { /* WiFi_MAC_Frame_Contol_Type in CONFigure:WAVE:PSDU:MACHeader:FCONtrol:TYPE, CONFigure:WAVE:PSDU:MACHeader:FCONtrol:TYPE? */
    LP_WIFI_TYPE_DATA,       /* DATA,       Data Packet */
    LP_WIFI_TYPE_ACK,        /* ACK,        ACK Packet */
    LP_WIFI_TYPE_RTS,        /* RTS,        RTS Packet */
    LP_WIFI_TYPE_CTS,        /* CTS,        CTS Packet */
    LP_WIFI_TYPE_BEACON,     /* BEACON,     Beacon Packet */
    LP_WIFI_TYPE_PROBE_RES,   /* PROBE_RES, Probe Response Packet */
    LP_WIFI_TYPE_NDPA,       /* NDPA,       NDP Announcement */
    LP_WIFI_TYPE_ACTION_NACK,   /* ACTION_NACK, Action No Ack */ 
    MAX_WIFI_MAC_FRAME_CONTOL_TYPE
};
extern const char*           WiFi_MAC_Frame_Contol_TypeToString(LP_WiFi_MAC_Frame_Contol_Type_t val);
extern const char*           WiFi_MAC_Frame_Contol_TypeToSCPI(LP_WiFi_MAC_Frame_Contol_Type_t val);
extern LP_WiFi_MAC_Frame_Contol_Type_t ScpiToWiFi_MAC_Frame_Contol_Type(const char* val);

enum LP_WiFi_OFDM_Standards_t { /* WiFi_OFDM_Standards in CONFigure:STANdard:OFDM, CONFigure:STANdard:OFDM? */
    LP_A_P_N_AC,             /* A_P_N_AC,   WiFi 802.11a/g/p/n/ac */
    LP_AF,                   /* AF,         WiFi 802.11af */
    LP_AH,                   /* AH,         WiFi 802.11ah */ 
    MAX_WIFI_OFDM_STANDARDS
};
extern const char*           WiFi_OFDM_StandardsToString(LP_WiFi_OFDM_Standards_t val);
extern const char*           WiFi_OFDM_StandardsToSCPI(LP_WiFi_OFDM_Standards_t val);
extern LP_WiFi_OFDM_Standards_t ScpiToWiFi_OFDM_Standards(const char* val);

enum LP_WiFi_Spatial_Mapping_Type_t { /* WiFi_Spatial_Mapping_Type in CONFigure:WAVE:OFDM:SMAPping:TYPE, CONFigure:WAVE:OFDM:SMAPping:TYPE? */
    LP_WIFI_NONE,            /* NONE,       No Spatial Mapping */
    LP_WIFI_COMMON,          /* COMMON,     Common Spatial mapping for all tones */
    LP_WIFI_TONES,           /* TONES,      Tone specific spatial mapping */ 
    MAX_WIFI_SPATIAL_MAPPING_TYPE
};
extern const char*           WiFi_Spatial_Mapping_TypeToString(LP_WiFi_Spatial_Mapping_Type_t val);
extern const char*           WiFi_Spatial_Mapping_TypeToSCPI(LP_WiFi_Spatial_Mapping_Type_t val);
extern LP_WiFi_Spatial_Mapping_Type_t ScpiToWiFi_Spatial_Mapping_Type(const char* val);

enum LP_WiFi_Standard_t {    /* WiFi_Standard in CONFigure:WAVE:STANdard, CONFigure:WAVE:STANdard? */
    LP_WIFI_B,               /* B,          WiFi 802.11b */
    LP_WIFI_A,               /* A,          WiFi 802.11a/g */
    LP_WIFI_N,               /* N,          WiFi 802.11n */
    LP_WIFI_AC,              /* AC,         WiFi 802.11ac */
    LP_WIFI_P,               /* P,          WiFi 802.11p */
    LP_WIFI_AF,              /* AF,         WiFi 802.11af */
    LP_WIFI_AH,              /* AH,         WiFi 802.11ah */ 
    MAX_WIFI_STANDARD
};
extern const char*           WiFi_StandardToString(LP_WiFi_Standard_t val);
extern const char*           WiFi_StandardToSCPI(LP_WiFi_Standard_t val);
extern LP_WiFi_Standard_t    ScpiToWiFi_Standard(const char* val);

enum LP_WiFi_Standards_Family_t { /* WiFi_Standards_Family in CONFigure:STANdard, CONFigure:STANdard? */
    LP_DSSS,                 /* DSSS,       WiFi 802.11b */
    LP_OFDM,                 /* OFDM,       WiFi 802.11a/g/p/n/ac/af */ 
    MAX_WIFI_STANDARDS_FAMILY
};
extern const char*           WiFi_Standards_FamilyToString(LP_WiFi_Standards_Family_t val);
extern const char*           WiFi_Standards_FamilyToSCPI(LP_WiFi_Standards_Family_t val);
extern LP_WiFi_Standards_Family_t ScpiToWiFi_Standards_Family(const char* val);

enum LP_Window_Type_t {      /* Window_Type in CONFigure:SPECtrum:WINDow, CONFigure:SPECtrum:WINDow?, CONFigure:WAVE:OFDM:WINDow, CONFigure:WAVE:OFDM:WINDow? */
    LP_WINDOW_TYPE_NONE,     /* NONE,       No window */
    LP_WINDOW_TYPE_RRC,      /* RRC,        Root raised cosine window */
    LP_WINDOW_TYPE_LINEAR,   /* LINEAR,     Linear window */
    LP_WINDOW_TYPE_GAUSS,    /* GAUSS,      Gaussian Window */
    LP_WINDOW_TYPE_FLATTOP,   /* FLATTOP,   Flattop Window */
    LP_WINDOW_TYPE_HAMMING,   /* HAMMING,   Hamming Window */
    LP_WINDOW_TYPE_HANN,     /* HANN,       Hann Window */
    LP_WINDOW_TYPE_BLACKMANHARRIS,   /* BLACKMANHARRIS, BLACKMANHARRIS Window */ 
    MAX_WINDOW_TYPE
};
extern const char*           Window_TypeToString(LP_Window_Type_t val);
extern const char*           Window_TypeToSCPI(LP_Window_Type_t val);
extern LP_Window_Type_t      ScpiToWindow_Type(const char* val);

enum LP_transmit_filter_type_t { /* transmit_filter_type in CONFigure:WAVE:DSSS:FILTer:TYPE, CONFigure:WAVE:DSSS:FILTer:TYPE? */
    LP_TRANSMIT_FILTER_TYPE_RC,   /* RC,    Raised Cosine Filter */
    LP_TRANSMIT_FILTER_TYPE_RRC,   /* RRC,  Root Raised Cosine Filter */
    LP_TRANSMIT_FILTER_TYPE_GAUSS,   /* GAUSS, Gaussian Filter */
    LP_TRANSMIT_FILTER_TYPE_GAUSS_RECT,   /* GAUSS_RECT, Gaussian Rectangular Filter */
    LP_TRANSMIT_FILTER_TYPE_USER,   /* USER, User Defined Filter */ 
    MAX_TRANSMIT_FILTER_TYPE
};
extern const char*           transmit_filter_typeToString(LP_transmit_filter_type_t val);
extern const char*           transmit_filter_typeToSCPI(LP_transmit_filter_type_t val);
extern LP_transmit_filter_type_t ScpiTotransmit_filter_type(const char* val);



#ifdef __cplusplus
}
#endif
#endif 
