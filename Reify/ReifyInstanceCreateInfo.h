#pragma once
#include <vulkan\vulkan.h>
class ReifyInstanceCreateInfo
{
public:
	ReifyInstanceCreateInfo();
	~ReifyInstanceCreateInfo();

	void setSType(VkStructureType sType);
	void setApplicationInfo(const VkApplicationInfo *appInfo);;
	void setEnabledExtensionCount(int count);
	void setEnalbedExtensionNames(const char* const* names);
	void setEnabledLayerCount(int count);
	const VkInstanceCreateInfo getInfo();
private:
	VkInstanceCreateInfo info;
};

