#include "Mass.h"


int Mass::get_num_of_elements() // Получает стартовое количество элементов
{
  int num_of_elements = 0;

  std::cout << std::endl
	    << "Specify the number of elements: ";
  std::cin >> num_of_elements;

      return num_of_elements;
}


void Mass::initialization() // Начальная инициализация
{
  int what_to_do = 0;
  
  std::cout << std::endl
	    << "1.Fill trivially" << std::endl
	    << "2.Generate randomly" << std::endl
	    << "3.Enter array elements manually" << std::endl
	    << "4.Read from file" << std::endl	     
	    << "Select action: ";
  
  std::cin >> what_to_do;
  
  switch(what_to_do)
    {       	  
    case 1: // Заполняем тривиально
      {
	size = get_num_of_elements();
	arr = new int[size];
	
	for (int i = 0; i < size; ++i) arr[i] = i+1;
      }; break;
      
    case 2: // Генерируем рандомно
      {
	
      }; break;
      
    case 3: // Вводим с клавиатуры
      {
	
      }; break;
      
    case 4: // Читаем из файла
      {
	
      }; break;
    }
}


void Mass::insert_items() // Добавляем элементы
{
  
}


void Mass::delete_items() // Удаляем элементы
{
  
}


void Mass::seek_items() // Ищем элементы
{
  
}


void Mass::replace_items() // Заменяем элементы
{
  
}


void Mass::sort_items() // Сортируем элементы
{
  
}


void Mass::mix_items() // Перемешиваем элементы
{
  
}

void Mass::print() // Вывод массива на экран
{
  for(int i = 0; i < size; ++i)
    {
      std::cout << arr[i] << " ";
    }
}


Mass &Mass::operator=(Mass &mass)
{
  this->size = mass.size;
  this->arr = new int[this->size];

  for (int i = 0; i < size; ++i) this->arr[i] = mass.arr[i];

  delete[] mass.arr;
  mass.arr = nullptr;

  return *this;
}
