#include "ReifyVKInstance.h"



ReifyVKInstance::ReifyVKInstance()
{
	
	instance =  { vkDestroyInstance };
	
}


ReifyVKInstance::~ReifyVKInstance()
{
}



void ReifyVKInstance::intializeVkInstance(ReifyInstanceCreateInfo createInfo)
{
	if (vkCreateInstance(&(createInfo.getInfo()), nullptr, instance.replace())!= VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}
}

ReifyVKInstance ReifyVKInstance::createInstance(ReifyAppInfo & appInfo)
{
	ReifyVKInstance instance;
	ReifyInstanceCreateInfo createInfo;
	createInfo.setSType(VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
	createInfo.setApplicationInfo(&appInfo.getAppInfo());


	unsigned int glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.setEnabledExtensionCount(glfwExtensionCount);
	createInfo.setEnalbedExtensionNames(glfwExtensions);
	createInfo.setEnabledLayerCount(0);

	instance.intializeVkInstance(createInfo);
	return instance;
}





