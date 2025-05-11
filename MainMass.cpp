#include "MainMass.h"


int Main_mass::select_arr() // Выбор массива для обработки
{
  if (size_of_array == 0) // Если элементов нет
    {
      std::cerr << std::endl
		<< "There is nothing to choose from" << std::endl;
      return -1;
    } 
  if (size_of_array == 1) { return 0; } // Если элемент единственный
  
  int select_arr = 0;
  
  while(1) // Выбор пользователя одного из массивов
    {
      std::cout << std::endl
		<< "Select array: ";
      
      std::cin >> select_arr;
      
      if (1 <= select_arr && select_arr <= size_of_array) return select_arr-1;
    }
  return -1; // На всякий случай
}


void Main_mass::print_mass() // Вывод массивов на экран
{
  if (main_arr != nullptr && size_of_array != 0)
    for (int i = 0; i < size_of_array; ++i)
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
		<< "5.Seek items" << std::endl
		<< "6.Replace items" << std::endl
		<< "7.Sort items" << std::endl
		<< "8.Mix items" << std::endl
		<< "0.Exit" << std::endl << std::endl
		<< "Select action: ";
      
      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    delete_all(&main_arr, size_of_array);
	    std::cout << std::endl << "Goodbye!" << std::endl;
	    return; 
	  }; break;
	  
	case 1: // Создаём массив
	  {
	    menu_create_mass(&main_arr, size_of_array);
	  }; break;
	  
	case 2: // Удаляем массив
	  {
	    menu_delete_mass(&main_arr, size_of_array);
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
