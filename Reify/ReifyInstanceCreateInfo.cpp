#include "ReifyInstanceCreateInfo.h"



ReifyInstanceCreateInfo::ReifyInstanceCreateInfo()
{
	info = {};
}


ReifyInstanceCreateInfo::~ReifyInstanceCreateInfo()
{
}

void ReifyInstanceCreateInfo::setSType(VkStructureType sType)
{
	info.sType = sType;
}

void ReifyInstanceCreateInfo::setApplicationInfo(VkApplicationInfo *appInfo)
{
	this->info.pApplicationInfo = appInfo;
}

void ReifyInstanceCreateInfo::setEnabledExtensionCount(int count)
{
	this->info.enabledExtensionCount = count;
}

void ReifyInstanceCreateInfo::setEnalbedExtensionNames(const char* const* names)
{
	this->info.ppEnabledExtensionNames = names;
}

void ReifyInstanceCreateInfo::setEnabledLayerCount(int count)
{
	this->info.enabledLayerCount = count;
}

const VkInstanceCreateInfo ReifyInstanceCreateInfo::getInfo()
{
	return info;
}
