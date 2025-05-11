#ifndef MAINMASS_H
#define MAINMASS_H

#include <iostream>
#include "Mass.h"
#include "createarray.h"
#include "deletearray.h"


class Main_mass
{
  Mass *main_arr = nullptr;
  int size_of_array = 0;
  
  int select_arr(); // Выбор массива для обработки
  void print_mass(); // Вывод массивов на экран

public:
  void create(); // Запуск работы с массивами 
};


#endif
