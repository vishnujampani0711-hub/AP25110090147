#include <stdio.h>

int main() {
    int numCustomers, numItems;
    float price, subtotal, gst, totalBill;
    float totalRevenue = 0, highestBill = 0;
    int feedback, totalFeedback = 0;
    float averageFeedback;

    printf("Enter number of customers: ");
    scanf("%d", &numCustomers);


    for(int i = 1; i <= numCustomers; i++) {
        printf("\nCustomer %d:\n", i);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        subtotal = 0;


        for(int j = 1; j <= numItems; j++) {
            printf("Enter price of item %d: ", j);
            scanf("%f", &price);
            int qty;
            printf("Enter quantity of item %d: ", j);
            scanf("%d", &qty);

            subtotal = subtotal + (price * qty);
        }


        gst = subtotal * 0.05;
        totalBill = subtotal + gst;


        printf("Enter feedback rating (1-5): ");
        scanf("%d", &feedback);


        if(feedback < 1 || feedback > 5) {
            printf("Invalid feedback! Taking it as 3.\n");
            feedback = 3;
        }


        printf("\nCustomer %d Bill: ₹%.2f\n", i, totalBill);


        totalRevenue = totalRevenue + totalBill;
        totalFeedback = totalFeedback + feedback;


        if(totalBill > highestBill)
            highestBill = totalBill;
    }

    averageFeedback = (float)totalFeedback / numCustomers;


    printf("\n Restaurant Bill Summary \n");
    printf("Total Revenue Today: ₹%.2f\n", totalRevenue);
    printf("Average Feedback Rating: %.2f\n", averageFeedback);
    printf("Highest Single-Customer Bill: ₹%.2f\n", highestBill);

    return 0;
}
