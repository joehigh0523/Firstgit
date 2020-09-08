#pragma once
#include "iqapiDefines.h"

class IQ_API iqapiSignalData
{
public:	
     iqapiSignalData(void); //!< Constructor
    virtual ~iqapiSignalData(void);	//!< Destructor
    //! A copy constructor that can be used to make a deep copy of an \c iqapiModulationWave object.
    /*! Use this constructor when you wish to create a copy of an \c iqapiModulationWave object.
    */
    iqapiSignalData(const iqapiSignalData &src);
    //! Assignment operation 
    iqapiSignalData & operator = (const iqapiSignalData &src);
    
    int         length[N_MAX_TESTERS];    //!< Integer array that represents the length of the \a real and \a imag vectors, with one integer for each VSA in the test systems. 
    
    /*!< \c Length[0] indicates the length of \c real[0] and \c imag[0] vectors, which is the sample data returned from the first VSA (0).
    */

    double      *real[N_MAX_TESTERS];	//!< Double pointer array that represents the (real) sample data captured on each VSA.
    
    /*!<The length of \c real[x] is indicated by \c length[x], where x is the VSA number minus one. For example, the test system 1 uses a value of \c real[0], test system 2 uses a value of \c real[1] etc.
    */

    double      *imag[N_MAX_TESTERS];	//!< Double pointer array that represents the (imaginary) sample data captured on each VSA.
    
    /*!< The length of \c imag[x] is indicated by \c length[x], where x is the VSA number minus one. For example, the test system 1 uses a value of \c imag[0], test system 2 uses a value of \c imag[1] etc.
    */

    double      sampleFreqHz[N_MAX_TESTERS];	//!< Double pointer array that represents the sample frequency of \c real and \c imag data.
    
    /*!<\c sampleFreqHz[x] is the sampling rate of \c real[x] and \c imag[x], where x is the VSA number minus one. For example, the test system 1 uses a value of \c sampleFreqHz[0], test system 2 uses a value of \c sampleFreqHz[1] etc.
    */	
    char     lastErr[MAX_LEN_ERR_TXT];	//!< Char array (\c hndl->wave->lastErr) that contains an error message if a call to the \c hndl->GenerateWave function fails.

		
    virtual int	Save(char *fileName) = 0;		//!< Saves an \c iqapiModulationWave object to a \c .mod file(set by filename), which can be downloaded to a VSG via this API, or by the VSG panel in the IQsignal for MIMO application.    
    /*!< This function returns 0 (\c IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer). 
    */
	
   //! Get the capture type of the signal capture or signal wave generation
   virtual IQV_CAPTURE_TYPE_ENUM GetCaptureType() = 0;

   //! Free real and imag memory and assign length to 0 if any memory has been created
   void ReleaseMemory();
   
};

class IQ_API iqapiCapture : public iqapiSignalData
{
public:	
    iqapiCapture(void);	//!< Constructor
    virtual ~iqapiCapture(void);	//!< Destructor
    //Copy constructor
    iqapiCapture(const iqapiCapture &src);		//!< A Copy Constructor that can be used to make a deep copy of an iqapiCapture object. Use this constructor when you wish to create a copy of an iqapiCapture object.
    iqapiCapture & operator = (const iqapiCapture & src);

    //int         length[N_MAX_TESTERS];        //!< This integer array represents the length of the real and imag vectors described below (one integer for each VSA in the LitePoint Test Instrument(s)). Length[0] indicates the length of \c real[0] and \c imag[0]  and is the sample data returned from the first VSA (0).
    //double      *real[N_MAX_TESTERS];	        //!< This double pointer array represents the (real) sample data captured on each VSA. The length of real[x] is indicated by length[x], where x is the VSA number (minus one).
    //double      *imag[N_MAX_TESTERS];	        //!< This double pointer array represents the (imaginary) sample data captured on each VSA. The length of imag[x] is indicated by length[x], where x is the VSA number (minus one).
    //double      sampleFreqHz[N_MAX_TESTERS];	//!< This double array represents the sample frequency of real and imag. sampleFreqHz[x] is the sampling rate of real[x] and imag[x], where x is the VSA number (minus one).
    
    int         adc_clip[N_MAX_TESTERS];		//!< This integer array indicates whether or not clipping occurred during the data capture stored in \c real and \c imag. \c adc_clip[x] indicates clipping in \c real[x] and \c imag[x], where x is the VSA number (minus one).

    // Text of last error
    char		lastErr[MAX_LEN_ERR_TXT];	    //!< Saves the iqapiCapture object to a \c .sig file, (set by filename) which can be read and analyzed by IQsignal for MIMO. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).

    int Save(char *fileName) { return Save(fileName, IQV_DATA_IN_IQAPI); };
    int	Save(char *fileName, IQV_CAPTURE_DATA_HANDLING_ENUM captureDataHandling); 	//!< Saves the captured signal in a file (.sig)	
    int SaveNormalize(char *fileName, IQV_CAPTURE_DATA_HANDLING_ENUM captureDataHandling = IQV_DATA_IN_IQAPI, int lengthOfNormFactorDb=0, double *normFactorDb=NULL); //!< Saves normalized captured signal to a file (typically, a \c .mod file); this file can be used as a generator file to download to the VSG.

    int PlotPower(int figNum, char *plotArgs, int vsaNum);
    /*! Displays the signal contents of an \c iqapiCapture object during the debug and development phases. The data will first be converted to dBm before plotting. This function returns 0 (IQAPI_ERR_OK) if successful; if it returns a value that is less than 0, then it indicates a warning and if it returns a value that is greater than 0, then it indicates an error (see IQAPI_ERR_CODES, or the \c hndl->lastErr buffer).
    */

    // Internal use
    void  SetCaptureType(IQV_CAPTURE_TYPE_ENUM capType);
    IQV_CAPTURE_TYPE_ENUM GetCaptureType();
    double   reserved[5];

private:
   int Save(char *fileName, enum IQV_SAVE_FILE_TYPE_ENUM eFileType, IQV_CAPTURE_DATA_HANDLING_ENUM captureDataHandling = IQV_DATA_IN_IQAPI, int lengthOfNormFactorDb=0, double *normFactorDb = NULL);

   IQV_CAPTURE_TYPE_ENUM  captureType;
};