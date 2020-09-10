typedef struct __timeb64 lp_time_t;

#define DEBUG_PRINT true

#define IP_ADDR				  "192.168.13.165"

#define FREQ_HZ			  2442e6
#define FREQ_HZ_5G			  5500e6
#define SAMPLING_TIME_SEC 500e-6
#define VSA_TRIGGER_TYPE  IQV_TRIG_TYPE_IF2_NO_CAL

#define MAX_FILENAME_SIZE  128   
#define ASCII_ESC 27
// Carrier number
#define CARRIER_0    0
#define CARRIER_1    1
#define CARRIER_2    2
#define CARRIER_16   16
#define CARRIER_17   17
#define CARRIER_26   26
#define CARRIER_28   28
#define CARRIER_42   42
#define CARRIER_43   43
#define CARRIER_58   58
#define CARRIER_84   84
#define CARRIER_85   85
#define CARRIER_122  122

#define MAX_BUFFER_SIZE 4096

// status code for error checking
#define		IQMT_ERR_OK				0
#define		IQMT_ERR_FUNCTION_FAIL	1

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }

unsigned int __stdcall WiFi_11ac_Loopback_multithread(void *data);

void CheckReturnCode( int returnCode, char *functionName='\0' );
void PrintErrorStatus( int status, char * pFunctionName );
unsigned int GetElapsedMSec(lp_time_t start, lp_time_t end);
void ReadLogFiles (void);




