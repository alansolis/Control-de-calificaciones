#include <iostream>
#include <stdlib.h>
using namespace std;

class Sistema_calificaciones
{
	int opcion, capturas;
	float calificacion, buscar, calificaciones[6];
	
	public:
		Sistema_calificaciones ()
		{
			this->calificaciones[0] = 0;
			this->calificaciones[1] = 0;
			this->calificaciones[2] = 0;
			this->calificaciones[3] = 0;
			this->calificaciones[4] = 0;
			this->calificaciones[5] = 0;
			this->capturas = 0;
		}

		void iniciar()
		{
			this->mostrarMenu();
			this->leerOpcion();
			this->validarOpcion();
		}

		void mostrarMenu()
		{
			cout << "*--------------------------------------------------*" << endl;
			cout << "|               Menú calificaciones                |" << endl;
			cout << "*--------------------------------------------------*" << endl;
			cout << "1) Captura de calificaciones." << endl;
			cout << "2) Buscar calificación." << endl;
			cout << "3) Mostrar las calificaciones capturadas." << endl;
			cout << "4) Mostrar: cuantos aprobados, reprobados y promedio." << endl;
			cout << "5) Salir." << endl << endl;
			cout << "Selecciona una opción:" << endl;
		}

		void leerOpcion()
		{
			cin >> opcion;
		}

		void validarOpcion()
		{
			if(opcion == 5)
				this->opcionSalir();
			else if(opcion == 4)
				this->opcionDetalle();
			else if(opcion == 3)
				this->opcionMostrar();
			else if(opcion == 2)
				this->opcionBuscar();
			else if(opcion == 1)
				this->opcionGuardar();
			else
				this->opcionInvalida();
		}

		void opcionSalir()
		{
			cout << "Hasta luego!" << endl;
			exit(0);
		}

		void opcionInvalida()
		{
			cout << "Opción invalida, seleccione una opción" << endl;
			this->iniciar();
		}

		void opcionGuardar()
		{
			if(this->capturas < 6)
			{
				cout << "Ingresa una calificación: " << endl;
				cin >> this->calificacion;
				if(this->calificacion > 10 || this->calificacion < 1)
				{
					cout << "Error: Calificación invalida" << endl;
					this->calificaciones[capturas] = 5;
				}else
				{
					this->calificaciones[capturas] = this->calificacion;
				}
				capturas++;
			}else
			{
				cout << "Warning: Las 6 calificaciones de los alumnos han sido capturadas" << endl;
			}

			this->iniciar();
		}

		void opcionBuscar()
		{
			if(this->capturas > 0)
			{
				cout << "Ingrese la calificación a buscar: " << endl;
				cin >> this->buscar;

				int encontrados = 0;
				for (int i = 0; i < 6; ++i)
				{
					if(this->calificaciones[i] == this->buscar)
						encontrados ++;
				}

				cout << "Se encontraron " << encontrados << " calificaciones capturadas" << endl;
			}else
				cout << "No hay datos disponibles." << endl;

			this->iniciar();
		}

		void opcionMostrar()
		{
			if(this->capturas > 0)
			{
				for(int i; i < 6; i++)
					cout << "Calificación capturada del alumno " << i+1 << ": " << this->calificaciones[i] << endl;
			}else
				cout << "No hay datos disponibles." << endl;
			this->iniciar();
		}

		void opcionDetalle()
		{
			if(this->capturas > 0)
			{
				int numReprobados = 0, numAprobados = 0;
				float promedio = 0, reprobados = 0, aprobados = 0;

				for (int i = 0; i < 6; ++i)
				{
					if(this->calificaciones[i] < 6)
					{
						numReprobados = numReprobados+1;
						reprobados = reprobados + this->calificaciones[i];
					}else if(this->calificaciones[i] >= 6)
					{
						numAprobados = numAprobados+1;
						aprobados = aprobados + this->calificaciones[i];
					}

					promedio = promedio + this->calificaciones[i];
				}

				cout << "Aprobados: " << numAprobados << endl;
				cout << "Promedio de aprobados: " << aprobados/numAprobados <<endl;
				cout << "Reprobados: " << numReprobados << endl;
				cout << "Promedio de reprobados: " << reprobados/numReprobados << endl;
				cout << "Promedio de la materia: " << promedio/6 << endl;
				
				this->iniciar();
			}else
			{
				cout << "No hay datos disponibles." << endl;
			}

			this->iniciar();
		}

};

int main()
{
	Sistema_calificaciones objSistema;
	objSistema.iniciar();
	return 0;
}