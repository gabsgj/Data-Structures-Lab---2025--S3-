#include <stdio.h>

typedef struct {
    int coeff;
    int exp;
}Polynomial;

void printPoly(Polynomial a[], int n){
    for (int i = 0; i < n;i++)
    {
        if (a[i].exp==0)
        printf("%d", a[i].coeff);
        else
        printf("%d x^%d", a[i].coeff, a[i].exp);
        if (i!=n-1)
        printf(" + ");
    }
    printf("\n");
}

void addPolynomials(Polynomial p1[], int n1, Polynomial p2[], int n2, Polynomial result[],int *nResult){
    int i, j, k;
    i=j=k=0;

    while (i<n1 && j<n2)
    {
        if (p1[i].exp>p2[j].exp){
            result[k].exp=p1[i].exp;
            result[k++].coeff=p1[i++].coeff;
        } else if (p1[i].exp<p2[j].exp){
            result[k].exp=p2[j].exp;
            result[k++].coeff=p2[j++].coeff;
        }else{
            result[k].exp=p2[j].exp;
            result[k++].coeff=p2[j++].coeff + p1[i++].coeff;
        }
    }
    while(i<n1)
    {
        result[k].exp=p1[i].exp;
        result[k++].coeff=p1[i++].coeff;
    }
    while(j<n2)
    {
        result[k].exp=p2[j].exp;
        result[k++].coeff=p2[j++].coeff;
    }
    *nResult = k;
}


int main()
{
    int n1, n2;
    printf("Enter the number of terms in the first polynomial(n1) : ");
    scanf("%d", &n1);
    Polynomial p1[n1];
    printf("Enter the polynomial expression in descending order : \n");
    for (int i = 0; i < n1 ; i++)
    {
        printf("Enter the coefficient : ");
        scanf("%d", &p1[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d", &p1[i].exp);
    }
    printPoly(p1,n1);
    printf("Enter the number of terms in the second polynomial(n1) : ");
    scanf("%d", &n2);
    Polynomial p2[n1];
    printf("Enter the polynomial expression in descending order : \n");
    for (int i = 0; i < n2 ; i++)
    {
        printf("Enter the coefficient : ");
        scanf("%d", &p2[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d", &p2[i].exp);
    }
    printPoly(p2, n2);
    Polynomial result[n1+n2];
    int nres;
    addPolynomials(p1, n1, p2, n2, result, &nres);

    printf("Result = \n");
    printPoly(result, nres);

}