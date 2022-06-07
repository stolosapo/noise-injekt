#include <iostream>
#include <noiseinjekt/GlobalAppContext.h>
#include "TestService.h"
#include "TestServiceFactory.h"

using namespace std;
using namespace NoiseInjekt;

void mainRegisterServiceDelegate(int argc, char* argv[]);
void mainFinilizeServiceDelegate();

int main(int argc, char* argv[])
{
    cout << "Example noiseinjekt" << endl;

    // First initialize the global app context
    initializeAppContext(&mainRegisterServiceDelegate, argc, argv);

    // Use it.. just call inject to get a service
    TestService* srv = inject<TestService>("TestService");
    srv->test();

    TestService* srv2 = inject<TestService>("TestService");
    srv2->test();

    cout << "Those 2 services are actual the same instance..? "
        << (srv == srv2)
        << " since that the service have registared as SINGLETON."
        << endl;

    // Finilize global app context
    deleteAppContext(&mainFinilizeServiceDelegate);
}

void mainRegisterServiceDelegate(int argc, char* argv[])
{
    cout << " | GlobalAppContext Services Registration .." << endl;

    // Register one by one any service with its factory that needed to be injectable
    registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);
}

void mainFinilizeServiceDelegate()
{
    cout << " | GlobalAppContext Fililiazation .." << endl;
}
