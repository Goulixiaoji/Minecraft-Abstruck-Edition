#include <iostream>
#include <string>
//GLEW��
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW��
#include <GLFW/glfw3.h>
//GLM��
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
	//��ʼ��GLFW
	glfwInit();

	//����GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//����˫������
	glfwWindowHint(GL_DOUBLEBUFFER, 1);

	//��������
	GLFWwindow *window =
	    glfwCreateWindow(WIDTH, HEIGHT,
	    (MC + " - " + VERSION+GAME_STATE).c_str(), //Mincraft���ڣ�
		nullptr, nullptr);
	glfwMakeContextCurrent(window);

	//�ص���������
	glfwSetKeyCallback(window, key_callback);

	//��鴰���Ƿ�ɹ���
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) { //��ʼ��GLEW
		cout << "[Error]:Failed to initialize GLEW!" << endl;
		glfwTerminate();
		return -1;
	}

	//���ڴ�С����
	glViewport(0, 0, WIDTH, HEIGHT);

	//����OpenGL
	glEnable(GL_DEPTH_TEST);
	
	//���ִ��ڴ�
	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();

	return 0;
}
//���� ����/�ͷ� ��ʱ����
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

