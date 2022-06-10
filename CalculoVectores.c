#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"Vectores.h"
#define PI 3.14159265358979

Vector creaVector(double x, double y, double z) {
	
	Vector vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;

}

void imprimeVector(Vector vec, double x, double y, double z) {

	/*printf("Vector = %f, %f, %f \r\n", vec.x, vec.y, vec.z);*/

}

double moduloVector(Vector vec) {

	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));

}

Vector vectorUnitario(Vector vec) {
	
	Vector unitario;
	unitario.x = vec.x / moduloVector(vec);
	unitario.y = vec.y / moduloVector(vec);
	unitario.z = vec.z / moduloVector(vec);
	return unitario;

}

Vector sumaVectores(Vector vec1, Vector vec2) {

	Vector resultadosuma;
	resultadosuma.x = vec1.x + vec2.x;
	resultadosuma.y = vec1.y + vec2.y;
	resultadosuma.z = vec1.z + vec2.z;
	return resultadosuma;

}

Vector restaVectores(Vector vec1, Vector vec2) {

	Vector resultadoresta;
	resultadoresta.x = vec1.x - vec2.x;
	resultadoresta.y = vec1.y - vec2.y;
	resultadoresta.z = vec1.z - vec2.z;
	return resultadoresta;

}

Vector distanciaPuntos(Punto p1, Punto p2) {
	
	Vector auxiliar;
	auxiliar.x = p1.x - p2.x;
	auxiliar.y = p1.y - p2.y;
	auxiliar.z = p1.z - p2.z;
	return auxiliar;

}

Vector realPorVector(Vector v, double x) {

	Vector vec;
	vec.x = v.x * x;
	vec.y = v.y * x;
	vec.z = v.z * x;
	return vec;

}

double productoEscalar(Vector v, Vector w) {

	double escalar;
	escalar = v.x * w.x + v.y * w.y + v.z * w.z;
	return escalar;
}

Vector productoVectorial(Vector v, Vector w) {

	Vector vectorial;
	vectorial.x = (v.y * w.z - w.y * v.z);
	vectorial.y = -(v.x * w.z - w.x * v.z);
	vectorial.z = (v.x * w.y - w.x * v.y);
	return vectorial;

}

double anguloVectores(Vector v, Vector w) {

	return ((acos(productoEscalar(v, w) / (moduloVector(v) * moduloVector(w)))) * (360 / (2 * PI)));

}

Recta creaRecta(Vector v, Vector p) {

	Recta rec;
	rec.director = v;
	rec.puntorecta = p;
	return rec;

}

Punto creaPunto(double x, double y, double z) {

	Punto pto;
	pto.x = x;
	pto.y = y;
	pto.z = z;
	return pto;

}

double distanciaPuntoRecta(Recta r, Vector p) {

	Vector pto;
	Vector rcta;
	double distancia;

	pto = restaVectores(p, r.puntorecta);
	distancia = moduloVector(productoVectorial(pto, r.director)) / moduloVector(r.director);
	
	return distancia;

}

Vector rotacionPuntoRecta(Recta r, Vector p, double ang) {

	Vector resultado;
	double angulo = ang*(PI/180);
	Vector director = vectorUnitario(r.director);

	resultado.x = (cos(angulo) + pow(director.x, 2) * (1 - cos(angulo))) * p.x + (director.x * director.y * (1 - cos(angulo)) - director.z * sin(angulo))*p.y + (director.x * director.z * (1 - cos(angulo)) + director.y * sin(angulo))*p.z;
	resultado.y = (director.y * director.x * (1 - cos(angulo)) + director.z * sin(angulo)) * p.x + (cos(angulo) + pow(director.y, 2) * (1 - cos(angulo)))*p.y + (director.y * director.z * (1 - cos(angulo)) - director.x * sin(angulo))*p.z;
	resultado.z = (director.z * director.x * (1 - cos(angulo)) - director.y * sin(angulo)) * p.x + (director.z * director.y * (1 - cos(angulo)) + director.x * sin(angulo)) * p.y + (cos(angulo) + pow(director.z, 2) * (1 - cos(angulo)))*p.z;
	return resultado;

	/*for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("| %d |", resultadorotacion[i][j]);
		}
		printf("\n");
	}*/
}


Plano creaPlanoVectorPunto(Vector normal, Vector punto) { //Le paso el punto como vector por comodidad

	Plano auxiliar;
	auxiliar.normal.x = normal.x;
	auxiliar.normal.y = normal.y;
	auxiliar.normal.z = normal.z;
	auxiliar.puntoplano.x = punto.x;
	auxiliar.puntoplano.y = punto.y;
	auxiliar.puntoplano.z = punto.z;

	//Cálculo de la ecuación del plano como Ax + By + Cz + D = 0
	auxiliar.a = auxiliar.normal.x;
	auxiliar.b = auxiliar.normal.y;
	auxiliar.c = auxiliar.normal.z;
	auxiliar.d = -(auxiliar.a * punto.x + auxiliar.b * punto.y + auxiliar.c * punto.z);
	return auxiliar;

}

double distanciaPuntoPlano(Plano p, Vector aux) {
	
	return fabs(p.a * aux.x + p.b * aux.y + p.c * aux.z + p.d) / sqrt(pow(p.a, 2) + pow(p.b, 2) + pow(p.c, 2));

}

Plano creaPlanoTresPuntos(Vector v1, Vector v2, Vector v3) {

	Vector x = restaVectores(v2, v1);
	Vector y = restaVectores(v3, v1);
	return creaPlanoVectorPunto(productoVectorial(y, x), v1);

}

double anguloVectoresRad(Vector v, Vector w) {

	return ((acos(productoEscalar(v, w) / (moduloVector(v) * moduloVector(w)))));

}