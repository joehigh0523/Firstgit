/*
  Litepoint Instrument Driver
  (C) Litepoint 2011, All rights reserved
*/
#ifndef LP_DRIVER_COMMANDS_H
#define LP_DRIVER_COMMANDS_H

#include "LP_driver_enums.h"
#include "LP_driver_defines.h"

#ifdef LP_INSTRUMENTDRIVER_EXPORTS
#define LP_DRIVER_API extern "C" __declspec(dllexport)
#else
#define LP_DRIVER_API extern "C" __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum LP_Comm_Interface_t {LP_TCPIP, LP_USB3, LP_GPIB};


/*! Opens the communication connection with the instrument, returning a handle to the instrument.  This
	is similar to a standard file open command.  Note that the IP address (address_string), Port Number (port_number)
	must all be specified as strings, whereas the Timeout (Timeout_ms) is specified as an integer.  
	The units for the timeout are in milliseconds.  A zero or negative number returned indicates that a
	connection to the instrument was not established.
*/
LP_DRIVER_API int __cdecl LP_Open_Session					(int *session_number, enum	LP_Comm_Interface_t comm, char address_string[], char port_number[], int timeout_ms);

/*! Closes the communication connection with the instrument and sets the session and handle to 0.  
	A positive return value indicates that the operation was successful whereas 
	a negative number indicates that the operation was unsuccessful.  Usually, an unsuccessful result is caused by
	the instrument not being open in the first place.
*/
LP_DRIVER_API int __cdecl LP_Close_Session				(int session_number);

/*!
    Returns numeric instrument driver version
    The version is also shown in the DLL file properties.
*/
LP_DRIVER_API void LP_Inst_Driver_Version_Get(unsigned int* major, unsigned int* minor, unsigned int* service, unsigned int* build);

/*!
    Returns string instrument driver version, in the form:
    major.minor.service.build
*/
LP_DRIVER_API const char* LP_Inst_Driver_Version_Str();

/*!
    Convert an error code to a string.
    Returns an empty string if no error (errorCode == 0)
    Returns "unknown error" for an invalid error number.
*/
LP_DRIVER_API const char* LP_DriverErrorCodeToString(int errorCode);


/*!
    Calls DiverErrorCodeToString if driverErrorCode != 0
    It then calls LP_Sys_Error_All_Get() with the remaining buffer
    This returns the result of LP_Sys_Error_All_Get()
    if LP_Sys_Error_All_Get() returns non-zero, that error is also appended to buffer.
*/
LP_DRIVER_API int LP_GetInstrumentError(int session, int driverErrorCode, int maxSize, char* buffer);  

#if 0
/*!
	This function will reset the entire system associated with session.  
	\param session
	Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
	are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  
*/
LP_DRIVER_API int __cdecl LP_Reset_System					(int session);

/*!
	This function will save the current settings of the entire system in the register denoted by reg.  
	\param session
	Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
	are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  
	\param reg 
	Save/Recall register number, 1~10.
*/
LP_DRIVER_API int __cdecl LP_Save_Register_System			(int session, unsigned int reg);

/*!
	This function will set the current settings of the entire system to those found in the register denoted by reg.	
	\param session
	Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
	are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  
	\param reg 
	Save/Recall register number, 1~10.
*/
LP_DRIVER_API int __cdecl LP_Recall_Register_System		(int session, unsigned int reg);

/*!
	This function will clear all information in the register denoted by reg.
	\param session
	Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
	are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  
	\param reg 
	Save/Recall register number, 1~10.
*/
LP_DRIVER_API int __cdecl LP_Clear_Register_System		(int session, unsigned int reg);

/*!
	This function will return a text string identifying the current module.
	\param maximum_size
	The size of the response array buffer.

	\param response
	A string describing the current module.
	  
	\param actual_size
	The actual returning data size.
*/
LP_DRIVER_API int __cdecl LP_Module_Query					(int session, unsigned int maximum_size, char response[], unsigned int *actual_size);

