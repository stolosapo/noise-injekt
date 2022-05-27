#include "ServiceFactory.h"

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