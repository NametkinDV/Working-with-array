#include <iostream>

class Mass
{
  int *nums;

public:
};

void create_mass(Mass ***main_mass, int &size) // 1.Создаём массив
{
  
}

void delete_mass(Mass ***main_mass, int &size) // 2.Удаляем массив
{
  
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

void launch(Mass ***main_mass, int &size) // Запуск функции для работы с массивами 
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
	    return; 
	  }; break;
	  
	case 1: // Создаём массив
	  {
	    create_mass(main_mass, size);
	  }; break;

	case 2: // Удаляем массив
	  {
	    delete_mass(main_mass, size);
	  }; break;

	case 3: // Добавляем элементы
	  {
	    insert_items(main_mass, size);
	  }; break;
	  
	case 4: // Удаляем элементы
	  {
	    delete_items(main_mass, size);
	  }; break;

	case 5: // Ищем элементы
	  {
	     seek_items(main_mass, size);
	  }; break;

	case 6: // Заменяем элементы
	  {
	     replace_items(main_mass, size);
	  }; break;

	case 7: // Сортируем элементы
	  {
	     sort_items(main_mass, size);
	  }; break;

	case 8: // Перемешиваем элементы
	  {
	     mix_items(main_mass, size);
	  }; break;
	
	}
    }
}

int main()
{
  Mass **main_mass = nullptr;
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
