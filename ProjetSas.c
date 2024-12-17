#include <stdio.h>
#include <string.h>
#include <time.h>

     //+++++++++++++++++++++++++++++STRUCTURES+++++++++++++++++++++++++++++++++++++++++
	
struct Tache {
	int id;
	char titre[50];
	char description[200];
	char deadline[11]; 
	char statut[20];
	   };

// ===================================Déclarations =========================================
           struct Tache taches[1000];
            int nbTaches = 0;
            int prochainID = 1;

//++++++++++++++++++++++++++++++++++AFFICHAGE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void afficherMenu() {
    printf("\nMenu :\n");
    printf("1. Ajouter une nouvelle tâche\n");
    printf("2. Afficher la liste de toutes les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Rechercher des tâches\n");
    printf("6. Afficher les statistiques\n");
    printf("0. Quitter\n");
}

//+++++++++++++++++++AJOUTERTACHE+++++++++++++++++++++++++++++

void ajouterTache() {
    struct Tache nouvelleTache;
    nouvelleTache.id = prochainID++;
    printf("Titre de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.titre);
    printf("Description de la tâche : ");
    scanf(" %[^\n]s", nouvelleTache.description);
    printf("Deadline (YYYY-MM-DD) : ");
    scanf("%[^\n]s", nouvelleTache.deadline);
    printf("Statut de la tâche (à réaliser, en cours de réalisation, finalisée) : ");
    scanf("%s", nouvelleTache.statut);
    
    taches[nbTaches++] = nouvelleTache;
    printf("Tâche ajoutée avec succès.\n");
}
//++++++++++++++++++AJOUTERPLUSIEURSTACHES+++++++++++++++++++++++++++
  
  void ajouterplusieurstaches(){
  	 {
        int nombreTachesAAjouter;
        printf("Combien de tâches voulez-vous ajouter ? : ");
        scanf("%d", &nombreTachesAAjouter);

        for (int i = 0; i < nombreTachesAAjouter; i++) {
            ajouterTache();
        }

        printf("%d tâches ajoutées avec succès.\n", nombreTachesAAjouter);
    }
  }
  
  //+++++++++++++++++++++++++++++AFFICHAGE++++++++++++++++++++++++++++++++++
  
void afficherToutesLesTaches() {
    printf("\nListe de toutes les tâches :\n");
    for (int i = 0; i < nbTaches; i++) {
        printf("ID : %d\n", taches[i].id);
        printf("Titre : %s\n", taches[i].titre);
        printf("Description : %s\n", taches[i].description);
        printf("Deadline : %s\n", taches[i].deadline);
        printf("Statut : %s\n", taches[i].statut);
        printf("-----------\n");
    }
}

//+++++++++++++++++++MOFIFICATION++++++++++++++++++++++++++++++++++++++++

void modifierTache(int id) {
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == id) {
            printf("Nouveau titre de la tâche : ");
            scanf(" %[^\n]s", taches[i].titre);
            printf("Nouvelle description de la tâche : ");
            scanf(" %[^\n]s", taches[i].description);
            printf("Nouveau deadline (YYYY-MM-DD) : ");
            scanf("%s", taches[i].deadline);
            printf("Nouveau statut de la tâche (à réaliser, en cours de réalisation, finalisée) : ");
            scanf("%s", taches[i].statut);
            printf("Tâche modifiée avec succès.\n");
            return;
        }
    }
    printf("Tâche avec l'ID %d non trouvée.\n", id);
}

//+++++++++++++++++++++++++++++++++++SUPPRESSSION++++++++++++++++++++++++++++++++

void supprimerTache(int id) {
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == id) {
            for (int j = i; j < nbTaches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbTaches--;
            printf("Tâche supprimée avec succès.\n");
            return;
        }
    }
    printf("Tâche avec l'ID %d non trouvée.\n", id);
}

//++++++++++++++++++++++++++++++DEADLINE+++++++++++++++++++++++++++++++++++++++
void afficherTachesDeadlineProche() {
    time_t maintenant;
    time(&maintenant);
    printf("\nTâches dont le deadline est dans 3 jours ou moins :\n");
    for (int i = 0; i < nbTaches; i++) {
        struct tm dateDeadline;
        sscanf(taches[i].deadline, "%4d-%2d-%2d", &dateDeadline.tm_year, &dateDeadline.tm_mon, &dateDeadline.tm_mday);
        dateDeadline.tm_year -= 1900; 
        dateDeadline.tm_mon--; 
        double diff = difftime(maintenant, mktime(&dateDeadline));
        int joursRestants = (int)(diff / (24 * 3600)); 

        if (joursRestants <= 3) {
            printf("ID : %d\n", taches[i].id);
            printf("Titre : %s\n", taches[i].titre);
            printf("Deadline : %s\n", taches[i].deadline);
            printf("Jours restants : %d\n", joursRestants);
            printf("-----------\n");
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++modifierDescriptionTache++++++++++++++++++++++++++++++++++++++++++++++++++

void modifierDescriptionTache(int id) {
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == id) {
            printf("Entrez la nouvelle description pour la tâche %d : ", id);
            scanf("%s", taches[i].description);
            printf("Description mise à jour avec succès.\n");
            return;
        }
    }
    printf("Aucune tâche avec l'identifiant %d n'a été trouvée.\n", id);
}
//++++++++++++++++++++++++++++++++++++++++modifierDeadlineTache++++++++++++++++++++++++++++++++++++++++++++++++++

void modifierDeadlineTache(int id) {
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == id) {
            printf("Entrez la nouvelle deadline (date limite) pour la tâche %d : ", id);
            scanf("%s", taches[i].deadline);
            printf("Deadline mise à jour avec succès.\n");
            return;
        }
    }
    printf("Aucune tâche avec l'identifiant %d n'a été trouvée.\n", id);
}

