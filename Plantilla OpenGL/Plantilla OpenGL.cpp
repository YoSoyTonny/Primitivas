// Plantilla OpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include <math.h>

using namespace std;

void dibujarLineas() {
	glBegin(GL_LINES);

	glColor3f(1, 1, 1);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.4, 0);

	glVertex3f(0.2, 0.4, 0);
	glVertex3f(-0.2, 0.4, 0);

	glEnd();

}

void dibujarLineContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0.3, -0.2, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);

	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1, 1, 1);

	glVertex3f(0, 0, 0);
	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, -0.2, 0);
	glVertex3f(0.5, -0.5, 0);

	glEnd();
}

void dibujarCuadrado() {
	glBegin(GL_QUADS);
	
	glEnd();
}

void dibujarPoligonos() {
	glBegin(GL_POLYGON);

	glColor3f(1, 0.8, 0);

	for (int i = 0; i < 360; i++)
	{
		glVertex3f(0.2 * cos((double)i*3.14159/180.0) - 0.7 , 0.2 * sin((double)i*3.14159/180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1, 0.6, 0);

	for (int i = 0; i < 360; i++)
	{
		glVertex3f(0.08 * cos((double)i*3.14159 / 180.0) - 0.7, 0.08 * sin((double)i*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	for (int o = 0; o < 360; o++)
	{
		glVertex3f(0.1 * cos((double)o*3.14159 / 180.0) - 0.2, 0.1 * sin((double)o*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	for (int o = 0; o < 360; o++)
	{
		glVertex3f(0.1 * cos((double)o*3.14159 / 180.0) - 0.1, 0.1 * sin((double)o*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	for (int o = 0; o < 360; o++)
	{
		glVertex3f(0.1 * cos((double)o*3.14159 / 180.0) + 0.3, 0.1 * sin((double)o*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	for (int o = 0; o < 360; o++)
	{
		glVertex3f(0.1 * cos((double)o*3.14159 / 180.0) + 0.4, 0.1 * sin((double)o*3.14159 / 180.0) + 0.7, 0);
	}
	glEnd();

	
}

void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0.7);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glEnd();

}

void dibujar() {
	//dibujarTriangulos();
	dibujarPoligonos();
	//dibujarCuadrado();
}

void actualizar() {


}


int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//Si no se pudo iniciar glfw
	//terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar el glfw
	//Entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	//Si no se puede iniciar la ventana
	//terminamos la ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el control
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Activa funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0, 0, 0.2, 0);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los Buffer
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

