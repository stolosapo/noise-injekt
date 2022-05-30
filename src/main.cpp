#include <iostream>
#include "GlobalAppContext.h"

using namespace std;
using namespace NoiseInjekt;

void mainRegisterServiceDelegate(int argc, char* argv[]);
void mainFinilizeServiceDelegate();

class TestService: public Service
{
public:
    TestService(): Service()
    {
        cout << "TestService :: Initialized" << endl;
    }

    virtual ~TestService()
    {
        cout << "TestService :: Finalized" << endl;
    }

    void test()
    {
        cout << "This is a Service Test" << endl;
    }
};

class TestServiceFactory: public ServiceFactory
{
public:
	TestServiceFactory(): ServiceFactory()
    {
        cout << "TestServiceFactory :: Initialized" << endl;
    }

    virtual ~TestServiceFactory()
    {
        cout << "TestServiceFactory :: Finalized" << endl;
    }

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

    TestService* srv2 = inject<TestService>("TestService");
    srv2->test();

    cout << "Those 2 services are actual the same instance..? "
        << (srv == srv2)
        << " since that the service have registared as SINGLETON."
        << endl;

    deleteAppContext(&mainFinilizeServiceDelegate);

    cout << "Bye Bye.." << endl;
}

void mainRegisterServiceDelegate(int argc, char* argv[])
{
    cout << " | GlobalAppContext Services Registration .." << endl;

    registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);
}

void mainFinilizeServiceDelegate()
{
    cout << " | GlobalAppContext Fililiazation .." << endl;
}
