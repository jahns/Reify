#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>
#include "ReifyVKInstance.h"

class ReifyLoop
{
public:
	ReifyLoop();
	ReifyLoop(ReifyVKInstance vkInstance, GLFWwindow* window);
	~ReifyLoop();

	void run();
	void setVkInstance(ReifyVKInstance vkInstance);
	void setWindow(GLFWwindow* window);
	
private:
	GLFWwindow* window;
	ReifyVKInstance vkInstance;
	

	void renderLoop();
	void initWindow();
	void initVulkan();
};

