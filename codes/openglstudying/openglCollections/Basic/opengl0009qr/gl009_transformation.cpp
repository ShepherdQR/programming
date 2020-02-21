
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
#include "include/functions.h"

#include "resources/data/data.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float color_bump_back = 1.0;// set 0 to stop bumpping.
float mixValue = 0.2f; // mixValue * texture2 + (1 - mixValue) * texture1




int main()
{
    
    //glm_check_qr();

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));//将矩阵向要进行移动场景的反方向移动。
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH *1.0f / (float)SCR_HEIGHT, 0.1f, 100.0f);

    glm::mat4 model3d = projection * view * model;
    
    

    


    auto t_start = std::chrono::high_resolution_clock::now();

    





    // step1 initialization starts-------

        // glfw: initialize and configure
    glfwInit_qr(3, 3);//version
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL_qr", NULL, NULL);// glfw window creation
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        //glad: load all OpenGL function pointers
    gladLoad_check_qr();

    // step1 initialization ends-------

    // ================================

    // step2 compile and bind shaders start---

    Shader shaderProgramColorPalette("vertex001.qr", "fragment001.qr");
    Shader shaderProgramColorChanging("vertex001.qr", "fragment002.qr");

    Shader shaderProgramTexture01("vertex002_tex.qr", "fragment003_tex.qr");


    // step2 compile and bind shaders end---

    // =================================


    // step3 input data to GPU starts-------
    // set up vertex data (and buffer(s)) and configure vertex attributes
    


    unsigned int VAOs[3], VBOs[3], EBOs[3];
    glGenVertexArrays(3, VAOs);// 注意创建的是VAO时此处要 &VAO
    glGenBuffers(3, VBOs);
    glGenBuffers(3, EBOs);//必须在每次要用索引渲染一个物体时绑定相应的EBO


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





    //--- third triangles setup
    glBindVertexArray(VAOs[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_tex), vertices_tex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_tex), indices_tex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

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




        // render shaderProgramTexture01 --3
        shaderProgramTexture01.use();//!!Attention, use before setting its parameters.
        
            // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);//激活纹理单元.纹理单元GL_TEXTURE0默认总是被激活
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);


        //---- first draw -----01
        //实际的变换顺序应该与阅读顺序相反.
        //如果在代码中先位移再旋转，实际的变换是先旋转再位移
        glm::mat4 transform = glm::mat4(1.0f);
        //transform = glm::scale(transform, glm::vec3(0.5f, 0.5f, 1.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));//radians把角度转化为弧度

        unsigned int transformLoc = glGetUniformLocation(shaderProgramTexture01.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));//参数：变量位置，传送参数个数，是否转置（GLM的默认布局就是列主序，(Column-major Ordering)），

        shaderProgramTexture01.setFloat("mixValue", mixValue);

        glBindVertexArray(VAOs[2]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        //---- second draw -----02
        transform = glm::mat4(1.0f);
        float scaleAmount =pow( sin((float)glfwGetTime()), 2);
        transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, 1.0f));
        shaderProgramTexture01.use();
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]); // this time take the matrix value array's first element as its memory pointer value

        //shaderProgramTexture01.setFloat("mixValue", mixValue);//no need
        // glBindVertexArray(VAOs[2]);// no need
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        int modelLoc = glGetUniformLocation(shaderProgramTexture01.ID, "model3d");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model3d));// 观察矩阵和投影矩阵与之类似







        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(3, VAOs);
    glDeleteBuffers(3, VBOs);
    glDeleteBuffers(3, EBOs);

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



    