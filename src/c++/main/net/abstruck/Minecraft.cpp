#include <iostream>
#include <string>
//GLEW库
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW库
#include <GLFW/glfw3.h>
//GLM库
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
int WIDTH = 854, HEIGHT = 480;
const string MC = "Minecraft";
const string VERSION = "21w42a";
string GAME_STATE = "";
bool keys[1024];

int main() {
	//初始化GLFW
	glfwInit();

	//配置GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//启用双缓存区
	glfwWindowHint(GL_DOUBLEBUFFER, 1);

	//创建窗口
	GLFWwindow *window =
	    glfwCreateWindow(WIDTH, HEIGHT,
	    (MC + " - " + VERSION+GAME_STATE).c_str(), //Mincraft窗口！
		nullptr, nullptr);
	glfwMakeContextCurrent(window);

	//回调函数设置
	glfwSetKeyCallback(window, key_callback);

	//检查窗口是否成功打开
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) { //初始化GLEW
		cout << "[Error]:Failed to initialize GLEW!" << endl;
		glfwTerminate();
		return -1;
	}

	//窗口大小设置
	glViewport(0, 0, WIDTH, HEIGHT);

	//配置OpenGL
	glEnable(GL_DEPTH_TEST);
	
	//保持窗口打开
	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();

	return 0;
}
//按键 按下/释放 检时调用
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024){
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

