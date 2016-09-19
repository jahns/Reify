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





