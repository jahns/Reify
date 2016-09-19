#pragma once
#include <vulkan/vulkan.h>
#include <stdexcept>
#include "ReifyDeleter.h"
#include "ReifyInstanceCreateInfo.h"
class ReifyVKInstance
{
public:
	ReifyVKInstance();
	~ReifyVKInstance();
	void intializeVkInstance(ReifyInstanceCreateInfo createInfo);

private:
	ReifyDeleter<VkInstance> instance;
};

