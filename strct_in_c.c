#include <unistd.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(int argc, char **argv) {
    node *head = NULL;   // Pointeur vers la tête de la liste chaînée
    node *current = NULL; // Pointeur pour parcourir la liste
    int i = 0;
    int len = 0;

    if (argc != 2) {
        write(1, "Usage: ./program \"string\"\n", 27);
        return 1;
    }

    // Calcul de la longueur de la chaîne argv[1]
    while (argv[1][i]) {
        len++;
        i++;
    }

    i = 0;
    if (argc == 2) {
        while (argv[1][i]) {
            // Allocation d'un nouveau nœud
            node *str = (node *)malloc(sizeof(node));
            if (!str) {
                write(1, "error malloc\n", 14);
                return 1;
            }

            // Initialisation du nouveau nœud
            str->data = argv[1][i];
            str->next = NULL;

            // Ajout du nouveau nœud à la liste chaînée
            if (head == NULL) {
                head = str;
                current = head;
            } else {
                current->next = str;
                current = str;
            }

            i++;
        }

        // Affichage des données de la liste chaînée
        current = head;
        while (current) {
            write(1, &(current->data), 1);
            current = current->next;
        }
    }

    write(1, "\n", 1);

    // Libération de la mémoire allouée
    current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

