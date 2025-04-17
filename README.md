# На пути к познанию C++ и ROS

## Подготовка к работе

### Требования к системе

- Ubuntu 20.04 с ROS Noetic (GCC 9, частично поддерживает стандарт C++17)
- cmake, git, clang-format
- catkin tools ([инструкции по установке](https://catkin-tools.readthedocs.io/en/latest/installing.html))

Проверьте версии компилятора и CMake:
```shell
cmake --version
g++ --version
```

### Клонирование проекта

Склонируйте репозиторий к себе на компьютер (предварителньо рекомендуется сделать fork репозитория):
```shell
git clone <ссылка на репозиторий>
```

## Сборка проекта

Собрать проект можно следующей командой (из `workspace` и вложенных директорий):
```shell
catkin build
```

Собрать конкретный пакет:
```shell
catkin build ros_cpp_tutorials
```

## Темы

1. Namespaces: nested, aliases, using.
2. Header files: declarations, templates, inline functions (utils), guards.
3. Catkin (cmake): targets, compiling, linking, cmake variables.
4. OOP: struct/class, public/private/protected, ctr/dtr.
5. Inheritance (public), polymorhism (virtual).
6. RAII, smart pointers (unique_ptr, shared_ptr).
7. Threads: thread (join/detach), async, future, mutex, lock_guard.
8. *Thread pools (boost).
9. ROS: init, NodeHandle, callbacks (lambda), spinners (spin, spinOnce, AsyncSpinner)
