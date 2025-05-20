#include "MainMass.h"


void Main_mass::create_mass(int pos_add) // Создаём массив
{
  if (size == 0 && main_arr != nullptr) // Если пришёл массив с размером 0, но он не пуст
    {
      std::cerr << std::endl << "The array size is 0, but it is not empty!" << std::endl;
      return;
    }

  if (size == 0 && main_arr == nullptr) // Выделяем память под первый массив
    {
      main_arr = new Mass[1];
      main_arr->initialization();
      ++size;
    }

  else if (size > 0) // Добавляем память и переносим все массивы
    {
      Mass *temp = new Mass[size+1];
      	
      for (int i = 0, j = 0; i <= size; ++i) // Копирует существующие массивы и инициализирует созданный
	{
	  if (i == pos_add) temp[i].initialization(); // Инициализируем новый массив
	  else
	    {
	      temp[i] = main_arr[j]; // Копирует созданные
	      ++j;
	    }
	}

      delete[] main_arr;
      main_arr = temp;
      temp = nullptr;;
      
      ++size;
    }

  std::cout << std::endl << "New array has been added! Number of elements: " << size << std::endl;
}


void Main_mass::menu_create_mass() // Меню создания массива
{
  if (size == 0) // Если создаём первый массив
    {
      create_mass(0);
      return;
    }
  
  int what_to_do = 0;
  
  while(1) // Если уже есть созданные массивы
    {
      std::cout << std::endl
		<< "1.Create array in front" << std::endl
		<< "2.Create array in end" << std::endl
		<< "3.Create an array at the selected location" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";

      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Создаём массив в начале
	  {
	    create_mass(0);
	  }; break;

	case 2: // Создаём массив в конце
	  {
	    create_mass(size);
	  }; break;

	case 3: // Создаём массив в выбранном месте
	  {
	    int pos = size;
	    std::cout << "Select position from 1 to " << size+1 << ":";
	    std::cin >> pos;
	    --pos;

	    if (pos < 0 || size < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }

	    create_mass(pos);
	  }; break;
	}
    }
}


void Main_mass::delete_mass(int pos_del) // Удаляем массив
{
    if (size == 0 || main_arr == nullptr) // Если пришёл пустой массив
      {
	std::cerr << std::endl << "The array is empty! There is nothing to delete!" << std::endl;
	return;
      }

    if(size == 1) // Удаляем последний оставшийся массив
      {
	delete[] main_arr;
	main_arr = nullptr;
      }
    else // Удаляем массив в нужном месте
      {
	Mass *temp = new Mass[size-1];

	for (int i = 0, j = 0; i < size-1; ++i) // Копирует существующие элементы, проходя мимо удалённого
	{
	  if (i == pos_del) ++j;
	  temp[i] = main_arr[j];
	  ++j;
	}
	
	delete[] main_arr;
	main_arr = temp;
	temp = nullptr;;
      }
    
    --size;

    std::cout << std::endl <<"Array has been deleted! Number of elements: " << size << std::endl;
}


void Main_mass::menu_delete_mass() // Меню удаления массива
{
  if (size == 1) // Если остался последний массив
    {
      delete_mass(0);
      return;
    }
  
  int what_to_do = 0;
  
  while(1) // Если имеется несколько массивов
    {
      std::cout << std::endl
		<< "1.Delete array in front" << std::endl
		<< "2.Delete array in end" << std::endl
		<< "3.Delete array at selected location" << std::endl
		<< "0.Back" << std::endl << std::endl
		<< "Select action: ";

      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Удаляем массив в начале
	  {
	    delete_mass(0);
	  }; break;

	case 2: // Удаляем массив в конце
	  {
	    delete_mass(size);
	  }; break;

	case 3: // Удаляем массив в выбранном месте
	  {
	    if (size == 0)
	      {
		std::cerr << std::endl << "What are you going to delete here?"; // Что ты тут собрался удалять?!
		break;
	      }
	    
	    int pos = size;
	    std::cout << "Select position from 1 to " << size << ":";
	    std::cin >> pos;
	    --pos;

	    if (pos < 0 || size < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }

	    delete_mass(pos);
	  }; break;
	}
    }
}


void Main_mass::delete_all() // Полная очистка памяти
{
  if (size == 0 || main_arr == nullptr) return; // Если пришёл пустой массив
  
  delete[] main_arr;
  main_arr = nullptr;
  size = 0;	
  std::cout << "The memery has been cleared!" << std::endl;
}


int Main_mass::select_arr() // Выбор массива для обработки
{
  if (size == 0) // Если элементов нет
    {
      std::cerr << std::endl
		<< "There is nothing to choose from" << std::endl;
      return -1;
    } 
  if (size == 1) { return 0; } // Если элемент единственный
  
  int select_arr = 0;
  
  while(1) // Выбор пользователя одного из массивов
    {
      std::cout << std::endl
		<< "Select array: ";
      
      std::cin >> select_arr;
      
      if (1 <= select_arr && select_arr <= size) return select_arr-1;
    }
  return -1; // На всякий случай
}


void Main_mass::print_mass() // Вывод массивов на экран
{
  if (main_arr != nullptr && size != 0)
    for (int i = 0; i < size; ++i)
      {
	std::cout << i+1 << ": ";
	main_arr[i].print();
	std::cout << std::endl;
      }
  else
    {
      std::cout << "Empty";
      std::cout << std::endl;
    }
}


void Main_mass::create() // Запуск работы с массивами 
{
  int what_to_do = 0;
  
  while(1)
    {
      print_mass();
      
      std::cout << std::endl
		<< "1.Create mass" << std::endl
		<< "2.Delete mass" << std::endl
		<< "3.Insert items" << std::endl
		<< "4.Delete items" << std::endl
		<< "5.Find items" << std::endl
		<< "6.Replace items" << std::endl
		<< "7.Sort items" << std::endl
		<< "8.Shuffling items" << std::endl
		<< "0.Exit" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    delete_all();
	    std::cout << std::endl << "Goodbye!" << std::endl;
	    return; 
	  }; break;
	  
	case 1: // Создаём массив
	  {
	    menu_create_mass();
	  }; break;
	  
	case 2: // Удаляем массив
	  {
	    menu_delete_mass();
	  }; break;
	  
	case 3: // Добавляем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].menu_insert_items();
	  }; break;
	  
	case 4: // Удаляем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].menu_delete_items();
	  }; break;
	  
	case 5: // Ищем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].menu_find_items();
	  }; break;
	  
	case 6: // Заменяем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].menu_replace_items();
	  }; break;
	  
	case 7: // Сортируем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].sort_items();
	  }; break;
	  
	case 8: // Перемешиваем элементы
	  {
	    int select = select_arr();
	    if (select != -1) main_arr[select].shuffling_items();
	  }; break;  
	}
    }
}
