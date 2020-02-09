
// studying on 2020020720:12
// studying on 2020020817:18
// studying on 2020020822:48
// studying on 2020020900:00, shader
// studying on 2020020918:05, shader class

// background color changes with time, and drew 2 triangles.

/*
    step2:建立一个顶点和一个片段着色器
    step3:用一个顶点缓冲对象将顶点数据初始化至缓冲中
    step4:设置OpenGL中顶点数据与顶点着色器顶点属性之间的连接
*/


// negative values make the color black.

/*
    顶点数组对象(Vertex Array Object, VAO)可以像顶点缓冲对象那样被绑定，任何随后的顶点属性调用都会储存在这个VAO中。VAO储存：
    1）glEnableVertexAttribArray和glDisableVertexAttribArray的调用；
    2）通过glVertexAttribPointer设置的顶点属性配置；
    3）通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
*/



#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <math.h>

#include "include/shader001_s.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float color_bump_back = 1.0;// set 0 to stop bumpping.

//用着色器语言GLSL(OpenGL Shading Language)创建顶点着色器,储存在一个C的字符串中
/*
    in 声明所有的输入顶点属性(Input Vertex Attribute)
    vec3, 有3个float变量的向量
    layout标识着链接顶点数据，(location = 0) 这个是设置输入变量的位置
    第4个维度vec.w用在透视除法(Perspective Division)上
*/




int main()
{
    auto t_start = std::chrono::high_resolution_clock::now();

    // step1 initialization starts-------

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // step1 initialization starts-------




    // step2 compile and bind shaders start---

    Shader shaderProgramColorPalette("vertex001.qr", "fragment001.qr");
    Shader shaderProgramColorChanging("vertex001.qr", "fragment002.qr");


    // step2 compile and bind shaders end---




    // step3 input data to GPU starts-------
    // set up vertex data (and buffer(s)) and configure vertex attributes
    
    float vertices1[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top 
    };


    float vertices2[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices2[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };



    // !!注意每个中间的数据都要有逗号，没有逗号后面的数据无效
    //if(draw_two_triangles == 1)
    float vertices[] = {
        -0.5f, 0.0f, 0.0f, // left  
        0.5f, 0.0f, 0.0f, // right 
        0.0f,  0.5f, 0.0f,  // top
        -0.5f, 0.0f, 0.0f, // left
        0.5f, 0.0f, 0.0f, // right  
        0.0f,  -0.5f, 0.0f // bottom  
    };


    float vertices3[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
        // second triangle
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top 
    }; 

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2,  // first Triangle
        3, 4, 5   // second Triangle
    };

    

    float firstTriangle1[] = {
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
    };
    float secondTriangle1[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };



    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // right
        -0.45f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top 
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };





    unsigned int VAOs[2], VBOs[2], EBOs[2];
    glGenVertexArrays(2, VAOs);// 注意创建的是VAO时此处要 &VAO
    glGenBuffers(2, VBOs);
    glGenBuffers(2, EBOs);//必须在每次要用索引渲染一个物体时绑定相应的EBO


    //--- first triangle setup
    glBindVertexArray(VAOs[0]);
        //以下两行复制顶点数组到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);//通过顶点缓冲对象(Vertex Buffer Objects, VBO)管理内存
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    //目标缓冲类型，指定传输数据的大小(以字节为单位)，传送的数据，第四个参数指定了我们希望显卡如何管理给定的数据。它有三种形式：
    //GL_STATIC_DRAW ：数据不会或几乎不会改变。
    //GL_DYNAMIC_DRAW：数据会被改变很多。
    //GL_STREAM_DRAW ：数据每次绘制时都会改变。能确保显卡把数据放在能够高速写入的内存部分

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //复制索引到缓冲.

    //以下两行设置顶点属性指针Linking Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    /*
    1)顶点位置0，之前设置layout(location = 0)；
    2）顶点大小，vec3,是3；
    3）数据类型；
    4）Normalize=false不被标准化，无符号的不映射到0和1之间，有符号的不映射到(-1,1);
    5)步长，相邻2个顶点属性之间的距离。数值是紧密排列时可以设置为0让OpenGL决定具体步长；
    6）最后一个参数的类型是void*。位置数据在缓冲中起始位置的偏移量(Offset)
    */
    glEnableVertexAttribArray(0);//以顶点属性位置值作为参数，启用顶点属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// !!注意偏移量是3 * sizeof(float)
    glEnableVertexAttribArray(1);
    

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    //glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines




    //--- second triangle setup
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0); // not really necessary as well, but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)

    // step3 input data to GPU ends-------



    


    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);// uncomment this call to draw in wireframe polygons.


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // set background color
        auto t_now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
        glClearColor(color_bump_back * (sin(time * 4.0f) + 1.0f) / 2.0f, 0.2f, 0.3f, 1.0f);
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // another time changing codes
        float timeValue = glfwGetTime();//运行秒数
        float greenValue = sin(timeValue) / 2.0f + 0.5f;


        // render shaderProgramColorPalette---1
        shaderProgramColorPalette.use();
        shaderProgramColorPalette.set3f("transformation", sin(timeValue)-0.45, cos(timeValue), 0.0f);
        glBindVertexArray(VAOs[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //图元类型；顶点数组的起始索引0；绘制顶点个数是6




        
        // render shaderProgramColorChanging---2
        shaderProgramColorChanging.use();// be sure to activate the shader before any calls to glUniform

        // update shader uniform
        // be sure to activate the shader before any calls to glUniform
        

        shaderProgramColorChanging.set4f("changingColor", 0.0f, greenValue, 0.0f, 1.0f);
  
            // draw triangles
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//参数：绘制模式；顶点数；索引类型；EBO偏移量。
        // glBindVertexArray(0); // no need to unbind it every time



        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteBuffers(2, EBOs);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}