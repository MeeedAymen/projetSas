#include <stdio.h>
#include <stdlib.h>
#include <string.h>




            typedef struct {
            int id;
            char titre[100];
            char description[500];
            char deadline[20];
            char statut[30];
               } Tache;

               Tache taches[100];
               int nombreTaches = 0;

        void ajouterTache(){
             Tache nouvelleTache;

    printf("Identifiant : ");
    scanf("%d", &nouvelleTache.id);
    printf("Titre : ");
    scanf(" %s[^\n]", nouvelleTache.titre);
    printf("Description : ");
    scanf(" %s[^\n]", nouvelleTache.description);
    printf("Deadline : ");
    scanf(" %s[^\n]", nouvelleTache.deadline);
    printf("Statut : ");
    scanf(" %s[^\n]", nouvelleTache.statut);
    printf("Tache ajoutee avec succes.\n");


};
        
        void afficherListeTaches();
       /* void trierTachesAlphabetique();
        void trierTachesDeadline();
        void afficherTachesProcheDeadline();
        void modifierTache();
        void supprimerTache();
        void rechercherTacheParIdentifiant();
        void rechercherTacheParTitre();
        void afficherNombreTotalTaches();
        void afficherNombreTachesCompletesIncompletes();
        void afficherJoursRestantsTaches(); */




   int main() {

      int choix;

    do {

        printf("    ___________________________________Menu:___________________________________\n");
        printf("    |1.  Ajouter une nouvelle tache                                            |\n");
        printf("    |2.  Afficher la liste de toutes les taches                                |\n");
        printf("    |3.  Trier les taches par ordre alphabetique                               |\n");
        printf("    |4.  Trier les taches par deadline                                         |\n");
        printf("    |5.  Afficher les taches dont le deadline est dans 3 jours ou moins        |\n");
        printf("    |6.  Modifier une tache                                                    |\n");
        printf("    |7.  Supprimer une tache par identifiant                                   |\n");
        printf("    |8.  Rechercher une tache par son identifiant                              |\n");
        printf("    |9.  Rechercher une tache par son titre                                    |\n");
        printf("    |10. Afficher le nombre total des taches                                   |\n");
        printf("    |11. Afficher le nombre de taches completes et incompletes                 |\n");
        printf("    |12. Afficher le nombre de jours restants jusqu'au delai de chaque tache   |\n");
        printf("    |0.  Quitter                                                               |\n");
        printf("    |__________________________________________________________________________|\n");
        printf("      Choix: ");
        scanf("%d", &choix);



        switch (choix) {
            case 1:
                ajouterTache();
                break;
         /*   case 2:
                afficherListeTaches();
                break;
            case 3:
                trierTachesAlphabetique();
                break;
            case 4:
                trierTachesDeadline();
                break;
            case 5:
                afficherTachesProcheDeadline();
                break;
            case 6:
                modifierTache();
                break;
            case 7:
                supprimerTache();
                break;
            case 8:
                rechercherTacheParIdentifiant();
                break;
            case 9:
                rechercherTacheParTitre();
                break;
            case 10:
                afficherNombreTotalTaches();
                break;
            case 11:
                afficherNombreTachesCompletesIncompletes();
                break;
            case 12:
                afficherJoursRestantsTaches();
                break;*/
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
