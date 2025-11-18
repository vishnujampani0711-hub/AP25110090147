#include <stdio.h>

#define MAX 20

int id[MAX], qty[MAX], price[MAX];
int count = 0;
int rack[3][3];

void add_product() {
    int pid, q, p, i, dup = 0;

    if (count >= MAX) {
        printf("warehouse full\n");
        return;
    }

    printf("enter product id: ");
    scanf("%d", &pid);

    for (i = 0; i < count; i++) {
        if (id[i] == pid) dup = 1;
    }

    if (dup) {
        printf("duplicate id not allowed\n");
        return;
    }

    printf("enter quantity: ");
    scanf("%d", &q);
    printf("enter price: ");
    scanf("%d", &p);

    if (q <= 0 || p <= 0) {
        printf("invalid qty or price\n");
        return;
    }

    id[count] = pid;
    qty[count] = q;
    price[count] = p;
    count++;

    printf("product added\n");
}

void search_product() {
    int pid, i;
    printf("enter id to search: ");
    scanf("%d", &pid);

    for (i = 0; i < count; i++) {
        if (id[i] == pid) {
            printf("id:%d qty:%d price:%d\n", id[i], qty[i], price[i]);
            return;
        }
    }
    printf("not found\n");
}

void update_qty() {
    int pid, i, ch, v;
    printf("enter id: ");
    scanf("%d", &pid);

    for (i = 0; i < count; i++) {
        if (id[i] == pid) {
            printf("1 increase  2 decrease: ");
            scanf("%d", &ch);

            printf("enter value: ");
            scanf("%d", &v);

            if (ch == 1) qty[i] += v;
            else if (ch == 2 && qty[i] >= v) qty[i] -= v;
            else {
                printf("invalid\n");
                return;
            }

            printf("updated qty: %d\n", qty[i]);
            return;
        }
    }
    printf("not found\n");
}

void rack_report() {
    int i, j;
    int max = rack[0][0], min = rack[0][0];
    int rmax = 0, cmax = 0, rmin = 0, cmin = 0;
    int sum = 0;

    printf("enter 3x3 rack values:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &rack[i][j]);
            sum += rack[i][j];
            if (rack[i][j] > max) { max = rack[i][j]; rmax = i; cmax = j; }
            if (rack[i][j] < min) { min = rack[i][j]; rmin = i; cmin = j; }
        }
    }

    printf("max:%d at (%d,%d)\n", max, rmax, cmax);
    printf("min:%d at (%d,%d)\n", min, rmin, cmin);
    printf("total:%d\n", sum);
}

void stock_value() {
    int i;
    int maxv = -1, minv = 2147483647;
    int idmax = -1, idmin = -1;
    long long total = 0;

    for (i = 0; i < count; i++) {
        int sv = qty[i] * price[i];
        printf("id:%d stock value:%d\n", id[i], sv);
        if (sv > maxv) { maxv = sv; idmax = id[i]; }
        if (sv < minv) { minv = sv; idmin = id[i]; }
        total += sv;
    }

    printf("highest value: id %d = %d\n", idmax, maxv);
    printf("lowest value: id %d = %d\n", idmin, minv);
    printf("total value: %lld\n", total);
}

void display_all() {
    int i;
    printf("id qty price stockvalue\n");
    for (i = 0; i < count; i++) {
        printf("%d %d %d %d\n", id[i], qty[i], price[i], qty[i] * price[i]);
    }
}

int main() {
    int op;
    while (1) {
        printf("\n1 add 2 search 3 update 4 rack 5 value 6 display 7 exit\n");
        scanf("%d", &op);
        if (op == 1) add_product();
        else if (op == 2) search_product();
        else if (op == 3) update_qty();
        else if (op == 4) rack_report();
        else if (op == 5) stock_value();
        else if (op == 6) display_all();
        else if (op == 7) break;
    }
    return 0;
}
