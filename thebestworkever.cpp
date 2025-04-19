#include <iostream>

class Mass
{
  int *nums;

public:
  Mass(){num = 5;}
  int num;
};

void create_mass(Mass ***main_mass, int &size) // 1.Создаём массив
{
  if (size == 0 && **main_mass != nullptr) // Если пришёл массив с размером 0, но он не пуст
    {
      std::cout << "The array size is 0, but it is not empty!" << std::endl;
      return;
    }

  if (size == 0 && **main_mass == nullptr) // Выделяем память под первый элемент
    {
      **main_mass = new Mass[1];
      ++size;

      std::cout << "First element has been added!" <<  "  " << size << "  " << std::endl;
    }

  else if (size > 0) // Добавляем память и переносим все элементы
    {
      Mass *temp = new Mass[size+1];
      	
      for (int i = 0; i < size; ++i) temp[i] = (**main_mass)[i];
      delete[] **main_mass;
      **main_mass = temp;
      temp = nullptr;;
      
      ++size;

      std::cout << "Another element has been added!" <<  "  " << size << "  " << std::endl;
    }
}

void delete_mass(Mass ***main_mass, int &size) // 2.Удаляем массив
{
    if (size == 0 || **main_mass == nullptr) // Если пришёл пустой массив
      {
	std::cout << "The array is empty! There is nothing to delete!" << std::endl;
	return;
      }

    if(size == 1)
      {
	delete[] **main_mass;
	**main_mass = nullptr;
      }
    else
      {
	Mass *temp = new Mass[size-1];
	for (int i = 0; i < size-1; ++i) temp[i] = (**main_mass)[i];
	
	delete[] **main_mass;
	**main_mass = temp;
	temp = nullptr;;
      }
    
    --size;

    std::cout << "Another element has been deleted!" <<  "  " << size << "  " << std::endl;
}

void delete_all(Mass ***main_mass, int &size) // Полная очистка памяти
{
  if (size == 0 || **main_mass == nullptr) return; // Если пришёл пустой массив
  
  delete[] **main_mass;
  **main_mass = nullptr;
  size = 0;	
  std::cout << "The memery has been cleared!" << std::endl;
}

void insert_items(Mass ***main_mass, int &size) // 3.Добавляем элементы
{
  
}

void delete_items(Mass ***main_mass, int &size) // 4.Удаляем элементы
{
  
}

void seek_items(Mass ***main_mass, int &size) // 5.Ищем элементы
{
  
}

void replace_items(Mass ***main_mass, int &size) // 6.Заменяем элементы
{
  
}

void sort_items(Mass ***main_mass, int &size) // 7.Сортируем элементы
{
  
}

void mix_items(Mass ***main_mass, int &size) // 8.Перемешиваем элементы
{
  
}

void launch(Mass **main_mass, int &size) // Запуск функции для работы с массивами 
{
  int what_to_do = 0;
  
  while(1)
    {
      std::cout << "1.Create mass" << std::endl
		<< "2.Delete mass" << std::endl
		<< "3.Insert items" << std::endl
		<< "4.Delete items" << std::endl
		<< "5.Seek items" << std::endl
		<< "6.Replace items" << std::endl
		<< "7.Sort items" << std::endl
		<< "8.Mix items" << std::endl
		<< "0.Exit" << std::endl;

      std::cin >> what_to_do;
      
      switch(what_to_do)
	{
	case 0: // Выбегаем
	  {
	    delete_all(&main_mass, size);
	    return; 
	  }; break;
	  
	case 1: // Создаём массив
	  {
	    create_mass(&main_mass, size);
	  }; break;

	case 2: // Удаляем массив
	  {
	    delete_mass(&main_mass, size);
	  }; break;

	case 3: // Добавляем элементы
	  {
	    insert_items(&main_mass, size);
	  }; break;
	  
	case 4: // Удаляем элементы
	  {
	    delete_items(&main_mass, size);
	  }; break;

	case 5: // Ищем элементы
	  {
	    seek_items(&main_mass, size);
	  }; break;

	case 6: // Заменяем элементы
	  {
	    replace_items(&main_mass, size);
	  }; break;

	case 7: // Сортируем элементы
	  {
	    sort_items(&main_mass, size);
	  }; break;

	case 8: // Перемешиваем элементы
	  {
	    mix_items(&main_mass, size);
	  }; break;
	
	}
    }
}

int main()
{
  Mass *main_mass = nullptr;
  int size = 0;
  launch(&main_mass, size);

  return 0;
}


/*                                        
                    **************************
---      ---       *                          *
  ---  ---        *                ***        * ***   
---      ---      *               *   *       **   *
  ---  ---        *               *    *      *    *
---      --- **   *               *     ******     * 
  ---  ---  *  *  *              *   ***       ***  *
---      ---*  ** *              *   ***       ***  *
  ---  ---   *   **              *                  *
---      ---  **  *              *     *   *   *    *
  ---  ---      ***               *    *********   *
---      ---      *                *              *
  ---  ---       **                 **************
                *  **********************    *
	       *   * *  *          *   * *   *
               *  *  ***           ****   ****
	       ***
		
 */
