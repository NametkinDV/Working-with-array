#include <iostream>
#include "Mass.h"
#include "createarray.h"
#include "deletearray.h"

Mass *main_array = nullptr;
int num_of_arrays = 0;

int select_arr() // Выбор массива для обработки
{
  if (num_of_arrays == 0) { return -1; } // Если элементов нет
  if (num_of_arrays == 1) { return 0; } // Если элемент единственный
  
  int select_arr = 0;
  
  while(1) // Выбор пользователя одного из массивов
    {
      std::cout << std::endl
	<< "Select array: ";

      std::cin >> select_arr;

      if (0 <= select_arr && select_arr < num_of_arrays) return select_arr;
    }
  return -1; // На всякий случай
}


void print_mass()
{
      if (main_array != nullptr && num_of_arrays != 0)
	  for (int i = 0; i < num_of_arrays; ++i)
	    {
	      std::cout << i+1 << ": ";
	      main_array[i].print();
	      std::cout << std::endl;
	    }
      else
	{
	  std::cout << "Empty";
	  std::cout << std::endl;
	}
}


void launch(Mass **main_mass) // Запуск работы с массивами 
{
  int what_to_do = 0;
  
  while(1)
    {
      print_mass();
      
      std::cout << std::endl
		<<"1.Create mass" << std::endl
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
	    delete_all(main_mass, num_of_arrays);
	    std::cout << std::endl << "Goodbye!" << std::endl;
	    return; 
	  }; break;
	  
	case 1: // Создаём массив
	  {
	    menu_create_mass(main_mass, num_of_arrays);
	  }; break;

	case 2: // Удаляем массив
	  {
	    menu_delete_mass(main_mass, num_of_arrays);
	  }; break;

	case 3: // Добавляем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].insert_items();
	  }; break;
	  
	case 4: // Удаляем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].delete_items();
	  }; break;

	case 5: // Ищем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].seek_items();
	  }; break;

	case 6: // Заменяем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].replace_items();
	  }; break;

	case 7: // Сортируем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].sort_items();
	  }; break;

	case 8: // Перемешиваем элементы
	  {
	    int select = select_arr();
	    if (select != -1) (*main_mass)[select].mix_items();
	  }; break;
	
	}
    }
}

int main()
{
  launch(&main_array);

  return 0;
}


/*                                        
                    **************************
---      ---       *                          *        ---      ---
  ---  ---        *                ***        * ***      ---  ---   
---      ---      *               *   *       **   *   ---      ---
  ---  ---        *               *    *      *    *     ---  ---  
---      --- **   *               *     ******     *   ---      ---
  ---  ---  *  *  *              *   ***       ***  *    ---  ---  
---      ---*  ** *              *   ***       ***  *  ---      ---
  ---  ---   *   **              *                  *    ---  ---  
---      ---  **  *              *     *   *   *    *  ---      ---
  ---  ---      ***               *    *********   *     ---  ---  
---      ---      *                *              *    ---      ---
  ---  ---       **                 **************       ---  ---  
                *  **********************    *
	       *   * *  *          *   * *   *
               *  *  ***           ****   ****
	       ***
		
 */
