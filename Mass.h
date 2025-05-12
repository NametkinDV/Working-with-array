#ifndef Mass_h
#define Mass_h
#include <iostream>
#include <ctime>

class Mass
{
  int *arr = nullptr;
  int size = 0;

  void create_array(); // Создаём массив
  void insert_item(int pos_add); // Добавляем элемент
  void delete_item(int pos_del); // Удаляем элемент
  int find_item(int find, int mode, int pos_start); // Ищем элемент
  void quick_sort(int left, int right); // Быстрая сортировка
  
public:
  void initialization(); // Начальная инициализация
  void menu_insert_items(); // Меню добавления элементов
  void menu_delete_items(); // Меню удаления элементов
  void menu_find_items(); // Меню поиска элементов
  void menu_replace_items(); // Меню замены элементов
  void sort_items(); // Сортируем элементы
  void shuffling_items(); // Перемешиваем элементы
  void print(); // Вывод массива на экран

  Mass &operator= (Mass &mass);
};


#endif
