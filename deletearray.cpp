#include "deletearray.h"


void delete_mass(Mass **main_mass, int &size_mass, int pos_del) // 2.Удаляем массив
{
    if (size_mass == 0 || *main_mass == nullptr) // Если пришёл пустой массив
      {
	std::cerr << std::endl << "The array is empty! There is nothing to delete!" << std::endl;
	return;
      }

    if(size_mass == 1) // Удаляем последний оставшийся массив
      {
	delete[] *main_mass;
	*main_mass = nullptr;
      }
    else // Удаляем массив в нужном месте
      {
	Mass *temp = new Mass[size_mass-1];

	for (int i = 0, j = 0; i < size_mass-1; ++i) // Копирует существующие элементы, проходя мимо удалённого
	{
	  if (i == pos_del) ++j;
	  temp[i] = (*main_mass)[j];
	  ++j;
	}
	
	delete[] *main_mass;
	*main_mass = temp;
	temp = nullptr;;
      }
    
    --size_mass;

    std::cout << std::endl <<"Array has been deleted! Number of elements: " << size_mass << std::endl;
}


void menu_delete_mass(Mass **main_mass, int &size_mass) // 1.Меню удаления массива
{
  if (size_mass == 1) // Если остался последний массив
    {
      delete_mass(main_mass, size_mass, 0);
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
	    delete_mass(main_mass, size_mass, 0);
	  }; break;

	case 2: // Удаляем массив в конце
	  {
	    delete_mass(main_mass, size_mass, size_mass);
	  }; break;

	case 3: // Удаляем массив в выбранном месте
	  {
	    if (size_mass == 0)
	      {
		std::cerr << std::endl << "What are you going to delete here?"; // Что ты тут собрался удалять?!
		break;
	      }
	    
	    int pos = size_mass;
	    std::cout << "Select position from 1 to " << size_mass << ":";
	    std::cin >> pos;
	    --pos;

	    if (pos < 0 || size_mass < pos)
	      {
		std::cerr << std::endl << "Not guess, buddy!" << std::endl;
		break;
	      }

	    delete_mass(main_mass, size_mass, pos);
	  }; break;
	}
    }
}


void delete_all(Mass **main_mass, int &size_mass) // Полная очистка памяти
{
  if (size_mass == 0 || *main_mass == nullptr) return; // Если пришёл пустой массив
  
  delete[] *main_mass;
  *main_mass = nullptr;
  size_mass = 0;	
  std::cout << "The memery has been cleared!" << std::endl;
}
