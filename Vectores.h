#pragma once

typedef struct {
	double x, y, z;
} Vector;

typedef struct {
	double x, y, z;
} Punto;

typedef struct {
	Vector director;
	Vector puntorecta;
}Recta;

typedef struct {
	Vector normal;
	Vector puntoplano;
	double a, b, c, d;
}Plano;

Vector creaVector (double x, double y, double z); //Funci�n que crea un vector

void imprimeVector (Vector v); //Funci�n que visualiza un vector

double moduloVector(Vector v); //Funci�n que calcula el m�dulo de un vector

Vector vectorUnitario(Vector v); //Funci�n que calcula el vector unitario

Vector sumaVectores(Vector v, Vector w); //Funci�n que suma dos vectores

Vector restaVectores(Vector v, Vector w); //Funci�n que resta dos vectores

Vector distanciaPuntos(Punto p1, Punto p2); //Funci�n que calcula la distancia entre dos puntos

Vector realPorVector(Vector v, double x); //Funci�n que calcula el producto de un n�mero real por un vector

double productoEscalar(Vector v, Vector w); //Funci�n que calcula el producto escalar entre dos vectores

Vector productoVectorial(Vector v, Vector w); //Funci�n que calcula el producto vectorial entre dos vectores

double anguloVectores(Vector v, Vector w); //Funci�n que calcula el �ngulo entre dos vectores en grados

Punto creaPunto(double x, double y, double z); //Funci�n que crea un punto

Recta creaRecta(Vector v, Vector p); //Funci�n que crea una recta pas�ndole un vector director y un punto

double distanciaPuntoRecta(Recta r, Vector p); //Funci�n que calcula la distancia de un punto a una recta

Vector rotacionPuntoRecta(Recta r, Vector p, double angulo); //Funci�n que calcula la rotaci�n de un punto con respecto a una recta

Plano creaPlanoVectorPunto(Vector normal, Vector punto); //Funci�n que crea un plano que contiene un punto y es normal a un vector

double distanciaPuntoPlano(Plano p, Vector aux); //Funcion que calcula la distancia de un punto a un plano

Plano creaPlanoTresPuntos(Vector p1, Vector p2, Vector p3); //Funci�n que crea un plano a partir de 3 puntos (Para las planchas)

double anguloVectoresRad(Vector v, Vector w); //Funci�n que calcula el �ngulo entre dos vectores en radianes
