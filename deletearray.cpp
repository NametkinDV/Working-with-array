#include "deletearray.h"

void delete_mass(Mass ***main_mass, int &size_mass) // 2.Удаляем массив
{
    if (size_mass == 0 || **main_mass == nullptr) // Если пришёл пустой массив
      {
	std::cout << "The array is empty! There is nothing to delete!" << std::endl;
	return;
      }

    if(size_mass == 1)
      {
	delete[] **main_mass;
	**main_mass = nullptr;
      }
    else
      {
	Mass *temp = new Mass[size_mass-1];
	for (int i = 0; i < size_mass-1; ++i) temp[i] = (**main_mass)[i];
	
	delete[] **main_mass;
	**main_mass = temp;
	temp = nullptr;;
      }
    
    --size_mass;

    std::cout << "Another element has been deleted!" <<  "  " << size_mass << "  " << std::endl;
}

void delete_all(Mass ***main_mass, int &size_mass) // Полная очистка памяти
{
  if (size_mass == 0 || **main_mass == nullptr) return; // Если пришёл пустой массив
  
  delete[] **main_mass;
  **main_mass = nullptr;
  size_mass = 0;	
  std::cout << "The memery has been cleared!" << std::endl;
}
