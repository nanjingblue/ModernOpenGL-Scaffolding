#include <iostream>
#include <vector>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

// 暂时将顶点着色器的源代码硬编码在代码文件顶部的C风格字符串中
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
// 暂时将片段着色器的源代码硬编码在代码文件顶部的C风格字符串中
const char *fragmentShaderSource = "#version 330 core\n"
                                "out vec4 FragColor;\n"
                                "\n"
                                "void main()\n"
                                "{\n"
                                "    FragColor = vec4(1.0f, 0.5f, 0.2f"
                                ", 1.0f);\n"
                                "}\0";

// 定义顶点数组
float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};
const unsigned int size = sizeof(vertices);

/*
 * framebuffer_size_callback
 * 窗口大小改变后的回调函数 若手动更改了窗口大小将对OpenGL渲染窗口尺寸进行更新
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/*
 * processInput
 * 这个函数将会返回这个按键是否正在被按下
 */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow* initGlfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);      // MAC OS
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    return window;
}

void initGlad() {
    // GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
}

unsigned int initOpenGL(GLFWwindow *window) {
    glViewport(0, 0, 800, 600); // OpenGL渲染窗口的尺寸大小
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // // 创建着色器对象
    unsigned int vertextShader;
    vertextShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertextShader, 1, &vertexShaderSource, nullptr);     // 着色器源码附加到着色器对象
    glCompileShader(vertextShader);
    // 创建片段着色器
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    // 创建着色器程序
    // 着色器程序对象(Shader Program Object)是多个着色器合并之后并最终链接完成的版本
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertextShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // 链接到程序对象后，删除着色器对象，不在需要他们
    glDeleteShader(vertextShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

// makeVao 执行初始化并从提供的点里面返回一个顶点数组
unsigned int makeVAO(float vertices[]) {
    // 生成 VBO 对象
    unsigned int VBO;
    glGenBuffers(1, &VBO);  // 赋予一个缓冲 ID
    glBindBuffer(GL_ARRAY_BUFFER, VBO);     // 把新创建的缓冲绑定到 顶点缓冲对象的缓冲类型 GL_ARRAY_BUFFER目标上
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    // 创建 VAO 对象
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);     // 绑定和配置对应的VBO和属性指针
    glBindVertexArray(VAO);

    // OpenGL该如何解析顶点数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    return VAO;
}

int main() {

    GLFWwindow* window = initGlfw();
    initGlad();
    unsigned int shaderProgram = initOpenGL(window);

    // 创建顶点数组对象
    unsigned int VAO = makeVAO(vertices);

    // 渲染循环
    while(!glfwWindowShouldClose(window)) {
        // 键盘输入
        processInput(window);
        // 渲染
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);       // 自定义的颜色清空屏幕
        glClear(GL_COLOR_BUFFER_BIT);       // 使用颜色缓冲位

        // 激活着色器程序对象
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);        // 交换缓冲
        glfwPollEvents();   // 查有没有触发什么事件
    }
    glfwTerminate();        // 渲染循环结束后我们需要正确释放/删除之前的分配的所有资源
    return 0;
}
