//


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