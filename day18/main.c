#include <stdio.h>

int main() {

    int id[10];
    char name[10][40];
    int stock[10];
    float cost[10];

    int total = 0;
    int option;
    int j;

    while (1) {
        printf("\n=== menu ===\n");
        printf("1. enter product\n");
        printf("2. show products\n");
        printf("3. inventory report\n");
        printf("4. find product\n");
        printf("5. quit\n");
        printf("choose option: ");
        scanf("%d", &option);

        if (option == 1) {
            if (total == 10) {
                printf("limit reached. cannot add more.\n");
            } else {
                printf("product id: ");
                scanf("%d", &id[total]);

                printf("product name: ");
                scanf("%s", name[total]);

                printf("quantity: ");
                scanf("%d", &stock[total]);

                printf("price: ");
                scanf("%f", &cost[total]);

                total++;
            }
        }

        else if (option == 2) {
            if (total == 0) {
                printf("no items recorded yet.\n");
            } else {
                printf("\n--- all products ---\n");
                for (j = 0; j < total; j++) {
                    printf("%d | %s | qty: %d | price: %.2f\n",
                           id[j], name[j], stock[j], cost[j]);
                }
            }
        }

        else if (option == 3) {
            if (total == 0) {
                printf("nothing to calculate.\n");
            } else {
                float sum = 0;
                float maxv = stock[0] * cost[0];
                float minv = stock[0] * cost[0];
                int maxp = 0;
                int minp = 0;

                for (j = 0; j < total; j++) {
                    float temp = stock[j] * cost[j];
                    sum += temp;

                    if (temp > maxv) {
                        maxv = temp;
                        maxp = j;
                    }
                    if (temp < minv) {
                        minv = temp;
                        minp = j;
                    }
                }

                printf("total inventory value: %.2f\n", sum);
                printf("highest value item: %s (%.2f)\n", name[maxp], maxv);
                printf("lowest value item: %s (%.2f)\n", name[minp], minv);
            }
        }

        else if (option == 4) {
            if (total == 0) {
                printf("no data available.\n");
            } else {
                int key;
                int flag = 0;

                printf("enter id to search: ");
                scanf("%d", &key);

                for (j = 0; j < total; j++) {
                    if (id[j] == key) {
                        printf("found: %d | %s | qty: %d | price: %.2f\n",
                               id[j], name[j], stock[j], cost[j]);
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    printf("product not found.\n");
                }
            }
        }

        else if (option == 5) {
            printf("goodbye.\n");
            break;
        }

        else {
            printf("invalid option.\n");
        }
    }

    return 0;
}
