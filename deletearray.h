#ifndef deletearray_h
#define deletearray_h
#include "Mass.h"

class t2{};

void delete_mass(Mass **main_mass, int &size_mass, int pos_del); // Удаляем массив
void menu_delete_mass(Mass **main_mass, int &size_mass); // 2.Меню удаления массива
void delete_all(Mass **main_mass, int &size_mass); // Полная очистка памяти

#endif
