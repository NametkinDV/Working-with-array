#ifndef MainMass_H
#define MainMass_H

#include <iostream>
#include "Mass.h"

//#define LINUX
//#define WIN

class Main_mass
{
  Mass *main_arr = nullptr; // Массив элементов
  int size = 0; // Размер массива

  void create_mass(int pos_add); // Создаём массив
  void menu_create_mass(); // Меню создания массива
  void delete_mass(int pos_del); // Удаляем массив
  void menu_delete_mass(); // Меню удаления массива
  void delete_all(); // Полная очистка памяти
  int select_arr(); // Выбор массива для обработки
  void print_mass(); // Вывод массивов на экран

public:
  void create(); // Запуск работы с массивами
  void get_int(int &var); // Получение числа от пользователя
  void clear_screen(); // Очистка экрана для linux и windows
};


#endif
