#include "GlobalAppContext.h"

#include <map>

using namespace NoiseInjekt;

AppContext appContext;

void NoiseInjekt::initializeAppContext(RegisterServiceDelegate registerServiceDelegate, int argc, char* argv[])
{
    /* Created context */
    cout << "* Created appContext: " << &appContext << endl;

    /* register all services */
    registerServiceDelegate(argc, argv);

    cout << "* Registered Services" << endl;

    /* load START_UP services */
    loadStartupServices();
}

void NoiseInjekt::deleteAppContext(FinilizeServiceDelegate finilizeServiceDelegate)
{
    finilizeServiceDelegate();
}

void NoiseInjekt::loadStartupServices()
{
    map<string, InjectionScope> scopes = appContext.getScopes();

    for (map<string, InjectionScope>::iterator it = scopes.begin();
        it != scopes.end();
        ++it)
    {
        string curServiceName = it->first;
        InjectionScope curScope = it->second;

        if (curScope == START_UP)
        {
            appContext.getService(curServiceName);
        }
    }
}
