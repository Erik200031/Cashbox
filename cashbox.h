#pragma once
#ifndef CASHBOX_H_
#define CASHBOX_H_

//class declaration
class Cashbox
{
  public:
  Cashbox();
  void menu();
  void add();
  void take_out();
  void display_cash();
  void change_value_type();
  private:
  double cash_value;
  std::string type_value;
  double counter_for_add,counter_for_out;
};

#endif //CASHBOX_H_
