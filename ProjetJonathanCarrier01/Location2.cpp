//But : Programmer un c++ qui calculera le coût d'une location de voiture
// Auteur: Jonathan Carrier
// date 2020-09-15




#include <iostream>                 // Notre boîte à outils

int main()                         // Indique le début d'une instruction
{
	setlocale(LC_ALL, "");         // Permet d'afficher à l'écran les caractères accentués
	// Ici, on déclare les variables

	int jours;           // nombre de jours loués
	float km;            // nombre de km roulés
	float dollarskm;     // couts par km
	int dollarsjours;    // cout par jour de location
	float essence;       // nombre d'essence utilisé en litres
	float dollarsessence; // cout de cet essence
	float dollars;        // le cout total
	
	// le programme doit faire entrer à l'utilisateur 2 variables: le nombre de jours, ainsi que le nombre de kilomètres qu'il a roulé.

	std::cout << " Bienvenue au service de location de voiture ABC, veuillez entrer le nombre de jours loués : "; 
	std::cin >> jours; // l'utilisateur entre ici le(s) jours pour le(s)quel(s) il loue la voiture

	dollarsjours = jours * 45;

	std::cout << " Merci, veuillez maintenant entrer le nombre de kilomètres parcourus : ";
	std::cin >> km; // l'utilisateur entre ici le nombre de kilomètre qu'il a parcouru

	
	if (km >= 1 && jours > 1 ) // la voiture devrait être loué pour plus d'une journée / 1 km
	{

		if (km > 250) // si elle l'est pour plus de 250km
		{
			if (250 * jours > km) // en tenant compte du nombre de km inclus
			{
				dollarskm = 0;  // le kilmométrage quotidien n'a pas été dépassé
				essence = (km/100 * 7.6); // La voiture a une consommation de 7.6L au 100 km, / en 100 ca donne 0.76 L au km
				dollarsessence = essence * 1.25;// Le prix de l'essence est fixé à 1.25$ le litre 
				dollars = dollarsessence + dollarskm + dollarsjours; // le cout 

				std::cout << " Le coût total de votre voyage sera de :  " << dollars << " dollars canadiens." << std::endl; // le logiciel donne son prix à l'utilisateur
				std::cout << " Merci d'avoir utilisé les services de Location de voiture ABC. Au plaisir de vous revoir!" << std::endl;  // le logiciel remercie l'utilisateur
			}
			else // si dépassant le nombre de km inclus
			{
				dollarskm = (km - (250 * jours)) * 0.05; // le kilométrage a été dépassé, mais il y a toujours 250km de gratuits par jours
				essence = (km /100 * 7.6); // la quantité d'essence utilisée est la même partout
				dollarsessence = essence * 1.25; // le prix de l'essence est fixé au même prix qu'auparavant
				dollars = dollarskm + dollarsessence + dollarsjours; // le coût total

				std::cout << " Le coût total de votre voyage sera de : " << dollars << " dollars canadiens" << std::endl;// le logiciel donne son prix à l'utilisateur
				std::cout << " Merci d'avoir utilisé les services de Location de voiture ABC. Au plaisir de vous revoir!" << std::endl;// le logiciel remercie l'utilisateur
			}
		}
		else
		{   
			dollarskm = 0;   // Le kilométrage n'a pas été dépassé
			essence = (km/100 * 7.6); // la quantité d'essence utilisée est toujours la même
			dollarsessence = essence * 1.25; // pareil pour le prix de cett essence
			dollars = dollarsjours + dollarsessence + dollarskm ; // le coût total
			std::cout << " Le coût total de votre voyage sera de : " << dollars << " dollars canadiens" << std::endl;// le logiciel donne son prix à l'utilisateur
			std::cout << " Merci d'avoir utilisé les services de Location de voiture ABC. Au plaisir de vous revoir!" <<std::endl;// le logiciel remercie l'utilisateur
		}


	}
	else 
	{
		std::cout << " Êtes-vous certain? Vous devriez louer la voiture pour plus d'un kilomètre, et plus d'une journée! ;)" << std::endl; // aucune voiture ne devrait être louée pour ne pas rouler
	

	}




		return 0 ; // indique la fin du programme


}
/*
Plan de test :

Nombre de jours                  Kilométrage parcouru                résultat attendu                     
1                                        250                                64$
10                                      5000                               1050$
1                                         0           Êtes-vous certain? Vous devriez louer la voiture pour plus d'un kilomètre, et plus d'une journée!
365                                    20 000                              18 325 $    (à ce prix là, achetez la voiture)
-1                                       300          Êtes-vous certain? Vous devriez louer la voiture pour plus d'un kilomètre, et plus d'une journée!
1000                                   -3000          Êtes-vous certain? Vous devriez louer la voiture pour plus d'un kilomètre, et plus d'une journée!
                  








*/