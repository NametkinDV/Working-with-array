#include "Mass.h"


void Mass::create_array() // Создаём массив
{
  if (size == 0)
    {
      std::cout << std::endl
		<< "Specify the number of elements: ";
      std::cin >> size;
    }
  
  arr = new int[size];
}


void Mass::open_file(std::ifstream **input, int &file_size) // Открытие файла и определение его размера
{
  std::string file_name = "";

  std::cout << std::endl
	    << "Enter file name: ";
  std::cin >> file_name;

  std::ifstream *file = nullptr;
  file = new std::ifstream(file_name.c_str()); // Открываем файл

  if (file->fail()) // Упс, что-то пошло не так
    {
      std::cerr << std::endl
		<< "Error opening file" << std::endl;

      delete file;
      *input = nullptr;
      file_size = 0;
      return;
    }
  
  while (!file->eof()) // Проходим весь файл и считаем элементы
    {
      int temp = 0;
      *file >> temp;
      
      if (file->fail()) break; // Если встретили некорректный элемент
      else ++file_size;
    }

  file->clear();
  file->seekg(0); // Ставим позицию чтения на начало

  *input = file;
  file = nullptr;
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
	std::ifstream *file = nullptr;
	int file_size = 0;
	
	open_file(&file, file_size);

	if (0 < file_size)
	  {
	    size = file_size;
	    create_array();
	    
	    for (int i = 0; i < size; ++i) // Переносим данные из файла в массив
	      {
		if (file->fail()) break;
		*file >> arr[i];
	      }
	  }
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


int Mass::find_item(int find, int mode = 0, int pos_start = 0) // Ищем элемент
{
  if (mode == 0 && pos_start < size) // Ищем с заданного начала
    for (int i = pos_start; i < size; ++i) if (arr[i] == find) return i;	
  
  if (mode == 1) // Ищем с конца
    for (int i = size-1; 0 <= i; --i) if (arr[i] == find) return i;	

    return -1;
}


void Mass::menu_find_items() // Меню поиска элементов
{
  int what_to_do = 0, what_to_find = 0;
  
  while(1)
    {      
      std::cout << std::endl;
      print(); 
      
      std::cout << std::endl << std::endl
		<< "1.Find the first occurrence of an element" << std::endl
		<< "2.Find the last occurrence of an element" << std::endl
		<< "3.Find all occurrences of an element" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;

      if (0 < what_to_do && what_to_do <=3)
	{
	  std::cout << "Enter an item to search for: ";
	  std::cin >> what_to_find;
	}
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Ищем первое вхождение элемента
	  {
	    int res = find_item(what_to_find);

	    if (res == -1) std::cout << std::endl << "Element not found" << std::endl;
	    else std::cout << std::endl << "Element position: " << ++res << std::endl;
	  }; break;
	  
	case 2: // Ищем последнее вхождение элемента
	  {	   
	    int res = find_item(what_to_find, 1);

	    if (res == -1) std::cout << std::endl << "Element not found" << std::endl;
	    else std::cout << std::endl << "Element position: " << ++res << std::endl;
	  }; break;
	  
	case 3: // Ищем все вхождения элемента
	  {	   
	    std::cout << std::endl << "Element positions: ";
	    int res = 0, count = 0;
	    
	    while(1)
	      {
		res = find_item(what_to_find, 0, res);
		if (res == -1) break;		  

		std::cout << ++res << " ";
		++count;		  
	      }
	    if (count == 0) std::cout << std::endl << "Element not found" << std::endl;
	    std::cout << std::endl;
	  }; break;
	}
    }
}


void Mass::menu_replace_items() // Меню замены элементов
{
  int what_to_do = -1, what_to_replace = 0, new_item = 0;
  
  while(1)
    {
      std::cout << std::endl;
      print(); 
      
      std::cout << std::endl << std::endl
		<< "1.Set element by index" << std::endl
		<< "2.Set element by value" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;

      switch(what_to_do)
	{
	case 0:
	  {
	    return;
	  } break;

	case 1:
	  {
	    std::cout << std::endl << "Enter replacement index: ";
	    int index = 0;
	    std::cin >> index;

	    if (index < 0 || size <= index)
	      {
		std::cerr << std::endl << "Out of range" << std::endl;
		break;
	      }

	    else
	      {
		std::cout << "Enter a new element: ";
		std::cin >> new_item;
		arr[index] = new_item;
	      }
	  } break;

	case 2:
	  {
	    std::cout << std::endl;
	    print();
	    what_to_do = -1;
	    
	    std::cout << std::endl << std::endl
		      << "1.Replace first occurrence of an element" << std::endl
		      << "2.Replace last occurrence of an element" << std::endl
		      << "3.Replace all occurrences of an element" << std::endl
		      << "0.Back" << std::endl << std::endl
		      << "Select action: ";
	    
	    std::cin >> what_to_do;
	    
	    if (0 < what_to_do && what_to_do <=3)
	      {
		std::cout << "Enter an item to replace for: ";
		std::cin >> what_to_replace;
	      }
	    
	    switch(what_to_do)
	      {
	      case 0: // Выбегаем
		{
		  return; 
		}; break;
		
	      case 1: // Меняем первое вхождение элемента
		{
		  int res = find_item(what_to_replace);
		  
		  if (res == -1) std::cout << std::endl << "Element not found" << std::endl;
		  else
		    {
		      std::cout << "Enter a new element: ";
		      std::cin >> new_item;
		      arr[res] = new_item;
		    }
		}; break;
		
	      case 2: // Меняем последнее вхождение элемента
		{	   
		  int res = find_item(what_to_replace, 1);
		  
		  if (res == -1) std::cout << std::endl << "Element not found" << std::endl;
		  else
		    {
		      std::cout << "Enter a new element: ";
		      std::cin >> new_item;
		      arr[res] = new_item;
		    }
		}; break;
		
	      case 3: // Меняем все вхождения элемента
		{	   
		  int res = 0, count = 0;

		  std::cout << "Enter a new element: ";
		  std::cin >> new_item;
		  
		  while(1)
		    {
		      res = find_item(what_to_replace, 0, res);
		      if (res == -1) break;		  
		      
		      arr[res] = new_item;
		      
		      ++count;		  
		    }
		  if (count == 0) std::cout << std::endl << "Element not found" << std::endl;
		  std::cout << std::endl;
		}; break;
	      }
	  }
	}
    }
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
  if (this->size != 0) // Если в получающем элементе что-то было
    {
      delete[] this->arr;
      this->arr = nullptr;
      this->size = 0;
    }
    
  this->size = mass.size;
  this->arr = new int[this->size];

  for (int i = 0; i < size; ++i) this->arr[i] = mass.arr[i];

  delete[] mass.arr;
  mass.arr = nullptr;

  return *this;
}
