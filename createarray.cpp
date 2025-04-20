#include "createarray.h"

void create_mass_back(Mass ****main_mass, int &size_mass) // 1.Создаём массив в конце
{
  if (size_mass == 0 && ***main_mass != nullptr) // Если пришёл массив с размером 0, но он не пуст
    {
      std::cout << "The array size is 0, but it is not empty!" << std::endl;
      return;
    }

  if (size_mass == 0 && ***main_mass == nullptr) // Выделяем память под первый элемент
    {
      ***main_mass = new Mass[1];
      ++size_mass;

      std::cout << "First element has been added!" <<  "  " << size_mass << "  " << std::endl;
    }

  else if (size_mass > 0) // Добавляем память и переносим все элементы
    {
      Mass *temp = new Mass[size_mass+1];
      	
      for (int i = 0; i < size_mass; ++i) temp[i] = (***main_mass)[i];
      delete[] ***main_mass;
      ***main_mass = temp;
      temp = nullptr;;
      
      ++size_mass;

      std::cout << "Another element has been added!" <<  "  " << size_mass << "  " << std::endl;
    }
}

void create_mass(Mass ***main_mass, int &size_mass) // 1.Создаём массив
{
  int what_to_do = 0;
  
  while(1)
    {
      std::cout << "1.Create mass in front" << std::endl
		<< "2.Create mass in end" << std::endl
		<< "3.Create mass in select place" << std::endl
		<< "0.Exit" << std::endl;

      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    return; 
	  }; break;
	  
	case 1: // Создаём массив в начале
	  {
	    
	  }; break;

	case 2: // Создаём массив в конце
	  {
	    create_mass_back(&main_mass, size_mass);
	  }; break;

	case 3: // Создаём массив в выбранном месте
	  {
	    
	  }; break;
	}
    }
}
