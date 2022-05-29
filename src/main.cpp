#include <iostream>
#include "GlobalAppContext.h"

using namespace std;
using namespace NoiseInjekt;

void mainRegisterServiceDelegate(int argc, char* argv[]);
void mainFinilizeServiceDelegate();

class TestService: public Service
{
public:
    TestService(): Service() { }
    virtual ~TestService() { }
    void test()
    {
        cout << "This is a Service Test" << endl;
    } 
};

class TestServiceFactory: public ServiceFactory
{
public:
	TestServiceFactory(): ServiceFactory() { }
	Service *create()
    {
        return (Service*) new TestService;
    }
};

int main(int argc, char* argv[])
{
    cout << "noiseinjekt Library" << endl << endl;

    initializeAppContext(&mainRegisterServiceDelegate, argc, argv);

    TestService* srv = inject<TestService>("TestService");
    srv->test();

    deleteAppContext(&mainFinilizeServiceDelegate);

    cout << "Bye Bye.." << endl;
}

void mainRegisterServiceDelegate(int argc, char* argv[])
{
    registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);

    cout << "Initialized" << endl;
}

void mainFinilizeServiceDelegate()
{
    cout << "Finalized" << endl;
}
