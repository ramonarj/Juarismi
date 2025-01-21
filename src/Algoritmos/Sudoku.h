#ifndef __SUDOKU__
#define __SUDOKU__

#include <iostream>
#include <string>
#include <fstream>

typedef unsigned int uint;

struct Casilla
{
	Casilla(uint fil, uint col)
	{
		this->fil = fil;
		this->col = col;
	}
	uint fil;
	uint col;
};

struct Sudoku
{
	Sudoku(const std::string& filename)
	{
		this->haySolucion = false;
		// Abrir el archivo
		std::ifstream stream;
		stream.open(filename);
		if (!stream.is_open())
			std::cout << "No se encontró el archivo " << filename << std::endl;
		// Leer el sudoku del archivo
		for(int i = 0; i < 9; i++)
		{
			std::string s;
			std::getline(stream, s);
			for (int j = 0; j < 9; j++)
				unresolved[i][j] = s[j] - '0';
		}

		std::cout << "Sudoku sin resolver: \n" << cadenaTexto(unresolved);
		// Cerrar el flujo
		stream.close();
	}
	/* Resuelve el sudoku y almacena la solución */
	void resuelve()
	{
		// Probar todas las combinaciones
		for (int i = 1; i < 10; i++)
		{
			Casilla cas(0, 0);
			unresolved[0][0] = i;
			solucion_parcial(unresolved, cas);
			if (haySolucion) // Dejamos de explorar
				return;
		}
	}
	/* Devuelve la solución del sudoku como cadena de texto */
	std::string solucion()
	{
		return cadenaTexto(unresolved);
	}

	bool haySolucion;
private:

	uint solved[9][9];
	uint unresolved[9][9];

	/* */
	void solucion_parcial(uint sol[9][9], Casilla cas)
	{
		int fil = cas.fil; int col = cas.col;
		// Si el paso ha sido, correcto...
		if (comprueba_correcto(sol, cas))
		{
			// Hallar el siguiente cuadrado en blanco a explorar
			if (siguiente_casilla(sol, cas))
			{
				// Probar todas las combinaciones en el siguiente cuadrado en blanco
				for (int i = 1; i < 10; i++)
				{
					sol[cas.fil][cas.col] = i;
					solucion_parcial(sol, cas);
					if (haySolucion) // Dejamos de explorar
						return;
				}
			}
			// No quedan espacios en blanco; fin del sudoku y tenemos solución correcta
			else
				haySolucion = true;
		}
		// Si no, no hacemos nada (se poda la búsqueda)
		else
			sol[fil][col] = 0;
	}

	bool siguiente_casilla(uint sol[9][9], Casilla& cas)
	{
		// Avanzamos hasta encontrar una casilla vacía o salirnos del mapa
		while (sol[cas.fil][cas.col] != 0)
		{
			// Nueva fila
			if (cas.col == 8)
			{
				cas.fil++;
				cas.col = 0;
			}
			// Avanzar en la columna
			else
				cas.col++;

			// Fin del tablero
			if (cas.fil == 9)
				return false;
		}
		return true;
	}

	/* Comprueba que el número puesto en el cuadrado nuevo no genera conflicto con la ya correcta solución anterior */
	bool comprueba_correcto(uint sol [9][9], Casilla cas)
	{
		uint fil = cas.fil; uint col = cas.col;

		// Comprobar conflicto con los anteriores cuadrados
		for (int i = 0; i < 9; i++)
		{
			// Misma fila
			if (sol[fil][i] == sol[fil][col] && i != col) 
				return false; 
			// Misma columna
			if (sol[i][col] == sol[fil][col] && i != fil) 
				return false;
		}
		
		// Mismo cuadrado 3x3. Podría optimizarse para no comprobar lo que ya ha sido comprobado en filas/columnas
		// Centro del cuadrado al que corresponde
		uint cX = (col / 3) * 3 + 1;
		uint cY = (fil / 3) * 3 + 1;
		for(int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (sol[fil][col] == sol[cY + i][cX + j] && 
					(cY + i != fil) && (cX + j != col)) // Comprobar que no se compara con si mismo
					return false;
			}
		}

		// e.o.c., es correcta
		return true;
	}


	/* Devuelve el sudoku en una cadena lista para ser mostrada en pantalla / guardada en archivo*/
	static std::string cadenaTexto(uint sudoku [9][9])
	{
		std::string s;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				s += sudoku[i][j] + '0';
				s += ' ';
			}
			s += '\n';
		}
		return s;
	}
};

#endif