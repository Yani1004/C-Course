#include <stdio.h>

struct Product{
    char type[30];
    double price;
    int amount;
};

struct Shop{
    char name[30];
    char address[30];
    struct Product products[5];

};
void searchProduct(char userInput[],int amount,struct Shop shop){
    for(int i = 0;i < 2;i++){
        if(strcmp(userInput,shop.products[i].type)==0){
            if(shop.products[i].amount>=amount){
                shop.products[i].amount-=amount;
            }else{
                printf("Out of product amount!\n");
            }
        }else{
            printf("Product does not exist!\n");
        }

    }

}
void input(struct Shop shop){
    char userInput[30];
    int amount;
    scanf("%s",&userInput);
    scanf("%d",&amount);
    searchProduct(userInput,amount,shop);
}




int main(){
    struct Shop shop1;
    strcpy(shop1.name,"Kaufland");
    strcpy(shop1.address,"ulica1");
    struct Product product1;
    strcpy(product1.type,"TV");
    product1.amount = 101;
    product1.price = 500.59;

    struct Product product2;
    strcpy(product2.type,"Shoes");
    product2.amount = 50;
    product2.price = 80.59;

    shop1.products[0]=product1;
    shop1.products[1]=product2;
    //char userInput[30];
    //scanf("%s",&userInput);
    //printf("%s",userInput);
    /*
    printf("%s\n",shop1.name);
    printf("%s\n",shop1.address);
    printf("Product type - %s\n",shop1.products[0].type);
    printf("Product price %f\n",shop1.products[0].price);
    printf("Product abount %f\n",shop1.products[0].amount);

    printf("Product type - %s\n",shop1.products[1].type);
    printf("Product price %f\n",shop1.products[1].price);
    printf("Product abount %f\n",shop1.products[1].amount);
    */
    input(shop1);
    return 0;
}
