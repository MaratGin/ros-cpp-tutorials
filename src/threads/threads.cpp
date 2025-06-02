#include <iostream>
#include <thread>

void threadFunction() {
  const auto tid = std::this_thread::get_id();
  std::cout << "Working thread: " << tid << '\n';
  std::this_thread::sleep_for(std::chrono::seconds(5));  // эмулируем работу в 5 секунд ...
}

int main() {
  // создание и запуск нового "рабочего потока"
  // передаем функцию, которая будет выполняться в потоке (это задача)
  std::thread t1(threadFunction);

  // Задание: создайте ещё один поток с той же задачей

  // главный поток продолжает работу
  std::cout << "Main thread is working hard.\n";

  // ожидаем завершения "рабочего потока" (или рабочих потоков)
  t1.join();

  return 0;
}
