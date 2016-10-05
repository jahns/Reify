#include <vector>
#include "ReifyLoop.h"
#include "ReifyAppInfo.h"
#include "ReifyInstanceCreateInfo.h"

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

GLFWwindow* setUpWindow() {
	int WIDTH = 800, HEIGHT = 600;
	

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	return  glfwCreateWindow(WIDTH, HEIGHT, "Reify", nullptr, nullptr);
}

ReifyAppInfo createAppInfo() {
	ReifyAppInfo appInfo;
	appInfo.setType(VK_STRUCTURE_TYPE_APPLICATION_INFO);
	appInfo.setAppName("Reify Render");
	appInfo.setAppVersion(VK_MAKE_VERSION(0, 1, 0));
	appInfo.setEngineName("Reify");
	appInfo.setEngineVersion(VK_MAKE_VERSION(0, 1, 0));
	appInfo.setApiVersion(VK_API_VERSION_1_0);

	return appInfo;
}

int main() {

	glfwInit();
	GLFWwindow* window = setUpWindow();
	ReifyAppInfo appInfo = createAppInfo();
	ReifyVKInstance instance = ReifyVKInstance::createInstance(appInfo);
	ReifyLoop loop;
	loop.setWindow(window);
	loop.setVkInstance(&instance);
	loop.run();

}
/*
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include "ReifyLoop.h"
#include "ReifyAppInfo.h"
#include "ReifyInstanceCreateInfo.h"
const int WIDTH = 800;
const int HEIGHT = 600;

template <typename T>
class VDeleter {
public:
	VDeleter() : VDeleter([](T, VkAllocationCallbacks*) {}) {}

	VDeleter(std::function<void(T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [=](T obj) { deletef(obj, nullptr); };
	}

	VDeleter(const VDeleter<VkInstance>& instance, std::function<void(VkInstance, T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [&instance, deletef](T obj) { deletef(instance, obj, nullptr); };
	}

	VDeleter(const VDeleter<VkDevice>& device, std::function<void(VkDevice, T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [&device, deletef](T obj) { deletef(device, obj, nullptr); };
	}

	~VDeleter() {
		cleanup();
	}

	const T* operator &() const {
		return &object;
	}

	T* replace() {
		cleanup();
		return &object;
	}

	operator T() const {
		return object;
	}

	void operator=(T rhs) {
		cleanup();
		object = rhs;
	}

	template<typename V>
	bool operator==(V rhs) {
		return object == T(rhs);
	}

private:
	T object{ VK_NULL_HANDLE };
	std::function<void(T)> deleter;

	void cleanup() {
		if (object != VK_NULL_HANDLE) {
			deleter(object);
		}
		object = VK_NULL_HANDLE;
	}
};

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
	}

private:
	GLFWwindow* window;

	VDeleter<VkInstance> instance{ vkDestroyInstance };

	void initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	void initVulkan() {
		createInstance();
	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}

	void createInstance() {
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;
		
		ReifyInstanceCreateInfo createInfo;
		createInfo.setSType(VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
		createInfo.setApplicationInfo(&appInfo);

		unsigned int glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.setEnabledExtensionCount(glfwExtensionCount);
		createInfo.setEnalbedExtensionNames(glfwExtensions);

		createInfo.setEnabledLayerCount(0);

		if (vkCreateInstance(&(createInfo.getInfo()), nullptr, instance.replace()) != VK_SUCCESS) {
			throw std::runtime_error("failed to create instance!");
		}
	}
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}*/