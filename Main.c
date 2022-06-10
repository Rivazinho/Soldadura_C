#include <stdio.h>
#include <stdlib.h>
#include"Vectores.h"
#define PI 3.14159265358979

int main() {

	Vector v;
	Vector v1;
	Vector v2;
	double resultadomodulo;
	Vector unitario;
	Vector suma;
	Vector resta;
	Vector distanciapuntos;
	Vector realporvector;
	double escalar;
	Vector vectorial;
	double angulo;
	Recta r;
	Punto p1;
	Punto p2;
	double distanciapr;
	double rotacion[3][3];
	double angulorotacion;
	int i, j, k = 0;
	Plano plano;
	double distanciapp;

	/********************************************************************/
	/********************** Prueba de funciones *************************/
	/********************************************************************/

	/*v = creaVector(1.0, 2.0, 3.0);
	v1 = creaVector(2.0, 3.0, 4.0);
	v2 = creaVector(4.0, 3.0, 2.0);
	p1 = creaPunto(2.0, 3.0, 7.0);
	p2 = creaPunto(3.0, 2.0, 6.0);

	imprimeVector(v);

	resultadomodulo = moduloVector(v);
	printf("El modulo del vector es = %f\r\n", resultadomodulo);

	unitario = vectorUnitario(v);
	printf("El vector unitario es = %f, %f, %f \r\n", unitario);

	suma = sumaVectores(v1, v2);
	printf("La suma de ambos vectores es = %f, %f, %f \r\n", suma);

	resta = restaVectores(v1, v2);
	printf("La resta de ambos vectores es = %f, %f, %f \r\n", resta);

	distanciapuntos = distanciaPuntos(p1, p2);
	printf("La distancia de ambos puntos es = %f \r\n", distanciapuntos);

	realporvector = realPorVector(v1, 5.0); //Pongo 5 para probar
	printf("El resultado es = %f, %f, %f \r\n", realporvector);

	escalar = productoEscalar(v1, v2);
	printf("El producto escalar de ambos vectores es = %f \r\n", escalar);

	vectorial = productoVectorial(v1, v2);
	printf("El producto vectorial de ambos vectores es = %f, %f, %f \r\n", vectorial);

	angulo = anguloVectores(v1, v2);
	printf("El angulo entre ambos vectores es = %f \r\n", angulo);

	r = creaRecta(v1, v2);

	printf("La recta tiene un vector director = %f, %f, %f ", r.director);
	printf("y pasa por el punto = %f, %f, %f \r\n", r.puntorecta);

	distanciapr = distanciaPuntoRecta(r, v1);
	printf("La distancia del punto a la recta es = %f \n", distanciapr);

	printf("El resultado de la rotacion es = \n");
	angulorotacion = 2;
	rotacion[3][3] = rotacionPuntoRecta(r, p1, angulo);

	plano = creaPlanoVectorPunto(v1, v2);
	printf("Los coeficientes del plano son = %f, %f, %f, %f \r\n", plano);

	distanciapp = distanciaPuntoPlano(plano, v1);
	printf("La distancia del punto al plano es = %f \r\n", distanciapp);*/

	/********************************************************************/
	/****************** Posiciones del electrodo ************************/
	/********************************************************************/


	Vector P1, P2, P3, P4; // Vectores de las planchas
	Plano Plancha1, Plancha2;
	Vector elevacion;
	double distanciasoldado = 0.2;
	Vector lineadesplazamiento;
	Recta lineasoldado;
	Vector electrodo;

	P1 = creaVector(5.07, 3.28, 2.16);
	P2 = creaVector(10.53, 12.19, 17.72);
	P3 = creaVector(21.01, 15.63, 6.97);
	P4 = creaVector(-3.15, 4.96, 0.32);

	Plancha1 = creaPlanoTresPuntos(P1, P2, P3);
	Plancha2 = creaPlanoTresPuntos(P2, P1, P4);

	lineasoldado.director = restaVectores(P2, P1);
	lineasoldado.puntorecta = P1;

	int npuntos = 19;
	double longitudtotal = moduloVector(restaVectores(P2, P1));
	double intervalo = (longitudtotal / npuntos);
	double anguloplanchas;


	//Código para calcular el vector de módulo 0.2 que forma el mismo ángulo respecto a ambas planchas y
	//que estará situado a la distancia requerida sobre la línea de puntos de soldadura
	elevacion = realPorVector(vectorUnitario(sumaVectores(vectorUnitario(Plancha1.normal), vectorUnitario(Plancha2.normal))),distanciasoldado);
	
	//Código que calcula el vector que separa los puntos de la línea de soldadura, para recorrer la propia
	//línea usando 20 vectores unitarios
	lineadesplazamiento = realPorVector(vectorUnitario(lineasoldado.director), intervalo);

	//Código que partiendo de P1, calcula los sucesivos 20 puntos en la linea de unión de ambas planchas
	printf(" Posiciones del electrodo, distancia a la linea de soldadura y distancia a las planchas \r\n");
	for (k = 0; k < 20; k++) {
		electrodo = sumaVectores(sumaVectores(P1, realPorVector(lineadesplazamiento, k)), elevacion);
		printf("(%8.5f, %8.5f, %8.5f)", electrodo.x, electrodo.y, electrodo.z);
		printf("             %3.1f             %8.6f             %8.6f             \r\n",
			distanciaPuntoRecta(lineasoldado, electrodo), distanciaPuntoPlano(Plancha1, electrodo), distanciaPuntoPlano(Plancha2, electrodo));
	}

	anguloplanchas = 180.0-anguloVectores(Plancha1.normal, Plancha2.normal);
	printf("\n Angulo entre planchas = %f \r\n", anguloplanchas);

	/********************************************************************/
	/******************* Posicionamiento de la cámara *******************/
	/********************************************************************/

	Vector camara1;
	Vector camara2;
	Vector lineadesplazamientocamara;
	Vector elevacioncamara;
	Vector elevacioncamara1;
	Vector elevacioncamara2;

	double angulodesplazado = (anguloplanchas / 2.0) - (anguloplanchas /3.0);
	int npuntoscamara = 9;
	double intervalocamara = (longitudtotal / npuntoscamara);

	elevacioncamara = vectorUnitario(elevacion);
	elevacioncamara1 = rotacionPuntoRecta(lineasoldado, elevacioncamara, angulodesplazado);
	elevacioncamara2 = rotacionPuntoRecta(lineasoldado, elevacioncamara, -(angulodesplazado));

	lineadesplazamientocamara = realPorVector(vectorUnitario(lineasoldado.director), intervalocamara);

	printf("\n Posiciones de la camara y distancias a la linea de soldadura \r\n");
	for (k = 0; k < 10; k++) {
		camara1 = sumaVectores(sumaVectores(P1, realPorVector(lineadesplazamientocamara, k)), elevacioncamara1);
		printf("(%8.5f, %8.5f, %8.5f)", camara1.x, camara1.y, camara1.z);
		camara2 = sumaVectores(sumaVectores(P1, realPorVector(lineadesplazamientocamara, k)), elevacioncamara2);
		printf("(%8.5f, %8.5f, %8.5f)", camara2.x, camara2.y, camara2.z);
		printf("             %8.6f             %8.6f             \r\n",
			distanciaPuntoRecta(lineasoldado, camara1), distanciaPuntoRecta(lineasoldado, camara2));
	}
	return 0;
}