#include <iostream>

class Object {
public:
  Object(int data) : data_{data} {
    std::printf("Объект создан: %d.\n", data_);
  }

  ~Object() {
    std::printf("Объект уничтожен: %d.\n", data_);
  }

private:
  int data_{0};
};

class ObjectWrapper {
public:
  // захватываем ресурс (участок памяти)
  ObjectWrapper(int data) : object_{new Object(data)} {
  }

  // освобождаем выделенный участок памяти
  ~ObjectWrapper() {
    delete object_;
  }

private:
  Object* object_{nullptr};  // указатель на ресурс
};

class IntArray {
  // Задание 1: реализуйте обёртку для целочисленных массивов
  // - конструктор с размером массива (все элементы обнулить)
  // - деструктор

  // Запрещаем копирование (для простоты)
  IntArray(const IntArray&) = delete;
  IntArray& operator=(const IntArray&) = delete;

  // Доступ к элементам
  int& operator[](size_t index) {
    return data_[index];
  }

private:
  int size_{0};
  int* data_{nullptr};
};

int main(int argc, char const* argv[]) {
  // Пример: утечка памяти
  {
    auto obj = new Object(1);
    // нужно вручную очищать память после использования
    // delete obj;
  }  // ~Object() автоматически не вызывается!

  std::cout << '\n';

  // Пример: утечка памяти побольше
  {
    auto data = new int[1024];  // массив объектов
    // delete [] data;
  }

  // RAII (Resource Acquisition is Initialization)
  {
    auto object1 = ObjectWrapper(1);
    auto object2 = ObjectWrapper(2);
    auto object3 = ObjectWrapper(3);
  }  // всё подчистится автоматически при выходе из области видимости

  return 0;
}
