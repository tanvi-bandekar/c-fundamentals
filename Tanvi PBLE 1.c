#include <stdio.h>
#define MAX 50
struct Package
{
    int no;
    float value;
    float weight;
    float ratio;
    float quantity;
};
struct Package p[MAX];
int n = 0;
float capacity = 0;
void enterDetails()
{
    int i;
    printf("Enter number of packages: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        p[i].no = i + 1;
        printf("\nEnter value of package %d: ", i + 1);
        scanf("%f", &p[i].value);
        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &p[i].weight);
        p[i].ratio = 0;
        p[i].quantity = 0;
    }
    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);
    printf("\nPackage details entered successfully!\n");
}
void displayDetails()
{
    int i;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    printf("\nPackage\tValue\tWeight\tRatio\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].no,
               p[i].value,
               p[i].weight,
               p[i].ratio);
    }
    printf("Vehicle Capacity = %.2f\n", capacity);
}
void calculateRatio()
{
    int i;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    for(i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }
    printf("\nValue/Weight ratios calculated successfully.\n");
}
void sortPackages()
{
    int i, j;
    struct Package temp;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nPackages sorted by decreasing ratio.\n");
}
void findMaximumValue()
{
    int i;
    float remaining = capacity;
    float totalValue = 0;
    float totalWeight = 0;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    /* Calculate ratios if not already calculated */
    for(i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
        p[i].quantity = 0;
    }
    /* Sort packages according to ratio */
    sortPackages();
    for(i = 0; i < n; i++)
    {
        if(remaining == 0)
            break;
        if(p[i].weight <= remaining)
        {
            /* Complete package is selected */
            p[i].quantity = 1;
            remaining = remaining - p[i].weight;
            totalWeight = totalWeight + p[i].weight;
            totalValue = totalValue + p[i].value;
        }
        else
        {
            /* Fraction of package is selected */
            p[i].quantity = remaining / p[i].weight;
            totalWeight = totalWeight + remaining;
            totalValue = totalValue + (p[i].value * p[i].quantity);
            remaining = 0;
        }
    }
    printf("\nMaximum value calculated successfully.\n");
    printf("Total Weight Used = %.2f\n", totalWeight);
    printf("Maximum Value = %.2f\n", totalValue);
}
void displaySelectedPackages()
{
    int i;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    printf("\nSelected Packages:\n");
    printf("Package\tRatio\tQuantity\n");
    for(i = 0; i < n; i++)
    {
        if(p[i].quantity > 0)
        {
            printf("%d\t%.2f\t%.2f",
                   p[i].no,
                   p[i].ratio,
                   p[i].quantity);
            if(p[i].quantity == 1)
                printf(" (Complete)\n");
            else
                printf(" (Fraction)\n");
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n========== FRACTIONAL KNAPSACK ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                enterDetails();
                break;
            case 2:
                displayDetails();
                break;
            case 3:
                calculateRatio();
                break;
            case 4:
                sortPackages();
                break;
            case 5:
                findMaximumValue();
                break;
            case 6:
                displaySelectedPackages();
                break;
            case 7:
                printf("\nProgram terminated.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(choice != 7);
    return 0;
}