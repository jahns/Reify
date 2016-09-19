#include "ReifyLoop.h"
#include "ReifyAppInfo.h"
#include "ReifyVKInstance.h"


ReifyLoop::ReifyLoop()
{
}

ReifyLoop::ReifyLoop(ReifyVKInstance vkInstance, GLFWwindow* window)
{
	this->vkInstance = vkInstance;
	this->window = window;
}


ReifyLoop::~ReifyLoop()
{
}

void ReifyLoop::run()
{
	initWindow();
	initVulkan();
	renderLoop();
}

void ReifyLoop::setVkInstance(ReifyVKInstance vkInstance)
{
	this->vkInstance = vkInstance;
}

void ReifyLoop::setWindow(GLFWwindow * window)
{
	this->window = window;
}

void ReifyLoop::renderLoop()
{
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void ReifyLoop::initWindow()
{
	
}

void ReifyLoop::initVulkan()
{
}
