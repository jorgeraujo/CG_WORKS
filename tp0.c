/* ===================================================================================
	Departamento Eng. Informatica - FCTUC
	Computacao Grafica - 2015/16
	................................................... PMartins/JArrais
	Trabalho 0 - Introducao ao OpenGL
======================================================================================= */


//.................................................... Bibliotecas necessarias
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



//.................................................... Variaveis
GLfloat r,g,b;						// cor RGB


//-----------------------------------------------------------------------------------
//																		Init
//-----------------------------------------------------------------------------------
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);	//....	Cor para apagar (Branco)
	gluOrtho2D(0, 1, 0, 1);		//....	Definicao sistema coordenadas area de desenho
	glShadeModel(GL_FLAT);				//....  Interpolacao de cor com base na cor dos vertices
	r=1; g=0; b=0;						//....  Vermelho
}

void keyboard(unsigned char key, int x, int y){

	switch (key) {
	case 'r':
		r=1.0; g=0.0; b=0.0;
		glutPostRedisplay();
		break;

	case 'g':
		r=0.0; g=1.0; b=0.0;
		glutPostRedisplay();
		break;

	case 'b':
		r=0.0; g=0.0; b=1.0;
		glutPostRedisplay();
		break;

	case 27:					//tecla ESCAPE
		exit(0);
		break;
	}
}

//---------------------------------------- Fun�cao callback de desenho (principal)
void draw(void)
{

	glClear(GL_COLOR_BUFFER_BIT);			//....	Apaga ecra

 	glColor3f (r, g, b);			//....	Especfica cor actual
 	glBegin(GL_POLYGON);			//.... Desenha poligno
 		glVertex2f(0.25,0.25);      //.... Especifica os v�rtices
	 	glVertex2f(0.75,0.25);
		glVertex2f(0.75,0.75);
	 	glVertex2f(0.25,0.75);
 	glEnd();

	glutSwapBuffers();					//.. actualiza ecran
}


//-----------------------------------------------------------------------------------
//																		         MAIN
//-----------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 glutInit(&argc, argv);							//===1:Inicia janela
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   //		:Double mode, RBG
     glutInitWindowSize(600,500);					//		:dimensoes (pixeis)
     glutInitWindowPosition(200,100);				//		:localizacao da janela
	 glutCreateWindow("Exemplo inicial");           //      :criacao da janela

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 init();									//===2:Inicia estado/parametros

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
													//===3:Definicao callbaks
	 glutDisplayFunc(draw);						//		:desenho
	 glutKeyboardFunc(keyboard);						//		:eventos teclado

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 glutMainLoop();								//===4:Inicia processamento


    return 0;
}
