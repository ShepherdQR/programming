
/*
    studying on 2020020720:12
    studying on 2020020817:18
    studying on 2020020822:48
    studying on 2020020900:00, shader
    studying on 2020020918:05, shader class
    studying on 2020020920:39, texture
    studying on 2020021101:21, transformation
*/


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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "include/stb_image.h"
#include "include/shader001_s.h"
//#include "include/functions.h"
//#include "resources/data/data.h"

using namespace std;


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float color_bump_back = 1.0;// set 0 to stop bumpping.
float mixValue = 0.2f; // mixValue * texture2 + (1 - mixValue) * texture1




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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL_qr", NULL, NULL);// glfw window creation
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        //glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // step1 initialization ends-------

    // ================================

    // step2 compile and bind shaders start---
    
    glEnable(GL_DEPTH_TEST);// configure global opengl state

    //Shader shaderProgramColorPalette("vertex001.qr", "fragment001.qr");
    //Shader shaderProgramColorChanging("vertex001.qr", "fragment002.qr");

    Shader shaderProgramTexture01("vertex003_trans.qr", "fragment003_tex.qr");


    // step2 compile and bind shaders end---

    // =================================


    // step3 input data to GPU starts-------
    // set up vertex data (and buffer(s)) and configure vertex attributes
    


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

    //float tex_left = 0.0, tex_right = 1.0;
    //float tex_left = 0.0, tex_right = 2.0;
    //float tex_left = 0.45, tex_right = 0.55;
    float tex_left = 0.0, tex_right = 1.0;

    float vertices_tex[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   tex_right, tex_right, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   tex_right, tex_left, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   tex_left, tex_left, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   tex_left, tex_right  // top left 
    };
    unsigned int indices_tex[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };


    float vertices_3d[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };


    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };



    unsigned int VAOs[4], VBOs[4], EBOs[4];
    glGenVertexArrays(4, VAOs);// 注意创建的是VAO时此处要 &VAO
    glGenBuffers(4, VBOs);
    glGenBuffers(4, EBOs);//必须在每次要用索引渲染一个物体时绑定相应的EBO

    



    //--- forth triangles setup
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_3d), vertices_3d, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // step3 input data to GPU ends-------







    // load and create a texture
    unsigned int texture1, texture2;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); //all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        //see the pixels more clearly
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


        // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("../resources/textures/container.jpg", &width, &height, &nrChannels, 0);//需要是该函数所在cpp的文件夹..出来
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        /*参数：
        1）纹理目标；
        2）多级渐远纹理的级别，0是基础级别；
        3）纹理储存格式；
        4）最终纹理宽；
        5）最终纹理高；
        6）这里一直写0；
        7）原图格式，这里用RGB值加载图像；
        8）原图数据类型，这里储存为char(byte)数组；
        9）图像数据。
        */
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture1" << std::endl;
    }
    stbi_image_free(data);//释放图像的内存



    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        /*
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        */
       /*
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    */
        



    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    data = stbi_load("../resources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture2" << std::endl;
    }
    stbi_image_free(data);


    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)设置每个采样器的方式告诉OpenGL每个着色器采样器属于哪个纹理单元
    shaderProgramTexture01.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(shaderProgramTexture01.ID, "texture1"), 0);
    // or set it via the texture class
    shaderProgramTexture01.setInt("texture2", 1);







    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);// uncomment this call to draw in wireframe polygons.




    



    // render loop
    // -----------
    int k_lock(0);
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // set background color
        auto t_now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
        glClearColor(color_bump_back * (sin(time * 4.0f) + 1.0f) / 2.0f, 0.2f, 0.3f, 1.0f);
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // another time changing codes
        float timeValue = glfwGetTime();//运行秒数
        float greenValue = sin(timeValue) / 2.0f + 0.5f;


        

        

        // render shaderProgramTexture01 --3

            // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);//激活纹理单元.纹理单元GL_TEXTURE0默认总是被激活
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        shaderProgramTexture01.use();
        
        


        //glm::mat4 model= glm::mat4(1.0f); 
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection  = glm::mat4(1.0f);

        //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));//这里改变是场景中的所有物体，如这里是所有物体后退3
        projection = glm::perspective(glm::radians(45.0f), 1.0f * (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // 只改变FOV，越小，显示的区域约小，物体越近，看起来越大。
        //宽高比变大，会变上下长，变小会变左右长


            // model matrix
        //unsigned int modelLoc = glGetUniformLocation(shaderProgramTexture01.ID, "model");
        //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            // view matrix
        unsigned int viewLoc  = glGetUniformLocation(shaderProgramTexture01.ID, "view");
        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);


        float radius = 10.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        glm::mat4 view_rotation = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        view_rotation = glm::lookAt(
            glm::vec3(camX, 0.0, camZ),//position
            glm::vec3(0.0, 0.0, 0.0),//focuspoint
            glm::vec3(0.0, 1.0, 0.0)//up
        );
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view_rotation[0][0]);



            // projection matrix
        unsigned int projectionLoc  = glGetUniformLocation(shaderProgramTexture01.ID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);

        
        shaderProgramTexture01.setFloat("mixValue", mixValue);


        



        glBindVertexArray(VAOs[1]);
        //glDrawArrays(GL_TRIANGLES, 0, 36);
        
        for (unsigned int i = 0; i < 10; ++i)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            
            //if(i==0 | (i+1)%3==0)
            if(i%3==0)
            {
            model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
            if( k_lock == 0)
            cout << "rotation number is: " << i << endl;
            }
            unsigned int modelLoc = glGetUniformLocation(shaderProgramTexture01.ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        k_lock = 1;




        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(4, VAOs);
    glDeleteBuffers(4, VBOs);
    glDeleteBuffers(4, EBOs);




    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        mixValue += 0.01f; // change this value accordingly (might be too slow or too fast based on system hardware)
        std::cout << "mixValue, the percentage of texture2 is: " << mixValue << std::endl;
        if(mixValue >= 1.0f)
            mixValue = 1.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        mixValue -= 0.01f; // change this value accordingly (might be too slow or too fast based on system hardware)
        std::cout << "mixValue, the percentage of texture2 is: " << mixValue << std::endl;
        if (mixValue <= 0.0f)
            mixValue = 0.0f;
    }
    

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



    