// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 20/09/2023

// Fecha modificaci�n: 25/09/2023

// N�mero de ejericio: 2

// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
// nos devuelva el pa�s que mayor n�mero de medallas ha ganado.
#include <iostream>
#include <cstring>

using namespace std;

struct Datos {
    char nombre[40];
};

struct Atleta {
    char deporte[30];
    Datos pers;
    int nmedallas;
};

const int MAX_ATLETAS = 30;

int main() {
    int N;
    cout << "Ingrese el n�mero de atletas: ";
    cin >> N;

    Atleta atletas[MAX_ATLETAS];
    char paisMayorMedallas[40] = "";
    int maxMedallas = 0;

    for (int i = 0; i < N; i++) {
        cout << "Nombre[" << i + 1 << "]: ";
        cin.ignore();
        cin.getline(atletas[i].pers.nombre, sizeof(atletas[i].pers.nombre));

        cout << "Pais[" << i + 1 << "]: ";
        cin.getline(atletas[i].pers.pais, sizeof(atletas[i].pers.pais));

        cout << "Deporte[" << i + 1 << "]: ";
        cin.getline(atletas[i].deporte, sizeof(atletas[i].deporte));

        cout << "N�mero de Medallas[" << i + 1 << "]: ";
        cin >> atletas[i].nmedallas;

        // Verificar si este atleta tiene m�s medallas que el m�ximo encontrado hasta ahora
        if (atletas[i].nmedallas > maxMedallas) {
            maxMedallas = atletas[i].nmedallas;
            strcpy(paisMayorMedallas, atletas[i].pers.pais);
        }
    }

    cout << "**Datos del atleta con mayor n�mero de Medallas**" << endl;
    cout << "Nombre: " << atletas[N - 1].pers.nombre << endl;
    cout << "Pais: " << atletas[N - 1].pers.pais << endl;
    cout << "Deporte: " << atletas[N - 1].deporte << endl;
    cout << "N�mero de Medallas: " << atletas[N - 1].nmedallas << endl;

    cout << "Pais con el mayor n�mero de Medallas: " << paisMayorMedallas << endl;

    return 0;
}
