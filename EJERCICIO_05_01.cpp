// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 20/09/2023

// Fecha modificación: 25/09/2023

// Número de ejericio: 1

// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo
// struct llamada “empleado”.
// La información con que se cuenta es: nombre, ci, departamento y salario.
// Realizar un programa en C++ que lea un array de estructura de los datos de N
// empleados e imprima los siguiente:
// • Empleado con mayor salario
// • Empleado con menor salario
// • Promedio salarial
// • Promedio por departamento
// • Departamento con mayor salario en promedio
// • Departamento con menor salario en promedio
#include <iostream>
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    int ci;
    string departamento;
    double salario;
};

void imprimirEmpleado(Empleado empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "CI: " << empleado.ci << endl;
    cout << "Departamento: " << empleado.departamento << endl;
    cout << "Salario: " << empleado.salario << endl;
}

int main() {
    int N;
    cout << "Ingrese el número de empleados: ";
    cin >> N;

    Empleado empleados[N];

    // Leer los datos de los empleados
    for (int i = 0; i < N; i++) {
        cout << "Empleado " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "CI: ";
        cin >> empleados[i].ci;
        cout << "Departamento: ";
        cin.ignore();
        getline(cin, empleados[i].departamento);
        cout << "Salario: ";
        cin >> empleados[i].salario;
    }

    // Encontrar empleado con mayor salario y empleado con menor salario
    Empleado empleadoMayorSalario = empleados[0];
    Empleado empleadoMenorSalario = empleados[0];
    double totalSalario = 0.0;
    double salarioPorDepartamento[100] = {0.0};
    int contadorPorDepartamento[100] = {0};
    string departamentoMayorPromedio;
    string departamentoMenorPromedio;
    double salarioMayorPromedio = 0.0;
    double salarioMenorPromedio = numeric_limits<double>::max();

    for (int i = 0; i < N; i++) {
        if (empleados[i].salario > empleadoMayorSalario.salario) {
            empleadoMayorSalario = empleados[i];
        }
        if (empleados[i].salario < empleadoMenorSalario.salario) {
            empleadoMenorSalario = empleados[i];
        }
        totalSalario += empleados[i].salario;
        salarioPorDepartamento[empleados[i].departamento] += empleados[i].salario;
        contadorPorDepartamento[empleados[i].departamento]++;
    }

    // Calcular el promedio salarial
    double promedioSalarial = totalSalario / N;

    // Encontrar el departamento con mayor y menor salario promedio
    for (int i = 0; i < 100; i++) {
        if (contadorPorDepartamento[i] > 0) {
            double salarioPromedio = salarioPorDepartamento[i] / contadorPorDepartamento[i];
            if (salarioPromedio > salarioMayorPromedio) {
                salarioMayorPromedio = salarioPromedio;
                departamentoMayorPromedio = to_string(i);
            }
            if (salarioPromedio < salarioMenorPromedio) {
                salarioMenorPromedio = salarioPromedio;
                departamentoMenorPromedio = to_string(i);
            }
        }
    }

    // Imprimir los resultados
    cout << "Empleado con mayor salario:" << endl;
    imprimirEmpleado(empleadoMayorSalario);
    cout << "Empleado con menor salario:" << endl;
    imprimirEmpleado(empleadoMenorSalario);
    cout << "Promedio salarial: " << promedioSalarial << endl;
    cout << "Promedio por departamento:" << endl;
    cout << "Departamento con mayor salario en promedio: " << departamentoMayorPromedio << endl;
    cout << "Departamento con menor salario en promedio: " << departamentoMenorPromedio << endl;

    return 0;
}
