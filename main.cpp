#include <iostream>

      void agregarNuevaSemana();
      void modificarProduccion();
      void calcularCOGS();
      void mostrarPlanProduccion();
      float** matrizPlanificacion;
      float* vectorCostos;
      float* vectorMateriaPrima;
      int requerimientos[5 * 4];
      int numProductos = 5;
      int numSemanas = 4;
      int numMateriasPrimas = 4;
//Aplicación de la fórmula del COGS

int main() {   

    std::cout << "Simulación de Interacción\n --- Sistema de Planificación y Costos (COGS) ---\n";
    std::cout << "\n";
//---------------------------------
matrizPlanificacion = new float*[numSemanas];
for (int i = 0; i < numSemanas; i++)
{
   matrizPlanificacion[i] = new float[numSemanas];
}

vectorCostos = new float[numProductos];
vectorMateriaPrima = new float[numMateriasPrimas];

//p = producto y s = numeroSemanas
for (int p = 0; p < numProductos; p++)
{
   for (int m = 0; m < numSemanas; m++)
   {
      requerimientos[p * numMateriasPrimas + m]
      
   }
}

//----------------------------------------
    std::cout << "Inicialización exitosa. Matriz de Planificación: 5 Productos x 4 Semanas.\n";
     std::cout << "\n";

     std::cout << "--- Menú Principal ---\n";
     std::cout << "1. Ver Plan de Producción\n";
     std::cout << "2. Agregar Nueva Semana\n";
     std::cout << "3. Modificar Producción\n";
     std::cout << "4. Calcular COGS y Final Inventory\n";
     std::cout << "5. Salir\n";
   int selectoption = 0;
     std::cin >> selectoption;
     switch (selectoption)
     {
     case 1:{
      std::cout << "\n";
        std::cout << "FUnciono :)";
        break;
     }

     case 2:{ //Agregar nueva semana
      int originalNumeroSemanas = numSemanas;
       numSemanas++;
      std::cout << "\n";
       
       float** auxMatrizPlanificada = new float*[numProductos];
      for (int i = 0; i < numProductos; i++)
      {
         auxMatrizPlanificada[i] = new float[numSemanas];
      }
      
      //Transferir datos originales a la matriz auxiliar
       for (int i = 0; i < numProductos; i++)
       {
         for (int j = 0; j < originalNumeroSemanas; j++)
         {
            auxMatrizPlanificada[i][j] = matrizPlanificacion[i][j];
         }
         
       }
       //LIBERAR MEMORIA DE LA MATRIZ ORIGINAL
       for (int i = 0; i < numProductos; i++)
       {
         delete[] matrizPlanificacion[i];
       }
       delete[] matrizPlanificacion;

       matrizPlanificacion = auxMatrizPlanificada; //Le asignamos los nuevos valores a la matriz original
       
        std::cout << "Agregando semana ";

     std:: cout << "Matriz redimensionada a 5x" << numSemanas <<". ¡Memoria gestionada con éxito!\n";

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
      std::cout << "Liberando memoria de Matriz y Vectores Dinámicos...\n Sistema cerrado.";
      exit(0);

     }

     default:
        break;
     }

    return 0;
}