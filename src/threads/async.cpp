#include <future>
#include <iostream>

void task(const std::string& name) {
  std::cout << "Task " << name << " started\n";

  // симулируем работу
  for (int i = 0; i < 3; ++i) {
    std::cout << name << " working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  // Deferred - запускается при вызове get()
  auto fut1 = std::async(std::launch::deferred, task, "Deferred");

  // Запускается сразу в отдельном потоке
  auto fut2 = std::async(std::launch::async, task, "Async");

  std::cout << "Main thread waiting...\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));

  fut1.get();  // запуск defered задачи
  fut2.get();  // эта задача уже давно запущена и может быть уже выполнена

  return 0;
}
