// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 20/09/2023

// Fecha modificaci�n: 25/09/2023

// N�mero de ejericio: 3

// Problema planteado:Realice un programa en C++ con funciones y estructuras para el estacionamiento del
// Multicine.
// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de
// autos
// Piso 1 � 50 autos
// Piso 2 � 40 autos
// Piso 3 � 30 autos
// Piso 4 � 45 autos
// El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,
// autom�viles, minivans y motocicletas), marca del auto, modelo del auto y color del
// auto.
// Escribir un programa en C++ utilizando funciones y estructuras para:
// � Simular la entrada de veh�culos, el programa debe pedir la cantidad de
// veh�culos ingresados y el programa debe simular los tipos de veh�culo, la
// marca, el modelo, el color y en que piso se han estacionado.
// � La simulaci�n puede repetirse varias veces hasta que el usuario ingrese el valor
// de 0 (cero) en la cantidad de veh�culos. La cantidad de veh�culos debe se
// incremental.
// � Luego de cada ingreso de veh�culos se desea saber cuantos hay estacionado en
// cada piso.
// � Cuantos son vagoneta, camionetas, autom�viles, minivans y motocicletas.
// � Hacer un reporte por colores de autos, modelo y marca.
// � La simulaci�n debe determinar cuando el parqueo se ha llenado.
// � La simulaci�n debe determinar cu�ntos espacios libres queda.
#include <iostream>
#include <cstring>

using namespace std;

// Estructura para representar un veh�culo
struct Vehiculo {
    char tipo[20];
    char marca[50];
    char modelo[50];
    char color[20];
    int piso;
};

const int CAPACIDAD_PISOS[] = {50, 40, 30, 45};
const int NUM_PISOS = sizeof(CAPACIDAD_PISOS) / sizeof(CAPACIDAD_PISOS[0]);
const int MAX_VEHICULOS = 100;

Vehiculo estacionamiento[MAX_VEHICULOS];
int numVehiculosEstacionados = 0;

// Funci�n para mostrar la disponibilidad de cada piso
void mostrarDisponibilidad() {
    for (int i = 0; i < NUM_PISOS; i++) {
        cout << "Piso " << (i + 1) << ": " << CAPACIDAD_PISOS[i] - contarVehiculosEnPiso(i + 1) << " veh�culos disponibles" << endl;
    }
}

// Funci�n para contar veh�culos en un piso dado
int contarVehiculosEnPiso(int piso) {
    int contador = 0;
    for (int i = 0; i < numVehiculosEstacionados; i++) {
        if (estacionamiento[i].piso == piso) {
            contador++;
        }
    }
    return contador;
}

// Funci�n para mostrar un reporte por tipo de veh�culo
void mostrarReportePorTipo() {
    int contadorVagonetas = 0, contadorCamionetas = 0, contadorAutomoviles = 0, contadorMinivans = 0, contadorMotocicletas = 0;

    for (int i = 0; i < numVehiculosEstacionados; i++) {
        if (strcmp(estacionamiento[i].tipo, "vagoneta") == 0) {
            contadorVagonetas++;
        } else if (strcmp(estacionamiento[i].tipo, "camioneta") == 0) {
            contadorCamionetas++;
        } else if (strcmp(estacionamiento[i].tipo, "automovil") == 0) {
            contadorAutomoviles++;
        } else if (strcmp(estacionamiento[i].tipo, "minivan") == 0) {
            contadorMinivans++;
        } else if (strcmp(estacionamiento[i].tipo, "motocicleta") == 0) {
            contadorMotocicletas++;
        }
    }

    cout << "Reporte por tipo de veh�culo:" << endl;
    cout << "Vagonetas: " << contadorVagonetas << endl;
    cout << "Camionetas: " << contadorCamionetas << endl;
    cout << "Autom�viles: " << contadorAutomoviles << endl;
    cout << "Minivans: " << contadorMinivans << endl;
    cout << "Motocicletas: " << contadorMotocicletas << endl;
}

// Funci�n para mostrar un reporte por color, modelo y marca de autos
void mostrarReportePorColorModeloMarca() {
    cout << "Reporte por color, modelo y marca de autos:" << endl;
    for (int i = 0; i < numVehiculosEstacionados; i++) {
        cout << "Veh�culo " << (i + 1) << ": " << endl;
        cout << "   Color: " << estacionamiento[i].color << endl;
        cout << "   Modelo: " << estacionamiento[i].modelo << endl;
        cout << "   Marca: " << estacionamiento[i].marca << endl;
    }
}

int main() {
    int cantidadVehiculos;
    bool parqueoLleno = false;

    while (!parqueoLleno) {
        cout << "Ingrese la cantidad de veh�culos a estacionar (0 para salir): ";
        cin >> cantidadVehiculos;

        if (cantidadVehiculos == 0) {
            break;
        }

        for (int i = 0; i < cantidadVehiculos; i++) {
            if (numVehiculosEstacionados >= MAX_VEHICULOS) {
                cout << "El parqueo est� lleno." << endl;
                parqueoLleno = true;
                break;
            }

            Vehiculo vehiculo;
            cout << "Ingrese el tipo de veh�culo (vagoneta, camioneta, automovil, minivan o motocicleta): ";
            cin >> vehiculo.tipo;
            cout << "Ingrese la marca del veh�culo: ";
            cin.ignore();
            cin.getline(vehiculo.marca, sizeof(vehiculo.marca));
            cout << "Ingrese el modelo del veh�culo: ";
            cin.getline(vehiculo.modelo, sizeof(vehiculo.modelo));
            cout << "Ingrese el color del veh�culo: ";
            cin.getline(vehiculo.color, sizeof(vehiculo.color));
            int piso = 0;

            // Determinar el piso de estacionamiento seg�n el tipo de veh�culo
            if (strcmp(vehiculo.tipo, "vagoneta") == 0) {
                piso = 1;
            } else if (strcmp(vehiculo.tipo, "camioneta") == 0) {
                piso = 2;
            } else if (strcmp(vehiculo.tipo, "automovil") == 0) {
                piso = 3;
            } else if (strcmp(vehiculo.tipo, "minivan") == 0) {
                piso = 4;
            } else if (strcmp(vehiculo.tipo, "motocicleta") == 0) {
                piso = 4;
            }

            // Verificar si el piso est� lleno
            if (contarVehiculosEnPiso(piso) >= CAPACIDAD_PISOS[piso - 1]) {
                cout << "El piso " << piso << " est� lleno. No se pudo estacionar el veh�culo." << endl;
            } else {
                vehiculo.piso = piso;
                estacionamiento[numVehiculosEstacionados] = vehiculo;
                numVehiculosEstacionados++;
                cout << "El veh�culo se ha estacionado en el piso " << piso << "." << endl;
            }
        }

        mostrarDisponibilidad();
        mostrarReportePorTipo();
        mostrarReportePorColorModeloMarca();
    }

    return 0;
}
