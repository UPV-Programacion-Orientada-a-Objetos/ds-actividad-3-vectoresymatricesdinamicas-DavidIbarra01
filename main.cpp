#include <iostream>

      float** matrizPlanificacion;
      float* vectorCostos;
      float* vectorMateriaPrima;
      int requerimientos[5 * 4];
     const int numProductos = 5;
     const int numMateriasPrimas = 4;
      int numSemanas = 4; 
      bool seguirCorriendoPrograma = true;

int main() {   

    std::cout << "Simulación de Interacción\n --- Sistema de Planificación y Costos (COGS) ---\n";
    std::cout << "\n";
//---------------------------------
matrizPlanificacion = new float*[numProductos];
for (int i = 0; i < numProductos; i++)
{
   matrizPlanificacion[i] = new float[numSemanas];
}

vectorCostos = new float[numProductos];
vectorMateriaPrima = new float[numMateriasPrimas];

//p = producto y m = numMaterias
for (int p = 0; p < numProductos; p++)
{
   for (int m = 0; m < numMateriasPrimas; m++)
   {
      requerimientos[p * numMateriasPrimas + m] = 1; 
   }
}
std::cout << "Inicialización exitosa. Matriz de Planificación: 5 Productos x 4 Semanas.\n";
//----------------------------------------
while (seguirCorriendoPrograma == true)
{
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
      int numeroProducto = 0;
      int semanaAModificar;
      float cantidadAProducir = 0.0f;

      std::cout << "Ingrese el numero del producto: (0-4) ";
     
      do
      {
         std::cin >> numeroProducto;
      } while (numeroProducto < 0 || numeroProducto > 4);     
       
        std::cout << "La semana a modificar: (0-" << numSemanas - 1 << ":\n";
         do
      {
         std::cin >> semanaAModificar;
      } while (semanaAModificar < 0 || semanaAModificar >= numSemanas);
        
        std::cout << "Y por la cantidad a producir: ";
         std::cin >> cantidadAProducir;
        matrizPlanificacion[numeroProducto][semanaAModificar] = cantidadAProducir;
        break;
     }

     case 4:{
      int semanaSeleccionada;
      std::cout << "Ingrese Semana para el cálculo de costos: ";

      while (true) //Validar semana seleccionada
      {
        std::cin >> semanaSeleccionada;
      if (semanaSeleccionada >= numSemanas || semanaSeleccionada < 0)
      {
         std::cout << "ERROR: No existe esa semana\n";
      }else{
         break;
      }
      }
      
       float consumoMP[numMateriasPrimas] = {0};
      float consumo = 0.0f;
      
      //=== Calcular consumo de materia prima por semana ===
for (int materia = 0; materia < numMateriasPrimas; materia++)
{
    float consumo_por_materia = 0.0f;
    for (int product = 0; product < numProductos; product++)
    {
        consumo_por_materia += matrizPlanificacion[product][semanaSeleccionada] * requerimientos[product * numMateriasPrimas + materia];
    }
    consumoMP[materia] = consumo_por_materia;
}
   //=== Calcular COGS ===
        float cogsTotal = 0.0f;

        for (int producto = 0; producto < numProductos; producto++)
        {
         cogsTotal = cogsTotal + matrizPlanificacion[producto][semanaSeleccionada] * vectorCostos[producto];
        }
        // === Calcular el inventario final ===
        float valorInventarioFinal = 0.0f;
        float costosAdquision = 0.0f;
        float mpRestante = 0.0f;
        const float costoAdquisicionMP[4] = {10.50, 25.00, 5.75, 18.20};

        for (int materia = 0; materia < numMateriasPrimas; materia++)
        {
         mpRestante = vectorMateriaPrima[materia] - consumoMP[materia];
         valorInventarioFinal = valorInventarioFinal + mpRestante * costoAdquisicionMP[materia];
        }

      std::cout << "--- Reporte de Costos (Semana " << semanaSeleccionada << ") ---\n";
std::cout << "Costo Total de Producción (COGS): $" << cogsTotal << std::endl;
std::cout << "Valor del Inventario Final (M.P. restante): $" << valorInventarioFinal << std::endl;
for (int i = 0; i < numMateriasPrimas; ++i) {
    std::cout << "Consumo de Materia Prima " << i << ": " << consumoMP[i] << " unidades.\n";
}
        
        break;
     }

     case 5:{

      seguirCorriendoPrograma = false;
      std::cout << "Liberando memoria de Matriz y Vectores Dinámicos...\n Sistema cerrado.\n";
      
for (int i = 0; i < numProductos; i++) {
        delete[] matrizPlanificacion[i];
    }
    delete[] matrizPlanificacion;

    delete[] vectorCostos;
    delete[] vectorMateriaPrima;
     }

     default:
     std::cout << "Opcion invalida compadre\n";
        break;
     }
}
    return 0;
}