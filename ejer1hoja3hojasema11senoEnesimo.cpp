// ConsoleApplication3.cpp : main project file.

#include "stdafx.h"

/*
1 con menu varios
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <iomanip>
using namespace std;
using namespace System;
void ingresapositivo(int *nfact) //recibe con la indereccion, no crea una copia ni guarda direccion manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes
{
	do
	{
		cout << "ingerese numero positivo:";
		cin >> *nfact;  //manipulando o ingresando directamente el valor con la indireccion
	} while (*nfact < 0);
}

void ingresak(int *k) /*recibe con la indereccion, no crea una copia ni guarda direccion
manipula directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes*/

{
	do
	{
		cout << "ingerese k:"; cin >> *k; //manipulando o ingresando directamente el valor con la indireccion
	} while (*k <= 0 || *k > 20);
}
float  factorial(int &i)  // recibiendo con la dirección ahorra 2 bytes
{
	float result = 1;
	int j = 0;
	while (j <= i)
	{
		if (j == 0)
			result = 1;
		else result = result*(2 * j)*(2 * j + 1);
		j++;
	}
	return result;
}
float potencia(float &x, int &i) // recibiendo con la dirección ahorra 2+2 bytes
{
	float result;
	result = pow(x, 2 * i + 1);
	return result;
}
void funcionseno(double *sumaserie) /*recibe con la indereccion, no crea una copia ni guarda direccion manipula
directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes*/
{
	*sumaserie = 0;  //manipulando o ingresando directamente el valor con la indireccion
	float x;
	int *n = new int;  // crea un puntero ademas reserva para un entero ocupacion 2+4
	cout << "ingresa el angulo en radianes ejemplo :60 grados =1.047197551 rad :"; cin >> x;  //ingresa a
	ingresak(n);   //ingresa k
	for (int i = 0; i < *n; i++)
		if (i % 2 == 0)

			*sumaserie = *sumaserie + potencia(x, i) / factorial(i); //manipulando o ingresando directamente el valor con la indireccion
		else
			*sumaserie = *sumaserie - potencia(x, i) / factorial(i);

	delete n;

}


int digit(int *num, int *N)/*recibe con la indereccion, no crea una copia ni guarda direccion manipula
directamente por que ya sabe la direccion por tanto esta ahorrando los 4 bytes*/

{
	int *digito=new int;// crea un puntero ademas reserva para un entero ocupacion 2+4
	if (*num < 0)
		*num = -1*(*num);//manipulando o ingresando directamente el valor con la indireccion
	if (*N == 0)
		*digito = *num % 10;//manipulando o ingresando directamente el valor con la indireccion
	else
	for (int i = 1; i <= *N; i++)
	{
		
		if (i == *N)
			*digito = *num / pow(10, *N);
		*digito = *digito % 10;//manipulando o ingresando directamente el valor con la indireccion
	}
	return *digito;
	delete digito; //rompiendo el enlace entre el puntero y la memoria que guarda el dato almacenado
}

void menu()
{
	system("cls");
	cout << endl; cout << endl;
	cout << "MENU PRINCIPAL" << endl;
	cout << "1. funcion calcula seno de una angulo en radianes" << endl;
	cout << "2. funcion devuelve n-esimo digito de un numero" << endl;
	cout << "3. fin" << endl;
	cout << "ingrese su opcion:";
}

int main()
{
	int option;
	int nfact; //ojo no es puntero esta normal
	double *sumaserie = new double;
	int *num = new int; //crea un puntero ademas reserva para un entero ocupacion 2 + 4
	int *N = new int;//crea un puntero ademas reserva para un entero ocupacion 2 + 4

	while (1)
	{
		menu();
		cin >> option;
		switch (option)
		{
		
		case 1:
			cout << endl << "funcion calcula seno " << endl;
			funcionseno(sumaserie); //pasamos direccion de sumaserie, para que ponga el resultado y es void por eso la ejuccion es asi
			cout << "el resultado del sen(angulo en radianes) es  :" << *sumaserie << endl; //como ya tiene valor y lo podemos ver con la indreccion.
			delete sumaserie;//rompiendo el enlace entre el puntero y la memoria que guarda el dato almacenado
			_getch();
			break;
		case 2:
			
			cout << endl << "funcion que extrae el N-esimo digito " << endl;
			cout << "ingrese numero: "; cin >> *num;
			cout << "ingrese posicion del digito que se extraera ( el cero se considera como la posicion 1: "; cin >> *N;
			cout << "el digito es " << digit(num, N) << endl; //pasamos direccion de N y num
			delete N;//rompiendo el enlace entre el puntero y la memoria que guarda el dato almacenado
			delete num;//rompiendo el enlace entre el puntero y la memoria que guarda el dato almacenado
		
			
			_getch();
				break;
		case 3:
			exit(0);
			break;
		default:
			cout << endl << "ingrese opcion correcta" << endl;
			menu();
		}
	}

	_getch();
}
