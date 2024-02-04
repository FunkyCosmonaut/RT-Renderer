#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <stdio.h>
#include "window.h"

//defaults
const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

int initWindow() {
    glfwInit();

    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount         =       0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    printf("%u extensions supported\n", extensionCount);

    glm::mat4 matrix;
    glm::vec4 vec;
    glm::vec4 test = matrix * vec;
    //linear algebra refresher, mat * vec = vec

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;

}
