#include "ReifyAppInfo.h"



ReifyAppInfo::ReifyAppInfo()
{
	appInfo = {};
}


ReifyAppInfo::~ReifyAppInfo()
{
}

void ReifyAppInfo::setType(VkStructureType type)
{
	appInfo.sType = type;
}

void ReifyAppInfo::setPNext(const void * pNext)
{
	appInfo.pNext = pNext;
}

void ReifyAppInfo::setAppName(const char * name)
{
	appInfo.pApplicationName = name;
}

void ReifyAppInfo::setAppVersion(uint32_t appVersion)
{
	appInfo.applicationVersion = appVersion;
}

void ReifyAppInfo::setEngineName(const char * engineName)
{
	appInfo.pEngineName = engineName;
}

void ReifyAppInfo::setEngineVersion(uint32_t engineVersion)
{
	appInfo.engineVersion = engineVersion;
}

void ReifyAppInfo::setApiVersion(uint32_t apiVersion)
{
	appInfo.apiVersion = apiVersion;
}

VkApplicationInfo ReifyAppInfo::getAppInfo()
{
	return appInfo;
}
