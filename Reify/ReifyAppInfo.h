#pragma once
#include <vulkan\vulkan.h>
class ReifyAppInfo
{
public:
	ReifyAppInfo();
	~ReifyAppInfo();

	void setType(VkStructureType type);
	void setPNext(const void* pNext);
	void setAppName(const char* name);
	void setAppVersion(uint32_t appVersion);
	void setEngineName(const char* engineName);
	void setEngineVersion(uint32_t engineVersion);
	void setApiVersion(uint32_t apiVersion);

	VkApplicationInfo getAppInfo();
private:
	VkApplicationInfo appInfo;
};

