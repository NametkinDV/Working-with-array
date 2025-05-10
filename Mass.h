#ifndef Mass_h
#define Mass_h
#include <iostream>


class Mass
{
  int *arr = nullptr;
  int size = 0;
  
public:
  int get_num_of_elements(); // Получает стартовое количество элементов
  void initialization(); // Начальная инициализация
  void insert_items(); // Добавляем элементы
  void delete_items(); // Удаляем элементы
  void seek_items(); // Ищем элементы
  void replace_items(); // Заменяем элементы
  void sort_items(); // Сортируем элементы
  void mix_items(); // Перемешиваем элементы
  void print(); // Вывод массива на экран

  Mass &operator= (Mass &mass);
};


#endif
