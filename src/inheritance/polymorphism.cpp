#include <iostream>
#include <vector>

// Базовый класс
class Animal {
public:
  // метод класса с базовой реализацией
  // virtal: метод может быть переопределён в производных классах
  virtual void eat() {
    std::cout << "Я могу кушать базовые продукты.\n";
  }

  Animal() {
    std::cout << "Рождение животного.\n";
  }

  virtual ~Animal() {
    std::cout << "Смерть животного.\n";
  }

  // vtable: [ &Animal::eat() ]
};

// Производный класс (наследник)
class Dog : public Animal {
public:
  // "override" не обязательно писать (но рекомендуется)
  void eat() override {
    std::cout << "Я могу кушать собачий корм.\n";
  }

  void bark() {
    std::cout << "Я могу лаять! Гав-гав...\n";
  }

  Dog() {
    std::cout << "Рождение собаки.\n";
  }

  ~Dog() {
    std::cout << "Смерть собаки.\n";
  }

  // vtable: [ &Dog::eat() ]
};

// Ещё один производный класс (наследник)
class Bird : public Animal {
public:
  void eat() override {
    std::cout << "Я люблю поклевать зерно.\n";
  }

  Bird() {
    std::cout << "Рождение птицы.\n";
  }

  virtual ~Bird() {
    std::cout << "Смерть птицы.\n";
  }
};

void work_with_animals(Animal* animal) {
  std::cout << "Ухаживаем за ЛЮБЫМ животным.\n";
  std::cout << "Что ты любишь поесть?\n";

  animal->eat();

  std::cout << "Животное успешно накормлено.\n";
}

int main(int argc, char const* argv[]) {
  {
    // указатель полностью ссылается на область памяти с Dog
    // Animal* видит только начало объекта (часть Animal)
    // vtable ведёт к Dog::vtable
    Animal* dog = new Dog();

    // полиморфизм - вроде работаем с Animal, а ведёт себя как Dog
    dog->eat();  // 1. Ищет vtable в *dog (Dog)
                 // 2. Переходит по Dog::vtable
                 // 3. Вызывает Dog::eat()

    // ошибка: Animal::bark() не существует
    // Вопрос 1: почему не ведёт себя как Dog в данном случае?
    // dog->bark();

    // Вопрос 2: будет ли вызван деструктор для объектов Animal и Dog (в каком порядке)?
    // Задание 2: вызовите деструктор объекта dog
  }

  std::cout << "\n";

  {
    // Вопрос 3: какой тип данных у dog и bird?
    auto dog = new Dog();
    auto bird = new Bird();

    // Вопрос 4: можно ли передавать Dog* и Bird* в аргумент типа Animal*?
    work_with_animals(dog);
    work_with_animals(bird);

    // Проблема: постоянно помнить об очистке памяти
    delete dog;
    delete bird;
  }

  return 0;
}
