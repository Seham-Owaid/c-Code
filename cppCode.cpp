#include<iostream>
#include<cmath>
#include <string>
#include<fstream>
using namespace std; 

//The students names who worked hard to create this c++ program:
//Raghad frayhan saad alharthi # 44202915
//Reem bader saleem alsofiani # 44252971
//Deemah shaker owaidh althagafi # 44206762
//Seham Owaidh Moaidh Albogami # 44204608

/* THIS IS A FULL C++ PROGRAM THAT SOLVES A BIG PROBLEM THAT CAN BE SPLIT INTO SMALLER PROBLEMS, So we split the work between us
 = The program IS ABOUT CURRENCY EXCHANGE so we ask the user to put the currency that he has AND the currency that he want
to exchange And we check if the user put CAPITAL letters instead of small letters and the program do the exchange. 
inputs : word - word2 - money 
inputs from files : cur1 - cur2 - rate1 - rate2
outputs : word3 - word4 - R - (program statments)   */

//global variables: 
string word,word2;
ifstream cinFile;
ofstream coutFile;
double rate1,rate2;
string strf1,strf2;
string saudi="SAR",Kuwait="KWD";
string Qatar="QAR",Emirates="AED";
string Bahrain="BHD",oman="OMR";


//function to chack if the user enters the correct currency .
//it's formal parameters : str
//it's return value : true /false
bool capitalletters(string str){
    if(( str==saudi)|| (str==Kuwait)|| (str==Qatar)|| (str==Emirates)|| (str==Bahrain)|| (str==oman))
     return true;
      return false; 
    }
    

//function to ask the user to enter money.
//it's formal parameters : no formal parameters
//it's return value :no return value because it is void
void AskForMoney(){
    cout<<"How much money you want to exchange?";
}



//function to exchange the money from the file .
//it's formal parameters : strf1 / strf2 / myRate
//it's return value : R 
double exchangeRate(string strf1,string strf2,double myRate){
    
double R;
string cur1, cur2;
double rate1, rate2;
  cinFile.open("ExchangeRate.txt");
      while(!cinFile.eof())
   {
          cinFile>>rate1>>cur1>>rate2>>cur2;
          
        if(strf1==cur1 && strf2==cur2)
           {R=myRate*rate2;}
        else if(strf1==cur2 && strf2==cur1)
           {R=myRate/rate2;}
    }
  cinFile.close();
        return R;  }
        
        
int main() {
    
double money;

cout<< " The currencies we have exchange for are: \n"<<endl;
cout<<" SAR --> Saudi Arabia Riyal\n KWD --> Kuwaiti Dinar "<<endl;
cout<<" QAR --> Qatar Riyal\n AED --> United Arab Emirates Dirham "<<endl;
cout<<" BHD --> Bahraini Dinar\n OMR --> Omani Rial\n "<<endl;


cout<<"What is the currency you have?";
getline(cin,word);
cout<<endl;
string word3;
// loop to chack if the user enters a small letters it will show as "incorrect..." but if the user put a capital letters the code will check and shows it, if it's correct 
  for (int i=0;i<word.length();i++)
    {word3+= static_cast<char>(toupper(word[i])); } 
       if(!capitalletters(word3))
{         
    cout<<"incorrect abbreviation please provide it again" <<endl;
    word3.clear();
    getline(cin,word);
  for (int i=0;i<word.length();i++)
    {word3+= static_cast<char>(toupper(word[i])); }
   capitalletters(word3);
}



cout<<"What is the currency you want to exchange it for?"<<endl,
getline(cin,word2);
string word4;
// loop chack if the user enters a small letters it will show as "incorrect..." but if the user put a capital letters the code will check and shows it, if it's correct 
  for (int i=0;i<word2.length();i++)
    {word4+= static_cast<char>(toupper(word2[i])); }
       if(!capitalletters(word4))
{ 
    cout<<"incorrect abbreviation please provide it again" <<endl;
    word4.clear();
    getline(cin,word2);
  for (int i=0;i<word2.length();i++)
    {word4+= static_cast<char>(toupper(word2[i])); }
   capitalletters(word4);
}


//function call to ask for money
AskForMoney();
cin>>money;
cout<<endl;

//output the last result of exchange 
cout<<money<<" "<<word3<<" is "<<exchangeRate( word3, word4, money)<<" "<<word4;

return 0; }
