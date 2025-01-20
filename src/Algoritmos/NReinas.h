#ifndef __NREINAS__
#define __NREINAS__

#include <iostream>

typedef unsigned int uint;

/* Struct para representar el problema de las N-reinas */
struct NReinas
{
	// El tablero es cuadrado
	NReinas(uint numReinas = 8, uint tamTablero = 8)
	{
		this->numReinas = numReinas;
		this->tamTablero = tamTablero;
		this->numSoluciones = 0;
	}

	/* Resuelve el problema, almacenando el número de soluciones que tiene */
	void resuelve()
	{
		uint* solucion = new uint[(int)numReinas];
		for (int i = 0; i < numReinas; i++)
		{
			solucion[0] = i;
			std::cout << "Explorando nivel " << i << std::endl;
			solucion_parcial(solucion, 0);
		}
	}

	uint numSoluciones;
private:

	uint numReinas;
	uint tamTablero;

	void solucion_parcial(uint* sol, uint paso)
	{
		// Si el paso ha sido, correcto...
		if(comprueba_correcto(sol, paso))
		{
			// Caso base
			if (paso == numReinas - 1)
				numSoluciones++;
				
			// Caso recursivo
			else
			{
				for(int i = 0; i < numReinas; i++)
				{
					sol[paso + 1] = i;
					solucion_parcial(sol, paso + 1);
				}
			}
		}
		// Si no, no hacemos nada (se poda la búsqueda)
	}

	/* Comprueba que la reina puesta en el paso 'paso' no genera conflicto con la ya correcta solución anterior */
	bool comprueba_correcto(uint* sol, uint paso)
	{
		// Comprobar conflicto con las anteriores paso reinas
		for(int i = 0; i < paso; i++)
		{
			if (sol[paso] == sol[i] || // Misma columna
				paso + sol[paso] == i + sol[i] || // Misma diagonal ascendente
				paso - sol[paso] == i - sol[i]) // Misma diagonal descendente
				return false;
		}
		// e.o.c., es correcta
		return true;
	}
};


#endif