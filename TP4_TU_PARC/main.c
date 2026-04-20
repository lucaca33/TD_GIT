#include "parc.h"
#include "cas.h"

int main()
{

	File* file_attente = creerFile();
	if (file_attente == NULL)
		return 1;

	int L = 0;
	int C = 0;
	int N = 0;

	int * tab = cas6(&L, &C, &N);

	for (int i = 0; i < N; i++)
	{
		Groupe * g = creerGroupe(tab[i]);
		ajouterGroupeDansFile(g, file_attente);
	}
	
	long long int gain = gains(file_attente, C, L, N);
	printf("mon gain est de %llu\n", gain);




	return 0;
}