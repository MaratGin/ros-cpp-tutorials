#include <iostream>

#include <mutex>
#include <thread>

// общая переменная, будем увеличивать значение в одном потоке, а в другом уменьшать
int shared_data = 0;

std::mutex mtx;  // переменная, которая позволяет разделять доступ к данным из разных потоков

void increment() {
  for (int i = 0; i < 10; ++i) {
    // захватываем доступ к mtx - "говорим всем остальным потокам - доступ к переменной у меня"
    // std::lock_guard<std::mutex> lock(mtx);
    int local_copy = shared_data;

    // эмулируем работу
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    local_copy += 1;
    shared_data = local_copy;
  }  // автоматически отдаём доступ к mtx (RAII)
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);

  // запускаем два потока

  t1.join();
  t2.join();

  std::cout << "Final value: " << shared_data << '\n';
  return 0;
}
