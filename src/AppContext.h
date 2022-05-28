#ifndef AppContext_h__
#define AppContext_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Service.h"

using namespace std;

namespace NoiseInjekt
{

    typedef void (*RegisterServiceDelegate)(int argc, char* argv[]);
    typedef void (*FinilizeServiceDelegate)();

    enum InjectionScope
    {
        SINGLETON = 0,

        REQUEST = 1,

        START_UP = 2,
    };

    class AppContext
    {
    private:
        /* All instatiated services */
        map<string, Service*> services;

        /* All registered factories */
        map<string, ServiceFactory*> serviceFactories;

        /* All scoped service */
        map<string, InjectionScope> scopes;

        /* All instantiated services, to be desposed */
        vector<Service*> servicesToBeDisposed;

        bool serviceExists(string serviceName);
        bool factoryExists(string serviceName);
        bool scopeExists(string serviceName);

        Service* instantiateService(string serviceName);

        Service* getSingletonService(string serviceName);
        Service* getRequestedService(string serviceName);
        Service* getStartupService(string serviceName);

    public:
        AppContext();
        virtual ~AppContext();

        map<string, InjectionScope> getScopes();

        void registerService(InjectionScope scope, string serviceName, ServiceFactory* serviceFactory);

        Service* getService(string serviceName);

    };
}

#endif // AppContext_h__
