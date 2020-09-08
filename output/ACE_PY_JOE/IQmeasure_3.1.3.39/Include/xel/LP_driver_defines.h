#ifndef LP_INSTRUMENTDRIVERDEFINES_H
#define LP_INSTRUMENTDRIVERDEFINES_H

/*
  Litepoint Instrument Driver
  (C) Litepoint 2011, All rights reserved
*/


#ifdef LP_INSTRUMENTDRIVER_EXPORTS
#define LP_DRIVER_API extern "C" __declspec(dllexport)
#else
#define LP_DRIVER_API extern "C" __declspec(dllimport)
#endif

// Multi instance support
// Usage Example: 
// LP_VSG_Some_Command(session, instance | LP_MULTI_INST, ...)
// LP_VSG_Some_Command(session, LP_MULTI_ALL, ...)
#define LP_MULTI_INST 0x4000
#define LP_MULTI_ALL  0x8000


#define LP_LENGTH_ADDRESS_STRING		24

#define LP_LENGTH_IDENTITY				256
#define LP_LENGTH_SUB_IDENTITY			50
#define LP_LENGTH_MANUFACTURER			72
#define LP_LENGTH_MODEL_NUMBER			72
#define LP_LENGTH_SERIAL_NUMBER			72
#define LP_LENGTH_FIRMWARE_REVISION		72
#define LP_LENGTH_WRITE_BUFFER			1024
#define LP_LENGTH_READ_BUFFER			1024
#define LP_CLR_BLOCK_SIZE				1024
//#define LP_MAX_QUERY_ATTEMPTS			100
#define LP_RANGE_PARAMETER_LENGTH		36

#define LP_MAX_COMMANDS					500		// max commands per module
#define LP_MAX_COMMAND_LENGTH			256
#define LP_MAX_FN_CALL_LENGTH			256
#define LP_MAX_PATH_LENGTH				256
#define LP_MAX_SEQUENCES				100
#define LP_MAX_SEQUENCE_LENGTH			256
#define LP_MAX_FILENAME_LENGTH			256


#define LP_MAX_ERRORS					300		// max errors for entire system
#define LP_MAX_ERROR_LENGTH				100

#define LP_MAX_GPRF_SLOTS				10
#define LP_MAX_CDMA2K_SLOTS				30
#define LP_MAX_WCDMA_SLOTS				30
#define LP_MAX_GSM_SLOTS				30
#define LP_MAX_LTE_SLOTS				50
#define LP_WCDMA_ACLR_SIZE				5
#define LP_CDMA2K_ACLR_SIZE				5

// The following two values must be fixed!!
#define LP_MAX_BT_SLOTS                 10
#define LP_MAX_WIFI_SLOTS               10

// Driver History
#define LP_MAX_COMMAND_HISTORY			200


#define TOKEN_LINE_FEED					0x0A
#define TOKEN_SPACE						0x20
#define TOKEN_CARRIAGE_RETURN			0x13

#define LP_SCPI_END						1
#define LP_SCPI_CONTINUED				0

#define LP_NUMBER_OF_KEYWORDS			2
#define LP_KEYWORD_LENGTH				20
#define LP_MAX_LTE_CHANNELS				3

#define LP_IDN_FIELD_LENGTH				96	// Max size for an individual field
#define LP_MIDN_FIELDS					10	// 1 for the entire string, 1 for each of the 9 (max) fields.  10 total.




// ERROR CODES
#define LP_NO_ERROR										0x00000000

#define LP_ERR_NO_CONNECTION							-1
#define LP_ERR_TIMEOUT									-2
#define LP_ERR_UNEXPECTED								-3
#define LP_ERR_BYTES_NOT_WRITTEN						-4
#define LP_ERR_WRITING									-5
#define LP_ERR_BINARY_BLOCK_READ						-6
#define LP_ERR_UNDEFINED_INTERFACE						-7
#define LP_ERR_SYSTEM_NOT_FOUND							-8
#define LP_ERR_MODULE_NOT_FOUND							-9
#define LP_ERR_INSUFFICIENT_ARRAY_MEMORY				-10
#define LP_ERR_WAVE_FILE_COULD_NOT_BE_OPENED			-11
#define LP_ERR_ERROR_READING_WAVE_FILE					-12
#define LP_ERR_ERROR_BINARY_READ_BUFFER_TOO_SHORT		-13
#define LP_ERR_QUERY_NOT_TERMINATED						-14
#define LP_ERR_FUNCTION_NOT_FOUND						-15
#define LP_ERR_DRIVER_HISTORY_FILE_COULD_NOT_BE_OPENED	-16
#define LP_ERR_SCPI_HISTORY_FILE_COULD_NOT_BE_OPENED	-17
#define LP_ERR_BINARY_BLOCK_START_NOT_DETECTED			LP_ERR_SCPI_HISTORY_FILE_COULD_NOT_BE_OPENED	- 1
#define LP_ERR_BINARY_BLOCK_READ_INTERRUPTED			LP_ERR_BINARY_BLOCK_START_NOT_DETECTED			- 1
#define LP_ERR_BINARY_BLOCK_TIMEOUT						LP_ERR_BINARY_BLOCK_READ_INTERRUPTED			- 1
#define LP_ERR_BINARY_BLOCK_END_NOT_DETECTED			LP_ERR_BINARY_BLOCK_TIMEOUT						- 1
#define LP_ERR_SCPI_PARAMETER_NOT_FOUND					LP_ERR_BINARY_BLOCK_END_NOT_DETECTED			- 1
#define LP_ERR_INVALID_POINTER_DETECTED					LP_ERR_SCPI_PARAMETER_NOT_FOUND					- 1
#define LP_ERR_NOT_IN_MULTI_COMMAND_MODE 			    LP_ERR_INVALID_POINTER_DETECTED					- 1
// See also:
// LP_DRIVER_API const char* DriverErrorCodeToString(int errorCode)


#endif
