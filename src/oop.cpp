#include <iostream>  // cout

// структуры
//  - поля
//  - методы (this, const, статические)
//  - идентификаторы доступа: public, private
//  - поля, инициализация
//  - конструктор(ы), деструктор
//  - наследование (public)
//  - полиморфизм (ключевое слово virtual, override)
//  - виртуальный деструктор

// "сырые" указатели, проблемы утечки памяти
// RAII - Resource Acquisition is Initialization (получение ресурса = инициализация)
// умные указатели - shared_ptr, unique_ptr
// make_shared, make_unique

struct Resource {
  // ctr, dtr, void use()
  int id;
  std::string name;
  std::string description;
};

struct Camera : public Resource {};

// Camera : Resource
// Motor : Resource

int main(int argc, char const* argv[]) {
  Resource device = Camera();

  std::printf("ID: %d, name: %s, desc: %s", device.id, device.name.c_str(), device.description.c_str());

  return 0;
}
