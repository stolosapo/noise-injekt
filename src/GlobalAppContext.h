#ifndef GlobalAppContext_h__
#define GlobalAppContext_h__

#include <iostream>
#include <string>

#include "AppContext.h"
#include "Service.h"

using namespace std;
using namespace NoiseInjekt;


/* Global AppContext */
extern AppContext appContext;

namespace NoiseInjekt
{
    /* Context initialization */
    void initializeAppContext(int argc, char* argv[]);
    void deleteAppContext();


    /* Context methods */
    void loadStartupServices();

    template<class T>
    void registerGlobalService(InjectionScope scope, string serviceName, T* serviceFactory);

    template<class T>
    T* inject(string serviceName);


    template<class T>
    void registerGlobalService(InjectionScope scope, string serviceName, T* serviceFactory)
    {
        appContext.registerService(scope, serviceName, (ServiceFactory*) serviceFactory);

        cout << "* Factory for service: '" << serviceName << "' registed in appContext." << endl;
    }


    template<class T>
    T* inject(string serviceName)
    {
        Service* srv = appContext.getService(serviceName);
        return (T*) srv;
    }
}

#endif // GlobalAppContext_h__
