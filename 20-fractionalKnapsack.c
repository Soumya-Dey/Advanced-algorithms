#include<stdio.h>
#define N 3

struct object
{   
    float cost;
    float weight;
    float ratio;
    float x;
};
typedef struct object object;

int greedy_cost();
int greedy_weight();
int greedy_ratio();
void disp();
void swap(object *a, object *b);

object obj[N];
int capcity = 10;

int main()
{
    obj[0].cost = 7;
    obj[1].cost = 2;
    obj[2].cost = 5;
    //obj[3].cost = 40;
    //obj[4].cost = 60;

    obj[0].weight = 9;
    obj[1].weight = 5;
    obj[2].weight = 6;
    //obj[3].weight = 40;
    //obj[4].weight = 50;

    greedy_ratio();
    greedy_cost();
    greedy_weight();

    return 0;
}

int greedy_cost()
{
    int i, j, sack = capcity;
    object t;
    float x[N], net=0.0;

    for(i = 0 ; i < N ; i++)
    {
        obj[i].ratio = obj[i].cost/obj[i].weight;//initializing the ratio
        obj[i].x = 0.0;
    }
    
    // sorting by cost
    for(i = 0 ; i < N - 1 ; i++)
    {
        for(j = 0 ; j < N - i - 1 ; j++)
        {
            if(obj[j].cost < obj[j+1].cost)
                swap(&obj[j], &obj[j+1]);
        }
    }

    //fractional knap sack
    for(i = 0 ; i < N && sack != 0; i++)
    {
        if(sack > obj[i].weight)
            obj[i].x = 1.0;
        else
            obj[i].x = sack/obj[i].weight;
         
        sack -=  obj[i].x *  obj[i].weight;
    }
    
    for(i = 0 ; i < N ; i++)
        net += obj[i].x * obj[i].cost;
    
    printf("max cost : \n");
    disp();
    printf("\nprofit = %f\n\n", net);
}

int greedy_weight()
{
    int i, j, sack = capcity;
    object t;
    float x[N], net=0.0;

    for(i = 0 ; i < N ; i++)
    {
        obj[i].ratio = obj[i].cost/obj[i].weight;//initializing the ratio
        obj[i].x = 0.0;
    }
    
    // sorting by weight
    for(i = 0 ; i < N - 1 ; i++)
    {
        for(j = 0 ; j < N - i - 1 ; j++)
        {
            if(obj[j].weight > obj[j+1].weight)
                swap(&obj[j], &obj[j+1]);
        }
    }

    //fractional knap sack
    for(i = 0 ; i < N && sack != 0; i++)
    {
        if(sack > obj[i].weight)
            obj[i].x = 1.0;
        else
            obj[i].x = sack/obj[i].weight;
         
        sack -=  obj[i].x *  obj[i].weight;
    }
    
    for(i = 0 ; i < N ; i++)
        net += obj[i].x * obj[i].cost;
    
    printf("min weight : \n");
    disp();
    printf("\nprofit = %f\n\n", net);
}

int greedy_ratio()
{
    int i, j, sack = capcity;
    object t;
    float x[N], net=0.0;

    for(i = 0 ; i < N ; i++)
    {
        obj[i].ratio = obj[i].cost/obj[i].weight;//initializing the ratio
        obj[i].x = 0.0;
    }
    
    // sorting by ratio
    for(i = 0 ; i < N - 1 ; i++)
    {
        for(j = 0 ; j < N - i - 1 ; j++)
        {
            if(obj[j].ratio < obj[j+1].ratio)
                swap(&obj[j], &obj[j+1]);
        }
    }

    //fractional knap sack
    for(i = 0 ; i < N && sack != 0; i++)
    {
        if(sack > obj[i].weight)
            obj[i].x = 1.0;
        else
            obj[i].x = sack/obj[i].weight;
         
        sack -=  obj[i].x *  obj[i].weight;
    }
    
    for(i = 0 ; i < N ; i++)
        net += obj[i].x * obj[i].cost;
    
    printf("max ratio : \n");
    disp();
    printf("\nprofit = %f\n\n", net);
} 

void disp()
{
    int i;
    printf("cost\t= ");
    for(i = 0 ; i < N ; i++)
        printf("%0.2f \t", obj[i].cost);

    printf("\nweight\t= ");
    for(i = 0 ; i < N ; i++)
        printf("%0.2f \t", obj[i].weight);

    printf("\nratio\t= ");
    for(i = 0 ; i < N ; i++)
        printf("%0.2f \t", obj[i].ratio); 

    printf("\nx\t= ");
    for(i = 0 ; i < N ; i++)
        printf("%0.2f \t", obj[i].x);  
}

void swap(object *a, object *b)
{
    object t;
    t.weight    = a->weight;
    t.cost      = a->cost;
    t.ratio     = a->ratio;

    a->weight    = b->weight;
    a->cost      = b->cost;
    a->ratio     = b->ratio;

    b->weight    = t.weight;
    b->cost      = t.cost;
    b->ratio     = t.ratio;
}