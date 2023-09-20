// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 20/09/2023

// Fecha modificación: 25/09/2023

// Número de ejericio: 3

// Problema planteado:Realice un programa en C++ con funciones y estructuras para el estacionamiento del
// Multicine.
// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de
// autos
// Piso 1 – 50 autos
// Piso 2 – 40 autos
// Piso 3 – 30 autos
// Piso 4 – 45 autos
// El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,
// automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del
// auto.
// Escribir un programa en C++ utilizando funciones y estructuras para:
// • Simular la entrada de vehículos, el programa debe pedir la cantidad de
// vehículos ingresados y el programa debe simular los tipos de vehículo, la
// marca, el modelo, el color y en que piso se han estacionado.
// • La simulación puede repetirse varias veces hasta que el usuario ingrese el valor
// de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se
// incremental.
// • Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en
// cada piso.
// • Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
// • Hacer un reporte por colores de autos, modelo y marca.
// • La simulación debe determinar cuando el parqueo se ha llenado.
// • La simulación debe determinar cuántos espacios libres queda.
#include <iostream>
#include <cstring>

using namespace std;

// Estructura para representar un vehículo
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

// Función para mostrar la disponibilidad de cada piso
void mostrarDisponibilidad() {
    for (int i = 0; i < NUM_PISOS; i++) {
        cout << "Piso " << (i + 1) << ": " << CAPACIDAD_PISOS[i] - contarVehiculosEnPiso(i + 1) << " vehículos disponibles" << endl;
    }
}

// Función para contar vehículos en un piso dado
int contarVehiculosEnPiso(int piso) {
    int contador = 0;
    for (int i = 0; i < numVehiculosEstacionados; i++) {
        if (estacionamiento[i].piso == piso) {
            contador++;
        }
    }
    return contador;
}

// Función para mostrar un reporte por tipo de vehículo
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

    cout << "Reporte por tipo de vehículo:" << endl;
    cout << "Vagonetas: " << contadorVagonetas << endl;
    cout << "Camionetas: " << contadorCamionetas << endl;
    cout << "Automóviles: " << contadorAutomoviles << endl;
    cout << "Minivans: " << contadorMinivans << endl;
    cout << "Motocicletas: " << contadorMotocicletas << endl;
}

// Función para mostrar un reporte por color, modelo y marca de autos
void mostrarReportePorColorModeloMarca() {
    cout << "Reporte por color, modelo y marca de autos:" << endl;
    for (int i = 0; i < numVehiculosEstacionados; i++) {
        cout << "Vehículo " << (i + 1) << ": " << endl;
        cout << "   Color: " << estacionamiento[i].color << endl;
        cout << "   Modelo: " << estacionamiento[i].modelo << endl;
        cout << "   Marca: " << estacionamiento[i].marca << endl;
    }
}

int main() {
    int cantidadVehiculos;
    bool parqueoLleno = false;

    while (!parqueoLleno) {
        cout << "Ingrese la cantidad de vehículos a estacionar (0 para salir): ";
        cin >> cantidadVehiculos;

        if (cantidadVehiculos == 0) {
            break;
        }

        for (int i = 0; i < cantidadVehiculos; i++) {
            if (numVehiculosEstacionados >= MAX_VEHICULOS) {
                cout << "El parqueo está lleno." << endl;
                parqueoLleno = true;
                break;
            }

            Vehiculo vehiculo;
            cout << "Ingrese el tipo de vehículo (vagoneta, camioneta, automovil, minivan o motocicleta): ";
            cin >> vehiculo.tipo;
            cout << "Ingrese la marca del vehículo: ";
            cin.ignore();
            cin.getline(vehiculo.marca, sizeof(vehiculo.marca));
            cout << "Ingrese el modelo del vehículo: ";
            cin.getline(vehiculo.modelo, sizeof(vehiculo.modelo));
            cout << "Ingrese el color del vehículo: ";
            cin.getline(vehiculo.color, sizeof(vehiculo.color));
            int piso = 0;

            // Determinar el piso de estacionamiento según el tipo de vehículo
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

            // Verificar si el piso está lleno
            if (contarVehiculosEnPiso(piso) >= CAPACIDAD_PISOS[piso - 1]) {
                cout << "El piso " << piso << " está lleno. No se pudo estacionar el vehículo." << endl;
            } else {
                vehiculo.piso = piso;
                estacionamiento[numVehiculosEstacionados] = vehiculo;
                numVehiculosEstacionados++;
                cout << "El vehículo se ha estacionado en el piso " << piso << "." << endl;
            }
        }

        mostrarDisponibilidad();
        mostrarReportePorTipo();
        mostrarReportePorColorModeloMarca();
    }

    return 0;
}
