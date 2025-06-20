#ifndef Mass_h
#define Mass_h
#include <iostream>
#include <fstream>
#include <ctime>
#include "limits"

#define LINUX
//#define WIN

#ifdef WIN
#ifdef max
#undef max
#endif
#endif

class Mass
{
  int *arr = nullptr;     // Массив элементов
  int *changes = nullptr; // Массив изменений
  int size = 0;           // Размер массива
  int deleted_item = 0;   // Последний удалённый элемент
  
  enum change {NONE, CREATE, DELETE_FORWARD, DELETE_BACK, DELETE_LAST, INSERT, FIND, REPLACE, SORT, SHUF};
  enum colors {DEF, RED, GREEN, YELLOW, BLUE};
  
  void create_array(); // Создаём массив
  void open_file(std::ifstream **input, int &file_size); // Открытие файла и определение его размера
  void insert_item(int pos_add); // Добавляем элемент
  void delete_item(int pos_del); // Удаляем элемент
  int find_item(int find, int mode, int pos_start); // Ищем элемент
  void quick_sort(int left, int right); // Быстрая сортировка
  std::string change_color(int color); // Изменение цвета текста
  
public:
  void initialization(); // Начальная инициализация
  void menu_insert_items(); // Меню добавления элементов
  void menu_delete_items(); // Меню удаления элементов
  void menu_find_items(); // Меню поиска элементов
  void menu_replace_items(); // Меню замены элементов
  void sort_items(); // Сортируем элементы
  void shuffling_items(); // Перемешиваем элементы
  void clear_changes(); // Обнуление индикаторов предыдущих изменений
  void print(); // Вывод массива на экран

  void get_int(int &var); // Получение числа от пользователя
  void clear_screen(); // Очистка экрана для linux и windows
  Mass &operator= (Mass &mass);
};


#endif