//++++++++++++++++++++++++++++++++++++++++modifierStatutTache++++++++++++++++++++++++++++++++++++++++++++++++++

void modifierStatutTache(int id) {
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == id) {
            printf("Entrez le nouveau statut pour la tâche %d : ", id);
            scanf("%s", taches[i].statut);
            printf("Statut mis à jour avec succès.\n");
            return;
        }
    }
    printf("Aucune tâche avec l'identifiant %d n'a été trouvée.\n", id);
}
//++++++++++++++++++++++++++++++++++++++++rechercherTacheParId++++++++++++++++++++++++++++++++++++++++++++++++++

void rechercherTacheParId(int id) {
    printf("\nRecherche de la tâche par identifiant %d :\n", id);
    printf("ID\tTitre\tDescription\tDeadline\tStatut\n");
    for (int i = 0; i < nbTaches; i++) {
        struct Tache tache = taches[i];
        if (tache.id == id) {
            printf("%d\t%s\t%s\t%s\t%s\n", tache.id, tache.titre, tache.description, tache.deadline, tache.statut);
            return;
        }
    }
    printf("Aucune tâche avec l'identifiant %d n'a été trouvée.\n", id);
}

//++++++++++++++++++++++++++++++++++++++++rechercherTacheParTitre++++++++++++++++++++++++++++++++++++++++++++++++++
void rechercherTacheParTitre(char titre[100]) {
    printf("\nRecherche de la tâche par titre '%s' :\n", titre);
    printf("ID\tTitre\tDescription\tDeadline\tStatut\n");
    int trouve = 0;
    for (int i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].titre, titre) == 0) {
            printf("%d\t%s\t%s\t%s\t%s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune tâche avec le titre '%s' n'a été trouvée.\n", titre);
    }
}

// +++++++++++++++++++++++++STATISTIQUES+++++++++++++++++++++++++++

void afficherStatistiques() {
    printf("\nStatistiques :\n");
    printf("Nombre total de tâches : %d\n", nbTaches);

    int tachesTerminees = 0;
    int tachesNonTerminees = 0;

    // Obtenir la date actuelle
    time_t maintenant;
    time(&maintenant);

    printf("\nJours restants jusqu'au délai de chaque tâche :\n");

    for (int i = 0; i < nbTaches; i++) {
        struct tm dateDeadline;
        sscanf(taches[i].deadline, "%4d-%2d-%2d", &dateDeadline.tm_year, &dateDeadline.tm_mon, &dateDeadline.tm_mday);
        dateDeadline.tm_year -= 1900;
        dateDeadline.tm_mon--;

        // Convertir la date limite en time_t
        time_t deadline = mktime(&dateDeadline);

        // Calculer la différence en secondes entre la date limite et la date actuelle
        double diff = difftime(deadline, maintenant);

        // Convertir la différence en jours
        int joursRestants = (int)(diff / (24 * 3600));

        printf("ID : %d\n", taches[i].id);
        printf("Titre : %s\n", taches[i].titre);
        printf("Deadline : %s\n", taches[i].deadline);
        printf("Jours restants : %d\n", joursRestants);
        printf("-----------\n");

        if (strcmp(taches[i].statut, "finalisée") == 0) {
            tachesTerminees++;
        } else {
            tachesNonTerminees++;
        }
    }

    printf("Nombre de tâches terminées : %d\n", tachesTerminees);
    printf("Nombre de tâches non terminées : %d\n", tachesNonTerminees);
}

//++++++++++++++++++++++MAIN+++++++++++++++++++++++

int main() {
    int choix;

    do {
        afficherMenu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherToutesLesTaches();
                break;
            case 3:
                // Sous-menu pour la modification
                int choixModification;
                printf("Menu de modification :\n");
                printf("1. Modifier la description d'une tâche\n");
                printf("2. Modifier le statut d'une tâche\n");
                printf("3. Modifier le deadline d'une tâche\n");
                printf("Entrez votre choix : ");
                scanf("%d", &choixModification);

                int idModification;
                printf("Entrez l'identifiant de la tâche à modifier : ");
                scanf("%d", &idModification);

                switch (choixModification) {
                    case 1:
                        modifierDescriptionTache(idModification);
                        break;
                    case 2:
                        modifierStatutTache(idModification);
                        break;
                    case 3:
                        modifierDeadlineTache(idModification);
                        break;
                    default:
                        printf("Choix invalide pour la modification.\n");
                }
                break;
            case 4:
                int idSuppression;
                printf("Entrez l'identifiant de la tâche à supprimer : ");
                scanf("%d", &idSuppression);
                supprimerTache(idSuppression);
                break;
            case 5:
                // Sous-menu pour la recherche
                int choixRecherche;
                printf("Menu de recherche :\n");
                printf("1. Rechercher une tâche par son Identifiant\n");
                printf("2. Rechercher une tâche par son Titre\n");
                printf("Entrez votre choix : ");
                scanf("%d", &choixRecherche);

                switch (choixRecherche) {
                    case 1:
                        int idRecherche;
                        printf("Entrez l'identifiant de la tâche à rechercher : ");
                        scanf("%d", &idRecherche);
                        rechercherTacheParId(idRecherche);
                        break;
                    case 2:
                        char titreRecherche[100];
                        printf("Entrez le titre de la tâche à rechercher : ");
                        scanf(" %[^\n]s", titreRecherche);
                        rechercherTacheParTitre(titreRecherche);
                        break;
                    default:
                        printf("Choix invalide pour la recherche.\n");
                }
                break;
            case 6:
                afficherStatistiques();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
