#include <iostream>
#include <memory>  // shared_ptr, unique_ptr

class Animal {
public:
  virtual ~Animal() = default;   // = {} пустой деструктор
  virtual void eat() const = 0;  // = 0 означает, что реализация отсутствует
};

class Dog : public Animal {
public:
  // Задание 1: попробуйте не определять eat(). Возникнет ли ошибка?
  void eat() const override {
    std::cout << "Кушаю собычий корм.\n";
  }

  void bark() const {
    std::cout << "Гав-гав!\n";
  }
};

class Snake : public Animal {
public:
  void eat() const override {
    std::cout << "Кушаю маленьких мышей.\n";
  }

  void speak() const {
    std::cout << "Ccc-cc ccc-ccc...\n";
  }
};

void work_with_animals(std::shared_ptr<Animal> animal) {
  // Вопрос 1: какое количество владельцев выведется? Почему?
  std::printf("Количество владельцев: %ld\n", animal.use_count());

  std::cout << "Обслужим животное.\n";
  std::cout << "Кушать будешь?\n";
  animal->eat();
}

int main(int argc, char const* argv[]) {
  // создать объект класса Animal запрещено (интерфейс / абстрактный класс)
  // auto animal = std::make_shared<Animal>();

  auto dog = std::make_shared<Dog>();
  dog->bark();
  work_with_animals(dog);

  std::cout << '\n';

  auto snake = std::make_shared<Snake>();
  snake->speak();
  work_with_animals(snake);

  return 0;
}
