#pragma once
#include <vulkan\vulkan.h>
#include <vector>

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class ReifyVkValidationLayers
{
public:
	ReifyVkValidationLayers();
	~ReifyVkValidationLayers();
};

