#include "AppContext.h"

using namespace NoiseInjekt;

AppContext::AppContext()
{

}


AppContext::~AppContext()
{
    /* Clear scopes */
    scopes.clear();


    /* Clear service factories */
    for (map<string, ServiceFactory*>::iterator it = serviceFactories.begin();
        it != serviceFactories.end();
        ++it)
    {
        delete it->second;
    }

    serviceFactories.clear();


    /* Clear singleton services */
    for (map<string, Service*>::iterator it = services.begin();
        it != services.end();
        ++it)
    {
        delete it->second;
    }

    services.clear();
}


map<string, InjectionScope> AppContext::getScopes()
{
    return scopes;
}


void AppContext::registerService(InjectionScope scope, string serviceName, ServiceFactory* serviceFactory)
{
    /* First register service scope */
    scopes[serviceName] = scope;

    /* Then register factory */
    serviceFactories[serviceName] = serviceFactory;
}


bool AppContext::serviceExists(string serviceName)
{
    map<string, Service*>::iterator it;
    it = services.find(serviceName);

    return it != services.end();
}


bool AppContext::factoryExists(string serviceName)
{
    map<string, ServiceFactory*>::iterator it;
    it = serviceFactories.find(serviceName);

    return it != serviceFactories.end();
}


bool AppContext::scopeExists(string serviceName)
{
    map<string, InjectionScope>::iterator it;
    it = scopes.find(serviceName);

    return it != scopes.end();
}


Service* AppContext::instantiateService(string serviceName)
{
    ServiceFactory* factory = serviceFactories.find(serviceName)->second;

    if (serviceExists(serviceName))
    {
        map<string, Service*>::iterator it = services.find(serviceName);
        delete it->second;
        services.erase(it);
    }

    Service* service = factory->create();

    services[serviceName] = service;

    return service;
}


Service* AppContext::getSingletonService(string serviceName)
{
    bool exists = serviceExists(serviceName);

    if (!exists)
    {
        return instantiateService(serviceName);
    }

    return services.find(serviceName)->second;
}


Service* AppContext::getRequestedService(string serviceName)
{
    return instantiateService(serviceName);
}


Service* AppContext::getStartupService(string serviceName)
{
    return getSingletonService(serviceName);
}


Service* AppContext::getService(string serviceName)
{
    /* First get scope */
    InjectionScope scope = scopes.find(serviceName)->second;

    switch (scope)
    {
        case SINGLETON:
            return getSingletonService(serviceName);

        case REQUEST:
            return getRequestedService(serviceName);

        case START_UP:
            return getStartupService(serviceName);

        default:
            return getRequestedService(serviceName);
    }
}
