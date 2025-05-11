#ifndef Mass_h
#define Mass_h
#include <iostream>
#include <ctime>

class Mass
{
  int *arr = nullptr;
  int size = 0;

  void create_array(); // Создаём массив
  void insert_item(); // Добавляем элемент
  void delete_item(); // Удаляем элемент
  void find_item(); // Ищем элемент
  void replace_item(); // Заменяем элемент
  
public:
  void initialization(); // Начальная инициализация
  void menu_insert_items(); // Меню добавления элементов
  void menu_delete_items(); // Меню удаления элементов
  void menu_find_items(); // Меню поиска элементов
  void menu_replace_items(); // Меню замены элементов
  void sort_items(); // Сортируем элементы
  void mix_items(); // Перемешиваем элементы
  void print(); // Вывод массива на экран

  Mass &operator= (Mass &mass);
};


#endif
