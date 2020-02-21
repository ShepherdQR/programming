

//  https://learnopengl-cn.github.io/

// /usr/include/GL/freeglut_std.h文件查看opengl version  4.13 . but is wrong. should be 4.2

// ln -s /usr/include /usr/x/y/z/x.h (假设缺少的头文件路径 /usr/x/y/z/，根据实际情况操作）

// extern "C"{
//     #include <glad/glad.h>
//     #include <GLFW/glfw3.h>
// }

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    /*
    To check the opengl version, in shell:
    $ sudo apt-get install mesa-utils
    $ glxinfo
    mine is 4.2, make sure it's higher than the next two parameters.
    */
  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//we'll get access to a smaller subset of OpenGL features without backwards-compatible features we no longer need

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearningOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //We register the callback functions after we've created the window and before the render loop is initiated.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    //initialize GLAD before calling any OpenGL function---------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input function
        processInput(window);

        // render functon 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);// state-setting function, a dark green-blueish color
        glClear(GL_COLOR_BUFFER_BIT);//state=-using function.it uses the current state to retrieve the clearing color from.
        //The possible bits we can set are GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT and GL_STENCIL_BUFFER_BIT. 

        glfwSwapBuffers(window);//swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window) 
        glfwPollEvents();//poll IO events (keys pressed/released, mouse moved etc.)
    }

    //双缓冲(Double Buffer):单缓冲绘图时图像的逐步生成可能会使图像闪烁。双缓冲的前缓冲保存最终输出的图像并显示在屏幕上，后缓冲进行渲染。渲染完成后交换(Swap)前缓冲和后缓冲，立即显示图像消除不真实感。


    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}



// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    // this function means pressing esc to close window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}




// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    /*
    make sure the viewport matches the new window dimensions; note that width and 
    height will be significantly larger than specified on retina displays.
    the location of the lower left corner of the window is set to (0, 0)
    The third and fourth parameter set the width and height of the rendering window in pixels
    Note that processed coordinates in OpenGL are between -1 and 1 so we effectively map from the range (-1 to 1) to (0, 800) and (0, 600).
*/
}

