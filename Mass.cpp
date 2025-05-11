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
	create_array();
	for (int i = 0; i < size; ++i)
	  {
	    std::cout << "Enter element number " << i+1 << ": ";
	    std::cin >> arr[i];
	  }
      }; break;
      
    case 4: // Читаем из файла
      {
	
      }; break;
    }
}


void Mass::insert_item(int pos_add) // Добавляем элемент
{  
   int *temp = new int[size+1];
      	
      for (int i = 0, j = 0; i <= size; ++i) // Копирует существующие элементы и инициализирует созданный
	{
	  if (i == pos_add)
	    {
	      std::cout << "Enter a new element: ";
	      std::cin >> temp[i]; // Инициализируем новый элемент
	    } 
	  else
	    {
	      temp[i] = arr[j]; // Копирует созданные
	      ++j;
	    }
	}

      delete[] arr;
      arr = temp;
      temp = nullptr;;
      
      ++size;
}


void Mass::menu_insert_items() // Меню добавления элементов
{
  int what_to_do = -1;
  
  while(what_to_do != 0)
    {      
      std::cout << std::endl;
      print(); 
      
      std::cout << std::endl << std::endl
		<< "1.Insert item in front" << std::endl
		<< "2.Insert item in end" << std::endl
		<< "3.Insert item at the selected location" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
  
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Вставка элемента в начало
	  {
	    insert_item(0);
	  }; break;
	  
	case 2: // Вставка элемента в конец
	  {
	    insert_item(size);
	  }; break;
	  
	case 3: // Вставка элемента в выбранном месте
	  {
	    int pos = size;
	    std::cout << "Select position from 1 to " << size+1 << ": ";
	    std::cin >> pos;
	    --pos;

	    if (pos < 0 || size < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }

	    insert_item(pos);
	  }; break;
	}
    }
}


void Mass::delete_item(int pos_del) // Удаляем элемент
{
  if (size == 0 || arr == nullptr) // Если пришёл пустой массив
    {
      std::cout << std::endl << "The array is empty! There is nothing to delete!" << std::endl;
      return;
    }
  
  if(size == 1) // Удаляем последний оставшийся элемент
    {
      delete[] arr;
      arr = nullptr;
    }
  else // Удаляем элемент в нужном месте
    {
      int *temp = new int[size-1];
      
      for (int i = 0, j = 0; i < size-1; ++i) // Копирует существующие элементы, проходя мимо удалённого
	{
	  if (i == pos_del) ++j;
	  temp[i] = arr[j];
	  ++j;
	}
      
      delete[] arr;
      arr = temp;
      temp = nullptr;;
    }
  
  --size;
}


void Mass::menu_delete_items() // Меню удаления элементов
{
  int what_to_do = -1;
  
  while(what_to_do != 0)
    {      
      std::cout << std::endl;
      print(); 
      
      std::cout << std::endl << std::endl
		<< "1.Delete item in front" << std::endl
		<< "2.Delete item in end" << std::endl
		<< "3.Delete item at the selected location" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Удаление элемента в начале
	  {
	    delete_item(0);
	  }; break;
	  
	case 2: // Удаление элемента в конце
	  {
	    delete_item(size);
	  }; break;
	  
	case 3: // Удаление элемента в выбранном месте
	  {
	    if (size == 0)
	      {
		std::cerr << std::endl << "What are you going to delete here?"; // Что ты тут собрался удалять?!
		break;
	      }
	    
	    int pos = size;
	    std::cout << "Select position from 1 to " << size << ": ";
	    std::cin >> pos;
	    --pos;
	    
	    if (pos < 0 || size < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }
	    
	    delete_item(pos);
	  }; break;
	}
    }
}


void Mass::find_item() // Ищем элемент
{
  
}


void Mass::menu_find_items() // Меню поиска элементов
{
  
}


void Mass::replace_item() // Заменяем элемент
{
  
}


void Mass::menu_replace_items() // Меню замены элементов
{
  
}


void Mass::quick_sort(int left, int right) // Быстрая сортировка
{
  if (left >= right) return;

  int mid = arr[(right + left)/2];
  int l = left, r = right;

  while (l <= r)
    {
      while (arr[l] < mid) l += 1;
      while (mid < arr[r]) r -= 1;

      if (l <= r)
	{
	  std::swap(arr[l], arr[r]);
	  ++l;
	  --r;
	}
    }
  if (l < size) quick_sort(l, right);
  if (0 < r) quick_sort(left, r);
}


void Mass::sort_items() // Сортируем элементы
{
  quick_sort(0, size-1);
}


void Mass::shuffling_items() // Перемешиваем элементы
{
  srand(std::time(0));

  for (int i = size-1; 0 < i; --i)
    {
      int j = rand() % i;
      std::swap(arr[i], arr[j]);
    }
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
