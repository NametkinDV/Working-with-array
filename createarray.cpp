#include "createarray.h"


void create_mass(Mass **main_mass, int &size_mass, int pos_add) // Создаём массив
{
  if (size_mass == 0 && *main_mass != nullptr) // Если пришёл массив с размером 0, но он не пуст
    {
      std::cerr << std::endl << "The array size is 0, but it is not empty!" << std::endl;
      return;
    }

  if (size_mass == 0 && *main_mass == nullptr) // Выделяем память под первый массив
    {
      *main_mass = new Mass[1];
      (*main_mass)->initialization();
      ++size_mass;
    }

  else if (size_mass > 0) // Добавляем память и переносим все массивы
    {
      Mass *temp = new Mass[size_mass+1];
      	
      for (int i = 0, j = 0; i <= size_mass; ++i) // Копирует существующие массивы и инициализирует созданный
	{
	  if (i == pos_add) temp[i].initialization(); // Инициализируем новый массив
	  else
	    {
	      temp[i] = (*main_mass)[j]; // Копирует созданные
	      ++j;
	    }
	}

      delete[] *main_mass;
      *main_mass = temp;
      temp = nullptr;;
      
      ++size_mass;
    }

  std::cout << std::endl << "New array has been added! Number of elements: " << size_mass << std::endl;
}


void menu_create_mass(Mass **main_mass, int &size_mass) // 1.Меню создания массива
{
  int what_to_do = 0;
  
  while(1)
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
	    create_mass(main_mass, size_mass, 0);
	  }; break;

	case 2: // Создаём массив в конце
	  {
	    create_mass(main_mass, size_mass, size_mass);
	  }; break;

	case 3: // Создаём массив в выбранном месте
	  {
	    int pos = size_mass;
	    std::cout << "Select position from 1 to " << size_mass+1 << ":";
	    std::cin >> pos;
	    --pos;

	    if (pos < 0 || size_mass < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }

	    create_mass(main_mass, size_mass, pos);
	  }; break;
	}
    }
}
