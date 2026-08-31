//Práctica#2
//Guerra Marcelino Brenda Paola
//Fecha de entrega: 30 de agosto de 2026
//Número de cuenta: 319021068

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Práctica 2 - Brenda Guerra", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//0.5f,  0.5f, 0.0f,    1.0f,1.0f,0.0f,  // top right
		//0.5f, -0.5f, 0.0f,    1.0f,1.0f,0.0f,  // bottom right
		//-0.5f, -0.5f, 0.0f,   1.0f,0.0f,1.0f,  // bottom left
		//-0.5f,  0.5f, 0.0f,   1.0f,1.0f,0.0f, // top left 
	
		// FONDO	
		-1.0f, 1.0f, 0.0f,      1.0f,0.0f,0.0f, //0
		-1.0f, 0.5f, 0.0f,      1.0f,0.0f,0.0f, //1
		-0.5f, 1.0f, 0.0f,      1.0f,0.0f,0.0f, //2

		-1.0f, 0.5f, 0.0f,      0.863f,0.078f,0.235f, //1
		-0.5f, 1.0f, 0.0f,      0.863f,0.078f,0.235f, //2
		-1.0f, 0.35f, 0.0f,     0.863f,0.078f,0.235f, //3

		-0.5f, 1.0f, 0.0f,      0.863f,0.078f,0.235f, //2
		-1.0f, 0.35f, 0.0f,     0.863f,0.078f,0.235f, //3
		0.0f, 0.3f, 0.0f,       0.863f,0.078f,0.235f, //4

		-0.5f, 1.0f, 0.0f,      0.722f,0.451f,0.200f, //2
		0.0f, 0.3f, 0.0f,       0.722f,0.451f,0.200f, //4
		0.0f, 1.0f, 0.0f,       0.722f,0.451f,0.200f, //5

		0.0f, 0.3f, 0.0f,       0.824f,0.706f,0.549f, //4
		0.0f, 1.0f, 0.0f,       0.824f,0.706f,0.549f, //5
		0.5f, 1.0f, 0.0f,       0.824f,0.706f,0.549f, //6

		0.0f, 0.3f, 0.0f,       0.824f,0.706f,0.549f, //4
		0.5f, 1.0f, 0.0f,       0.824f,0.706f,0.549f, //6
		0.5f, 0.4f, 0.0f,       0.824f,0.706f,0.549f, //7

		0.5f, 1.0f, 0.0f,       0.902f,0.824f,0.039f, //6
		0.5f, 0.4f, 0.0f,       0.902f,0.824f,0.039f, //7
		1.0f, 1.0f, 0.0f,       0.902f,0.824f,0.039f, //8

		0.5f, 0.4f, 0.0f,       0.902f,0.824f,0.039f, //7
		1.0f, 1.0f, 0.0f,       0.902f,0.824f,0.039f, //8
		1.0f, 0.5f, 0.0f,       0.902f,0.824f,0.039f, //9

		-1.0f, 0.35f, 0.0f,     1.0f,0.498f,0.314f, //3
		0.0f, 0.3f, 0.0f,       1.0f,0.498f,0.314f, //4
		-1.0f, 0.1f, 0.0f,      1.0f,0.498f,0.314f, //10

		-1.0f, 0.1f, 0.0f,      1.0f,0.498f,0.314f, //10
		-1.0f, -0.2f, 0.0f,     1.0f,0.498f,0.314f, //11
		-0.4f, -0.2f, 0.0f,     1.0f,0.498f,0.314f, //12

		0.5f, 0.4f, 0.0f,       1.0f,1.0f,0.0f, //7
		1.0f, 0.5f, 0.0f,       1.0f,1.0f,0.0f, //9
		1.0f, 0.2f, 0.0f,       1.0f,1.0f,0.0f, //13

		0.5f, 0.4f, 0.0f,       0.902f,0.824f,0.039f, //7
		1.0f, 0.2f, 0.0f,       0.902f,0.824f,0.039f, //13
		0.55f, -0.05f, 0.0f,    0.902f,0.824f,0.039f, //14

		1.0f, 0.2f, 0.0f,       0.902f,0.824f,0.039f, //13
		0.55f, -0.05f, 0.0f,    0.902f,0.824f,0.039f, //14
		1.0f, 0.0f, 0.0f,       0.902f,0.824f,0.039f, //15

		0.55f, -0.05f, 0.0f,    0.824f,0.706f,0.549f, //14
		1.0f, 0.0f, 0.0f,       0.824f,0.706f,0.549f, //15
		1.0f, -0.25f, 0.0f,     0.824f,0.706f,0.549f, //16

		0.55f, -0.05f, 0.0f,    0.824f,0.706f,0.549f, //14
		1.0f, -0.25f, 0.0f,     0.824f,0.706f,0.549f, //16
		0.6f, -0.24f, 0.0f,     0.824f,0.706f,0.549f, //17

		0.5f, 0.4f, 0.0f,       0.761f,0.494f,0.569f, //7
		0.1f, 0.1f, 0.0f,       0.761f,0.494f,0.569f, //18
		0.55f, -0.05f, 0.0f,    0.761f,0.494f,0.569f, //14

		0.5f, 0.4f, 0.0f,       0.761f,0.494f,0.569f, //7
		0.1f, 0.1f, 0.0f,       0.761f,0.494f,0.569f, //18
		-0.4f, 0.22f, 0.0f,     0.761f,0.494f,0.569f, //19

		-1.0f, 0.1f, 0.0f,      0.941f,0.824f,0.549f, //10
		-0.4f, -0.2f, 0.0f,     0.941f,0.824f,0.549f, //12
		-0.4f, 0.22f, 0.0f,     0.941f,0.824f,0.549f, //19

		0.55f, -0.05f, 0.0f,    1.0f,0.8f,0.8f, //14
		0.6f, -0.24f, 0.0f,     1.0f,0.8f,0.8f, //17
		0.1f, -0.21f, 0.0f,     1.0f,0.8f,0.8f, //20

		0.55f, -0.05f, 0.0f,    1.0f,0.8f,0.8f, //14
		0.1f, 0.1f, 0.0f,       1.0f,0.8f,0.8f, //18
		0.1f, -0.21f, 0.0f,     1.0f,0.8f,0.8f, //20

		-0.4f, -0.2f, 0.0f,     0.933f,0.549f,0.133f, //12
		0.1f, 0.1f, 0.0f,       0.933f,0.549f,0.133f, //18
		-0.4f, 0.22f, 0.0f,     0.933f,0.549f,0.133f, //19

		-0.4f, -0.2f, 0.0f,     0.933f,0.549f,0.133f, //12
		0.1f, 0.1f, 0.0f,       0.933f,0.549f,0.133f, //18
		0.1f, -0.21f, 0.0f,     0.933f,0.549f,0.133f, //20
		
		-0.4f, -0.2f, 0.0f,     0.722f,0.451f,0.2f, //12
		-0.8f, -0.2f, 0.0f,     0.722f,0.451f,0.2f, //21
		-0.4f, -0.05f, 0.0f,    0.722f,0.451f,0.2f, //22

		// MESA
		-1.0f, -0.15f, 0.0f,    1.0f,0.973f,0.2f, //1
		0.3f, -0.22f, 0.0f,     1.0f,0.973f,0.2f, //2
		-1.0f, -0.6f, 0.0f,     1.0f,0.973f,0.2f, //3

		-1.0f, -0.6f, 0.0f,     0.753f,0.753f,0.753f, //3
		-0.8f, -1.0f, 0.0f,     0.753f,0.753f,0.753f, //4
		-1.0f, -1.0f, 0.0f,     0.753f,0.753f,0.753f, //5

		0.3f, -0.22f, 0.0f,     0.898f,0.898f,0.898f, //2
		-1.0f, -0.6f, 0.0f,     0.898f,0.898f,0.898f, //3
		-0.8f, -1.0f, 0.0f,     0.898f,0.898f,0.898f, //4

		-0.8f, -1.0f, 0.0f,     0.863f,0.078f,0.235f, //4
		-0.1f, -0.5f, 0.0f,     0.863f,0.078f,0.235f, //6
		0.0f, -1.0f, 0.0f,      0.863f,0.078f,0.235f, //7

		-0.1f, -0.5f, 0.0f,     0.945f,0.298f,0.298f, //6
		0.0f, -1.0f, 0.0f,      0.945f,0.298f,0.298f, //7
		0.5f, -0.45f, 0.0f,     0.945f,0.298f,0.298f, //8

		0.0f, -1.0f, 0.0f,      0.945f,0.298f,0.298f, //7
		0.5f, -0.45f, 0.0f,     0.945f,0.298f,0.298f, //8
		0.3f, -1.0f, 0.0f,      0.945f,0.298f,0.298f, //9
		
		0.5f, -0.45f, 0.0f,     1.0f,0.961f,0.561f, //8
		0.3f, -1.0f, 0.0f,      1.0f,0.961f,0.561f, //9
		1.0f, -1.0f, 0.0f,      1.0f,0.961f,0.561f, //10

		0.5f, -0.45f, 0.0f,     1.0f,0.961f,0.561f, //8
		1.0f, -1.0f, 0.0f,      1.0f,0.961f,0.561f, //10
		1.0f, -0.4f, 0.0f,      1.0f,0.961f,0.561f, //11

		-0.1f, -0.5f, 0.0f,     1.0f,0.992f,0.816f, //6
		1.0f, -0.42f, 0.0f,      1.0f,0.992f,0.816f, //11
		1.0f, -0.23f, 0.0f,     1.0f,0.992f,0.816f, //12

		0.3f, -0.22f, 0.0f,     1.0f,0.992f,0.816f, //2
		-0.1f, -0.5f, 0.0f,     1.0f,0.992f,0.816f, //6
		1.0f, -0.23f, 0.0f,     1.0f,0.992f,0.816f, //12

		// JARRÓN
		-0.2f, -0.75f, 0.0f,    0.878f,0.745f,1.0f, //1
		-0.08f, -0.75f, 0.0f,   0.878f,0.745f,1.0f, //2
		-0.15f, -0.4f, 0.0f,    0.878f,0.745f,1.0f, //3

		-0.08f, -0.75f, 0.0f,   0.878f,0.745f,1.0f, //2
		-0.15f, -0.4f, 0.0f,    0.878f,0.745f,1.0f, //3
		0.1f, -0.7f, 0.0f,      0.878f,0.745f,1.0f, //4

		0.1f, -0.7f, 0.0f,      0.529f,0.808f,0.922f, //4
		-0.1f, -0.46f, 0.0f,    0.529f,0.808f,0.922f, //5
		0.15f, -0.56f, 0.0f,    0.529f,0.808f,0.922f, //6

		-0.1f, -0.46f, 0.0f,    0.529f,0.808f,0.922f, //5
		0.15f, -0.56f, 0.0f,    0.529f,0.808f,0.922f, //6
		0.12f, -0.35f, 0.0f,    0.529f,0.808f,0.922f, //7

		-0.15f, -0.4f, 0.0f,    0.604f,0.404f,0.804f, //3
		-0.1f, -0.46f, 0.0f,    0.604f,0.404f,0.804f, //5
		0.12f, -0.35f, 0.0f,    0.604f,0.404f,0.804f, //7

		-0.2f, -0.75f, 0.0f,    0.275f,0.510f,0.706f, //1
		-0.35f, -0.65f, 0.0f,   0.275f,0.510f,0.706f, //8
		-0.16f, -0.5f, 0.0f,    0.275f,0.510f,0.706f, //9

		-0.35f, -0.65f, 0.0f,   0.275f,0.510f,0.706f, //8
		-0.16f, -0.5f, 0.0f,    0.275f,0.510f,0.706f, //9
		-0.38f, -0.46f, 0.0f,   0.275f,0.510f,0.706f, //10

		-0.15f, -0.4f, 0.0f,    0.855f,0.439f,0.839f, //3
		-0.16f, -0.5f, 0.0f,    0.855f,0.439f,0.839f, //9
		-0.38f, -0.46f, 0.0f,   0.855f,0.439f,0.839f, //10

		-0.15f, -0.4f, 0.0f,    0.855f,0.439f,0.839f, //3
		-0.38f, -0.46f, 0.0f,   0.855f,0.439f,0.839f, //10
		-0.32f, -0.3f, 0.0f,    0.855f,0.439f,0.839f, //11

		-0.15f, -0.4f, 0.0f,    0.604f,0.404f,0.804f, //3
		0.12f, -0.35f, 0.0f,    0.604f,0.404f,0.804f, //7
		0.01f, -0.1f, 0.0f,     0.604f,0.404f,0.804f, //12

		-0.15f, -0.4f, 0.0f,    0.604f,0.404f,0.804f, //3
		0.01f, -0.1f, 0.0f,     0.604f,0.404f,0.804f, //12
		-0.21f, -0.12f, 0.0f,   0.604f,0.404f,0.804f, //13

		-0.15f, -0.4f, 0.0f,    0.604f,0.404f,0.804f, //3
		-0.21f, -0.12f, 0.0f,   0.604f,0.404f,0.804f, //13
		-0.25f, -0.345f, 0.0f,  0.604f,0.404f,0.804f, //14

		-0.32f, -0.3f, 0.0f,    0.8f,0.918f,0.965f, //11
		-0.25f, -0.345f, 0.0f,  0.8f,0.918f,0.965f, //14
		-0.18f, -0.01f, 0.0f,   0.8f,0.918f,0.965f, //15

		-0.18f, -0.01f, 0.0f,   0.8f,0.918f,0.965f, //15
		-0.2f, -0.1f, 0.0f,     0.8f,0.918f,0.965f, //16
		-0.35f, 0.04f, 0.0f,    0.8f,0.918f,0.965f, //17

		0.01f, -0.1f, 0.0f,     0.686f,0.847f,0.902f, //12
		-0.21f, -0.12f, 0.0f,   0.686f,0.847f,0.902f, //13
		0.08f, -0.06f, 0.0f,    0.686f,0.847f,0.902f, //18

		-0.21f, -0.12f, 0.0f,   0.686f,0.847f,0.902f, //13
		-0.18f, -0.01f, 0.0f,   0.686f,0.847f,0.902f, //15
		0.08f, -0.06f, 0.0f,    0.686f,0.847f,0.902f, //18

		// FLORES
		-0.2f, -0.01f, 0.0f, 	0.0f,0.604f,0.388f, //1 
		-0.17f, -0.015f, 0.0f,  0.0f,0.604f,0.388f, //2
		-0.3f, 0.7f, 0.0f,      0.0f,0.604f,0.388f, //3 

		-0.17f, -0.015f, 0.0f,  0.0f,0.604f,0.388f, //2
		-0.3f, 0.7f, 0.0f,      0.0f,0.604f,0.388f, //3
		-0.27f, 0.7f, 0.0f,     0.0f,0.604f,0.388f, //4

		-0.14f, -0.02f, 0.0f,   0.0f,0.604f,0.388f, //1
		-0.11f, -0.025f, 0.0f,  0.0f,0.604f,0.388f, //2
		-0.14f, 0.7f, 0.0f,     0.0f,0.604f,0.388f, //3

		-0.11f, -0.025f, 0.0f,  0.0f,0.604f,0.388f, //2
		-0.14f, 0.7f, 0.0f,     0.0f,0.604f,0.388f, //3
		-0.11f, 0.7f, 0.0f,     0.0f,0.604f,0.388f, //4

		-0.05f, -0.035f, 0.0f,  0.0f,0.604f,0.388f, //1
		-0.02f, -0.04f, 0.0f,   0.0f,0.604f,0.388f, //2
		0.08f, 0.7f, 0.0f,      0.0f,0.604f,0.388f, //3

		-0.05f, -0.035f, 0.0f,  0.0f,0.604f,0.388f, //1
		0.08f, 0.7f, 0.0f,      0.0f,0.604f,0.388f, //3
		0.05f, 0.7f, 0.0f,      0.0f,0.604f,0.388f, //4

		// PRUEBA
		// FLORES ROSAS

		// FLOR 1
		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.34f, 0.82f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.27f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.27f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.20f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.20f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.21f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.21f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.27f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.27f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.35f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.285f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.35f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.39f, 0.72f, 0.0f, 1.0f, 0.4f, 0.7f,


		// FLOR 2
		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.18f, 0.82f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.11f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.11f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.04f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.04f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.05f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.05f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.11f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.11f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.19f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,

		-0.125f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.19f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.235f, 0.72f, 0.0f, 1.0f, 0.4f, 0.7f,


		// FLORE 3
		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.01f, 0.82f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.08f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,

		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.08f, 0.83f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.15f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,

		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.15f, 0.76f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.14f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,

		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.14f, 0.68f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.08f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,

		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.08f, 0.59f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.00f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,

		0.065f, 0.70f, 0.0f, 1.0f, 0.4f, 0.7f,
		0.00f, 0.61f, 0.0f, 1.0f, 0.4f, 0.7f,
		-0.04f, 0.72f, 0.0f, 1.0f, 0.4f, 0.7f,
	};
	unsigned int indices[] = {  // note that we start from 0!
		1,3,4,// second Triangle
		0,1,3,
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);

		// FONDO
		glDrawArrays(GL_TRIANGLES,0,3); //inicio, vértices
		glDrawArrays(GL_TRIANGLES,3,3);
		glDrawArrays(GL_TRIANGLES,6,3);
		glDrawArrays(GL_TRIANGLES,9,3);
		glDrawArrays(GL_TRIANGLES,12,3);
		glDrawArrays(GL_TRIANGLES,15,3);
		glDrawArrays(GL_TRIANGLES,18,3);
		glDrawArrays(GL_TRIANGLES,21,3);
		glDrawArrays(GL_TRIANGLES,24,3);
		glDrawArrays(GL_TRIANGLES,27,3);
		glDrawArrays(GL_TRIANGLES,30,3);
		glDrawArrays(GL_TRIANGLES,33,3);
		glDrawArrays(GL_TRIANGLES,36,3);
		glDrawArrays(GL_TRIANGLES,39,3);
		glDrawArrays(GL_TRIANGLES,42,3);
		glDrawArrays(GL_TRIANGLES,45,3);
		glDrawArrays(GL_TRIANGLES,48,3);
		glDrawArrays(GL_TRIANGLES,51,3);
		glDrawArrays(GL_TRIANGLES,54,3);
		glDrawArrays(GL_TRIANGLES,57,3);
		glDrawArrays(GL_TRIANGLES,60,3);
		glDrawArrays(GL_TRIANGLES,63,3);
		glDrawArrays(GL_TRIANGLES,66,3);

		// MESA
		glDrawArrays(GL_TRIANGLES,69,3);
		glDrawArrays(GL_TRIANGLES,72,3);
		glDrawArrays(GL_TRIANGLES,75,3);
		glDrawArrays(GL_TRIANGLES,78,3);
		glDrawArrays(GL_TRIANGLES,81,3);
		glDrawArrays(GL_TRIANGLES,84,3);
		glDrawArrays(GL_TRIANGLES,87,3);
		glDrawArrays(GL_TRIANGLES,90,3);
		glDrawArrays(GL_TRIANGLES,93,3);
		glDrawArrays(GL_TRIANGLES,96,3);

		// JARRÓN
		glDrawArrays(GL_TRIANGLES,99,3);
		glDrawArrays(GL_TRIANGLES,102,3);
		glDrawArrays(GL_TRIANGLES,105,3);
		glDrawArrays(GL_TRIANGLES,108,3);
		glDrawArrays(GL_TRIANGLES,111,3);
		glDrawArrays(GL_TRIANGLES,114,3);
		glDrawArrays(GL_TRIANGLES,117,3);
		glDrawArrays(GL_TRIANGLES,120,3);
		glDrawArrays(GL_TRIANGLES,123,3);
		glDrawArrays(GL_TRIANGLES,126,3);
		glDrawArrays(GL_TRIANGLES,129,3);
		glDrawArrays(GL_TRIANGLES,132,3);
		glDrawArrays(GL_TRIANGLES,135,3);
		glDrawArrays(GL_TRIANGLES,138,3);
		glDrawArrays(GL_TRIANGLES,141,3);
		glDrawArrays(GL_TRIANGLES,144,3);

		// FLORES
		glDrawArrays(GL_TRIANGLES,147,3);
		glDrawArrays(GL_TRIANGLES,150,3);
		glDrawArrays(GL_TRIANGLES,153,3);
		glDrawArrays(GL_TRIANGLES,156,3);
		glDrawArrays(GL_TRIANGLES,159,3);
		glDrawArrays(GL_TRIANGLES,162,3);

		// PRUEBA
		// FLORES ROSAS

		// FLOR 1
		glDrawArrays(GL_TRIANGLES, 165, 3);
		glDrawArrays(GL_TRIANGLES, 168, 3);
		glDrawArrays(GL_TRIANGLES, 171, 3);
		glDrawArrays(GL_TRIANGLES, 174, 3);
		glDrawArrays(GL_TRIANGLES, 177, 3);
		glDrawArrays(GL_TRIANGLES, 180, 3);

		// FLOR 2
		glDrawArrays(GL_TRIANGLES, 183, 3);
		glDrawArrays(GL_TRIANGLES, 186, 3);
		glDrawArrays(GL_TRIANGLES, 189, 3);
		glDrawArrays(GL_TRIANGLES, 192, 3);
		glDrawArrays(GL_TRIANGLES, 195, 3);
		glDrawArrays(GL_TRIANGLES, 198, 3);

		// FLOR 3
		glDrawArrays(GL_TRIANGLES, 201, 3);
		glDrawArrays(GL_TRIANGLES, 204, 3);
		glDrawArrays(GL_TRIANGLES, 207, 3);
		glDrawArrays(GL_TRIANGLES, 210, 3);
		glDrawArrays(GL_TRIANGLES, 213, 3);
		glDrawArrays(GL_TRIANGLES, 216, 3);

        //glPointSize(10);
        //glDrawArrays(GL_POINTS,2,2);
        
        //glDrawArrays(GL_LINES,0,4);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
        //glDrawArrays(GL_TRIANGLES,0,3);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);

        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}