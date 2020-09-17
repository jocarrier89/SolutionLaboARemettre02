//But : Programmer un c++ qui calculera le co�t d'une location de voiture
// Auteur: Jonathan Carrier
// date 2020-09-15




#include <iostream>                 // Notre bo�te � outils

int main()                         // Indique le d�but d'une instruction
{
	setlocale(LC_ALL, "");         // Permet d'afficher � l'�cran les caract�res accentu�s
	// Ici, on d�clare les variables

	int jours;           // nombre de jours lou�s
	float km;            // nombre de km roul�s
	float dollarskm;     // couts par km
	int dollarsjours;    // cout par jour de location
	float essence;       // nombre d'essence utilis� en litres
	float dollarsessence; // cout de cet essence
	float dollars;        // le cout total
	
	// le programme doit faire entrer � l'utilisateur 2 variables: le nombre de jours, ainsi que le nombre de kilom�tres qu'il a roul�.

	std::cout << " Bienvenue au service de location de voiture ABC, veuillez entrer le nombre de jours lou�s : "; 
	std::cin >> jours; // l'utilisateur entre ici le(s) jours pour le(s)quel(s) il loue la voiture

	dollarsjours = jours * 45;

	std::cout << " Merci, veuillez maintenant entrer le nombre de kilom�tres parcourus : ";
	std::cin >> km; // l'utilisateur entre ici le nombre de kilom�tre qu'il a parcouru

	
	if (km >= 1 && jours > 1 ) // la voiture devrait �tre lou� pour plus d'une journ�e / 1 km
	{

		if (km > 250) // si elle l'est pour plus de 250km
		{
			if (250 * jours > km) // en tenant compte du nombre de km inclus
			{
				dollarskm = 0;  // le kilmom�trage quotidien n'a pas �t� d�pass�
				essence = (km/100 * 7.6); // La voiture a une consommation de 7.6L au 100 km, / en 100 ca donne 0.76 L au km
				dollarsessence = essence * 1.25;// Le prix de l'essence est fix� � 1.25$ le litre 
				dollars = dollarsessence + dollarskm + dollarsjours; // le cout 

				std::cout << " Le co�t total de votre voyage sera de :  " << dollars << " dollars canadiens." << std::endl; // le logiciel donne son prix � l'utilisateur
				std::cout << " Merci d'avoir utilis� les services de Location de voiture ABC. Au plaisir de vous revoir!" << std::endl;  // le logiciel remercie l'utilisateur
			}
			else // si d�passant le nombre de km inclus
			{
				dollarskm = (km - (250 * jours)) * 0.05; // le kilom�trage a �t� d�pass�, mais il y a toujours 250km de gratuits par jours
				essence = (km /100 * 7.6); // la quantit� d'essence utilis�e est la m�me partout
				dollarsessence = essence * 1.25; // le prix de l'essence est fix� au m�me prix qu'auparavant
				dollars = dollarskm + dollarsessence + dollarsjours; // le co�t total

				std::cout << " Le co�t total de votre voyage sera de : " << dollars << " dollars canadiens" << std::endl;// le logiciel donne son prix � l'utilisateur
				std::cout << " Merci d'avoir utilis� les services de Location de voiture ABC. Au plaisir de vous revoir!" << std::endl;// le logiciel remercie l'utilisateur
			}
		}
		else
		{   
			dollarskm = 0;   // Le kilom�trage n'a pas �t� d�pass�
			essence = (km/100 * 7.6); // la quantit� d'essence utilis�e est toujours la m�me
			dollarsessence = essence * 1.25; // pareil pour le prix de cett essence
			dollars = dollarsjours + dollarsessence + dollarskm ; // le co�t total
			std::cout << " Le co�t total de votre voyage sera de : " << dollars << " dollars canadiens" << std::endl;// le logiciel donne son prix � l'utilisateur
			std::cout << " Merci d'avoir utilis� les services de Location de voiture ABC. Au plaisir de vous revoir!" <<std::endl;// le logiciel remercie l'utilisateur
		}


	}
	else 
	{
		std::cout << " �tes-vous certain? Vous devriez louer la voiture pour plus d'un kilom�tre, et plus d'une journ�e! ;)" << std::endl; // aucune voiture ne devrait �tre lou�e pour ne pas rouler
	

	}




		return 0 ; // indique la fin du programme


}
/*
Plan de test :

Nombre de jours                  Kilom�trage parcouru                r�sultat attendu                     
1                                        250                                64$
10                                      5000                               1050$
1                                         0           �tes-vous certain? Vous devriez louer la voiture pour plus d'un kilom�tre, et plus d'une journ�e!
365                                    20 000                              18 325 $    (� ce prix l�, achetez la voiture)
-1                                       300          �tes-vous certain? Vous devriez louer la voiture pour plus d'un kilom�tre, et plus d'une journ�e!
1000                                   -3000          �tes-vous certain? Vous devriez louer la voiture pour plus d'un kilom�tre, et plus d'une journ�e!
                  








*/