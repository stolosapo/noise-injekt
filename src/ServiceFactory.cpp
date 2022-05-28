#include "Service.h"

using namespace NoiseInjekt;

ServiceFactory::ServiceFactory()
{
    this->implementationSelection = "";
}

ServiceFactory::ServiceFactory(string implementationSelection)
{
    this->implementationSelection = implementationSelection;
}

ServiceFactory::~ServiceFactory()
{

}