/*!
	This function will return a text string identifying the system (as opposed to the system module) associated with session. 
	The response will follow the form "<Manufacturer>,<Model Number>,<Serial Number>,<Firmware Revision>", where <Manufacturer> 
	would be Litepoint.

  \param session
  Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
  are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  

  \param maximum_size
  The length of response array buffer, which provided by called to store the returning data 

  \param max_field_size
  The length of each field buffer, such as Manufacturer, Firmware Revision etc.

	\param response
	The response string.

  \param actual_size
  The actual returning data size.

  \param Manufacturer
  Would be Litepoint.

  \param Module_Model_Number
  Current module name

  \param Serial_Number
  Serial number

  \param Firmware_App_Revision
  Firmware application revision number

*/
LP_DRIVER_API int __cdecl LP_Identify_System_Query		(int session, unsigned int maximum_size, unsigned int max_field_size, char response[], unsigned int *actual_size, char Manufacturer[], char Model_Number[], char Serial_Number[], char Firmware_Revision[]);
#endif
/*!
	This function will turn on/off logs files setting.

	/param on
	1, turn on log; 0 turn off log.

	/param driver_log_file
	Path and file name which log of driver should be saved

	/param tcp_log_file
	Path and file name which log of communication layer should be saved
*/
LP_DRIVER_API int __cdecl LP_Driver_Log_set				(int on, char driver_log_file[], char tcp_log_file[]);

LP_DRIVER_API int __cdecl LP_Driver_Command_Log_set				(int on, char command_log_file[]);

/*!
	This function clears the driver history -- once cleared, the history cannot be retrieved.  
	The history consists of all driver calls (including parameters).
*/
int	LP_Driver_Clear_History			(void);

/*!
	This function either turns driver storage on or off, depending on the value of status.  
	If status is greater than zero, driver commands will be stored.  If status is zero or less, 
	they will not.
*/
int	LP_Driver_Set_Storage			(int status);

/*!
	This function clears the SCPI command history -- once cleared, the history cannot be retrieved.  
	The history consists of all SCPI calls (including parameters).
*/
LP_DRIVER_API int __cdecl LP_SCPI_Clear_History			(void);

/*!
	This function either turns SCPI storage on or off, depending on the value of status.  If status 
	is greater than zero, SCPI commands will be stored.  If status is zero or less, they will not.
*/
int	LP_SCPI_Set_Storage				(int status);

/*!
	This function turns error checking on or off, depending on the value of status.  If status is 
	greater than zero, error checks will be performed after each communication with the instrument. 
	If status is zero or less, they will not.
*/
LP_DRIVER_API int __cdecl LP_Driver_Save_To_File			(int num_commands_to_save, char filename[LP_MAX_PATH_LENGTH]);

/*
	This function saves the requested number of scpi commands and queries to the specified file.  
	For example, if you specify you want 37 scpi, it will save the last 37 to the file -- in 
	chronological order. Note that all calls are appended if the file already exists.  Furthermore, 
	if you request more calls than are available, only the available calls will be saved.  
	To save all available commands, simply set num_commands_to_save to 0 or a negative number.
*/
LP_DRIVER_API int __cdecl LP_SCPI_Save_To_File			(int num_commands_to_save, char filename[LP_MAX_PATH_LENGTH]);

/*!
	This function turns error checking on or off, depending on the value of status.  If status is 
	greater than zero, error checks will be performed after each communication with the instrument.  
	If status is zero or less, they will not.
*/
LP_DRIVER_API int __cdecl LP_Error_Check_Set				(int  session, int status);

/*!
	This function retrieves the string in the ReadErrorBuffer.  Note that it does not send a SYST:ERR? query to the
	instrument.  It is intended to be used with the LP_Error_Check_Set function.  Note that memory for resp_string
	must be allocated prior to the call -- it should be LP_LENGTH_READ_BUFFER bytes long to match the error buffer.
*/
LP_DRIVER_API int __cdecl LP_Error_Retrieve				(int  session, char resp_string[]);
#if 0
/*!
	This function will get the range of the function "function_name".  For example, for LP_VSA_Frequency_Set, 
	it will return LP_GTLT, 4e8, 3e9, 2.5e9 (or something similar).  Note that function name must be null-terminated. 
*/
//int	LP_Get_Range					(int  session, int instance, char function_name[LP_MAX_FN_CALL_LENGTH], char parameter_name[], enum LP_Limit_Type_t *limit_type, enum LP_Limit_Comparison_t *limit_comparison, double *min_value, double *max_value, double *default_value);

/*!
	This function will get the documentation of the function "function_name".
*/
//int	LP_Get_Documentation			(int session, int instance, char function_name[], char response[], unsigned int *actual_size);

/*!
	This function simply returns an enum value corresponding to the string input.  
	This enum value will indicate the type of the module.
*/
//int	LP_Determine_Module_Type		(char *str, enum LP_Modules_t *eMod);

/*!
	This function copies the scpi_spec array for the selected module to the scpi_spec parameter. 
	Note that this is a copy and adequate memory must be allocated prior to calling this function.
*/
//LP_DRIVER_API int __cdecl LP_List_Internal_Commands		(enum LP_Modules_t eMod, char *scpi_spec);

#endif

