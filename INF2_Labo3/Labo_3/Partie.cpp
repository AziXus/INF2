/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
Partie::Partie(Joueurs joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur)
:JOUEURS(joueurs), NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur)
{
    pioche = genererCartes();
    distribuerCartes();
}

Cartes genererCartes()
{
    Cartes paquets;
    for(size_t i = A; i <= NOMBRE_FAMILLES)
}
