#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONNES 100
#define TAILLE_NOM 100
#define TAILLE_RUE 100
#define TAILLE_VILLE 100

typedef struct {
    char rue[TAILLE_RUE];
    char ville[TAILLE_VILLE];
    int code_postal;
} Adresse;

typedef struct {
    char nom[TAILLE_NOM];
    int age;
    Adresse adresse;
} Personne;

Personne personnes[MAX_PERSONNES];
int compteur = 0;

void creer_personne() {
    if (compteur >= MAX_PERSONNES) {
        printf("Erreur: Maximum de personnes atteint.\n");
        return;
    }

    Personne nouvelle_personne;

    printf("Entrez le nom: ");
    scanf("%s", nouvelle_personne.nom);
    printf("Entrez l'�ge: ");
    scanf("%d", &nouvelle_personne.age);
    printf("Entrez la rue: ");
    scanf("%s", nouvelle_personne.adresse.rue);
    printf("Entrez la ville: ");
    scanf("%s", nouvelle_personne.adresse.ville);
    printf("Entrez le code postal: ");
    scanf("%d", &nouvelle_personne.adresse.code_postal);

    personnes[compteur] = nouvelle_personne;
    compteur++;
    printf("Personne ajout�e avec succ�s.\n");
}

void afficher_personnes() {
    if (compteur == 0) {
        printf("Aucune personne � afficher.\n");
        return;
    }

    printf("\nListe des personnes:\n");
    for (int i = 0; i < compteur; i++) {
        printf("Nom: %s, Age: %d, Adresse: %s, %s, %d\n",
               personnes[i].nom,
               personnes[i].age,
               personnes[i].adresse.rue,
               personnes[i].adresse.ville,
               personnes[i].adresse.code_postal);
    }
}

void mettre_a_jour_personne() {
    char nom[TAILLE_NOM];
    printf("Entrez le nom de la personne � mettre � jour: ");
    scanf("%s", nom);

    for (int i = 0; i < compteur; i++) {
        if (strcmp(personnes[i].nom, nom) == 0) {
            printf("Mise � jour des informations de %s:\n", personnes[i].nom);
            printf("Entrez le nouvel �ge: ");
            scanf("%d", &personnes[i].age);
            printf("Entrez la nouvelle rue: ");
            scanf("%s", personnes[i].adresse.rue);
            printf("Entrez la nouvelle ville: ");
            scanf("%s", personnes[i].adresse.ville);
            printf("Entrez le nouveau code postal: ");
            scanf("%d", &personnes[i].adresse.code_postal);
            printf("Informations mises � jour avec succ�s.\n");
            return;
        }
    }
    printf("Personne non trouv�e.\n");
}


void supprimer_personne() {
    char nom[TAILLE_NOM];
    printf("Entrez le nom de la personne � supprimer: ");
    scanf("%s", nom);

    for (int i = 0; i < compteur; i++) {
        if (strcmp(personnes[i].nom, nom) == 0) {
            for (int j = i; j < compteur - 1; j++) {
                personnes[j] = personnes[j + 1];
            }
            compteur--;
            printf("Personne supprim�e avec succ�s.\n");
            return;
        }
    }
    printf("Personne non trouv�e.\n");
}

int main() {
    int choix;

    do {
        printf("\nMenu:\n");
        printf("1. Cr�er une personne\n");
        printf("2. Afficher les personnes\n");
        printf("3. Mettre � jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creer_personne();
                break;
            case 2:
                afficher_personnes();
                break;
            case 3:
                mettre_a_jour_personne();
                break;
            case 4:
                supprimer_personne();
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 5);

    return 0;
}
