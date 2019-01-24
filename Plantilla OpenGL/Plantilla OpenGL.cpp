// Plantilla OpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarPuntos() {
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex3f(0.5f, 0.1f, 0.0f);
	glColor3f(0, 0, 0);
	glVertex3f(0.55f, 0.1f, 0.0f);
	glEnd();
}

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

void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0.7);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);

	glVertex3f(0, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0.2, 0.6, 1);
	glVertex3f(1, 1, 0);

	glEnd();

}

void dibujar() {
	//dibujarTRiangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineContinua();
	//dibujarTrianguloContinuo();
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
		glClearColor(1, 0, 0, 0);
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

