/*
  Litepoint Instrument Driver
  (C) Litepoint 2011, All rights reserved
*/
#include "LP_driver_enums.h"

#ifdef __cplusplus
extern "C" {
#endif

LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Phase_Interval(int session, double Start_Offset, unsigned int Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Power(int session, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Power_Interval(int session, double Start_Offset, unsigned int Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Resampled(int session, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Spectrum(int session, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Txquality(int session, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Phase_Interval(int session, unsigned int segment, double Start_Offset, unsigned int Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Power(int session, unsigned int segment, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Power_Interval(int session, unsigned int segment, double Start_Offset, unsigned int Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Resampled(int session, unsigned int segment, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Spectrum(int session, unsigned int segment, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Calculate_Segment_Txquality(int session, unsigned int segment, double Start_Offset, double Length);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_All      (int session);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_Phase    (int session);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_Power    (int session);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_Resampled(int session);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_Spectrum (int session);
LP_DRIVER_API int __cdecl LP_GPRF_Clear_Txquality(int session);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Phase_Fecompensate_Set(int session, enum LP_Boolean_t Frequency_Error_Compensation);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Phase_Fecompensate_Get(int session, enum LP_Boolean_t *Frequency_Error_Compensation);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Phase_Felimit_Set(int session, double Frequency_Estimation_Limit);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Phase_Felimit_Get(int session, double *Frequency_Estimation_Limit);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Power_Icount_Set(int session, unsigned int Number_of_Intervals);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Power_Icount_Get(int session, unsigned int *Number_of_Intervals);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Fbw_Set(int session, int Filter_Bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Fbw_Get(int session, int *Filter_Bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Filter_Set(int session, enum LP_GPRF_POWER_t Filter_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Filter_Get(int session, enum LP_GPRF_POWER_t *Filter_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Flength_Set(int session, enum LP_Filter_Length_Selection_Mode_t Filter_Length_Selection_Mode);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Flength_User_Set(int session, unsigned int Filter_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Flength_User_Get(int session, unsigned int *Filter_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Flength_Get(int session, enum LP_Filter_Length_Selection_Mode_t *Filter_Length_Selection_Mode);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Fofrequency_Set(int session, int Filter_Offset_Frequency);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Fofrequency_Get(int session, int *Filter_Offset_Frequency);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Frolloff_Set(int session, double RRC_Filter_Roll_Off);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Frolloff_Get(int session, double *RRC_Filter_Roll_Off);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Ilength_Set(int session, double Interval_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Ilength_Get(int session, double *Interval_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Mlength_Set(int session, double Measurement_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Mlength_Get(int session, double *Measurement_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Resampled_Unit_Set(int session, enum LP_Unit_t Unit);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Resampled_Unit_Get(int session, enum LP_Unit_t *Unit);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Npeaks_Set(int session, unsigned int Number_of_Peaks);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Npeaks_Get(int session, unsigned int *Number_of_Peaks);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Rbw_Set(int session, int RBW);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Rbw_Get(int session, int *RBW);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Signal_Set(int session, enum LP_Signal_Type_t Signal_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Signal_Get(int session, enum LP_Signal_Type_t *Signal_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Window_Set(int session, enum LP_Window_Type_t Window_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Spectrum_Window_Get(int session, enum LP_Window_Type_t *Window_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Txquality_Flength_Set(int session, unsigned int GPRF_TXQ_Filter_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Txquality_Flength_Get(int session, unsigned int *GPRF_TXQ_Filter_Length);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Txquality_Frolloff_Set(int session, double TXQ_RRC_Filter_Rolloff);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Txquality_Frolloff_Get(int session, double *TXQ_RRC_Filter_Rolloff);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Wave_Cwave_Normalize_Set(int session, enum LP_Boolean_t CW_Power_Normalization);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Wave_Cwave_Normalize_Get(int session, enum LP_Boolean_t *CW_Power_Normalization);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Wave_Cwave_Ofrequency_Get(int session, unsigned int max_items, int CW_Offset_Frequency[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Wave_Cwave_Rpower_Set(int session, unsigned num_values, double CW_Power_Level[]);
LP_DRIVER_API int __cdecl LP_GPRF_Configure_Wave_Cwave_Rpower_Get(int session, unsigned int max_items, int CW_Power_Level[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Ferror(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Frequency_Error[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Noise_Average(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Average_Phase_Noise_RMS[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Noise(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Phase_Noise_RMS[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Scount(int session, unsigned int segment, unsigned int max_items, int Status_Code[], unsigned int Statistical_Count[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Average(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Average_Phase[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Maximum(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Maximum_Phase[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Minimum(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Minimum_Phase[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase_Sdeviation(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Std_of_Phase[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Phase(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Phase[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Peak(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Peak_Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Scount(int session, unsigned int segment, unsigned int max_items, int Status_Code[], unsigned int Statistical_Count[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Average(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Average_Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Maximum(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Maximum_Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Minimum(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Minimum_Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power_Sdeviation(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Std_of_Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Power(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Power[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Resampled(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Resampled_Data[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Spectrum_Ofrequency(int session, unsigned int segment, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Offset_Frequencies[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Spectrum_Peak_Ofrequency(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Spectrum_Peak_Offset_Frequency[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Spectrum_Peak(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Spectrum_Peak[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Fetch_Segment_Spectrum(int session, unsigned int segment, unsigned int signal, unsigned int instance, unsigned int number_of_slots, unsigned int number_of_points[], int Status_Code[], float *Spectrum[], unsigned int actual_size[], unsigned int *actual_slots);
LP_DRIVER_API int __cdecl LP_GPRF_Mrcl           (int session, unsigned int Register_Location);
LP_DRIVER_API int __cdecl LP_GPRF_Mrst           (int session);
LP_DRIVER_API int __cdecl LP_GPRF_Msav           (int session, unsigned int Register_Location);
LP_DRIVER_API int __cdecl LP_GPRF_Msds           (int session, unsigned int Register_Location);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Apply(int session, const char* Output_Filename, const char* Input_Filename);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Band_Set(int session, enum LP_WIFI_Band_t TGn_Band);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Band_Get(int session, enum LP_WIFI_Band_t *TGn_Band);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Doppler_Set(int session, double TGn_Doppler_Frequency);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Doppler_Get(int session, double *TGn_Doppler_Frequency);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Losight_Set(int session, enum LP_Boolean_t TGn_Line_Of_Sight);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Losight_Get(int session, enum LP_Boolean_t *TGn_Line_Of_Sight);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Model_Set(int session, enum LP_TGn_Channel_Model_t TGn_Channel_Model);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Model_Get(int session, enum LP_TGn_Channel_Model_t *TGn_Channel_Model);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Rxaspacing_Set(int session, double TGn_Rx_Antenna_Spacing);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Rxaspacing_Get(int session, double *TGn_Rx_Antenna_Spacing);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Tradelta_Set(int session, int TGn_Tx_Rx_Antenna_Delta);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Tradelta_Get(int session, int *TGn_Tx_Rx_Antenna_Delta);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Txaspacing_Set(int session, double TGn_Tx_Antenna_Spacing);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Txaspacing_Get(int session, double *TGn_Tx_Antenna_Spacing);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Tgn_Version_Get(int session, unsigned int max_items, int Status_Code[], unsigned int TGn_Version[], unsigned int Min_TGn_Version[], unsigned int Max_TGn_Version[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Channel_Type_Get(int session, enum LP_Channel_Type_t *Channel_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Concatenate(int session, const char* Output_File_Name, const char* Input_File_Name_1, const char* Input_File_Name_2, const char* Input_File_Name_3, const char* Input_File_Name_4, const char* Input_File_Name_5, const char* Input_File_Name_6, const char* Input_File_Name_7, const char* Input_File_Name_8, const char* optional_Input_File_Name_9);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Apply(int session, const char* Output_File_Name, const char* Input_File_Name);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Awgn_Sbw_Set(int session, int Signal_bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Awgn_Sbw_Get(int session, int *Signal_bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Awgn_Snr_Set(int session, unsigned num_values, double SNR[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Awgn_Snr_Get(int session, unsigned int max_items, double SNR[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Fnormalize_Set(int session, enum LP_Boolean_t Filter_normalization);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Fnormalize_Get(int session, enum LP_Boolean_t *Filter_normalization);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Gain_Set(int session, unsigned num_values, double Channel_gain[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Gain_Get(int session, unsigned int max_items, double Channel_gain[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Phase_Set(int session, unsigned num_values, double Channel_phase[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Channel_Phase_Get(int session, unsigned int max_items, double Channel_phase[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Dci_Set(int session, unsigned num_values, double DC_Offset_I[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Dci_Get(int session, unsigned int max_items, double DC_Offset_I[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Dcq_Set(int session, unsigned num_values, double DC_Offset_Q[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Dcq_Get(int session, unsigned int max_items, double DC_Offset_Q[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Frequency_Set(int session, int Frequency_Error);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Frequency_Get(int session, int *Frequency_Error);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Iqgain_Set(int session, unsigned num_values, double IQ_Gain[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Iqgain_Get(int session, unsigned int max_items, double IQ_Gain[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Iqphase_Set(int session, unsigned num_values, double IQ_Phase[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Iqphase_Get(int session, unsigned int max_items, double IQ_Phase[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Nlinear_Backoff_Set(int session, unsigned num_values, double Back_Off[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Nlinear_Backoff_Get(int session, unsigned int max_items, double Smoothness_Factor[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Nlinear_Sfactor_Set(int session, unsigned num_values, double Smoothness_Factor[]);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Nlinear_Sfactor_Get(int session, unsigned int max_items, int Smoothness_Factor[], unsigned int *actual_items);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Pnoise_Set(int session, double Phase_Noise);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Pnoise_Bw_Set(int session, int PLL_Bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Pnoise_Bw_Get(int session, int *PLL_Bandwidth);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Pnoise_Get(int session, double *Phase_Noise);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Sclock_Set(int session, double Symbol_Clock_Error);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Sclock_Get(int session, double *Symbol_Clock_Error);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Seed_Set(int session, enum LP_Seed_Type_t Seed_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Degradation_Seed_Get(int session, enum LP_Seed_Type_t *Seed_Type);
LP_DRIVER_API int __cdecl LP_GPRF_Wave_Generate_Mmemory(int session, const char* File_Name, const char* optional_Description_of_Waveform);


#ifdef __cplusplus
}
#endif
