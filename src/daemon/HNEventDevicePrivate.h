#ifndef __HN_EVENT_DEVICE_PRIVATE_H__
#define __HN_EVENT_DEVICE_PRIVATE_H__

#include <string>
#include <vector>

#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/OptionSet.h"

#include <hnode2/HNodeDevice.h>
#include <hnode2/HNodeConfig.h>
#include <hnode2/HNEPLoop.h>
#include <hnode2/HNReqWaitQueue.h>

#define HNODE_TEST_DEVTYPE   "hnode2-event-device"

typedef enum HNEventDeviceResultEnum
{
  HNEVD_RESULT_SUCCESS,
  HNEVD_RESULT_FAILURE,
  HNEVD_RESULT_BAD_REQUEST,
  HNEVD_RESULT_SERVER_ERROR
}HNEVD_RESULT_T;

class HNEventDevice : public Poco::Util::ServerApplication, public HNDEPDispatchInf //, public HNEPLoopCallbacks
{
    private:
        bool _helpRequested   = false;
        bool _debugLogging    = false;
        bool _instancePresent = false;

        std::string _instance; 
        std::string m_instanceName;

        HNodeDevice m_hnodeDev;

        void displayHelp();

        bool configExists();
        HNEVD_RESULT_T initConfig();
        HNEVD_RESULT_T readConfig();
        HNEVD_RESULT_T updateConfig();

    protected:
        // HNDevice REST callback
        virtual void dispatchEP( HNodeDevice *parent, HNOperationData *opData );

        // Poco funcions
        void defineOptions( Poco::Util::OptionSet& options );
        void handleOption( const std::string& name, const std::string& value );
        int main( const std::vector<std::string>& args );

};

#endif // __HN_EVENT_DEVICE_PRIVATE_H__
