#include <stdio.h>

int main() {
    int choice;
    float balance = 10000.0;  // initial balance ₹10,000
    float amount, bonus;

    do {
        // Display the menu
        printf("\n------ Smart Bank Account Manager ------\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:  // Deposit
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                // Apply 1% bonus if deposit > 25,000
                if(amount > 25000) {
                    bonus = amount * 0.01;
                    printf("Bonus of ₹%.2f added!\n", bonus);
                    amount += bonus;
                }

                balance += amount;  // Add amount to balance
                balance -= 5;       // Service charge
                printf("Service charge ₹5 applied.\n");
                printf("Updated Balance: ₹%.2f\n", balance);
                break;

            case 2:  // Withdraw
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount > balance) {
                    printf("Warning: Insufficient balance! Withdrawal not allowed.\n");
                } else {
                    balance -= amount;
                    balance -= 5;   // Service charge
                    printf("Service charge ₹5 applied.\n");
                    printf("Updated Balance: ₹%.2f\n", balance);
                }
                break;

            case 3:  // Check balance
                printf("Your Current Balance: ₹%.2f\n", balance);
                break;

            case 4:  // Exit
                printf("Thank you for banking with us!\n");
                break;

            default:
                printf("Invalid choice! Please enter 1–4.\n");
        }

    } while(choice != 4);  // Continue until user chooses Exit

    return 0;
}