/* Internal command */
LP_DRIVER_API int __cdecl LP_VSG_Wave_Define_File	(int session, int instance, int id, char filename[], unsigned long int maxblocksize);

LP_DRIVER_API int __cdecl LP_Sys_PassThrough_Command	(int session, char command[]);

LP_DRIVER_API int __cdecl LP_Sys_PassThrough_Query		(int session, char query[], unsigned int max_size, char response[], unsigned int *actual_size);

LP_DRIVER_API int __cdecl LP_Sys_PassThrough_Binary    (int session, const char command[], unsigned int binary_data_size, const char* binary_data);


LP_DRIVER_API int __cdecl LP_Sys_PassThrough_QueryAppLog		(int session, bool send, char query[], unsigned int fname_size, char file_name[], unsigned int *name_size, 
																 unsigned int dbuf_size, char data[], unsigned int *data_size, bool * data_end);

//! Loads data into a file on the file system
/*!
  \param session
  Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
  are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  

  \param file_name
  File name on tester

  \param bufferSize
  Data size to be loaded

  \param buffer
  Data want to load to tester
*/
LP_DRIVER_API int __cdecl LP_Sys_Mmemory_Load_Data                       (int session, char file_name[], unsigned int bufferSize, char buffer[]);

/*!
	This function will return a text string identifying the system (as opposed to the system module) associated with session. 
	The response will follow the form "<Manufacturer>,<Model Number>,<Serial Number>,<Firmware Revision>", where <Manufacturer> 
	would be Litepoint.

  \param session
  Indicates the communication channel to the instrument.  Note that one instrument can have multiple sessions.  Sessions
  are assigned when the LP_Open_Session function is called.  They must be greater than 0 to be valid.  

  \param maximum_size
  The length of response array buffer, which provided by called to store the returning data 

  \param max_field_size
  The length of each field buffer, such as Manufacturer, Firmware Revision etc.

	\param response
	The response string.

  \param actual_size
  The actual returning data size.

  \param Manufacturer
  Would be Litepoint.

  \param Module_Model_Number
  Current module name

  \param Serial_Number
  Serial number

  \param Firmware_App_Revision
  Firmware application revision number

*/
LP_DRIVER_API int __cdecl LP_Identify_System_Query		    (int session, unsigned int maximum_size, unsigned int max_field_size, char response[], unsigned int *actual_size, char Manufacturer[], char Model_Number[], char Serial_Number[], char Firmware_Revision[]);
LP_DRIVER_API int __cdecl LP_Identify_Remote_System_Query	(int session, unsigned int maximum_size, unsigned int max_field_size, char response[], unsigned int *actual_size, char Manufacturer[], char Model_Number[], char Serial_Number[], char Firmware_Revision[]);

// This version uses a single resource
LP_DRIVER_API int __cdecl LP_Rout_Port_Resource_Set1	(int session, int instance, enum LP_Port_Name_t Port_name, int Resource1);

// Use LP_Rout_Port_Resource_Set for the two-resource version.
//LP_DRIVER_API int __cdecl LP_Rout_Port_Resource_Set2	(int session, int instance, enum LP_Port_Name_t Port_name, enum LP_Port_t Resource1, enum LP_Port_t Resource2);

LP_DRIVER_API int __cdecl LP_VSA_Initiate_Spectrum_Wide (int session, int instance);
LP_DRIVER_API int __cdecl LP_VSA_Initiate_Spectrum_Wide_Bw160 (int session, int instance);

/**
  This begins a sequence of SCPI commands separated by ';' 
  After calling this, then call other SCPI commands to add them to the program message.
  No response data will be returned from commands, and the response arguments may be NULL.

  Next call LP_Execute_Multi_Command() to execute the command
*/
LP_DRIVER_API int __cdecl LP_Begin_Multi_Command (int session);

/**
  Execute the set of commands given after calling LP_Begin_Multi_Command()

  Following this call the API functions should be called again to get the response data.

  Finish with LP_End_Multi_Command()
*/
LP_DRIVER_API int __cdecl LP_Execute_Multi_Command (int session);

/**
  Return to normal operation after calling LP_Begin/Execute_Multi_Command
*/
LP_DRIVER_API int __cdecl LP_End_Multi_Command (int session);


/**
  Cancel a multi command sequence. May be slow, because commands will execute.
*/
LP_DRIVER_API int LP_Cancel_Multi_Command (int session);


/**
  Query, returns 1 for true and 0 for false
*/
int LP_is_in_begin_multi_command (int session);

/**
  Query, returns 1 for true and 0 for false
*/
int LP_is_in_execute_multi_command (int session);


#ifdef __cplusplus
}
#endif

#endif


