#ifndef Service_h__
#define Service_h__

#include <string>

using namespace std;

namespace NoiseInjekt
{
    class Service
    {
    public:
        Service();
        virtual ~Service();

    };

    class ServiceFactory
    {
    private:
        string implementationSelection;

    public:
        ServiceFactory();
        ServiceFactory(string implementationSelection);
        virtual ~ServiceFactory();

        virtual Service* create() = 0;

    };
}

#endif // Service_h__
