/*
  Litepoint Instrument Driver
  (C) Litepoint 2011, All rights reserved
*/
#ifndef LP_DOTNET_DRIVER_ENUMS_H
#define LP_DOTNET_DRIVER_ENUMS_H

namespace LP {
 
public enum class ALC_Source : int
{
    INTINT,                  // Internal feedback
    ALC_SOURCE_NONE
};

public enum class ALC_State : int
{
    SING,                    // One correction cycle and hold 
    AUT,                     // Continuous periodic correction cycles 
    OFF,                     // No correction cycles
    ALC_STATE_NONE
};

public enum class BT_Data_Rate : int
{
    AUTO,                    // BT Data Rate Auto Detect 
    LP_1MBPS,                // BT Data Rate 1Mbps 
    LP_2MBPS,                // BT Data Rate 2Mbps 
    LP_3MBPS,                // BT Data Rate 3Mbps 
    LEN,                     // BT Low Energy
    BT_DATA_RATE_NONE
};

public enum class Bit_Pattern_Type : int
{
    ALL0,                    // data content: all 0 
    ALL1,                    // data content: all 1 
    PN9,                     // data content: PN9
    BIT_PATTERN_TYPE_NONE
};

public enum class CDMA2K_CCD_Type : int
{
    AUTO,                    // Auto detection 
    MAN,                     // Manual detection
    CDMA2K_CCD_TYPE_NONE
};

public enum class CDMA2K_Conf : int
{
    IS2KRC1RC2,              // IS2000 Radio Configuration 1 and 2 
    IS2KRC3RC4,              // IS2000 Radio Configuration 3 and 4 
    IS2000,                  // IS2000 
    EVDO0,                   // EVDO Rev 0 
    EVDOA,                   // EVDO Rev A 
    EVDOB,                   // EVDO Rev B
    CDMA2K_CONF_NONE
};

public enum class CDMA2K_Data_Rate : int
{
    FULL_RATE,               // Full Rate 
    HALF_RATE,               // Half Rate 
    QUARTER_RATE,            // Quarter Rate 
    EIGTH_RATE,              // Eigth Rate
    CDMA2K_DATA_RATE_NONE
};

public enum class CDMA2K_Filter_Type : int
{
    NONE,                    // No Filtering 
    BW1M,                    // 1.23MHz CDMA filter 
    BW2M,                    // 2MHz RRC filter 
    BW4M,                    // 4MHz RRC filter 
    BW8M,                    // 8MHz RRC filter 
    BW10M,                   // 10MHz RRC filter
    CDMA2K_FILTER_TYPE_NONE
};

public enum class CDMA2K_RPC_Type : int
{
    ALL0,                    // CDMA2K/EVDO All Up 
    ALL1,                    // CDMA2K/EVDO All Down 
    ALT01,                   // CDMA2K/EVDO All Down 
    ALT10,                   // CDMA2K/EVDO All Down 
    USER_DEF,                // CDMA2K/EVDO USER DEFINED
    CDMA2K_RPC_TYPE_NONE
};

public enum class CDMA2K_Time_HW_Timemode : int
{
    MAN,                     // Manual mode 
    TRAC,                    // Tracking mode
    CDMA2K_TIME_HW_TIMEMODE_NONE
};

public enum class Channel_Estimation_Type : int
{
    LTF,                     // Long Training Field 
    DATA,                    // Data Part
    CHANNEL_ESTIMATION_TYPE_NONE
};

public enum class Channel : int
{
    CHAN1,                   // Measurement CHAN1 
    CHAN2,                   // Measurement CHAN2 
    CHAN3,                   // Measurement CHAN3 
    CHAN4,                   // Measurement CHAN4 
    CHAN5,                   // Measurement CHAN5 
    CHAN6,                   // Measurement CHAN6 
    CHAN7,                   // Measurement CHAN7 
    CHAN8,                   // Measurement CHAN8 
    CHAN9,                   // Measurement CHAN9 
    CHAN10,                  // Measurement CHAN10
    CHANNEL_NONE
};

public enum class Clear_capture_memory_mode : int
{
    OFF,                     // Disable clear capture memory mode 
    ON,                      // Enable clear capture memory mode 
    PASS,                    // Enable clear capture memory mode for successful calculations only
    CLEAR_CAPTURE_MEMORY_MODE_NONE
};

public enum class Coupling_Mode : int
{
    AC,                      // AC mode 
    DC,                      // DC mode
    COUPLING_MODE_NONE
};

public enum class Data_Byte_Order : int
{
    NORM,                    // Output byte order is little-endian format 
    SWAP,                    // Output byte order is big-endian format
    DATA_BYTE_ORDER_NONE
};

public enum class Data_Format : int
{
    ASC,                     // Output data is ASCII format 
    NR3,                     // Output data is ASCII exponential notation format 
    PACK,                    // Output data is binary number array format
    DATA_FORMAT_NONE
};

public enum class Downlink_Type : int
{
    WCDMA,                   // Downlink signal of WCDMA 
    HSDPA,                   // Downlink signal of HSDPA 
    HSUPA,                   // Downlink signal of HSUPA 
    HSPA,                    // Downlink signal of HSDPA and HSUPA 
    HSPAPLUS,                // Downlink signal of HSPA plus 
    DCHSDPA,                 // Downlink signal of DC-HSDPA
    DOWNLINK_TYPE_NONE
};

public enum class EDR_Roll_Off : int
{
    LP_30PCT,                // Mod Index 0.3 
    LP_35PCT,                // Mod Index 0.35 
    LP_40PCT,                // Mod Index 0.4 
    LP_45PCT,                // Mod Index 0.45 
    LP_50PCT,                // Mod Index 0.5
    EDR_ROLL_OFF_NONE
};

public enum class EVM_METHOD : int
{
    STANDARD,                // EVM Method Standard 
    RMS,                     // EVM Method RMS
    EVM_METHOD_NONE
};

public enum class Frequency_Correction_Type : int
{
    LTF,                     // Long Training Field 
    DATA,                    // Whole Packet 
    SIG,                     // Long Training Field and Signaling Fields
    FREQUENCY_CORRECTION_TYPE_NONE
};

public enum class GPRF_POWER : int
{
    NONE,                    //  
    GAUSS,                   //  
    RRC,                     //
    GPRF_POWER_NONE
};

public enum class GSM_Filter_Type : int
{
    NONE,                    // No filter 
    GAUSS500K,               // Gaussian filter with 500 kHz bandwidth 
    GAUSS1M,                 // Gaussian filter with 1 MHz bandwidth
    GSM_FILTER_TYPE_NONE
};

public enum class GSM_Slot_Burst_Type : int
{
    GMSK,                    // GMSK Normal Burst 
    LP_8PSK,                 // 8PSK Normal Burst 
    ACC,                     // Access Burst 
    DUMM,                    // Dummy Burst 
    FCOR,                    // Frequency Correction Burst 
    SYNC,                    // Synchronization Burst 
    ANY,                     // Any type of burst
    GSM_SLOT_BURST_TYPE_NONE
};

public enum class GSM_Training_Seq_Type : int
{
    TSC0,                    // Training Sequence 0 for Normal Bursts 
    TSC1,                    // Training Sequence 1 for Normal Bursts 
    TSC2,                    // Training Sequence 2 for Normal Bursts 
    TSC3,                    // Training Sequence 3 for Normal Bursts 
    TSC4,                    // Training Sequence 4 for Normal Bursts 
    TSC5,                    // Training Sequence 5 for Normal Bursts 
    TSC6,                    // Training Sequence 6 for Normal Bursts 
    TSC7,                    // Training Sequence 7 for Normal Bursts 
    TS0,                     // Training Sequence 0 for Access Bursts 
    TS1,                     // Training Sequence 1 for Access Bursts 
    TS2,                     // Training Sequence 2 for Access Bursts 
    STAN,                    // Standard Training Sequence for Frequency Correction Bursts and Synchronization Bursts
    GSM_TRAINING_SEQ_TYPE_NONE
};

public enum class IF_BW : int
{
    LP_1150KHZ,              // BT IF BW 1.15MHz 
    LP_1300KHZ,              // BT IF BW 1.3MHz 
    LP_1450KHZ,              // BT IF BW 1.45MHz 
    LP_1600KHZ,              // BT IF BW 1.6MHz 
    LP_2000KHZ,              // BT IF BW 2.0MHz
    IF_BW_NONE
};

public enum class LTE_Modulation_Type : int
{
    AUTO,                    //  
    QPSK,                    //  
    LP_16QAM,                //  
    LP_64QAM,                //
    LTE_MODULATION_TYPE_NONE
};

public enum class LTE_Sync_Algorithm : int
{
    FAST,                    //  
    STAN,                    //
    LTE_SYNC_ALGORITHM_NONE
};

public enum class LTE_Synchronization_Method : int
{
    CORR,                    //  
    FFTF,                    //  
    AUTO,                    //
    LTE_SYNCHRONIZATION_METHOD_NONE
};

public enum class Marker_Type : int
{
    DET,                     //  
    VAL,                     // Valid trigger detection 
    VID,                     // Signal detection above threshold and immediately following configured gap 
    TIM,                     // Timer expiration 
    SWM,                     // Software marker 
    VSGM,                    // Start of a waveform. Repeats with the repeat of waveform. 
    VSGD,                    // End of a waveform 
    VSAD,                    // Capture is complete 
    RFD1,                    // Wideband RF power threshold detection on port RF1 
    RFD2,                    // Wideband RF power threshold detection on port RF2 
    RFD3,                    // Wideband RF power threshold detection on port RF3 
    RFD4,                    // Wideband RF power threshold detection on port RF4 
    WSM1,                    // Programmable marker in wave segment. Repeats with the repeat of wave segment. 
    WSM2,                    // Programmable marker in wave segment. Repeats with the repeat of wave segment. 
    OFF,                     // Power is set off 
    AOFF,                    //  
    HIGH,                    // Marker is set high 
    LOW,                     // Marker is set low 
    PWM,                     // Pulse Width Modulated signal of the specified duty cycle synchronized with the 10 MHz reference 
    LP_10MH,                 // 10MHz reference 
    INP,                     // Digital I/O is set to input
    MARKER_TYPE_NONE
};

public enum class Meas_Period_C2K : int
{
    FULLSLOT,                // Full Slot 
    HALFSLOT,                // First Half Slot
    MEAS_PERIOD_C2K_NONE
};

public enum class Meas_Period : int
{
    FULLSLOT,                // Measure over the entire time slot 
    HALFSLOT1,               // Measure over the first half of the time slot 
    HALFSLOT2,               // Measure over the second half of the time slot
    MEAS_PERIOD_NONE
};

public enum class Module : int
{
    SYS,                     //  
    VSG1,                    //  
    VSG2,                    //  
    VSA1,                    //  
    VSA2,                    //  
    ROUT1,                   //  
    ROUT2,                   //  
    BP,                      //  
    GSM,                     //  
    WCDMA,                   //  
    CDMA2K,                  //  
    LTE,                     //  
    GPRF,                    //  
    BT,                      //  
    WIFI,                    //
    MODULE_NONE
};

public enum class Number_of_Equilizer_Taps : int
{
    OFF,                     // Equalizer Taps Off 
    TAP5,                    // Equalizer Taps = 5 
    TAP7,                    // Equalizer Taps = 7 
    TAP9,                    // Equalizer Taps = 9
    NUMBER_OF_EQUILIZER_TAPS_NONE
};

public enum class OCNS_type : int
{
    OCNS16,                  // OCNS defined in release 99 
    OCNS6,                   // OCNS for HSDPA 
    OCNS1,                   // OCNS for HSDPA FRC 8 9 10 11
    OCNS_TYPE_NONE
};

public enum class PHICH_duration_type_Normal_or_Extended : int
{
    NORMAL,                  // Normal PHICH Duration type 
    EXTENDED,                // Extended PHICH Duration type
    PHICH_DURATION_TYPE_NORMAL_OR_EXTENDED_NONE
};

public enum class PSDU_Setting : int
{
    USER_CRC,                // User Defined Bits with CRC 
    USER_NOCRC,              // User Defined Bits without CRC 
    DEFAULT,                 // Random bits. 
    RANDOM,                  // Random Bits
    PSDU_SETTING_NONE
};

public enum class Packet_Format : int
{
    AUTO,                    //  
    MIX,                     // Mixed Mode 
    GRE,                     // Greenfield
    PACKET_FORMAT_NONE
};

public enum class Packet_Type : int
{
    ID,                      // Packet Type ID 
    NULL,                    // Packet Type NULL 
    POLL,                    // Packet Type POLL 
    DM1,                     // Packet Type DM1 
    DH1,                     // Packet Type DH1 
    DM3,                     // Packet Type DM3 
    DH3,                     // Packet Type DH3 
    DM5,                     // Packet Type DM5 
    DH5,                     // Packet Type DH5 
    AUX1,                    // Packet Type AUX1 
    LP_2DH1,                 // Packet Type 2DH1 
    LP_2DH3,                 // Packet Type 2DH3 
    LP_2DH5,                 // Packet Type 2DH5 
    LP_3DH1,                 // Packet Type 3DH1 
    LP_3DH3,                 // Packet Type 3DH3 
    LP_3DH5,                 // Packet Type 3DH5 
    LE,                      // Packet Type Low Energy
    PACKET_TYPE_NONE
};

public enum class Payload_Type : int
{
    ALT10,                   // Alternating 1 0 
    ALL1,                    // All 1 
    ALL0,                    // All 0 
    FOUR1FOUR0,              // 11110000 
    USER,                    // User defined 
    RANDOM,                  // PRBS9
    PAYLOAD_TYPE_NONE
};

public enum class Port_Name : int
{
    STRM1A,                  //  
    RF1A,                    //  
    RF2A,                    //  
    RF3A,                    //  
    RF4A,                    //  
    STRM1B,                  //  
    RF1B,                    //  
    RF2B,                    //  
    RF3B,                    //  
    RF4B,                    //
    PORT_NAME_NONE
};

public enum class Port : int
{
    VSG1,                    //  
    VSG2,                    //  
    VSA1,                    //  
    VSA2,                    //  
    OFF,                     //
    PORT_NONE
};

public enum class Preamble_Setting : int
{
    OFF,                     // Preamble OFF 
    SHORT,                   // Short Preamble 
    LONG,                    // Long Preamble
    PREAMBLE_SETTING_NONE
};

public enum class Reference_Oscillator : int
{
    INT,                     // Reference oscillator is internally generated 
    EXT,                     // Reference oscillator is externally supplied
    REFERENCE_OSCILLATOR_NONE
};

public enum class SLOT2 : int
{
    FULLSLOT,                // Full Slot 
    FHSLOT,                  // First Half Slot 
    SHSLOT,                  // Second Half Slot
    SLOT2_NONE
};

public enum class TPC_Pattern_Type : int
{
    ALL1,                    // TPC command: all 1 
    ALL0,                    // TPC command: all 0 
    ALT01,                   // TPC command: repeating of 01 
    ALT10,                   // TPC command: repeating of 10 
    PALT,                    // TPC command: user specified TPC pattern followed by repeating of 01 or 10 
    PAL1,                    // TPC command: user specified TPC pattern followed by all 1 
    PAL0,                    // TPC command: user specified TPC pattern followed by all 0 
    PCON,                    // TPC command: repeat user specified TPC pattern 
    SPAB,                    // TPC pattern used for inner loop power control step ABC 
    SPEF,                    // TPC pattern used for inner loop power control step EF 
    SPGH,                    // TPC pattern used for inner loop power control step GH
    TPC_PATTERN_TYPE_NONE
};

public enum class Timer_Source : int
{
    IMM,                     // Triggers when armed 
    TIM,                     // Triggers when the configured timer expiration occurs 
    VID,                     // Triggers when an RF signal transition of the configured slope, level, and gap time occurs at baseband 
    EXT1,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT2,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT3,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT4,                    // Triggers when a signal transition of the configured slope occurs on the specified external line
    TIMER_SOURCE_NONE
};

public enum class Transport_Type : int
{
    RMC12P2,                 // Downlink RMC with data rate of 12.2 kbps 
    RMC64,                   // Downlink RMC with data rate of 64 kbps 
    RMC144,                  // Downlink RMC with data rate of 144 kbps 
    RMC384,                  // Downlink RMC with data rate of 384 kbps
    TRANSPORT_TYPE_NONE
};

public enum class Trigger_Mode : int
{
    SSH,                     // Generates a single trigger when the configured trigger event occurs 
    MSH,                     // Generates a trigger every time the configured trigger event occurs 
    MPAC,                    // Generates a trigger every time the configured packet event occurs
    TRIGGER_MODE_NONE
};

public enum class Trigger_Slope : int
{
    POS,                     // Signal transition is rising edge 
    NEG,                     // Signal transition is falling edge
    TRIGGER_SLOPE_NONE
};

public enum class Trigger_Source : int
{
    IMM,                     // Triggers when armed 
    TIM,                     // Triggers when the configured timer expiration occurs 
    VID,                     // Triggers when an RF signal transition of the configured slope, level, and gap time occurs at baseband 
    INT1,                    //  
    INT2,                    //  
    EXT1,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT2,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT3,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    EXT4,                    // Triggers when a signal transition of the configured slope occurs on the specified external line 
    RFD1,                    // Triggers when Wideband RF power threshold detection occurs on port RF1 
    RFD2,                    // Triggers when Wideband RF power threshold detection occurs on port RF2 
    RFD3,                    // Triggers when Wideband RF power threshold detection occurs on port RF3 
    RFD4,                    // Triggers when Wideband RF power threshold detection occurs on port RF4
    TRIGGER_SOURCE_NONE
};

public enum class Trigger_Type : int
{
    EDGE,                    // Edge trigger 
    LEV,                     // Level trigger
    TRIGGER_TYPE_NONE
};

public enum class Unscheduled_subframe : int
{
    DUMMY,                   // Dummy subframe 
    DTX,                     // Discontinuous transmission (DTX) subframe
    UNSCHEDULED_SUBFRAME_NONE
};

public enum class Uplink_Type : int
{
    WCDMA,                   // Uplink signals of WCDMA 
    HSDPA,                   // Uplink signals of HSDPA 
    HSUPA,                   // Uplink signals of HSUPA 
    HSPA,                    // Uplink signals of HSDPA and HSUPA 
    HSPAPLUS,                // Uplink signals of HSPA plus
    UPLINK_TYPE_NONE
};

public enum class WCDMA_Buffer_All_Type : int
{
    IMPLICIT,                // IMPLICIT buffer allocation 
    EXPLICIT,                // EXPLICIT buffer allocation
    WCDMA_BUFFER_ALL_TYPE_NONE
};

public enum class WCDMA_EDPDCH_Modulation_Type : int
{
    BPSK,                    // Modulation of BPSK 
    LP_4PAM,                 // Modulation of 4PAM
    WCDMA_EDPDCH_MODULATION_TYPE_NONE
};

public enum class WCDMA_FRC_Type : int
{
    H1QPSK,                  // Downlink Fixed Reference Channel H-SET 1: QPSK 
    H1QAM16,                 // Downlink Fixed Reference Channel H-SET 1: 16QAM 
    H2QPSK,                  // Downlink Fixed Reference Channel H-SET 2: QPSK 
    H2QAM16,                 // Downlink Fixed Reference Channel H-SET 2: 16QAM 
    H3QPSK,                  // Downlink Fixed Reference Channel H-SET 3: QPSK 
    H3QAM16,                 // Downlink Fixed Reference Channel H-SET 3: 16QAM 
    H4QPSK,                  // Downlink Fixed Reference Channel H-SET 4: QPSK 
    H5QPSK,                  // Downlink Fixed Reference Channel H-SET 5: QPSK 
    H6QPSK,                  // Downlink Fixed Reference Channel H-SET 6: QPSK 
    H6QAM16,                 // Downlink Fixed Reference Channel H-SET 6: 16QAM 
    H7QPSK,                  // Downlink Fixed Reference Channel H-SET 7: QPSK 
    H8QAM64,                 // Downlink Fixed Reference Channel H-SET 8: 64QAM 
    H9QAM16QPSK,             // Downlink Fixed Reference Channel H-SET 9: 16QAM/QPSK 
    H10QPSK,                 // Downlink Fixed Reference Channel H-SET 10: QPSK 
    H10QAM16,                // Downlink Fixed Reference Channel H-SET 10: 16QAM 
    H11QAM64QAM16,           // Downlink Fixed Reference Channel H-SET 11: 64QAM/16QAM 
    H12QPSK,                 // Downlink Fixed Reference Channel H-SET 12: QPSK
    WCDMA_FRC_TYPE_NONE
};

public enum class WCDMA_Filter_Type : int
{
    RRC,                     // Root Raised Cosine filter with bandwidth of 3.8 MHz 
    NONE,                    // No filtering 
    LPF,                     // Low Pass Filter with bandwidth 6.0 MHz 
    RRCBW63,                 // Root Raised Cosine filter with bandwidth of 6.3 MHz
    WCDMA_FILTER_TYPE_NONE
};

public enum class WCDMA_Slot_Number : int
{
    SLOT0,                   // Slot 0 
    SLOT1,                   // Slot 1 
    SLOT2,                   // Slot 2 
    SLOT3,                   // Slot 3 
    SLOT4,                   // Slot 4 
    SLOT5,                   // Slot 5 
    SLOT6,                   // Slot 6 
    SLOT7,                   // Slot 7 
    SLOT8,                   // Slot 8 
    SLOT9,                   // Slot 9 
    SLOT10,                  // Slot 10 
    SLOT11,                  // Slot 11 
    SLOT12,                  // Slot 12 
    SLOT13,                  // Slot 13 
    SLOT14,                  // Slot14 
    ANY,                     // Any slot
    WCDMA_SLOT_NUMBER_NONE
};

public enum class WCDMA_TPC_mode_Type : int
{
    A1S1,                    // Algorithm 1 with 1 dB step 
    A1S2,                    // Algorithm 1 with 2 dB step 
    A2S1,                    // Algorithm 2 with 1 dB step
    WCDMA_TPC_MODE_TYPE_NONE
};

public enum class WiFi_Standard : int
{
    B,                       // WiFi 802.11b 
    N,                       // WiFi 802.11a/g/n 
    AC,                      // WiFi 802.11a/g/n/ac
    WIFI_STANDARD_NONE
};

public enum class Wifi_Data_Rate : int
{
    RATE1,                   // Bit Rate 1 Mbps 
    RATE2,                   // Bit Rate 2 Mbps 
    RATE5_5,                 // Bit Rate 5.5 Mbps 
    RATE11,                  // Bit Rate 11 Mbps
    WIFI_DATA_RATE_NONE
};



} // end namespace LP

#endif 
