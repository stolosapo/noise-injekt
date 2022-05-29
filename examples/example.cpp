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

    // Finilize global app context
    deleteAppContext(&mainFinilizeServiceDelegate);
}

void mainRegisterServiceDelegate(int argc, char* argv[])
{
    // Register one by one any service with its factory that needed to be injectable
    registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);

    cout << "Initialized" << endl;
}

void mainFinilizeServiceDelegate()
{
    cout << "Finalized" << endl;
}