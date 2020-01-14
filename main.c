#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};
typedef struct list list_el;
typedef list_el *list_t;

void createlist(list_t Listen[10]);
int add_lists(list_t pliste1, list_t liste2);
list_t  newlist(int x);
void freeLists(list_t nl);


int main() {

    list_t Listen[10] = {0};
    createlist(Listen);
    printf("Bitte Listen eingeben!\n");
    int eingabe1,eingabe2;
    scanf("%d",&eingabe1); scanf("%d",&eingabe2);

    list_t addedlist = newlist(add_lists(Listen[eingabe1], Listen[eingabe2]));

    for (int i = 0; i < 10; i++) {
        freeLists(Listen[i]);
    }
    freeLists(addedlist);
    return 0;
}

void createlist(list_t Listen[10]){
    for (int i = 0; i < 10; i++) {
        list_t last = NULL;
        for (int x = rand()%7+1;x > 0;x--) {
            list_t new = malloc(sizeof(list_t));
            new->val = rand() % 10;
            if (last == NULL) {
                Listen[i] = new;
            } else if (x == 1) {
                last->next = NULL;
            } else {
                last->next = new;
            }
            last = new;
        }
    }

}

int add_lists(list_t liste1, list_t liste2) {
    int x = 0, y = 1;
    list_t nl = liste1;
    while (nl != NULL) {
        x += nl->val * y;
        y = y * 10;
        nl = nl->next;
    }
    printf("%d\n", x);
    int z = x;
    nl = liste2;
    y = 1;
    while (nl != NULL) {
        x += nl->val * y;
        y = y * 10;
        nl = nl->next;
    }
    printf("%d\n%d\n", x - z, x);
    return x;
}

list_t newlist(int x) {
    list_t output = NULL, last = NULL,nl = NULL;
    while (1) {
        nl = malloc(sizeof(list_el));
        if (last == NULL) {
            output = nl;
        } else {
            last->next = nl;
        }
        nl->val = x % 10;
        printf("%d->", x % 10);
        x = x / 10;
        if (x == 0) {
            break;
        }
        last = nl;
    }
    printf("Null");
    return output;
}

void freeLists(list_t nl) {
    list_t last = NULL;
    while (nl != NULL) {
        last = nl;
        nl = nl->next;
        free(last);
    }
}