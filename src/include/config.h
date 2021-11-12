//
// Created by cherry on 2021/11/6.
//

#ifndef MODERNOPENGL_CONFIG_H
#define MODERNOPENGL_CONFIG_H

//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;

// 摄像头相关
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
float speed = 0;
int cnt = 0;

const std::string image1 = "../images/container.jpg";
//const std::string image5 = "../images/awesomeface.png";
//const std::string image1 = "../images/xkb.jpg";
//const std::string image4 = "../images/2.gif";
const std::string image2 = "../images/dance.png";
//const std::string image2 = "../images/fff.png";

std::string vs = "../src/shader/shader.vs";
std::string fs = "../src/shader/shader.fs";

std::string vs02 = "../src/shader/shader02.vs";
std::string fs02 = "../src/shader/shader.fs";

std::string vs03 = "../src/shader/shader03.vs";
std::string fs03 = "../src/shader/shader03.fs";

//// 定义顶点数组
//float vertices[] = {
////     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
//        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
//        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
//        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
//};
//const unsigned int verticesSize = sizeof(vertices);
//
//unsigned int indices[] = { // 注意索引从0开始!
//        0, 1, 3, // 第一个三角形
//        1, 2, 3  // 第二个三角形
//};
//const unsigned int indicesSize = sizeof(indices);

//// 纹理数组
//float texCoords[] = {
//        0.5f,  0.5f,// 右上
//        0.5f, -0.5,// 右下
//        -0.5f, -0.5,// 左下
//        -0.5f,  0.5,// 左上
//};
#endif //MODERNOPENGL_CONFIG_H
