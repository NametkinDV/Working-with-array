#include "Mass.h"


void Mass::create_array() // Создаём массив
{
  std::cout << std::endl
	    << "Specify the number of elements: ";
  std::cin >> size;

  arr = new int[size];
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
	create_array();
	for (int i = 0; i < size; ++i) arr[i] = i+1;
      }; break;
      
    case 2: // Генерируем рандомно
      {
	srand(std::time(0));
	create_array();
	for (int i = 0; i < size; ++i) arr[i] = rand() % 100 + 1; // В пределах от 0 до 100 
      }; break;
      
    case 3: // Вводим с клавиатуры
      {
	
      }; break;
      
    case 4: // Читаем из файла
      {
	
      }; break;
    }
}


void Mass::insert_item() // Добавляем элемент
{

}


void Mass::menu_insert_items() // Меню добавления элементов
{
  int what_to_do = 0;

  std::cout << std::endl;
  print(); 
  std::cout << std::endl;
  
  while(1)
    {
      std::cout << std::endl
		<< "1.Insert one element" << std::endl
		<< "2.Insert multiple elements" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return;
	  }; break;
	  
	case 1: // Вставляем один элемент
	  {
	    
	  }; break;
	  
	case 2: // Вставляем несколько элементов
	  {
	    
	  }; break;
	}
    }
}


void Mass::delete_item() // Удаляем элемент
{
  
}


void Mass::menu_delete_items() // Меню удаления элементов
{
  int what_to_do = 0;

  std::cout << std::endl;
  print(); 
  std::cout << std::endl;
  
  while(1)
    {
      std::cout << std::endl
		<< "1.Delete one element" << std::endl
		<< "2.Delete multiple elements" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return;
	  }; break;
	  
	case 1: // 
	  {
	    
	  }; break;
	  
	case 2: //
	  {
	    
	  }; break;
	}
    }
}


void Mass::find_item() // Ищем элемент
{
  
}


void Mass::menu_find_items() // Меню поиска элементов
{
  int what_to_do = 0;

  std::cout << std::endl;
  print(); 
  std::cout << std::endl;
  
  while(1)
    {
      std::cout << std::endl
		<< "1.Find one element" << std::endl
		<< "2.Find multiple elements" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return;
	  }; break;
	  
	case 1: // 
	  {
	    
	  }; break;
	  
	case 2: //
	  {
	    
	  }; break;
	}
    }
}


void Mass::replace_item() // Заменяем элемент
{
  
}


void Mass::menu_replace_items() // Меню замены элементов
{
  int what_to_do = 0;

  std::cout << std::endl;
  print(); 
  std::cout << std::endl;
  
  while(1)
    {
      std::cout << std::endl
		<< "1.Replace one element" << std::endl
		<< "2.Replace multiple elements" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return;
	  }; break;
	  
	case 1: // 
	  {
	    
	  }; break;
	  
	case 2: //
	  {
	    
	  }; break;
	}
    }
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
