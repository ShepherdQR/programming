

#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

using namespace std;


void glm_check_qr(){
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);//point
    // glm::mat4 trans;//0.9.9及以下版本默认初始化为单位矩阵；
    // glm::mat4 trans;//0.9.9及以上版本默认初始化为零矩阵；
    glm::mat4 trans= glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    vec = trans * vec;
    std::cout << "Correct answer is 210, the output is: " << vec.x << vec.y << vec.z << "glm works well." << std::endl;

}



void glfwInit_qr(const int VERSION_MAJOR, const int MINOR_MAJOR){
    glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_MAJOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif
        cout << "ok" << endl;
}


int gladLoad_check_qr(){
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
}

