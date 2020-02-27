#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * January 20, 2020
 * Developer Name: Güven TUNCAY
 * Problem link: https://www.hackerrank.com/contests/inzva-algorithm-winter-camp-2020-qualification/challenges/post-war
**/



int main()
{
    /*
        Sample Input 0
        5 6 18
        2 4 15
        3 4 2
        3 4 4
        1 5 11
        4 5 9
        2 3 4
        Sample Output 0
        26

        Sample Input 1
        8 7 9
        3 7 17
        2 8 17
        5 6 11
        3 7 7
        6 8 15
        6 8 6
        1 3 7
        Sample Output 1
        56
    */
    int numOfCity,numOfRoads,costOfNewRoad;// N,M,K
    int X,Y,C; // Which means there was a road between X and Y, and the cost of repairing that road is C.
    printf("Please enter number of city, number of roads, cost of new road\n");
    scanf("%d",&numOfCity);
    scanf("%d",&numOfRoads);
    scanf("%d",&costOfNewRoad);
    int Xarr[numOfRoads],Yarr[numOfRoads],Carr[numOfRoads];//Xarr is an array for all elements of X values. same as. same as Yarr, Carr
    bool isVisited[numOfCity];// we going to use this boolean array in kruskal algorithm
    printf("N M K: %d %d %d\n\n",numOfCity,numOfRoads,costOfNewRoad);

    for(int i = 0 ; i < numOfRoads ; i++) // setting all elements of the array to zero, ={0} method didn't work, idk why.
    {
        Xarr[i] = 0;
        Yarr[i] = 0;
        Carr[i] = 0;
    }

    printf("Please enter roads before the war\n");
    printf("        X Y C\n");
    for(int i = 0 ; i < numOfRoads ; i++)//getting X Y C
    {
        printf("road %d :",i+1);
        scanf("%d",&X);
        scanf("%d",&Y);
        scanf("%d",&C);
        X--,Y--;// the first element of an array is 0. element. if we don't do this, we going to have problem for last element of array.


            Xarr[i] = X;//we going to use these roads in kruskal algorithm
            Yarr[i] = Y;
            Carr[i] = C;

    }
    printf("\n");

   // printf("Unsorted roads\n");
    for(int i = 0 ; i < numOfRoads ; i++)
      //  printf("%d %d %d\n",Xarr[i],Yarr[i],Carr[i]);

    //bubble sort for kruskal algorithm
    for( int i = 0 ; i < numOfRoads ; i++)
        for( int j = 0 ; j < numOfRoads - 1 ; j++)
        {
            if(Carr[j]>Carr[j+1])
            {
                 int x = Carr[j];
                Carr[j] = Carr[j+1];
                Carr[j+1] = x;
                x = Xarr[j];
                Xarr[j] = Xarr[j+1];
                Xarr[j+1] = x;
                x= Yarr[j];
                Yarr[j] = Yarr[j+1];
                Yarr[j+1] = x;
            }
        }


     //   printf("Sorted roads\n");
    for( int i = 0 ; i < numOfRoads ; i++)
     //   printf("%d %d %d\n",Xarr[i],Yarr[i],Carr[i]);

    //set all elements of bool array to false;
    for( int i = 0 ; i < numOfCity ; i++)
        isVisited[i] = false;

    //start of kruskal
     int totalCost = 0;//the minimum coast
     int kruskalRoad = 0;
    for( int i = 0,j = 0 ; j < numOfRoads ; j++)
    {
        if(isVisited[Xarr[j]] == false || isVisited[Yarr[j]] == false )
        {
            kruskalRoad++;

            if(Carr[j] < costOfNewRoad )
            {                           // if cost of repairing the road is more expensive than cost of new road,
                totalCost += Carr[j];   // we can build new road instead of repairing old road.
               // printf("kruskal: %d %d %d\n",Xarr[j],Yarr[j],Carr[j]);
            }else{
                totalCost += costOfNewRoad;
                //printf("kruskal: %d %d %d\n",Xarr[j],Yarr[j],costOfNewRoad);
            }
            isVisited[Xarr[j]] = true;
            isVisited[Yarr[j]] = true;
        }
    }//end of kruskal
  //  printf("kruskal road num %d\n",kruskalRoad);
  //  printf("Kruskal roads cost: %d\n",totalCost);

    /*Kruskal algorithm creates minimum spanning tree. And in all the trees,
    the sum of nodes is one more than the sum of the edges.
    if we have 3 nodes and 1 edges, we need one more edge for connect nodes each other.
    In our problem, numOfCity is sum of nodes and kruskalRoad is sum of edges.
    */
    while(numOfCity != kruskalRoad + 1)
    {
        totalCost += costOfNewRoad;
        kruskalRoad++;
    }

    printf("Total coast: %d\n",totalCost);

}
