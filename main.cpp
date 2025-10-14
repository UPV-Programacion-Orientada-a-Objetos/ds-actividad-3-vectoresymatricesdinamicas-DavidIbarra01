#include <iostream>

float** planificacionProductos = new float*[5];
int cantidadUnidadesPorFila;

int tamanyoCostoVariadoProducto = 5;
int* costoVariadoPorProducto = new int[tamanyoCostoVariadoProducto];

int tamanyoMateriaPrima = 4;
float* materiaPrima = new float[tamanyoMateriaPrima];


int main() {

    int selectoption = 0;
    std::cout << "Simulación de Interacción\n --- Sistema de Planificación y Costos (COGS) ---\n";
    std::cout << "\n";
    std::cout << "Inicialización exitosa. Matriz de Planificación: 5 Productos x 4 Semanas.\n";
     std::cout << "\n";

     std::cout << "--- Menú Principal ---\n";
     std::cout << "1. Ver Plan de Producción\n";
     std::cout << "2. Agregar Nueva Semana (Redimensionar Matriz)\n";
     std::cout << "3. Modificar Producción\n";
     std::cout << "4. Calcular COGS y Final Inventory\n";
     std::cout << "5. Salir\n";

     std::cin >> selectoption;
     switch (selectoption)
     {
     case 1:{
        std::cout << "FUnciono :)";
        break;
     }

     case 2:{
        std::cout << "La opcion 2";
        break;
     }

     case 3:{
        std::cout << "La opcion 2";
        break;
     }

     case 4:{
        std::cout << "La opcion 2";
        break;
     }

     case 5:{
        std::cout << "La opcion 2";
        break;
     }
        
     
     default:
        break;
     }

    return 0;
}