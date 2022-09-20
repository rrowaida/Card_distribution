#include <iostream>
#include <vector>
#include <ctime>
const char* CNum [13]= {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"};
const char* CType [4]= {"Hearts", "Club", "Spade", "Diamond"};
std::vector<int> deal_hand(int i)
{
    std::vector<int> res;
    if(i<1 || i>52)
        return res;
    std::vector<int> temp;
    for(int j=0; j<52; j++) {
        temp.push_back(j);
    }
    std::vector<int>::iterator it=temp.begin();
    srand((int)time(0));
    int r_pos = rand()%52;
    for(int j=0; j<i; j++)
    {
        //std::cout<<r_pos<<"\n";
        res.push_back(temp[r_pos]);
        temp.erase(it+r_pos);
        r_pos = rand() % temp.size();
    }
    //std::cout<<"size: "<<res.size()<<"\n";
    return res;
}


int main() {
    int n;
    std::cout<<"Enter a number between 1-52 as the size of the randomly distributed hand: ";
    std::cin>>n;
    std::vector<int> for_print = deal_hand(n);
    if(for_print.size()==0)
        std::cout<<"Input hand size is not permitted. Enter a value between 1-52.\n";
    else
        std::cout<<"The hand contains: ";

    for(int i=0; i<n; i++)
    {
        if(i<n-1)
        {
            std::cout<<CNum[for_print[i]%13]<<" of "<<CType[for_print[i]/13]<<", ";
        }
        else std::cout<<CNum[for_print[i]%13]<<" of "<<CType[for_print[i]/13]<<"\n";
    }
    return 0;
}