#pragma once
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <GLFW\glfw3.h>
#include "ReifyAppInfo.h"
#include "ReifyDeleter.h"
#include "ReifyInstanceCreateInfo.h"
class ReifyVKInstance
{
public:
	ReifyVKInstance();
	~ReifyVKInstance();
	void intializeVkInstance(ReifyInstanceCreateInfo createInfo);
	static ReifyVKInstance createInstance(ReifyAppInfo& appInfo);

private:
	ReifyDeleter<VkInstance> instance;
};

