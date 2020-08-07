// Example program
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;
int main()
{
    srand( time(NULL) );
    int num;
    double index;
    cout<<"Input number of bags"<<endl;

    cin>>num;
    while (num<0)
        {
            cout<<"Bag number can not be less then 0. Input mew value"<<endl;
            cin>>num;
        }
    int bagWeight, badBagWeight;
    cout<<"Input good bag weight"<<endl;
    cin>>bagWeight;
    while (bagWeight<0)
        {
            cout<<"Bag weight can not be less then 0. Input mew value"<<endl;
            cin>>bagWeight;
        }
    cout<<"Input bad bag weight"<<endl;
    cin>>badBagWeight;
    while (badBagWeight<0 || badBagWeight == bagWeight)
        {
            cout<<"Bag weight can not be less then 0. Input mew value"<<endl;
            cin>>badBagWeight;
        }
    
    vector<int> bags;
    int bagNum = rand()%num;
    for (int i=0; i<num; i++)
    {
        bags[i]=bagWeight;
    }
    bags[bagNum]=badBagWeight;
    
   if (num%2!=0)
   {
        int tempnum=num-1;
        vector<int>left(tempnum/2);
        vector<int>right(tempnum/2);
        for (int i=0; i<tempnum/2; i++)
        {left[i]=bags[i];}
        for (int i=tempnum/2; i<tempnum; i++)
        {right[i]=bags[i];}
        double leftSumm=0, rightSumm=0;
        
        for (int i=0; i<left.size(); i++)
        {
            leftSumm+=(double)left[i]/i;
            rightSumm+=(double)right[i]/i;
        }

        if (leftSumm==rightSumm)
            index = bags.size()-1;
        else
        {
            index = abs(bagWeight-badBagWeight)/abs(leftSumm-rightSumm);
        }
 
    }
    else
    {
        vector<int>left(num/2);
        vector<int>right(num/2);
        for (int i=0; i<num/2; i++)
        {left[i]=bags[i];}
        for (int i=num/2; i<num; i++)
        {right[i]=bags[i];}
        
        double leftSumm=0, rightSumm=0;
        
        for (int i=0; i<left.size(); i++)
        {
            leftSumm+=(double)left[i]/i;
            rightSumm+=(double)right[i]/i;
        }
        
  
        index = abs(bagWeight-badBagWeight)/abs(leftSumm-rightSumm);
        
    }
    cout<<bagNum;
    cout<<index;
}

