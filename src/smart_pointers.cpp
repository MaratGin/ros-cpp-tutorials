#include <iostream>
#include <memory>  // shared_ptr, unique_ptr

class Resource {
public:
  Resource() {
    std::cout << "Ресурс создан.\n";
  }
  ~Resource() {
    std::cout << "Ресурс уничтожен.\n";
  }
  void use() {
    std::cout << "Resource::use()\n";
  }
};

int main(int argc, char const* argv[]) {
  std::cout << "unique pointer\n";

  // unique_ptr - исключительно владение ресурсом + RAII
  {
    auto resource = std::make_unique<Resource>(/* аргументы конструктора */);
    // auto resource = std::unique_ptr<Resource>(new Resource());

    resource->use();  // использование будто через "сырой указатель"

    // нельзя копировать ресурс
    // auto resource_copy = resource;

    // можно перемещать
    // владение переходит в новый объект (указатель)
    std::cout << "Перемещение ресурса...\n";
    auto resource_transfered = std::move(resource);

    // можем использовать перемещенный ресурс
    resource_transfered->use();

    // старый указатель пуст (валидное состояние после перемещения)
    if (!resource) {
      std::cout << "Старый указатель пуст.\n";
    }
  }  // ресурс автоматически подчистится после выхода из области видимости

  std::cout << "\nshared pointer\n";

  // shared_ptr - разделяемое владение ресурсом + RAII
  {
    auto resource = std::make_shared<Resource>(/* аргументы конструктора */);
    std::printf("Количество владельцев: %ld\n", resource.use_count());

    {
      auto resource_copy = resource;
      std::printf("Количество владельцев (после копирования): %ld\n", resource.use_count());
    }  // ресурс полностью уничтожается только после того, как на него ничто не ссылается

    std::printf("Количество владельцев (после выхода из области видимости): %ld\n", resource.use_count());
  }

  return 0;
}
