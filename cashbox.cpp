#include <iostream>
#include "cashbox.h"

//class implementation

Cashbox::Cashbox(){
  cash_value= 0;
  type_value = "AMD";
  counter_for_add=0;
  counter_for_out=0;
  menu();
}
void Cashbox::menu(){
   int ch;
    do
    {
        system ("clear");
        std::cout << "............................................\n";
        std::cout << "                  CASHBOX\n";
        std::cout << "--------------------------------------------\n\n";
        std::cout << "::::::::::::::: PROGRAMM MENU :::::::::::::::\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Change the type of cash value \n";
        std::cout << "2. Display the total cash \n";
        std::cout << "3. Add some cash to the cashbox \n";
        std::cout << "4. Take some cash out of the box \n";
        std::cout << "Enter Your Choice : ";
        std::cin >> ch;
        system ("clear");
        switch (ch)
        {
           case 1:
              change_value_type();
              break;
           case 2:
              display_cash();
              break;
           case 3:
              add();
              break;
           case 4:
              take_out();
              break;
         }        

    }while (ch);
}

void Cashbox::change_value_type(){
  int ch;
  std::cout << "0. Exit\n";
  std::cout << "1. AMD (\"DRAM\") \n";
  std::cout << "2. RUB (\"RUBLI\") \n";
  std::cout << "3. USD (\"DOLLAR\") \n";
  std::cout << "Enter Your Choice : ";
  std::cin >> ch;
  if(ch==0){exit(0);}
  else if(ch==1){
    if (type_value=="RUB"){
      type_value = "";
      cash_value = cash_value * 6.95;
      counter_for_add = counter_for_add *6.95;
      counter_for_out = counter_for_out *6.95;
      type_value = "AMD";
    }
    else if(type_value=="USD"){
      type_value = "";
      cash_value = cash_value * 480;
            counter_for_add = counter_for_add *480;
      counter_for_out = counter_for_out *480;
      type_value = "AMD";      
    }
  }
  else if(ch==2){
    if (type_value=="AMD"){
      type_value = "";
      cash_value = cash_value / 6.95;
      counter_for_add = counter_for_add /6.95;
      counter_for_out = counter_for_out /6.95;
      type_value = "RUB";
    }
    else if(type_value=="USD"){
      type_value = "";
      counter_for_add = (counter_for_add* 480) / 6.95;
      counter_for_out = (counter_for_out * 480) / 6.95;
      cash_value = (cash_value * 480) / 6.95;
      type_value = "RUB";      
    }
  }
  else if(ch==3){
    if (type_value=="AMD"){
      type_value = "";
      counter_for_add = (counter_for_add/ 480);
      counter_for_out = (counter_for_out/ 480);
      cash_value = cash_value / 480;
      type_value = "USD";
    }
    else if(type_value=="RUB"){
      type_value = "";
      counter_for_add = (counter_for_add* 6.95) / 480;
      counter_for_out = (counter_for_out* 6.95) / 480;
      cash_value = (cash_value * 6.95) / 480;
      type_value = "USD";      
    }
  }
}

void Cashbox::display_cash(){
  std::cout<<"The current amount of the Cash is "<< cash_value<<" "<<type_value<<"\n";
  std::cout<<"How mush cash was put in the cashbox is  "<<counter_for_add<<" "<<type_value<<"\n";
  std::cout<<"How much cash was take out of the cashbox is "<<counter_for_out<<" "<<type_value<<"\n";
  std::cout<<"If you want to exit please input 0 \n";
  std::cout<<"or for continue input 1\n";
  int ch;
  std::cin>>ch;
  if(ch==0){exit(0);}
}

void Cashbox::add(){
  std::cout<<"How much is the purchase price ? \n";
  std::cout<<"The current type of value is "<< type_value << "\n";
  std::cout<<"Input price : ";
  double tmp;
  std::cin>>tmp;
  cash_value+=tmp;
  counter_for_add+=tmp;
}

void Cashbox::take_out(){
  std::cout << "How much you want to take ? ";
  std::cout<<"The current type of value is "<< type_value << "\n";
  std::cout << "Enter : ";
  double tmp;
  std::cin>>tmp;
  while(cash_value<tmp){
    std::cout<<"There is not that much money in the cashbox ! \n Please enter again : ";
    std::cin>>tmp;
  }
  cash_value-=tmp;
  counter_for_out+=tmp;
}